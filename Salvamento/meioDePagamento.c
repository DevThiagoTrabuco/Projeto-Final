
int payment(float totalPrice){
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
				summary(totalPrice, op);
				break;
			case 2:
				cardData();
				adress();
				summary(totalPrice, op);
				break;
			case 3:
				cpf();
				adress();
				pix();
				summary(totalPrice, op);
				break;
		}
}
