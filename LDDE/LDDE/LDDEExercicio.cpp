#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

struct TpPont {
	char nome[100], cpf[14], cidade[100];
	int idade, ano;
	float salario;
	TpPont* ant, * prox;
};

//protótipos:
char Menu(void);
void ExibirDados();
void ExibirArquivo();
TpPont* CriaCaixa(TpPont dados);
TpPont* InserirOrdenadoArquivoTexto(TpPont* CB);
TpPont* InserirPilhaArquivoTexto(TpPont* CB);
TpPont* InserirFilaArquivoTexto(TpPont* CB);
TpPont* ExcluirDadosTXT(TpPont* CB);
TpPont* OrdenarAposExcluirOrdemFila(TpPont* CB);
TpPont* OrdenarAposExcluirOrdemPilha(TpPont* CB);
TpPont* ExibirLDDERecursivo(TpPont* CB);
TpPont* ExeibirLDDEIterativo(TpPont* CB);
TpPont* AlterarDados(TpPont* CB);
TpPont* Consultar(TpPont* CB);
TpPont* Relatorio(TpPont* CB);

void ExibirArquivo() {

	char nomeArq[100];
	TpPont dados;
	printf("\nNome do arquivo: ");
	fflush(stdin);
	gets_s(nomeArq);

	FILE* PtrArq = fopen(nomeArq, "r");

	while (fscanf(PtrArq, "%[^;];%[^;];%[^;];%d;%d;%f ", dados.nome, dados.cpf, dados.cidade, &dados.idade, &dados.ano, &dados.salario) == 6) {

		printf("\nNome: %s", dados.nome);
		printf("\nCPF: %s", dados.cpf);
		printf("\nCidade: %s", dados.cidade);
		printf("\nIdade: %d", dados.idade);
		printf("\nAno: %d", dados.ano);
		printf("\nSalario: %.2f", dados.salario);
		printf("\n\n-----------------------\n");
	}
	_getch();
}

TpPont* CriaCaixa(TpPont dados) {
	TpPont* Caixa;
	Caixa = new TpPont;
	strcpy(Caixa->nome, dados.nome);
	strcpy(Caixa->cpf, dados.cpf);
	strcpy(Caixa->cidade, dados.cidade);
	Caixa->idade = dados.idade;
	Caixa->ano = dados.ano;
	Caixa->salario = dados.salario;
	Caixa->prox = NULL;
	Caixa->ant = NULL;
	return Caixa;
}

TpPont* InserirOrdenadoArquivoTexto(TpPont* CB) {

	TpPont* atual, * nc,dados;
	FILE* PtrArq = fopen("ExercicioA.txt", "w");
	printf("\nForneca o nome: ");
	fflush(stdin);
	gets_s(dados.nome);

	while (strcmp(dados.nome, "") != 0) {

		printf("\nCPF [ SEM FORMATACAO]:  ");
		fflush(stdin);
		gets_s(dados.cpf);

		printf("\nCidade: ");
		fflush(stdin);
		gets_s(dados.cidade);

		printf("\nIdade: ");
		scanf("%d", &dados.idade);

		printf("\nAno: ");
		scanf("%d", &dados.ano);

		printf("\nSalario: ");
		scanf("%f", &dados.salario);

		nc = CriaCaixa(dados);


		if (CB == NULL)
			CB = nc;
		else {

			if (strcmp(dados.nome, CB->nome) < 0) {
				nc->prox = CB;
				CB->ant = nc;
				CB = nc;
			}
			else {

				atual = CB;

				while (atual->prox != NULL && strcmp(dados.nome, atual->nome) > 0)
					atual = atual->prox;

				if (strcmp(dados.nome, atual->nome) > 0) {
					nc->ant = atual;
					atual->prox = nc;
				}
				else {

					nc->ant = atual->ant;
					nc->prox = atual;
					atual->ant->prox = nc;
					atual->ant = nc;

				}

			}

		}
		system("cls");
		printf("\nForneca outro nome: ");
		fflush(stdin);
		gets_s(dados.nome);

	}

	atual = CB;

	while (atual != NULL) {

		fprintf(PtrArq, "%s \t\t %s \t\t %s \t\t %d \t %d \t %.2f", atual->nome, atual->cpf, atual->cidade, atual->idade, atual->ano, atual->salario);
		fprintf(PtrArq, "\n");
		atual = atual->prox;	
	}

	fclose(PtrArq);
	return CB;
}

