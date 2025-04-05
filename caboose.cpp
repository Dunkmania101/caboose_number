/*
   It seems like this might be pointless, according to this website: https://archive.lib.msu.edu/crcmath/math/math/l/l447.htm
*/

#include <iostream>
//#include <cmath> // sqrt is provided by BigInt
#include "BigInt.hpp" // https://faheel.github.io/BigInt/

using namespace std;


int main(int argc, char** argv) {
    BigInt c = 1;
    bool pass = true;

    BigInt start;
    if (argc >= 3) {
        start = argv[2];
    } else {
        start = 0;
    }

    BigInt times;
    if (argc >= 2) {
        times = argv[1];
    } else {
        times = 99999999999;
    }

    for (BigInt t = start; t < times; t++) {
        c++;

        pass = true;
        for (BigInt n = 1; n < c; n++) {
            BigInt x = (n*n)-n+c;
            for (BigInt a = 2; a < sqrt(x); a++) {
                //cout << x << " mod " << a << " == " << x%a << "\n\n";
                if (x%a == 0) {
                    pass = false;
                    break;
                }
            }

            if (!pass) {
                break;
            }
        }

        if (pass) {
            cout << "CABOOSE:";
        } else {
            cout << "non-CABOOSE:";
        }
        cout << "\nc = " << c << "\n\n===\n\n";
    }

    return 0;
}

