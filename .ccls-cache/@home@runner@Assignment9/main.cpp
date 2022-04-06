include <iostream>
#include "Problem3.hpp"
using namespace std;


int main() {
    cout << "Enter the number of Employees: " << endl;
    string s1;
    cin >> s1;
    int number_of_employes = stoi(s1);

    int counter = 1;
    Employee *list[number_of_employes];


    while (counter <= number_of_employes) {
        cout << "Enter the following information for Employee number" << to_string(counter) << ": " << endl;
        cout << "Name: " << endl;
        string name_1;
        cin >> name_1;

        cout << "Birthdate: " << endl;
        string birthdate_1;
        cin >> birthdate_1;

        cout << "Company: " << endl;
        string company_1;
        cin >> company_1;

        cout << "Title: " << endl;
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
            double hourly_rate = stoi(number);

            string number2;
            cout << " Enter the number of Hours work per week" << endl;
            cin >> number;
            int number_of_hours_per_week = stoi(number2);
            list[counter] = new HourlyEmployee()


        }

        if (employ_type_1 == "Salaried") {

        }

    }
}
