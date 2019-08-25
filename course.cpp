#include"course.h"

Course::Course(int Weight_mt1,int Weight_mt2,int Weight_final)
{
    weight_mt1= Weight_mt1;
    weight_mt2= Weight_mt2;
    weight_final= Weight_final;
	num = 0;
}
int Course::getNum(void)
{
	return num;
}
void Course::addStudent(void)
{
	int ID;
    char Name[16];
	char Surname[16];
	char* pname = Name;
	char* psurname = Surname;
	int Mt1_score,Mt2_score,Final_score;
	cout << "Enter ID, name, surname and exam scores (MT1,MT2,Final): " << endl ;
    cin  >> ID >> Name >> Surname >>  Mt1_score >> Mt2_score >> Final_score;
    int exist;
	for (exist = 0; exist<10; exist++) //Check for faulty inputs 
	{
		if (entries[exist].getID() == ID)
        {
		  exist = 10;
        }
	}
	if (ID < 0 )
	{
		cout <<"ID cannot be negative!" << endl;
		return; 
	} else if (exist == 11)
	{
        cout <<"There is a student with this ID!" << endl;
		return;
	} else if ((Mt1_score < 0)||(Mt1_score > 100)||(Mt2_score < 0)||(Mt2_score > 100)||(Final_score < 0)||(Final_score > 100))
	{	
		cout <<"At least one of the midterms grades are invalid." << endl;
		return;
	} else //If there is no fault in the input add the student
	{		
	entries[num].setID(ID);
	entries[num].setName(pname);
	entries[num].setSurname(psurname);
	entries[num].setMt1_Score(Mt1_score);
	entries[num].setMt2_Score(Mt2_score);
	entries[num].setFinal_Score(Final_score);
	num++;
    return;
	}
}
void Course::changeWeights(int Weight_mt1,int Weight_mt2,int Weight_final)
{
	weight_mt1 = Weight_mt1;
	weight_mt2 = Weight_mt2;
	weight_final = Weight_final;
}
Student* Course::getStudent(int index)
{
	return &entries[index];
}
void Course::calcAverage(void)
{
	float mt1_average = 0;
	float mt2_average = 0;
	float final_average = 0;
	float overall_average = 0;
	for ( int index = 0; index<num; index++)
	{
		mt1_average += entries[index].getMt1_Score();
		mt2_average += entries[index].getMt2_Score();
		final_average += entries[index].getFinal_Score();
	}
	mt1_average = mt1_average/num;
	mt2_average = mt2_average/num;
	final_average = final_average/num;
	overall_average = (weight_mt1*mt1_average+weight_mt2*mt2_average+weight_final*final_average)/100;
	cout << "MT1 Average: " << fixed << setprecision(2) << mt1_average << endl; //Only display 2 decimal digits 
	cout << "MT2 Average: " << fixed << setprecision(2) << mt2_average << endl;
	cout << "Final Average: " << fixed << setprecision(2) << final_average << endl;
	cout << "Overall Average: " << fixed << setprecision(2) << overall_average << endl;
}

float Course::Overall(int index) //Use the overall function of student class and pass the answer to main.
{
    float overall = 0 ;
    overall = entries[index].getOverallScore(weight_mt1,weight_mt2,weight_final);
    return overall;
}




