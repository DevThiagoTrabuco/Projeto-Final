int menuFuncionario();
int menuAdm();

void areaRestrita(){
	int option;
	setlocale(LC_ALL, "");
	while(option!=3){
		system("cls");
		color(1);
		printf("\t\t###################\n\t\t#\t\t  #\n\t\t#  AREA RESTRITA  #\n\t\t#\t\t  #\n\t\t###################\n\n");
		color(7);
		printf("\n-------------------------------------------------");
		printf("\n||[1]-Login como Funcionario\t\t\t||\n||[2]-Login como ADM\t\t\t\t||\n||[3]-Sair\t\t\t\t\t||");
		printf("\n-------------------------------------------------");
		
		printf("\n||Por favor, escolha uma opção: \t\t\t\n||");
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
			case 3:
				menu();
			default:
				printf("\n||Opção invalida\n");
				break;
		}
	}
}