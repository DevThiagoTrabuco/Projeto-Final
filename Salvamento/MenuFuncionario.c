int menuFuncionario(){
	int input;
	
	while(input!=3){
		printf("\nMenu de funcionarios\n[1]-Cadastrar Produtos\n[2]-Editar Produtos\n[3]-Sair\n");
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