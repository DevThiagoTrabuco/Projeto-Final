void summary(float totalPrice, int op){
	system("cls");
	printf("Valor do produto: R$%.2f\n", totalPrice);
	if(op == 1)
		printf("\nMétodo de pagamento: Á vista\n\n");
	else if(op == 2 || op == 3) 
		printf("\nMétodo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op);
	else if(op == 4)
		printf("\nMétodo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.10));
	else if(op == 5)
		printf("\nMétodo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.20));
	else if(op == 6)
		printf("\nMétodo de pagamento: %dX de R$%.2f\n\n", op, totalPrice / op + (totalPrice*0.30));
	else if(op == 0)
		printf("\nMétodo de pagamento: PIX\n\n");
	system("pause");
	system("cls");
}