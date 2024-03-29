#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int receipt_ip;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

FILE* fpn;
int num[7];
int m = 1;

void get_rand(){
    for(int i = 0 ; i < 6 ; i++){
        num[i] = rand() % 69 + 1;
        for(int j = 0 ; j < i ; j++){
            if(num[i] == num[j]){
                num[i]++;
            }
        }
    }
    qsort(num , 6 , sizeof(int) , cmpfunc);
    for(int i = 0 ; i < 6 ; i++){
        if(num[i] == 68){
            num[i] -= 6 - i;
        }
    }
    for(int i = 0 ; i < 6 ; i++){
        fprintf(fpn,"%02d ",num[i]);
    }
}

int main(){
    int n;
    srand(time(NULL));
    printf("歡迎光臨長庚樂透購買機台\n");
    printf("請問您要購買幾組樂透: ");
    scanf("%d", &n);
    if(n == 0){
        int pr[10];
        int nc;
        printf("請輸入中獎號碼(最多三個):");
        for(int i = 0; i < 3; i++){
            scanf("%d", &pr[i]);
            nc = i + 1;
            char ch = getchar();
            if(ch == '\n'){
                break;
            }
        }
        printf("輸入中獎號碼為:");
        for (int i = 0; i < nc; i++) {
            printf("%02d ", pr[i]);
        }
        printf("\n");
        printf("以下為中獎彩券\n");
        
    }else if(n >= 6){
        printf("只能購買最多五組喔");
    }else if(n < 0){
        printf("不能輸入無意義的數字喔");
    }else{
        char name[20];
        printf("已為您購買的 %d 組樂透組合輸出至 lotto%05d.txt\n", n, m);
        sprintf(name, "lotto%05d.txt", m);
        while((fopen(name,"w+")) != NULL){
            fpn = fopen(name, "w+");
        fprintf(fpn, " ========= lotto649 =========\n");
        fprintf(fpn, " ========+ NO.%05d +========\n", m);
            m++;
        }
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);
        char date[100];
        strftime(date, 100, " = %a %b %01d %H:%M:%S %Y =", tm_info);
        if((int)date[11] == 0){
            for(int i = 0 ; i < 11 ; i++){
                fprintf(fpn,"%c",date[i]);
            }
            for(int i = 12 ; i < 100 ; i++){
                if(date[i]='\0'){
                    break;
                }
                fprintf(fpn,"%c",date[i]);
            }
        }else{
            fprintf(fpn,"%s", date);
        }
        fprintf(fpn,"\n");
        for(int i = 0 ; i < 5 ; i++){
            if(i < n){
                fprintf(fpn," [%d]: ", i + 1);
                get_rand();
                num[7] = rand()%9 + 1;
                if((num[7] == num[0]) && num[0] != 1){
                    num[7]--;
                }else if((num[7] == num[0]) && num[0] == 1){
                    num[7]++;
                }
                fprintf(fpn,"%02d\n",num[7]);
            }else{
                fprintf(fpn," [%d]: -- -- -- -- -- -- --\n", i + 1);
            }
        }
        fprintf(fpn," ========= csie@CGU =========\n");
    }
    return 0;
}
