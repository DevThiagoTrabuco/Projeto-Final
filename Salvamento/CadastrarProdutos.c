#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<locale.h>

#include "flush.c"

#define MAX_CHAR 80

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
			int doisFatoresNome=0;
			int doisFatoresCodigo=0;
	    	
			while(canCopy==0 && canCopy==0){
				canCopy=1;
				fflush(stdin);
				
				if(doisFatoresNome==0){
					printf("Digite o nome do produto a ser cadastrado: ");
					gets(productsStruct[0].productName);
					strupr(productsStruct[0].productName);	
					fflush(stdin);
				}
				if(doisFatoresCodigo==0){
					printf("Digite o codigo do produto a ser cadastrado: ");
					scanf("%d", &productsStruct[0].code);
					sprintf(textCode,"%d",productsStruct[0].code);
				}

				for(column=0;column<aux;column++){					
					if(strcmp(product[column],productsStruct[0].productName)==0 && doisFatoresNome==0){
						printf("\nNome de produto j� cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresCodigo=1;
					}
				}
				for(column=0;column<aux;column++){
					if(strcmp(productCode[column],textCode)==0 || strcmp(productCode[column], codeAux)==0 && doisFatoresCodigo==0){
						printf("Codigo de produto j� cadastrado.\n\n");
						canCopy=0;
						doisFatoresCodigo=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresCodigo=1;
					}
				}	
			}
			printf("\nDigite o preco do produto: ");
			scanf("%f", &productsStruct[0].price);
			printf("\nDigite quantos produtos tem no estoque: ");
			scanf("%d", &productsStruct[0].stock);
			
			strcpy(codeAux,textCode);
			fprintf(file,"\nProduto: \n%s#\n", productsStruct[0].productName);
			fprintf(file, "Preco: \n%.2f#\n", productsStruct[0].price);
			fprintf(file, "Codigo: \n%d#\n", productsStruct[0].code);
			fprintf(file, "Estoque: \n%d#\n", productsStruct[0].stock);
			
			fclose(file);
			
			printf("\nProduto: %s\nCodigo: %d\nPreco: %.2f\n", productsStruct[0].productName, productsStruct[0].code, productsStruct[0].price);
			printf("\nDeseja cadastrar mais algum produto?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de produtos:)\n\n");
	    system("pause");
}
