int getOut(int saida){
	int i = 1;
	char op[1];
	if(saida == 0){
		printf("||Deseja sair?||[1]Sim\n||[2]Nao\n||: ");
	    scanf("%c", &op);
		strupr(op);
	    fflush(stdin);
		
		switch(op[0]){
			case 'S':
				system("cls");
		        printf("||Até o seu próximo acesso :]");
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
        printf("||Até o seu próximo acesso :]");
		abort();
	}
}