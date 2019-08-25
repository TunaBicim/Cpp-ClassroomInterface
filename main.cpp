#include <iostream>
#include <string.h>
#include <iomanip>
#include "course.h"

using namespace std;

void showByID(int ID,Course &CourseName);
void showAbove(float threshold,Course &CourseName);
void showBelow(float threshold,Course &CourseName);
void showAverage(Course &CourseName);
void updateStudentScore(int Score,Course &CourseName,int index,char* Type);

char MT1[4] = "MT1",Mt1[4] = "Mt1",mt1[4] = "mt1",mT1[4] = "mT1";
char MT2[4] = "MT2",Mt2[4] = "Mt2",mt2[4] = "mt2",mT2[4] = "mT2";
char FINAL[6] = "FINAL",Final[6] = "Final",final[6] = "final";

int main()
{	Course DataStructures(25,25,50); //Create Course Class object
	int option = 0;
	int ID = 0;
	float threshold = 0;
	cout << "Classroom Information Interface" << endl << endl; //Printout options
	cout << "Choose your option:" << endl;
	cout << "1) Add a student" << endl;
	cout << "2) Search a student by ID" << endl;
	cout << "3) Show students with overall score above a threshold" << endl;
	cout << "4) Show students with overall score below a threshold" << endl;
	cout << "5) Show classroom average" << endl;
	cout << "6) Change a student's score" << endl;
	cout << "7) Exit" << endl;

	while(1)
	{
		cout << endl << "Enter your option: ";
		if (!(cin  >> option)) //If the input is faulty clear and ignore (ie. a letter is recieved instead of number)
        {
            cin.clear();
            cin.ignore();
            cout << "Please enter a valid option";
        }
		switch(option) //The cases are self explanatory in this part. The working concepts of the functions will be adressed at their actual location
		{
			case 1:
				DataStructures.addStudent();
				break;

			case 2:
				cout << "Enter ID: ";
				cin  >> ID;
				showByID(ID, DataStructures);
				break;

            case 3:
                cout << "Enter minimum score: ";
                cin >> threshold;
                showAbove(threshold, DataStructures);
                break;

			case 4:
                cout << "Enter maximum score: ";
                cin >> threshold;
                showBelow(threshold, DataStructures);
                break;

            case 5:

				showAverage(DataStructures);
				break;

			case 6:
				if (DataStructures.getNum() == 0)
				{
					cout << "No registered students!" << endl;
					break;
				}
				int index;
				char Type[6];
				int Score;
				cout << "Please enter ID, exam type and updated score: ";
				cin  >> ID >> Type >> Score;
				if ((Score < 0)||(Score > 100)) //Check if the score is valid
				{
					cout <<"Invalid Score!"<< endl;
				} else  //Check if there is a student with the provided ID
				{
					for (index = 0; index<10; index++)
					{
						if (DataStructures.getStudent(index)->getID() == ID)
						{
							updateStudentScore(Score,DataStructures,index,Type);
							index = 11;
						}
					}
					if (index == 10)
					{
						cout <<"No student with such ID!" << endl;
					}
				}
				break;

            case 7:

                return 0;

			default:
				option = 0;
				break;
		}
	}
}

void showByID(int ID,Course &CourseName)
{
	if (CourseName.getNum() == 0)
	{
		cout << "No registered students!" << endl;
		return;
	}
	if (ID < 0)
	{
		cout << "ID cannot be negative!" << endl;
		return;
	}
    int index;
	for (index = 0; index<10; index++) //If there is a student with this ID print their details
	{
		if (CourseName.getStudent(index)->getID() == ID)
        {
          cout << CourseName.getStudent(index)->getID() << ' ';
          cout << CourseName.getStudent(index)->getName() << ' ';
          cout << CourseName.getStudent(index)->getSurname() << ' ';
          cout << CourseName.getStudent(index)->getMt1_Score() << ' ';
          cout << CourseName.getStudent(index)->getMt2_Score() << ' ';
          cout << CourseName.getStudent(index)->getFinal_Score() << ' ';
          cout << fixed << setprecision(2) <<CourseName.Overall(index) << endl;
          index = 10;
        }
	}
	if (index == 10)
	{
        cout << "No student with such ID!" << endl;
	}
	return;
}

