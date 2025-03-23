#include <iostream>

using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float gpa;
};

void addStudent(Student students[], int &count);
void editStudent(Student students[], int count);
void deleteStudent(Student students[], int &count);
void viewStudent(Student students[], int count);
void displayMenu();

const int MAX_STUDENTS = 100; // Maximum students that can be stored

int main() {
    Student students[MAX_STUDENTS]; // Array of student structures
    int count = 0; // Number of students
    int option;

    do {
        displayMenu();
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1: addStudent(students, count); break;
            case 2: editStudent(students, count); break;
            case 3: deleteStudent(students, count); break;
            case 4: viewStudent(students, count); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (option != 5);

    return 0;
}

void displayMenu() {
    cout << "\n--- Student Record Management ---\n";
    cout << "[1] Add Student\n";
    cout << "[2] Edit Student\n";
    cout << "[3] Delete Student\n";
    cout << "[4] View Students\n";
    cout << "[5] Exit Program\n";
}

void addStudent(Student students[], int &count) {
    if (count >= MAX_STUDENTS) {
        cout << "Database is full. Cannot add more students.\n";
        return;
    }

    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Error: Student ID already exists!\n";
            return;
        }
    }

    students[count].id = id;
    cout << "Enter First Name: ";
    cin >> students[count].firstName;
    cout << "Enter Last Name: ";
    cin >> students[count].lastName;
    cout << "Enter Course: ";
    cin >> students[count].course;
    cout << "Enter GPA: ";
    cin >> students[count].gpa;

    count++;
    cout << "Student added successfully!\n";
}

void editStudent(Student students[], int count) {
    if (count == 0) {
        cout << "No records to edit.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Editing record for " << students[i].firstName << " " << students[i].lastName << ":\n";
            cout << "Enter New First Name: ";
            cin >> students[i].firstName;
            cout << "Enter New Last Name: ";
            cin >> students[i].lastName;
            cout << "Enter New Course: ";
            cin >> students[i].course;
            cout << "Enter New GPA: ";
            cin >> students[i].gpa;

            cout << "Record updated successfully!\n";
            return;
        }
    }

    cout << "Student ID not found.\n";
}

void deleteStudent(Student students[], int &count) {
    if (count == 0) {
        cout << "No records to delete.\n";
        return;
    }

    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student record deleted successfully!\n";
            return;
        }
    }

    cout << "Student ID not found.\n";
}

void viewStudent(Student students[], int count) {
    if (count == 0) {
        cout << "No records available.\n";
        return;
    }

    int choice;
    cout << "View by:\n[1] Alphabetically\n[2] GPA\n";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (students[i].lastName > students[j].lastName) {
                    swap(students[i], students[j]);
                }
            }
        }
        cout << "Displaying students alphabetically:\n";
    } else if (choice == 2) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (students[i].gpa > students[j].gpa) {
                    swap(students[i], students[j]);
                }
            }
        }
        cout << "Displaying students by GPA (ascending order):\n";
    } else {
        cout << "Invalid choice.\n";
        return;
    }

    cout << "ID\tFirst Name\tLast Name\tCourse\t   GPA\n";
    cout << "------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << students[i].id << "\t"
             << students[i].firstName << "\t" << "\t"
             << students[i].lastName << "\t" << "\t"
             << students[i].course << "\t    "
             << students[i].gpa << "\n";
    }
}