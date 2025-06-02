#include <iostream>
#include <map>
#include <string>
using namespace std;

class GradeEntry {
public:
    map<string, char> grades;

    void inputGrades() {
        int n;
        cout << "Enter number of subjects: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            string subject;
            char grade;
            cout << "Enter subject name: ";
            cin >> subject;
            cout << "Enter grade (A-F): ";
            cin >> grade;
            grades[subject] = grade;
        }
    }
};

class GradeCompiler {
public:
    string compile(const map<string, char>& grades) {
        string result = "";
        for (map<string, char>::const_iterator it = grades.begin(); it != grades.end(); ++it) {
            result += it->first + ": " + it->second + "\n";
        }
        return result;
    }
};

class GradeReporter {
public:
    void report(const string& result) {
        cout << "\nCompiled Grades:\n" << result;
    }
};

int main() {
    GradeEntry entry;
    GradeCompiler compiler;
    GradeReporter reporter;

    entry.inputGrades();
    string result = compiler.compile(entry.grades);
    reporter.report(result);

    return 0;
}
