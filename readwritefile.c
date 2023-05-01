#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void displayMenu() {
    printf("Select from the options below\n");
    printf("1) Add a new name \n");
    printf("2) Print names\n");
    printf("0) Exit \n");
}

void writeFile(char* fileName) {
    char name[50];
    printf("Enter a name to add:\n");
    scanf(" %s", name);
    FILE* fp = fopen(fileName, "a");
    fprintf(fp, "%s\n", name);
    fclose(fp);
}

void readFile(char* fileName) {
    char name[50];
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Failed to open file, terminating\n");
        exit(0);
    }
    while(fgets(name, 50, fp) != NULL) {
        printf("%s", name);
    }
    fclose(fp);
    printf("File read and printed.\n");
}

int main() {
    char fileName[50];
    bool isContinue = true;
    printf("Enter the name of the file to be processed:\n");
    scanf("%s", fileName);
    while(isContinue) {
        displayMenu();
        char selection;
        printf("Enter your selection:\n");
        scanf(" %c", &selection);
        switch(selection) {
            case '1':
                writeFile(fileName);
                break;
            case '2':
                readFile(fileName);
                break;
            case '0':
                isContinue = false;
                break;
        }
    }
}