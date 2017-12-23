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

///-------------------------------------------------------------------------
/// @brief
///   Provides an runtime verification about the condition.
///   This works **exactly** like COREASSERT_ASSERT but instead isn't
//    stripped out in RELEASE builds.
/// @param cond
///   The condition that will be tested - like (pFile != nullptr),
///   if the condition fails, the assertion will be triggered.
/// @param msg
///   A C-style string message - It can contains the same format specifiers
///   as the printf(3) would accept.
/// @param ...
///   Variadic arguments that will be used as argument to the format msg.
/// @see
///   COREASSERT_ASSERT.
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
