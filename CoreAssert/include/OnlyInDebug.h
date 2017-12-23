//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : OnlyInDebug.h                                                 //
//  Project   : CoreAssert                                                    //
//  Date      : Dec 14, 2017                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2017                                             //
//                                                                            //
//  Description :                                                             //
//    Provides a way to execute arbitrary code only when the CoreAssert       //
//    is built in Debug mode.                                                 //
//                                                                            //
//    This facilitates and let very clean, that we don't want that code       //
//    to be executed every time, but yet want it in Debug builds              //
//    (usually it's error checking and that kind of things).                  //
//                                                                            //
//    Actually this functionality can be achieved writing a lot of:           //
//      #if (DEBUG)                                                           //
//        if(x != 100)                                                        //
//        {                                                                   //
//           make_something();                                                //
//        }                                                                   //
//      #end if                                                               //
//    But we found that makes code harder to read compared with:              //
//      COREASSERT_ONLY_IN_DEBUG({                                            //
//          if(x != 0) { make_something(); }                                  //
//      });                                                                   //
//---------------------------------------------------------------------------~//

#pragma once

// CoreAssert
#include "Config.h"

//------------------------------------------------------------------------------
// Debug Mode.
#if (COREASSERT_CONFIG_MODE == COREASSERT_CONFIG_MODE_DEBUG)

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Let us execute arbritary pieces of code only when the CoreAssert
    ///   is built in DEBUG mode.
    /// @param code
    ///   Any piece of code ;D
    #define COREASSERT_ONLY_IN_DEBUG(_code_) do { _code_ } while(0);

//------------------------------------------------------------------------------
// Release mode.
#else
    #define COREASSERT_ONLY_IN_DEBUG(_code_) do {} while(0);

#endif // (COREASSERT_CONFIG_MODE == COREASSERT_CONFIG_MODE_DEBUG)
