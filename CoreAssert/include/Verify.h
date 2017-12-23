//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Verify.h                                                      //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//    Like COREASSERT_ASSERT but the checks are kept even in release          //
//    builds, so with the check fails you gonna get the program to abort      //
//    the a nice descriptive message.                                         //
//---------------------------------------------------------------------------~//

#pragma once

// CoreAssert
#include "CoreAssert_Utils.h"
// CoreAssert - Private
#include "../include/private/PrivateHelpers.h"


NS_COREASSERT_BEGIN

#define COREASSERT_VERIFY(_cond_, _msg_, ...)        \
    ((_cond_))                                       \
     ? (void) 0 /* No-Op */                          \
     : CoreAssert::Private::_core_assert_print_args( \
            #_cond_,                                 \
            __FILE__,                                \
            __LINE__,                                \
            __func__,                                \
            (_msg_),                                 \
            ##__VA_ARGS__                            \
       )

NS_COREASSERT_END
