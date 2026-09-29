#include <cstdio>
#include <string>

int main() {
    int x = 0;

    printf("Initial x = %d\n", x);

    // A lambda can execute immediately
    auto v = [&x](int v) -> int {
        x += v;
        return v;
    }(15);

    printf("Returned value from lambda, v = %d\n", v);
    printf("After lambda run, x = %d\n", x);

    return 0;
}