TpPont* InserirFilaArquivoTexto(TpPont* CB) {

	TpPont* atual, * nc,dados;

	FILE* PtrArq = fopen("ExercicioB.txt", "w");
	printf("\nForneca o nome: ");
	fflush(stdin);
	gets_s(dados.nome);

	while (strcmp(dados.nome, "") != 0) {

		printf("\nCPF [SEM FORMATACAO]:  ");
		fflush(stdin);
		gets_s(dados.cpf);

		printf("\nCidade: ");
		fflush(stdin);
		gets_s(dados.cidade);

		printf("\nIdade: ");
		scanf("%d", &dados.idade);

		printf("\nAno: ");
		scanf("%d", &dados.ano);

		printf("\nSalario: ");
		scanf("%f", &dados.salario);

		nc = CriaCaixa(dados);

		if (CB == NULL)
			CB = nc;
		else {

			atual = CB;
			while (atual->prox != NULL)
				atual = atual->prox;


			if (atual->prox == NULL) {

				nc->ant = atual;
				atual->prox = nc;
			}

			
		}

	}

	atual = CB;
	while (atual != NULL) {

		fprintf(PtrArq, "%s \t\t %s \t\t %s \t\t %d \t %d \t %.2f", atual->nome, atual->cpf, atual->cidade, atual->idade, atual->ano, atual->salario);
		fprintf(PtrArq, "\n");
		atual = atual->prox;
	}

	fclose(PtrArq);
	return CB;
}

TpPont* InserirPilhaArquivoTexto(TpPont* CB) {

	TpPont* atual, * nc, dados;

	FILE* PtrArq = fopen("ExercicioB.txt", "w");
	printf("\nForneca o nome: ");
	fflush(stdin);
	gets_s(dados.nome);

	while (strcmp(dados.nome, "") != 0) {
		printf("\nCPF [SEM FORMATACAO]:  ");
		fflush(stdin);
		gets_s(dados.cpf);

		printf("\nCidade: ");
		fflush(stdin);
		gets_s(dados.cidade);

		printf("\nIdade: ");
		scanf("%d", &dados.idade);

		printf("\nAno: ");
		scanf("%d", &dados.ano);

		printf("\nSalario: ");
		scanf("%f", &dados.salario);

		nc = CriaCaixa(dados);

		if (CB == NULL)
			CB = nc;
		else{
			
			nc->prox = CB;
			CB->ant = nc;
			CB = nc;
		}

	}

	atual = CB;
	while (atual != NULL) {

		fprintf(PtrArq, "%s \t\t %s \t\t %s \t\t %d \t %d \t %.2f", atual->nome, atual->cpf, atual->cidade, atual->idade, atual->ano, atual->salario);
		fprintf(PtrArq, "\n");
		atual = atual->prox;
	}

	fclose(PtrArq);

	return CB;

}

TpPont* OrdenarAposExcluirOrdemAlfabetica(TpPont* CB) {

	TpPont* atual, * auxCB=NULL, dados, *atual2,*nc;
	atual = CB;
	while (atual != NULL) {

		nc = new TpPont;

		if (auxCB == NULL) {
			strcpy(nc->nome, atual->nome);
			strcpy(nc->cpf, atual->cpf);
			strcpy(nc->cidade, atual->cidade);
			nc->idade = atual->idade;
			nc->ano = atual->ano;
			nc->salario = atual->salario;
			nc->prox = NULL;
			nc->ant = NULL;
			auxCB = nc;
		}
			
		else {

			if (strcmp(atual->nome, auxCB->nome) < 0) {
				strcpy(nc->nome, atual->nome);
				strcpy(nc->cpf, atual->cpf);
				strcpy(nc->cidade, atual->cidade);
				nc->idade = atual->idade;
				nc->ano = atual->ano;
				nc->salario = atual->salario;
				nc->prox = auxCB;
				auxCB->ant = nc;
				nc->ant = NULL;

			}
			else {

				atual2 = auxCB;

				while (atual2->prox != NULL && (strcmp(atual->nome, atual2->nome) > 0))
					atual2 = atual2->prox;

				if (strcmp(atual->nome, atual2->nome) > 0) {
					strcpy(nc->nome, atual->nome);
					strcpy(nc->cpf, atual->cpf);
					strcpy(nc->cidade, atual->cidade);
					nc->idade = atual->idade;
					nc->ano = atual->ano;
					nc->salario = atual->salario;
					nc->ant = atual2;
					nc->prox = NULL;
					atual2->prox = nc;
				}
				else {
					strcpy(nc->nome, atual->nome);
					strcpy(nc->cpf, atual->cpf);
					strcpy(nc->cidade, atual->cidade);
					nc->idade = atual->idade;
					nc->ano = atual->ano;
					nc->salario = atual->salario;

					nc->ant = atual2->ant;
					nc->prox = atual2;
					atual2->ant->prox = nc;
					atual2->ant = nc;
				}
			}
		}

		atual = atual->prox;
	}

	return auxCB;
}

