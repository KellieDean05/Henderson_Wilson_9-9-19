/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan 
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
#include <cmath>
#include <iomanip>
using namespace std;
void showMenu(); // function prototype
void workSelection(char); // function prototype
void welcomeMessage (); // function prototype
double calcAreaCircle(double);
double calcAreaRectangle(double, double); // 2 parameters
double calcAreaTriangle(double,double);



void welcomeMessage ()
  {
    for(int i = 0; i <= 1;i++)
    cout << "\x1b[91;16mAre you ready to Area?!\x1b[0m\n" << endl;
  }

int main()
{
  cout << fixed << setprecision(3);
	// a program to practice functions and user-menus
  // with char input. 
  // Kellie Henderson, Dr_T. 8-09-2019

  char option = '\0'; // menu options of the user.
  do
  {
  showMenu();
  welcomeMessage();
  option = validateChar(option);
  workSelection(option); // based on the user input, select a menu item  
  }
while (option != '5');  
    
    return 0;
}
// Function Definition
void showMenu()
{
cout << "\n\x1b[36;4mChoose from the following menu options:\x1b[0m\n" << endl;
cout << "1 = Area of Triangle" << endl;
cout << "2 = Area of Rectangle" << endl;
cout << "3 = Area of Circle" << endl;
cout << "4 = clear the screen" << endl;
cout << "5 = EXIT" << endl;
cout << "Selection: " << endl;
}

void workSelection(char selection)
{
  double radius = 0.0, s1 = 0.0, s2 = 0.0, h = 0.0, b = 0.0;
  if(selection == '3')
   {
      cout << "\nIt's Circle time!" << endl;
      cout << "\nPlease enter a radius." << endl;
      radius = validateDouble (radius);
    // call function to calculate area of circle
    cout << "\nCircle area with radius of: " << radius << " is "<<calcAreaCircle(radius) << endl;
   }

    else if (selection == '2')
  {
    cout << "\nIt's Rectangle time!" << endl;
    cout << "\nPlease enter a side 1 : " << endl;
      radius = validateDouble (s1);
        cout << "\nPlease enter side 2 : " << endl;
      radius = validateDouble (s2);
    // call the function to calculate the area of the Rectangle
    cout << "\nRectangle area with sides( " << s1 << " , " << s2 << " )"; cout << "is \x1b[93;4m " << calcAreaRectangle(s1,s2) << "\x1b[0m\n";
    
  }
  
  else if (selection == '1')
  {
    cout << "\n It's TriAngel time!" << endl;
    cout << "\nPlease enter the height: ";
    h = validateDouble(radius);
    cout << "\nPlease enter the base: ";
    b = validateDouble(radius);
    cout << "\nTriangle area with the height is: " << h << " and the base is: " << b << " \nwith these two the area of the Triangle is: " << calcAreaTriangle(h,b) << endl; 
    // call the function to calculate the area of a Triangle
  }
  else if (selection == '4')
   { 
   // clear the screen
   cout << system("cls");
   }
   else if (selection == '5')
   {
     cout << "\nKeep the change you filthy animal." << endl;
   }
   else // default clause
   {
     cout << "\nSomething went wrong!" << endl; 
   }
}

double calcAreaCircle(double r)
  { const double PI = 3.14;
  return (2.0* PI * pow(r,2.0) );


  } 
double calcAreaRectangle(double s1, double s2)
  {
    return ( (s1 * s2) / 2.0);

  } 
  
double calcAreaTriangle(double h, double b)
{
  return( (h * b) / 2.0);
}
