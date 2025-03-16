#include "iniworks.h"
#include "stringkft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printIni(const char *title, const char *key) {
    FILE *theIni = fopen("./catrt/config/config.ini", "r");
    char temp[100];
    int check = 0;
    while (fgets(temp, 100, theIni)) {
        int len = strlen(temp);
        if (check == 0) {
            if (temp[0] == '[') {
                char *tampon = getIniTitle(temp);
                printf("Tampon: %s", tampon);
                if (strcmp(tampon, title) == 0) {
                    printf("%s", tampon);
                    check = 1;
                }
                free(tampon);
            }
        } else {
            if (temp[0] == '[') {
                fclose(theIni);
                return;
            } else {
                char *val = getIniKey("name", temp);
                if (val != NULL) {
                    printf("Value: %s", val);
                    free(val);
                    fclose(theIni);
                    return;
                }
                free(val);
                
            }
        }
    }
    fclose(theIni);
}

char *getIniValue(const char *title, const char *key) {
    FILE *theIni = fopen("./catrt/config/config.ini", "r");
    char temp[100];
    int check = 0;
    while (fgets(temp, 100, theIni)) {
        int len = strlen(temp);
        if (check == 0) {
            if (temp[0] == '[') {
                char *tampon = getIniTitle(temp);
                if (strcmp(tampon, title) == 0) {
                    check = 1;
                }
                free(tampon);
            }
        } else if (check == 1) {
            char *val = getIniKey(key, temp);
            if (val == NULL) {
                return val;;
            }
            free(val);
        }
    }
    fclose(theIni);
}
