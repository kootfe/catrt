#include <string.h>
#include "stringkft.h"
#include <stdlib.h>

char *getIniTitle(char *input) {
    int temp = 0;
    int len = strlen(input);
    char *ret = (char*)malloc(len + 1);

    if (ret == NULL) { //Well "There is nothing we can do..."
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        if (input[i] != '[' && input[i] != ']' && input[i] != '\n') {
             ret[temp++] = input[i];
        }
    }

    ret[temp] = '\0';

    return ret;
}


/**
 * İnput = "something = 20"
 * f1 = "something=20"
 * f2 = Return it
 */
char *removeSpace(const char *input) {
    int temp = 0;
    int len = strlen(input);
    char *ret = (char*)malloc(len + 1);

    if (ret == NULL) {
        return NULL;
    } 

    for (int i = 0; i < len; i++) {
        if (input[i] != ' ') {
            ret[temp++] = input[i];
        }
    }

    ret[temp] = '\0';

    return ret;
}

char *getIniKey(const char *key, const char *texts) { //
    char *text = removeSpace(texts);
    int len = strlen(text);
    
    char *che = NULL, *ret = NULL;

    int ch = 0, temp = 0;
    for (int i = 0; i < len; i++) {
        if (ch == 0) {
            if (text[i] == '=') {
                if (che) {
                    che[temp] = '\0';
                } else {
                    free(text);
                    return NULL;
                }
                if (strcmp(key, che) == 0) {
                    ch = 1;
                    temp = 0;
                    free(che);
                } else {
                    free(text);
                    free(che);
                    return NULL;
                }
            } else {
                if (!che) {
                    che = (char*)malloc(len);
                    if (!che) {
                        free(text);
                        return NULL;
                    }
                }
                che[temp++] = text[i];
            }
        } else {
            if (!ret) {
                ret = (char*)malloc(len - i + 1);
                if (!ret) {
                    free(text);
                    return NULL;
                }
            }
            ret[temp++] = text[i];
        }
    }
    ret[temp] = '\0';
    free(text);
    return ret;
}

