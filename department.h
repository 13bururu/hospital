#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "patient.h"
#include "doctor.h"
#include <string>
#include <vector>
#include <iostream>

class Department {
private:
    std::string name;
    int place;
    int freeplace;
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;

public:
    Department();
    Department(std::string name_, int place_, int freeplace_);
    std::string getname() const;
    int getplace() const;
    int getfreeplace() const;
    const std::vector<Doctor>& getdoctors() const; 
    std::vector<Doctor>& getdoctors(); 
    const std::vector<Patient>& getpatients() const;
    void setname(std::string name_);
    void setplace(int place_);
    void setfreeplace(int freeplace_);
    void addDoctor(const Doctor& doctor);
    void removeDoctor(const std::string& doctorName);
    void addPatient(const Patient& patient);
    void removePatient(const std::string& patientName);
    friend std::ostream& operator<<(std::ostream& out, const Department& department);
    friend std::istream& operator>>(std::istream& in, Department& department);
};

#endif
