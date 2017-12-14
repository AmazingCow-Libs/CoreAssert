#pragma once

//----------------------------------------------------------------------------//
// Debug Configs                                                              //
//----------------------------------------------------------------------------//
#define COREASSERT_CONFIG_MODE_DEBUG   1
#define COREASSERT_CONFIG_MODE_RELEASE 0

#define COREASSERT_CONFIG_MODE COREASSERT_CONFIG_MODE_DEBUG


//----------------------------------------------------------------------------//
// Assert Configs                                                             //
//----------------------------------------------------------------------------//
#define COREASSERT_CONFIG_ENABLE_ASSERTS COREASSERT_CONFIG_MODE


//----------------------------------------------------------------------------//
// Exceptions Configs                                                         //
//----------------------------------------------------------------------------//
#define COREASSERT_CONFIG_ENABLE_EXCEPTIONS         0
#define COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS 0
#define COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS 1

#if !COREASSERT_CONFIG_ENABLE_EXCEPTIONS && (COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS == COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS)
    #error "Cannot have both Assert and Verify instead Exception."
#endif

