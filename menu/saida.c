#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int getOut(){
	int i = 1;
	char op;
	//while (/*/i != 0*/ op != 'S'){
	    printf("Deseja sair?(S/N): ");
	    scanf("%c", &op);
	    fflush(stdin);
		toupper(op);
		
		switch(op){
			case 'S':
		        printf("At� o seu pr�ximo acesso :]\n");
				abort();
			case 'N':
				return 0;
			default:
				printf("Escolha uma op��o v�lida\n");
				break;
		}
	
	    /*if(op == 'S'){
	        printf("At� seu pr�ximo acesso :]\n");
	    	i = 0;
	    } else if(op == 'N'){
	    	printf("Voltando ao menu...");
	        i = 1;
	    } else {
	        printf("Escolha uma op��o v�lida\n");
	        i = -1;
	    }
	    printf("##%d##", i);
	    system("pause");*/
	//}
}