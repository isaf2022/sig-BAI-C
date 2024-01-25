#define MAX 1000
#define MAXLINE 100

struct Pessoa {
	int codigo;
	char nome[MAXLINE];
	char identificacao[MAXLINE];
	int telefone;
};

struct Conta {
	int tipo_conta;
	int numero_conta;
	float saldo;
	int estado;
	int codigo_cliente;
};

typedef struct Pessoa Pessoa;
typedef struct Conta Conta;