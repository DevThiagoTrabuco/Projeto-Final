void areaRestrita();
void getBack();
int getOut();

void menu(){
	char op, op2;
	int exit;
	int logged=0;
	float totalPrice;
	setlocale(LC_ALL, "");
		system("cls");
		while(exit != 1){
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\n\tBem vindo(a) � loja [PLACEHOLDER]!!");
			if(logged==0){
				printf("\n\n[1] - Login (N�o logado) \n[2] - Cadastro\n[3] - Ir as compras\n[4] - �rea restrita\n[5] - Fechar aplica��o");
			}
			else{
				printf("\n\n[1] - Login (Logado) \n[2] - Cadastro\n[3] - Ir as compras\n[4] - �rea restrita\n[5] - Fechar aplica��o");
			}
			printf("\n\nPor favor, escolha uma op��o: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1':
					logged = loginClient();
					break;
				case '2':
					if(logged == 0){
						cadastrarClientes();
					} else {
						printf("\nUsu�rio j� logado.\n");
						Sleep(2000);
						system("cls");
					}
					break;
				case '3':
					if(logged == 1){						
						totalPrice = comprar();							
						payment(totalPrice);
					} else {
						printf("\nLogue-se primeiro.\n");
						Sleep(2000);
						system("cls");
					}
					break;
				case '4':
					areaRestrita();
					getBack();
					break;
				case '5':
					exit = getOut(0);
                	break;
				default:
					printf("Op��o inv�lida.\n");
					Sleep(1000);
					break;
			}
			system("cls");
		} 
}
