#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flush.c"
int comprar(int option){
	int productCodes=0, products=4, produtctPrices=2, productCodeAux=0, productAux=0, productPriceAux=0;
	char txt[30][30], product[30][50], productCode[30][50], productPrice[30][50];
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
				}
				if(products%7==0){
					strcpy(product[productAux], txt[column]);
					number++;
					printf("%d - Produto: %s\n", number,product[productAux]);					
					productAux++;
					
				}
				if(produtctPrices%7==0){
					strcpy(productPrice[productPriceAux], txt[column]);
					printf("Preco: %s\n", productPrice[productPriceAux]);					
					productPriceAux++;
				}
				if(productCodes%7==0){
					strcpy(productCode[productCodeAux], txt[column]);
					printf("Codigo: %s\n\n", productCode[productCodeAux]);
					productCodeAux++;
				}
				column++;
			}	
		}
		int input;
		while(1){
			printf("\nQual produto deseja adicionar no carrinho?\n");
			scanf("%d", &input);
		}
		
		
	}
}
int main(){
	int option=2;
	comprar(option);
}