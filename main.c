#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "types.h"

Pessoa clientes[MAX];
Conta contas[MAX];

bool  cadastrar_cliente   (Pessoa p);
bool  abertura_de_conta   (Pessoa p, int tipo_de_conta);
bool  depositar_dinheiro  (int numero_da_conta, float valor);
bool  levantar_dinheiro   (int numero_da_conta, float valor);
float consultar_saldo     (int numero_da_conta);
bool  transferir_dinheiro (int numero_da_conta_enviar, int numero_da_conta_receber, float valor);
bool  atualizar_dados     (Pessoa p, int codigo_cliente);
void  listar_clientes     (void);

int main () {
	int opcao;
	
	printf("Insira uma opcao: ");
	scanf("%d", &opcao);
	
	while (opcao != 9) {
		switch (opcao) {
			case 1:
				printf("Opcao %d selecionada", opcao);
				break;
			case 2:
				printf("Opcao %d selecionada", opcao);
				break;
			case 3:
				printf("Opcao %d selecionada", opcao);
				break;
			case 4:
				printf("Opcao %d selecionada", opcao);
				break;
			case 5:
				printf("Opcao %d selecionada", opcao);
				break;
			case 6:
				printf("Opcao %d selecionada", opcao);
				break;
			case 7:
				printf("Opcao %d selecionada", opcao);
				break;
			case 8:
				printf("Opcao %d selecionada", opcao);
				break;
		}
		
		printf("\nInsira uma Opcao: ");
		scanf("%d", &opcao);
	}
}
