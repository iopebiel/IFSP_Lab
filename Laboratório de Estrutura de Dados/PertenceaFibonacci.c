#include <stdio.h>
#include <stdlib.h>

int main () {

    int a, b, auxiliar, i, n;

    a = 0;
    b = 1;

    printf("Digite um número: ");
    scanf("%d", &n);
    
    printf("Sequência Fibbonaci:\n");     
    while (auxiliar < n) 
    {
        auxiliar = a + b;
        a = b;
        b = auxiliar;
        
        printf("%d\n", auxiliar);
    }
    
    if (auxiliar == n)
        printf("O número pertence a sequência de Fibonacci!");
    else
        printf("O número não pertence a sequência de Fibonacci!");
    
}