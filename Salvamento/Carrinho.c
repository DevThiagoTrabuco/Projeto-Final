#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<ctype.h>
#include<windows.h>

int carrinho(int *answerPointer){
	int  products=4, produtctPrices=0, productQuantity=2,productAux=0, productPriceAux=0, productQuantityAux=0;
	char txt[200], productString[30][50], productPriceString[30][50], productQuantityString[30][50];	
	int column = 0;
	int number = 0;
	
		FILE * file=fopen("ListaDeCompras.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio de compras.");	
			
		printf("\nCarrinho\n")		;
		
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
			printf("\nValor total das compras: R$%.2f\n\nDigite uma opcao\n1-Finalizar Compra.\n2-Editar Pedido.\n3-Voltar as Compras.\n", totalPrice);
			scanf("%d", &choicePrincipalMenu);
			switch(choicePrincipalMenu){
				case 1:
					printf("\nFinalizando a compra.");
					Sleep(2000);
					*answerPointer+=1;
					return totalPrice;
					break;
				case 2:
					fflush(stdin);
					system("cls");
					printf("\nEditando pedido\n");
					for(int i=0; i<aux;i++){
						if( productQuantityString[i]==0){
							continue;
						}
						printf("\n%d Produto: %s\n", i+1, productString[i]);
						printf("Quantidade: %s\n", productQuantityString[i]);
						printf("Preço total: %s\n", productPriceString[i]);
					}
					printf("\nO que deseja fazer?\n1-Adicionar unidades ao carrinho\n2-Retirar unidades do carrinho.\n");
					scanf("%d", &choice);
					switch(choice){
						case 1:
							printf("\nPara qual produto quer adicionar?\n");
							scanf("%d", &choice);
							if(choice>aux){
								printf("\nProduto inexistente.\n");
								Sleep(1000);
								continue;
							}
							choiceAux=choice;
							fflush(stdin);
							printf("\nProduto: %s selecionado.\nQuantas unidades deseja adicionar? ", productString[choiceAux-1]);
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
							printf("\nDe qual produto deseja retirar?\n");
							scanf("%d", &choice);
							if(choice>aux){
								printf("\nProduto inexistente.\n");
								Sleep(1000);
								continue;
							}
							choiceAux=choice;
							fflush(stdin);
							printf("\nProduto: %s selecionado.\nQuantas unidades deseja retirar? ", productString[choiceAux-1]);
							scanf("%d", &choice);
							
							unityPrice=atof(productPriceString[choiceAux-1])/atoi(productQuantityString[choiceAux-1]);
							choice=atoi(productQuantityString[choiceAux-1])-choice;
							sprintf(unityAux,"%d", choice);
							strcpy(productQuantityString[choiceAux-1], unityAux);

							sprintf(unityAux,"%.2f", unityPrice);
							strcpy(productPriceString[choiceAux-1], unityAux);
							
							if(atoi(productQuantityString[choiceAux-1])==0){
								strcpy(productPriceString[choiceAux-1],"0.00");
							}
							fflush(stdin);
							break;
					}
				case 3:
					break;
			}
			
		}
		
		
}
