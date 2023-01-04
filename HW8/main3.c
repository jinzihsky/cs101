#include <stdio.h>

int main(void)
{
    int i = 15;
    int count = 0;
    for (int j = 31; j >= 0; j--)
    {
        printf("%d", (i >> j) & 1);
        count++;
        if (count % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

