# math-x

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
I use it to store some math-related functon(s)

### GCD
```cpp
uint64_t GCD(uint64_t a, uint64_t b)
```
This function allows for reducing fractions
