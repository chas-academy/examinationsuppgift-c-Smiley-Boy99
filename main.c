#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STUDENTS 5
#define TESTS 13

// Funktion som fixar namnet: stor begynnelsebokstav, resten små
void formatName(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
    }
}

int main() {
    char names[STUDENTS][20];
    int scores[STUDENTS][TESTS];
    double averages[STUDENTS];

    // Läs in data
    for (int i = 0; i < STUDENTS; i++) {
        scanf("%s", names[i]);
        for (int j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    // Räkna medelvärden
    for (int i = 0; i < STUDENTS; i++) {
        int sum = 0;
        for (int j = 0; j < TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / (double)TESTS;
    }

    // Hitta högsta medelvärdet
    int bestIndex = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[bestIndex]) {
            bestIndex = i;
        }
    }

    // Räkna gruppsnitt
    double total = 0;
    for (int i = 0; i < STUDENTS; i++) {
        total += averages[i];
    }
    double groupAverage = total / STUDENTS;

    // Skriv ut: först bästa eleven
    formatName(names[bestIndex]);
    printf("%s\n", names[bestIndex]);

    // Skriv ut elever under gruppsnittet
    for (int i = 0; i < STUDENTS; i++) {
        if (averages[i] < groupAverage) {
            formatName(names[i]);
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
