	
#include <stdio.h>

#include <stdlib.h>



int main()
{
    int x;

    scanf("%d", &x);
    printf("%d", cont(x));
    return 0;
}



int cont (int x)
{
    int dig = 1;

    if (x >= 10)
    {
        dig = dig + cont(x/10);
    }
    return dig;
}

