int installments(float totalPrice){
	int choice;
	printf("\n\n||Escolha as parcelas:\n||[1] - 1X de R$%.2f\n||[2] - 2X de R$%.2f sem juros\n||[3] - 3X de R$%.2f sem juros", totalPrice, totalPrice / 2, totalPrice / 3);
	printf("\n||[4] - 4X de R$%.2f\n||[5] - 5X de R$%.2f\n||[6] - 6X de R$%.2f\n", totalPrice / 4 + (totalPrice*0.1), totalPrice / 5 + (totalPrice*0.20), totalPrice / 6 + (totalPrice*0.30));
	scanf("%d", &choice);
	
	return choice;
}

