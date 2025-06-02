#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StudentDetails {
public:
    string name;
    vector<int> marks;

    void inputDetails() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks for 5 subjects (each out of 100): ";
        for (int i = 0; i < 5; i++) {
            int mark;
            cin >> mark;
            marks.push_back(mark);
        }
    }
};

class GPACalculator {
public:
    double calculateGPA(const vector<int>& marks) {
        int total = 0;
        for (int mark : marks)
            total += mark;

        double percentage = (double)total / (marks.size() * 100) * 100;
        double gpa = (percentage / 100) * 4.0;
        return gpa;
    }
};

class ResultDisplayer {
public:
    void display(const string& name, double gpa) {
        cout << "Student: " << name << ", GPA (out of 4.0): " << gpa << endl;
    }
};

int main() {
    StudentDetails s;
    GPACalculator gpaCalc;
    ResultDisplayer displayer;

    s.inputDetails();
    double gpa = gpaCalc.calculateGPA(s.marks);
    displayer.display(s.name, gpa);

    return 0;
}
