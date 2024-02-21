//
//  Student.hpp
//  Final-C867
//
//  Created by Tyler Oneil on 1/31/24.
//

#ifndef Student_hpp
#define Student_hpp

#include <iostream>
#include <string>
#include "Degree.h"
#include "Roster.hpp"
#include "Student.hpp"

using namespace std;

// Student Class will be the basis for the Student objects as they are created being made from our data.
class Student {
    
    

public:
    // Constructors for our class
    //Defualt empty constructor
    Student();
    
    // Constructor with parameters to be intialized
    Student(string SID, 
            string FNAME,
            string LNAME,
            string EMAIL,
            int age,
            array<int,3> avgDaysArray,
            DegreeProgram degreeProgram);
    ~Student();

    
    // Setter member functions
    void setSID(string SID);
    void setFNAME(string FNAME);
    void setLNAME(string LNAME);
    void setEMAIL(string EMAIL);
    void setAGE(int AGE);
    void setARRAYDAYS(array<int, 3>DAYSARRAY);
    void setDEGREEPROGRAM(DegreeProgram PROGRAM);
    
    // Getter Member Functions
    string getSID();
    string getFNAME();
    string getLNAME();
    string getEMAIL();
    int getAGE();
    void getARRAYDAYS();
    int getAvgDays();
    string getDEGREEPROGRAM();
    
    // PrintAll Function
    void print();
    
private:
    // Our Private variables that will hold our values
    string studentID;
    string firstName;
    string lastName;
    string studentEmail;
    int age;
    array<int, 3>avgDaysArray;
    DegreeProgram degreeProgram;
    
};


#endif /* Student_hpp */
