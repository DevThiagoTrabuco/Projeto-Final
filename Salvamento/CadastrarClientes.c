#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<locale.h>

#include "flush.c"

#define MAX_CHAR 80

typedef struct{
	char name[20];
	char surname[50];
	char email[50];
	char password[20];
}Register;

void cadastrarClientes(){
	setlocale(LC_ALL,"");
	int choice=0, i=0;
	char txt[30][30], textCode[50], codeAux[20];
	
	Register client[1];
		while(choice!=2){
			
	    	FILE * file = fopen("Clientes.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Clientes.txt", "w");
				system("pause");
				system("cls");
			}
			
			int clientNames=4, emails=2, passwords=0, clientNameAux=0 , clientFirstNameAux=0, clientSurNameAux=0, emailsAux=0,  passwordAux=0;
			char clientName[30][50], email[30][50], password[30][50];
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

					if(clientNames ||  emails || passwords){
						clientNames++;
						emails++;
						passwords++;
					}
					if(clientNames%7==0){
						strcpy(clientName[clientNameAux], txt[coluna]);						
						clientNameAux++;
					}
					if(emails%7==0){
						strcpy(email[emailsAux], txt[coluna]);				
						emailsAux++;	
					}
					coluna++;
				}
			}
			int aux=clientNameAux;
			int doisFatoresNome=0;
			int doisFatoresSobreNome=0;
			int doisFatoresSenha=0;
	    	int doisFatoresEmail=0;
	    	char choiceEmail;
	    	
			while(canCopy==0){
				canCopy=1;
				
				fflush(stdin);
				if(doisFatoresNome==0){
					printf("\nDigite o nome e sobrenome do Cliente a ser cadastrado: ");
					gets(client[0].name);
					strupr(client[0].name);
					doisFatoresNome=1;
				}
				if(doisFatoresSenha==0){
					printf("\nDigite a senha do Cliente a ser cadastrado: ");
					gets(client[0].password);
					while(1){
						if(strlen(client[0].password)<5){
							printf("\nSenha fraca, digite uma nova senha: ");
							gets(client[i].password);
						}
						else 
						break;
					}
					doisFatoresSenha=1;
				}
				if(doisFatoresEmail==0){
					printf("\nDigite o e-mail do Cliente a ser cadastrado: ");
					gets(client[0].email);
					strupr(client[0].email);
					doisFatoresEmail=1;
				}
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(email[coluna], client[0].email)==0){
						printf("\nEmail de cliente já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						printf("\nDeseja ir para a pagina de login?\nSim\nNão\n");
						scanf("%c", &choiceEmail);
						fflush(stdin);
						
						if(choiceEmail=='S'|| choiceEmail=='s'){
							printf("\nRedirecionando a pagina de login\n");
							Sleep(2000);
						}
						else {
							system("cls");
							printf("\nDigite o e-mail do Cliente a ser cadastrado: ");
							gets(client[0].email);
							strupr(client[0].email);
						}

						break;
					}
				}
			}
			fprintf(file,"\nCliente: \n%s#\n", client[0].name);
			fprintf(file, "Email: \n%s#\n", client[0].email);
			fprintf(file, "Senha: \n%s#\n", client[0].password);
			
			fclose(file);
			
			printf("\nDeseja cadastrar mais algum cliente?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de funcionarios:)\n\n");
	    system("pause");
	}