TpPont* OrdenarAposExcluirOrdemFila(TpPont* CB) {

	TpPont* atual, * auxCB = NULL,*nc, *atual2;

	atual = CB;

	while (atual != NULL) {

		nc = new TpPont;

		if (auxCB == NULL) {
			strcpy(nc->nome, atual->nome);
			strcpy(nc->cpf, atual->cpf);
			strcpy(nc->cidade, atual->cidade);
			nc->idade = atual->idade;
			nc->ano = atual->ano;
			nc->salario = atual->salario;
			nc->prox = NULL;
			nc->ant = NULL;
			auxCB = nc;
		}
		else {

			atual2 = auxCB;

			while (atual2->prox != NULL)
				atual2 = atual2->prox;

			if (atual2->prox == NULL) {
				strcpy(nc->nome, atual->nome);
				strcpy(nc->cpf, atual->cpf);
				strcpy(nc->cidade, atual->cidade);
				nc->idade = atual->idade;
				nc->ano = atual->ano;
				nc->salario = atual->salario;
				nc->ant = atual2;
				nc->prox = NULL;
				atual2->prox = nc;
			}


		}
		atual = atual->prox;
	}

	return auxCB;
}

TpPont* OrdenarAposExcluirOrdemPilha(TpPont* CB) {

	TpPont* atual, * auxCB = NULL, * atual2, * nc;

	atual = CB;

	while (atual != NULL) {
		nc = new TpPont;
		if (auxCB == NULL) {
			strcpy(nc->nome, atual->nome);
			strcpy(nc->cpf, atual->cpf);
			strcpy(nc->cidade, atual->cidade);
			nc->idade = atual->idade;
			nc->ano = atual->ano;
			nc->salario = atual->salario;
			nc->prox = NULL;
			nc->ant = NULL;
			auxCB = nc;
		}
		else {
			strcpy(nc->nome, atual->nome);
			strcpy(nc->cpf, atual->cpf);
			strcpy(nc->cidade, atual->cidade);
			nc->idade = atual->idade;
			nc->ano = atual->ano;
			nc->salario = atual->salario;
			nc->ant = NULL;
			nc->prox = auxCB;
			auxCB->ant = nc;
			auxCB = nc;

		}

		atual = atual->prox;


	}

	return auxCB;
}

