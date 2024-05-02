#include <stdio.h>
#include <stdlib.h>
void merge(int num, char filename[][100], char* output) {
    FILE* Output = fopen(output, "w");
    if (Output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    for (int i = 0; i < num; i++) {
        FILE* input = fopen(filename[i], "r");
        if (input == NULL) {
            printf("Error opening input file: %s\n", filename[i]);
            continue;
        }
        char ch;
        while ((ch = fgetc(input)) != EOF) {
            fputc(ch, Output);
        }
        fclose(input);
    }
    fclose(Output);
}
int main() {
    int num;
    printf("Enter the number of files: ");
    scanf("%d", &num);

    char filename[num][100]; 
    for (int i = 0; i < num; i++) {
        printf("Enter filename %d: ", i + 1);
        scanf("%s", filename[i]);
    }
    char output[100];
    printf("Enter the output filename: ");
    scanf("%s", output);

    merge(num, filename, output);
    printf("Files merged successfully into %s.\n", output);

    return 0;
}

