#include <iostream>
#include <fstream>

using namespace std;

float calcAvgGrade(int grade[5])
{
  // (sizeof(grade) / sizeof()grade[0]) should give num elements according to google
  //changing it so there is a fix num of grades, 
  /*less flexible but I don't need to find the num of elements through sizeof which I don't really understand*/
  float avg=0;
  for(int i = 0; i <5; i++)
    {
       avg += grade[i];
    }
  return avg / 5;
}

float highestGrade(int grade[5])
{
  //finds max num in array 
  float max = -1.0;
  for(int i = 0; i < 5; i++)
    {
      if(grade[i] > max)
      {
        max = grade[i];
      }
    }
  return max;
}

int main() {
  ifstream grades("grades.txt");
  string line;
  string classNames[5];
  string name;
  int indivGrades[5] = {0, 0, 0, 0, 0};
  int classMaxGrades[5] = {0, 0, 0, 0, 0};
  int counter = 0;
  int classAvg = 0;
  while(getline(grades, line))
    {
      name = line.substr(0,line.find(','));
      line.erase(0, line.find(',') + 1);
      for (int i = 0; i < 5; i++)
      {
        indivGrades[i] = stoi(line.substr(0,line.find(',')));
        classAvg += stoi(line.substr(0,line.find(',')));
        line.erase(0,line.find(',') + 1);
        
      }
      cout << name << " Avg = " << calcAvgGrade(indivGrades) << " Highest grade = "<< highestGrade(indivGrades) << endl;
      classMaxGrades[counter] = highestGrade(indivGrades);
      classNames[counter] = name;
      counter++;
    }
cout << "Class average = " << classAvg / 25 << endl;
cout << "Highest grade in class = " << highestGrade(classMaxGrades) << endl;
}