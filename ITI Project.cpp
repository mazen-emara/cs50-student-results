#include <iostream>
#include <string>
using namespace std;

int main() 
{
    // 1. Data Setup (Parallel Arrays)
    int id[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    
    string names[10] = {
        "Mazen Emara", 
        "Youssef Mohamed", 
        "Omar Khaled", 
        "Mohamed Ibrahim", 
        "Ali Mahmoud", 
        "Sarah Youssef", 
        "Menna Mostafa", 
        "Youssef Ahmed", 
        "Hassan Aly", 
        "Khaled Reda"
    };
    
    float Grade[10] = {90, 90, 85, 81, 82, 89, 70, 77, 88, 79};

    int searched_id;

    cout << "========================================" << endl;
    cout << "       CS50 Training Results System     " << endl;
    cout << "========================================" << endl;

    // Loop to keep the program running
    while (true) {
        cout << "\nEnter Student ID (101-110), 100 for All, 99 for Average, or 0 to Exit: ";
        cin >> searched_id;

        // Exit Condition
        if (searched_id == 0) {
            cout << "\nExiting Program. Good luck!" << endl;
            break;
        }

        // Feature 1: Display All Students (ID: 100)
        if (searched_id == 100) {
            cout << "\n========================================" << endl;
            cout << "          ALL STUDENTS RESULTS          " << endl;
            cout << "========================================" << endl;
            for (int i = 0; i < 10; i++) {
                cout << "ID: " << id[i] << " | Name: " << names[i] << " | Grade: " << Grade[i] << "%" << endl;
            }
            cout << "========================================" << endl;
            continue;
        }

        // Feature 2: Calculate Class Average (ID: 99)
        if (searched_id == 99) {
            float sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += Grade[i];
            }
            float average = sum / 10.0;
            cout << "\n----------------------------------------" << endl;
            cout << "Class Average Grade: " << average << "%" << endl;
            cout << "----------------------------------------" << endl;
            continue;
        }

        // Feature 3: Individual Student Search
        bool found = false;

        for (int i = 0; i < 10; i++) {
            if (id[i] == searched_id) {
                // Determine Grade Letter
                char letter;
                if (Grade[i] >= 85) letter = 'A';
                else if (Grade[i] >= 75) letter = 'B';
                else if (Grade[i] >= 65) letter = 'C';
                else if (Grade[i] >= 60) letter = 'D';
                else letter = 'F';

                // Output Result
                cout << "\n----------------------------------------" << endl;
                cout << "Student Name : " << names[i] << endl;
                cout << "Course Name  : CS50" << endl;
                cout << "Grade        : " << Grade[i] << "%" << endl;
                cout << "Grade Letter : " << letter << endl;
                cout << "----------------------------------------" << endl;

                found = true;
                break;
            }
        }

        // Error message if ID is not found
        if (!found) {
            cout << "\nError: Student ID not found! Please enter a valid ID between 101 and 110." << endl;
        }
    }

    return 0;
}