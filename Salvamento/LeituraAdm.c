
int loginAdm(){

	FILE * file = fopen("ADM.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
		
	int codes=0, adms=2, codeAux=0, admAux=0;
	char txt[30][30], input[50], adm[30][50], code[30][50];
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
	
	while(1){
		printf("Digite seu nome: ");
		gets(inputName);
		fflush(stdin);

		printf("Agora digite o codigo: ");
		gets(inputCode);	
		strupr(inputCode);
		fflush(stdin);
		
		strupr(inputName);
		for(column=0;column<aux;column++){
			if(strcmp(adm[column],inputName)==0 && strcmp(code[column], inputCode)==0){
				return 1;
			}			
		}
		
		printf("\nNome ou codigo incorretos digite novamente.\n");
		Sleep(2000);
		break;
				
	}
	fclose(file);

}
