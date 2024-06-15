#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<locale.h>

#include "flush.c"
int editarFuncionario(){
	
	while(1){
	FILE * file = fopen("Produtos.txt", "r");
	if(file==NULL)
		printf("Erro ao abrir o arquivo\nDica: crie um arquivo por meio do cadastro.");
	int productCodes=2, products=6, produtctPrices=4, productStocks=0, productCodeAux=0, productAux=0, productPriceAux=0, productStockAux=0;
	char txt[200], productString[30][50], productCodeString[30][50], productPriceString[30][50], productStockString[30][50];	
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
	int replaceCode;

	char replaceCodeAux[50];
	char replaceName[50];
	
		system("cls");
		printf("\n\nO que deseja editar?\n1-Nome do produto.\n2-Codigo do produto.\n3-Preço do produto\n4-Estoque do produto\n5-Excluir produto.\n6-Voltar ao menu.\n");
		scanf("%d", &input);
		fflush(stdin);
		switch(input){
			case 1:
				system("cls");
				printf("\nEdição de nome\n\nDe qual produto deseja editar o nome?");
				for(int i=0;i<aux;i++){
					printf("\n\n%d- Produto: %s", i+1,productString[i]);
				}
				printf("\n\n");
				scanf("%d", &input);
				
				if(input>aux){
					printf("\nOpção invalida.\n");
					break;
				}
				
				fflush(stdin);
				inputAux=input;
				system("cls");
				printf("\nO produto %s é o selecionado\n", productString[inputAux-1]);
				strcpy(productString[inputAux-1], "");
				
				int twoFactorName=0;
				
				while(canCopy==0){
					if(twoFactorName==0){
						printf("\nDigite o novo nome.\n");
						gets(replaceName);
						strupr(replaceName);
					}
					for(int i=0;i<=aux;i++){
						if(strcmp(replaceName, productString[i])==0 && twoFactorName==0){
							printf("\nNome já está sendo usado, escolha outro.\n");
							system("pause");
							break;
						}
						else{
							
							printf("\nNome alterado com sucesso.\n");
							strcpy(productString[inputAux-1], replaceName);
							system("pause");
							
							file = fopen("Produtos.txt", "w");
							for(int i=0;i<aux;i++){
								fprintf(file,"\nProduto: \n%s#\n", productString[i]);
								fprintf(file, "Preco: \n%.2f#\n", productPriceString[i]);
								fprintf(file, "Codigo: \n%d#\n", productCodeString[i]);
								fprintf(file, "Estoque: \n%d#\n", productStockString[i]);
							}
							fclose(file);
							
							canCopy=1;
							break;
						}
					}
				}
				break;
			/*case 2:
				system("cls");
				printf("\nEdição de codigo\n\nDe qual funcionario deseja editar o codigo?");
				for(int i=0;i<aux;i++){
					printf("\n\n%d- Funcionario: %s", i+1,employee[i]);
					printf("\nCodigo: %s", code[i]);
				}
				printf("\n\n");
				scanf("%d", &input);
				
				if(input>aux){
					printf("\nOpção invalida.\n");
					break;
				}
				
				fflush(stdin);
				inputAux=input;
				printf("\nO funcionario %s é o selecionado. Para qual codigo desejar mudar?\n", employee[inputAux-1]);
				strcpy(code[inputAux-1], "");
				scanf("%d", &replaceCode);
				sprintf(replaceCodeAux, "%d", replaceCode);
				fflush(stdin);
				
				while(canCopy==0){
					
					for(int i=0;i<aux;i++){
						if(strcmp(replaceCodeAux, code[i])==0 && canCopyCode==0){
						printf("\nCodigo invalido, escolha outro.\n");
						scanf("%d", &replaceCode);
						sprintf(replaceCodeAux, "%d", replaceCode);
						fflush(stdin);
						}
						else{
							printf("\nCodigo alterado com sucesso.\n");
							strcpy(code[inputAux-1], replaceCodeAux);
							system("pause");
							
							file = fopen("Funcionarios.txt", "w");
							for(int i=0;i<aux;i++){
								fprintf(file,"\nFuncionario: \n%s#\n", employee[i]);
								fprintf(file, "Codigo: \n%s#\n", code[i]);
							}
							fclose(file);
			
							canCopy=1;
							break;
						}
					}

				break;
			case 3:
				system("cls");
				printf("\nRemoção de funcionario.\n\nLista de funcionarios:");
				for(int i=0;i<aux;i++){
					printf("\n\n%d- Funcionario: %s", i+1,employee[i]);
					printf("\nCodigo: %s", code[i]);
				}
				printf("\n\nQual funcionario deseja remover?\n");
				scanf("%d", &input);
				
				if(input>aux){
					printf("\nOpção invalida.\n");
					break;
				}
				
				fflush(stdin);
				file = fopen("Funcionarios.txt", "w");
				strcpy(employee[input-1], "");
				strcpy(code[input-1], "");
				for(int i=0;i<aux;i++){
					if(i==input-1){
						continue;
					}
					fprintf(file,"\nFuncionario: \n%s#\n", employee[i]);
					fprintf(file, "Codigo: \n%s#\n", code[i]);
					
				}
				fclose(file);
			case 4:
				system("cls");
				printf("Voltando ao menu\n");
				Sleep(1000);
				break;*/
		}
	}
}
int main(){
	editarFuncionario();
}