#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>

#define MAX_PATH 1024

void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));

int main(int argc, char** argv) {
    if (argc == 1) {
        fsize(".");
    } else {
        while (--argc > 0) {
            fsize(*++argv);
        }
    }
    return 0;
}

void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk(name, fsize);
    }
    printf("%8ld %s\n", stbuf.st_size, name);

    printf("%s\n", name);
    printf("\tsize: %8ld\n", stbuf.st_size);
    printf("\tst_blksize: %d\n", stbuf.st_blksize);
    printf("\tblocks: %ld\n", stbuf.st_blocks);
    printf("\tdevice: %ld\n", stbuf.st_dev);
    printf("\tserial number: %ld\n", stbuf.st_ino);
    printf("\tmode: %d\n", stbuf.st_mode);
    printf("\tuid: %d\n", stbuf.st_uid);
    printf("\tgid: %d\n", stbuf.st_gid);


    // unsigned long   st_dev;     /* Device.  */
    // unsigned long   st_ino;     /* File serial number.  */
    // unsigned int    st_mode;    /* File mode.  */
    // unsigned int    st_nlink;   /* Link count.  */
    // unsigned int    st_uid;     /* User ID of the file's owner.  */
    // unsigned int    st_gid;     /* Group ID of the file's group. */
    // unsigned long   st_rdev;    /* Device number, if device.  */
    // unsigned long   __pad1;
    // long        st_size;    /* Size of file, in bytes.  */
    // int     st_blksize; /* Optimal block size for I/O.  */
    // int     __pad2;
    // long        st_blocks;  /* Number 512-byte blocks allocated. */
    // long        st_atime;   /* Time of last access.  */
    // unsigned long   st_atime_nsec;
    // long        st_mtime;   /* Time of last modification.  */
    // unsigned long   st_mtime_nsec;
    // long        st_ctime;   /* Time of last status change.  */
    // unsigned long   st_ctime_nsec;
    // unsigned int    __unused4;
    // unsigned int    __unused5;


}

void dirwalk(char *dir, void (*fcn)(char*)) {
    char name [MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
            fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
        } else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }
    closedir(dfd);
}
