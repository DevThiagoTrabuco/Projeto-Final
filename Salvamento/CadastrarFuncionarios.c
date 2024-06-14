#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<locale.h>

#include "flush.c"

#define MAX_CHAR 80

typedef struct{
	int code;
	char employeeName[MAX_CHAR];
}Employees;

void cadastrarFuncionarios(){
	setlocale(LC_ALL,"");
	int choice=0, i=0;
	char txt[30][30], textCode[50], codeAux[20];
	
	Employees employeesStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("Funcionarios.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Funcionarios.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codes=0, employees=2, codAux=0, employeeAux=0;
			char employee[30][50], code[30][50];
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

					if(codes || employees){
						codes++;
						employees++;
					}
					if(codes%5==0){
						strcpy(code[codAux], txt[column]);
						codAux++;
					}
					if(employees%5==0){
						strcpy(employee[employeeAux], txt[column]);
						employeeAux++;	
					}
					column++;
				}
			}
			int aux=column;
			int twoFactorName=0;
			int twoFactorCode=0;
	    	
			while(canCopy==0){
				canCopy=1;
				
				fflush(stdin);
				if(twoFactorName==0){
					printf("Digite o nome do Funcionario a ser cadastrado: ");
					gets(employeesStruct[0].employeeName);
					strupr(employeesStruct[0].employeeName);
				}
				if(twoFactorCode==0){
					printf("Digite o codigo do funcionario a ser cadastrado: ");
					scanf("%d", &employeesStruct[0].code);
					flush();
					sprintf(textCode,"%d",employeesStruct[0].code);
				}
				
				for(column=0;column<aux;column++){
					if(strcmp(employee[column],employeesStruct[0].employeeName)==0 && twoFactorName==0){
						printf("\nNome de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						twoFactorName=1;
					}
				}
				for(column=0;column<aux;column++){
					if(strcmp(code[column],textCode)==0 || strcmp(code[column],codeAux)==0 && twoFactorCode==0){
						printf("Codigo de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						twoFactorCode=1;
					}
				}	
			}
			strcpy(codeAux, textCode);
			fprintf(file,"\nFuncionario: \n%s#\n", employeesStruct[0].employeeName);
			fprintf(file, "Codigo: \n%d#\n", employeesStruct[0].code);
			flush();
			fclose(file);
			printf("\nFuncionario: %s\nCodigo: %d\n", employeesStruct[0].employeeName, employeesStruct[0].code);
			printf("\nDeseja cadastrar mais algum funcionario?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de Funcionarios:)\n\n");
	    system("pause");
}
