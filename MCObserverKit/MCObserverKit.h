//
//  MCObserverKit.h
//
//  Created by Rake Yang on 17/2/9.
//  Copyright © 2017年 BinaryParadise. All rights reserved.
//

/**
 对象KVO快速注册关联,单利模式请手动移除观察者
 */
#import <MCFoundation/MCFoundation.h>
#import "MOKBinding.h"

#define MCBinding(TARGET, ...) \
macro_if_eq(1, macro_argcount(__VA_ARGS__))(_OKit_(TARGET, __VA_ARGS__))(_OKit_(TARGET, __VA_ARGS__))

#define _OKit_(TARGET, KEYPATH) \
[[MOKBinding alloc] initWithTarget:(TARGET)][@keypath(TARGET, KEYPATH)]

#define MCObserver(TARGET, KEYPATH) \
[[MOKObject alloc] initWithTarget:TARGET keyPath:@keypath(TARGET, KEYPATH) mode:MOKBindingModeNone]

#define MCObserverCC(TARGET, KEYPATH) \
[[MOKObject alloc] initWithTarget:TARGET keyPath:@keypath(TARGET, KEYPATH) mode:MOKBindingModeReversible]


@interface MCObserverKit : NSObject

/**
 调试模式
 */
@property (class, nonatomic, assign) BOOL debugMode;

@end
