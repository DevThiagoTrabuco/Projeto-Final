
typedef struct{
	char street[MAX_CHAR];
	char neighborhood[MAX_CHAR];
	char city[MAX_CHAR];
	char uf[2];
	int houseNmbr;
} Adresses;

Adresses shipment;

void adress(){
	system("cls");
	printf("||Endereço:\n");
	scanf(" %s", &shipment.street);
	fflush(stdin);
	printf("||Número:\n");
	scanf(" %d", &shipment.houseNmbr);
	printf("||Bairro:\n");
	scanf(" %s", &shipment.neighborhood);
	fflush(stdin);
	printf("||Cidade:\n");
	scanf(" %s", &shipment.city);
	fflush(stdin);
	printf("||UF:\n");
	scanf(" %s", &shipment.uf);
	system("pause");
	system("cls");
}