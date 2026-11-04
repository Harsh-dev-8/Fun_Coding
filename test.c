#include <stdio.h>

int main(){
    int x = 16;
    int *p = &x;
    printf("THe value of x is %p\n", &x);
    printf("THe value of p is %p\n", &*p);
}