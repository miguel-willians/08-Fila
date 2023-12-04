#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void remove();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}



void insere()
{
	NO* novo = (NO*)malloc(sizeof(NO));
    cout << "Digite o número a ser adicionado" << endl;
    cin >> novo->valor;

    if (novo == NULL){
        return;
    }

    if (inicio == NULL){
        inicio = novo;
        fim = novo;
    }

    else {
        inicio->prox = novo;
        novo->prox = NULL;
        fim  = novo;
    }

}

void remove()
{
	if(inicio == NULL){
        cout << "Não há elementos para efetuar a remoção" << endl;
    }

    else {
        NO* aux = inicio;
        cout << "Elemento a ser excluído:" << aux->valor << endl;
        inicio = inicio->prox;
        free(aux);
    }
}
