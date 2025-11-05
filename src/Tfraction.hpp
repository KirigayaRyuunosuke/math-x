#pragma once

#include "header.hpp"

namespace Xmath{

    class Tfraction{

    private:

        class Ttemp;
        // class Ttemp{
        // public:
        //     bool sign{0};
        //     uint64_t value{};
        //     Ttemp(uint64_t a = 0, bool sign = 0){                   //temp var
        //         value = a;
        //         this->sign = sign;
        //     };
        // };

        bool sign{};    // 0+ 1-
        uint64_t a{},b{};
        double approx{};

        Tfraction reduce(Tfraction);

        Tfraction sum(Tfraction);

        Tfraction mul(Tfraction);

    public:
        Tfraction(uint64_t = 0, uint64_t = 1, bool = 0);

        Tfraction(int, int);

        Tfraction operator+(Tfraction);

        Tfraction operator-(Tfraction);

        Tfraction operator*(Tfraction);

        Tfraction operator/(Tfraction);

        void print(){
            std::cout << (sign ? "-" : "") << a << "/" << b << '\n';
        }

    };

};
