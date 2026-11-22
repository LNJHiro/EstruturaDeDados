#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define tamanho 50001

typedef struct lista {
	int vetor[tamanho];
	int qtd;
} Lista;

Lista f;

void inserir(int p);
int remover();
void imprimir();
int verificarCheia();
int verificarVazia();
void inicializar();

void inserir(int p) {
	
	if(!verificarCheia()) {
		f.vetor[f.qtd] = p;
		f.qtd++;
	} else {
		printf("Nao eh possivel inserir elemento na lista pois ela estah cheia");
	}
}

int remover() {
	if(!verificarVazia()) {
		int aux, i;

		aux = f.vetor[0];
		for(i = 0; i < f.qtd - 1; i++) {
			f.vetor[i] = f.vetor[i + 1];
		}
		f.qtd--;
		return aux;
	} else {
		printf("A lista estah vazia.");
		return 0;
	}
}

void imprimir() {
	int i;
	
	if(!verificarVazia()) {
		for(i = 0; i < f.qtd; i++) {
			printf("%d ", f.vetor[i]);
		}
	} else {
		printf("A lista estah vazia.");
	}
}

int verificarCheia() {
	if(f.qtd == tamanho)
		return 1;
	else return 0;
}

int verificarVazia() {
	if(f.qtd == 0)
		return 1;
	else return 0;
}

void inicializar() {
	f.qtd = 0;
}

int numeroAleatorio(int low, int high) {
    int k;
    double d;
    d = (double) rand () / ((double) tamanho + 1);
    k = d * (high - low + 1);
    return low + k;
}

int obterDado() {
	return numeroAleatorio(0, tamanho);
}

void exibirDado(int p) {
	printf("\nElemento: %i", p);
}

int main(int argc, char *argv[]) {
	double start, finish, elapsed;
	int quantidade;
	int opcao, p, i;
	printf("Digite a quantidade de elementos para testar: ");
	scanf("%d", &quantidade);
	inicializar();
	do {
		printf("\n     MENU");
		printf("\n1. Inserir %d elementos na lista", quantidade);
		printf("\n2. Remover %d elementos na lista", quantidade);
		printf("\n3. Imprimir a lista");
		printf("\n4. Inicializar a lista");
		printf("\n5. Sair");
		printf("\nDigite a opcao: ");
		scanf("%d", &opcao);

		switch(opcao) {
			case 1:
				inicializar();
				start = (double) clock();
				for(i = 0; i < quantidade; i++) {
					p = obterDado();
					inserir(p);
					exibirDado(p);
				}
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 2:
				inicializar();
				for(i = 0; i < quantidade; i++) {
					p = obterDado();
					inserir(p);
				}
				start = (double) clock();
				for(i = 0; i < quantidade; i++) {
					p = remover();
					exibirDado(p);
				}
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 3:
				inicializar();
				for(i = 0; i < quantidade; i++) {
					p = obterDado();
					inserir(p);
				}
				start = (double) clock();
				imprimir();
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 4:
				inicializar();
				break;
			case 5:
				printf("\nEncerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero de 1 a 5.");
		}

	} while(opcao != 5);
	return 0;
}
