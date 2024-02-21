//
//  Roster.cpp
//  Final-C867
//
//  Created by Tyler Oneil on 1/31/24.
//

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include "Degree.h"
#include "Student.hpp"
#include "Roster.hpp"

// Global variables that are used below in the class to create our array of pointers and index to operate with
int const MAX_SIZE = 5;
Student* classRosterArray[MAX_SIZE];
int indexLast = -1;

// The Add function for our Roster class to call our Student Constructor class
void Roster::add(string studentID, string firstName, string lastName, string studentEmail, int age, int avgDay1, int avgDay2, int avgDay3, DegreeProgram degreeProgram) {
    array<int,3> avgDayArray;
    
    for (int i = 0; i < 3; i++) {
        avgDayArray[0] = avgDay1;
        avgDayArray[1] = avgDay2;
        avgDayArray[2] = avgDay3;
    }
    
    if (indexLast < MAX_SIZE - 1) {
        indexLast++;
        classRosterArray[indexLast] = new Student(studentID, firstName, lastName, studentEmail, age, avgDayArray, degreeProgram);

    }
    else {
        cout << "Roster Full!" << "\n" << endl;
    }
    
    
};

// Parse Data Function for studentData[] strings
void Roster::parseData(string stringData) {

        // size_t is used due to availability of features that allow for operating on strings with methods like find() and substr().
        size_t rhs = stringData.find(",");
        string studentID = stringData.substr(0, rhs);
        
        size_t lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        string firstName = stringData.substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        string lastName = stringData.substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        string email = stringData.substr(lhs, rhs - lhs);
        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        int age = stoi(stringData.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        int avgDay1 = stoi(stringData.substr(lhs, rhs - lhs));
        
        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        int avgDay2 = stoi(stringData.substr(lhs, rhs - lhs));

        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        int avgDay3 = stoi(stringData.substr(lhs, rhs - lhs));
        
        lhs = rhs + 1;
        rhs = stringData.find(",", lhs);
        string strDegreeProgram = stringData.substr(lhs, rhs - lhs);
        
    DegreeProgram degreeProgram;
        
    // Need conversion for degreeProgram here before sending to add function so we submit our proper degree program
    if (strDegreeProgram == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    }
    else if (strDegreeProgram == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    }
    else if (strDegreeProgram == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    else {
        degreeProgram = DegreeProgram::NO_PROGRAM;
    }
    
    add(studentID, firstName, lastName, email, age, avgDay1, avgDay2, avgDay3, degreeProgram);

};


// Print all function that iterates through out student objects
void Roster::printAll() {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
};

// Print Invalid Email function to show any false emails that within out Roster
void Roster::printInvalidEmails() {
    for (int i = 0; i < MAX_SIZE; i++) {
        string email = classRosterArray[i]->getEMAIL();
        string pullEmails = email.substr(email.find_first_of(email), email.find_last_of(email) + 1);
        string invalidEmails;
        for (int l = 0; l < email.length(); l++) {
            size_t s = email.find(" ");
            size_t p = email.find(".");
            size_t at = email.find("@");
            if (s != pullEmails.find(s)) {
                invalidEmails = pullEmails;
                cout << invalidEmails << "\n";
                break;
            }
            if (p == pullEmails.find(p)) {
                invalidEmails = pullEmails;
                cout << invalidEmails << "\n";
                break;
            }
            if (at == pullEmails.find(at)) {
                invalidEmails = pullEmails;
                cout << invalidEmails << "\n";
                break;
            }
            
        }
    }
    
};


// Returns our average course time from student class and members
void Roster::printAvgDaysInCourse(string SID) {
    for (int i = 0; i < MAX_SIZE; i++) {
        SID = classRosterArray[i]->getSID();
            cout << "Student ID: " << SID << "\t";
            cout << "Average Days In Course: " << classRosterArray[i]->getAvgDays() << endl;
    }
};

// Returns the student IDs and Degree programs to verify against data
void Roster::printByDegreeProgram(string degree) {
    for (int i = 0; i < MAX_SIZE; i++){
        string SID = classRosterArray[i]->getSID();
        if (classRosterArray[i]->getDEGREEPROGRAM() == degree) {
            cout << "Student ID: " << SID << "\nDegree Program: " << degree << "\n" << endl;
        }
    }
};


// Our remove student function that assigns a null pointer to the array so we can keep our static array size and with out using and kind of copy functions or vectors even though that would be preferred here.
void Roster::remove(string SID) {
    bool studentFound = false;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getSID() == SID) {
            studentFound = true;
            cout << "\n" << "Searching for Student: " << SID << "\n";
            cout << "Student Found... "<< "\n" <<"Removing..." << "\n" << endl;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            cout << "Student Removed!" << "\n" << endl;
            break;
            
        }
    }
    if (!studentFound) {
            cout << "Student: " << SID << " Not Found" << endl;
        }
};


Roster::~Roster(){};
