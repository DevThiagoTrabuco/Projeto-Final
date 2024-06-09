#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flush.c"
int comprar(int option){
	int productCodes=2, products=6, produtctPrices=4, productStocks=0, productCodeAux=0, productAux=0, productPriceAux=0, productStockAux=0;
	char txt[200][50], input[50], productString[30][50], productCodeString[30][50], productPriceString[30][50], productStockString[30][50];	
	int column = 0, canCopy=0;
	int number = 0;
	
	if(option==2){
		FILE * file = fopen("Produtos.txt", "r");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");	
				
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
					strcpy(productString[productAux], txt[column]);
					number++;
					printf("%d - \tProduto: %s\n", number,productString[productAux]);					
					productAux++;
					
				}
				if(produtctPrices%9==0){
					strcpy(productPriceString[productPriceAux], txt[column]);
					printf("\tPreco: %s\n", productPriceString[productPriceAux]);
					productPriceAux++;
				}
				if(productCodes%9==0){
					strcpy(productCodeString[productCodeAux], txt[column]);
					printf("\tCodigo: %s\n\n", productCodeString[productCodeAux]);
					productCodeAux++;
				}
				if(productStocks%9==0){
					strcpy(productStockString[productStockAux], txt[column]);
					productStockAux++;
				}
				column++;
			}	
		}
		
		char productCode, productStock[30];
		float productPriceFloat;
		
		int productsCodeAux, productStockAux;
		float productsPriceFloatAux;
		
		int input;
		int inputAux;
		
		while(input!=75){
			printf("\nQual produto deseja adicionar no carrinho?\n");
			scanf("%d", &input);
			inputAux=input-1;
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
			}
			else{
				productStockAux=atoi(productStockString[inputAux])-productStockAux;
				sprintf(productStock,"%d", productStockAux);
				strcpy(productStockString[inputAux], productStock);
				printf("\nEstoque: %s\n", productStock);
			}
		}
		fclose(file);
		FILE * file2 = fopen("Produtoss.txt", "w");
		if(file==NULL)
			printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");	
		int aux=0;
		while(aux<number){
			fprintf(file2,"\nProduto: \n%s#\n", productString[aux]);
			fprintf(file2, "Preco: \n%s#\n", productPriceString[aux]);
			fprintf(file2, "Codigo: \n%s#\n", productCodeString[aux]);
			fprintf(file2, "Estoque: \n%s#\n", productStockString[aux]);
			aux++;
		}
		
	}
}
int main(){
	int option=2;
	comprar(option);
}