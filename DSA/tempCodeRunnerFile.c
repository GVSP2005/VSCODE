#include <stdio.h>
int  main(){
    int n;
    scanf("%d",&n);
    int num[n];
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    printf("%d",sum);
}