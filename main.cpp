#include <iostream>
#include <fstream>
#include <string>

/* 
student structure, 
  student name, ID, test scores, avg, and final letter grade 
*/

struct Stdnt {
string name;
int id;
double* tests;
double avg;
char grade;
};

/*
Referencing to an opened ifsteam, studentCnt will hold the # of students, testCnt will hold the # of tests.
*/

student* getData(ifsteam& file, int& studentCnt, int&t testCnt);

void calcAverage(student students[], int studentCnt, int testCnt);

void printReprt(student students[], int studentCnt);


char grabLetter(double avg);

int main() {
ifstream file("student_data");
  if (!file) {
    cout << "Something went wrong when opening the file.\n";
    return 1;
  }

int studentCnt, testCnt;

  // Read data 
  student* students = getData(file, studentCnt, testCnt);

  // Calculation
  calcAvg(student, studentCnt, testCnt);

  // Report
printReprt(students, studentCnt);

  // Clean up
  for (int i = 0; i < studentCnt; i++) {
    delete[] students[i].tests;
  }
  delete[] students;

  return 0;
  }

}