TpPont* ExcluirDadosTXT(TpPont* CB) {

	TpPont* atual, *nc,dados;
	char nomeArq[100],opc;
	printf("\nQual arquivo texto voce deseja utilizar para excluir algum dado ? ");
	fflush(stdin);
	gets_s(nomeArq);

	FILE* PtrArq = fopen(nomeArq, "r");

	if (PtrArq == NULL) {
		printf("\nArquivo NULL, nenhum dado para listar e excluir.");
		_getch();
		return NULL;
	}
		
	else {
		while (fscanf(PtrArq, "%[^;];%[^;];%[^;];%d;%d;%f ", dados.nome, dados.cpf, dados.cidade,&dados.idade, &dados.ano, &dados.salario) == 6) {
			nc = CriaCaixa(dados);
			if (CB == NULL) {
				CB = nc; 
			}
			else {
				
				atual = CB;

				while (atual->prox != NULL)
					atual = atual->prox;

				if (atual->prox == NULL) {
					nc->ant = atual;
					atual->prox = nc;
				}
			}
		}

	}

	printf("\nQual nome deseja procurar para excluir ?: ");
	fflush(stdin);
	gets_s(dados.nome);

	if (strcmp(dados.nome, CB->nome) == 0) {
		atual = CB;
		CB = CB->prox;
		delete(atual);
		CB->ant = NULL;
	}
	else {

		atual = CB;

		while (atual != NULL && strcmp(atual->nome, dados.nome) != 0)
			atual = atual->prox;

		if (atual == NULL)
			printf("\nNao Achou.");
		else if (strcmp(atual->nome, dados.nome) == 0 && atual->prox != NULL) {

			atual->ant->prox = atual->prox;
			atual->prox->ant = atual->ant;
			delete(atual);
		}
		else {
			atual = atual->ant;
			delete(atual->prox);
			atual->prox = NULL;
		}

	}


	printf("\nDeseja ordenar de qual forma([F] Fila, [P] Pilha, [C] Ordem alfabetica, [Q] Inserir do jeito que esta e ordenar depois): ");
	fflush(stdin);
	opc = toupper(_getche());

	if (opc == 'C')
		CB = OrdenarAposExcluirOrdemAlfabetica(CB);
	else if (opc == 'F')
		CB = OrdenarAposExcluirOrdemFila(CB);
	else if (opc == 'P')
		CB = OrdenarAposExcluirOrdemPilha(CB);

	PtrArq = fopen(nomeArq, "w");
	atual = CB;

	while (atual != NULL) {
		fprintf(PtrArq, "%s;%s;%s;%d;%d;%.2f", atual->nome, atual->cpf, atual->cidade, atual->idade, atual->ano, atual->salario);
		fprintf(PtrArq, "\n");
		atual = atual->prox;
	}
	fclose(PtrArq);


	return CB;
	

}

TpPont* ExibirLDDERecursivo(TpPont* CB) {

	if (CB == NULL)
		return NULL;
	else {

		printf("\nNome: %s", CB->nome);
		printf("\nCPF: %s", CB->cpf);
		printf("\nCidade: %s", CB->cidade);
		printf("\nIdade: %d", CB->idade);
		printf("\nAno: %d", CB->ano);
		printf("\nSalario: %.2f", CB->salario);
		printf("\n\n-----------------------\n");
		ExibirLDDERecursivo(CB->prox);
	}
}

TpPont* ExeibirLDDEIterativo(TpPont* CB) {

	TpPont* atual;

	if (CB == NULL)
		return NULL;
	else {
		atual = CB;

		while (atual != NULL) {
			printf("\nNome: %s", atual->nome);
			printf("\nCPF: %s", atual->cpf);
			printf("\nCidade: %s", atual->cidade);
			printf("\nIdade: %d", atual->idade);
			printf("\nAno: %d", atual->ano);
			printf("\nSalario: %.2f", atual->salario);
			printf("\n\n-----------------------\n");
			atual = atual->prox;
		}


	}

	return CB;

}

void ExibirDados() {
	
	TpPont dados, *CB=NULL, *nc, *atual;
	char nomeArq[100],opc;
	printf("\nQual arquivo deseja ler para exibir os dados ? ");
	fflush(stdin);
	gets_s(nomeArq);

	FILE* PtrArq = fopen(nomeArq, "r");

	while (fscanf(PtrArq, "%[^;];%[^;];%[^;];%d;%d;%f ", dados.nome, dados.cpf, dados.cidade, &dados.idade, &dados.ano, &dados.salario) == 6) {
		nc = new TpPont;
		if (CB == NULL) {
			strcpy(nc->nome, dados.nome);
			strcpy(nc->cpf, dados.cpf);
			strcpy(nc->cidade, dados.cidade);
			nc->idade = dados.idade;
			nc->ano = dados.ano;
			nc->salario = dados.salario;
			nc->prox = NULL;
			nc->ant = NULL;
			CB = nc;
		}
		else {

			atual = CB;

			while (atual->prox != NULL)
				atual = atual->prox;

			if (atual->prox == NULL) {
				strcpy(nc->nome, dados.nome);
				strcpy(nc->cpf, dados.cpf);
				strcpy(nc->cidade, dados.cidade);
				nc->idade = dados.idade;
				nc->ano = dados.ano;
				nc->salario = dados.salario;

				nc->prox = NULL;
				nc->ant = atual;
				atual->prox = nc;

			}


		}
	}

	printf("\nDeseja exibir no formato Iterativo [I] ou Recursivo [R] ? ");
	opc = toupper(_getche());
	system("cls");
	if(opc=='R')
		ExibirLDDERecursivo(CB);
	else
		ExeibirLDDEIterativo(CB);
	
	_getch();
	fclose(PtrArq);

}

