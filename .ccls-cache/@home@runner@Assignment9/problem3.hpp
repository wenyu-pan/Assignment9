#include <iostream>
#include <string>
using namespace std;


class Person {
private:
    char* fName;
    string birthdate;

public:
    Person() {
        fName = NULL;
        birthdate = "";
    }

public:
    Person(char* fn, string bd) {
        fName = fn;
        birthdate = bd;
    }

    ~Person(){}

public:
    char * fNameGetter() {
        return this->fName;
    }

		void setFName(char * givenName) {
			this->fName = givenName;
		}

    string birthdateGetter() {
        return this->birthdate;
    }

		void setBirthdate(string givenBirthdate) {
			this->birthdate = givenBirthdate;
		}


};

enum class EmployeeType{
    HourlyEmployee,
    CommissionEmployee
};

class Employee : public Person {
private:
    string employeeID;
    string jobTitle;
    char * company;
    EmployeeType type;

public:
    Employee() {
        this->employeeID = "";
        this->jobTitle = "";
        this->company = NULL;
        this->type = EmployeeType::HourlyEmployee;
    }

public:
    Employee(string eid, string jb, char * company, EmployeeType t) {
        this->employeeID = eid;
        this->jobTitle = jb;
        this->company = company;
        this->type = t;
    }

    ~Employee(){}


public:
    void setEmployeeID(string givenID) {
			this->employeeID = givenID;
		}

    string jobTitleGetter() {
        return this->jobTitle;
    }

		void setJobTitle(string givenTitle) {
			this->jobTitle = givenTitle;
		}

    string employIDGetter() {
        return this->employeeID;
    }

    char * companyGetter() {
        return this->company;
    }

		void setCompany(char * givenCompany) {
			this->company = givenCompany;
		}

    EmployeeType employeeTypeGetter() {
        return this->type;
    }

		void setEmployeeType(EmployeeType givenType) {
			this->type = givenType;
		}

    //pure virtual function, defined in the specific subclass
    virtual double getAnnualSalary() = 0;

    virtual std::ostream & operator<<(std::ostream &output) = 0;

    // compares the given employee to the current employee to check whose salary is larger
    virtual int operator==(Employee & e) = 0;
};

// class for a SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double basePay;

public:
    SalariedEmployee() {
        this->basePay = 0;
    }

    SalariedEmployee(double bp) {
        this->basePay = bp;
    }

    ~SalariedEmployee(){}



    double getBasePay() {
        return this->basePay;
    }

		void setBasePay(double pay) {
			this->basePay = pay;
		}


    // gets the current SalariedEmployee's annual salary with the basePay
    virtual double getAnnualSalary() {
        return basePay;
    }

    virtual std::ostream & operator<<(std::ostream &output) {
        output << this->employIDGetter() << ": " << this->getAnnualSalary() << endl;
      return output;
    }

    // compares the given employee to the current employee to check whose salary is larger
    virtual int operator==(Employee & e) {
        return (this->getAnnualSalary() - e.getAnnualSalary());
    }


};

// class for a CommissionEmployee
class CommissionEmployee : public SalariedEmployee {
private:
    double salesTotal, commissionPercentage;

public:
    CommissionEmployee() {
        this->salesTotal = 0;
        this->commissionPercentage = 0;
    }

    CommissionEmployee(double st, double cp) {
        this->salesTotal = st;
        this->commissionPercentage = cp;
    }

    ~CommissionEmployee(){}

    // getter method to return salesTotal
    double salesTotalGetter() {
        return salesTotal;
    }

    // getter method to return commissionPercentage
    double getCommissionPercentage() {
        return commissionPercentage;
    }

    // gets the current CommissionEmployee's annual salary with the basePay
    double getAnnualSalary() {
        return this->getBasePay() + (getCommissionPercentage() * salesTotal);
    }

     std::ostream & operator<<(std::ostream &output) {
        output << this->employIDGetter() << ": " << this->getAnnualSalary() << endl;
      return output;
    }

    // compares the given employee to the current employee to check whose salary is larger
    int operator==(Employee & e) {
        return (this->getAnnualSalary() - e.getAnnualSalary());
    }

};


class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int numberOfHoursPerWeek;

public:
    HourlyEmployee() {
        this->hourlyRate = 0;
        this->numberOfHoursPerWeek = 0;
    }

public:
    HourlyEmployee(double hourlyRate, int numberOfHoursPerWeek) {
        this->hourlyRate = hourlyRate;
        this->numberOfHoursPerWeek = numberOfHoursPerWeek;
    }

public:

    ~HourlyEmployee(){}

public:
    double getHourlyRate() {
        return this->hourlyRate;
    }

public:
     std::ostream & operator<<(std::ostream &output) {
        output << this->employIDGetter() << ": " << this->getAnnualSalary() << endl;
      return output;
    }

public:
    // compares the given employee to the current employee to check whose salary is larger
    int operator==(Employee & e) {
        return (this->getAnnualSalary() - e.getAnnualSalary());
    }

public:
double getAnnualSalary() {
  return this->hourlyRate * this->numberOfHoursPerWeek;
}


    //main
    //create a vector
    //create a pointer to the employee
    //delete each employee instead of the vector
    //use sort for sorting


};