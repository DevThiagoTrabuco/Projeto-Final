void print(char texto[50]){
    for (int i = 0; texto[i] != '\0'; i++) {
        putchar(texto[i]);
        Sleep(1);
    }
}

void printLoad(char texto[50]){
    for (int i = 0; texto[i] != '\0'; i++) {
        putchar(texto[i]);
        Sleep(100);
    }
}

void inicio() {
    print("##.....##....###....##.......##.....##....###....########..########\n");
	print("##.....##...##.##...##.......###...###...##.##...##.....##....##...\n");
	print("##.....##..##...##..##.......####.####..##...##..##.....##....##...\n");
	print("##.....##.##.....##.##.......##.###.##.##.....##.########.....##...\n");
	print(".##...##..#########.##.......##.....##.#########.##...##......##...\n");
	print("..##.##...##.....##.##.......##.....##.##.....##.##....##.....##...\n");
	print("...###....##.....##.########.##.....##.##.....##.##.....##....##...\n\n");
	Sleep(500);
	printLoad("\t\t Inicializando sistema . . .");
}

