#include <stdio.h>
void print_top(int n, int center);
void print_truck(int n, int center);
void print_spaces(int n);
void print_stars(int padding, int n);

int main() {
    print_spaces(3);
    printf("X'mas tree!\n");
    print_top(3, 8);
    print_top(5, 8);
    print_top(7, 8);
    print_truck(5, 8);
}



void print_top(int n, int center) {
    for (int i = 0; i < n; i++) {
        print_stars(center - i - 1, i * 2 + 1);
        printf("\n");
    }
    return;
}

void print_truck(int n, int center) {
    for (int i = 0; i < n; i++) {
        print_spaces(center-1);
        printf("*\n");
    }
    return;
}

void print_spaces(int n) {
    printf("%*c", n, ' ');
    return;
}

void print_stars(int padding, int n) {
    int i = 0;
    print_spaces(padding);
    while (i++ < n) {
        printf("*");
    }
    return 0;
}
