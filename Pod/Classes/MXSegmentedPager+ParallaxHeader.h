// MXSegmentedPager+ParallaxHeader.h
//
// Copyright (c) 2015 Maxime Epain
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "MXSegmentedPager.h"
#import "UIScrollView+VGParallaxHeader.h"

/**
 MXProgressBlock type définition.
 
 @param progress The scroll progress.
 */
typedef void (^MXProgressBlock) (CGFloat progress);

/**
 MXSegmentedPager with parallax header. This category uses [VGParallaxHeader](http://cocoadocs.org/docsets/VGParallaxHeader/0.0.6/ ) to set up a parallax header on top of a segmented-pager.
 */
@interface MXSegmentedPager (ParallaxHeader)

/**
 The parallax header. cf. [VGParallaxHeader](http://cocoadocs.org/docsets/VGParallaxHeader/0.0.6/ ) for more details.
 */
@property (nonatomic, strong, readonly) VGParallaxHeader *parallaxHeader;

/**
 The minimum header height, the header won't scroll below this value. By default, the minimum height is set to 0.
 */
@property (nonatomic, assign) CGFloat minimumHeaderHeight;

/**
 The progress block called when scroll is progressing.
 */
@property (nonatomic, strong) MXProgressBlock progressBlock;

/**
 Sets the parallax header view.
 
 @param view   The parallax header view.
 @param mode   The parallax header mode. cf. [VGParallaxHeader](http://cocoadocs.org/docsets/VGParallaxHeader/0.0.6/ ) for more details.
 @param height The header height.
 */
- (void)setParallaxHeaderView:(UIView *)view
                         mode:(VGParallaxHeaderMode)mode
                       height:(CGFloat)height;

@end

/**
 While using MXSegmentedPager with Parallax header, your pages can adopt the MXPageDelegate protocol to have a nice effect while scrolling.
 This is useful when you have a page with a scrolling subview (e.g. UIWebView).
 */
@protocol MXPageDelegate <NSObject>

@optional

/**
 Tells if the view is at its scrolling top.
 
 @return Whether or nor the view is at its scroll top.
 */
- (BOOL) isAtTop;

/**
 Scrolls to top with no animation.
 */
- (void) scrollToTop;

@end

/**
 UIScrollView category that adopt the MXPageDelegate protocol.
 */
@interface UIScrollView (MXSegmentedPager) <MXPageDelegate>
@end

/**
 UIWebView category that adopt the MXPageDelegate protocol.
 */
@interface UIWebView (MXSegmentedPager) <MXPageDelegate>
@end
