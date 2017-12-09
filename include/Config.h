#pragma once

//----------------------------------------------------------------------------//
// Assert Configs                                                             //
//----------------------------------------------------------------------------//
#define COREASSERT_CONFIG_ENABLE_ASSERTS 1


//----------------------------------------------------------------------------//
// Exceptions Configs                                                         //
//----------------------------------------------------------------------------//
#define COREASSERT_CONFIG_ENABLE_EXCEPTIONS         1
#define COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS 0
#define COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS 0

#if !COREASSERT_CONFIG_ENABLE_EXCEPTIONS && (COREASSERT_CONFIG_ASSERT_INSTEAD_EXCEPTIONS == COREASSERT_CONFIG_VERIFY_INSTEAD_EXCEPTIONS)
    #error "Cannot have both Assert and Verify instead Exception."
#endif

