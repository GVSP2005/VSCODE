#include <stdio.h>
#include <stdlib.h>
void mergesort(int *a,int f,int l){
if(l==f){
    return;
}
//printf("%d %d \n",f,l);
int *lt,*rt;
int mid=(f+l)/2;
mergesort(a,f,mid),mergesort(a,mid+1,l);
lt=(int*)(malloc(sizeof(int)*(mid-f+1)));
rt=(int*)(malloc(sizeof(int)*(l-mid)));
for(int i=f;i<=mid;i++)lt[i-f]=a[i];
for(int i=mid+1;i<=l;i++)rt[i-mid-1]=a[i];
int il=0,ir=0,i=0;
for(i=f;i<=l&&il<mid-f+1&&ir<l-mid;i++){
if(lt[il]>rt[ir])a[i]=rt[ir],ir++;
else a[i]=lt[il],il++;
}
while(il<mid-f+1){
    a[i++]=lt[il];
    il++;
}
while(ir<l-mid){
    a[i++]=rt[ir];
    ir++;
}
//for(int i=f;i<=l;i++)printf("%d,",a[i]);printf("\nmergearray\n");
}
int main(){
    int *a;
    int n=10;
    a=(int*)(malloc(sizeof(int)*n));
    for(int i=0;i<n;i++)a[i]=(rand())%100+1,printf("%d ,",a[i]);
    mergesort(a,0,n-1);
    printf("\n");
    for(int i=0;i<n;i++)printf("%d ,",a[i]);
}