#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

#include "flush.c"

#define MAX_CHAR 80

typedef struct{
	int code;
	float price;
	char productName[MAX_CHAR];
}Produtos;

typedef struct{
	int code;
	char employeeName[MAX_CHAR];
}Funcionarios;

int salvamento(int option){
	int choice, i=0, codeAux;
	char txt[30][30], textCode[50], text3[50], funcionario[30][50], codigo[30][50];
	
	if(option==1){
		Funcionarios funcionariosStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("Funcionarios.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Funcionarios.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codigos=0, funcionarios=2, codigoAux=0, funcionarioAux=0;
			char funcionario[30][50], codigo[30][50];
			int coluna = 0, canCopy=0;
			
			while(!feof(file)){
				if(fgets(txt[coluna],500,file)){
				int linha=0;
					do{
						if(txt[coluna][linha]=='#'){
							txt[coluna][linha]='\0';
							break;
						}
						linha++;
					}while(txt[coluna][linha]!='\n');

					if(codigos || funcionarios){
						codigos++;
						funcionarios++;
					}
					if(codigos%5==0){
						strcpy(codigo[codigoAux], txt[coluna]);
						codigoAux++;
					}
					if(funcionarios%5==0){
						strcpy(funcionario[funcionarioAux], txt[coluna]);
						funcionarioAux++;	
					}
					coluna++;
				}
			}
			int aux=coluna;
			int doisFatoresNome=0;
			int doisFatoresCodigo=0;
	    	
			while(canCopy==0){
				canCopy=1;
				
				fflush(stdin);
				if(doisFatoresNome==0){
					printf("Digite o nome do Funcionario a ser cadastrado: ");
					gets(funcionariosStruct[0].employeeName);
					strupr(funcionariosStruct[0].employeeName);
				}
				if(doisFatoresCodigo==0){
					printf("Digite o codigo do funcionario a ser cadastrado: ");
					scanf("%d", &funcionariosStruct[0].code);
					sprintf(textCode,"%d",funcionariosStruct[0].code);
				}
				
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(funcionario[coluna],funcionariosStruct[0].employeeName)==0 && doisFatoresNome==0){
						printf("\nNome de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresNome=1;
					}
				}
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(codigo[coluna],textCode)==0 && doisFatoresCodigo==0){
						printf("Codigo de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresCodigo=1;
					}
				}	
			}
			codeAux=funcionariosStruct[0].code;
			fprintf(file,"\nFuncionario: \n%s#\n", funcionariosStruct[0].employeeName);
			fprintf(file, "Codigo: \n%d#\n", funcionariosStruct[0].code);
			flush();
			fclose(file);
			printf("\nFuncionario: %s\nCodigo: %d\n", funcionariosStruct[0].employeeName, funcionariosStruct[0].code);
			printf("\nDeseja cadastrar mais algum funcionario?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de funcionarios:)\n\n");
	    system("pause");
	}
	if(option==2){
		Funcionarios funcionariosStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("Funcionarios.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Funcionarios.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codigos=0, funcionarios=2, codigoAux=0, funcionarioAux=0;
			char funcionario[30][50], codigo[30][50];
			int coluna = 0, canCopy=0;
			
			while(!feof(file)){
				if(fgets(txt[coluna],500,file)){
				int linha=0;
					do{
						if(txt[coluna][linha]=='#'){
							txt[coluna][linha]='\0';
							break;
						}
						linha++;
					}while(txt[coluna][linha]!='\n');

					if(codigos || funcionarios){
						codigos++;
						funcionarios++;
					}
					if(codigos%5==0){
						strcpy(codigo[codigoAux], txt[coluna]);
						codigoAux++;
					}
					if(funcionarios%5==0){
						strcpy(funcionario[funcionarioAux], txt[coluna]);
						funcionarioAux++;	
					}
					coluna++;
				}
			}
			int aux=coluna;
			int doisFatoresNome=0;
			int doisFatoresCodigo=0;
	    	
			while(canCopy==0){
				canCopy=1;
				
				fflush(stdin);
				if(doisFatoresNome==0){
					printf("Digite o nome do Funcionario a ser cadastrado: ");
					gets(funcionariosStruct[0].employeeName);
					strupr(funcionariosStruct[0].employeeName);
				}
				if(doisFatoresCodigo==0){
					printf("Digite o codigo do funcionario a ser cadastrado: ");
					scanf("%d", &funcionariosStruct[0].code);
					sprintf(textCode,"%d",funcionariosStruct[0].code);
				}
				
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(funcionario[coluna],funcionariosStruct[0].employeeName)==0 && doisFatoresNome==0){
						printf("\nNome de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresNome=1;
					}
				}
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(codigo[coluna],textCode)==0 && doisFatoresCodigo==0){
						printf("Codigo de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresCodigo=1;
					}
				}	
			}
			codeAux=funcionariosStruct[0].code;
			fprintf(file,"\nFuncionario: \n%s#\n", funcionariosStruct[0].employeeName);
			fprintf(file, "Codigo: \n%d#\n", funcionariosStruct[0].code);
			flush();
			fclose(file);
			printf("\nFuncionario: %s\nCodigo: %d\n", funcionariosStruct[0].employeeName, funcionariosStruct[0].code);
			printf("\nDeseja cadastrar mais algum funcionario?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de funcionarios:)\n\n");
	    system("pause");
	}
}
int main(){
	int option=2;
	salvamento(option);
}