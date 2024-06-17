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
		printf("\n||\n||[1]-Login como Funcionario\n||[2]-Login como Administrador\n||[3]-Sair\n||");
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
				printf("\n||Opção inválida\n");
				break;
		}
	}
}