#pragma once

// std
#include <cstdarg>
#include <string>
// CoreAssert
#include "../CoreAssert_Utils.h"

NS_COREASSERT_BEGIN

namespace Private {

//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
std::string _core_assert_join_args(const char *msg, ...);


//------------------------------------------------------------------------------
void _core_assert_print_args(
    const    char   *expr,
    const    char   *file,
    unsigned int     line,
    const    char   *func,
    const    char   *msg,
    ...);

} // namespace Private
NS_COREASSERT_END
