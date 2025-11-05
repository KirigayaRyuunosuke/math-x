#pragma once

#include "header.hpp"

namespace Xmath{
    inline uint64_t GCD(uint64_t a, uint64_t b){
        while ( a != b )
            if(a > b)
                a-= b;
            else
                b-= a;
        return a;
    };
}
