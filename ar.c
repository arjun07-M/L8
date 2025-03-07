#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[100];
    int attendance;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a student
void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter student name: ");
        scanf("%s", students[studentCount].name);
        students[studentCount].attendance = 0;
        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum student limit reached!\n");
    }
}

// Function to mark attendance
void markAttendance() {
    char name[100];
    printf("Enter student name: ");
    scanf("%s", name);
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, name) == 0) {
            students[i].attendance++;
            printf("Attendance marked successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

// Function to view attendance
void viewAttendance() {
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s, Attendance: %d\n", students[i].name, students[i].attendance);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Attendance Management System\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                markAttendance();
                break;
            case 3:
                viewAttendance();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
