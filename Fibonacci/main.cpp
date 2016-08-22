#include <cassert>
#include <iostream>

class Fibonacci final {
public:
    static int get(int n) {
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
        return n;
    }
};

int main(void) {
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}
