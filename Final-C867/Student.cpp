//
//  Student.cpp
//  Final-C867
//
//  Created by Tyler Oneil on 1/31/24.
//

#include <iostream>
#include <string>
#include "Degree.h"
#include "Roster.hpp"
#include "Student.hpp"

// Empty Constructor
Student::Student() {
    studentID = "No StudentID";
    firstName = "No Name";
    lastName = "No Last";
    studentEmail = "No Email";
    age = 0;
    avgDaysArray = {0,0,0};
    degreeProgram = NO_PROGRAM;
};

// Constructor Definiton
Student::Student(string SID,
                 string FNAME,
                 string LNAME,
                 string EMAIL,
                 int nAge,
                 array<int,3> nAvgDaysArray,
                 DegreeProgram nDegreeProgram) {
    studentID = SID;
    firstName = FNAME;
    lastName = LNAME;
    studentEmail = EMAIL;
    age = nAge;
    avgDaysArray = nAvgDaysArray;
    degreeProgram = nDegreeProgram;
};

Student::~Student() {};

// Setter functions for Student class
void Student::setSID(string SID) {
    studentID = SID;
};
void Student::setFNAME(string FNAME){
    firstName = FNAME;
};
void Student::setLNAME(string LNAME){
    lastName = LNAME;
};
void Student::setEMAIL(string EMAIL){
    studentEmail = EMAIL;
};
void Student::setAGE(int AGE){
    age = AGE;
};
void Student::setARRAYDAYS(array<int, 3>DAYSARRAY){
    avgDaysArray = DAYSARRAY;
};
void Student::setDEGREEPROGRAM(DegreeProgram PROGRAM){
    degreeProgram = PROGRAM;
};



// Getters for our Student Class:
string Student::getSID(){
    return studentID;
};
string Student::getFNAME(){
    return firstName;
};
string Student::getLNAME(){
    return lastName;
};
string Student::getEMAIL(){
    return studentEmail;
};
int Student::getAGE(){
    return age;
};
void Student::getARRAYDAYS(){
    cout << "{"<< avgDaysArray[0] << "," << avgDaysArray[1] << "," << avgDaysArray[2] << "}\t";
};

int Student::getAvgDays(){
    int avg = (avgDaysArray[0] + avgDaysArray[1] + avgDaysArray[2]) / 3;
    return avg;
};

string Student::getDEGREEPROGRAM(){
    string program;
    if (degreeProgram == 0) {
        return program = "NETWORK";
    }
    else if (degreeProgram == 1) {
        return program = "SECURITY";
    }
    else if (degreeProgram == 2) {
        return program = "SOFTWARE";
    }
    return program;
};



// Print Statement
void Student::print(){
    cout << getSID() << "\t" << getFNAME() << "\t";
    cout << getLNAME() << "\t" << getEMAIL() << "\t";
    cout << getAGE() << "\t";
    getARRAYDAYS();
    cout << getDEGREEPROGRAM() << "\n";
};

