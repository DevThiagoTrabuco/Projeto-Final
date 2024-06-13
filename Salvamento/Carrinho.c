#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>

int carrinho(){
	int  products=4, produtctPrices=0, productQuantity=2,productAux=0, productPriceAux=0, productQuantityAux=0;
	char txt[200], productString[30][50], productPriceString[30][50], productQuantityString[30][50];	
	int column = 0, canCopy=0;
	int number = 0;
	
		FILE * file=fopen("ListaDeCompras.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");	
			
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
					printf("\n%d Produto: %s\n", number, productString[productAux]);			
					productAux++;
					
				}
				if(produtctPrices%7==0){
					strcpy(productPriceString[productPriceAux], txt);	
					printf("Preço total: %s\n", productPriceString[productPriceAux]);				
					productPriceAux++;
				}
				if(productQuantity%7==0){
					strcpy(productQuantityString[productQuantityAux], txt);	
					printf("Quantidade: %s\n", productQuantityString[productQuantityAux]);				
					productQuantityAux++;
				}
			
			}
		
		}	
		fclose(file);
		float totalPrice=0.0;
		float unityPrice=0.0;
		int choice;
		
		printf("\nDigite uma opcao\n1-Finalizar Compra.\n2-Editar Pedido.\n3-Voltar as Compras.\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nFinalizando a compra.");
				Sleep(2000);
				break;
			case 2:
				fflush(stdin);
				system("cls");
				printf("\nEditando pedido\n");
				for(int i=0; i<productQuantityAux;i++){
					printf("\n%d Produto: %s\n", i+1, productString[i]);
					printf("Quantidade: %s\n", productQuantityString[i]);
					printf("Preço total: %s\n", productPriceString[i]);
				}
				printf("\nO que deseja fazer?\n1-Retirar uma unidade\n2-Retirar todos os produtos do carrinho.\n");
				scanf("%d", &choice);
				switch(choice){
					case 1:
						printf("\nDe qual produto deseja retirar?\n");
						scanf("%d", &choice);
						fflush(stdin);
						printf("\nProduto: %s selecionado\n", productString[choice-1]);
				}
		}
		
}
int main(){
	carrinho();
}