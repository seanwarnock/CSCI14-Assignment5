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
0 Regular Pay (40 hours or less)
1 Overtime Pay if any (over 40 hours)
2 Gross Pay (Regular Pay plus Overtime if any)
3 Federal Taxes Withheld
4 State Taxes Withheld
5 Social Security Taxes Withheld (6.2% of Gross)
6 Medicare Taxes Withheld (1.45% of Gross)
7 Net Pay


Open program, allow user to enter payroll data or exit
  if payroll information is entered then allow user to selct what to calculate including exit.

*/

#include <time.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <cstring>
#ifdef _WIN32
  #include <winsock2.h>
  #include <windows.h>
#endif
#ifdef __linux__

#endif

using namespace std;

void EmployeeDataInput (string &, string &, float &, float &, float &, float &);
float PayCalculater (float, float, float, float, short);

int main()
{
  char charMenuChoice;
  string stringEmployeeName = "AAAA AAAA";
  string stringEmployeeID = "AAAA";
  float floatHour = 40.00;
  float floatPayrate = 10.0;
  float floatFedTaxRate = .1;
  float floatStateTaxRate = .10;




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
          // Just enter the
          EmployeeDataInput(stringEmployeeName, stringEmployeeID, floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate);
          break;
        case '2' :
          // Call calculate @#$%  But the output has to come from main.
          cout  << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 7) << endl;
          break;
        case '9' :
          //If there is anything for cleanup call it here but really just fall out.
          break;
      }
    //cout << (int)charMenuChoice;
    system("pause");
  } while (charMenuChoice != '9');

}


void EmployeeDataInput (string &Name, string &ID, float &Hours, float &PayRate, float &FedTax, float &StateTax)
{
/*
Thread safety out the window.
So I cheated on this function and treated it like a Pascal procedure.
This function takes all user input and returns it to the main program.
*/
  system("cls");
char Test[80];

  cin.ignore();
  cout << "Emplyees full name : ";
  cin.getline(Test,80);
  Name = Test;
  cout << "Name Variable: " << Name;

  cout  << "Employee ID : ";
  cin.getline(Test,80);
  ID = Test;
  //cin.ignore();

  cout << "Enter employee hours worked (up to 60 hours): ";
  cin >> Hours;
  cin.ignore();

  cout << "Enter employee hourly pay rate : ";
  cin >> PayRate;
  cin.ignore();

  cout << "Enter the Federal Tax rate (up to 50%): ";
  cin >> FedTax;
cin.ignore();

  cout << "Enter the State Tax rate (up to 30%): ";
  cin >> StateTax;
  cin.ignore();
}


float PayCalculater (float hours, float payrate, float fedtaxrate, float statetaxrate, short responsetype)
{
/*
This function will calculate one of the requested pay functions and return
it's value.
*/
  const short shortRegularPayHours = 40; //Default value for regular hours.
  const float floatOvertimeRate = 1.5;   //Default overtime pay rate.
  const float floatSocialSecurityTax = .062;
  const float floatMeicareTax = .0145;
  float floatGrossPay;
  float floatNetPay;

  //Awesome logic error in action.
  //cout << "can I output Gross Pay" << floatGrossPay;
  //floatGrossPay = (PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1));
  switch (responsetype)
  {
    case 0 :
      {
        //This calculates regular time pay.
        if (hours > shortRegularPayHours)
          {
            return (shortRegularPayHours * payrate);
          }
          else
          {
            return (hours * payrate);
          }
        break;
      }
    case 1 :
      {
        //This calculates overtime pay.
        if (hours > shortRegularPayHours)
          {
            return ((hours - shortRegularPayHours) * payrate * floatOvertimeRate);
          }
          else
          {
            return 0;
          }
        break;
      }
    case 2 :
      {
        //This calculates  overtime pay and regular time pay.  Lets go for recursion on this one.
        return (PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1));
        break;
      }
    case 3 :
      {
        //This returns the Federal Taxes Withheld
        return ((PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1)) * fedtaxrate);
        break;
      }
    case 4 :
      {
          //This returns the State Taxes Withheld
        return ((PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1)) * statetaxrate);
        break;
      }
    case 5 :
      {
        //This returns the Social Security Taxes Withheld (6.2% of Gross)
        return ((PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1)) * floatSocialSecurityTax);
        break;
      }
    case 6 :
      {
        // This returns the Medicare taxes withheld (1.45% of Gross
        return ((PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1)) * floatMeicareTax);
        break;
      }
    case 7 :
      {
        // This returns the net pay.
        floatGrossPay = (PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 0) + PayCalculater(hours, payrate, fedtaxrate, statetaxrate, 1));
        floatNetPay = floatGrossPay;
        floatNetPay += floatGrossPay * fedtaxrate;
        floatNetPay += floatGrossPay * statetaxrate;
        floatNetPay += floatGrossPay * floatSocialSecurityTax;
        floatNetPay += floatGrossPay * floatMeicareTax;
        return floatNetPay;
        break;
      }
    default :
      {
        //Basically an error condition.
        return 0;
      }


  }
}
