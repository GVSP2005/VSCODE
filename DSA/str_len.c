#include <stdio.h>
#include <stdlib.h>
int len(char *s){
    int l=0;
    while(s[l++]!='\0');
    //while(s[l]!="\0")l++;don't use " double quotes" it gives warning and behavior is undefined

    return l-1;
    /*for(;*s!='\0';s++)l++;return l;*/
}
int main(){
    char *str;
    str=(char*)(malloc(sizeof(char)*100));
    scanf("%s",str);
    printf("%d\n",len(str));
}