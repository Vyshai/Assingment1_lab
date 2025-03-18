#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Structure for student data
struct Student {
    int id;
    string firstName;
    string lastName;
    string course;
    float gpa;
};

// Function prototypes
void addStudent(Student students[], int &count);
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
            case 2: viewStudent(students, count); break;
            case 3: cout << "Thank You, Have a Great Day!!!....Exiting program....\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (option != 3);

    return 0;
}

// Function to display the main menu
    void displayMenu() {
        cout << "\n--- Student Record Management ---\n";
        cout << "[1] Add Student\n";
        cout << "[2] View Students\n";
        cout << "[3] Exit Program\n";
    }
    
    // Function to add a new student
    void addStudent(Student students[], int &count) {
        if (count >= MAX_STUDENTS) {
            cout << "Database is full. Cannot add more students.\n";
            return;
        }
    
        int id;
        cout << "Enter Student ID: ";
        cin >> id;
    
        // Check for duplicate ID
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

    
// Function to view student records
void viewStudent(Student students[], int count) {
    if (count == 0) {
        cout << "No records available.\n";
        return;
    }

    int choice;
    cout << "View by:" << endl << "[1] Alphabetically" << endl <<"[2] GPA\n";
    cin >> choice;

    // Sorting logic for displaying students
    if (choice == 1) {
        // Sort alphabetically by last name (simple bubble sort)
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (students[i].lastName > students[j].lastName) {
                    swap(students[i], students[j]);
                }
            }
        }
        cout << "Displaying students alphabetically:\n";
    } else if (choice == 2) {
        // Sort by GPA (ascending order)
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

    // Display students
    cout << left << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(10) << "Course" << setw(5) << "GPA\n";
    cout << "------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << students[i].id
             << setw(15) << students[i].firstName
             << setw(15) << students[i].lastName
             << setw(10) << students[i].course
             << setw(5) << students[i].gpa << "\n";
    }
}
