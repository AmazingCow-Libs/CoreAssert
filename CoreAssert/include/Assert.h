//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Assert.h                                                      //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//    Provides a better assetion model than the standard assert macro         //
//    by the libc.                                                            //
//                                                                            //
//    The Asserts will have information of:                                   //
//      1 - The condition (the actual text) that failed.                      //
//      2 - The file path.                                                    //
//      3 - The line number.                                                  //
//      4 - The function the ASSERT is.                                       //
//      5 - A user given message with variadic arguments like printf(3)       //
//---------------------------------------------------------------------------~//

#pragma once

// CoreAssert
#include "CoreAssert_Utils.h"
// CoreAssert - Private
#include "private/PrivateHelpers.h"

NS_COREASSERT_BEGIN

//------------------------------------------------------------------------------
// Assertions are enabled.
#if (COREASSERT_CONFIG_ENABLE_ASSERTS)

    #define COREASSERT_ASSERT(_cond_, _msg_, ...)        \
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

//------------------------------------------------------------------------------
// Assertions are disabled.
#else
    #define COREASSERT_ASSERT(_cond_, _msg_, ...) \
        do { } while(0)

#endif // (COREASSERT_CONFIG_ENABLE_ASSERTS)

NS_COREASSERT_END
