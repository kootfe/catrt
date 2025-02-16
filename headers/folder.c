#include "folder.h"
#include <direct.h>
#include <windows.h>
#include <stdio.h>

void createFolder(const char *foldername) {
    if (_mkdir(foldername) == 0) {
        printf("Created '%s' folder sucsesfully \n", foldername);
    } else {
        printf("Failed to create folder. '%s' \n", foldername);
    }
}

void readFolderRecursive(const char *foldername, int depth) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    char searchPath[256];
    snprintf(searchPath, sizeof(searchPath), "%s\\*", foldername);

    hFind = FindFirstFile(searchPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Failed to open folder '%s'\n", foldername);
        return;
    }

    do {
        // Skip the current folder "." and parent folder ".."
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0) {
            continue;
        }

        // Indent based on the depth of the folder
        for (int i = 0; i < depth; i++) {
            printf("    ");
        }

        printf("%s\n", findFileData.cFileName);

        // If the entry is a directory, call the function recursively
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            char subfolderPath[256];
            snprintf(subfolderPath, sizeof(subfolderPath), "%s\\%s", foldername, findFileData.cFileName);
            readFolderRecursive(subfolderPath, depth + 1);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void readFolder(const char *foldername) {
    printf("Contents of '%s':\n", foldername);
    readFolderRecursive(foldername, 0);
}
