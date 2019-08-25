#include <iostream>
#include <string.h>
#include <iomanip>
#include "student.h" //Student header is provided since the course creates its' Student class member array. 

using namespace std;

const int MAX_SIZE = 10;
// class declaration 
class Course
{
	private:
		
		Student entries[MAX_SIZE];
		int num;
		int weight_mt1;
		int weight_mt2;
		int weight_final;
	public:
		Course(int Weight_mt1 = 25,int Weight_mt2 = 25,int Weight_final = 50); //Assign default weights if not specified 
		int getNum(void);
		void addStudent(void);
		void changeWeights(int Weight_mt1,int Weight_mt2,int Weight_final);
		Student* getStudent(int index);
		void calcAverage(void);
        float Overall(int index);
};
