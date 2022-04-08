#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include "problem3.hpp"
using namespace std;


int main() {
    cout << "Enter the number of Employees: " << endl;
    string s1;
    cin >> s1;
    int number_of_employes = stoi(s1);

    int counter = 0;
   vector<Employee *> list;

  for (int i = 0; i < number_of_employes; i ++) {
    Employee * newPointer = NULL;
    list.push_back(newPointer);
  }
 


    while (counter < number_of_employes) {
        cout << "Enter the following information for Employee number" << to_string(counter+1) << ": " << endl;
        cout << "Name: " << endl;
        string name_1;
        cin >> name_1;

        cout << "Birthdate: " << endl;
        string birthdate_1;
        cin >> birthdate_1;

        cout << "Company: " << endl;
        string company_1;
        cin >> company_1;

        cout << "Job Title: " << endl;
        string title_1;
        cin >> title_1;

        cout << "ID: " << endl;
        string id_1;
        cin >> id_1;

        cout << "Employee Type: " << endl;
        string employ_type_1;
        cin >> employ_type_1;

        if (employ_type_1 == "Hourly") {
            string number;
            cout << "Enter the hourly rate: " << endl;
            cin >> number;
            double hourly_rate = stod(number);

            string number2;
            cout << "Enter the number of Hours work per week: " << endl;
            cin >> number2;
            int number_of_hours_per_week = stoi(number2);

						// creating a new employee in the list of employees
						HourlyEmployee * newEmployee = new HourlyEmployee(hourly_rate, number_of_hours_per_week);
						// setting the fields for the current employee
						newEmployee->setFName(const_cast<char*>(name_1.c_str()));
						newEmployee->setBirthdate(birthdate_1);
						newEmployee->setCompany(const_cast<char*>(company_1.c_str()));
						newEmployee->setJobTitle(title_1);
						newEmployee->setEmployeeID(id_1);
						newEmployee->setEmployeeType(EmployeeType::HourlyEmployee);
						list[counter] = newEmployee;
        }

        else if (employ_type_1 == "Salaried") {
						double pay;
						cout << "Enter the base pay: " ;
						cin >> pay;

						// creating a new employee in the list of employees
            SalariedEmployee * newSalaried = new SalariedEmployee(pay);
						// setting the fields for the current employee
						newSalaried->setFName(const_cast<char*>(name_1.c_str()));
						newSalaried->setBirthdate(birthdate_1);
						newSalaried->setCompany(const_cast<char*>(company_1.c_str()));
						newSalaried->setJobTitle(title_1);
						newSalaried->setEmployeeID(id_1);
						newSalaried->setEmployeeType(EmployeeType::CommissionEmployee); // is this supposed to be salary??
          list[counter] = newSalaried;
        }

				else if (employ_type_1 == "Commission") {
						double sales, percent, pay;
						cout << "Enter the base pay: " ;
						cin >> pay;

						cout << "Enter the commission percentage: " ;
						cin >> percent;

						cout << "Enter the sales total: " ;
						cin >> sales;

						// creating a new employee in the list of employees
            CommissionEmployee * newEmployee = new CommissionEmployee(sales, percent);
						// setting the fields for the current employee
						newEmployee->setFName(const_cast<char*>(name_1.c_str()));
						newEmployee->setBirthdate(birthdate_1);
						newEmployee->setCompany(const_cast<char*>(company_1.c_str()));
						newEmployee->setJobTitle(title_1);
						newEmployee->setEmployeeID(id_1);
						newEmployee->setBasePay(pay);
						newEmployee->setEmployeeType(EmployeeType::CommissionEmployee);
          list[counter] = newEmployee;
        } // end of if-else statement for employee type
      counter = counter + 1;
      }

    

   std::sort(list.begin(), list.end(),[](Employee * x, Employee *y){
     if (* x == * y) {
       return true;
     }
     else {
       return false;
     }
   });
 

  for (int i = 0; i < number_of_employes; i ++) {
      //cout << list[i]->employIDGetter() << "salary: " << list[i]->getAnnualSalary() << endl;
    
    
  cout << * list[i] << endl;
    }
  }

  
  //for (int i = 0; i < number_of_employes; i ++) {
   // delete (list[i]);
  //}
//}


