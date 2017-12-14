#pragma once

// CoreAssert
#include "CoreAssert_Utils.h"
// CoreAssert - Private
#include "private/PrivateHelpers.h"

NS_COREASSERT_BEGIN

//------------------------------------------------------------------------------
// Assertions are enabled.
#if (COREASSERT_CONFIG_ENABLE_ASSERTS)

    #define COREASSERT_ASSERT(_cond_, _msg_, ...)        \
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

//------------------------------------------------------------------------------
// Assertions are disabled.
#else
    #define COREASSERT_ASSERT(_cond_, _msg_, ...) \
        do { } while(0)

#endif // (COREASSERT_CONFIG_ENABLE_ASSERTS)

NS_COREASSERT_END
