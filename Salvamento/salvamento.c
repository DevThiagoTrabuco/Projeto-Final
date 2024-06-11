#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

#include "flush.c"

#define MAX_CHAR 80

typedef struct{
	int code, stock;
	float price;
	char productName[MAX_CHAR];
}Produtos;

typedef struct{
	int code;
	char employeeName[MAX_CHAR];
}Funcionarios;

int salvamento(int option){
	int choice=0, i=0;
	char txt[30][30], textCode[50], text3[50], funcionario[30][50], codigo[30][50], codeAux[20];
	
	if(option==1){
		Funcionarios funcionariosStruct[1];
		while(choice!=2){
			
	    	FILE * file = fopen("Funcionarios.txt", "a+");
	    	if(file==NULL){
				printf("Erro ao abrir o arquivo\nCriando um arquivo novo :)");
				FILE * file = fopen("Funcionarios.txt", "w");
				system("pause");
				system("cls");
			}
			
			int codigos=0, funcionarios=2, codigoAux=0, funcionarioAux=0;
			char funcionario[30][50], codigo[30][50];
			int coluna = 0, canCopy=0;
			
			while(!feof(file)){
				if(fgets(txt[coluna],500,file)){
				int linha=0;
					do{
						if(txt[coluna][linha]=='#'){
							txt[coluna][linha]='\0';
							break;
						}
						linha++;
					}while(txt[coluna][linha]!='\n');

					if(codigos || funcionarios){
						codigos++;
						funcionarios++;
					}
					if(codigos%5==0){
						strcpy(codigo[codigoAux], txt[coluna]);
						codigoAux++;
					}
					if(funcionarios%5==0){
						strcpy(funcionario[funcionarioAux], txt[coluna]);
						funcionarioAux++;	
					}
					coluna++;
				}
			}
			int aux=coluna;
			int doisFatoresNome=0;
			int doisFatoresCodigo=0;
	    	
			while(canCopy==0){
				canCopy=1;
				
				fflush(stdin);
				if(doisFatoresNome==0){
					printf("Digite o nome do Funcionario a ser cadastrado: ");
					gets(funcionariosStruct[0].employeeName);
					strupr(funcionariosStruct[0].employeeName);
				}
				if(doisFatoresCodigo==0){
					printf("Digite o codigo do funcionario a ser cadastrado: ");
					scanf("%d", &funcionariosStruct[0].code);
					sprintf(textCode,"%d",funcionariosStruct[0].code);
				}
				
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(funcionario[coluna],funcionariosStruct[0].employeeName)==0 && doisFatoresNome==0){
						printf("\nNome de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresNome=1;
					}
				}
				for(coluna=0;coluna<aux;coluna++){
					if(strcmp(codigo[coluna],textCode)==0 || strcmp(codigo[coluna],codeAux)==0 && doisFatoresCodigo==0){
						printf("Codigo de funcionario já cadastrado.\n\n");
						canCopy=0;
						Sleep(2000);
						system("cls");
						break;
					}
					else{
						doisFatoresCodigo=1;
					}
				}	
			}
			strcpy(codeAux, textCode);
			fprintf(file,"\nFuncionario: \n%s#\n", funcionariosStruct[0].employeeName);
			fprintf(file, "Codigo: \n%d#\n", funcionariosStruct[0].code);
			flush();
			fclose(file);
			printf("\nFuncionario: %s\nCodigo: %d\n", funcionariosStruct[0].employeeName, funcionariosStruct[0].code);
			printf("\nDeseja cadastrar mais algum funcionario?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de funcionarios:)\n\n");
	    system("pause");
	}
	if(option==2){
		Produtos produtosStruct[1];
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
					gets(produtosStruct[0].productName);
					strupr(produtosStruct[0].productName);	
					fflush(stdin);
				}
				if(doisFatoresCodigo==0){
					printf("Digite o codigo do produto a ser cadastrado: ");
					scanf("%d", &produtosStruct[0].code);
					sprintf(textCode,"%d",produtosStruct[0].code);
				}

				for(column=0;column<aux;column++){					
					if(strcmp(product[column],produtosStruct[0].productName)==0 && doisFatoresNome==0){
						printf("\nNome de produto já cadastrado.\n\n");
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
						printf("Codigo de produto já cadastrado.\n\n");
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
			scanf("%f", &produtosStruct[0].price);
			printf("\nDigite quantos produtos tem no estoque: ");
			scanf("%d", &produtosStruct[0].stock);
			
			strcpy(codeAux,textCode);
			fprintf(file,"\nProduto: \n%s#\n", produtosStruct[0].productName);
			fprintf(file, "Preco: \n%.2f#\n", produtosStruct[0].price);
			fprintf(file, "Codigo: \n%d#\n", produtosStruct[0].code);
			fprintf(file, "Estoque: \n%d#\n", produtosStruct[0].stock);
			flush();
			fclose(file);
			
			printf("\nProduto: %s\nCodigo: %d\nPreco: %.2f\n", produtosStruct[0].productName, produtosStruct[0].code, produtosStruct[0].price);
			printf("\nDeseja cadastrar mais algum produto?\n[1]Sim\n[2]Nao\n");
			scanf("%d", &choice);
			system("cls");
	    }
	    printf("Obrigado por usar a plataforma de cadastro de produtos:)\n\n");
	    system("pause");
	}
}
int main(){
	int option=2;
	salvamento(option);
}