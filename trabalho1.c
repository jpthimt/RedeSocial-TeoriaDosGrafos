//Alunos: Fulvio Stefanine Silva Junior; Joao Pedro Thim Tarossi;
//Teoria dos Grafos - Trabalho 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

void inicializaGrafo(int matrizP[MAX][MAX]){
	int i, j;
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++){
			matrizP[i][j]==0;
		}
	}
}

void insereUsuario(int cont, char nome[], char matrizN[MAX][MAX]){
	int i, aux=0, comp=1;
	for(i=0; i<=cont; i++){
		comp = strcmp(nome, matrizN[i]);
		if (comp == 0){
			aux++;
		}
	}
	if(aux>0){
		printf("\n Usuario %s ja cadastrado.", nome);
	}else{
		aux = strlen(nome);
		cont++;
		strcpy(matrizN[cont], nome);
		matrizN[cont][aux] = '\0';
		printf("\n Usuario \"%s\" cadastrado com sucesso na posicao %d", nome, cont);
	}
	getchar();
}

void insereRelacaoSeguidor( int cont, int matrizP[MAX][MAX], char matrizN[MAX][MAX]){
	int aux1=0, aux2=0, pos1, pos2, i, tempo;
	char nome1[20], nome2[20];
	printf("\n Nome do usuario seguidor: ");
	scanf("%s", nome1);
	printf(" Nome do usuario seguido: ");
	scanf("%s", nome2);
	printf(" Tempo da relacao em meses: ");
	scanf("%i", &tempo);

	for(i=1; i<=cont; i++){
		if(strcmp(nome1, matrizN[i])==0){
			aux1=1;
			pos1=i;
		}
		if(strcmp(nome2, matrizN[i])==0){
			aux2=1;
			pos2=i;
		}
	}
	if(strcmp(nome1, nome2)==0){
		printf("\n Nome de seguidor e seguido iguais, acao invalida.");
	}else if(aux1==1 && aux2==1){
		if(matrizP[pos1][pos2]!=0){
			char resp;
			printf("\n\n Relacao ja existente de %i meses, deseja atualizar (s/n)? ", matrizP[pos1][pos2]);
			scanf("%c", &resp);
			if(resp=='s'||resp=='S'){
				matrizP[pos1][pos2]=tempo;
				printf("\n\n Relacao atualizada para %i meses.", matrizP[pos1][pos2]);
			}else{
				printf("\n\n Relacao nao atualizada.");
			}
		}else{
			matrizP[pos1][pos2]=tempo;
			printf("\n\n Relacao de %i meses inserida.", matrizP[pos1][pos2]);
		}
	}else{
		printf("\n Usuario nao encontrado.");
		char resp;
		printf("\n\n Deseja ver a lista de usuarios (s/n)? ");
		scanf("%s", &resp);
		if(resp=='s' || resp=='S'){
			printf("\n\n Lista de usuarios:\n");
			for(i=1;i<=cont;i++){
				printf("\n %i - %s", i, matrizN[i]);
			}
			getchar();
			insereRelacaoSeguidor(cont, matrizP, matrizN);
		}else {
			printf("\n\n Voltando para o menu...");
		}
	}
	getchar();
}

void segueQuem(int cont, int matrizP[MAX][MAX], char matrizN[MAX][MAX]){
	int i, aux=0, pos;
	char nome[20];
	printf("\n Nome do seguidor: ");
	scanf("%s", nome);
	for(i=1; i<=cont; i++){
		if(strcmp(nome, matrizN[i])==0){
			aux=1;
			pos=i;
		}
	}
	if(aux==1){
		printf("\n Usuarios seguidos por %s", matrizN[pos]);
		for(i=1;i<=cont;i++){
			if(matrizP[pos][i]!=0){
				printf("\n %s - %i meses.", matrizN[i], matrizP[pos][i]);
			}
		}
	}else{
		printf("\n Usuario nao encontrado.");
		printf("\n\n Lista de usuarios:\n");
		for(i=1;i<=cont;i++){
			printf("\n %i - %s", i, matrizN[i]);
		}
		segueQuem(cont, matrizP, matrizN);
	}
	getchar();
}

void quemSegue(int cont, int matrizP[MAX][MAX], char matrizN[MAX][MAX]){
	int i, aux=0, pos;
	char nome[20];
	printf("\n Nome do seguido: ");
	scanf("%s", nome);
	for(i=1; i<=cont; i++){
		if(strcmp(nome, matrizN[i])==0){
			aux=1;
			pos=i;
		}
	}
	if(aux==1){
		printf("\n Usuarios que seguem %s", matrizN[pos]);
		for(i=1;i<=cont;i++){
			if(matrizP[i][pos]!=0){
				printf("\n %s - %i meses.", matrizN[i], matrizP[i][pos]);
			}
		}
	}else{
		printf("\n Usuario nao encontrado.");
		printf("\n\n Lista de usuarios:\n");
		for(i=1;i<=cont;i++){
			printf("\n %i - %s", i, matrizN[i]);
		}
		quemSegue(cont, matrizP, matrizN);
	}
	getchar();
}

