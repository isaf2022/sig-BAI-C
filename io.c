#include <stdio.h>
#include "types.h"

void mostrar_menu (void) {
	printf("|========================================|\n");
	printf("| [1] - Cadastrar clientes               |\n");
	printf("| [2] - Listar clientes                  |\n");
	printf("| [3] - Abertura de conta                |\n");
	printf("| [4] - Depositar dinheiro               |\n");
	printf("| [5] - Levantar dinheiro                |\n");
	printf("| [6] - Consultar saldo                  |\n");
	printf("| [7] - Transferir dinheiro              |\n");
	printf("| [8] - Actualizar dados do cliente      |\n");
	printf("| [9] - Terminar                         |\n");
	printf("|========================================|\n");
}

void mensagem_de_sucesso (void) {
	printf("|========================================|\n");
	printf("| OPERACAO REALIZADA COM SUCESSO!        |\n");
	printf("|========================================|\n");
}

void mensagem_de_erro (char erro[]) {
	printf("==========================================\n");
	printf(" ERRO! %d\n", erro);
	printf("==========================================\n");
}

void mostrar_saldo (float saldo) {
	printf("==========================================\n");
	printf(" SALDO ATUAL DA CONTA: %f\n", saldo);
	printf("==========================================\n");
}

void mostrar_dados_cliente (Pessoa cliente) {
	printf("==========================================\n");
	printf("        DADOS PESSOAIS DO CLIENTE         \n");
	printf(" CODIGO: %d\n", cliente.codigo);
	printf(" NOME: %s\n", cliente.nome);
	printf(" IDENTIFICACAO: %s\n", cliente.identificacao);
	printf(" TELEFONE: %d\n\n", cliente.telefone);
}

void mostrar_dados_conta (Conta conta) {
	printf("        DADOS DA CONTA DO CLIENTE         \n");
	printf(" NUMERO DA CONTA: %d\n", conta.numero_conta, "\n");
	printf(" TIPO DE CONTA: %d\n", conta.tipo_conta, "\n");
	printf(" SALDO: %f\n", conta.saldo, "\n");
	printf(" ESTADO DA CONTA: %d\n\n", conta.estado, "\n");
}

void ler_str (char mensagem[], char *ptr) {
	printf(mensagem);
	scanf("%[^\n]", ptr);
	getchar();
}

void ler_int (char mensagem[], int *ptr) {
	printf(mensagem);
	scanf("%d", ptr);
	getchar();
}

void ler_float (char mensagem[], float *ptr) {
	printf(mensagem);
	scanf("%f", ptr);
	getchar();
}