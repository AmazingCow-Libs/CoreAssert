//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreAssert_Utils.h                                            //
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

//----------------------------------------------------------------------------//
// Namespaces                                                                 //
//----------------------------------------------------------------------------//
// All classes of this core is placed inside this namespace.
// We use MACROS so is easier to change if needed.
// Is (in our opinion) more explicit.
// And finally the editors will not reformat the code.
#define NS_COREASSERT_BEGIN namespace CoreAssert {
#define NS_COREASSERT_END   }
#define USING_NS_COREASSERT using namespace CoreAssert


//----------------------------------------------------------------------------//
// Version                                                                    //
//----------------------------------------------------------------------------//
#define COW_COREASSERT_VERSION_MAJOR    "0"
#define COW_COREASSERT_VERSION_MINOR    "0"
#define COW_COREASSERT_VERSION_REVISION "1"

#define COW_COREASSERT_VERSION       \
    COW_COREASSERT_VERSION_MAJOR "." \
    COW_COREASSERT_VERSION_MINOR "." \
    COW_COREASSERT_VERSION_REVISION
