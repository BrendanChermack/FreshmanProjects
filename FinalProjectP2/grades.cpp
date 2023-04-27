#include <iostream>  
#include <fstream>  
#include <cstring> 
#include <string> 
#include <iomanip>  
#include "classListH.h"
using namespace std;  
  
const int maxSize = 20; //at most 20 students 
const int nameLength = student::nameLength; 

classList stuList(5);
ofstream outfile;  
ifstream infile;    
char input_file_name[21], output_file_name[21], name[nameLength+1]; 
string id;
/*------------------------------------------------------------------------  
  Functions used by main program and the user interface  
  ------------------------------------------------------------------------*/  
//menu function
void showmenu(){  
  cout<< "Please type in  one of the following options: \n";  
  cout<< "A or a to Load a data file containing information about the students and the scores \n";  
  cout<< "B or b to Display the stored data(raw data) \n";  
  cout<< "C or c to Process the records currently loaded\n";  
  cout<< "D or d to Search for a particular student, specified by name or ID \n";  
  cout<< "E or e to Print the processed grades to a file \n";  
  cout<< "F or f to Add a student to the classlist \n";  
  cout<< "G or g to Change a student’s test scores \n";  
  cout<< "H or h to Exit and save the (modified) raw data(name, id, test scores and homework scores) \n";    
}  
//loads students data from an inputfile
void loadStudent(){  
    student sTemp; 
    float hworkScores[10];
    float participation, testScore1, testScore2, testScore3, testScoreF;
    bool exit;
    int size;
    cout << "Enter name of the data file:  ";  
    cin >> input_file_name;  
    infile.open(input_file_name);  
    if (!infile){  
        // abandons operation with error mesg  
        cout << "Could not open input file \n";  
        infile.close();  
        infile.clear();  
        return;  
    }
    infile >> name; 
    sTemp.setName(name);
    while(!infile.eof()){
        infile >> id;
        sTemp.setId(id);
        size = 0;
        for(int i = 0; i <= 9; i++){
           infile >> hworkScores[i];
           size++;
        }
        sTemp.setHworkScores(hworkScores, size);
        infile >> participation; 
        sTemp.setParticipation(participation);
        infile >> testScore1;
        sTemp.setTestScore1(testScore1);
        infile >> testScore2;
        sTemp.setTestScore2(testScore2);
        infile >> testScore3;
        sTemp.setTestScore3(testScore3);
        infile >> testScoreF;
        sTemp.setTestScoreF(testScoreF);
        stuList.addStudent(sTemp);
        infile >> name;
        sTemp.setName(name);
        }
    infile.close();  
    infile.clear(); 
    }  
//displays the students data
void displayData(){
    cout << "Displaying data \n";
    stuList.writeData(cout);
}
//calculates the grades and aggregated scores
void processRecords(){  
  cout << "Processing Records \n";
  stuList.processStudent();
}  
//searches for a specific student in the class list and displays there data
void searchStudent(){  
  char c; 
  int j;
  cout << "Please enter n/N to search by name and anything else will seach by id\n";
  cin >> c;
  if((c == 'n') || (c == 'N')){
    cout << "Please enter the name of the student\n";
    cin >> name;
    j = stuList.searchByName(name);
  }
  else{
    cout << "Enter the ID of the student\n";
    cin >> id;
    j = stuList.searchById(id);
  }
  
  if(j != -1){
    stuList.getStudent(j).writeStudentReport(cout);
  }
  else{
    cout << "student could not be found\n";
  }
}  
//prints student data the console
void printToDataFile(){  
  cout << "Printing student data to a file \n"; 
  stuList.printStudent(cout);
}  
//adds a student to the class
void addStudentToList(){
    student sTemp; 
    float homeWorkScores[10];
    float participation;
    float test1, test2, test3, testF;
    int i = 0;
    cout << "Adding student \n"; 
    cout << "Using this format (Name ID 10HomeworkScores ParticipationScore 3TestScores FinalScore) Enter the student data \n";
    //read the student name
    cin >> name; 
    sTemp.setName(name);
    
    //read the students Id
    cin >> id; 
    sTemp.setId(id);

    //Read 10 values to add to the homework scores
    while(i <= 9){
        cin >> homeWorkScores[i];
        i++;
    }
    sTemp.setHworkScores(homeWorkScores, 10);
    //sets new values to the scores
    cin >> participation; 
    sTemp.setParticipation(participation);
    cin >> test1; 
    sTemp.setTestScore1(test1);

    cin >> test2; 
    sTemp.setTestScore2(test2);

    cin >> test3; 
    sTemp.setTestScore3(test3);

    cin >> testF; 
    sTemp.setTestScoreF(testF);
    
    //add the temp student to the list
    bool success = stuList.addStudent(sTemp);
    
    if(success){
        cout << "Student Added to class list. \n";
    }
    else{
        cout << "Failed to Add, class list is Full. \n";
    }  
}  
//set the final score and reprocesses the data
void changeTestScore(){  
  int j;
  cout << "Enter the ID of the student\n";
  cin >> id;
  j = stuList.searchById(id);

  if(j != -1){
    cout << "Enter the new final test score\n";
    int newScoreF;
    cin >> newScoreF;
    stuList.getStudent(j).modFinal(newScoreF);
    stuList.processStudent();
  }
  else{
    cout << "student could not be found\n";
  }

}
//writes the processed data to an outfile of the users choice
void saveInfo(){ 
  cout << "Enter where you would like to save your data\n";
  cin >> output_file_name;
  outfile.open(output_file_name);
  stuList.printStudent(outfile); 
  cout << "Saving data";  
  outfile.close();
}  
  
  
/* ---------------------- start of Main Program -----------------------------*/  
  
  
int main(){  
  
  char choice;  
  
  showmenu();  
  cout << "Please indicate your choice of operation (m for menu): ";  
  cin >> choice;  
  
  while ((choice != 'h')&& (choice != 'H')){  
        switch(choice){  
            case 'a':  
            case 'A': loadStudent(); break;  
            case 'b':
            case 'B': displayData(); break;
            case 'c':  
            case 'C': processRecords();break;  
            case 'd':  
            case 'D': searchStudent();break;  
            case 'e':  
            case 'E': printToDataFile();break;  
            case 'f':  
            case 'F': addStudentToList();break;  
            case 'g':  
            case 'G': changeTestScore();break;  
            case 'm':
            case 'M': showmenu();break;
            default : cout << "Not a valid choice" << endl;  
        }  
      cin.ignore(200, '\n'); cin.clear(); //clear out all input  
      cout << "Please indicate your choice of operation (m for menu): ";  
      cin >> choice;  
    }  
  saveInfo();  
  cout << " Thank-you, good bye! \n";  
}  
  