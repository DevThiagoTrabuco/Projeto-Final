#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<locale.h>

#include "flush.c"

#define MAX_CHAR 80

typedef struct{
	char admName[MAX_CHAR], code[MAX_CHAR];
}Employees;

void cadastrarAdms(){
	setlocale(LC_ALL,"");
	int choice=0, i=0;
	char txt[30][30], textCode[50], codeAux[20];
	
	Employees admsStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("ADM.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("ADM.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codes=0, adms=2, codAux=0, admAux=0;
			char adm[30][50], code[30][50];
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

					if(codes || adms){
						codes++;
						adms++;
					}
					if(codes%5==0){
						strcpy(code[codAux], txt[column]);
						codAux++;
					}
					if(adms%5==0){
						strcpy(adm[admAux], txt[column]);
						admAux++;	
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
					printf("Digite o nome do Administrador a ser cadastrado: ");
					gets(admsStruct[0].admName);
					strupr(admsStruct[0].admName);
				}
				if(twoFactorCode==0){
					printf("Digite o codigo do Administrador a ser cadastrado(Dica: utilize letras e numeros): ");
					scanf("%s", admsStruct[0].code);
					flush();
					strupr(admsStruct[0].code);
				}
				
				for(column=0;column<aux;column++){
					if(strcmp(adm[column],admsStruct[0].admName)==0 && twoFactorName==0){
						printf("\nNome de Administrador j� cadastrado.\n\n");
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
					if(strcmp(code[column], admsStruct[0].code)==0 && twoFactorCode==0){
						printf("Codigo de Admnistrador j� cadastrado.\n\n");
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
			fprintf(file,"\nFuncionario: \n%s#\n", admsStruct[0].admName);
			fprintf(file, "Codigo: \n%s#\n", admsStruct[0].code);
			fclose(file);
			printf("\nFuncionario: %s\nCodigo: %s\n", admsStruct[0].admName, admsStruct[0].code);
			printf("\nDeseja cadastrar mais algum Administrador?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de Administradores:)\n\n");
	    system("pause");
}
int main(){
	cadastrarAdms();
}
