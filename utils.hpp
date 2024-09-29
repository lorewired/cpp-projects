#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

typedef long double __longD;
typedef std::string __str;

struct account_handle_response {
    unsigned status;
    __str message;
};

#endif