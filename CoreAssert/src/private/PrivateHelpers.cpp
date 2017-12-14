// Header
#include "../../include/private/PrivateHelpers.h"

// Usings
USING_NS_COREASSERT;


//----------------------------------------------------------------------------//
// Helper Functions                                                           //
//----------------------------------------------------------------------------//
namespace {
    std::string vformat(const char *fmt, std::va_list list)
    {
        constexpr int kBufferSize = 1024;
        char buffer[kBufferSize]  = {'\0'};

        // Build the buffer with the variadic args list.
        vsnprintf(buffer, kBufferSize, fmt, list);

        return std::string(buffer);
    }
}


//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//
//------------------------------------------------------------------------------
std::string Private::_core_assert_join_args(const char *msg, ...)
{
    va_list args;
    va_start(args, msg);

    // Forward the '...' to vformat
    auto buffer = vformat(msg, args);

    va_end(args);

    return std::string(buffer);
}

//------------------------------------------------------------------------------
void Private::_core_assert_print_args(
    const    char *expr,
    const    char *file,
    unsigned int   line,
    const    char *func,
    const    char *msg,
    ...)
{
    va_list args;
    va_start(args, msg);

    // Forward the '...' to vformat
    auto buffer = vformat(msg, args);

    va_end(args);

    // Print the message and abort.
    fprintf(stderr,
            "Cooper Assert: assertion failed on: \n \
  file       : %s \n \
  line       : %d \n \
  function   : %s \n \
  expression : %s \n \
  message    : %s \n",
            file, line, func, expr, buffer.c_str());

    abort();
}


