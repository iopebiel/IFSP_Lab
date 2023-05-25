#include <stdio.h>
#include <sys/time.h>

int main () {
    double total = 0;
    double adicionar = 1;

    // inicia  mediação do tempo
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    int iterations = 1000*1000*1000;
    for (int i=0; i<iterations; i++) {
        total += adicionar;
        adicionar /= 2.0;
    }

    // Para a mediação do tempo e calcula o tempo passado
    gettimeofday(&end, 0);
    long segundos = end.tv_sec - begin.tv_sec;
    long microsegundos = end.tv_usec - begin.tv_usec;
    double tPassado = segundos + microsegundos*1e-6;

    printf("Resultado: %.20f\n", total);

    printf("Tempo medido: %.3f segundos.\n", tPassado);

    return 0;
}




