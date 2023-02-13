#ifndef ERROR_CODE_H
#define ERROR_CODE_H

#pragma once
#include <string>

namespace join_query
{
    enum class error_code
    {
        ok			= 0,
        parse_error = 1,
        duplicate	= 2
    };

    std::string error_string(error_code ec);
}


#endif // ERROR_CODE_H
