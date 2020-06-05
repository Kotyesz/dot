#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){
    int size = 26, arrsiz;
    printf("number of dots: ");
    scanf("%d", &arrsiz);
    int  *arr = calloc(arrsiz,sizeof(int)),
         *arr2 = calloc(arrsiz,sizeof(int));
    char ans;
    printf("autofill?(Y/n): ");
    scanf(" %c",&ans);
    if(ans == 'y' | ans == 'Y'){
        srand(time(NULL)); 
        for(int i = 0; i < arrsiz; i++){
            *(arr+i) = rand()%(size-1)+1;
            *(arr2+i) = rand()%(size-1)+1;
        }
    } else 
    for(int i = 0; i < arrsiz; i++){
        printf("X%d = ",i+1);
        scanf("%d", &*(arr+i));   
        printf("Y%d = ",i+1);
        scanf("%d", &*(arr2+i));
    } 
    printf("\n%s\n\n", ans == 'y' | ans == 'Y' ? "AUTO" : "MANUAL"); 
    for(int i = 0; i < arrsiz; i++)
        printf("dot%d = %d,%d\t ",i+1,*(arr+i),*(arr2+i));
    puts(""); 
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == 0 & j == 0)
                printf(" \t");
            else if(i == 0)
                printf("%d\t",j);
            else if(j == 0)
                printf("%d\t",i);
            else{
                _Bool van = 0;
                for(int k = 0; k < arrsiz; k++){
                    if(*(arr+k) == j & *(arr2+k) == i){
                        printf("X\t");
                        van = 1;
                        break;
                    }
                }
                if(!van) printf(" \t"); 
            }
        }
        puts("\n");
    }
    return 0;
}
