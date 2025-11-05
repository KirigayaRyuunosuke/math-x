#include "header.hpp"
#include "Xmath.hpp"

namespace Xmath{
    uint64_t GCD(uint64_t a, uint64_t b) {
    while (b != 0) {
        uint64_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    long factorial(long number){

        return (number > 1) ? number *= factorial(number - 1) : number;

    }

    double power(double a, int b){

        return (b > 1) ? a *= power( a, b-1 ) : a;

    }

    double sin(double x, int precision){
        double result = x;

        if(precision > 0)
            result = power(-1, precision) * (power(x, (2 * precision + 1) ) / ( factorial( 2 * precision + 1) ) ) + sin(x, precision - 1);

        return result;
    };
}
