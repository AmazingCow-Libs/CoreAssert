#pragma once

// CoreAssert
#include "CoreAssert_Utils.h"
// CoreAssert - Private
#include "lib/CoreAssert/CoreAssert/include/private/PrivateHelpers.h"


NS_COREASSERT_BEGIN

#define COREASSERT_VERIFY(_cond_, _msg_, ...)        \
    ((_cond_))                                       \
     ? (void) 0 /* No-Op */                          \
     : CoreAssert::Private::_core_assert_print_args( \
            #_cond_,                                 \
            __FILE__,                                \
            __LINE__,                                \
            __func__,                                \
            (_msg_),                                 \
            ##__VA_ARGS__                            \
       )

NS_COREASSERT_END
