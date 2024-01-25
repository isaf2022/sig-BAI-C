#include <stdbool.h>
#include "types.h"

extern Pessoa clientes[MAX];

bool  cadastrar_cliente   (Pessoa p);
bool  abertura_de_conta   (Pessoa p, int tipo_de_conta);
bool  depositar_dinheiro  (int numero_da_conta, float valor);
bool  levantar_dinheiro   (int numero_da_conta, float valor);
float consultar_saldo     (int numero_da_conta);
bool  transferir_dinheiro (int numero_da_conta_enviar, int numero_da_conta_receber, float valor);
bool  atualizar_dados     (Pessoa p, int codigo_cliente);
void  listar_clientes     (void);

int pesquisar_cliente_codigo_cliente (int codigo_cliente);

void mostrar_menu  (void);
void mostrar_saldo (float );

void ler_str (char [], char *);
void ler_int (char [], int *);
void ler_float (char [], float *);

int main () {
	enum {
		CADASTRAR_CLIENTE = 1,
		LISTAR_CLIENTES,
		ABERTURA_DE_CONTA,
		DEPOSITAR_DINHEIRO,
		LEVANTAR_DINHEIRO,
		CONSULTAR_SALDO,
		TRANSFERIR_DINHEIRO,
		ATUALIZAR_DADOS,
		TERMINAR
	};
	
	int opcao;

	while (opcao != TERMINAR) {
		mostrar_menu();
		ler_int("Digite uma opcao: ", &opcao);

		bool resultado;
		switch (opcao) {
			case CADASTRAR_CLIENTE:
			{
				Pessoa p;

				ler_str("Digite o seu nome completo: ", p.nome);
				ler_str("Digite o seu documento de identificacao: ", p.identificacao);
				ler_int("Digite o seu numero de telefone: ", &p.telefone);

				resultado = cadastrar_cliente(p);

				break;
			}
			case LISTAR_CLIENTES:
				listar_clientes();
				
				break;
			case ABERTURA_DE_CONTA:
			{
				int codigo, tipo_de_conta;

				ler_int("Digite o seu codigo pessoal: ", &codigo);

				int posicao = pesquisar_cliente_codigo_cliente(codigo);
				if (posicao == NAO_ENCONTRADO) {
					break;
				}

				ler_int("Digite 0 para conta pessoal ou 1 para conta empresarial: ", &tipo_de_conta);
				resultado = abertura_de_conta (clientes[posicao], tipo_de_conta);

				break;
			}
			case DEPOSITAR_DINHEIRO: 
			{
				int numero_conta;
				float valor;

				ler_int("Digite o seu numero da conta: ", &numero_conta);
				ler_float("Digite o valor a depositar: ", &valor);

				resultado = depositar_dinheiro(numero_conta, valor);
				
				break;
			}
			case LEVANTAR_DINHEIRO:
			{
				int numero_conta;
				float valor;

				ler_int("Digite o seu numero da conta: ", &numero_conta);
				ler_float("Digite o valor a levantar: ", &valor);

				resultado = levantar_dinheiro(numero_conta, valor);
				
				break;
			}
			case CONSULTAR_SALDO:
			{
				int numero_conta;

				ler_int("Digite o seu numero da conta: ", &numero_conta);

				float saldo = consultar_saldo(numero_conta);
				if (saldo == NAO_ENCONTRADO) {
					break;
				}

				mostrar_saldo(saldo);

				break;
			}
			case TRANSFERIR_DINHEIRO:
			{
				int numero_conta_enviar, numero_conta_receber;
				float valor;

				ler_int("Digite o seu numero da conta: ", &numero_conta_enviar);
				ler_int("Digite o numero da conta a receber: ", &numero_conta_receber);
				ler_float("Digite o valor a transferir: ", &valor);

				resultado = transferir_dinheiro (numero_conta_enviar, numero_conta_receber, valor);

				break;
			}
			case ATUALIZAR_DADOS:
			{
				Pessoa p;
				int codigo;

				ler_int("Digite o seu codigo pessoal: ", &codigo);
				ler_str("Digite o seu nome completo: ", p.nome);
				ler_str("Digite o seu documento de identificacao: ", p.identificacao);
				ler_int("Digite o seu numero de telefone: ", &p.telefone);

				resultado = atualizar_dados(p, codigo);
				break;
			}
		}
	}
}