void menu();

int carrinho(int *answerPointer){
	setlocale(LC_ALL, "");
	int  products=4, produtctPrices=0, productQuantity=2,productAux=0, productPriceAux=0, productQuantityAux=0;
	char txt[200], productString[30][50], productPriceString[30][50], productQuantityString[30][50];	
	int column = 0;
	int number = 0;
	
	printf("\nCarrinho\n");
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
		float totalPrice;
		float unityPrice;
		int choice;
		int choicePrincipalMenu=0;
		int choiceAux;
		int aux=productQuantityAux;
		char unityAux[10];
		
		while(choicePrincipalMenu!=3){
			system("cls");
			totalPrice=0;
			for(int i=0; i<aux;i++){
				if( productQuantityString[i]==0){
					continue;
				}
				printf("\n%d Produto: %s\n", i+1, productString[i]);
				printf("Quantidade: %s\n", productQuantityString[i]);
				printf("Preço total: R$%s\n", productPriceString[i]);
				totalPrice=totalPrice+atof(productPriceString[i]);
			}
			printf("\n||Valor total das compras: R$%.2f\n\n||Digite uma opcao\n||[1]-Finalizar Compra.\n||[2]-Editar Pedido.\n||[3]-Voltar as Compras.\n||[4]-Voltar ao menu\n", totalPrice);
			scanf("%d", &choicePrincipalMenu);
			switch(choicePrincipalMenu){
				case 1:
					if(totalPrice!=0.0){
						printf("\n||Finalizando a compra.");
						Sleep(2000);
						*answerPointer+=1;
						return totalPrice;
					}
					else{
						printf("\n||Voce não tem compras no carrinho.\n");
						Sleep(2000);
						fflush(stdin);
						break;
					}
					break;
				case 2:
					fflush(stdin);
					system("cls");
					printf("\n||Editando pedido\n");
					for(int i=0; i<aux;i++){
						if( productQuantityString[i]==0){
							continue;
						}
						printf("\n%d Produto: %s\n", i+1, productString[i]);
						printf("Quantidade: %s\n", productQuantityString[i]);
						printf("Preço total: %s\n", productPriceString[i]);
					}
					printf("\n||O que deseja fazer?\n||[1]-Adicionar unidades ao carrinho\n||[2]-Retirar unidades do carrinho.\n");
					scanf("%d", &choice);
					switch(choice){
						case 1:
							printf("\n||Para qual produto quer adicionar?\n");
							scanf("%d", &choice);
							if(choice>aux){
								printf("\n||Produto inexistente.\n");
								Sleep(1000);
								continue;
							}
							choiceAux=choice;
							fflush(stdin);
							printf("\n||Produto: %s selecionado.\nQuantas unidades deseja adicionar? ", productString[choiceAux-1]);
							scanf("%d", &choice);
							
							unityPrice=atof(productPriceString[choiceAux-1])/atoi(productQuantityString[choiceAux-1]);
							unityPrice=unityPrice*(choice+atoi(productQuantityString[choiceAux-1]));
							
							choice=atoi(productQuantityString[choiceAux-1])+choice;
							sprintf(unityAux,"%d", choice);
							strcpy(productQuantityString[choiceAux-1], unityAux);
							
							sprintf(unityAux,"%.2f", unityPrice);
							strcpy(productPriceString[choiceAux-1], unityAux);
							
							break;
						case 2:
							printf("\n||De qual produto deseja retirar?\n");
							scanf("%d", &choice);
							if(choice>aux){
								printf("\n||Produto inexistente.\n");
								Sleep(1000);
								continue;
							}
							choiceAux=choice;
							fflush(stdin);
							printf("\n||Produto: %s selecionado.\n||Quantas unidades deseja retirar? ", productString[choiceAux-1]);
							scanf("%d", &choice);
							
							unityPrice=atof(productPriceString[choiceAux-1])/atoi(productQuantityString[choiceAux-1]);
							choice=atoi(productQuantityString[choiceAux-1])-choice;
							sprintf(unityAux,"%d", choice);
							strcpy(productQuantityString[choiceAux-1], unityAux);

							sprintf(unityAux,"%.2f", unityPrice*atoi(productQuantityString[choiceAux-1]));
							strcpy(productPriceString[choiceAux-1], unityAux);
							
							if(atoi(productQuantityString[choiceAux-1])==0){
								strcpy(productPriceString[choiceAux-1],"0.00");
							}
							fflush(stdin);
							break;
					}
				case 3:
					break;
				case 4:
					menu();
			}
			
		}	
}
