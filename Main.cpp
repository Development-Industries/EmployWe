#include <iostream>
#include <vector>
#include "Base.h"
#include "Employee.h"
#include "Student.h"
#include <string>


void AddRecord(std::vector<Base*>& v);
void DisplayRecords(const std::vector<Base*>& v);
void DuplicateRecord(std::vector<Base*>& v);

int main() {
    std::vector<Base*> records;
    int choice = 0;

    do {
        std::cout << "Menu:\n1. Add Record\n2. Display All Records\n3. Duplicate Record\n4. Exit\nChoose an option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            AddRecord(records);
            break;
        case 2:
            DisplayRecords(records);
            break;
        case 3:
            DuplicateRecord(records);
            break;
        case 4:
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 4);

    // Clean up memory
    for (Base* record : records) {
        delete record;
    }

    return 0;
}

void AddRecord(std::vector<Base*>& v) {
    int type;
    std::cout << "Select type to add (1: Employee, 2: Student): ";
    std::cin >> type;

    Base* newRecord = nullptr;

    if (type == 1) {
        newRecord = new Employee();
        std::string name;
        int salary;
        std::cout << "Enter Employee Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Salary: ";
        std::cin >> salary;
        newRecord->SetName(name.c_str());
        static_cast<Employee*>(newRecord)->SetSalary(salary);
    }
    else if (type == 2) {
        newRecord = new Student();
        std::string name;
        float gpa;
        std::cout << "Enter Student Name: ";
        std::cin.ignore();
        std::getline(std::cin, name); 
        std::cout << "Enter GPA: ";
        std::cin >> gpa;
        newRecord->SetName(name.c_str());
        static_cast<Student*>(newRecord)->SetGPA(gpa);
    }
    else {
        std::cout << "Invalid type selected." << std::endl;
        return;
    }

    v.push_back(newRecord);
}

void DisplayRecords(const std::vector<Base*>& v) {
    for (const Base* record : v) {
        record->DisplayRecord();
    }
}

void DuplicateRecord(std::vector<Base*>& v) {
    int index;
    std::cout << "Enter the index of the record to duplicate: ";
    std::cin >> index;

    if (index < 0 || index >= v.size()) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    Base* original = v[index];
    Base* duplicate = nullptr;

    if (dynamic_cast<Employee*>(original)) {
        duplicate = new Employee(*dynamic_cast<Employee*>(original));
    }
    else if (dynamic_cast<Student*>(original)) {
        duplicate = new Student(*dynamic_cast<Student*>(original));
    }

    if (duplicate) {
        v.push_back(duplicate);
    }
}
