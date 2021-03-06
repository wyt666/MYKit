//
//  UIViewController+ClassName.m
//  MYKitDemo
//
//  Created by sunjinshuai on 2018/3/23.
//  Copyright © 2018年 com.51fanxing. All rights reserved.
//

#import "UIViewController+ClassName.h"
#import "UIDevice+Extension.h"
#import <objc/runtime.h>

#define kClassNameTag 20000

static BOOL displayClassName = NO;

@implementation UIViewController (ClassName)

+ (void)displayClassName:(BOOL)yesOrNo {
    displayClassName = yesOrNo;
    if (displayClassName) {
        [self displayClassName];
    } else {
        [self removeClassName];
    }
}

+ (void)load {
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Class class = [self class];
        
        SEL originalSelector = @selector(viewDidAppear:);
        SEL swizzledSelector = @selector(yn_viewDidAppear:);
        
        Method originalMethod = class_getInstanceMethod(class, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(class, swizzledSelector);
        
        // When swizzling a class method, use the following:
        // Class class = object_getClass((id)self);
        // ...
        // Method originalMethod = class_getClassMethod(class, originalSelector);
        // Method swizzledMethod = class_getClassMethod(class, swizzledSelector);
        
        BOOL didAddMethod = class_addMethod(class,
                                            originalSelector,
                                            method_getImplementation(swizzledMethod),
                                            method_getTypeEncoding(swizzledMethod));
        
        if (didAddMethod) {
            class_replaceMethod(class,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        } else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}

#pragma mark - Method Swizzling

- (void)yn_viewDidAppear:(BOOL)animated {
    [self yn_viewDidAppear:animated];
    
    if (displayClassName) {
        [[self class] displayClassName];
    }
}

+ (void)displayClassName {
    UIWindow *window = [self appWindow];
    
    UILabel *classNameLabel;
    if ([window viewWithTag:kClassNameTag]) {
        classNameLabel = (UILabel *)[window viewWithTag:kClassNameTag];
        [window bringSubviewToFront:classNameLabel];
    } else {
        classNameLabel = [[UILabel alloc] initWithFrame:CGRectMake(5, 15 + ([UIDevice isIphoneX] ? 20 : 0), window.bounds.size.width, 20)];
        classNameLabel.textColor = [UIColor redColor];
        classNameLabel.font = [UIFont systemFontOfSize:12];
        classNameLabel.tag = kClassNameTag;
        [window addSubview:classNameLabel];
        [window bringSubviewToFront:classNameLabel];
    }
    
    classNameLabel.userInteractionEnabled = NO;
    
    const char *className = class_getName(self.class);
    NSString *classNameStr = [NSString stringWithCString:className encoding:NSUTF8StringEncoding];
    
    if ([self needDisplay:classNameStr]) {
        [classNameLabel setText:classNameStr];
    }
}

+ (void)removeClassName {
    UIWindow *window = [self appWindow];
    
    UILabel *classNameLabel;
    if ([window viewWithTag:kClassNameTag]) {
        classNameLabel = (UILabel *)[window viewWithTag:kClassNameTag];
        [classNameLabel removeFromSuperview];
    }
}

+ (BOOL)needDisplay:(NSString *)className {
    if ([className isEqualToString:@"UIInputWindowController"] || [className isEqualToString:@"UINavigationController"] || [className isEqualToString:@"UIApplicationRotationFollowingControllerNoTouches"]) {
        return NO;
    } else if ([NSClassFromString(className) isSubclassOfClass:[UIInputViewController class]]) {    // 输入类controller
        return NO;
    } else {
        return YES;
    }
}

+ (UIWindow *)appWindow {
    id<UIApplicationDelegate> appDelegate = [UIApplication sharedApplication].delegate;
    return [appDelegate window];
}

@end
