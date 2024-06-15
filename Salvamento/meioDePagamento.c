
int payment(){
	setlocale(LC_ALL, "");
	int op, choice;
	float price;
	char name[40];
	
		printf("Escolha o método de pagamento:\n[1] - Cartão de débito\n[2] - Cartão de crédito\n[3] - PIX\n");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:
				cardData();
				adress();
				summary(price, 9, name);
				break;
			case 2:
				cardData();
				adress();
				choice = installments(price);
				summary(price, choice, name);
				break;
			case 3:
				cpf();
				adress();
				summary(price, 0, name);
				pix();	
				break;
		}
}
