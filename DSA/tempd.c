#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    float x,y;
}*p1;
//here struct point is the datatype
//for accessing pointer first you have to allocate it 
int main(){
    p1=(struct point*)malloc(sizeof(struct point));
    p1->x=1,p1->y=2;
    printf("%f %f",p1->x,p1->y);
}