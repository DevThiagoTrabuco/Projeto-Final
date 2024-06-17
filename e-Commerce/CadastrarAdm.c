void color(int colors);

typedef struct{
	int code;
	char admName[MAX_CHAR];
}Employees;

void cadastrarAdms(){
	setlocale(LC_ALL,"");
	int choice=0, i=0;
	char txt[MAX_CHAR][MAX_CHAR], textCode[MAX_CHAR], codeAux[MAX_CHAR];
	
	Employees admsStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("ADM.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("ADM.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codes=0, adms=2, codAux=0, admAux=0, number=0;
			char adm[MAX_CHAR][MAX_CHAR], code[MAX_CHAR][MAX_CHAR];
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

					if(codes || adms){
						codes++;
						adms++;
					}
					if(codes%5==0){
						strcpy(code[codAux], txt[column]);
						codAux++;
					}
					if(adms%5==0){
						strcpy(adm[admAux], txt[column]);
						admAux++;
						number++;	
					}
					column++;
				}
			}
			int aux=admAux;
			system("cls");
			color(5);
			printf("\t\t####################################\n\t\t#\t\t\t\t   #\n\t\t#    CADASTRO DE ADMINISTRADORES   #\n\t\t#\t\t\t\t   #\n\t\t####################################\n\n");
			color(7);
			printf("\n-------------------------------------------------\n");
		
			fflush(stdin);
			printf("||Digite o nome do Administrador a ser cadastrado: ");
			gets(admsStruct[0].admName);
			strupr(admsStruct[0].admName);
			
			admsStruct[0].code=number+1;
			
			fprintf(file,"\nAdministrador: \n%s#\n", admsStruct[0].admName);
			fprintf(file, "Codigo: \n%d#\n", admsStruct[0].code);
			fclose(file);
			printf("\n||Administrador: %s\n||Codigo: %d\n||", admsStruct[0].admName, admsStruct[0].code);
			printf("\n||Deseja cadastrar mais algum Administrador?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de Administradores:)\n\n");
	    system("pause");
}

