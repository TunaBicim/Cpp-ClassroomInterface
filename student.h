#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

static char defName[16] = "John"; //Name for dummy students
static char defSurname[16] = "Doe";

/* class declaration */
class Student
{
    private:
        int ID; 
        char name[16];
		char surname[16]; 
        int mt1_score,mt2_score,final_score; 

    public:
        Student(int Id = -1, int Mt1_score = 0, int Mt2_score = 0, int Final_score = 0,char* Name = defName,char* Surname = defSurname); 
        /* Setter Functions */
        void setID(int Id);
        void setName(char* Name);
        void setSurname(char* Surname);
        void setMt1_Score(int Mt1_score);
        void setMt2_Score(int Mt2_score);
        void setFinal_Score(int Final_score);
        /* Getter Functions */
        int getID(void);
        char* getName(void);
        char* getSurname(void);
        int getMt1_Score(void);
        int getMt2_Score(void);
        int getFinal_Score(void);
		float getOverallScore(int weight_mt1,int weight_mt2,int weight_final); // Overall Score Calculator 

};
