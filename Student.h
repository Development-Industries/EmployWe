#ifndef STUDENT_H
#define STUDENT_H

#include "Base.h"

class Student : public Base {
private:
    float gpa;

public:
    Student() : gpa(0.0f) {}

    void SetGPA(float newGPA) {
        gpa = newGPA;
    }

    virtual void DisplayRecord() const override {
        std::cout << "Student Name: " << GetName() << ", GPA: " << gpa << std::endl;
    }
};

#endif // STUDENT_H
