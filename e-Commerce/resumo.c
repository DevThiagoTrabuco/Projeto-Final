void summary(float totalPrice, int op){
	system("cls");
	printf("Valor do produto: R$%.2f\n", totalPrice);
	if(op == 1)
		printf("\nM�todo de pagamento: � vista\n\n");
	else if(op == 2 || op == 3) 
		printf("\nM�todo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op);
	else if(op == 4)
		printf("\nM�todo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.10));
	else if(op == 5)
		printf("\nM�todo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.20));
	else if(op == 6)
		printf("\nM�todo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.30));
	else if(op == 0)
		printf("\nM�todo de pagamento: PIX\n\n");
	system("pause");
	system("cls");
}