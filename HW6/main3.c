#include <stdio.h>

int main()
{
    int year = 2022;
    if(year % 4 != 0)
		{
			printf("非閏年\n");
			year ++;
		}else if(year % 100 != 0 || year % 400 == 0){
			printf("閏年\n");
		}
    return 0;
}

