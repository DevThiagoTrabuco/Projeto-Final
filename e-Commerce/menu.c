void areaRestrita();
int getOut();

void menu(){
	char op, op2;
	int exit;
	int logged=0;
	float totalPrice;
	setlocale(LC_ALL, "");
		system("cls");
		while(exit != 1){
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\nBem vindo(a) � loja [PLACEHOLDER]!!");
			printf("\n\n[1] - Login \n[2] - Cadastro\n[3] - Ir as compras\n[4] - �rea restrita\n[5] - Fechar aplica��o\n\nPor favor, escolha uma op��o: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1':
					logged=loginClient();
					break;
				case '2':
					cadastrarClientes();
					break;
				case '3':
					if(logged==1){						
						totalPrice=comprar();							
						payment(totalPrice);
						
					}
					else{
						printf("\nLogue-se primeiro\n");
						Sleep(2000);
						system("cls");
					}
					
					break;
				case '4':
					areaRestrita();
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
