#include "header.hpp"
#include <cstdint>
#include <ctime>

namespace Xmath{

    int GCD(int a, int b){
        while ( a != b )
            if(a > b)
                a-= b;
            else
                b-= a;
        return a;
    };

    class Tfraction{

    private:

        class Ttemp{
        public:
            bool sign{0};
            uint64_t value{};
            Ttemp(uint64_t a = 0, bool sign = 0){                   //temp var
                value = a;
                this->sign = sign;
            };
        };

        bool sign{};    // 0+ 1-
        uint64_t a{},b{};
        double approx{};

        Tfraction sum(Tfraction other){
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

            return result;
        }

    public:
        Tfraction(uint64_t a = 0, uint64_t b = 1, bool sign = 0){   //constructor 1
            this->sign = sign;
            this->a = a;
            this->b = b;
            approx = double(a) / double(b);
        }

        Tfraction(int a, int b){                                    //constructor 2
            a*b ? this->sign = 0 : this->sign = 1;
            this->a = uint64_t(a);
            this->b = uint64_t(b);
            approx = double(a) / double(b);
        }

        Tfraction operator+(Tfraction other){                       // +
            Tfraction result;

            result = sum(other);

            return result;
        }

        Tfraction operator-(Tfraction other){                       // -
            Tfraction result;
            Tfraction copy{other.a,other.b,!other.sign};

            result = sum(copy);

            return result;
        }

        Tfraction operator*(Tfraction other){                       // *
            Tfraction result;

            //TODO math

            return result;
        }

        Tfraction operator/(Tfraction other){                       // /
            Tfraction result;

            //TODO math

            return result;
        }

        void print(){
            std::cout << (sign ? "-" : "") << a << "/" << b << '\n';
        }

    };

};
