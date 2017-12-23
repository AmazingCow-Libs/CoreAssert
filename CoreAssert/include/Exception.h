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

    //--------------------------------------------------------------------------
    // Throw If
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

    //--------------------------------------------------------------------------
    // Throw If Not
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
        COREASSERT_ASSERT(!(_cond_), (_fmt_), ##__VA_ARGS__);

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
    #define COREASSERT_THROW_IF(_cond_, _exception_, _fmt_, ...) \
            COREASSERT_VERIFY(!(_cond_), (_fmt_), ##__VA_ARGS__);

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
