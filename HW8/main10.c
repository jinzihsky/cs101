#include <stdio.h>

int get_digit(int n) {
    return n % 10;
}

int main() {
    int n = 1234;
    int sum = 0;

    while (n > 0) {
        sum = sum * 10 + get_digit(n);
        n /= 10;
    }

    printf("sum = %d\n", sum);
    return 0;
}
