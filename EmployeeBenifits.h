#ifndef EMPLOYEEBENIFITS_H
#define EMPLOYEEBENIFITS_H

#include <iostream>

// Abstract base class Employee
class Employee {
protected:
  std::string name;
  int employeeId;

public:
  Employee(const std::string &_name, int _employeeId)
      : name(_name), employeeId(_employeeId) {}

  virtual double calculateWeeklySalary() const = 0; // Pure virtual function
  virtual double
  calculateHealthCareContributions() const = 0;  // Pure virtual function
  virtual int calculateVacationDays() const = 0; // Pure virtual function

  void displayInfo() const {
    std::cout << "Employee ID: " << employeeId << "\nName: " << name
              << std::endl;
  }
};

class Professional : public Employee {
private:
  double monthlySalary;
  int vacationDaysPerMonth;

public:
  Professional(const std::string &_name, int _employeeId, double _monthlySalary,
               int _vacationDaysPerMonth)
      : Employee(_name, _employeeId), monthlySalary(_monthlySalary),
        vacationDaysPerMonth(_vacationDaysPerMonth) {}

  double calculateWeeklySalary() {
    // Assuming a month has 4 weeks for simplicity
    return (monthlySalary / 4.0);
  }

  double calculateHealthCareContributions() {
    // Example: 5% of monthly salary
    return (0.05 * monthlySalary);
  }
  int calculateVacationDays() {
    return (vacationDaysPerMonth / 4); // Assuming 4 weeks in a month
  }
};

class Nonprofessional : public Employee {
private:
  double hourlyRate;
  double hoursWorked;
  int vacationHoursPerWeek;

public:
  Nonprofessional(const std::string &_name, int _employeeId, double _hourlyRate,
                  double _hoursWorked, int _vacationHoursPerWeek)
      : Employee(_name, _employeeId), hourlyRate(_hourlyRate),
        hoursWorked(_hoursWorked), vacationHoursPerWeek(_vacationHoursPerWeek) {
  }

  double calculateWeeklySalary();

  double calculateHealthCareContributions();

  int calculateVacationDays();
};

#endif
