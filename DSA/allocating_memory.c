#include <stdio.h>
#define alloc_size 10000
char alloc_buff[alloc_size];
char *palloc=alloc_buff;
char *alloc(int n){
    if(alloc_buff+alloc_size-palloc>=n){
        palloc+=n;
        return palloc-n;

    }
    else return NULL;
}
int main(){
    int n;
    scanf("%d",&n);
    if(alloc(n)==NULL)printf("memory allocation failed\n");
    else printf("memory allocated successfully\n");

}