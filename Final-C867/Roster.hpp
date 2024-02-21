//
//  Roster.hpp
//  Final-C867
//
//  Created by Tyler Oneil on 1/31/24.
//

#ifndef Roster_hpp
#define Roster_hpp
using namespace std;

#include <iostream>
#include <string>
#include "Degree.h"
#include "Roster.hpp"
#include "Student.hpp"

// Class Definitions for Roster
class Roster {
public:
    // Parse Data function to break apart the the information in the studentData table
    void parseData(string stringData);
    void add(string studentID, string firstName, string lastName, string studentEmail, int age, int avgDay1, int avgDay2, int avgDay3, DegreeProgram degreeProgram);
    void printAll();
    void printInvalidEmails();
    void printAvgDaysInCourse(string SID);
    void printByDegreeProgram(string degree);
    void remove(string SID);
    
    ~Roster();
private:
    
    
    
};


#endif /* Roster_hpp */