TpPont* AlterarDados(TpPont* CB) {

	TpPont* atual, * nc, dados;
	char nomeArq[100], opc;

	printf("\nForneca o nome do arquivo na qual deseja trabalhar: ");
	fflush(stdin);
	gets_s(nomeArq);

	FILE* PtrArq = fopen(nomeArq, "r");

	if (PtrArq == NULL) {
		printf("\nArquivo NULL");
		return NULL;
	}
	else {
		while (fscanf(PtrArq, "%[^;];%[^;];%[^;];%d;%d;%f ", dados.nome, dados.cpf, dados.cidade, &dados.idade, &dados.ano, &dados.salario) == 6) {
			nc = new TpPont;

			if (CB == NULL) {
				strcpy(nc->nome, dados.nome);
				strcpy(nc->cpf, dados.cpf);
				strcpy(nc->cidade, dados.cidade);
				nc->idade = dados.idade;
				nc->ano = dados.ano;
				nc->salario = dados.salario;
				nc->prox = NULL;
				nc->ant = NULL;
				CB = nc;
			}
			else {

				atual = CB;

				while (atual->prox != NULL)
					atual = atual->prox;

				if (atual->prox == NULL) {
					strcpy(nc->nome, dados.nome);
					strcpy(nc->cpf, dados.cpf);
					strcpy(nc->cidade, dados.cidade);
					nc->idade = dados.idade;
					nc->ano = dados.ano;
					nc->salario = dados.salario;
					nc->prox = NULL;
					nc->ant = atual;
					atual->prox = nc;
				}

			}
		}

		printf("\nQual o nome que deseja alterar ? ");
		fflush(stdin);
		gets_s(dados.nome);
		
		atual = CB;

		while (atual != NULL && _stricmp(dados.nome, atual->nome) != 0)
			atual = atual->prox;

		if (atual == NULL)
			printf("\nNao achou");
		else {

			printf("\nForneca o novo nome: ");
			fflush(stdin);
			gets_s(dados.nome);

			printf("\nForneca o novo CPF [SEM FORMATACAO]:  ");
			fflush(stdin);
			gets_s(dados.cpf);

			printf("\nForneca a nova cidade: ");
			fflush(stdin);
			gets_s(dados.cidade);

			printf("\nForneca a nova idade: ");
			scanf("%d", &dados.idade);

			printf("\nForneca o novo ano: ");
			scanf("%d", &dados.ano);

			printf("\nForneca o novo salario: ");
			scanf("%f", &dados.salario);

			strcpy(atual->nome, dados.nome);
			strcpy(atual->cpf, dados.cpf);
			strcpy(atual->cidade, dados.cidade);
			atual->idade = dados.idade;
			atual->ano = dados.ano;
			atual->salario = dados.salario;
		}

	}

	printf("\nDeseja ordenar de qual forma([F] Fila, [P] Pilha, [C] Ordem alfabetica, [Q] Inserir do jeito que esta e ordenar depois): ");
	fflush(stdin);
	opc = toupper(_getche());

	if (opc == 'C')
		CB = OrdenarAposExcluirOrdemAlfabetica(CB);
	else if (opc == 'F')
		CB = OrdenarAposExcluirOrdemFila(CB);
	else if (opc == 'P')
		CB = OrdenarAposExcluirOrdemPilha(CB);

	PtrArq = fopen(nomeArq, "w");
	atual = CB;

	while (atual != NULL) {
		fprintf(PtrArq, "%s;%s;%s;%d;%d;%.2f", atual->nome, atual->cpf, atual->cidade, atual->idade, atual->ano, atual->salario);
		fprintf(PtrArq, "\n");
		atual = atual->prox;
	}
	fclose(PtrArq);

	return CB;
}

