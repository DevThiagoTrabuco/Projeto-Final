#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flush.c"

int loginFuncionario(){
	
	FILE * file = fopen("Funcionarios.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
		
		int codes=0, employees=2, codeAux=0, employeeAux=0;
		char txt[30][30], input[50], employee[30][50], code[30][50];
		int column = 0, canCopy=0;
		
		while(!feof(file)){
			if(fgets(txt[column],500,file)){
			int linha=0;
				do{
					if(txt[column][linha]=='#'){
						txt[column][linha]='\0';
						break;
					}
					linha++;
				}while(txt[column][linha]!='\n');
			
			
				if(codes|| employees){
					codes++;
					employees++;
				}
				if(codes%5==0){
					strcpy(code[codeAux], txt[column]);
					codeAux++;
				}
				if(employees%5==0){
					strcpy(employee[employeeAux], txt[column]);
					employeeAux++;	
				}
				column++;
			}
		}
		int aux=employeeAux;
		int canCopyName=0;
		int canCopyCode=0;
		char inputName[50];
		char inputCode[50];
		
		while(1){
			if(canCopyName==0){
				printf("Digite seu nome: ");
				gets(inputName);
				fflush(stdin);
				printf("Agora digite o codigo: ");
				gets(inputCode);
				strupr(inputName);
				for(column=0;column<aux;column++){
					if(strcmp(employee[column],inputName)==0 && strcmp(code[column], inputCode)==0){
						return 1;
						
					}
					else{
						printf("\nNome ou codigo incorretos digite novamente.\n");
						system("pause");
						break;
					}	
					system("cls");
				}
			}
		}
	fclose(file);
}

