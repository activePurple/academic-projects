//
//  main.cpp
//  Final-C867
//
//  Created by Tyler Oneil on 1/31/24.
//

#include <iostream>
#include <string>
#include "Student.hpp"
#include "Roster.hpp"
#include "Degree.h"


void printInfo() {
    cout << "C867 C++ Programming and Scripting" << "\n";
    cout << "Tyler ONeil" << "\n";
    cout << "Student ID: 007747889" << "\n";
    cout << endl;
};

const string studentData[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,first,last,student@wgu.edu,25,30,40,44,SOFTWARE"};


Roster classRoster;

// Main Function
int main(int argc, const char * argv[]) {
    
    printInfo();
    
    for (int i = 0; i < 5; i++) {
        classRoster.parseData(studentData[i]);
    }
    
    
    cout << "Printing Roster Of Student: " << "\n";
    cout << "-----------------------" << endl;
    classRoster.printAll();

    cout << "-----------------------"  << "\n " << endl;

    cout << "Printing Invalid Emails: " << "\n";
    cout << "-----------------------" << endl;
    
    classRoster.printInvalidEmails();
    cout << "-----------------------"  << "\n " << endl;
    
    
    cout << "Printing Average Days By StudentID: " << "\n";
    cout << "-----------------------" << endl;
    classRoster.printAvgDaysInCourse("A3");
    cout << "-----------------------"  << "\n " << endl;

    cout << "Printing By Degree Program: " << "\n";
    cout << "-----------------------"  << endl;

    classRoster.printByDegreeProgram("SOFTWARE");
    
    cout << "-----------------------"  << "\n " << endl;
    
    cout << "\n" << "Removing Student: A3" << "\n";
    cout << "-----------------------" << endl;

    classRoster.remove("A3");
    classRoster.printAll();
    cout << "\n" << "-----------------------" << endl;
    
    
    cout << "\n" << "Verifying Removal..."  << "\n";
    cout << "\n" << "-----------------------" << endl;
    classRoster.remove("A3");
    cout << "\n" << "-----------------------" << endl;

    
    classRoster.~Roster();
    

    
    return 0;
}
