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
#include "Config.h"
#include "CoreAssert_Utils.h"
// CoreAssert - Private
#include "private/PrivateHelpers.h"

NS_COREASSERT_BEGIN

//------------------------------------------------------------------------------
// Assertions are enabled.
#if (COREASSERT_CONFIG_ENABLE_ASSERTS)
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Provides an runtime assertion about the condition.
    /// @param cond
    ///   The condition that will be tested - like (pFile != nullptr),
    ///   if the condition fails, the assertion will be triggered.
    /// @param msg
    ///   A C-style string message - It can contains the same format specifiers
    ///   as the printf(3) would accept.
    /// @param ...
    ///   Variadic arguments that will be used as argument to the format msg.
    /// @see
    ///   COREASSERT_VERIFY.
    #define COREASSERT_ASSERT(_cond_, _msg_, ...) \
        ((_cond_))                                \
         ? (void) 0 /* No-Op */                   \
         : _core_assert_private_print_args(       \
                #_cond_,                          \
                __FILE__,                         \
                __LINE__,                         \
                __func__,                         \
                (_msg_),                          \
                ##__VA_ARGS__                     \
           )

//------------------------------------------------------------------------------
// Assertions are disabled.
#else
    #define COREASSERT_ASSERT(_cond_, _msg_, ...) \
        do { } while(0)

#endif // (COREASSERT_CONFIG_ENABLE_ASSERTS)


#define COREASSERT_ASSERT_NOT_NULL(_var_)                            \
    COREASSERT_ASSERT(                                               \
        _var_ != nullptr,                                            \
         "Var: " _COREASSERT_STRINGIZE_HELPER(_var_) "can't be null" \
    )


NS_COREASSERT_END
