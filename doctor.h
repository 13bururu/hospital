#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <iostream>

class Doctor {
private:
    std::string name;
    std::string spec;

public:
    Doctor(std::string name_, std::string spec_);
    std::string getname() const;
    std::string getspec() const;
    void setname(std::string name_);
    void setspec(std::string spec_);
    friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);
    friend std::istream& operator>>(std::istream& in, Doctor& doctor);
};

#endif