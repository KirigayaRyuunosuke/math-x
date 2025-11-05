#include "header.hpp"
#include "Xmath.hpp"

#include "Tfraction.hpp"

namespace Xmath{

    class Tfraction::Ttemp{
    public:
        bool sign{0};
        uint64_t value{};
        Ttemp(uint64_t a = 0, bool sign = 0){                   //temp var
            value = a;
            this->sign = sign;
        };
    };

    Tfraction Tfraction::reduce(Tfraction input){
        uint64_t gcd = GCD(input.a,input.b);
        if(gcd > 1){
            input.a /= gcd;
            input.b /= gcd;
        }
        return input;
    }

    Tfraction Tfraction:: sum(Tfraction other){                             //sum function
        Tfraction result{this->a, this->b, this->sign};
        Ttemp a1,a2,a3;

        a1.value = result.a * other.b;
        a2.value = result.b * other.a;

        result.b = result.b * other.b;

        a1.sign = result.sign;
        a2.sign = other.sign;

        if(a1.sign == a2.sign){
            result.sign = a1.sign;
            result.a = a1.value+a2.value;
        }
        else{
            if(a1.sign){
                result.sign = !(a1.value < a2.value);
                result.a = a1.value-a2.value;
            }
            else {
                result.sign = !(a1.value > a2.value);
                result.a = a2.value-a1.value;
            }
        }
        result = reduce(result);
        return result;
    }

    Tfraction Tfraction:: mul(Tfraction other){
        Tfraction result{this->a, this->b, this->sign};
        result.a *= other.a;
        result.b *= other.b;
        if(result.sign == other.sign)
            result.sign = 0;
        else result.sign = 1;
        result = reduce(result);
        return result;
    }


    Tfraction::Tfraction(uint64_t a, uint64_t b, bool sign){   //constructor 1
        this->sign = sign;
        this->a = a;
        this->b = b;
        approx = double(a) / double(b);
    }

    Tfraction::Tfraction(int a, int b){                                    //constructor 2
        a*b ? this->sign = 0 : this->sign = 1;
        this->a = uint64_t(a);
        this->b = uint64_t(b);
        approx = double(a) / double(b);
    }

    Tfraction Tfraction::operator+(Tfraction other){                       // +
        Tfraction result;

        result = sum(other);

        return result;
    }

    Tfraction Tfraction::operator-(Tfraction other){                       // -
        Tfraction result;
        Tfraction copy{other.a,other.b,!other.sign};

        result = sum(copy);

        return result;
    }

    Tfraction Tfraction::operator*(Tfraction other){                       // *
        Tfraction result;

        result = mul(other);

        return result;
    }

    Tfraction Tfraction::operator/(Tfraction  other){                       // /
        Tfraction result;
        Tfraction copy{other.b,other.a,other.sign};

        result = mul(copy);

        return result;
    }
};

