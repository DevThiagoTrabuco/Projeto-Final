
void menu(){
	char op, op2;
	int exit;
	setlocale(LC_ALL, "");
		
		while(exit != 1){
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\nBem vindo(a) à loja [PLACEHOLDER]!!");
			printf("\n\n[1] - Login \n[2] - Cadastro\n[3] - Visualizar catálogo\n[4] - Área restrita\n[5] - Fechar aplicação\n\nPor favor, escolha uma opção: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1'://login Cliente
					
					loginClient();
					break;
				case '2'://cadastro Cliente
					cadastrarClientes();
					break;
				case '3'://área restrita
					getBack();
					break;
				case '4'://sair da aplicação
					getBack();
					break;
				case '5'://sair da aplicação
					exit = getOut();
                	break;
				default:
					printf("Opção inválida.\n");
					Sleep(500);
					break;
			}
			system("cls");
		} 
}
