//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Exception.h                                                   //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//    Those macros provide ways to you conditionally control if the code      //
//    should throw an exception or instead be an ASSERT or VERIFY.            //
//                                                                            //
//    This way we can still write code that throw exceptions but let the      //
//    clients disable them and instead opt out.                               //
//                                                                            //
//    The effect is achieved in two steps:                                    //
//      1 - You write the code normally as it would throw the exception, but  //
//          instead of use the "naked" throw mechanism you use the following  //
//          macros instead.                                                   //
//      2 - The client of the code, set in Config.h what is the replacement   //
//          of the following macros if he wants to not have exceptions        //
//          at all.                                                           //
//                                                                            //
//    Notice that this have two implications. With exceptions you allways can //
//    catch it - and possible handle - but if you disable the exceptions you  //
//    won't have this possibility, so the program will abort.                 //
//    Moreover if you set the replacement for COREASSERT_ASSERT and disable   //
//    assertions in RELEASE builds, you will HAVE NOTHING in the exceptional  //
//    situation.                                                              //
//                                                                            //
//    So use this with care....                                               //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// CoreAssert
#include "CoreAssert_Utils.h"
#include "Config.h"
#include "Assert.h"
#include "Verify.h"
// CoreAssert - Private
#include "CoreAssert/include/private/PrivateHelpers.h"

NS_COREASSERT_BEGIN

//------------------------------------------------------------------------------
// Exceptions are enabled.
//   So just plain throw a exception if condition is not met.
//   This is the most straightforward case.
#if (COREASSERT_CONFIG_ENABLE_EXCEPTIONS)

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Throws a exception if the condition is met.
    /// @param cond
    ///   The condition that will be tested. If it evaluates to true
    ///   a exception will be throw, otherwise just ignored.
    /// @param exception
    ///   The type of exception that will be thrown.
    /// @param fmt
    ///   The C-style string message that will be used to
    ///   construct the exception. It can use any format specifiers
    ///   that printf(3) would use as well.
    /// @param ...
    ///   Variadic arguments that will be used as argument to the format msg.
    /// @note
    ///   This macro replacement is controlled by
    ///   COREASSERT_CONFIG_ENABLE_EXCEPTIONS definition found in the Config.h
    ///   file, meaning that if it's disable, the code will not generate an
    ///   exception but instead a ASSERT or VERIFY.
    /// @see
    ///   COREASSERT_CONFIG_ENABLE_EXCEPTIONS
    ///   COREASSERT_THROW_IF_NOT
    ///   COREASSERT_VERIFY
    ///   COREASSERT_ASSERT
    #define COREASSERT_THROW_IF(_cond_, _exception_, _fmt_, ...)  \
        do {                                                      \
            if((_cond_)) {                                        \
                throw _exception_(                                \
                    CoreAssert::Private::_core_assert_join_args(  \
                        _fmt_,                                    \
                        ##__VA_ARGS__                             \
                    )                                             \
                );                                                \
            }                                                     \
        } while(0);

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Same as COREASSERT_THROW_IF, but only generate exceptions when
    ///   condition isn't met.
    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...)  \
        COREASSERT_THROW_IF(!(_cond_), (_exception_), (_fmt_), ##__VA_ARGS__);

//------------------------------------------------------------------------------
// Exceptions ARE NOT enabled.
//   But CoreAssert is configure to replace them with Assertions instead.
//   So build a COREASSERT that provides enough info about what's going on.
#elif (COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS)

    //--------------------------------------------------------------------------
    // Throw If
    #define COREASSERT_THROW_IF(_cond_, _exception_, _fmt_, ...) \
        COREASSERT_ASSERT(                                       \
            !(_cond_),                                           \
            /* This will print the exception name */             \
            CoreAssert::Private::_core_assert_join_args(         \
                "(%s): %s",                                      \
                #_exception_,                                    \
                _fmt_                                            \
            ).c_str(),                                           \
            ##__VA_ARGS__                                        \
        );

    //--------------------------------------------------------------------------
    // Throw If Not
    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...)  \
        COREASSERT_THROW_IF(!(_cond_), (_exception_), (_fmt_), ##__VA_ARGS__);


//------------------------------------------------------------------------------
// Exceptions ARE NOT enabled.
//   But CoreAssert is configure to replace them with Verifies instead.
//   So build a COREASSERT that provides enough info about what's going on.
#elif (COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS)

    //--------------------------------------------------------------------------
    // Throw If
    #define COREASSERT_THROW_IF(_cond_, _exception_, _fmt_, ...)     \
            COREASSERT_VERIFY(                                       \
                !(_cond_),                                           \
                /* This will print the exception name */             \
                CoreAssert::Private::_core_assert_join_args(         \
                    "(%s): %s",                                      \
                    #_exception_,                                    \
                    _fmt_                                            \
                ).c_str(),                                           \
                ##__VA_ARGS__                                        \
        );

    //--------------------------------------------------------------------------
    // Throw If Not
    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...)  \
        COREASSERT_THROW_IF(!(_cond_), (_exception_), (_fmt_), ##__VA_ARGS__);


//------------------------------------------------------------------------------
// Exceptions ARE NOT enabled.
//   And CoreAssert is configured to not replace them with anything...
#else
    //--------------------------------------------------------------------------
    // Throw If
    #define COREASSERT_THROW_IF(_cond_, _exception_, _fmt_, ...) \
        do { } while(0);

    //--------------------------------------------------------------------------
    // Throw If Not
    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...)  \
        COREASSERT_THROW_IF(!(_cond_), (_exception_), (_fmt_), ##__VA_ARGS__);

#endif // COREASSERT_CONFIG_ENABLE_EXCEPTIONS


NS_COREASSERT_END
