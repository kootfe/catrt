#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/file.c"
#include "./headers/folder.c"

int argcom(char arg[], char argv[]) {
    if (strcmp(arg, argv) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc = 1) {
        FILE *fptr = fopen("../../catrt/indo.txt", "r");
        if (fptr) {
            char info[100];
            while (fgets(info, sizeof(info), fptr)) {
                printf("%s", info);
            }
            fclose(fptr);
        }
    } else if (argc > 1) {
        if (argcom("init", argv[1])) {
            FILE *tempConf, *newConf;
            int ch;
            tempConf = fopen("./templates/config.ini", "r");
            if (tempConf == NULL) {
                printf("Failed to open template");
                return -1;
            }

            newConf = fopen("./config.ini", "w");
            if (newConf == NULL) {
                printf("Failed to copy file.");
                fclose(tempConf);
                return -1;
            }

            while ((ch = fgetc(tempConf)) != EOF) {
                fputc(ch, newConf);
            }

            fclose(newConf);
            fclose(tempConf);
        } else if (argcom("file", argv[1])) {
           readFolder(".");
        }
    }
    return 0;
}
