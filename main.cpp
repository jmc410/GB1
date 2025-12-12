#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Student structure, holds data.
struct student {
    string name;
    int id;
    double* tests;
    double average;
    char grade;
};


student* grabData(ifstream& file, int& studentCnt, int& testCnt);

/*
    calcAvg
    Icludes the folowing:
student array,
studentCnt - student #,
testCnt - test #.
*/
void calcAvg(student students[], int studentCount, int testCnt);

void printReport(student students[], int studentCnt);

//   grabLetter - returns a letter grade based on the avg.

char grabLetter(double avg);



int main() {
    ifstream file("student_data");
    if (!file) {
        cout << "Something went wrong - sorry!\n";
        return 1;
    }

    int studentCnt, testCnt;

    // Read and build student data
    student* students = grabData(file, studentCnt, testCnt);

    // Calculates the average and letter grade.
    calcAvg(students, studentCnt, testCnt);

    // Output of the report.
    printReport(students, studentCnt);

    // Dynamically allocated memory is cleared.
    for (int i = 0; i < studentCnt; i++) {
        delete[] students[i].tests;  
    }
    delete[] students;                

    return 0;
}



// Definitions.

student* grabData(ifstream& file, int& studentCnt, int& testCnt) {
    file >> studentCnt >> testCnt;

    student* students = new student[studentCnt];

    for (int i = 0; i < studentCnt; i++) {

        file >> students[i].name;
        file >> students[i].id;

        students[i].tests = new double[testCnt];

        for (int j = 0; j < testCnt; j++) {
            file >> students[i].tests[j];
        }
    }

    return students;
}


void calcAvg(student students[], int studentCnt, int testCnt) {
    for (int i = 0; i < studentCnt; i++) {

        double total = 0;

        for (int j = 0; j < testCnt; j++) {
            total += students[i].tests[j];
        }

        students[i].average = total / testCnt;
        students[i].grade = grabLetter(students[i].average);
    }
}


void printReport(student students[], int studentCnt) {
    cout << "Student/ID/Score/Grade\n";

    for (int i = 0; i < studentCnt; i++) {
        cout << students[i].name << "/"
             << students[i].id << "/"
             << students[i].average << "/"
             << students[i].grade << endl;
    }
}


char grabLetter(double avg) {
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}
