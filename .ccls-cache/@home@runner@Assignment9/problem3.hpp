#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
    char* fName;
    string birthdate;

public:
    Person() {
        fName = NULL;
        birthdate = "";

    }

    Person(char* fn, string bd) {
        fName = fn;
        birthdate = bd;
    }

    ~Person(){}

    char * getFName() {
        return this->fName;
    }

		void setFName(char * givenName) {
			this->fName = givenName;
		}

    string getBirthdate() {
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
protected:
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

    Employee(string eid, string jb, char * company, EmployeeType t) {
        this->employeeID = eid;
        this->jobTitle = jb;
        this->company = company;
        this->type = t;
    }

    ~Employee(){}

    string getEmployeeID() {
        return this->employeeID;
    }

		void setEmployeeID(string givenID) {
			this->employeeID = givenID;
		}

    string jobTitleGetter() {
        return this->jobTitle;
    }

		void setTitle(string givenTitle) {
			this->jobTitle = givenTitle;
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

    virtual double getAnnualSalary(); // defined as header, no information ??????????????????????????????????????????/

		//finish this ***************************************
		string toString() {
			
		}

    std::ostream & operator<<(std::ostream &output) {
        output << this->toString() << endl;
    }

		// compares the given employee to the current employee to check whose salary is larger
    bool operator==(Employee & obj) {
			if (this->getAnnualSalary() > obj.getAnnualSalary()) {
				return true;
			}
			else if (this->getAnnualSalary() < obj.getAnnualSalary()) {
				return false;
			}
			else {
				return false;
			}
    }
};

// class for a SalariedEmployee
class SalariedEmployee : public Employee {
	protected:
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
			return basePay;
		}

		// gets the current SalariedEmployee's annual salary with the basePay
		double getAnnualSalary() {
			return basePay;
		}


		std::ostream & operator<<(std::ostream &output) {
        output << this->getEmployeeID() << ": " << this->getAnnualSalary() << endl;
			}

  	bool operator==(Employee & obj); // no overriding necessary??????????????
};

// class for a CommissionEmployee
class CommissionEmployee : public SalariedEmployee {
	protected:
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
		double getSalesTotal() {
			return salesTotal;
		}

		// getter method to return commissionPercentage
		double getCommissionPercentage() {
			return commissionPercentage;
		}

		// gets the current CommissionEmployee's annual salary with the basePay
		double getAnnualSalary() {
			return getBasePay() + (commissionPercentage * salesTotal);
		}

		// operator<<

		//bool operator==(Employee & obj); // no overriding necessary??????????????
};

// class for a HourlyEmployee
class HourlyEmployee : public Employee {
	protected:
		double hourlyRate;
		int numHoursPerWeek;

	public:
		HourlyEmployee() {
			this->hourlyRate = 0;
			this->numHoursPerWeek = 0;
		}

		HourlyEmployee(double hr, int hours) {
			this->hourlyRate = hr;
			this->numHoursPerWeek = hours;
		}

		~HourlyEmployee(){}

		// getter function to return hourlyRate
		double getHourlyRate() {
			return hourlyRate;
		}

		// getter function to return numHoursPerWeek
		int getNumHoursPerWeek() {
			return numHoursPerWeek;
		}

		// gets the current HourlyEmployee's annual salary with the basePay
		double getAnnualSalary() {
			return (numHoursPerWeek * hourlyRate)*52;
		}

		// operator<<
};




