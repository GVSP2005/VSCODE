#include <stdio.h>
#include <stdlib.h>
int *a;
void swap(int *x,int *y){
    int temp;
    temp=*x,*x=*y,*y=temp;

}
void upos(int n){
    if(n==1)return;
    if(a[n-2]>a[n-1]){
        swap(&a[n-2],&a[n-1]);
        upos(n-1);
    }

}
int main(){
    int n=10;
    a=(int*)(malloc(sizeof(int)*(n+1)));
    for(int i=0;i<n;i++){
        a[i]=rand()%n+1;printf("%d ",a[i]);
    }printf("\n");
    for(int i=0;i<n;i++){
        upos(i+1);
    }
    for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
}
