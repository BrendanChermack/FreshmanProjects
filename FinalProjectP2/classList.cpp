#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "studentH.h"
#include "classListH.h"
#include <vector>
using namespace std;
/*------------------------------------------------------------------------
Functions for handling and processing the list of students
-------------------------------------------------------------------------*/
//adds a student to the vector
bool classList::addStudent(student stu){  
  //cout << maxSize << endl;
    if((stuList.size()) >= maxSize)
        return false;  
        stuList.push_back(stu);
        return true;  
}  
//displays all the students data from the student vector
void classList::writeData(ostream& outfile){
  for(unsigned int index = 0; index < stuList.size(); index++){       
      (stuList.at(index)).displayStudent(outfile);
       outfile << endl;
    }
}
//processes all the students
void classList::processStudent(){
    for(unsigned int i = 0; i < stuList.size(); i++)
    {
        (stuList.at(i)).processStudent();
        
    }
}
//prints all the students data
void classList::printStudent(ostream& outfile){
    for(unsigned int i = 0; i < stuList.size(); i++){
        (stuList.at(i)).writeStudentReport(outfile);
        outfile << endl;
    }
}
//returns a studetn at index i
student& classList::getStudent(int i){
  return stuList.at(i);
}
//searches a specific student with a specific ID and returns the idex
int classList::searchById(string Id){
  for(unsigned int i = 0; i < stuList.size(); i++){
    if(stuList.at(i).getId() == Id){
      return i;
    }
  }
  return -1;
}
//searches for specific student with a specific name and returns the idex
int classList::searchByName(char name[]){
  for(unsigned int i = 0; i < stuList.size(); i++){
    if(strcmp(stuList.at(i).getName(), name) == 0){
      return i;
    }
  }
  return -1;
}