#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float rd_x(float s, float t){
    srand(time(NULL));
    float x = (t - s) * rand() / RAND_MAX + s;
    return x;
}

int rd_p(float l, float r, float x){
    if(r - l < 1.0){
        return 0;
    }
    float l_x = rd_x(l, x - 1.0);
    float r_x = rd_x(x+1, r - 1.0);
    printf("%f\n%f\n", l_x, r_x);
    return rd_p(l, x, l_x) + 1 + rd_p(x+1, r, r_x);
}
int main(){
    float l = 0;
    float r = 5.0;
    float x = rd_x(l, r - 1.0);
    printf("parking %d\n", rd_p(l, r, x));
}
