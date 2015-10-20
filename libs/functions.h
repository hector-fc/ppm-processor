char header[3];
int w, h, max_color;

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

void menu() {
    printf("-------------------- MENU --------------------\n");
    printf("'inf' \t mostrar informacoes da imagem.\n");
    printf("'thr' \t binarizar imagem usando thresholding.\n");
    printf("'blu' \t executar blurring.\n");
    printf("'sha' \t executar sharpening.\n");
    printf("'rot' \t rotacionar imagem.\n");
    printf("'amp' \t ampliar imagem.\n");
    printf("'red' \t reduzir imagem.\n\n");
    printf("'fim' \t finalizar programa.\n");
    printf("----------------------------------------------\n\n");
}

void img_info(Pixel img[w][h]) {
    int i, j;
    printf("Dados da Imagem lida:\n");
    printf("Tipo: %s\n", header);
    printf("Tamanho: %ix%i\n", w, h);
    printf("Cor maxima: %i\n", max_color);
    printf("Cores de cada pixel:\n");
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            printf("%i %i %i\n", img[i][j].r, img[i][j].g, img[i][j].b);
}

void choice(char op[3], Pixel img[w][h]) {
    op[0] = tolower(op[0]),
    op[1] = tolower(op[1]),
    op[2] = tolower(op[2]);

    system("clear");

    if (strcmp(op, "fim") == 0)
        return;
    else if (strcmp(op, "inf") == 0) {
        printf("Exibindo informacoes da imagem...\n");
        img_info(img);
    }else if (strcmp(op, "thr") == 0)
        printf("Executando thresholding...\n");
    else if (strcmp(op, "blu") == 0)
        printf("Executando blurring...\n");
    else if (strcmp(op, "sha") == 0)
        printf("Executando sharpening...\n");
    else if (strcmp(op, "rot") == 0) {
        int ang;
        printf("Digite o angulo de rotacao: ");
        scanf("%i", &ang);
        printf("Rotacionando Imagem...\n");
    }else if (strcmp(op, "amp") == 0) {
        int zoom;
        printf("Digite o zoom: ");
        scanf("%i", &zoom);
        printf("Ampliando Imagem...\n");
    }else if (strcmp(op, "red") == 0) {
        int zoom;
        printf("Digite o zoom: ");
        scanf("%i", &zoom);
        printf("Reduzindo Imagem...\n");
    }else {
        printf("A opcao selecionada nao esta disponivel.\nTente novamente: ");
        scanf("%s", op);
        choice(op, img);
    }
}

int read_ppm(char file_name[]) {
    int i, j; //Iteradores

    FILE *img;

    img = fopen(file_name, "r");
    if (img == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fscanf(img, "%s", header);
    fscanf(img, "%i %i", &w, &h);
    fscanf(img, "%i", &max_color);

    Pixel image[w][h];

    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            fscanf(img, "%i %i %i", &image[i][j].r, &image[i][j].g, &image[i][j].b);

    fclose(img);

    menu();
    char op[3];
    printf("O que voce deseja fazer? ");
    scanf("%s", op);
    choice(op, image);

    return 1;
}
