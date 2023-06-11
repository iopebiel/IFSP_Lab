#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE meuProcesso;
    HANDLE minhaThread;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD ProcessId =  0;
    DWORD ThreadId =  0;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    BOOL novoProcesso = NULL;

    novoProcesso = CreateProcessA(
            ("C:\\Windows\\system32\\calc.exe"),
             NULL,
             NULL,
             NULL,
             FALSE,
             0,
             NULL,
             NULL,
             &si,
             &pi);

     if (novoProcesso) {
        cout << "Processo Iniciado." << endl << "Processo ID:\t" << pi.dwProcessId << endl;
        cout << "Endereçamento: " <<pi.hProcess << endl;
     }
     else
     {
         cout << "Nao consegui Iniciar o Processo!" << endl;
         if(GetLastError() == 2)
            cout << "Aplicativo nao encontrado";
     }
    return 0;
}
