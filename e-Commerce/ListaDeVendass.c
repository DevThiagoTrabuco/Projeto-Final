
void sales(){
	system("cls");
	color(6);
	printf("\t\t#############################\n\t\t#\t\t\t    #\n\t\t#      LISTA DE VENDAS      #\n\t\t#\t\t\t    #\n\t\t#############################\n\n");
	color(7);
	printf("\n-------------------------------------------------\n");	
	FILE * file=fopen("ListaDeVendas.txt", "r");
	char txt[50];
	int line=0;
	while(!feof(file)){
		if(fgets(txt,500,file)){
			printf("||%s", txt);
		}
	}
	printf("\n-------------------------------------------------\n");	
	system("pause");
	fclose(file);
}
