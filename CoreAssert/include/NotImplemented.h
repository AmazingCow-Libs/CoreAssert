//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : NotImplemented.h                                              //
//  Project   : CoreAssert                                                    //
//  Date      : Jan 25, 2018                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2018                                             //
//                                                                            //
//  Description :                                                             //
//    Simple implementation of NotImplementedException to mark that the       //
//    code block is currently in development.                                 //
//    The idea is to use it in the same way that C# does.                     //
//---------------------------------------------------------------------------~//

#pragma once

// std
#include <exception>
#include <string>
// CoreAssert
#include "Exception.h"


//----------------------------------------------------------------------------//
// Types                                                                      //
//----------------------------------------------------------------------------//
namespace CoreAssert {

class NotImplementedException
    : public std::runtime_error
{
    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    NotImplementedException(const char *p_message)
        : std::runtime_error(p_message)
    {
        // Empty...
    }

    NotImplementedException(const std::string &message)
        : NotImplementedException(message.c_str())
    {
        // Empty...
    }

}; // class NotImplementedException
}  // namespace CoreAssert

//----------------------------------------------------------------------------//
// MACROS                                                                     //
//----------------------------------------------------------------------------//
#define COREASSERT_NOT_IMPLEMENTED(_fmt_, ...) \
    COREASSERT_THROW_IF(                       \
        true,                                  \
        CoreAssert::NotImplementedException,   \
        _fmt_,                                 \
        ##__VA_ARGS__                          \
    )
