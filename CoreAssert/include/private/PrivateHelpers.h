//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : PrivateHelpers.h                                              //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <stdarg.h>
#include <string.h>
// CoreAssert
#include "include/CoreAssert_Utils.h"

//----------------------------------------------------------------------------//
// Macros                                                                     //
//----------------------------------------------------------------------------//
#define _COREASSERT_STRINGIZE_HELPER(A) #A
#define COREASSERT_STRINGIZE(A) _COREASSERT_STRINGIZE_HELPER(A)


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
COREASSERT_EXTERN_C char *
_core_assert_private_join_args(const char *fmt, ...);

COREASSERT_EXTERN_C void
_core_assert_private_print_args(
    const    char   *expr,
    const    char   *file,
    unsigned int     line,
    const    char   *func,
    const    char   *msg,
    ...);
