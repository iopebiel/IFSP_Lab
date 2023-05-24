#include <iostream>
#include <string>

using namespace std;

void criar() {
    cout << "Opcao CRIAR selecionada." << endl;
}

void inserir() {
    cout << "Opcao INSERIR selecionada." << endl;
}

void listar() {
    cout << "Opcao LISTAR selecionada." << endl;
}

void apagar() {
    cout << "Opcao APAGAR selecionada." << endl;
}

void renomear() {
    cout << "Opcao RENOMEAR selecionada." << endl;
}

void mover() {
    cout << "Opcao MOVER selecionada." << endl;
}

void deletar() {
    cout << "Opcao DELETAR selecionada." << endl;
}

void ajuda() {
    cout << "Opcao AJUDA selecionada." << endl;
}

void ver() {
    cout << "Opcao VER selecionada." << endl;
}

void data() {
    cout << "Opcao DATA selecionada." << endl;
}

void hora() {
    cout << "Opcao HORA selecionada." << endl;
}

void limpar() {
    cout << "Opcao LIMPAR selecionada." << endl;
}

int main() {
    string choice;

    while (true) {
        cout << "Selecione uma opcao:" << endl;
        cout << "CRIAR" << endl;
        cout << "INSERIR" << endl;
        cout << "LISTAR" << endl;
        cout << "APAGAR" << endl;
        cout << "RENOMEAR" << endl;
        cout << "MOVER" << endl;
        cout << "DELETAR" << endl;
        cout << "AJUDA" << endl;
        cout << "VER" << endl;
        cout << "DATA" << endl;
        cout << "HORA" << endl;
        cout << "LIMPAR" << endl;
        cout << "SAIR" << endl;

        cout << "Digite o nome da opcao: ";
        getline(cin, choice);

        if (choice == "CRIAR") {
            criar();
        } else if (choice == "INSERIR") {
            inserir();
        } else if (choice == "LISTAR") {
            listar();
        } else if (choice == "APAGAR") {
            apagar();
        } else if (choice == "RENOMEAR") {
            renomear();
        } else if (choice == "MOVER") {
            mover();
        } else if (choice == "DELETAR") {
            deletar();
        } else if (choice == "AJUDA") {
            ajuda();
        } else if (choice == "VER") {
            ver();
        } else if (choice == "DATA") {
            data();
        } else if (choice == "HORA") {
            hora();
        } else if (choice == "LIMPAR") {
            limpar();
        } else if (choice == "SAIR") {
            cout << "Saindo do programa..." << endl;
            break;
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }

        cout << endl;
    }

    return 0;
}
