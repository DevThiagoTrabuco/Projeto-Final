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
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\n\tBem vindo(a) à loja [PLACEHOLDER]!!");
			if(logged==0){
				printf("\n\n[1] - Login (Não logado) \n[2] - Cadastro\n[3] - Ir as compras\n[4] - Área restrita\n[5] - Fechar aplicação");
			}
			else{
				printf("\n\n[1] - Deslogar (Logado) \n[2] - Cadastro\n[3] - Ir as compras\n[4] - Área restrita\n[5] - Fechar aplicação");
			}
			printf("\n\nPor favor, escolha uma opção: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1':
					if(logged==0){
						logged = loginClient();
					}
					else if(logged==1){
						printf("\nDeseja deslogar?\nSim\nNão\n");
						scanf("%c", &op2);
						fflush(stdin);
						switch(op2){
							case 'S':
								printf("\nDeslogando...\n");
								Sleep(2000);
								op2=0;
								logged=0;
							break;
							case 's':
								printf("\nDeslogando...\n");
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
						printf("\nUsuário já logado.\n");
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
					if(logged==0)
						areaRestrita();
					else{
						printf("\nCliente detectado, por favor va para outra area.\n");
						Sleep(2000);
						system("cls");
					}
						
					break;
				case '5':
					exit = getOut(0);
                	break;
				default:
					printf("Opção inválida.\n");
					Sleep(1000);
					break;
			}
			system("cls");
		} 
}
