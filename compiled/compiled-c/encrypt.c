#include <stdio.h>
#include <stdlib.h>

void encrypt(const char* input, const char* output) {
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (!fin || !fout) {
        printf("File error\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch + 1, fout); // Simple Caesar cipher
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: encrypt <input> <output>\n");
        return 1;
    }

    encrypt(argv[1], argv[2]);
    return 0;
}