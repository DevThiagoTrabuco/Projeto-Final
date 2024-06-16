void cpf(){
	char cpf[12];
	system("cls");
		
	do {
	printf("||Digite o seu CPF:\n");
	scanf("%s", cpf);
		
		if (strlen(cpf) < 11 || strlen(cpf) > 11){
			printf("||Por favor, digite apenas 11 números.\n");
			system("pause");
			system("cls");
			continue;
		} 			
		for(int i = 0; cpf[i] != '\0';i++){
				if (!isdigit(cpf[i])){
				printf("||Por favor, digite apenas números\n\n");
				cpf[i] = '\0';
				system("pause");
				system("cls");
			}
		}
	} while (strlen(cpf) < 11 || strlen(cpf) > 11 || cpf == '\0');
}