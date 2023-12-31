#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *file;

    file = fopen(argv[1], "r");

    int n_seeds;
    fscanf(file, "%d", &n_seeds);

    int n_spaces;
    fscanf(file, "%d", &n_spaces);

    int profits[2667] = {0};

    for (int i = 0; i < n_seeds; i++) {
        int seed_size;
        fscanf(file, "%d", &seed_size);

        int seed_value;
        fscanf(file, "%d", &seed_value);

        for (int space = n_spaces; space >= seed_size; --space) {
            profits[space] = (profits[space] >= profits[space - seed_size] + seed_value) ? profits[space] : profits[space-seed_size] + seed_value;
        }
    }

    printf("%d\n", profits[n_spaces]);
    fclose(file);
    return 0;
}