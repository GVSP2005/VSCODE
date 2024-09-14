#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long 
ll int mul10(ll int c1,int n){
    char *ianum;
    ianum=(char*)(malloc(65*sizeof(char)));
    itoa(c1,ianum,10);
    //printf("%s the string ianum and length of ianum=%ld\n",ianum,strlen(ianum));
    int j=strlen(ianum);
    while(n--)
    //ianum[strlen(ianum)]='0',printf("%ld length of ianum and value of ianum=%ld\n",strlen(ianum),atoi(ianum));
    ianum[j++]='0';
    c1=atoi(ianum);
    //printf("%lld before free value of %d\n",c1,n);
    free(ianum);
    //printf("%lld after free num\n",c1);
    return c1;
}
ll int karatsuba(char *s1,char *s2){
    ll int n1=atoi(s1),n2=atoi(s2);
    //printf("s1=%s,s2=%s,n1=%lld,n2=%lld\n",s1,s2,n1,n2);
    if(n1==0||n2==0)return 0;
    else if(abs(n1)<10&&abs(n2)<10)return n1*n2;
    int l1=strlen(s1),l2=strlen(s2);
    //char *str1=(char*)(malloc((l1)*sizeof(char)));due to size factor and using atoi on this giving undefined behavior
    char str1[64]="";//so it is better to declare like this pointing to null;
    //char *str2=(char*)(malloc((l2)*sizeof(char))); 
    char str2[64]="";
    strncpy(str1,s1,l1-1);
    strncpy(str2,s2,l2-1);
    //a^b^
    ll int c1=karatsuba(str1,str2);
    //ab
    ll int c2=karatsuba(&s1[l1-1],&s2[l2-1]);
    // printf("c1=%lld,c2=%lld\n",c1,c2);
    char *news1=(char*)(malloc(l1*sizeof(char)));
    char *news2=(char*)(malloc(l2*sizeof(char)));
    itoa(atoi(str1)+atoi(&s1[l1-1]),news1,10);
    itoa(atoi(str2)+atoi(&s2[l2-1]),news2,10);
    //(a^+a)(b^+b)
    ll int c3=karatsuba(news1,news2);
    free(news1),free(news2);
    ll int cval=c3-c2-c1;
    ll int ans=(mul10(c1,2))+mul10(cval,1)+c2;
    return ans;
}
int main(){
    char s1[64],s2[64];ll int v1=0,v2=0;int count=0;
    for(int i=0;i<100;i++){
        v1=1+(rand())%10000,v2=(rand())%10000+1;
        itoa(v1,s1,10),itoa(v2,s2,10);
        //sprintf(s1,"%lld",v1);
        //sprintf(s2,"%lld",v2);
    if(v1*v2!=karatsuba(s1,s2))
    printf("v1=%lld,v2= %lld,v1*v2=%lld \n",v1,v2,karatsuba(s1,s2)),count++;
    }
    printf("No of test cases failed:%d\n",count);

}
// I don't know what the error is
// if i remove if it is printing all and showing 49 wrong and if i put if then it is showing 0 test cases failed;