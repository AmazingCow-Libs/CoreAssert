//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : PrivateHelpers.cpp                                            //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../../include/private/PrivateHelpers.h"
// std
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
static char*
vformat(const char *fmt, va_list list)
{
    const size_t kBufferSize = 1024;
    char* buffer = (char*)malloc(kBufferSize);
    memset(buffer, kBufferSize, 0);

    // Build the buffer with the variadic args list.
    vsnprintf(buffer, kBufferSize, fmt, list);

    return buffer;
}


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
static char *
_core_assert_join_args(const char *msg, ...)
{
    va_list args;
    va_start(args, msg);

    // Forward the '...' to vformat
    char *buffer = vformat(msg, args);

    va_end(args);

    return buffer;
}

//------------------------------------------------------------------------------
void _core_assert_private_print_args(
    const    char *expr,
    const    char *file,
    unsigned int   line,
    const    char *func,
    const    char *msg,
    ...)
{
    va_list args;
    va_start(args, msg);

    // Forward the '...' to vformat
    char *buffer = vformat(msg, args);

    va_end(args);

    // Print the message and abort.
    fprintf(stderr,
            "CoreAssert: assertion failed on: \n \
  file       : %s \n \
  line       : %d \n \
  function   : %s \n \
  expression : %s \n \
  message    : %s \n",
            file, line, func, expr, buffer);

    fflush(stderr);
    free(buffer);

    abort();
}
