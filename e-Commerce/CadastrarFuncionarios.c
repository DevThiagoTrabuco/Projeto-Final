
typedef struct{
	int code;
	char employeeName[MAX_CHAR];
}Employeess;

void cadastrarFuncionarios(){
	setlocale(LC_ALL,"");
	int choice=0, i=0;
	char txt[MAX_CHAR][MAX_CHAR], textCode[MAX_CHAR], codeAux[MAX_CHAR];
	
	Employeess employeesStruct[1];
		while(choice!=2){
			int number=0;
			
	    	FILE * file = fopen("Funcionarios.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Funcionarios.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codes=0, employees=2, codAux=0, employeeAux=0;
			char employee[MAX_CHAR][MAX_CHAR], code[MAX_CHAR][MAX_CHAR];
			int column = 0, canCopy=0;
			
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

					if(codes || employees){
						codes++;
						employees++;
					}
					if(codes%5==0){
						strcpy(code[codAux], txt[column]);
						codAux++;
					}
					if(employees%5==0){
						strcpy(employee[employeeAux], txt[column]);
						employeeAux++;
						number++;
					}
					column++;
				}
			}
			int aux=employeeAux;
			system("cls");
			color(6);
			printf("\t\t############################\n\t\t#\t\t\t   #\n\t\t# CADASTRO DE FUNCIONÁRIOS #\n\t\t#\t\t\t   #\n\t\t############################\n\n");
			color(7);
			printf("\n-------------------------------------------------\n");
			
			fflush(stdin);
			printf("||Digite o nome do Funcionario a ser cadastrado: ");
			gets(employeesStruct[0].employeeName);
			strupr(employeesStruct[0].employeeName);
			
			employeesStruct[0].code=number+1;
			
			fprintf(file,"\nFuncionario: \n%s#\n", employeesStruct[0].employeeName);
			fprintf(file, "Codigo: \n%d#\n", employeesStruct[0].code);
			fclose(file);
			printf("\n||Funcionario: %s\n||Codigo: %d\n||", employeesStruct[0].employeeName, employeesStruct[0].code);
			printf("\n||Deseja cadastrar mais algum funcionario?\n||[1]Sim\n||[2]Nao\n||");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("||Obrigado por usar a plataforma de cadastro de Funcionarios:)\n\n");
	    system("pause");
}
