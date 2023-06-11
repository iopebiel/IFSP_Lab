#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI ImprimirNumerosPares(LPVOID lpParam) {
    Sleep(100);
    for (int i = 2; i <= 10; i += 2) {
        cout << "par: " << i << endl;
        Sleep(500);
    }
    return 0;
}


DWORD WINAPI ImprimirNumerosImpares(LPVOID lpParam) {
    for (int i = 1; i <= 10; i += 2) {
        cout << "impar: " << i << endl;
        Sleep(500);
    }
    return 0;
}

int main() {
    HANDLE threadNumerosPares, threadNumerosImpares;

    threadNumerosPares = CreateThread(NULL, 0, ImprimirNumerosPares, NULL, 0, NULL);
    if (threadNumerosPares == NULL) {
        cerr << "Erro ao criar a thread dos números pares." << endl;
        return 1;
    }
    threadNumerosImpares = CreateThread(NULL, 0, ImprimirNumerosImpares, NULL, 0, NULL);
    if (threadNumerosImpares == NULL) {
        cerr << "Erro ao criar a thread dos números ímpares." << endl;
        return 1;
    }

    WaitForSingleObject(threadNumerosPares, INFINITE);
    WaitForSingleObject(threadNumerosImpares, INFINITE);

    CloseHandle(threadNumerosPares);
    CloseHandle(threadNumerosImpares);

    return 0;
}