#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<locale.h>

#include "flush.c"
int editarFuncionario(){
	
	while(1){
	FILE * file = fopen("Funcionarios.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
	int codes=0, employees=2, codeAux=0, employeeAux=0;
		char txt[30][30], employee[30][50], code[30][50];
		int column = 0, number=0;
	
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
				number++;
				employeeAux++;
			}
			column++;
		}
	}
	fclose(file);
	int aux=employeeAux;
	int input;
	int inputAux;
	int replaceCode;
	int canCopy=0;
	char replaceCodeAux[50];
	char replaceName[50];
	
		system("cls");
		printf("\n\nO que deseja editar?\n1-Nome do funcionario.\n2-Codigo do funcionario.\n3-Excluir funcionario.\n");
		scanf("%d", &input);
		fflush(stdin);
		switch(input){
			case 1:
				system("cls");
				printf("\nEdição de nome\n\nDe qual funcionario deseja editar o nome?");
				for(int i=0;i<aux;i++){
					printf("\n\n%d- Funcionario: %s", i+1,employee[i]);
					printf("\nCodigo: %s", code[i]);
				}
				printf("\n\n");
				scanf("%d", &input);
				fflush(stdin);
				inputAux=input;
				system("cls");
				printf("\nO funcionario %s é o selecionado\n", employee[inputAux-1]);
				strcpy(employee[inputAux-1], "");
				
				int twoFactorName=0;
				
				while(canCopy==0){
					if(twoFactorName==0){
						printf("\nDigite o nome para mudar.\n");
						gets(replaceName);
						strupr(replaceName);
					}
					for(int i=0;i<=aux;i++){
						if(strcmp(replaceName, employee[i])==0 && twoFactorName==0){
							printf("\nNome invalido, escolha outro.\n");
							system("pause");
							break;
						}
						else{
							twoFactorName=1;
							printf("\nNome alterado com sucesso.\n");
							strcpy(employee[inputAux-1], replaceName);
							system("pause");
							
							file = fopen("Funcionarios.txt", "w");
							for(int i=0;i<aux;i++){
								fprintf(file,"\nFuncionario: \n%s#\n", employee[i]);
								fprintf(file, "Codigo: \n%s#\n", code[i]);
							}
							fclose(file);
							
							canCopy=1;
							break;
						}
					}
				}
				break;
			case 2:
				system("cls");
				printf("\nEdição de codigo\n\nDe qual funcionario deseja editar o codigo?");
				for(int i=0;i<aux;i++){
					printf("\n\n%d- Funcionario: %s", i+1,employee[i]);
					printf("\nCodigo: %s", code[i]);
				}
				printf("\n\n");
				scanf("%d", &input);
				fflush(stdin);
				inputAux=input;
				printf("\nO funcionario %s é o selecionado. Para qual codigo desejar mudar?\n", employee[inputAux-1]);
				strcpy(code[inputAux-1], "");
				scanf("%d", &replaceCode);
				sprintf(replaceCodeAux, "%d", replaceCode);
				fflush(stdin);
				while(canCopy==0){
					for(int i=0;i<aux;i++){
						if(strcmp(replaceCodeAux, code[i])==0){
							printf("\nCodigo invalido, escolha outro.\n");
							scanf("%d", &replaceCode);
							sprintf(replaceCodeAux, "%d", replaceCode);
							fflush(stdin);
						}
						/*else
							printf("\nCodigo alterado com sucesso.\n");
							strcpy(code[inputAux-1], replaceCodeAux);
							system("pause");
							
							file = fopen("Funcionarios.txt", "w");
							for(int i=0;i<aux;i++){
								fprintf(file,"\nFuncionario: \n%s#\n", employee[i]);
								fprintf(file, "Codigo: \n%s#\n", code[i]);
							}
							fclose(file);
			
							canCopy=1;
							break;*/
					}
				}
				break;
		}
	}
	
}
int main(){
	editarFuncionario();
}