TpPont* Consultar(TpPont* CB) {

	TpPont* atual, * nc, dados;
	char nomeArq[100];

	printf("\nDigite o nome do arquivo: ");
	fflush(stdin);
	gets_s(nomeArq);

	FILE* PtrArq = fopen(nomeArq, "r");

	while (fscanf(PtrArq, "%[^;];%[^;];%[^;];%d;%d;%f ", dados.nome, dados.cpf, dados.cidade, &dados.idade, &dados.ano, &dados.salario) == 6) {
		nc = new TpPont;

		if (CB == NULL) {
			strcpy(nc->nome, dados.nome);
			strcpy(nc->cpf, dados.cpf);
			strcpy(nc->cidade, dados.cidade);
			nc->idade = dados.idade;
			nc->ano = dados.ano;
			nc->salario = dados.salario;
			nc->prox = NULL;
			nc->ant = NULL;
			CB = nc;
		}
		else {

			atual = CB;

			while (atual->prox != NULL)
				atual = atual->prox;

			if (atual->prox == NULL) {
				strcpy(nc->nome, dados.nome);
				strcpy(nc->cpf, dados.cpf);
				strcpy(nc->cidade, dados.cidade);
				nc->idade = dados.idade;
				nc->ano = dados.ano;
				nc->salario = dados.salario;
				nc->prox = NULL;
				nc->ant = atual;
				atual->prox = nc;
			}

		}

	}

	printf("\nForneca o nome na qual deseja consultar os dados: ");
	fflush(stdin);
	gets_s(dados.nome);

	atual = CB;


	while (atual != NULL && _stricmp(atual->nome, dados.nome) != 0)
		atual = atual->prox;

	if (atual == NULL) {
		printf("\nNao achou");
		_getch();
	}
		
	else {
		system("cls");
		printf("\n-----------------------\n");
		printf("\nNome: %s", atual->nome);
		printf("\nCPF: %s", atual->cpf);
		printf("\nCidade: %s", atual->cidade);
		printf("\nIdade: %d", atual->idade);
		printf("\nAno: %d", atual->ano);
		printf("\nSalario: %.2f", atual->salario);
		printf("\n\n-----------------------\n");
		_getch();

	}

	fclose(PtrArq);
	return CB;



}

TpPont* Relatorio(TpPont* CB) {

	TpPont* atual, * nc, dados;
	char nomeArq[100], opc,opc2;

	printf("\nNome do arquivo: ");
	fflush(stdin);
	gets_s(nomeArq);

	FILE* PtrArq=fopen(nomeArq, "r");

	while (fscanf(PtrArq, "%[^;];%[^;];%[^;];%d;%d;%f ", dados.nome, dados.cpf, dados.cidade, &dados.idade, &dados.ano, &dados.salario) == 6) {
		nc = new TpPont;
		if (CB == NULL) {
			strcpy(nc->nome, dados.nome);
			strcpy(nc->cpf, dados.cpf);
			strcpy(nc->cidade, dados.cidade);
			nc->idade = dados.idade;
			nc->ano = dados.ano;
			nc->salario = dados.salario;
			nc->prox = NULL;
			nc->ant = NULL;
			CB = nc;
		}
		else {

			atual = CB;

			while (atual->prox != NULL)
				atual = atual->prox;

			if (atual->prox == NULL) {
				strcpy(nc->nome, dados.nome);
				strcpy(nc->cpf, dados.cpf);
				strcpy(nc->cidade, dados.cidade);
				nc->idade = dados.idade;
				nc->ano = dados.ano;
				nc->salario = dados.salario;
				nc->prox = NULL;
				nc->ant = atual;
				atual->prox = nc;
			}

		}
	}

	printf("\nLista de relatorios criada!");
	printf("\nQual tipo de relatorio deseja: Completo e de todos os dados [C] ou de um unico dado [U]");
	opc = toupper(_getche());

	if (opc == 'C') {

		atual = CB;
		system("cls");
		while (atual != NULL) {
			
			printf("\nNome: %s", atual->nome);
			printf("\nCPF: %s", atual->cpf);
			printf("\nCidade: %s", atual->cidade);
			printf("\nIdade: %d", atual->idade);
			printf("\nAno: %d", atual->ano);
			printf("\nSalario: %.2f", atual->salario);
			printf("\n\n-----------------------\n");
			atual = atual->prox;
		}
		_getch();

	}
	else {
		
		printf("\nNome para buscar e gerar relatorio: ");
		fflush(stdin);
		gets_s(dados.nome);
		while (strcmp(dados.nome, "") != 0) {
			atual = CB;
			while (atual != NULL && strcmp(dados.nome, atual->nome) != 0)
				atual = atual->prox;

			if (strcmp(dados.nome, atual->nome) == 0) {
				system("cls");
				printf("\n-----------------------\n");
				printf("\nNome: %s", atual->nome);
				printf("\nCPF: %s", atual->cpf);
				printf("\nCidade: %s", atual->cidade);
				printf("\nIdade: %d", atual->idade);
				printf("\nAno: %d", atual->ano);
				printf("\nSalario: %.2f", atual->salario);
				printf("\n\n-----------------------\n");
				_getch();
			}
			else
				printf("\nNao achou.");

			printf("\nNome para buscar e gerar relatorio ou pressione [ENTER] para terminar a aplicacao:  ");
			fflush(stdin);
			gets_s(dados.nome);
		}
	}
	
	fclose(PtrArq);
	return CB;

}

