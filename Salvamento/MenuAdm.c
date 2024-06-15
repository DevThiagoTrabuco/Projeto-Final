int menuAdm(){
	
	int input;
	while(input!=6){
		printf("\nMenu de Adm\n[1]-Cadastrar Funcionario.\n[2]-Editar Funcionario.\n[3]-Cadastrar Produto\n[4]-Editar Produto\n[5]-Cadastrar ADM\n[6]- Sair\n");
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
				return 1;
			default:
				printf("\nOpção invalida\n");
		}
	}
	
}