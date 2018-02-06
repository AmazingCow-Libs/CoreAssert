
add_library(CoreAssert
    CoreAssert/src/private/PrivateHelpers.cpp
)

target_include_directories(CoreAssert PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
