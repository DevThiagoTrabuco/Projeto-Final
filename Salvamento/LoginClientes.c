
int loginClient(){	
	char txt[30][30], textCode[50], codeAux[20];
	setlocale(LC_ALL, "");
    	FILE * file = fopen("Clientes.txt", "r");
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
		fclose(file);
		int aux=clientNameAux;
		int canCopyEmail=0;
		int canCopyPassword=0;
		char emailInput[50];
		char passwordInput[50];
		char choice;
		int returns=1;
		
		while(aux!=-2){
			
			printf("Digite Email: ");
			gets(emailInput);
			fflush(stdin);
			printf("Agora digite a senha: ");
			gets(passwordInput);
			strupr(emailInput);
			for(column=0;column<aux;column++){
				if(strcmp(email[column],emailInput)==0 && strcmp(password[column], passwordInput)==0){
					return returns;
				}
				else{
					printf("\nNome ou codigo incorretos.\nDeseja ir ao cadastro?\nSim\nNao\n");
					scanf("%c", &choice);
					fflush(stdin);
					if(choice=='s' || choice=='S'){
						cadastrarClientes();
					}
					else
						break;
				}	
				system("cls");
			}
			
		}
	fclose(file);
}