char Menu(void) {
	system("cls");
	printf(" **** MENU DE OPC ****\n");
	printf("[A] Inserir de forma ordenada do maior para o menor no TXT.\n");
	printf("[B] Inserir no formato de FILA no TXT.\n");
	printf("[C] Inserir no formato de PILHA no TXT.\n");
	printf("[D] Excluir dados do TXT.\n");
	printf("[E] Exibir de forma iterativa e recursiva.\n");
	printf("[F] Alterar um determinado dado.\n");
	printf("[G] Exibir um determinado arquivo do tipo TXT.\n");
	printf("[H] Consultar determinado dado em um arquivo TXT.\n");
	printf("[I] Relatorio completo e parcial de um arquivo texto.\n");
	printf("[J]\n");
	printf("[K]\n");
	printf("[L]\n");
	printf("[M]\n");
	printf("[N]\n");
	printf("[O]\n");
	printf("[P]\n");
	printf("[Q]\n");
	printf("[R]\n");
	printf("[S]\n");
	printf("[T]\n");
	printf("[U]\n");
	printf("[V]\n");
	printf("[W]\n");
	printf("[X]\n");
	printf("[Y]\n");
	printf("[Z]\n");


	printf("[ESC] Sair do Programa\n\n");

	printf("Opcao: ");

	char opcao = toupper(_getch());
	system("cls");
	return opcao;
}



int main() {

	TpPont* Lista = NULL, dados;
	char opcao;
	do
	{
		opcao = Menu();
		system("cls");
		switch (opcao)
		{
		case 'A':Lista = InserirOrdenadoArquivoTexto(Lista);
			break;
		case 'B':Lista = InserirFilaArquivoTexto(Lista);
			break;
		case 'C':Lista = InserirPilhaArquivoTexto(Lista);
			break;
		case 'D':Lista = ExcluirDadosTXT(Lista);
			break;
		case 'E':ExibirDados();
			break;
		case 'F': Lista = AlterarDados(Lista);
			break;
		case 'G':ExibirArquivo();
			break;
		case 'H': Lista = Consultar(Lista);
			break;
		case 'I': Lista = Relatorio(Lista);
			break;
		case 'J':
			break;
		case 'K':
			break;
		case 'L':
			break;
		case 'M':
			break;
		case 'N':
			break;
		case 'O':
			break;
		case 'P':
			break;
		case 'Q':
			break;
		case 'R':
			break;
		case 'S':
			break;
		case 'T':
			break;
		case 'U':
			break;
		case 'V':
			break;
		case 'W':
			break;
		case 'X':
			break;
		case 'Y':
			break;
		case 'Z':
			break;
		default:
			break;
		}

	} while (opcao != 27);

	return 0;
}