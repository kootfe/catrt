#include "file.h"
#include <stdio.h>
#include <stdlib.h>

int copyFile(const char *filePath, const char *targetPath) {
    FILE *oldFile, *newFile;
    int ch;

    oldFile = fopen(filePath, "r");
    if (oldFile == NULL) {
        printf("Failed to open `Old File`!");
        return -1;
    }

    newFile = fopen(targetPath, "w");
    if (newFile == NULL) {
        printf("Faield to create `new file`!");
        fclose(oldFile);
        return -1;
    }

    while((ch = fgetc(oldFile)) != EOF) {
        fputc(ch, newFile);
    }

    fclose(oldFile);
    fclose(newFile);
    return 0;
}

int readFile(const char *path) {
    FILE *fptr = fopen(path, "r");
    if (fptr) {
        char *yep = (char*)malloc(sizeof(char) * 100);
        while (fgets(yep, sizeof(yep), fptr)) {
            printf("%s", yep);
        }
        free(yep);
        fclose(fptr);
    }
    return 0;
}
