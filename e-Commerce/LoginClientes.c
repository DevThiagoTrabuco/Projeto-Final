
int loginClient(){	
	char txt[MAX_CHAR][MAX_CHAR], textCode[MAX_CHAR], codeAux[MAX_CHAR];
	setlocale(LC_ALL, "");
    	FILE * file = fopen("Clientes.txt", "r");
    	if(file==NULL){
			printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
			FILE * file = fopen("Clientes.txt", "w");
			system("pause");
			system("cls");
		}
		int clientNames=4, emails=2, passwords=0, clientNameAux=0 , clientFirstNameAux=0, clientSurNameAux=0, emailsAux=0,  passwordAux=0;
		char clientName[MAX_CHAR][MAX_CHAR], email[MAX_CHAR][MAX_CHAR], password[MAX_CHAR][MAX_CHAR];
		int column = 0, canCopy=0;
		
		while(!feof(file)){
			if(fgets(txt[column],2000,file)){
			int line=0;
				do{
					if(txt[column][line]=='#'){
						txt[column][line]='\0';
						break;
					}
					line++;
				}while(txt[column][line]!='\n');

				if(clientNames ||  emails ){
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
		fclose(file);
		int aux=clientNameAux;
		int canCopyEmail=0;
		int canCopyPassword=0;
		char emailInput[MAX_CHAR];
		char passwordInput[MAX_CHAR];
		char choice;
		int returns=1;
		
		while(aux!=-2){
			system("cls");
			color(6);
			printf("\t\t########################\n\t\t#\t\t       #\n\t\t#   LOGIN DE CLIENTE   #\n\t\t#\t\t       #\n\t\t########################\n\n");
			color(7);
			printf("\n---------------------------------------------------------\n");
			
			printf("||Digite o Email: ");
			gets(emailInput);
			fflush(stdin);
			printf("||Agora digite a senha: ");
			gets(passwordInput);
			strupr(emailInput);
			for(column=0;column<aux;column++){
				if(strcmp(email[column],emailInput)==0 && strcmp(password[column], passwordInput)==0){
					return returns;
				}	
			}
			printf("\n||Nome ou codigo incorretos.\n||Deseja ir para o menu ou para o cadastro?\n||[1]Menu\n||[2]Cadastro\n||[3]Continuar\n||");
			scanf("%c", &choice);
			fflush(stdin);
			if (choice=='1'){
				menu();
				break;
			}
			else if(choice=='2'){
				cadastrarClientes();
				aux=-2;
			}
			
		}
}
