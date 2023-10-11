#include "EmployeeBenifits.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  // Create instances of Professional and Nonprofessional employees
  Professional profEmployee("John Doe", 101, 5000.0, 10);
  Nonprofessional nonProfEmployee("Jane Smith", 102, 15.0, 40.0, 20);

  // Display information and calculate weekly salary, health care contributions,
  // and vacation days
  cout << "Professional Employee Information:" << endl;
  profEmployee.displayInfo();
  cout << "Weekly Salary: $" << profEmployee.calculateWeeklySalary() << endl;
  cout << "Health Care Contributions: $"
       << profEmployee.calculateHealthCareContributions() << endl;
  cout << "Vacation Days Earned: " << profEmployee.calculateVacationDays()
       << " days" << std::endl;

  cout << "\nNonprofessional Employee Information:" << endl;
  nonProfEmployee.displayInfo();
  cout << "Weekly Salary: $" << nonProfEmployee.calculateWeeklySalary() << endl;
  cout << "Health Care Contributions: $"
       << nonProfEmployee.calculateHealthCareContributions() << endl;
  cout << "Vacation Days Earned: " << nonProfEmployee.calculateVacationDays()
       << " days" << endl;

  return 0;
}
