int getOut(int saida);

void getBack(){
	int x;
	char op[1];
		
	while(x != 1){
		printf("||Deseja retornar ao menu?\n||Sim   ||Não\n||: ");
	    scanf("%c", &op);
	    fflush(stdin);
		strupr(op);
		
			switch(op[0]){
				case 'S':
					x = 1;
					break;
				case 'N':
					getOut(1);
					x = 1;
					break;
				default:
					printf("||Opção inválida\n");
					system("pause");
					x = 0;
					break;
			}
		system("cls");
	}
}