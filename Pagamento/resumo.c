void summary(float price, int op, char nomeProduto[]){
	printf("Nome do produto: %s\nValor do produto: %.2f\n", nomeProduto, price);
	if(op == 1 || op == 2 || op == 3) 
		printf("M�todo de pagamento: %dX de R$%.2f\n\n", op, price / op);
	else if(op == 4)
		printf("M�todo de pagamento: %dX de R$%.2f\n\n", op, price / op + (price*0.08));
	else if(op == 5)
		printf("M�todo de pagamento: %dX de R$%.2f\n\n", op, price / op + (price*0.15));
	else if(op == 6)
		printf("M�todo de pagamento: %dX de R$%.2f\n\n", op, price / op + (price*0.21));
	else if(op == 0)
		printf("M�todo de pagamento: PIX\n\n");
	else if(op == 9)
		printf("M�todo de pagamento: � vista\n\n");
	system("pause");
	system("cls");
}