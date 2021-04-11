#include <stdio.h>
#include "division.h"
int main ()
{
    int a = 1000;
    int b = 20;
    int c;

    divide(a,b,&c);

    printf("%d",c);

      return 0;
}
