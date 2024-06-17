void cardData(){
	int crdNum, crdMM, crdYY, cvc;
	char crdOwner[50];
	system("cls");
	printf("\n||Número do cartão:\n");
	scanf(" %d", &crdNum);
	printf("||Titular do cartão:\n");
	scanf(" %s", &crdOwner);
	fflush(stdin);
	printf("||Data de validade(MM/AA):\n");
	scanf(" %d %d", &crdMM, &crdYY);
	fflush(stdin);
	printf("||Código de Verificacao do Cartão:\n");
	scanf(" %d", &cvc);
	system("pause");
}