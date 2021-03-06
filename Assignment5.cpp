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
5 Security Taxes Withheld (6.2% of Gross)
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
          // If output MUST come from main then here we go.
          int intMenuChoice2;
          do
          {
              system("cls");
              cout << "[1] Gross Pay" << endl;
              cout << "[2] Federal Taxes Withhel @ %" << (floatFedTaxRate * 100)  << endl;
              cout << "[3] State Taxes Withheld @ %" << (floatStateTaxRate * 100) << endl;
              cout << "[4] Medicare Witheld" << endl;
              cout << "[5] Social Security Withheld" << endl;
              cout << "[6] Net Pay (Less all Deductions)" << endl;
              cout << "[7] Regular Pay on " << floatHour << " hours worked" << endl;
              cout << "[8] Overtime Pay on " << floatHour << " hours worked" << endl;
              cout << "[9] Total Pay" << endl;
              cout << "[10] Exit" << endl;
              cin >> intMenuChoice2;
              switch (intMenuChoice2)
              {
                case 1 :
                  cout << "Your total pay is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 2) << endl;
                  system ("pause");
                  break;
                case 2 :
                  cout << "Your Federal Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 3) << endl;
                  system ("pause");
                  break;
                case 3 :
                  cout << "Your State Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 4) << endl;
                  system ("pause");
                  break;
                case 4 :
                  cout << "Your Medicare Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 6) << endl;
                  system ("pause");
                  break;
                case 5 :
                  cout << "Your Social Security Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 5) << endl;
                  system ("pause");
                  break;
                case 6 :
                  cout << "Your Net Pay less deductions is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 7) << endl;
                  system("pause");
                  break;
                case 7 :
                  cout << "Your regular pay is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 0) << endl;
                  system("pause");
                  break;
                case 8 :
                  cout << "Your overtime pay is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 1) << endl;
                  system("pause");
                  break;
                case 9 :
                   cout << "Your regular pay is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 0) << endl;
                   cout << "Your overtime pay is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 1) << endl;
                   cout << "Your total pay is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 2) << endl;
                   cout << "Your Federal Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 3) << endl;
                   cout << "Your State Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 4) << endl;
                   cout << "Your Medicare Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 6) << endl;
                   cout << "Your Social Security Taxes withheld are $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 5) << endl;
                   cout << "Your Net Pay less deductions is $" << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 7) << endl;
                   system("pause");
                  break;
                case 10:
                  break;
              }


            }while (intMenuChoice2 != 10);
          //cout  << PayCalculater(floatHour, floatPayrate, floatFedTaxRate, floatStateTaxRate, 7) << endl;
          break;
        case '9' :
          //If there is anything for cleanup call it here but really just fall out.
          break;
      }
    //cout << (int)charMenuChoice;
    //system("pause");
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
  bool boolRangeChecker;

  cin.ignore();
  cout << "Emplyees full name : ";
  cin.getline(Test,80);
  Name = Test;

  cout  << "Employee ID : ";
  cin.getline(Test,80);
  ID = Test;


  boolRangeChecker = true;
  do
  {
    cout << "Enter employee hours worked (up to 60 hours): ";
    cin >> Hours;
    cin.ignore();
    if (!((Hours >= 0) && (Hours <= 60 )))
    {
      system("cls");
      cout << "You entered : " << Hours << " hours." << endl;
    }
    else
    {
      boolRangeChecker = false;
    }
  }while (boolRangeChecker == true);

  boolRangeChecker = true;
  do
  {
    cout << "Enter employee hourly pay rate ($10.75 - $99.99): ";
    cin >> PayRate;
    cin.ignore();
    if (!((PayRate >= 10.75) && (PayRate <= 99.99)))
    {
      system("cls");
      cout << "You entered : $" << PayRate << " per hour." << endl;
    }
    else
    {
      boolRangeChecker = false;
    }
  }while (boolRangeChecker == true);

  boolRangeChecker = true;
  do
  {
    cout << "Enter the Federal Tax rate (up to 50%): ";
    cin >> FedTax;
    cin.ignore();
    FedTax = FedTax / 100;
    if (!((FedTax >= 0) && (FedTax < .51)))// ran in to some rounding issues. Need a better way to solve this.
    {
      system("cls");
      cout << "You entered : %" << (FedTax * 100) << " for the Federal Tax rate." << endl;
    }
    else
    {
      boolRangeChecker = false;
    }
  }while (boolRangeChecker == true);

   boolRangeChecker = true;
  do
  {
    cout << "Enter the State Tax rate (up to 30%): ";
    cin >> StateTax;
    cin.ignore();
    StateTax = StateTax / 100;
    if (!((StateTax >= 0) && (StateTax < .31)))// ran in to some rounding issues. Need a better way to solve this.
    {
      system("cls");
      cout << "You entered : %" << (StateTax * 100) << " for the State Tax rate." << endl;
    }
    else
    {
      boolRangeChecker = false;
    }
  }while (boolRangeChecker == true);
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
        floatNetPay -= floatGrossPay * fedtaxrate;
        floatNetPay -= floatGrossPay * statetaxrate;
        floatNetPay -= floatGrossPay * floatSocialSecurityTax;
        floatNetPay -= floatGrossPay * floatMeicareTax;
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
