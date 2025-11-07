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

        long result = number;
        if(number > 1)
            result *= factorial(number - 1);
        else
            result = 1;
        return result;

        //return (number > 1) ? number *= factorial(number - 1) : number;

    }

    double power(double a, int b){

        if(b == 0)
            return 1;

        double result = a;
        if(b > 1)
            result *= power(a, b-1);

        return result;

        //return (b > 1) ? a *= power( a, b-1 ) : a;

    }

    double sin(double x, int precision){
        double result = x;

        if(precision > 0)
            result = power(-1, precision) * (power(x, (2 * precision + 1) ) / ( factorial( 2 * precision + 1) ) ) + sin(x, precision - 1);

        return result;
    };
}
