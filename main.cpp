#include <iostream>
#include <string>
using namespace std;

#include "problem3.hpp"

int main() {
	int numEmployees;
	char* tempName;
	string tempBirthdate;
	char* tempCompany;
	string tempTitle;
	string tempID;
	string tempType;
	int tempSalary;
	
	cout << "Enter the number of Employees: ";
	cin >> numEmployees;
	cout << endl;

	for(int i = 0; i < numEmployees; i++) {
		cout << "Enter the following information for Employee number " << i+1 << endl;
		cout << "Name: ";
		cin >> tempName;
		cout << "Birth Date: ";
		cin >> tempBirthdate;
		cout << "ID: ";
		cin >> tempID;
		cout << "Title: ";
		cin >> tempTitle;
		cout << "Company: ";
		cin >> tempCompany;
		cout << "Employee Type (Salaried, Commission, or Hourly): ";
		cin >> tempType;
		cout << "Annual Salary: $";
		cin >> tempSalary;
		cout << endl;
		/*if(tempType == "Salaried") {
			// make new salaried employee
		}*/

		Employee employee1("40", "Engineering", "Apple", CommissionEmployee);
		employee1.setFName("John");
		employee1.setBirthdate("December 31, 2001");
		cout << employee1.getFName() << " " << employee1.getBirthdate();
		
	}
	
}