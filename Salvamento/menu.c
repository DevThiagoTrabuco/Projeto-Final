
void menu(){
	char op, op2;
	int exit;
	setlocale(LC_ALL, "");
		
		while(exit != 1){
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\nBem vindo(a) � loja [PLACEHOLDER]!!");
			printf("\n\n[1] - Login \n[2] - Cadastro\n[3] - Visualizar cat�logo\n[4] - �rea restrita\n[5] - Fechar aplica��o\n\nPor favor, escolha uma op��o: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1'://login Cliente
					
					loginClient();
					break;
				case '2'://cadastro Cliente
					cadastrarClientes();
					break;
				case '3'://�rea restrita
					getBack();
					break;
				case '4'://sair da aplica��o
					getBack();
					break;
				case '5'://sair da aplica��o
					exit = getOut();
                	break;
				default:
					printf("Op��o inv�lida.\n");
					Sleep(500);
					break;
			}
			system("cls");
		} 
}
