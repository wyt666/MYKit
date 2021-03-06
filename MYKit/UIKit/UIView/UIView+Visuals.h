//
//  UIView+Visuals.h
//  MYKitDemo
//
//  Created by sunjinshuai on 2017/9/6.
//  Copyright © 2017年 com.51fanxing. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^AnimationCompletBlock) ();

@interface UIView (Visuals)

/*
 *  Sets a corners with radius, given stroke size & color
 */
- (void)cornerRadius:(CGFloat)radius
          strokeSize:(CGFloat)size
               color:(UIColor *)color;

/*
 *  Draws shadow with properties
 */
- (void)shadowWithColor:(UIColor *)color
                 offset:(CGSize)offset
                opacity:(CGFloat)opacity
                 radius:(CGFloat)radius;

/*
 *  Removes from superview with fade
 */
- (void)removeFromSuperviewWithFadeDuration:(NSTimeInterval)duration;

/*
 *  Adds a subview with given transition & duration
 */
- (void)addSubview:(UIView *)view withTransition:(UIViewAnimationTransition)transition duration:(NSTimeInterval)duration;

/*
 *  Removes view from superview with given transition & duration
 */
- (void)removeFromSuperviewWithTransition:(UIViewAnimationTransition)transition duration:(NSTimeInterval)duration;

/*
 *  Rotates view by given angle. TimingFunction can be nil and defaults to kCAMediaTimingFunctionEaseInEaseOut.
 */
- (void)rotateByAngle:(CGFloat)angle
             duration:(NSTimeInterval)duration
          autoreverse:(BOOL)autoreverse
          repeatCount:(CGFloat)repeatCount
       timingFunction:(CAMediaTimingFunction *)timingFunction;

/*
 *  Moves view to point. TimingFunction can be nil and defaults to kCAMediaTimingFunctionEaseInEaseOut.
 */
- (void)moveToPoint:(CGPoint)newPoint
           duration:(NSTimeInterval)duration
        autoreverse:(BOOL)autoreverse
        repeatCount:(CGFloat)repeatCount
     timingFunction:(CAMediaTimingFunction *)timingFunction;

// animation
- (void)startPopAnimationWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay;

// 从中心，从小到大放大
- (void)centerExpandAniamtion;
- (void)dissmissCenterExpandAniamtionCompletBlock:(AnimationCompletBlock)block;

@end
