#include <stdio.h>
#include <stdlib.h>
int hsize=0;
void swap(int *x,int *y){
    int t;
    t=*x,*x=*y,*y=t;
}
void print(int a[],int n){
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    printf("\n");

}
void max_heapify(int a[],int n,int i){
    if(i*2>n)return;
    else {
        int lar=i;
        if(a[i*2]>a[i])lar=i*2;
        if(i*2+1<=n&&a[i*2+1]>a[lar])lar=i*2+1;
        if(lar==i)return;
        swap(&a[i],&a[lar]);
        max_heapify(a,n,lar);
        
    }
}
void build_heap(int a[],int n){
    for(int i=n/2;i>0;i--){
        max_heapify(a,n,i);
        
    }
}
void hsort(int a[],int n){
    build_heap(a,n);
    for(int i=1;i<=n;i++){
        swap(&a[1],&a[hsize]);
        //i have to swap last node and root node not i and hsize;
        hsize--;
        max_heapify(a,hsize,1);

    }
}
int main(){
    int n=10;
    int a[n+1];a[0]=0;
    printf("array before sorting:\n");
    hsize=n;
    for(int i=1;i<n+1;i++){
        a[i]=rand()%100+1;
        printf("%d ",a[i]);
    }printf("\n");
    hsort(a,n);
    printf("array after sorting \n");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);

    }printf("\n");
}