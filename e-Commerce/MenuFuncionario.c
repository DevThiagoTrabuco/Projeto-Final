int menuFuncionario(){
	int input;
	setlocale(LC_ALL, "");
	while(input!=3){
		system("cls");
		color(3);
		printf("\t\t#########################\n\t\t#\t\t\t#\n\t\t#  MENU DE FUNCIONÁRIO  #\n\t\t#\t\t\t#\n\t\t#########################\n\n");
		color(7);
		printf("\n-------------------------------------------------\n||");
		printf("\n||[1]-Cadastrar Produtos\n||[2]-Editar Produtos\n||[3]-Sair\n||");
		printf("\n-------------------------------------------------");
		
		printf("\n||Por favor, escolha uma opção: \t\t\t\n||");
		scanf("%d", &input);
		fflush(stdin);
		switch(input){
			case 1:
				cadastrarProdutos();
				break;
			case 2:
				editarProduto();
				break;
			case 3:
				return 1;
		}
	}
	
}