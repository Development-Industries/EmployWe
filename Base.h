#ifndef BASE_H
#define BASE_H

#include <cstring>
#include <iostream>

class Base {
private:
    char* name;

public:
    Base() : name(nullptr) {}

    Base(const Base& other) {
        name = nullptr;
        *this = other;  // Use the assignment operator to copy
    }

    Base& operator=(const Base& other) {
        if (this != &other) {
            delete[] name;
            if (other.name) {
                size_t length = strlen(other.name) + 1;
                name = new char[length];
                strcpy_s(name, length, other.name); // Replaced with MS recc version
            }
            else {
                name = nullptr;
            }
        }
        return *this;
    }

    virtual ~Base() {
        delete[] name;
    }

    void SetName(const char* newName) {
        delete[] name;
        if (newName) {
            size_t length = strlen(newName) + 1;
            name = new char[length];
            strcpy_s(name, length, newName); //Replaced with Microsoft recc version
        }
        else {
            name = nullptr;
        }
    }

    const char* GetName() const {
        return name;
    }

    virtual void DisplayRecord() const = 0; // Pure virtual function
};

#endif // BASE_H
