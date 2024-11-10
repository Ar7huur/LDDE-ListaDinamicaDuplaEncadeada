//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <conio.h>
//#include <ctype.h>
//#include <stdlib.h>
//#include <windows.h>
//
//#pragma region LDDE antiga
//
////struct TpPont {
////
////	char info;
////	TpPont* prox, * ant;
////};
////
////
////TpPont* CriaCaixa(char E) {
////
////	TpPont* Caixa;
////	Caixa = new TpPont;
////	Caixa->info = E;
////	Caixa->prox = NULL;
////	Caixa->ant = NULL;
////	return Caixa;
////}
////
////
////
////
////TpPont* InserirLDDE(TpPont *CB, char E) {
////	TpPont* atual, * nc;
////	nc = CriaCaixa(E);
////	if (CB == NULL)
////		CB = nc;
////	else {
////		if (E < CB->info) {
////			nc->prox = CB;
////			CB->ant = nc;
////			CB = nc;
////		}
////		else {
////			atual = CB;
////			while (atual->prox != NULL && E > atual->info)
////				atual = atual->prox;
////
////			if (E > atual->info && atual->prox == NULL) {
////				nc->ant = atual;
////				atual->prox = nc;
////			}
////			 if(atual->info > E) {
////				nc->ant = atual->ant;
////				nc->prox = atual;
////				atual->ant->prox = nc;
////				atual->ant = nc;
////			 }
////		}
////	}
////	return CB;
////}
////
////
////TpPont* ExcluirElementoLDDE(TpPont* CB) {
////	char E;
////	TpPont* atual;
////
////	printf("Elemento: ");
////	E = toupper(_getche());
////
////	if (CB == NULL)
////		printf("\nLista null, forneca uma lista que esteja preenchida.");
////
////	if (CB->info == E) {
////		atual = CB;
////		CB = CB->prox;
////		CB->ant =NULL;
////		delete(atual);
////
////	}
////	else {
////
////		atual = CB;
////
////		while (atual != NULL && atual->info != E)
////			atual = atual->prox;
////
////		if (atual == NULL)
////			printf("\nNao achou o elemento");
////		else if(atual->prox != NULL && atual->info == E){
////
////			atual->ant->prox = atual->prox;
////			atual->prox->ant = atual->ant;
////		
////			delete(atual);
////		}
////		else if (atual->prox == NULL && atual->info == E) {
////			atual->ant->prox = NULL;
////			delete(atual->prox);
////		}
////
////
////	}
////	return CB;
////}
////
////
////
////
////
////void ExibirLDDE(TpPont* CB) {
////	system("cls");
////	TpPont* aux;
////	aux = CB;
////
////	if (CB == NULL)
////		printf("\nLista esta null");
////	else {
////		
////		while (aux != NULL) {
////			printf("%c ", aux->info);
////			aux = aux->prox;
////		}
////
////		Sleep(5000);
////	}
////
////	system("cls");
////}
//#pragma endregion
//
//struct TpPont {
//
//	char nome[100];
//	int idade,ano;
//	float salario;
//
//	TpPont* ant, * prox;
//};
//
//void GerarArquivo(TpPont* CB);
//
//TpPont * PopularRegistro(TpPont *CB) {
//
//	TpPont* atual, * nc, dados;
//	char opc;
//	printf("\nNome: ");
//	fflush(stdin);
//	gets_s(dados.nome);
//
//	FILE* PtrArq = fopen("arq.txt", "w");
//	FILE* PtrArq2 = fopen("arqBin.dat", "ab+");
//
//	while (strcmp(dados.nome, "") != 0) {
//		nc = new TpPont; //usar o cria caixa a função passando os TpPont dados via parametro para a função e criando já a caixa
//		printf("\nIdade: ");
//		scanf("%d", &dados.idade);
//		printf("\nAno: ");
//		scanf("%d", &dados.ano);
//		printf("\nSalario: ");
//		scanf("%f", &dados.salario);
//
//		if (CB == NULL) {
//			strcpy(nc->nome, dados.nome);
//			nc->idade = dados.idade;
//			nc->ano = dados.ano;
//			nc->salario = dados.salario;
//			nc->prox = NULL;
//			nc->ant = NULL;
//			CB = nc;
//		}
//		else {
//			if (strcmp(dados.nome, CB->nome) < 0) {
//
//				strcpy(nc->nome, dados.nome);
//				nc->idade = dados.idade;
//				nc->ano = dados.ano;
//				nc->salario = dados.salario;
//				nc->prox = CB;
//				CB->ant = nc;
//				nc->ant = NULL;
//				CB = nc;
//			}
//			else {
//				atual = CB;
//
//				while (atual->prox != NULL && strcmp(dados.nome, atual->nome) > 0)
//					atual = atual->prox;
//
//				if (strcmp(dados.nome, atual->nome) > 0) {
//					strcpy(nc->nome, dados.nome);
//					nc->idade = dados.idade;
//					nc->ano = dados.ano;
//					nc->salario = dados.salario;
//					nc->ant = atual;
//					atual->prox = nc;
//					nc->prox = NULL;
//				}
//				else if (strcmp(dados.nome, atual->nome) < 0) {
//					strcpy(nc->nome, dados.nome);
//					nc->idade = dados.idade;
//					nc->ano = dados.ano;
//					nc->salario = dados.salario;
//					nc->ant = atual->ant;
//					nc->prox = atual;
//					atual->ant->prox = nc;
//					atual->ant = nc;
//				}
//			}
//		}
//		system("cls");
//		printf("\nNovo nome: ");
//		fflush(stdin);
//		gets_s(dados.nome);
//
//	}
//	printf("\nPreparando para gravar os dados no arquivo texto e binario.");
//	printf("\nDeseja gravar em qual arquivo ? [B] para binário, [T] para texto ou [A] para ambos.");
//	
//	opc = toupper(_getche());
//
//
//	if (opc == 'A') {
//		system("cls");
//		atual = CB;
//		while (atual != NULL) {
//
//			fwrite(atual, sizeof(TpPont), 1, PtrArq2);
//			fprintf(PtrArq, "%s \t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//			fprintf(PtrArq, "\n");
//			atual = atual->prox;
//		}
//		fclose(PtrArq);
//		fclose(PtrArq2);
//	}
//	else if (opc == 'T') {
//		system("cls");
//		atual = CB;
//		while (atual != NULL) {
//
//			fprintf(PtrArq, "%s \t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//			fprintf(PtrArq, "\n");
//			atual = atual->prox;
//		}
//		fclose(PtrArq);
//		
//	}
//	else if (opc == 'B') {
//		system("cls");
//		atual = CB;
//		while (atual != NULL) {
//
//			fwrite(atual, sizeof(TpPont), 1, PtrArq2);
//			atual = atual->prox;
//		}
//		fclose(PtrArq2);
//	}
//
//
//	return CB;
//}
//
//void ExibirDadosArquivoBinario() {
//
//	char nomeArq[100];
//	printf("\nQual o nome do arquivo ?  ");
//
//	printf("\nForneca o nome (pressione Enter para sair): ");
//	fgets(nomeArq, sizeof(nomeArq), stdin);
//	nomeArq[strcspn(nomeArq, "\n")] = '\0';
//
//	FILE* Ptr = fopen(nomeArq, "rb");
//	if (Ptr == NULL) {
//		printf("Erro ao abrir o arquivo.\n");
//		return;
//	}
//
//	TpPont dados;
//	while (fread(&dados, sizeof(TpPont), 1, Ptr) == 1) {
//		printf("Nome: %s\n", dados.nome);
//		printf("Nome: %d\n", dados.idade);
//		printf("Nome: %d\n", dados.ano);
//		printf("Nome: %.2f\n", dados.salario);
//		printf("\n");
//	}
//
//	fclose(Ptr);
//	_getch();
//}
//
//void ExibirDadosArquivoTexto() {
//
//	char nomeArq[100];
//	printf("\nQual o nome do arquivo ?  ");
//
//	printf("\nForneca o nome (pressione Enter para sair): ");
//	fgets(nomeArq, sizeof(nomeArq), stdin);
//	nomeArq[strcspn(nomeArq, "\n")] = '\0';
//
//	FILE* Ptr = fopen(nomeArq, "rb");
//	if (Ptr == NULL) {
//		printf("Erro ao abrir o arquivo.\n");
//		return;
//	}
//
//	TpPont dados;
//	while (fscanf(Ptr, "%s %d %d %f", dados.nome, &dados.idade, &dados.ano, &dados.salario) == 4) {
//		printf("Nome: %s\n", dados.nome);
//		printf("Idade: %d\n", dados.idade);
//		printf("Ano: %d\n", dados.ano);
//		printf("Salário: %.2f\n", dados.salario);
//		printf("\n");
//	}
//
//	
//	fclose(Ptr);
//	_getch();
//}
//
//
//TpPont* InserirDadosFormatoFila(TpPont* CB) {
//
//	TpPont* atual,dados,*nc;
//	
//	printf("\nPreparando para cadastrar os dados e inserir no estilo FILA:");
//	printf("\nNome: ");
//	fflush(stdin);
//	gets_s(dados.nome);
//
//	while (strcmp(dados.nome, "") != 0) {
//		nc = new TpPont;
//		printf("\nIdade: ");
//		scanf("%d", &dados.idade);
//		printf("\nAno: ");
//		scanf("%d", &dados.ano);
//		printf("\nSalario: ");
//		scanf("%f", &dados.salario);
//
//		if (CB == NULL) {
//			strcpy(nc->nome, dados.nome);
//			nc->idade = dados.idade;
//			nc->ano = dados.ano;
//			nc->salario = dados.salario;
//			nc->prox = NULL;
//			nc->ant = NULL;
//			CB = nc;
//		}
//		else {
//			atual = CB;
//
//			while (atual->prox != NULL)
//				atual = atual->prox;
//
//			if (atual->prox == NULL) {
//				strcpy(nc->nome, dados.nome);
//				nc->idade = dados.idade;
//				nc->ano = dados.ano;
//				nc->salario = dados.salario;
//				nc->prox = NULL;
//				nc->ant = atual;
//				atual->prox = nc;
//				
//			}
//		}
//			
//
//		printf("\nNovo nome: ");
//		fflush(stdin);
//		gets_s(dados.nome);
//	}
//	GerarArquivo(CB);
//	return CB;
//
//}
//
//
//void GerarArquivo(TpPont* CB) {
//	TpPont* atual;
//	char opc, nomeBin[20],nomeTxt[20];
//	printf("\nInserindo dados para um arquivo qualquer.");
//	
//	atual = CB;
//
//	printf("\nDeseja gravar em qual arquivo ? [B] para binário, [T] para texto ou [A] para ambos.");
//	opc = toupper(_getche());
//	if (opc == 'A') {
//		system("cls");
//		printf("\nNome para o arquivo binario: MAXIMO DE 20 CARACTERES.");
//		fflush(stdin);
//		gets_s(nomeBin);
//		printf("\nNome para o arquivo texto: MAXIMO DE 20 CARACTERES.");
//		fflush(stdin);
//		gets_s(nomeTxt);
//
//		FILE* PtrArq = fopen(nomeTxt,"w");
//		FILE* PtrArq2 = fopen(nomeBin,"ab+");
//
//		
//		atual = CB;
//		while (atual != NULL) {
//
//			fwrite(atual, sizeof(TpPont), 1, PtrArq2);
//			fprintf(PtrArq, "%s \t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//			fprintf(PtrArq, "\n");
//			atual = atual->prox;
//		}
//		fclose(PtrArq);
//		fclose(PtrArq2);
//		printf("\nGravado com sucesso em ambos os arquivos.");
//	}
//	else if (opc == 'T') {
//
//		system("cls");
//		printf("\nNome para o arquivo texto: MAXIMO DE 20 CARACTERES.");
//		fflush(stdin);
//		gets_s(nomeTxt);
//
//		FILE* PtrArq = fopen(nomeTxt, "w");
//		atual = CB;
//		while (atual != NULL) {
//
//			fprintf(PtrArq, "%s \t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//			fprintf(PtrArq, "\n");
//			atual = atual->prox;
//		}
//		fclose(PtrArq);
//
//		printf("\nGravado com sucesso somente para o arquivo TEXTO");
//	}
//	else if (opc == 'B') {
//		system("cls");
//		printf("\nNome para o arquivo BINARIO: MAXIMO DE 20 CARACTERES.");
//		fflush(stdin);
//		gets_s(nomeTxt);
//
//		FILE* PtrArq = fopen(nomeTxt, "w");
//		atual = CB;
//		while (atual != NULL) {
//
//			fwrite(atual, sizeof(TpPont), 1, PtrArq);
//			atual = atual->prox;
//		}
//		fclose(PtrArq);
//	}
//
//}
//
//
//TpPont* AlterarDadosTxt(TpPont* CB) {
//
//	TpPont* atual, * nc, dados;
//
//	char nome[100],opc;
//	FILE* PtrArq = fopen("arq.txt", "r");
//	
//	printf("\nForneca o nome para alterar: ");
//	fflush(stdin);
//	gets_s(nome);
//
//	if (PtrArq == NULL)
//		printf("\nNada para alterar.");	
//	else {
//		
//		
//
//		while (fscanf(PtrArq, "%s %d %d %f", dados.nome, &dados.idade, &dados.ano, &dados.salario) == 4) {
//			nc = new TpPont;
//			if (CB == NULL) {
//				strcpy(nc->nome, dados.nome);
//				nc->idade = dados.idade;
//				nc->ano = dados.ano;
//				nc->salario = dados.salario;
//				nc->prox = NULL;
//				nc->ant = NULL;
//				CB = nc;
//			}
//			else {
//				atual = CB;
//
//				while (atual->prox != NULL)
//					atual = atual->prox;
//
//				if (atual->prox == NULL) {
//					strcpy(nc->nome, dados.nome);
//					nc->idade = dados.idade;
//					nc->ano = dados.ano;
//					nc->salario = dados.salario;
//					nc->prox = NULL;
//					nc->ant = atual;
//					atual->prox = nc;
//
//				}
//			}
//
//		}
//
//		if (strcmp(CB->nome, nome) == 0) {
//			atual = CB;
//			printf("\nDigite o novo nome: ");
//			fflush(stdin);
//			gets_s(nome);
//
//			strcpy(atual->nome, nome);
//
//		}
//		else {
//
//			atual = CB;
//			while (atual != NULL && strcmp(atual->nome, nome) != 0)
//				atual = atual->prox;
//
//			if (atual == NULL)
//				printf("\nNao achou.");
//			else {
//
//				printf("\nDigite o novo nome: ");
//				fflush(stdin);
//				gets_s(nome);
//
//				strcpy(atual->nome, nome);
//			}
//		}
//
//
//		printf("\nDeseja inserir os dados da forma que estão ou deseja uma nova ordenacao? [0/1]" );
//		fflush(stdin);
//		opc = toupper(_getche());
//
//		if (opc == '0') {
//			atual = CB;
//			PtrArq = fopen("arq.txt", "w");
//			while (atual != NULL) {
//				fprintf(PtrArq, "%s \t\t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//				fprintf(PtrArq, "\n");
//				atual = atual->prox;
//			}
//		}
//		else {
//			
//		}
//
//
//	}
//	fclose(PtrArq);
//	return CB;
//
//}
//
//
//TpPont* InserirOrdenado(TpPont *CB) {
//
//	FILE* PtrArq = fopen("arq.txt", "r");
//
//	TpPont* nc, * atual, dados;
//	
//	while (fscanf(PtrArq, "%s %d %d %f", &dados.nome, &dados.idade, &dados.ano, &dados.salario) == 4) {
//		nc = new TpPont;
//		if (CB == NULL) {
//
//			strcpy(nc->nome, dados.nome);
//			nc->idade = dados.idade;
//			nc->ano = dados.ano;
//			nc->salario = dados.salario;
//			nc->prox = NULL;
//			nc->ant = NULL;
//			CB = nc;
//		}
//		else {
//
//			if (strcmp(dados.nome, CB->nome) < 0) {
//				strcpy(nc->nome, dados.nome);
//				nc->idade = dados.idade;
//				nc->ano = dados.ano;
//				nc->salario = dados.salario;
//				CB->ant = nc;
//				nc->prox = CB;
//				nc->ant = NULL;
//				CB = nc;
//			}
//			else {
//
//				atual = CB;
//
//				while (atual->prox != NULL && strcmp(atual->nome, dados.nome) < 0)
//					atual = atual->prox;
//
//				if (strcmp(dados.nome, atual->nome) > 0) {
//					strcpy(nc->nome, dados.nome);
//					nc->idade = dados.idade;
//					nc->ano = dados.ano;
//					nc->salario = dados.salario;
//					nc->ant = atual;
//					nc->prox = NULL;
//					atual->prox = nc;
//				}
//				else {
//					strcpy(nc->nome, dados.nome);
//					nc->idade = dados.idade;
//					nc->ano = dados.ano;
//					nc->salario = dados.salario;
//					nc->ant = atual->ant;
//					nc->prox = atual;
//					atual->ant->prox = nc;
//					atual->ant = nc;
//
//				}
//
//			}
//
//		}
//	}
//
//	if (feof(PtrArq)) {
//
//		atual = CB;
//		
//		while (atual != NULL) {
//
//			printf("%s\n", atual->nome);
//			printf("%d\n", atual->idade);
//			printf("%d\n", atual->ano);
//			printf("%.2f\n", atual->salario);
//			printf("\n------------");
//			atual = atual->prox;
//		}
//		
//
//
//		printf("\nPreparando para inserir os novos dados de forma ordenada no arquivo.");
//		PtrArq = fopen("arq.txt", "w");
//		atual = CB;
//
//		while (atual != NULL) {
//
//			fprintf(PtrArq, "%s \t\t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//			fprintf(PtrArq, "\n");
//			atual = atual->prox;
//
//		}
//		fclose(PtrArq);
//	}
//
//	return CB;
//}
//
//
//
//TpPont* ExcluirDadoTxt(TpPont* CB) {
//
//	FILE* PtrArq = fopen("arq.txt", "r");
//	TpPont* atual, dados, *nc;
//
//	char nome[100];
//
//	while (fscanf(PtrArq, "%s %d %d %f", &dados.nome, &dados.idade, &dados.ano, &dados.salario) == 4) {
//		nc = new TpPont;
//		if (CB == NULL) {
//			strcpy(nc->nome, dados.nome);
//			nc->idade = dados.idade;
//			nc->ano = dados.ano;
//			nc->salario = dados.salario;
//			nc->ant = NULL;
//			nc->prox = NULL;
//			CB = nc;
//		}
//		else {
//			atual = CB;
//			while (atual->prox != NULL)
//				atual = atual->prox;
//			strcpy(nc->nome, dados.nome);
//			nc->idade = dados.idade;
//			nc->ano = dados.ano;
//			nc->salario = dados.salario;
//			atual->prox = nc;
//			nc->ant = atual;
//			
//			nc->prox = NULL;
//			
//		}
//	}
//
//	if (feof(PtrArq)) {
//
//		printf("\nQual o nome deseja excluir ?");
//		fflush(stdin);
//		gets_s(nome);
//
//		if (strcmp(CB->nome, nome) == 0) {
//			atual = CB;
//			CB = CB->prox;
//			delete(atual);
//			CB->ant = NULL;
//		}
//		else {
//
//			atual = CB;
//
//			while (atual != NULL && strcmp(atual->nome, nome) != 0)
//				atual = atual->prox;
//
//			if (atual == NULL)
//				printf("\nNao achou.");
//
//			if (strcmp(atual->nome, nome) == 0 && atual->prox != NULL) {
//
//				atual->ant->prox = atual->prox;
//				atual->prox->ant = atual->ant;
//				delete(atual);
//			}
//			else {
//
//				atual = atual->ant;
//				delete(atual->prox);
//				atual->prox = NULL;
//			}
//		}
//
//	}
//	printf("\nExcluído com sucesso.");
//	PtrArq = fopen("arq.txt", "w");
//	atual = CB;
//
//	while (atual != NULL) {
//
//		fprintf(PtrArq, "%s \t\t %d \t %d \t %.2f", atual->nome, atual->idade, atual->ano, atual->salario);
//		fprintf(PtrArq, "\n");
//		atual = atual->prox;
//	}
//
//	if (atual == NULL)
//		fclose(PtrArq);
//
//	CB = atual;
//	CB = InserirOrdenado(CB);
//
//	return CB;
//
//}
//
//
//
//char Menu(void) {
//	printf(" **** MENU DE OPC ****\n");
//	printf(" [A] Inserir ordenado.\n");
//	printf(" [B] Exibir dados do arquivo binario - cadastro feito de forma ordenada\n");
//	printf(" [C] Exibir dados do arquivo texto - cadastro feito de forma ordenada\n");
//	printf(" [D] Inserir no formato de fila\n");
//	printf(" [E] Alterar dados do Txt\n");
//	printf(" [F] Odernar dados a partir de um arquivo texto e retornando um novo.\n"); // fazer uma função nova de ordenar, lendo os dados do arquivo texto e em seguida, ordenando e no fim, re-inserindo.
//	printf(" [G] Excluir dados a partir da leitura de um arquivo texto\n"); //excluir dados partir de um arquivo texto
//	printf(" [H]\n"); //Exibir todos os cadastros a partir de um arquivo texto
//	printf(" [I]\n"); //recebendo um arquivo texto, leia-o e retorne um novo com os dados inseridos de forma de uma fila.
//	printf(" [J]\n"); //faça o mesmo de cima mas no formato de pilha
//	printf(" [K]\n"); //relatorio de arquivo texto;
//	printf(" [L]\n");
//	printf(" [M]\n");
//	printf(" [N]\n");
//	printf(" [O]\n");
//	printf(" [P]\n");
//	printf(" [Q]\n");
//	printf(" [R]\n");
//	printf(" [S]\n");
//	printf(" [T]\n");
//	printf(" [U]\n");
//	printf(" [V]\n");
//	printf(" [W]\n");
//	printf(" [X]\n");
//	printf(" [Y]\n");
//	printf(" [Z]\n");
//
//	printf(" [ESC] Sair do Programa\n\n");
//
//	printf("Opcao: ");
//
//	char opcao = toupper(_getch());
//	system("cls");
//	return opcao;
//}
//
//
//
//int main() {
//
//	TpPont* Lista = NULL, dados;
//	char opcao;
//	do
//	{
//		opcao = Menu();
//		system("cls");
//		switch (opcao)
//		{
//		case 'A': Lista = PopularRegistro(Lista);
//			break;
//		case 'B':ExibirDadosArquivoBinario();
//			break; 
//		case 'C':ExibirDadosArquivoTexto();
//			break;
//		case 'D': Lista = InserirDadosFormatoFila(Lista);
//			break;
//		case 'E': Lista= AlterarDadosTxt(Lista);
//			break;
//		case 'F':Lista = InserirOrdenado(Lista);
//			break;
//		case 'G':Lista = ExcluirDadoTxt(Lista);
//			break;
//		case 'H':
//			break;
//		case 'I':
//			break;
//		case 'J':
//			break;
//		case 'K':
//			break;
//		case 'L':
//			break;
//		case 'M':
//			break;
//		case 'N':
//			break;
//		case 'O':
//			break;
//		case 'P':
//			break;
//		case 'Q':
//			break;
//		case 'R':
//			break;
//		case 'S':
//			break;
//		case 'T':
//			break;
//		case 'U':
//			break;
//		case 'V':
//			break;
//		case 'W':
//			break;
//		case 'X':
//			break;
//		case 'Y':
//			break;
//		case 'Z':
//			break;
//		default:
//			break;
//		}
//
//	} while (opcao != 27);
//
//	return 0;
//}