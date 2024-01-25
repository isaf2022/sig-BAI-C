#include <stdbool.h>
#include "types.h"

Pessoa clientes[MAX];
Conta contas[MAX];
int total_clientes, total_contas;

void mensagem_de_erro (char []);

bool cadastrar_cliente (Pessoa p) {
	p.codigo = total_clientes + 1;
	clientes[total_clientes++] = p;
	return true;
}

bool abertura_de_conta (Pessoa p, int tipo_de_conta) {
	Conta c = {
		tipo_de_conta,
		total_contas + 1,
		0,
		1,
		p.codigo
	};
	
	contas[total_contas++] = c;
	
	return true;
}

static int pesquisar_conta_numero_conta (int numero_da_conta);

bool depositar_dinheiro (int numero_da_conta, float valor) {
	int posicao = pesquisar_conta_numero_conta (numero_da_conta);
	if (posicao == NAO_ENCONTRADO) {
		mensagem_de_erro("Numero de conta incorrecto");
		return false;
	}
	contas[posicao].saldo = contas[posicao].saldo + valor;
	
	return true;
}

static int pesquisar_conta_numero_conta (int numero_da_conta) {
	for (int i = 0; i < total_contas; i++) {
		if (contas[i].numero_conta == numero_da_conta) {
			return i;
		}
	}
	return NAO_ENCONTRADO;
}

bool levantar_dinheiro (int numero_da_conta, float valor) {
	int posicao = pesquisar_conta_numero_conta(numero_da_conta);
	if (posicao == NAO_ENCONTRADO) {
		mensagem_de_erro("Numero de conta incorrecto");
		return false;
	}
	
	int saldo = contas[posicao].saldo;
	if (saldo < valor) {
		mensagem_de_erro("Saldo insuficiente");
		return false;
	}
	contas[posicao].saldo -= valor;
}

float consultar_saldo (int numero_da_conta) {
	int posicao = pesquisar_conta_numero_conta(numero_da_conta);
	if (posicao == NAO_ENCONTRADO) {
		mensagem_de_erro("Numero de conta incorrecto");
		return NAO_ENCONTRADO;
	}

	return contas[posicao].saldo;
}

bool transferir_dinheiro (int numero_da_conta_enviar, int numero_da_conta_receber, float valor) {
	int posicao_enviar = pesquisar_conta_numero_conta (numero_da_conta_enviar);
	if (posicao_enviar == NAO_ENCONTRADO) {
		mensagem_de_erro("Numero de conta a enviar incorrecto");
		return false;
	}
	
	int posicao_receber = pesquisar_conta_numero_conta (numero_da_conta_receber);
	if (posicao_receber == NAO_ENCONTRADO) {
		mensagem_de_erro("Numero de conta a receber incorrecto");
		return false;
	}

	if (posicao_enviar == posicao_receber) {
		mensagem_de_erro("Nao pode transferir para a mesma conta");
		return false;
	}

	if (contas[posicao_enviar].saldo < valor) {
		mensagem_de_erro("O saldo da conta e insuficiente");
		return false;
	}
	
	contas[posicao_enviar].saldo -= valor;
	contas[posicao_receber].saldo += valor;
	
	return true;
}

int pesquisar_cliente_codigo_cliente (int codigo_cliente);

bool atualizar_dados (Pessoa p, int codigo_cliente) {
	int posicao = pesquisar_cliente_codigo_cliente (codigo_cliente);
	if (posicao == NAO_ENCONTRADO) {
		mensagem_de_erro("Codigo cliente incorrecto");
		return false;
	}
	
	clientes[posicao] = p;
	
	return true;
}

int pesquisar_cliente_codigo_cliente (int codigo_cliente) {
	for (int i = 0; i < total_clientes; i++) {
		if (clientes[i].codigo == codigo_cliente) {
			return i;
		}
	}
	return NAO_ENCONTRADO;
}

int pesquisar_conta_codigo_cliente (int );

void listar_clientes (void) {
	void mostrar_dados_cliente (Pessoa );
	void mostrar_dados_conta (Conta );
	
	for (int i = 0; i < total_clientes; i++) {
		Pessoa p = clientes[i];

		mostrar_dados_cliente(p);

		int posicao = pesquisar_conta_codigo_cliente(p.codigo);
		if (posicao == NAO_ENCONTRADO) {
			continue;
		}

		mostrar_dados_conta(contas[posicao]);
	}
}

int pesquisar_conta_codigo_cliente (int codigo_cliente) {
	for (int i = 0; i < total_contas; i++) {
		if (contas[i].codigo_cliente == codigo_cliente) {
			return i;
		}
	}
	return NAO_ENCONTRADO;
}