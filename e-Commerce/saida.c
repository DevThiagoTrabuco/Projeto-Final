void printLoad();

int getOut(int saida){
	int i = 1;
	int op;
	system("cls");
	if(saida == 0){
		printf("||Deseja sair?\n||[1]-Sim   ||[2]-N�o\n||");
	    scanf("%d", &op);
	    fflush(stdin);
		
		switch(op){
			case 1:
				system("cls");
		        printLoad("||At� o seu pr�ximo acesso :]");
				abort();
			case 2:
				return 0;
			default:
				printf("||Op��o inv�lida\n");
				system("pause");
				return 0;
		}
	} else if (saida == 1){
		system("cls");
        printLoad("||At� o seu pr�ximo acesso :]");
		abort();
	}
}