void atualizaRelacao(int cont, int matrizP[MAX][MAX], char matrizN[MAX][MAX]){
	int i, aux1, aux2, pos1, pos2, tempo;
	char nome1[20], nome2[20], resp;
	printf("\n Usuario seguidor: ");
	scanf("%s", nome1);
	printf(" Usuario seguido: ");
	scanf("%s", nome2);
	for(i=1; i<=cont; i++){
		if(strcmp(nome1, matrizN[i])==0){
			aux1=1;
			pos1=i;
		}
		if(strcmp(nome2, matrizN[i])==0){
			aux2=1;
			pos2=i;
		}
	}
	if(aux1==1 && aux2==1){
		if(matrizP[pos1][pos2]!=0){
			printf("\n Relacao atual de %i meses.", matrizP[pos1][pos2]);
			printf("\n Digite o novo tempo em meses: ");
			scanf("%i", &tempo);
			matrizP[pos1][pos2] = tempo;
			printf("\n Relacao atualizada para %i meses.", matrizP[pos1][pos2]);
		}else{
			printf("\n Relacao nao existe, deseja inserir (s/n)? ");
			scanf("%c", &resp);
			if(resp=='s'||resp=='S'){
				printf("\n Digite o novo tempo em meses: ");
				scanf("%i", &tempo);
				matrizP[pos1][pos2] = tempo;
				printf("\n Relacao de %i meses inserida.", matrizP[pos1][pos2]);
			}else{
				printf("\n Relacao nao inserida.");
			}
		}
	}else{
		if(aux1==0){
			printf("\n Usuario %s nao cadastrado.", nome1);
			printf("\n Deseja cadastrar (s/n)? ");
			scanf("%c", &resp);
			if(resp=='s'||resp=='S'){
				insereUsuario(cont, nome1, matrizN);
			}else{
				printf("\nC adastro nao realizado.");
			}
		}
		if(aux2==0){
			printf("\n Usuario %s nao cadastrado.", nome2);
			printf("\n Deseja cadastrar (s/n)? ");
			scanf("%c", &resp);
			if(resp=='s'||resp=='S'){
				insereUsuario(cont, nome2, matrizN);
			}else{
				printf("\n Cadastro nao realizado.");
			}
		}
		insereRelacaoSeguidor(cont, matrizP, matrizN);
	}
	getchar();
}

void removeRelacao(int cont, int matrizP[MAX][MAX], char matrizN[MAX][MAX]){
	int i, aux1, aux2, pos1, pos2;
	char nome1[20], nome2[20];
	printf("\n Usuario seguidor: ");
	scanf("%s", nome1);
	printf(" Usuario seguido: ");
	scanf("%s", nome2);
	for(i=1; i<=cont; i++){
		if(strcmp(nome1, matrizN[i])==0){
			aux1=1;
			pos1=i;
		}
		if(strcmp(nome2, matrizN[i])==0){
			aux2=1;
			pos2=i;
		}
	}
	if(aux1==1 && aux2==1){
		matrizP[pos1][pos2]=0;
		printf("\n Relacao removida.");
	}else{
		printf("\n Usuario nao encontrado.");
	}
	getchar();
}

void calculaSeguidoresTotal(int cont, int matrizP[MAX][MAX], char matrizN[MAX][MAX]){
	int i, j, soma=0, total=0;
	for(i=1;i<=cont;i++){
		soma=0;
		for(j=1;j<=cont;j++){
			if(matrizP[j][i]!=0){
				soma++;
				total++;
			}
		}
		printf("\n %s - %i seguidores.", matrizN[i], soma);
	}
	printf("\n Total de seguidores: %i", total);
	getchar();
}

int matrizP[MAX][MAX], cont=0, opcao=-1;
char matrizN[MAX][MAX], nome[20];

int main(){
	inicializaGrafo(matrizP);
	while(opcao!=0){
		system("clear || cls");
		printf("\n	---------------------\n");
		printf("	     REDE SOCIAL	");
		printf("\n	---------------------");
		printf("\n\n Menu de opcoes...\n");
		printf("\n 1 - Inserir novo usuario.");
		printf("\n 2 - Inserir nova relacao.");
		printf("\n 3 - Atualizar relacao.");
		printf("\n 4 - Remover relacao.");
		printf("\n 5 - Mostrar seguidores de um usuario.");
		printf("\n 6 - Mostrar usuarios seguidos por um usuario.");
		printf("\n 7 - Mostrar seguidores totais da rede social.");
		printf("\n 0 - Fechar programa.");
		printf("\n\n-> Digite a opcao desejada: ");
		scanf("%i", &opcao);

		switch(opcao){
			case 1:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Inserir novo usuario <-\n\n");
				printf(" Digite o nome de usuario: ");
				scanf("%s", nome);
				insereUsuario(cont, nome, matrizN);
				if(matrizN[cont+1][0]!='\0'){
					cont++;
				}
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 2:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Inserir nova relacao <-\n\n");
				insereRelacaoSeguidor(cont, matrizP, matrizN);
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 3:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Atualizar relacao <-\n\n");
				atualizaRelacao(cont, matrizP, matrizN);
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 4:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Remover relacao <-\n\n");
				removeRelacao(cont, matrizP, matrizN);
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 5:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Mostrar seguidores de um usuario <-\n\n");
				quemSegue(cont, matrizP, matrizN);
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 6:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Mostrar usuarios seguidos por um usuario <-\n\n");
				segueQuem(cont, matrizP, matrizN);
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 7:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Mostrar seguidores totais da rede social <-\n\n");
				calculaSeguidoresTotal(cont, matrizP, matrizN);
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
			break;
			case 0:
				system("clear || cls");
				fflush(stdin);
				printf("	-> Fechar programa <-\n\n");
				printf("\n O programa sera fechado :( \n");
				printf("\n Precisone alguma tecla para continuar...\n");
				getchar();
			break;
			default:
				system("clear || cls");
				printf("Opcao invalida!\n");
				printf("\n\n Precisone alguma tecla para continuar...");
				getchar();
				system("clear || cls");
			break;
		}
	}
}