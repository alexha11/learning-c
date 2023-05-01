#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

int main() {
    FILE *fp;
    Person people[10];
    int numPersons;
    printf("Data read from file:\n");
    fp = fopen("people.bin", "rb");

    numPersons = fread(people, sizeof(Person), 10, fp);

    fclose(fp);

    for (int i = 0; i < numPersons; i++) {
        printf("Person %d:\n", i+1);
        printf("\tName: %s\n", people[i].name);
        printf("\tAge: %d\n", people[i].age);
        printf("\tHeight: %.1f\n", people[i].height);
    }

    return 0;
}
