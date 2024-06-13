#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flush.c"

int loginClient(){
	
	char txt[30][30], textCode[50], codeAux[20];
	
		
    	FILE * file = fopen("Clientes.txt", "a+");
    	if(file==NULL){
			printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
			FILE * file = fopen("Clientes.txt", "w");
			system("pause");
			system("cls");
		}
		
		int clientNames=4, emails=2, passwords=0, clientNameAux=0 , clientFirstNameAux=0, clientSurNameAux=0, emailsAux=0,  passwordAux=0;
		char clientName[30][50], email[30][50], password[30][50];
		int column = 0, canCopy=0;
		
		while(!feof(file)){
			if(fgets(txt[column],500,file)){
			int line=0;
				do{
					if(txt[column][line]=='#'){
						txt[column][line]='\0';
						break;
					}
					line++;
				}while(txt[column][line]!='\n');

				if(clientNames ||  emails || passwords){
					clientNames++;
					emails++;
					passwords++;
				}
				if(clientNames%7==0){
					strcpy(clientName[clientNameAux], txt[column]);
					
					clientNameAux++;
				}
				if(emails%7==0){
					strcpy(email[emailsAux], txt[column]);
					
					emailsAux++;	
				}
				if(passwords%7==0){
					strcpy(password[passwordAux], txt[column]);
					passwordAux++;
				}
				column++;
			}
		}
		int aux=clientNameAux;
		int canCopyEmail=0;
		int canCopyPassword=0;
		char emailInput[50];
		char passwordInput[50];
		char choice;
		
		while(1){
			if(canCopyEmail==0){
				system("cls");
				printf("\nDigite seu email: ");
				gets(emailInput);
				fflush(stdin);
				strupr(emailInput);
				for(column=0;column<aux;column++){
					if(strcmp(email[column],emailInput)==0){
						aux=column;
						canCopyPassword=1;
						canCopyEmail=1;
						break;
					}
				}
				if(canCopyEmail==0){
						printf("\nEmail nao encontrado no banco de dados, deseja prosseguir para o cadastro?\nSim.\nNao.\n");
						scanf("%c", &choice);
						if(choice=='S' || choice=='s'){
							printf("redirecionando para a pagina de cadastro");
						}
					fflush(stdin);
				}
			}
			if(canCopyPassword==1){
				printf("\nUsuario: %s\nAgora digite a senha: ", emailInput);
				gets(passwordInput);	
				if(strcmp(password[aux],passwordInput)==0){
					return 1;
				}
				else{
					printf("\nSenha incorreta digite novamente.\n");
					system("pause");
				}	
				system("cls");
			}
		}
		fclose(file);
}
int main(){
	loginClient();
}
