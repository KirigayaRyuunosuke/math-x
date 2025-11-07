# math-x

## Run
To simply run the program use compile.sh script, which compiles files, run the program and removes it at the end
```bash
g++ main.cpp src/*.cpp -o program;  # compile
./program;                          # run
rm -f program;                      # remove
```
## Tfraction
This class allows for rather simple use of common fractions.
```cpp
Tfraction(uint64_t a = 0, uint64_t b = 1, bool sign = 0)
```
This constuctor takes a and b as in a/b common fraction, and also the sign, which is 0 for + and 1 for -

### Usage
```cpp
Xmath::Tfraction a{1,2};    // 1/2
Xmath::Tfraction b{3,4,1};  // -3/4
```
#### All basic operations support
```cpp
a = a - b;
a = a + b;
a = a * b;
a = a / b;
```

#### Printing
```cpp
a.print();
```

## Xmath
I use it to store my math-related functon(s)

### GCD
```cpp
uint64_t GCD(uint64_t a, uint64_t b)
```

### Factorial
```cpp
long factorial(long number)
```

### Power
```cpp
double power(double a, int b)
```
### inline version
In each of factorial() and power() is comment with simpler inline version. Use with caution! No edge case scenarios included for better readability.

### sin
```cpp
double sin(double x, int precision){
        double result = x;

        if(precision > 0)
            result = power(-1, precision) * (power(x, (2 * precision + 1) ) / ( factorial( 2 * precision + 1) ) ) + sin(x, precision - 1);

        return result;
    };
```
This function uses factorial() and power() to compute sin using Taylor series, where ```int precision``` is number of elements in series to calculate
