void cardData(){
	int crdNum, crdMM, crdYY, cvc;
	char crdOwner[50];
		printf("N�mero do cart�o:\n");
		scanf(" %d", &crdNum);
		printf("Titular do cart�o:\n");
		scanf(" %s", &crdOwner);
		fflush(stdin);
		printf("Data de validade(MM/AA):\n");
		scanf(" %d / %d", &crdMM, &crdYY);
		fflush(stdin);
		printf("C�digo de Verifica��o do Cart�o:\n");
		scanf(" %d", cvc);
}