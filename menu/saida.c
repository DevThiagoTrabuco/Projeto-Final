int getOut(){
	int i = 1;
	char op[1];
		
	printf("Deseja sair?(S/N): ");
    scanf("%c", &op);
    fflush(stdin);
	strupr(op);
	
	switch(op[0]){
		case 'S':
			system("cls");
	        printf("At� o seu pr�ximo acesso :]");
			abort();
		case 'N':
			return 0;
		default:
			printf("Op��o inv�lida\n");
			system("pause");
			return 0;
	}
}