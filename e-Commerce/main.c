#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<ctype.h>
#include<windows.h>

#define MAX_CHAR 80

#include "CadastrarAdm.c"
#include "CadastrarClientes.c"
#include "CadastrarFuncionarios.c"
#include "CadastrarProdutos.c"
#include "Carrinho.c"
#include "Compras.c"
#include "cpf.c"
#include "dadosDoCartao.c"
#include "EditarFuncionario.c"
#include "EditarProduto.c"
#include "endereço.c"
#include "flush.c"
#include "LeituraAdm.c"
#include "LeituraFuncionario.c"
#include "LoginClientes.c"
#include "meioDePagamento.c"
#include "menu.c"
#include "parcelas.c"
#include "qrCode.c"
#include "resumo.c"
#include "retornar.c"
#include "saida.c"
#include "AreaRestrita.c"
#include "MenuAdm.c"
#include "MenuFuncionario.c"

int main(){
	menu();
}