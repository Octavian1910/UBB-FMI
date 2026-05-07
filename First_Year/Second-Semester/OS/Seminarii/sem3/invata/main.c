#include <stdio.h>
#include <string.h>

void intrebare1() {
    char raspuns[100];

    printf("\n[Q1] Completeaza:\n");
    printf("// ruleaza ls -l\n");
    printf("________(\"/bin/ls\", \"ls\", \"-l\", NULL);\n");
    printf("Raspuns: ");

    scanf("%s", raspuns);

    if (strcmp(raspuns, "execl") == 0) {
        printf("✔ Corect!\n");
    } else {
        printf("❌ Gresit! Raspuns corect: execl\n");
    }
}

void intrebare2() {
    char raspuns[100];

    printf("\n[Q2] Ce functie foloseste PATH?\n");
    printf("Raspuns: ");

    scanf("%s", raspuns);

    if (strcmp(raspuns, "execvp") == 0) {
        printf("✔ Corect!\n");
    } else {
        printf("❌ Gresit! Raspuns corect: execvp\n");
    }
}

void intrebare3() {
    char raspuns[100];

    printf("\n[Q3] Completeaza:\n");
    printf("char *args[] = {\"ls\", \"-l\", NULL};\n");
    printf("________(\"ls\", args);\n");
    printf("Raspuns: ");

    scanf("%s", raspuns);

    if (strcmp(raspuns, "execvp") == 0) {
        printf("✔ Corect!\n");
    } else {
        printf("❌ Gresit! Raspuns corect: execvp\n");
    }
}

void intrebare4() {
    char raspuns[100];

    printf("\n[Q4] Ce reprezinta argv[0]?\n");
    printf("Raspuns: ");

    scanf("%s", raspuns);

    if (strcmp(raspuns, "numele_programului") == 0) {
        printf("✔ Corect!\n");
    } else {
        printf("❌ Gresit! Raspuns: numele_programului\n");
    }
}

void intrebare5() {
    char raspuns[100];

    printf("\n[Q5] Completeaza:\n");
    printf("execle(\"/usr/bin/env\", \"/usr/bin/env\", NULL, ______);\n");
    printf("Raspuns: ");

    scanf("%s", raspuns);

    if (strcmp(raspuns, "envp") == 0) {
        printf("✔ Corect!\n");
    } else {
        printf("❌ Gresit! Raspuns: envp\n");
    }
}

int main() {
    printf("=== EXEC QUIZ TRAINER ===\n");

    intrebare1();
    intrebare2();
    intrebare3();
    intrebare4();
    intrebare5();

    printf("\nGata! Mai ruleaza o data ca sa repeti 🔁\n");
    return 0;
}
