#include <iostream>
class Person
{
protected:
    char name[40];
public:
    void getName()
    {
        std::cout << "    Enter name: ";
        std::cin >> name;
    }
    void putName()
    {
        std::cout << "Name is: " << name << std::endl;
    }
    virtual void getData() = 0;             // pure virtual function
    virtual bool isOutstanding() = 0;       // pure virtual function
};
class Student : public Person
{
private:
    double gpa;                             // grade point average
public:
    void getData()                          // get student data from user
    {
        Person::getName();
        std::cout << "  Enter student's GPA: ";
        std::cin >> gpa;
    }
    bool isOutstanding()
    {
        return gpa > 3.5;
        // return (gpa > 3.5) ? true : false; // <- this was book version
    }
};

class Professor : public Person
{
private:
    int numberPublications;                 // number of publications
public:
    void getData()                          // get professor data from user
    {
        Person::getName();
        std::cout << "  Enter number of publications: ";
        std::cin >> numberPublications;
    }
    bool isOutstanding()
    {
        return numberPublications > 100;
        //return (numberPublications > 100) ? true : false; // <- this is book version
    }
};

int main() {
    Person* personPtr[100];                 // array of pointers to person
    int n = 0;
    char choice;

    do {
        std::cout << "Enter student or professor (s/p): ";
        std::cin >> choice;
        if (choice == 's')                   // put new student
        personPtr[n] = new Student;          // in array
        else
            personPtr[n] = new Professor;    // put new professor in array

        personPtr[n++]->getData();          // get data for person
        std::cout << "  Enter another (y/n): ";     // add another person
        std::cin >> choice;
    }while (choice == 'y');                 // cycle till answer is y

    for (int i = 0; i < n ; i++)
    {
        personPtr[i]->putName();
        if (personPtr[i]->isOutstanding())
            std::cout << "  This person is outstanding!";

    }

    system("pause");
    return 0;
}