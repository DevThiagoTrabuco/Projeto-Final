
typedef struct{
	int code, stock;
	float price;
	char productName[MAX_CHAR];
}Products;

void cadastrarProdutos(){
	setlocale(LC_ALL,"");
	int choice=0, i=0;
	char txt[30][30], textCode[50], codeAux[20];
	
	Products productsStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("Produtos.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Produtos.txt", "w");
				system("pause");
				system("cls");
			}
			
			int productCodes=2, products=6, produtctPrices=4, productStocks=0, productCodeAux=0, productAux=0, productPriceAux=0, productStockAux=0, number=0;
			char txt[30][30], input[50], product[30][50], productCode[30][50], productPrice[30][50], productStock[30][50];
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
						if(productCodes|| products || produtctPrices){
							productCodes++;
							products++;
							produtctPrices++;
							productStocks++;
						}
						if(products%9==0){
							strcpy(product[productAux], txt[column]);
							number++;							
							productAux++;
						}
						if(produtctPrices%9==0){
							strcpy(productPrice[productPriceAux], txt[column]);
							productPriceAux++;
						}
						if(productCodes%9==0){
							strcpy(productCode[productCodeAux], txt[column]);
							productCodeAux++;
						}
						if(productStocks%9==0){
							strcpy(productStock[productStockAux], txt[column]);
							productStockAux++;
						}
						column++;
					}	
				}
			int aux=number;
	    	system("cls");
	    	color(8);
			printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t#  CADASTRO DE PRODUTOS  #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
			color(7);
			printf("\n-------------------------------------------------\n");
			
			fflush(stdin);
			printf("||Digite o nome do produto a ser cadastrado: ");
			gets(productsStruct[0].productName);
			strupr(productsStruct[0].productName);	
			fflush(stdin);
			
			productsStruct[0].code=number+1;
			
			printf("\n||Digite o preco do produto: ");
			scanf("%f", &productsStruct[0].price);
			fflush(stdin);
			
			printf("\n||Digite quantos produtos tem no estoque: ");
			scanf("%d", &productsStruct[0].stock);
			fflush(stdin);
			
			fprintf(file,"\nProduto: \n%s#\n", productsStruct[0].productName);
			fprintf(file, "Preco: \n%.2f#\n", productsStruct[0].price);
			fprintf(file, "Codigo: \n%d#\n", productsStruct[0].code);
			fprintf(file, "Estoque: \n%d#\n", productsStruct[0].stock);
			
			fclose(file);
			
			printf("\n||Produto: %s\n||Codigo: %d\n||Preco: %.2f\n", productsStruct[0].productName, productsStruct[0].code, productsStruct[0].price);
			printf("\n||Deseja cadastrar mais algum produto?\n||[1]Sim\n||[2]Nao\n||");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("||Obrigado por usar a plataforma de cadastro de produtos:)\n");
	    Sleep(2000);
}
