#include <stdio.h>
int n,x;
int f(int i,int a[]){
if(i==n)return a[n];
return a[i]+x*(f(i+1,a));
}
int main(){

    printf("enter the value of n and x\n");

    scanf("%d%d",&n,&x);
    int a[n+1];
    printf("%d coeffcients of the polynomial\n",n+1);
    for(int i=0;i<=n;i++)scanf("%d",&a[i]);
    int sum=0,prod=1;
    for(int i=0;i<=n;i++){
        sum+=a[i]*prod;
        prod*=x;
    }
    printf("By normal substitution:%d\n",sum);
    sum=0,prod=1;
    sum+=f(0,a);
    printf("By recursive process : %d \n",sum);
}