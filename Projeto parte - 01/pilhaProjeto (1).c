#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define tamanho 50000

typedef struct pilha {
	int vetor[tamanho];
	int topo;
} Pilha;

Pilha f;

void inserir(int p);
int remover();
void imprimir();
int verificarCheia();
int verificarVazia();
void inicializar();

void inserir(int p) {
	
	if(!verificarCheia()) {
		f.topo++;
		f.vetor[f.topo] = p;
	} else {
		printf("Nao eh possivel inserir elemento na pilha pois ela estah cheia");
	}
}

int remover() {

	if(!verificarVazia()) {
		int aux;
		aux = f.vetor[f.topo];
		f.topo--;
		return aux;
	} else {
		printf("A pilha estah vazia.");
		return 0;
	}
}

void imprimir() {
	int i;

	if(!verificarVazia()) {
		for(i = f.topo; i >= 0; i--) {
			printf("%d ", f.vetor[i]);
		}
	} else {
		printf("A pilha estah vazia.");
	}
}

int verificarCheia() {
	if(f.topo == tamanho - 1)
		return 1;
	else return 0;
}

int verificarVazia() {
	if(f.topo == -1)
		return 1;
	else return 0;
}

void inicializar() {
	f.topo = -1;
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
		printf("\n1. Inserir %d elementos na pilha", quantidade);
		printf("\n2. Remover %d elementos na pilha", quantidade);
		printf("\n3. Imprimir a pilha");
		printf("\n4. Inicializar a pilha");
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
