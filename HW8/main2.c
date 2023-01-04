#include <stdio.h>

int count_ones(int x) {
    int count = 0;
    while (x > 0) {
        if (x % 2 == 1) {
            count++;
        }
        x = x / 2;
    }
    return count;
}
int main() {
    int i = 15;
    int ones = count_ones(i);
    printf("%d\n", ones);
    return 0;
}
