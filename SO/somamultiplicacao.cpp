#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI ImprimirSoma(LPVOID lpParam) {
    int a = *(int*) lpParam;
    int b = *((int*) lpParam + 1);
    cout <<  "Thread Soma: " << a <<" + "<< b << " = " << a+b << endl;
    return 0;
}

DWORD WINAPI ImprimirMultiplicacao(LPVOID lpParam) {
    Sleep(100);
    int a = *(int*) lpParam;
    int b = *((int*) lpParam + 1);
    cout <<  "Thread Multiplicacao: " << a <<" * "<< b << " = " << a*b << endl;
    return 0;
}

int main() {
    HANDLE threadSoma, threadMultiplicacao;

    int a, b;

    cout << "Digite o primeiro numero"<< endl;;
    cin >> a;
    cout << "Digite o segundo numero"<< endl;
    cin >> b;

    int parametros[2] = {a, b};

    threadSoma = CreateThread(NULL, 0, ImprimirSoma, parametros, 0, NULL);
    if (threadSoma == NULL) {
        cerr << "Erro ao criar a thread da soma." << endl;
        return 1;
    }

    threadMultiplicacao = CreateThread(NULL, 0, ImprimirMultiplicacao, parametros, 0, NULL);
    if (threadMultiplicacao == NULL) {
        cerr << "Erro ao criar a thread da multiplicacao." << endl;
        return 1;
    }

    WaitForSingleObject(threadSoma, INFINITE);
    WaitForSingleObject(threadMultiplicacao, INFINITE);

    CloseHandle(threadSoma);
    CloseHandle(threadMultiplicacao);

    return 0;
}