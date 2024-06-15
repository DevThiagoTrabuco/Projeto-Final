
void menu(){
	char op, op2;
	int exit;
	float totalPrice;
	setlocale(LC_ALL, "");
		system("cls");
		while(exit != 1){
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\nBem vindo(a) à loja [PLACEHOLDER]!!");
			printf("\n\n[1] - Login \n[2] - Cadastro\n[3] - Ir as compras\n[4] - Área restrita\n[5] - Fechar aplicação\n\nPor favor, escolha uma opção: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1':
					loginClient();
					break;
				case '2':
					cadastrarClientes();
					break;
				case '3':
					
					if(totalPrice=comprar()!=0){
						payment(totalPrice);
					}
					
					break;
				case '4':
					areaRestrita();
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
