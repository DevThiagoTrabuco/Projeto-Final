void printLoad();

int getOut(int saida){
	int i = 1;
	char op[1];
	system("cls");
	if(saida == 0){
		printf("||Deseja sair?\n||Sim   ||Não\n||");
	    scanf("%c", &op);
		strupr(op);
	    fflush(stdin);
		
		switch(op[0]){
			case 'S':
				system("cls");
		        printLoad("||Até o seu próximo acesso :]");
				abort();
			case 'N':
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