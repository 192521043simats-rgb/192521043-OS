#include <stdio.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int n, pos;

    fp = fopen("emp.dat", "wb+");
    if(fp == NULL) return 1;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter ID, name, salary: ");
        scanf("%d%19s%f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("Enter record number to read: ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= n) {
        fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);
        fread(&e, sizeof(e), 1, fp);
        printf("%d %s %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);
    return 0;
}