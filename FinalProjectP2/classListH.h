#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "studentH.h"
#ifndef classlistH
#define classlistH

class classList{
    private:
        unsigned int maxSize; 
        int nameLength, idLength; 
        vector<student> stuList;
    public:
    //constructor
    classList(unsigned int size = 0){
        maxSize = size;
        nameLength = student::nameLength;
    }
    //methods
    bool addStudent(student ); 
    void writeData(ostream& outfile);
    void processStudent();
    void printStudent(ostream& outfile);
    student& getStudent(int i);
    int searchById(string id);
    int searchByName(char name[]);
};
#endif
