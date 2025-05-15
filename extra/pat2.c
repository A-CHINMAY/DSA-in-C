#include <stdio.h>
void main(){
    int i , n , j;
    printf("enter value of n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=2*(n-i);j++){
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++){
            printf("* ");
        }
        printf("\n");

    }
}
