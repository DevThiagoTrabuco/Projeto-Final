void sales();
int menuAdm(){
	setlocale(LC_ALL, "");
	int input;
	while(input!=7){
		system("cls");
		color(6);
		printf("\t\t#############################\n\t\t#\t\t\t    #\n\t\t#   MENU DE ADMINISTRADOR   #\n\t\t#\t\t\t    #\n\t\t#############################\n\n");
		color(7);
		printf("\n-------------------------------------------------\n");
		printf("||\n||[1]-Cadastrar Funcionario.\n||[2]-Editar Funcionario.\n||[3]-Cadastrar Produto\n||[4]-Editar Produto\n||[5]-Cadastrar ADM\n||[6]-Lista de Vendas\n||[7]-Sair\n||");
		printf("\n-------------------------------------------------\n");
		
		printf("\n||Por favor, escolha uma opção: \t\t\t\n||");		
		scanf("%d", &input);
		fflush(stdin);
		switch(input){
			case 1:
				cadastrarFuncionarios();
				break;
			case 2:
				editarFuncionario();
				break;
			case 3:
				cadastrarProdutos();
				break;
			case 4:
				editarProduto();
				break;
			case 5:
				cadastrarAdms();
				break;
			case 6:
				sales();
				break;
			case 7:
				return 1;
			default:
				printf("\n||Opção inválida\n||");
		}
	}
	
}