void getBack(){
	//int i = 1;
	int x;
	char op[1];
		
	while(x != 1){
		printf("Deseja retornar ao menu?(S/N): ");
	    scanf("%c", &op);
	    fflush(stdin);
		strupr(op);
		
			switch(op[0]){
				case 'S':
					printf("Poggers.\n");
					system("pause");
					x = 1;
					break;
				default:
					printf("Opção inválida\n");
					system("pause");
					x = 0;
					break;
			}
		system("cls");
	}
}