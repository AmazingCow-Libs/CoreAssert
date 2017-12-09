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

    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...)     \
        do {                                                             \
            if(!(_cond_)) {                                              \
                throw _exception_(                                       \
                    CoreAssert::Private::_core_assert_join_args(         \
                        _fmt_,                                           \
                        ##__VA_ARGS__                                    \
                    )                                                    \
                );                                                       \
            }                                                            \
        } while(0);


//------------------------------------------------------------------------------
// Exceptions ARE NOT enabled.
//   But CoreAssert is configure to replace them with Assertions instead.
//   So build a COREASSERT that provides enough info about what's going on.
#elif (COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS)

    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...) \
        COREASSERT_ASSERT(_cond_, _fmt_, ##__VA_ARGS__);


//------------------------------------------------------------------------------
// Exceptions ARE NOT enabled.
//   But CoreAssert is configure to replace them with Verifies instead.
//   So build a COREASSERT that provides enough info about what's going on.
#elif (COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS)

    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...) \
            COREASSERT_VERIFY(_cond_, _fmt_, ##__VA_ARGS__);


//------------------------------------------------------------------------------
// Exceptions ARE NOT enabled.
//   And CoreAssert is configured to not replace them with anything...
#else
    #define COREASSERT_THROW_IF_NOT(_cond_, _exception_, _fmt_, ...) \
        do { } while(0);

#endif // COREASSERT_CONFIG_ENABLE_EXCEPTIONS


NS_COREASSERT_END
