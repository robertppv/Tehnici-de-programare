void pb1()
// {
//     FILE *filein, *fileout;
//     elem *lista = NULL;
//     elem *p = NULL;
//     int k, n;
//     if ((filein = fopen("date.in", "r")) == NULL)
//     {
//         perror("mem err");
//         exit(EXIT_FAILURE);
//     }

//     if ((fileout = fopen("date.out", "w")) == NULL)
//     {
//         perror("mem err");
//         exit(EXIT_FAILURE);
//     }

//     fscanf(filein, "%d", &k);

//     while (fscanf(filein, "%d", &n) == 1)
//     {
//         lista = adsf(lista, n);
//     }

//     lista = permutari(lista, k);

//     for (p = lista; p != NULL; p = p->urm)
//     {
//         fprintf(fileout, "%d ", p->info);
//     }

//     if (fclose(filein) != 0)
//     {
//         perror("mem err");
//         exit(EXIT_FAILURE);
//     }

//     if (fclose(fileout) != 0)
//     {
//         perror("mem err");
//         exit(EXIT_FAILURE);
//     }
// }
