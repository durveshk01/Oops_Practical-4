#include <iostream>
using namespace std;

void updateMarks(int &marks)
{
    marks += 5;
}

int main()
{
    int n;

    cout << "STUDENT MARKS MANAGEMENT SYSTEM" << endl;
    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0 || n > 50)
    {
        cout << "Invalid number of students. Enter a value from 1 to 50." << endl;
        return 0;
    }

    string *name = new string[n];
    int *marks = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;

        cout << "Name: ";
        cin >> name[i];

        cout << "Marks: ";
        cin >> marks[i];

        if (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks. Enter marks between 0 and 100." << endl;
            delete[] name;
            delete[] marks;
            return 0;
        }
    }

    cout << "\n--- Student Records ---" << endl;

    for (int i = 0; i < n; i++)
    {
        int *ptr = &marks[i];

        cout << "\nStudent: " << name[i] << endl;
        cout << "Original Marks: " << *ptr << endl;

        updateMarks(marks[i]);

        if (marks[i] > 100)
            marks[i] = 100;

        cout << "Updated Marks: " << *ptr << endl;
    }

    delete[] name;
    delete[] marks;

    cout << "\nDynamic memory released successfully." << endl;

    return 0;
}