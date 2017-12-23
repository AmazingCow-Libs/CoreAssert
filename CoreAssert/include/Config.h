//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Config.h                                                      //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//    Configurations in how CoreAssert behaves.                               //
//---------------------------------------------------------------------------~//

#pragma once

//----------------------------------------------------------------------------//
// Debug Configs                                                              //
//----------------------------------------------------------------------------//
#define COREASSERT_CONFIG_MODE_DEBUG   1
#define COREASSERT_CONFIG_MODE_RELEASE 0

//------------------------------------------------------------------------------
// Change this to alter how CoreAssert is built.
// By default CoreAssert behaves like:
//    DEBUG   -> ASSERT enabled,  VERIFY enabled
//    RELEASE -> ASSERT disabled, VERIFY enabled
#define COREASSERT_CONFIG_MODE COREASSERT_CONFIG_MODE_DEBUG


//----------------------------------------------------------------------------//
// Assert Configs                                                             //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// Change this to alter how CoreAssert handle ASSERTS.
//   By default it's using the CONFIG_MODE value, meaning that in DEBUG builds
//   the ASSERTs will be enabled, but in RELEASED they will be disabled.
//   Changing this you can disable or enable any time that you wish.
#define COREASSERT_CONFIG_ENABLE_ASSERTS COREASSERT_CONFIG_MODE


//----------------------------------------------------------------------------//
// Exceptions Configs                                                         //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
// This changes how exceptions that are thrown with the CoreAssert macros are
// handled.
//
// When a exception is thrown by the COREASSERT_THROW_IF(_NOT) macros, the
// options bellow changes what's really visible by the compiler when it's
// producing the code.
//
// By doing this way we can still make code that throws exceptions but let
// the clients decide how to use them. For example, if a piece of code
// can't handle exceptions at all, it can disable the exceptions by setting
// COREASSERT_CONFIG_ENABLE_EXCEPTIONS to 0 and the compiler will
// emit the code for ASSERT of a VERIFY instead.
//
// Notice the implications of this model, when the user set to not use
// exceptions, set the replacement of ASSERTs and make the build for RELEASE.
// ** In practice the compiler will not emit any error at all. **
// So use this wisely.
#define COREASSERT_CONFIG_ENABLE_EXCEPTIONS         1
#define COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS 0
#define COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS 0

#if !COREASSERT_CONFIG_ENABLE_EXCEPTIONS && (COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS == COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS)
    #error "Cannot have both Assert and Verify instead Exception."
#endif

