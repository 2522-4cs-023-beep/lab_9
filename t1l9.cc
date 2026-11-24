#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Number of students: ";
    cin >> n;

    int* marks = new int[n];

    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    int total = 0;
    int max = marks[0];

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << marks[i] << endl;
        total += marks[i];
        if (marks[i] > max) {
            max = marks[i];
        }
    }

    double average = static_cast<double>(total) / n;
    cout << "Average: " << average << endl;
    cout << "Highest: " << max << endl;

    cout << "Above average: ";
    for (int i = 0; i < n; i++) {
        if (marks[i] > average) {
            cout << marks[i] << " ";
        }
    }
    cout << endl;

    delete[] marks;
    marks = nullptr;

    return 0;
}