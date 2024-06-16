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
			fflush(stdin);
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\n\tBem vindo(a) � loja [PLACEHOLDER]!!");
			printf("\n---------------------------------------------------------");
			printf("\n||\t\t\t\t\t\t\t||");
			if(logged==0){
				printf("\n||[1] - Login ");
				color(4);
				printf("(N�o logado)");
				color(7);
				printf("\t\t\t\t||");
				printf("\n||[2] - Cadastro\t\t\t\t\t||\n||[3] - Ir as compras\t\t\t\t\t||\n||[4] - �rea restrita\t\t\t\t\t||\n||[5] - Fechar aplica��o\t\t\t\t||");
			}
			else{
				printf("\n||[1] - Deslogar ");
				color(1);
				printf("(Logado)");
				color(7);
				printf("\t\t\t\t||");
				printf("\n||[2] - Cadastro\t\t\t\t\t||\n||[3] - Ir as compras\t\t\t\t\t||\n||[4] - �rea restrita\t\t\t\t\t||\n||[5] - Fechar aplica��o\t\t\t\t||");
			}
			printf("\n---------------------------------------------------------");
			printf("\n||Por favor, escolha uma op��o: \t\t\t\n||");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1':
					if(logged==0){
						logged = loginClient();
					}
					else if(logged==1){
						printf("\n||Deseja deslogar?\n||Sim\n||N�o\n||");
						scanf("%c", &op2);
						fflush(stdin);
						switch(op2){
							case 'S':
								printf("||Deslogando...\n");
								Sleep(2000);
								op2=0;
								logged=0;
							break;
							case 's':
								printf("||Deslogando...\n");
								Sleep(2000);
								op2=0;
								logged=0;
							break;
							
							default:
								break;
						}
					}
					break;
				case '2':
					if(logged == 0){
						cadastrarClientes();
					} else {
						printf("||Usu�rio j� logado.\n");
						Sleep(2000);
						system("cls");
					}
					break;
				case '3':
					if(logged == 1){						
						totalPrice = comprar();							
						payment(totalPrice);
					} else {
						printf("||Logue-se primeiro.\n");
						Sleep(2000);
						system("cls");
					}
					break;
				case '4':
					if(logged==0)
						areaRestrita();
					else{
						printf("||Cliente detectado, por favor va para outra area.\n");
						Sleep(2000);
						system("cls");
					}
						
					break;
				case '5':
					exit = getOut(0);
                	break;
				default:
					printf("||Op��o inv�lida.\n");
					Sleep(1000);
					break;
			}
			system("cls");
		} 
}
