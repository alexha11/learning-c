#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char name[20];
    int number;
    struct node *pNext;
} Node;

typedef struct File File;

void menu() {
    printf("Select one:\n");
    printf("1) Read the text file\n");
    printf("2) Analyze the data\n");
    printf("3) Write text file\n");
    printf("0) Exit\n");
}


Node *readFile(char filename[], Node *head) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return head;
    }

    Node *current = head;
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char *token = strtok(line, ";\n");
        strcpy(current->name, token);
        token = strtok(NULL, ";\n");
        current->number = atoi(token);
        current->pNext = (Node*)malloc(sizeof(Node));
        current = current->pNext;
    }
    current->pNext = NULL;
    fclose(fp);
    return head;
}

double analysis(Node* head) {
    int count = 0;
    int sum = 0;
    Node* current = head;
    while(current->pNext != NULL) {
        sum += current->number;
        count++;
        //printf("%d\n", current-> number);
        current = current->pNext;
    }
    return (double)sum / count;
}

void writeFile(char filename[], double average) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "The average is %.2f", average);
    fclose(fp);
    printf("File written.\n");
}

int main() {
    char name[20];
    bool ok = 1;
    Node *head = (Node*) malloc(sizeof(Node));
    float ans;
    char fileName[100];
    while(ok) {
        menu();
        int choice;
        scanf("%d", &choice);
        printf("You selected %d.\n", choice);
        switch (choice) {
            case 1:
                printf("Please enter a filename:\n");
                scanf("%s", fileName);
                head = readFile(fileName, head);
                break;
            case 2:
                ans = analysis(head);
                printf("Data analysis done. Average is: %.2f\n", ans);
                break;
            case 3:
                printf("Please enter a filename:\n");
                scanf("%s", fileName);
                writeFile(fileName, ans);
                break;
            case 0:
                ok = 0;
                break;
        }
    }
    printf("Exiting...");


}