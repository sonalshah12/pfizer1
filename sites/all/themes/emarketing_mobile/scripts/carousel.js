/*
 * Swipe 1.0 (Modified by Ci&T)
 *
 * Brad Birdsall, Prime
 * Copyright 2011, Licensed GPL & MIT
 *
*/

window.Swipe = function(element, options) {

  // return immediately if element doesn't exist
  if (!element) return null;

  var _this = this;

  // retreive options
  this.options = options || {};
  this.index = this.options.startSlide || 1;
  this.speed = this.options.speed || 200;
  this.callback = this.options.callback || function() {};
  this.delay = this.options.auto || 0;

  // reference dom elements
  this.container = element;
  this.element = this.container.children[0]; // the slide pane

  // static css
  this.container.style.overflow = 'hidden';
  this.element.style.listStyle = 'none';
  this.element.style.margin = 0;

  // trigger slider initialization
  this.setup();

  // begin auto slideshow
  this.begin();

  // add event listeners
  if (this.element.addEventListener) {
    this.element.addEventListener('touchstart', this, false);
    this.element.addEventListener('touchmove', this, false);
    this.element.addEventListener('touchend', this, false);
    this.element.addEventListener('webkitTransitionEnd', this, false);
    this.element.addEventListener('msTransitionEnd', this, false);
    this.element.addEventListener('oTransitionEnd', this, false);
    this.element.addEventListener('transitionend', this, false);
    window.addEventListener('resize', this, false);
  }

};

