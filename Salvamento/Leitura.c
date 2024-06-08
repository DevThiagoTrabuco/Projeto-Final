#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flush.c"
#include "fileOpenPrint.c"

int leitura(int choice){
	if(choice==1){//Lista de funcionarios
	FILE * file = fopen("Funcionarios.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
		fileOpenPrint(file);
		fclose(file);
	}
	if(choice==2){//Lista de produtos
		FILE * file = fopen("Produtos.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");	

		fileOpenPrint(file);
			fclose(file);
		
	}
	if(choice==3){//Login de funcionario
		FILE * file = fopen("Funcionarios.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
			
			int codigos=0, funcionarios=2, codigoAux=0, funcionarioAux=0;
			char txt[30][30], input[50], funcionario[30][50], codigo[30][50];
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
				
				
					if(codigos|| funcionarios){
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

			while(canCopy==0){
				printf("Digite seu nome: ");
				gets(input);
				fflush(stdin);
				strupr(input);
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(funcionario[coluna],input)==0){
						aux=coluna;
						break;
					}
				}
				fflush(stdin);
				printf("Agora digite o codigo: ");
				gets(input);	
				if(strcmp(codigo[aux],input)==0){
					return 1;
				}
				else{
					printf("\nCodigo incorreto digite novamente.\n");
					system("pause");
				}	
				system("cls");
			}
				
		fclose(file);
	}
	
}

int main(){
	int choice=2;
	leitura(choice);
}