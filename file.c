#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

extern Pessoa clientes[MAX];
extern Conta contas[MAX];
extern int total_clientes, total_contas;

int pesquisar_conta_codigo_cliente (int );

int criar_ficheiro (void) {
	FILE *file = fopen("./backup/backup_isaf.txt", "a");

	if (file == NULL) {
		return ERR_EXEC;
	}

	fclose(file);
}

void copia_de_seguranca (void) {
	FILE *file = fopen("./backup/backup_isaf.txt", "w");

	for (int i = 0; i < total_clientes; i++) {
		Pessoa p = clientes[i];

		int posicao = pesquisar_conta_codigo_cliente (p.codigo);
		if (posicao == NAO_ENCONTRADO) {
			fprintf(file, "%d\t%s\t%s\t%d\n", p.codigo, p.nome, p.identificacao, p.telefone);
			continue;
		}

		Conta c = contas[posicao];
		fprintf(
			file,
			"%d\t%s\t%s\t%d\t%d\t%d\t%f\t%d\t%d\n", 
			p.codigo, p.nome, p.identificacao, p.telefone, c.tipo_conta, c.numero_conta, c.saldo, c.estado, c.codigo_cliente
		);
	}

	fclose(file);
}

void restaurar_copia_seguranca (void) {
	FILE *file = fopen("./backup/backup_isaf.txt", "r");
	char linha[MAX];

	while (fscanf(file, "%[^\n]\n", linha) == 1) {
		int tamanho = 0;
		char *tokens[9];
		char *token = strtok(linha, "\t");

		while (token != NULL) {
			tokens[tamanho++] = token;
			token = strtok(NULL, "\t");
		}

		Pessoa p;
		p.codigo = atoi(tokens[0]);
		char *nome = tokens[1];
		char *id = tokens[2];
		p.telefone = atoi(tokens[3]);

		int i = 0;
		while (*nome != '\0') {
			p.nome[i++] = *nome++;
		}
		i = 0;
		while (*id != '\0') {
			p.identificacao[i++] = *id++;
		}

		clientes[total_clientes++] = p;

		if (tamanho <= 4) {
			continue;
		}

		Conta c = {
			atoi(tokens[4]),
			atoi(tokens[5]),
			atof(tokens[6]),
			atoi(tokens[7]),
			atoi(tokens[8])
		};

		contas[total_contas++] = c;
	}
}