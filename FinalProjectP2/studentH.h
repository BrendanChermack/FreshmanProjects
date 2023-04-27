#include <iostream>  
#include <fstream>  
#include <cstring>  
#include <string> 
#include <iomanip>
#ifndef studentH
#define studentH
using namespace std;

class student{
    //public varaibles
    public:
        const static int nameLength = 20;
        const static int idLength = 8; 
        const static int maxHworks = 10;
    //private varaibles
    private:
        char name[nameLength];  // name is stored as an array of char 
        string id;
        int numHworks;
        float hworkScores[maxHworks];
        float participation, testScore1, testScore2, testScore3, testScoreF;
        float agTest, agHwork, totalScore;
        char grade;
    //public methods
    public:
    //returns the student name
        char* getName(){
            return name;
        }
         //returns the student id
        string getId(){
            return id;
        }
        //sets the student name
        void setName(char n[]){ // parameter is array of char, to match name
            strcpy(name, n); // need this function; cannot assign arrays
        }
        //sets the student id
        void setId(string n){
            id = n;
        }
        //sets homeworkscores
        void setHworkScores(float scores[], int size){
            numHworks = (size <= maxHworks) ? size : maxHworks;
            for(int i = 0; i < numHworks; i++){
                hworkScores[i]  = scores[i];
            }
        }
        //sets setParticipation
        void setParticipation(int p){
            participation = p;
        }
        //sets setTestScore1
        void setTestScore1(int score1){
            testScore1 = score1;
        }
        //sets setTestScore2
        void setTestScore2(int score2){
            testScore2 = score2;
        }
        //sets setTestScore3
         void setTestScore3(int score3){
            testScore3 = score3;
        }
        //sets setTestScoreF
        void setTestScoreF(int scoreF){
            
            testScoreF = scoreF;
        }
        //displays students info
        void displayStudent(ostream& outfile){
            char space = ' ';
            outfile << name << space << id << space;
            for(int i = 0; i < maxHworks; i++){
                outfile << hworkScores[i] << space;
            }
            outfile << participation << space << testScore1 << space 
            << testScore2 << space << testScoreF;
        }
        //calculates total homework score
        void hworkScoreCal(){
			float tempScore, totalScore;
			float min = 100, total = 0;
			bool error = false;
			
			for (int i = 0; i < maxHworks; i++){
				tempScore = hworkScores[i];
				if((tempScore > 100) || (tempScore < 0)){
					error = true;
				}
				if (tempScore < min){
					min = tempScore;
				}
				totalScore += hworkScores[i];
			}
			
			agHwork = (((totalScore - min) + participation)/1000)*50;
			if(error){
                agHwork = -1.0;
            }
		}
        //calculates tests score
        void testScoreCal(){
			float midScores = testScore1 + testScore2 + testScore3;
			float finalT = testScoreF*2;
			
            agTest = (((finalT + midScores)/500)*50);
			if((((testScore1 > 100) || (testScore1 < 0)) || ((testScore2 > 100) || (testScore2 < 0))) || (((testScore3 > 100) || (testScore3 < 0)) || ((testScoreF > 100) || (testScoreF < 0)))){
                agTest = -1;
			}
		}
        //calculates total score
        void totalScoreCal(){
			totalScore = agTest + agHwork;
			if((agHwork == -1) || (agTest == -1))
			{
				totalScore = -1;
			}
		}
        //determines the letter grade
        void letterGrade(){
            //grading logic for which score recieves what grade
            if(totalScore == -1)//if -1 then the letter z is returned
            {
                grade = 'Z';
            }
            else if(totalScore >= 90)
            {
                grade = 'A';
            }
            else if(totalScore >= 80)
            {
                grade = 'B';
            }
            else if(totalScore >= 70)
            {
                grade = 'C';
            }
            else if(totalScore >= 60) 
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }
		}
        //calls all the calculations so the student is processed
        void processStudent(){
			int totalScore = 0;
			hworkScoreCal();
			testScoreCal();
			totalScoreCal();
			letterGrade();
		}
        //outputs the students data
        void writeStudentReport(ostream& outfile){
		  char space = ' ';
		  outfile << name << space << id << space << agHwork << space << agTest << space << totalScore << space << grade << endl; 	  
		}
        //allows to adjust the final score
        void modFinal(int newFinalScore){
            int newScoreF = newFinalScore;
            setTestScoreF(newScoreF);
        }
};
#endif