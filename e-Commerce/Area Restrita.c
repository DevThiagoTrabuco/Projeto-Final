int menuFuncionario();
int menuAdm();

void areaRestrita(){
	int option;
	setlocale(LC_ALL, "");
	while(option!=3){
		printf("\n[1]-Login como Funcionario\n[2]-Login como ADM\n[3]-Sair\n");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
			if(loginFuncionarios()==1){
				menuFuncionario();
				system("pause");
			}
			else
				break;
			break;
			case 2:
				if(loginAdm()==1){
					menuAdm();
				}
				else
					break;
				break;
			default:
				printf("\nOp��o invalida\n");
				break;
		}
	}
}