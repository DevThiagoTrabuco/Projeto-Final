#define MAX_CHAR 50

typedef struct{
	char street[MAX_CHAR];
	char neighborhood[MAX_CHAR];
	char city[MAX_CHAR];
	char uf[2];
	int houseNmbr;
} Adress;

Adress shipment;

void adress(){
	printf("Endere�o:\n");
	scanf(" %s", &shipment.street);
	fflush(stdin);
	printf("N�mero:\n");
	scanf(" %d", &shipment.houseNmbr);
	printf("Bairro:\n");
	scanf(" %s", &shipment.neighborhood);
	fflush(stdin);
	printf("Cidade:\n");
	scanf(" %s", &shipment.city);
	fflush(stdin);
	printf("UF:\n");
	scanf(" %s", &shipment.uf);
	system("pause");
	system("cls");
}