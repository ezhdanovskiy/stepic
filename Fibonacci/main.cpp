#include <cassert>
#include <cstdint>
#include <iostream>

#define LOG(chain) std::cout << chain << std::endl;
//#define LOG(chain)

#define LOG1(el) std::cout << #el << "=" << (el) << std::endl;
//#define LOG1(el)

class Fibonacci final {
public:
    static int get_remainder0(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);
        // put your code here

        assert(n <= 1000000000000000000);
        assert(m <= 100000);
        int64_t f1 = 0;
        int64_t f2 = 1;
        for (int64_t i = 2; i <= n; ++i) {
            int64_t f = (f2 + f1) % m;
            f1 = f2;
            f2 = f;
        }
        n = f2;

        return n % m;
    }

    static int get_remainder1(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);
        // put your code here

        assert(n <= 1000000000000000000);
        assert(m <= 100000);
        int F[2][2] = {{1, 1},
                       {1, 0}};
        int M[2][2] = {{1, 1},
                       {1, 0}};
        for (int i = 2; i < n; ++i) {
            int f00 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
            int f01 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
            int f10 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
            int f11 = F[1][0] * M[0][1] + F[1][1] * M[1][1];
            F[0][0] = f00 % m;
            F[0][1] = f01 % m;
            F[1][0] = f10 % m;
            F[1][1] = f11 % m;
        }

        return F[0][0];
    }

    static int get_remainder2(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);
        // put your code here

        assert(n <= 1000000000000000000);
        assert(m <= 100000);
        int F[2][2] = {{1, 1}, {1, 0}};

        auto multiply = [m](int F[2][2], int M[2][2]) {
            int f00 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
            int f01 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
            int f10 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
            int f11 = F[1][0] * M[0][1] + F[1][1] * M[1][1];
            F[0][0] = f00 % m;
            F[0][1] = f01 % m;
            F[1][0] = f10 % m;
            F[1][1] = f11 % m;
        };

        auto power = [multiply](int F[2][2], int64_t n) {
            int M[2][2] = {{1, 1}, {1, 0}};
            for (int64_t i = 1; i < n; ++i) {
                multiply(F, M);
            }
        };

        power(F, n - 1);

        return F[0][0];
    }

    static int get_remainder_(int64_t n, int m) {
        assert(n >= 0);
        // put your code here
        assert(n <= 40);
        int n1 = n;
        int v[41];
        v[0] = 0;
        v[1] = 1;
        int i = 2;
        for (; i <= n1; ++i) {
            v[i] = v[i-1] + v[i-2];
        }
        n = v[i-1];
        return n % m;
    }

    static int get_remainder(int64_t n, int m) {
        assert(n >= 1);
        assert(m >= 2);
        // put your code here

        assert(n <= 1000000000000000000);
        assert(m <= 100000);

        auto multiply = [m](int64_t F[2][2], int64_t M[2][2]) {
            int64_t f00 = F[0][0] * M[0][0] + F[0][1] * M[1][0];
            int64_t f01 = F[0][0] * M[0][1] + F[0][1] * M[1][1];
            int64_t f10 = F[1][0] * M[0][0] + F[1][1] * M[1][0];
            int64_t f11 = F[1][0] * M[0][1] + F[1][1] * M[1][1];
            F[0][0] = f00 % m;
            F[0][1] = f01 % m;
            F[1][0] = f10 % m;
            F[1][1] = f11 % m;
        };

        auto power = [multiply](int64_t F[2][2], int64_t n) {
            int64_t M[2][2] = {{1, 1}, {1, 0}};
            while (n) {
                if (n & 1) {
                    multiply(F, M);
                }
                multiply(M, M);
                n >>= 1;
            }
        };

        int64_t F[2][2] = {{1, 0}, {0, 1}};
        power(F, n - 1);
        n = F[0][0];

        return n % m;
    }

};

int main(void) {
    int64_t n = 40;
    int m = 1000;
//    std::cin >> n >> m;
//    std::cout << Fibonacci::get_remainder(n, m) << std::endl;

    LOG1(Fibonacci::get_remainder0(n, m));
    LOG1(Fibonacci::get_remainder1(n, m));
    LOG1(Fibonacci::get_remainder2(n, m));
    LOG1(Fibonacci::get_remainder_(n, m));
    LOG1(Fibonacci::get_remainder(n, m));
    return 0;
}