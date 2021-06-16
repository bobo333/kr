#include <stdio.h>
#include <string.h>

int MAXLINESIZE = 500;

int main(int argc, char **argv) {
    // if not 2 args, error

    if (argc != 3) {
        fprintf(stderr, "%s: must include 2 file names as arguments\n", argv[0]);
    }

    char *file1 = argv[1];
    char *file2 = argv[2];

    FILE *fp1 = fopen(file1, "r");
    FILE *fp2 = fopen(file2, "r");

    char file1line[MAXLINESIZE];
    char file2line[MAXLINESIZE];

    int diff = 0;

    while(fgets(file1line, MAXLINESIZE, fp1) != NULL && fgets(file2line, MAXLINESIZE, fp2) != NULL) {
        if (strcmp(file1line, file2line) != 0) {
            fprintf(stdout, "%s%s", file1line, file2line);
            diff = 1;
            break;
        }
    }

    if (diff == 0) {

        printf("diffing\n");

        printf("file1: %s\n", file1line);
        printf("file2: %s\n", file2line);

        if (file1line == NULL) {
            fprintf(stdout, "%s", file2line);
        }

        if (file2line == NULL) {
            fprintf(stdout, "%s", file1line);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
