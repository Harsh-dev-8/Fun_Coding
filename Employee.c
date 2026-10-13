#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    int  id;
    char name[50];
    char dept[30];
    char position[30];
    float salary;
    char doj[15];          /* Date of Joining: DD-MM-YYYY */
};

struct Employee emp[MAX];
int count = 0;

/* read a line of text safely and remove the newline */
void readText(char *s, int size) {
    fgets(s, size, stdin);
    s[strcspn(s, "\n")] = '\0';
}

int readInt(void) {
    char buf[20]; int n = 0;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);
    return n;
}

float readFloat(void) {
    char buf[20]; float f = 0;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%f", &f);
    return f;
}

/* returns index of employee with given id, or -1 */
int findEmployee(int id) {
    int i;
    for (i = 0; i < count; i++)
        if (emp[i].id == id) return i;
    return -1;
}

void createRecord(void) {
    int id;
    if (count >= MAX) { printf("Database is full!\n"); return; }
    printf("Enter Employee ID      : ");
    id = readInt();
    if (findEmployee(id) != -1) { printf("ID already exists. Record not added.\n"); return; }
    emp[count].id = id;
    printf("Enter Employee Name    : "); readText(emp[count].name, 50);
    printf("Enter Department Name  : "); readText(emp[count].dept, 30);
    printf("Enter Position         : "); readText(emp[count].position, 30);
    printf("Enter Salary           : "); emp[count].salary = readFloat();
    printf("Enter Date of Joining (DD-MM-YYYY): "); readText(emp[count].doj, 15);
    count++;
    printf("Record added successfully.\n");
}

void listRecords(void) {
    int i;
    if (count == 0) { printf("No records found.\n"); return; }
    printf("\n%-6s %-18s %-14s %-16s %-10s %-12s\n",
           "ID", "Name", "Department", "Position", "Salary", "Joining Date");
    printf("-----------------------------------------------------------------------------\n");
    for (i = 0; i < count; i++)
        printf("%-6d %-18s %-14s %-16s %-10.2f %-12s\n",
               emp[i].id, emp[i].name, emp[i].dept,
               emp[i].position, emp[i].salary, emp[i].doj);
}

void modifyRecord(void) {
    int id, pos;
    printf("Enter Employee ID to modify: ");
    id = readInt();
    pos = findEmployee(id);
    if (pos == -1) { printf("Employee not found.\n"); return; }
    printf("Enter New Name          : "); readText(emp[pos].name, 50);
    printf("Enter New Department    : "); readText(emp[pos].dept, 30);
    printf("Enter New Position      : "); readText(emp[pos].position, 30);
    printf("Enter New Salary        : "); emp[pos].salary = readFloat();
    printf("Enter New Date of Joining: "); readText(emp[pos].doj, 15);
    printf("Record modified successfully.\n");
}

void deleteRecord(void) {
    int id, pos, i;
    printf("Enter Employee ID to delete: ");
    id = readInt();
    pos = findEmployee(id);
    if (pos == -1) { printf("Employee not found.\n"); return; }
    for (i = pos; i < count - 1; i++)
        emp[i] = emp[i + 1];
    count--;
    printf("Record deleted successfully.\n");
}

int main(void) {
    int choice;
    do {
        printf("\n===== EMPLOYEE DATABASE =====\n");
        printf("1. Create a New Record\n");
        printf("2. List All Records\n");
        printf("3. Modify a Record\n");
        printf("4. Delete a Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = readInt();
        switch (choice) {
            case 1: createRecord(); break;
            case 2: listRecords();  break;
            case 3: modifyRecord(); break;
            case 4: deleteRecord(); break;
            case 5: printf("Thank you. Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
    return 0;
}
