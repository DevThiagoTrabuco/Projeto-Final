void cpf(){
	char cpf[12];
	system("cls");
		
	do {
	printf("Digite o seu CPF:\n");
	scanf("%s", cpf);
		
		if (strlen(cpf) < 11 || strlen(cpf) > 11){
			printf("Por favor, digite apenas 11 n�meros.\n");
			system("pause");
			system("cls");
			continue;
		} 			
		for(int i = 0; cpf[i] != '\0';i++){
				if (!isdigit(cpf[i])){
				printf("Por favor, digite apenas n�meros\n\n");
				cpf[i] = '\0';
				system("pause");
				system("cls");
			}
		}
	} while (strlen(cpf) < 11 || strlen(cpf) > 11 || cpf == '\0');
}