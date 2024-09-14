#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Key{
    char *word;
    int num;
} key;
typedef struct Word{
    char *s;

}word;

int return_ind(char *str,key keytab[]){
    int f=0,l=31,mid;
    while(f<l){mid=(f+l)/2;
        if(strcmp(str,keytab[mid].word)==0){
            f=mid,l=mid;
        }
        else if(strcmp(str,keytab[mid].word)<0)l=mid;
        else f=mid+1;

    }
    if(strcmp(str,keytab[f].word)==0)return f;
    else return -1;
}
int main(){
    FILE *fp;
    fp=fopen("C:/Users/saipr/OneDrive/Documents/keywords_in_c.txt","r");
    if(fp==NULL)printf("unable to open the file\n");
    key keytab[33];
    char c=fgetc(fp);
    int i=0,j=0;
    keytab[0].word=(char*)(malloc(sizeof(char)*20));
    keytab[0].num=0;
    while(c!=EOF){
        if(c==' '){c=fgetc(fp);
            continue;
        }
        if(c!=',')
        keytab[i].word[j++]=c;
        else 
        {   keytab[i].num=0;
            keytab[i].word[j]='\0';
            i++,j=0;
            keytab[i].word=(char*)(malloc(sizeof(char)*20));
        }
        c=fgetc(fp);
    }
    //for(i=0;i<32;i++)printf("%s\n",keytab[i].word);
    i=return_ind("enum",keytab);
    printf("%d ",i);
    fclose(fp);
//finished upto bin search
//have to take words from a prog and check and increment

}