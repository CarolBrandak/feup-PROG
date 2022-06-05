#include <iostream>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

void HourlyEmployee::calculate_net_pay()
{
    Employee::set_net_pay(wage_rate_ * hours_);
}

void SalariedEmployee::calculate_net_pay()
{
    Employee::set_net_pay(salary_);
}

void read_hours_worked(vector<Employee *> &employees)
{
}

void calculate_pay(vector<Employee *> &employees)
{
}

void print_checks(const vector<Employee *> &employees)
{
}
