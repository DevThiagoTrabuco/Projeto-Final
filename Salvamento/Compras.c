

void comprar(){
	int productCodes=2, products=6, produtctPrices=4, productStocks=0, productCodeAux=0, productAux=0, productPriceAux=0, productStockAux=0;
	char txt[200], productString[30][50], productCodeString[30][50], productPriceString[30][50], productStockString[30][50];	
	int column = 0, canCopy=0;
	int number = 0;
	
		FILE * file = fopen("Produtos.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");	
				
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
				
				if(productCodes|| products || produtctPrices){
					productCodes++;
					products++;
					produtctPrices++;
					productStocks++;
				}
				if(products%9==0){
					strcpy(productString[productAux], txt);
					number++;					
					productAux++;
					
				}
				if(produtctPrices%9==0){
					strcpy(productPriceString[productPriceAux], txt);					
					productPriceAux++;
				}
				if(productCodes%9==0){
					strcpy(productCodeString[productCodeAux], txt);					
					productCodeAux++;
				}
				if(productStocks%9==0){
					strcpy(productStockString[productStockAux], txt);
					productStockAux++;
				}
			}	
		}
		fclose(file);
	
	char productCode, productStock[30];
	float productPriceFloat;
	
	int input;
	int inputAux;
	int repeats=0;
	int endWhile=0;
	int answerPointer=0;
	
	file=fopen("ListaDeCompras.txt", "w");
	
	while(endWhile==0){
		if(repeats!=0){
			file=fopen("ListaDeCompras.txt", "a+");
		}
		system("cls");
		
		printf("\nO que deseja fazer?\n1-Lista de compras\n2-Carrinho\n");
		scanf("%d", &input);

		switch(input){
			case 1:
				for(int i=0;i<number;i++){
					printf("%d - \tProduto: %s\n", i+1,productString[i]);
					printf("\tPreco: %s\n", productPriceString[i]);
					printf("\tCodigo: %s\n\n", productCodeString[i]);
				}
				printf("\nQual produto deseja adicionar no carrinho?\n");
				scanf("%d", &input);
				
				
				inputAux=input-1;
				if(input<0){
					printf("\nOpcao invalida.\n");
					system("pause");
					system("cls");
					continue;
				}
				if(input==0){
					continue;
				}
				if(input>number){
					printf("Produto nao existe");
					
					system("pause");
					system("cls");
					continue;
				}
				printf("O produto selecionado e o %s\n", productString[inputAux]);
				printf("Digite quantos %s voce deseja: ", productString[inputAux]);
				scanf("%d", &input);
				productStockAux=input;
				if(productStockAux>atoi(productStockString[inputAux])){
					printf("\nNumero de produtos excede o estoque\n");
					system("pause");
					continue;
				}
				if(input==0){
					continue;
				}
				if(input<0){
					printf("\nOpcao invalida.\n");
					system("pause");
					system("cls");
				}
				else{
					productPriceFloat=atof(productPriceString[inputAux])*input;
					productStockAux=atoi(productStockString[inputAux])-productStockAux;
					sprintf(productStock,"%d", productStockAux);
					strcpy(productStockString[inputAux], productStock);
					
					fprintf(file,"\nProduto: \n%s#\n", productString[inputAux]);
					fprintf(file, "Quantidade: \n%d#\n", input);
					fprintf(file, "Preço: \n%.2f#\n", productPriceFloat);
					fclose(file);
					repeats++;
				}
				break;
			case 2:
				carrinho(&answerPointer);
				
				if(answerPointer!=0){
					endWhile=1;
				}
		}	
	}
	FILE * file2 = fopen("Produtos.txt", "w");
	if(file2==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");	
	int aux=0;
	while(aux<number){
		fprintf(file2,"\nProduto: \n%s#\n", productString[aux]);
		fprintf(file2, "Preco: \n%s#\n", productPriceString[aux]);
		fprintf(file2, "Codigo: \n%s#\n", productCodeString[aux]);
		fprintf(file2, "Estoque: \n%s#\n", productStockString[aux]);
		aux++;
	}
	fclose(file2);
}
