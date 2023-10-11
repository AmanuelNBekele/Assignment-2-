#include "EmployeeBenifits.h"
#include <iostream>
#include <string>
using namespace std;

// Derived class Professional

// Derived class Nonprofessional

double Nonprofessional::calculateWeeklySalary() {
  return (hourlyRate * hoursWorked);
}

double Nonprofessional::calculateHealthCareContributions() {
  // Example: $50 per week
  return 50.0;
}

int Nonprofessional::calculateVacationDays() {
  return (vacationHoursPerWeek / 8); // Assuming 8 hours per day
}
