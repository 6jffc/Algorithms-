#include<stdio.h>
int main(){
int x = 10;
printf("Value of x is %d\n",x);
printf("Address of x in Hex is %p\n", &x);
printf("Address of x in decimal is %lu\n", &x);
printf("Value at address of x is %d\n",*(&x));
return 0;
}