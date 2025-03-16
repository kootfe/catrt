#include <string.h>
#include <stdio.h>
#include "./headers/file.h"
#include "./headers/folder.h"
#include "./headers/iniworks.h"

int argcom(char arg[], char argv[]) {
    if (strcmp(arg, argv) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        readFile("../info.txt");
    } else if (argc >= 2) {
        if (argcom("init", argv[1])) {
            createFolder("catrt");
            createFolder("catrt/config");
            copyFile("../templates/config.ini", "./catrt/config/config.ini"); //BTW this is an `int` fucntion so it returns 0 :3;
        } else if (argcom("file", argv[1])) {
           readFolder(".");
        } else if (argcom("test", argv[1])) {
            printIni("project", "a");
        } else if (argcom("test2", argv[1])) {
            return -1; //Ill make "test2 to fail" easter egg in my all codes from now on :3
        } else if (argcom("test1", argv[1])) {
            char *val = getIniValue("project", "name");
            printf("Value: %s", val);
        }
    }
    return 0;
}
