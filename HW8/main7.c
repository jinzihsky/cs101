#include <stdio.h>

int get_digit(int num){
    return num%10;
}

int main()
{
    int num = -9990;
    int sum = 0;
    int negative = 0;
    
    if (num < 0){
        negative = 1;
        num = 0 - num;
    }
    do{
        if (num < 10){
            if(negative){
                sum -= get_digit(num);
            }
        }else{
            sum += get_digit(num);
        }
        num /= 10;
    }while(num > 0);
    printf("sum = %d\n", sum);
    return 0;
}
