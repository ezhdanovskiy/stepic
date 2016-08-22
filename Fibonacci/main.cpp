#include <cassert>
#include <iostream>

class Fibonacci final {
public:
    static int get_last_digit(int n) {
        assert(n >= 1);
        // put your code here
        int f1 = 0;
        int f2 = 1;
        for (int i = 2; i <= n; ++i) {
            int f = (f2 + f1) % 10;
            f1 = f2;
            f2 = f;
        }
        n = f2;
        return n;
    }
};

int main(void) {
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get_last_digit(n) << std::endl;
    return 0;
}
