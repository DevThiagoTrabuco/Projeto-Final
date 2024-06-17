
int editarFuncionario(){
	setlocale(LC_ALL, "");
	int input;
	while(input != 3){
	FILE * file = fopen("Funcionarios.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
	int codes=0, employees=2, codeAux=0, employeeAux=0;
		char txt[MAX_CHAR][MAX_CHAR], employee[MAX_CHAR][MAX_CHAR], code[MAX_CHAR][MAX_CHAR];
		int column = 0, number=0;
	
	while(!feof(file)){
		if(fgets(txt[column],500,file)){
		int linha=0;
			do{
				if(txt[column][linha]=='#'){
					txt[column][linha]='\0';
					break;
				}
				linha++;
			}while(txt[column][linha]!='\n');
		
			if(codes|| employees){
				codes++;
				employees++;
			}
			if(codes%5==0){
				strcpy(code[codeAux], txt[column]);
				codeAux++;
				
			}
			if(employees%5==0){
				strcpy(employee[employeeAux], txt[column]);
				number++;
				employeeAux++;
			}
			column++;
		}
	}
	fclose(file);
	int aux=employeeAux;
	int inputAux;
	int replaceCode;
	int canCopy=0;
	char replaceCodeAux[50];
	char replaceName[50];
	
		system("cls");
    	color(8);
		printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t# EDIÇÃO DE FUNCIONÁRIOS #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
		color(7);
		printf("\n-------------------------------------------------\n");
		
		printf("||O que deseja editar?\n||[1]-Nome do funcionario.\n||[2]-Excluir funcionario.\n||[3]-Voltar ao menu\n||");
		scanf("%d", &input);
		fflush(stdin);
		switch(input){
			case 1:
				system("cls");
				printf("||De qual funcionario deseja editar o nome?");
				for(int i=0;i<aux;i++){
					printf("\n||%d- Funcionario: %s", i+1,employee[i]);
					printf("\n||Codigo: %s", code[i]);
				}
				printf("\n||\n||");
				scanf("%d", &input);
				
				if(input>aux){
					printf("\n||Opção inválida.\n||");
					Sleep(1000);
					break;
				}
				
				fflush(stdin);
				inputAux=input;
				system("cls");
				printf("\n||O funcionario %s é o selecionado\n", employee[inputAux-1]);
				strcpy(employee[inputAux-1], "");
				
				
				printf("\n||Para qual nome deseja alterar?\n||");
				gets(employee[inputAux-1]);
				strupr(employee[inputAux-1]);
				fflush(stdin);
				printf("\n||Nome alterado com sucesso.\n");
				Sleep(1000);
				
				file = fopen("Funcionarios.txt", "w");
				for(int i=0;i<aux;i++){
					fprintf(file,"\nFuncionario: \n%s#\n", employee[i]);
					fprintf(file, "Codigo: \n%s#\n", code[i]);
				}
				fclose(file);
				break;
			
			case 2:
				system("cls");
				color(4);
				printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t# REMOÇÃO DE FUNCIONÁRIO #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
				color(7);
				printf("\n-------------------------------------------------\n||");
				
				printf("||Lista de funcionarios:");
				for(int i=0;i<aux;i++){
					printf("\n||%d- Funcionario: %s", i+1,employee[i]);
					printf("\n||Codigo: %s", code[i]);
				}
				printf("\n||\n||Qual funcionario deseja remover?\n");
				scanf("%d", &input);
				
				if(input>aux){
					printf("\n||Opção inválida.\n");
					break;
				}
				
				fflush(stdin);
				file = fopen("Funcionarios.txt", "w");
				strcpy(employee[input-1], "");
				strcpy(code[input-1], "");
				for(int i=0;i<aux;i++){
					if(i==input-1){
						continue;
					}
					fprintf(file,"\nFuncionario: \n%s#\n", employee[i]);
					fprintf(file, "Codigo: \n%s#\n", code[i]);
					
				}
				fclose(file);
				break;
			case 3:
				system("cls");
				printf("||Voltando ao menu\n");
				Sleep(1000);
				break;
		}
	}
	
}
