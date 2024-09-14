/*The following is the algorithm that c use to make multiplications 

basically it have been done as follows;
12345*3467;
it will do recursively;
(123*34)*(10^((5/2)*2))+((123+45)*(34+67)-123*34-45*67)*10^(5/2)+45*67;
here we are reducing the size of the largest number ;
time complexity is o(n^1.59);
(12300+34)*(3400+67);
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int get_size(int x){
    int j=0;
    while(x>0){
        j++;
        x/=10;
    }
    return j;
}
long long int karatsuba(long long x,long long y){
    if(x==0||y==0)return 0;
    else if(x<10&&y<10)return x*y;
    //printf("%lld %lld\n",x,y);
    int size=fmax(get_size(x),get_size(y));
    int m=size/2;
    long long int div=pow(10,m);
    long long int l1=x/div,h1=x%div,l2=y/div,h2=y%div;
    long long int z1=karatsuba(l1,l2),z2=karatsuba(l1+h1,l2+h2),z3=karatsuba(h1,h2);
    return z1*(div*div)+(z2-z1-z3)*div+z3;
}

int main(){
// long long int x,y;
// scanf("%lld%lld",&x,&y);
// printf("%lld",karatsuba(x,y));
int count=0;
for(int i=0;i<100;i++){
long long int x=(rand())%100000,y=(rand())%100000;
printf("%lld %lld \n",x,y);
if(karatsuba(x,y)!=x*y)count++;
}
printf("number of test cases failed:%d\n",count);
}