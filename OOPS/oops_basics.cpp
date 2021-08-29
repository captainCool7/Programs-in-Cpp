#include <iostream>
using namespace std;

//----------------------------------------------------------------
//Abstration Class
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : AbstractEmployee
{
private:
    string Name;
    string Company;
    int Age;

public:
    //delegate constructor :- also known as constructor chaining
    //calling the param constructor from default constructor
    Employee() : Employee("Not Given", "Not Given", -1) {}
    Employee(string Name, string Company, int Age)
    {
        this->Name = Name;
        this->Company = Company;
        this->Age = Age;
    }

    void AskForPromotion()
    {
        if (Age > 30)
            cout << Name << " got promoted!!!" << endl;
        else
            cout << "You are not elegible for promotion" << endl;
    }

    //Encapsulation
    //setter
    void setName(string Name) { this->Name = Name; }
    void setCompany(string Company) { this->Company = Company; }
    void setAge(int Age) { this->Age = Age; }

    //getter
    string getName() { return this->Name; }
    string getCompany() { return this->Company; }
    int getAge() { return this->Age; }

    void sayHello()
    {
        cout << "I am " << Name << " from " << Company;
    }
};
int main()
{
    Employee e1 = Employee("Rosta", "Posche", 28);
    // Employee e2 = Employee();
    Employee e2 = Employee("Castry", "RomeWork", 35);
    e1.AskForPromotion();
    e2.AskForPromotion();
    return 0;
}