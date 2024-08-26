void printLoad();

int getOut(int saida){
	int i = 1;
	int op;
	system("cls");
	if(saida == 0){
		printf("||Deseja sair?\n||[1]-Sim   ||[2]-Não\n||");
	    scanf("%d", &op);
	    fflush(stdin);
		
		switch(op){
			case 1:
				system("cls");
		        printLoad("||Até o seu próximo acesso :]");
				abort();
			case 2:
				return 0;
			default:
				printf("||Opção inválida\n");
				system("pause");
				return 0;
		}
	} else if (saida == 1){
		system("cls");
        printLoad("||Até o seu próximo acesso :]");
		abort();
	}
}