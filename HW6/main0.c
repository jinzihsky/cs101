#include <stdio.h>

int main(){
    int i = 10;
    
    printf("%d is %s\n", i, !(i & i-1) ? "true" : "false");
    
    return 0;
}
