#include "Employee.h"
using namespace std;

const float Employee::TAX = 0.1f; 

void Employee::Read() {
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter zipcode: ";
    cin >> zipcode;

    cout << "Enter hourly wage: ";
    cin >> wage;

    cout << "Enter total hours worked this week: ";
    cin >> hoursWorked;
}

void Employee::Write() {
    float weeklyGross = wage * hoursWorked;
    float weeklyTax = weeklyGross * TAX;
    float weeklyNet = weeklyGross - weeklyTax;
    float yearlyGross = weeklyGross * 52;
    float yearlyNet = yearlyGross - (yearlyGross * TAX);

    cout << "\nEmployee Payroll Summary\n";
    cout << "-------------------------\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Zipcode: " << zipcode << "\n";
    cout << "Hourly Wage: $" << wage << "\n";
    cout << "Hours Worked: " << hoursWorked << "\n";
    cout << "Weekly Gross Pay: $" << weeklyGross << "\n";
    cout << "Weekly Net Pay: $" << weeklyNet << "\n";
    cout << "Yearly Gross Pay: $" << yearlyGross << "\n";
    cout << "Yearly Net Pay: $" << yearlyNet << "\n";
}