void showAbove(float threshold,Course &CourseName)
{
	if (CourseName.getNum() == 0)
	{
		cout << "No registered students!" << endl;
		return;
	}
	if ((threshold < 0)||(threshold > 100))
	{
		cout <<"Invalid threshold!" << endl;
		return;
	}
	int found = 0;
	for (int index = 0; index<10; index++) //Find students with grades above the threshold.
	{
        if (CourseName.Overall(index) >= threshold )
        {
            found++;
            cout << CourseName.getStudent(index)->getID() << ' ';
            cout << CourseName.getStudent(index)->getName() << ' ';
            cout << CourseName.getStudent(index)->getSurname() << ' ';
            cout << CourseName.getStudent(index)->getMt1_Score() << ' ';
            cout << CourseName.getStudent(index)->getMt2_Score() << ' ';
            cout << CourseName.getStudent(index)->getFinal_Score() << ' ';
            cout << fixed << setprecision(2) << CourseName.Overall(index) << endl;
        }
	}
	if (found == 0) //If no students found print out an error
	{
        cout << "No student with grades above this value!" << endl;
	}
	return;
}

void showBelow(float threshold,Course &CourseName)
{
	if (CourseName.getNum() == 0)
	{
		cout << "No registered students!" << endl;
		return;
	}
	if ((threshold < 0)||(threshold > 100))
	{
		cout <<"Invalid threshold!" << endl;
		return;
	}
	int found = 0;
	for (int index = 0; index<10; index++) //Since there are dummy students created when the Course class is created we need to exclude those by checking the overall
	{
        if ((CourseName.Overall(index) != 0) && (CourseName.Overall(index) <= threshold))
        {
            found++;
            cout << CourseName.getStudent(index)->getID() << ' ';
            cout << CourseName.getStudent(index)->getName() << ' ';
            cout << CourseName.getStudent(index)->getSurname() << ' ';
            cout << CourseName.getStudent(index)->getMt1_Score() << ' ';
            cout << CourseName.getStudent(index)->getMt2_Score() << ' ';
            cout << CourseName.getStudent(index)->getFinal_Score() << ' ';
            cout << fixed << setprecision(2) << CourseName.Overall(index) << endl;
        }
	}
	if (found == 0) //If no students found print out an error
	{
        cout << "No student with grades below this value!" << endl;
	}
	return;
}

void showAverage(Course &CourseName)
{
    if (CourseName.getNum() == 0)
	{
		cout << "No registered students!" << endl;
		return;
	}
	CourseName.calcAverage();
	return;
}

void updateStudentScore(int Score,Course &CourseName,int index,char* Type)
{   //Most used writing styles were used to compare with the Type to determine the exam.
	if((strcmp(Type,MT1) == 0) || (strcmp(Type,Mt1) == 0) || (strcmp(Type,mt1) == 0) || (strcmp(Type,mT1) == 0))
	{
        CourseName.getStudent(index)->setMt1_Score(Score);
	} else if((strcmp(Type,MT2) == 0) || (strcmp(Type,Mt2) == 0) || (strcmp(Type,mt2) == 0) || (strcmp(Type,mT2) == 0))
	{
        CourseName.getStudent(index)->setMt2_Score(Score);
	} else if((strcmp(Type,FINAL) == 0) || (strcmp(Type,Final) == 0) || (strcmp(Type,final) == 0))
	{
        CourseName.getStudent(index)->setFinal_Score(Score);
	} else
	{
	    cout << "Check the spelling of the exam name!"<< endl;
	}
	return;
}
