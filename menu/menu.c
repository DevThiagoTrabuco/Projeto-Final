#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<ctype.h>
#include<windows.h>

#include"saida.c"
#include"cadastroCliente.c"
#include"retornar.c"

void menu(){
	char op, op2;
	int exit;
	setlocale(LC_ALL, "");
		
		while(exit != 1){
			printf("\t\t##################\n\t\t#\t\t #\n\t\t#      MENU      #\n\t\t#\t\t #\n\t\t##################\n\nBem vindo(a) à loja [PLACEHOLDER]!!");
			printf("\n\n[1] - Login / Cadastro\n[2] - Visualizar catálogo\n[3] - Carrinho\n[4] - Área restrita\n[5] - Fechar aplicação\n\nPor favor, escolha uma opção: ");
			scanf("%c", &op);
			fflush(stdin);
			
			switch(op){
				case '1'://login/cadastro de cliente
					//clientList();
					getBack();
					break;
				case '2'://lista de produtos
					getBack();
					break;
				case '3'://carrinho
					getBack();
					break;
				case '4'://área restrita
					getBack();
					break;
				case '5'://sair da aplicação
					exit = getOut();
                	break;
				default:
					printf("Opção inválida.\n");
					Sleep(500);
					break;
			}
			system("cls");
		} 
}
int main(){
	menu();
}