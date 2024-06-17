void summary(float totalPrice, int op){
	setlocale(LC_ALL, "");
	int  products=4, produtctPrices=0, productQuantity=2,productAux=0, productPriceAux=0, productQuantityAux=0;
	char txt[MAX_CHAR], productString[MAX_CHAR][MAX_CHAR], productPriceString[MAX_CHAR][MAX_CHAR], productQuantityString[MAX_CHAR][MAX_CHAR];	
	int column = 0;
	int number = 0;
	
	FILE * file=fopen("ListaDeCompras.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio de compras.");	
			
		while(!feof(file)){
			if(fgets(txt,500,file)){
			int line=0;
				do{
					if(txt[line]=='#'){
						txt[line]='\0';
						break;
					}
					line++;
				}while(txt[line]!='\n');
				
				if( products || produtctPrices){
					products++;
					produtctPrices++;
					productQuantity++;
				}
				if(products%7==0){
					strcpy(productString[productAux], txt);
					number++;
					productAux++;
					
				}
				if(produtctPrices%7==0){
					strcpy(productPriceString[productPriceAux], txt);	
					productPriceAux++;
				}
				if(productQuantity%7==0){
					strcpy(productQuantityString[productQuantityAux], txt);	
					productQuantityAux++;
				}
			}
		}
	fclose(file);
	system("cls");
	for(int i=0;i<number;i++){
		printf("\n[%d]-Produto: %s\n", i+1,productString[i]);
		printf("Quantidade: %s\n", productQuantityString[i]);
		printf("Preço dos produtos: %s\n", productPriceString[i]);
	}
	printf("\n\n||Valor total dos produtos: R$%.2f\n", totalPrice);
	
	FILE * file3=fopen("ListaDeVendas.txt", "r");
	int sale=0;
	char txt2[MAX_CHAR];
	while(!feof(file3)){
		int line=0;
		if(fgets(txt2,500,file3)){
			do{
				if(txt2[line]=='#'){
					sale++;
					break;
				}
				line++;
			}while(txt2[line]!='\n');
		}
	}
	fclose(file3);
	
	if(totalPrice!=0.0){
		FILE * file2=fopen("ListaDeVendas.txt", "a+");
		for(int i=0;i<number;i++){
			if(i==0){
				fprintf(file2,"\nVENDA: \n%d#\n", sale+1);
				fprintf(file2,"PRODUTO: \n%s\n",productString[i]);
				fprintf(file2,"QUANTIDADE: \n%s\n", productQuantityString[i]);
			}
			else if(i!=0){
				fprintf(file2,"PRODUTO: \n%s\n",productString[i]);
				fprintf(file2,"QUANTIDADE: \n%s\n", productQuantityString[i]);
			}
		}
		fprintf(file2,"Valor total dos produtos: \n%.2f\n", totalPrice);
		fclose(file2);
	}
	
	
	if(op == 1)
		printf("\n||Método de pagamento: Á vista\n\n");
	else if(op == 2 || op == 3) 
		printf("\n||Método de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op);
	else if(op == 4)
		printf("\n||Método de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.10));
	else if(op == 5)
		printf("\n||Método de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.20));
	else if(op == 6)
		printf("\n||Método de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.30));
	else if(op == 0)
		printf("\n||Método de pagamento: PIX\n\n");
	system("pause");
	system("cls");
}