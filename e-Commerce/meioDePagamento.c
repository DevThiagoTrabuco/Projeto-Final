void cardData();
int installments(float totalPrice);
void pix();
void summary(float totalPrice, int op);

int payment(float totalPrice){
	setlocale(LC_ALL, "");
	int op, choice;
	
		printf("\n||Escolha o m�todo de pagamento:\n||[1] - Cart�o de d�bito\n||[2] - Cart�o de cr�dito\n||[3] - PIX\n");
		scanf("%d", &op);
		fflush(stdin);
		
		switch(op){
			case 1:
				cardData();
				adress();
				summary(totalPrice, 1);
				break;
			case 2:
				cardData();
				choice = installments(totalPrice);
				adress();
				summary(totalPrice, choice);
				break;
			case 3:
				cpf();
				adress();
				pix();
				summary(totalPrice, 0);
				break;
			default:
				printf("||Op��o inv�lida.\n");
				Sleep(1000);
				break;
		}
}
