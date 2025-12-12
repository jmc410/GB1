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


student* grabData(ifstream& file, int& stCnt, int& testCnt);

/*
    calcAvg
    Icludes the folowing:
student array,
stCnt - student #,
testCnt - test #.
*/
void calcAvg(student students[], int stCnt, int testCnt);

void printReport(student students[], int stCnt);

//   grabLetter - returns a letter grade based on the avg.

char grabLetter(double avg);



int main() {
    ifstream file("student_data");
    if (!file) {
        cout << "Something went wrong - sorry!\n";
        return 1;
    }

    int stCnt, testCnt;

    // Read and build student data
    student* students = grabData(file, stCnt, testCnt);

    // Calculates the average and letter grade.
    calcAvg(students, stCnt, testCnt);

    // Output of the report.
    printReport(students, stCnt);

    // Dynamically allocated memory is cleared.
    for (int i = 0; i < stCnt; i++) {
        delete[] students[i].tests;  
    }
    delete[] students;                

    return 0;
}



// Definitions.

student* grabData(ifstream& file, int& stCnt, int& testCnt) {
    file >> stCnt >> testCnt;

    student* students = new student[stCnt];

    for (int i = 0; i < stCnt; i++) {

        file >> students[i].name;
        file >> students[i].id;

        students[i].tests = new double[testCnt];

        for (int j = 0; j < testCnt; j++) {
            file >> students[i].tests[j];
        }
    }

    return students;
}


void calcAvg(student students[], int stCnt, int testCnt) {
    for (int i = 0; i < stCnt; i++) {

        double total = 0;

        for (int j = 0; j < testCnt; j++) {
            total += students[i].tests[j];
        }

        students[i].average = total / testCnt;
        students[i].grade = grabLetter(students[i].average);
    }
}


void printReport(student students[], int stCnt) {
    cout << "Student/ID/Score/Grade\n";

    for (int i = 0; i < stCnt; i++) {
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
