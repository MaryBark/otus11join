#include "error_code.h"

std::string join_query::error_string(error_code ec)
{
    const char * ERRORS[] = {	"OK",
                                "parse error",
                                "duplicate element" };

    return	(error_code::ok == ec ? std::string() : std::string("ERR ")) +
            ERRORS[static_cast<int>(ec)];
}
