
int editarProduto(){
	setlocale(LC_ALL, "");
	
	while(1){
		FILE * file = fopen("Produtos.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
		int productCodes=2, products=6, produtctPrices=4, productStocks=0, productCodeAux=0, productAux=0, productPriceAux=0, productStockAux=0;
		char txt[MAX_CHAR], productString[MAX_CHAR][MAX_CHAR], productCodeString[MAX_CHAR][MAX_CHAR], productPriceString[MAX_CHAR][MAX_CHAR], productStockString[MAX_CHAR][MAX_CHAR];	
		int column = 0, canCopy=0;
		int number = 0;
		
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
		int aux=productStockAux;
		int input;
		int inputAux;
		
		
			system("cls");
	    	color(8);
			printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t#   EDIÇÃO DE PRODUTOS   #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
			color(7);
			printf("\n-------------------------------------------------\n");
			
			printf("||O que deseja editar?\n||[1]-Nome do produto.\n||[2]-Preço do produto\n||[3]-Estoque do produto\n||[4]-Excluir produto.\n||[5]-Voltar ao menu.\n||");
			scanf("%d", &input);
			fflush(stdin);
			switch(input){
				case 1:
					system("cls");
					printf("||De qual produto deseja editar o nome?");
					for(int i=0;i<aux;i++){
						printf("\n||%d- Produto: %s", i+1,productString[i]);
					}
					printf("\n||\n||");
					scanf("%d", &input);
					
					if(input>aux){
						printf("\n||Opção inválida.\n");
						Sleep(2000);
						break;
					}
					
					fflush(stdin);
					inputAux=input;
					system("cls");
					printf("\n||O produto %s é o selecionado\n", productString[inputAux-1]);
					strcpy(productString[inputAux-1], "");
	
					printf("\n||Digite o novo nome.\n||");
					gets(productString[inputAux-1]);
					strupr(productString[inputAux-1]);
				
					printf("\n||Nome alterado com sucesso.\n");
					system("pause");
					
					file = fopen("Produtos.txt", "w");
					for(int i=0;i<aux;i++){
						fprintf(file,"\nProduto: \n%s#\n", productString[i]);
						fprintf(file, "Preco: \n%s#\n", productPriceString[i]);
						fprintf(file, "Codigo: \n%s#\n", productCodeString[i]);
						fprintf(file, "Estoque: \n%s#\n", productStockString[i]);
					}
					fclose(file);
					break;
	
	
				case 2:
					system("cls");
					printf("\n-------------------------------------------------\n");
					
					printf("||De qual produto deseja editar o preço?");
					for(int i=0;i<aux;i++){
						printf("\n||%d- Produto: %s", i+1,productString[i]);
						printf("\n||Preço: R$%s", productPriceString[i]);
					}
					printf("\n||\n||");
					scanf("%d", &input);
					
					if(input>aux){
						printf("\n||Opção inválida.\n||");
						Sleep(2000);
						break;
					}
					
					fflush(stdin);
					inputAux=input;
					system("cls");
					printf("\n||O produto %s é o selecionado\n||", productString[inputAux-1]);
					strcpy(productPriceString[inputAux-1], "");
	
					printf("\n||Digite o novo preço.\n||");
					gets(productPriceString[inputAux-1]);
					strupr(productPriceString[inputAux-1]);
				
					printf("\n||Preço alterado com sucesso.\n");
					system("pause");
					
					file = fopen("Produtos.txt", "w");
					for(int i=0;i<aux;i++){
						fprintf(file,"\nProduto: \n%s#\n", productString[i]);
						fprintf(file, "Preco: \n%s#\n", productPriceString[i]);
						fprintf(file, "Codigo: \n%s#\n", productCodeString[i]);
						fprintf(file, "Estoque: \n%s#\n", productStockString[i]);
					}
					fclose(file);
					break;
				
				case 3:
					system("cls");
					printf("\n-------------------------------------------------\n||");
					
					printf("\n||De qual produto deseja editar o Estoque?");
					for(int i=0;i<aux;i++){
						printf("\n||%d- Produto: %s", i+1,productString[i]);
						printf("\n||Estoque: %s", productStockString[i]);
					}
					printf("\n||\n||");
					scanf("%d", &input);
					
					if(input>aux){
						printf("\n||Opção inválida.\n||");
						Sleep(2000);
						break;
					}
					
					fflush(stdin);
					inputAux=input;
					system("cls");
					printf("\n||O produto %s é o selecionado\n||", productString[inputAux-1]);
					strcpy(productStockString[inputAux-1], "");
	
					printf("\n||Digite o novo estoque.\n||");
					gets(productStockString[inputAux-1]);
					strupr(productStockString[inputAux-1]);
				
					printf("\n||Estoque alterado com sucesso.\n");
					system("pause");
					
					file = fopen("Produtos.txt", "w");
					for(int i=0;i<aux;i++){
						fprintf(file,"\nProduto: \n%s#\n", productString[i]);
						fprintf(file, "Preco: \n%s#\n", productPriceString[i]);
						fprintf(file, "Codigo: \n%s#\n", productCodeString[i]);
						fprintf(file, "Estoque: \n%s#\n", productStockString[i]);
					}
					fclose(file);
					break;
				
				case 4:
					system("cls");
					color(4);
					printf("\t\t##########################\n\t\t#\t\t\t #\n\t\t#   REMOÇÃO DE PRODUTO   #\n\t\t#\t\t\t #\n\t\t##########################\n\n");
					color(7);
					printf("\n-------------------------------------------------\n||");
					
					printf("\n||Lista de produto:");
					for(int i=0;i<aux;i++){
						printf("\n||%d- Produto: %s", i+1,productString[i]);
					}
					printf("\n||Qual produto deseja remover?\n||");
					scanf("%d", &input);
					
					if(input>aux){
						printf("\n||Opção invalida.\n||");
						Sleep(2000);
						break;
					}
					
					fflush(stdin);
					file = fopen("Produtos.txt", "w");
					strcpy(productString[input-1], "");
					strcpy(productCodeString[input-1], "");
					strcpy(productPriceString[input-1], "");
					strcpy(productStockString[input-1], "");
					for(int i=0;i<aux;i++){
						if(i==input-1){
							continue;
						}
					fprintf(file,"\nProduto: \n%s#\n", productString[i]);
					fprintf(file, "Preco: \n%s#\n", productPriceString[i]);
					fprintf(file, "Codigo: \n%s#\n", productCodeString[i]);
					fprintf(file, "Estoque: \n%s#\n", productPriceString[i]);
						
					}
					fclose(file);
					break;
				case 5:
					system("cls");
					printf("||Voltando ao menu\n");
					Sleep(1000);
					return 1;
					break;
			}
		}
		
}
