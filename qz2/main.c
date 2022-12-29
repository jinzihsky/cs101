#include <stdio.h>

void print_spaces(int r, int rows) {
    printf("%*c", r*2, ' ');
    return;
}

void print_stars(int r) {
    for (int j = 0; j < r; j++) {
        if (j == r-1)
            printf("*");
        else
            printf("* ");
    }
    printf("\n");
    return;
}

int main() {
    int rows = 5;    // height
    for (int i = 0; i < rows; i++) {
        if (i)
            print_spaces(i, rows);
        print_stars((rows - i) * 2 -1);
    }
    return 0;
}
