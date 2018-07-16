/*
Sean Warnock
CSCI 14 Summer 2018
Assignment 5 due 7/19/2018
https://github.com/seanwarnock/CSCI14-Assignment5.git


Employee Full name
Employee ID
Hours Worked (maximum 60 hours)
Pay Rate for this employee
Federal Tax Rate (maximum 0. or 50%)
State Tax Rate (maximum 0.3 or 30%)

In this assignment, we will use a function to compute:
Regular Pay (40 hours or less)
Overtime Pay if any (over 40 hours)
Gross Pay (Regular Pay plus Overtime if any)
Federal Taxes Witheld
State WTaxes Withheld
Social Security Taxes Witheld (6.2% of Gross)
Medicare Taxes Withheld (1.45% of Gross)
Net Pay


Open program, allow user to enter payroll data or exit
  if payroll information is entered then allow user to selct what to calculate including exit.

*/

#include <time.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#ifdef _WIN32
  #include <winsock2.h>
  #include <windows.h>
#endif
#ifdef __linux__

#endif

using namespace std;

float PayCalculater (float, float, float, float, int);

int main()
{
  char charMenuChoice;

  do
  {
    system("cls");
      cout << "[1] Enter Employee data?" << endl;
      cout << "[2] Calculate Employee payroll?" << endl;
      cout << "[9] Exit" << endl;
      cin >> charMenuChoice;

      switch (charMenuChoice)
      {
        case '1' :
          // Call payroll enter
          break;
        case '2' :
          // Call calculate @#$%  But the output has to come from main.
          break;
        case '9' :
          //If there is anything for cleanup call it here but really just fall out.
          break;
      }
    cout << (int)charMenuChoice;
    system("pause");
  } while (charMenuChoice != '9');

}

float PayCalculater (float hours, float payrate, float fedtaxrate, float statetaxrate, int responsetype)
{
/*
This function will calculate one of the requested pay functions and return
it's value.
*/

}
