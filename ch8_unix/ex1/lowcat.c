#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int BUFSIZE=500;

int main(int argc, char** argv) {
    int i = 1;
    while(i < argc) {
        char* filename = argv[i++];
        char* c[BUFSIZE];
        int n_read;
        int n_write;

        int f = open(filename, O_RDONLY);
        if (f < 0) {
            printf("error opening: %s\n", filename);
            return 1;
        }

        while ((n_read = read(f, &c, BUFSIZE)) > 0) {
            n_write = write(1, &c, n_read);
            if (n_write < 0) {
                printf("error writing to stdout\n");
                return 1;
            }
        }
        if (n_read < 0) {
            printf("error reading %s\n", filename);
            return 1;
        }

        close(f);
    }

    return 0;
}



