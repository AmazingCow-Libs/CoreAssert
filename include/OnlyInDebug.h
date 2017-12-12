#pragma once

// CoreAssert
#include "Config.h"

#if (COREASSERT_CONFIG_MODE == COREASSERT_CONFIG_MODE_DEBUG)

    #define COREASSERT_ONLY_IN_DEBUG(_code_) do { _code_ } while(0);

#else
    #define COREASSERT_ONLY_IN_DEBUG(_code_) do {} while(0);

#endif // (COREASSERT_CONFIG_MODE == COREASSERT_CONFIG_MODE_DEBUG)
