#include <iostream>
#include <vector>
#include <iomanip>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

void HourlyEmployee::calculate_net_pay()
{
    set_net_pay(wage_rate_ * hours_);
}

void SalariedEmployee::calculate_net_pay()
{
    set_net_pay(salary_);
}

void read_hours_worked(vector<Employee *> &employees)
{
    for ( Employee* temp : employees){
        HourlyEmployee* worker = dynamic_cast<HourlyEmployee*>(temp); 
        if ( worker != nullptr){
            double temp2;
            cin >> temp2;
            worker->set_hours(temp2);
        }
    }
}

void calculate_pay(vector<Employee *> &employees)
{
    for ( Employee* temp : employees){
        temp->calculate_net_pay();
    }
}

void print_checks(const vector<Employee *> &employees)
{
    cout << "| ";
    for ( Employee* temp : employees){
        HourlyEmployee* hourly = dynamic_cast<HourlyEmployee*>(temp);
        SalariedEmployee* salary = dynamic_cast<SalariedEmployee*>(temp); 
        if ( hourly != nullptr){
            cout << fixed << setprecision(2) << temp->get_name() << ":HE(" << hourly->get_hours() << "," << hourly->get_rate() << ")=" << temp->get_net_pay() << " | ";
        }else if(salary != nullptr){
            cout << fixed << setprecision(2) << temp->get_name() << ":SE(" << salary->get_salary() << ")=" << temp->get_net_pay() << " | ";
        }
    }
}
