#include <iostream>
#include <math.h>
#include <iomanip>
#include <climits>

#define Billion 1000000000
typedef std::numeric_limits<long double> ld;

long double Euler() {
    long double pi = 0;
    
    for (uint64_t i = 1; i <= Billion; i++) {
        pi += (1.0 / (i * i));
    }
    return sqrt(6 * pi);
}

int main() {
    std::cout << std::setprecision(ld::digits) << "With Euler's method: " << Euler() << std::endl;

    return 0;
}
