#include"student.h"

Student::Student(int Id,int Mt1_score,int Mt2_score,int Final_score,char* Name,char* Surname)
{
    ID = Id;
    strcpy(name,Name);
    strcpy(surname,Surname);
    mt1_score = Mt1_score;
    mt2_score = Mt2_score;
    final_score = Final_score;
}
/* Setter Functions */
void Student::setID(int Id)
{
	ID = Id;
}

void Student::setName(char* Name)
{
	strncpy(name,Name,16);
}
void Student::setSurname(char* Surname)
{
	strncpy(surname,Surname,16);
}
void Student::setMt1_Score(int Mt1_score)
{	
	mt1_score = Mt1_score;
}
void Student::setMt2_Score(int Mt2_score)
{
	mt2_score = Mt2_score;
}
void Student::setFinal_Score(int Final_score)
{
	final_score = Final_score;
}
/* Getter Functions */
int Student::getID(void)
{
	return ID;
}
char* Student::getName(void)
{
	return name;
}
char* Student::getSurname(void)
{
	return surname;
}
int Student::getMt1_Score(void)
{
	return mt1_score;
}
int Student::getMt2_Score(void)
{
	return mt2_score;
}
int Student::getFinal_Score(void)
{
	return final_score;
}
float Student::getOverallScore(int weight_Mt1,int weight_Mt2,int weight_Final) /* Overall Score Calculator */
{
	float overallScore 	= 1.0*(weight_Mt1*mt1_score+weight_Mt2*mt2_score+weight_Final*final_score)/100; /* Compute overall score*/
	return overallScore;
}
