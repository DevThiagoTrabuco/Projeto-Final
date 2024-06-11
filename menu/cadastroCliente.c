typedef struct{
	char name[20];
	char surname[50];
	char email[50];
	char password[20];
} Register;

Register client[30];

int clientList(){
	char op[1];
	int i = 0;
	
	system("cls");
	printf("Voc√™ j√° possui cadastro?(S/N): ");
	scanf("%c", &op);
	fflush(stdin);
	strupr(op);
	
	switch(op[0]){
		case 'S': //login (checa o documento retorna se h√° email cadastrado ou senha correta)			
			printf("\nDigite o seu email:\n");
			gets(client[i].email);
			printf("Digite a sua senha:\n");
			gets(client[i].password);
			break;
		case 'N': //cadastro (escreve no documento)			
			printf("\nNome:\n");
			gets(client[i].name);
			printf("Sobrenome:\n");
			gets(client[i].surname);
			printf("Email:\n");
			gets(client[i].email);
			printf("Senha:\n");
			gets(client[i].password);
			while(1){
				if(strlen(client[i].password)<5){
				printf("\nSenha fraca, digite uma nova senha: ");
				gets(client[i].password);
				}
				else 
				break;
				}
			fflush(stdin);
			break;
		default:
			printf("OpÁ„o inv·lida\n");
			system("pause");
			return 0;
	}
	system("pause");
}
