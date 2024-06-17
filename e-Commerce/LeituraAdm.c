void areaRestrita();

int loginAdm(){
	setlocale(LC_ALL, "");
	FILE * file = fopen("ADM.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
		
	int codes=0, adms=2, codeAux=0, admAux=0;
	char txt[MAX_CHAR][MAX_CHAR], input[MAX_CHAR], adm[MAX_CHAR][MAX_CHAR], code[MAX_CHAR][MAX_CHAR];
	int column = 0, canCopy=0;
	
	while(!feof(file)){
		if(fgets(txt[column],500,file)){
		int line=0;
			do{
				if(txt[column][line]=='#'){
					txt[column][line]='\0';
					break;
				}
				line++;
			}while(txt[column][line]!='\n');
		
		
			if(codes|| adms){
				codes++;
				adms++;
			}
			if(codes%5==0){
				strcpy(code[codeAux], txt[column]);
				codeAux++;
			}
			if(adms%5==0){
				strcpy(adm[admAux], txt[column]);
				admAux++;	
			}
			column++;
		}
	}
	int aux=admAux;

	char inputName[50];
	char inputCode[50];
	char option;
	
	while(1){
		system("cls");
		color(5);
		printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t# LOGIN DE ADMINISTRADOR #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
		color(7);
		printf("\n-------------------------------------------------\n");
		
		printf("||Digite seu nome: ");
		gets(inputName);
		fflush(stdin);

		printf("||Agora digite o codigo: ");
		gets(inputCode);	
		strupr(inputCode);
		fflush(stdin);
		
		strupr(inputName);
		for(column=0;column<aux;column++){
			if(strcmp(adm[column],inputName)==0 && strcmp(code[column], inputCode)==0){
				return 1;
			}			
		}
		
		printf("\n||Nome ou codigo incorretos deseja retornar a area anterior?\n||Sim   ||Não\n||");
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
		break;
				
	}
	fclose(file);

}
