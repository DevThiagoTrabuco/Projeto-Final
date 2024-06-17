
int loginFuncionarios(){
	setlocale(LC_ALL, "");
	
	FILE * file = fopen("Funcionarios.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
		
		int codes=0, employees=2, codeAux=0, employeeAux=0;
		char txt[MAX_CHAR][MAX_CHAR], input[MAX_CHAR], employee[MAX_CHAR][MAX_CHAR], code[MAX_CHAR][MAX_CHAR];
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
					employeeAux++;	
				}
				column++;
			}
		}
		int aux=employeeAux;
		int canCopyName=0;
		int canCopyCode=0;
		char inputName[50];
		char inputCode[50];
		char option;
		
		while(option!='s' || option!='S'){
			system("cls");
			color(5);
			printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t#  LOGIN DE FUNCIONÁRIO  #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
			color(7);
			printf("\n-------------------------------------------------\n");
			
				printf("||Digite seu nome: ");
				gets(inputName);
				fflush(stdin);
				printf("||Agora digite o codigo: ");
				gets(inputCode);
				strupr(inputName);
				for(column=0;column<aux;column++){
					if(strcmp(employee[column],inputName)==0 && strcmp(code[column], inputCode)==0){
						return 1;
					}		
				}
				printf("\n||Nome ou codigo incorretos deseja retornar a area anterior?\n||[1]Sim   ||[2]Nao\n||");
				scanf("%c", &option);
				switch(option){
					case 'S':
						printf("||\n||Retornando...");
						Sleep(1000);
						fflush(stdin);
						areaRestrita();
						break;
					case 's':
						printf("||\n||Retornando...");
						Sleep(1000);
						fflush(stdin);
						areaRestrita();
						break;
					default:
						fflush(stdin);
						break;
				}
				
			}
			fclose(file);
		}
	