Swipe.prototype = {

  setup: function() {

    // get and measure amt of slides
    this.slides = this.element.children;
    this.length = this.slides.length;
    this.sliding = false;

    // return immediately if their are less than two slides
    if (this.length < 2) return null;

    // determine width of each slide
    this.width = ("getBoundingClientRect" in this.container) ? this.container.getBoundingClientRect().width : this.container.offsetWidth;

    // return immediately if measurement fails
    if (!this.width) return null;

    // hide slider element but keep positioning during setup
    this.container.style.visibility = 'hidden';

    // dynamic css
    this.element.style.width = ((this.slides.length) * this.width) + 'px';
    this.element.style.display = 'inline-table';
    var index = this.slides.length;
    while (index--) {
      var el = this.slides[index];
      el.style.width = this.width + 'px';
      el.style.display = 'table-cell';
      el.style.verticalAlign = 'top';

      /**
      Here we collect the first and the last element to clone
      */
      if(index === this.slides.length - 1) {
        var last_elem = el.cloneNode(true);
        last_elem.className = 'cloned';
      } 
      else if(index === 0) {
        var first_elem = el.cloneNode(true);
        first_elem.className = 'cloned';
      }
    }

    /**
      Appending first and last elements
    **/
    if(this.slides[0].className != 'cloned') {
      this.element.appendChild(first_elem); 
      this.element.insertBefore(last_elem, this.slides[0]);
    }

    //update length and width
    this.length = this.slides.length;
    this.element.style.width = ((this.slides.length) * this.width) + 'px';
    this.slides = this.element.children;
    // set start position and force translate to remove initial flickering
    this.slide(this.index, 0); 

    // show slider element
    this.container.style.visibility = 'visible';
  },

  slide: function(index, duration) {

    var style = this.element.style;

    // fallback to default speed
    if (duration == undefined) {
        duration = this.speed;
    }

    // set normal duration speed (0 represents 1-to-1 scrolling)
    style.webkitTransitionDuration = style.MozTransitionDuration = style.msTransitionDuration = style.OTransitionDuration = style.transitionDuration = duration + 'ms';
	
    // translate to given index position
    style.MozTransform = style.webkitTransform = 'translate3d(' + -(index * this.width) + 'px,0,0)';
    style.msTransform = style.OTransform = 'translateX(' + -(index * this.width) + 'px)';
	
    if(duration > 0) {
      this.sliding = true;
    } 
    else {
      this.sliding = false;
    }
	
    // set new index to allow for expression arguments
    this.index = index;

  },

  getPos: function() {
    
    // return current index position
    return this.index;

  },

  prev: function(delay) {
    if(!this.sliding) {
      // cancel next scheduled automatic transition, if any
      this.delay = delay || 0;
      clearTimeout(this.interval);

      // if not at first slide
      if (this.index) this.slide(this.index-1, this.speed);
    }
  },

  next: function(delay) {
    if(!this.sliding) {
      // cancel next scheduled automatic transition, if any
      this.delay = delay || 0;
      clearTimeout(this.interval);

      this.slide(this.index+1, this.speed);
    }
  },

  begin: function() {

    var _this = this;

    this.interval = (this.delay)
      ? setTimeout(function() { 
        _this.next(_this.delay);
      }, this.delay)
      : 0;
  
  },
  
  stop: function() {
    this.delay = 0;
    clearTimeout(this.interval);
  },
  
  resume: function() {
    this.delay = this.options.auto || 0;
    this.begin();
  },

  handleEvent: function(e) {
    switch (e.type) {
      case 'touchstart': this.onTouchStart(e); break;
      case 'touchmove': this.onTouchMove(e); break;
      case 'touchend': this.onTouchEnd(e); break;
      case 'webkitTransitionEnd':
      case 'msTransitionEnd':
      case 'oTransitionEnd':
      case 'transitionend': this.transitionEnd(e); break;
      case 'resize': this.setup(); break;
    }
  },

  transitionEnd: function(e) {
    if (this.delay) this.begin();

    var realIndex = this.index;
    if(this.index == 0) {
      realIndex = this.length - 2;
    } 
    else if(this.index == this.length - 1) {
      realIndex = 1;
    }
    this.callback(e, realIndex, this.slides[this.index]);
    
    if(this.index == 0 || this.index + 1 == this.slides.length) {
      this.slide(this.index==0?this.slides.length - 2:1, 0);
    }

    this.sliding = false;
  },

  onTouchStart: function(e) {
    if(!this.sliding) {
      this.sliding = true;
      
      this.start = {

        // get touch coordinates for delta calculations in onTouchMove
        pageX: e.touches[0].pageX,
        pageY: e.touches[0].pageY,

        // set initial timestamp of touch sequence
        time: Number( new Date() )

      };

      // used for testing first onTouchMove event
      this.isScrolling = undefined;

      // reset deltaX
      this.deltaX = 0;

      // set transition time to 0 for 1-to-1 touch movement
      this.element.style.MozTransitionDuration = this.element.style.webkitTransitionDuration = 0;

      e.stopPropagation();
      
      // cancel slideshow
      this.stop();
    }
  },

  onTouchMove: function(e) {
    if(this.index != 0 && this.index != this.length - 1) {
      // ensure swiping with one touch and not pinching
      if(e.touches.length > 1 || e.scale && e.scale !== 1) return;

      this.deltaX = e.touches[0].pageX - this.start.pageX;

      // determine if scrolling test has run - one time test
      if ( typeof this.isScrolling == 'undefined') {
        this.isScrolling = !!( this.isScrolling || Math.abs(this.deltaX) < Math.abs(e.touches[0].pageY - this.start.pageY) );
      }
      // if user is not trying to scroll vertically
      if (!this.isScrolling) {

        // prevent native scrolling 
        e.preventDefault();

        // cancel slideshow
        clearTimeout(this.interval);

        // increase resistance if first or last slide
        this.deltaX = 
          this.deltaX / 
            ( (!this.index && this.deltaX > 0               // if first slide and sliding left
              || this.index == this.length - 1              // or if last slide and sliding right
              && this.deltaX < 0                            // and if sliding at all
            ) ?                      
            ( Math.abs(this.deltaX) / this.width + 1 )      // determine resistance level
            : 1 );                                          // no resistance if false

        // translate immediately 1-to-1
        this.element.style.MozTransform = this.element.style.webkitTransform = 'translate3d(' + (this.deltaX - this.index * this.width) + 'px,0,0)';

        e.stopPropagation();
      }
    }
  },

  onTouchEnd: function(e) {

    // determine if slide attempt triggers next/prev slide
    var isValidSlide = 
          Number(new Date()) - this.start.time < 250      // if slide duration is less than 250ms
          && Math.abs(this.deltaX) > 20                   // and if slide amt is greater than 20px
          || Math.abs(this.deltaX) > this.width/2,        // or if slide amt is greater than half the width

    // determine if slide attempt is past start and end
        isPastBounds = 
          !this.index && this.deltaX > 0                          // if first slide and slide amt is greater than 0
          || this.index == this.length - 1 && this.deltaX < 0;    // or if last slide and slide amt is less than 0

    // if not scrolling vertically
    if (!this.isScrolling) {

      // call slide function with slide end value based on isValidSlide and isPastBounds tests
      this.slide( this.index + ( isValidSlide && !isPastBounds ? (this.deltaX < 0 ? 1 : -1) : 0 ), this.speed );

    }
    
    e.stopPropagation();
    
    this.sliding = false;
  }

};