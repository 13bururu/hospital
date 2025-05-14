#include "department.h"
#include <algorithm>

Department::Department() : name(""), place(0), freeplace(0) {}

Department::Department(std::string name_, int place_, int freeplace_)
    : name(name_), place(place_), freeplace(freeplace_) {}

std::string Department::getname() const { return name; }
int Department::getplace() const { return place; }
int Department::getfreeplace() const { return freeplace; }
const std::vector<Doctor>& Department::getdoctors() const { return doctors; }
std::vector<Doctor>& Department::getdoctors() { return doctors; } 
const std::vector<Patient>& Department::getpatients() const { return patients; }

void Department::setname(std::string name_) { name = name_; }
void Department::setplace(int place_) { place = place_; }
void Department::setfreeplace(int freeplace_) { freeplace = freeplace_; }

void Department::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}

void Department::removeDoctor(const std::string& doctorName) {
    doctors.erase(std::remove_if(doctors.begin(), doctors.end(),
        [&](const Doctor& d) { return d.getname() == doctorName; }),
        doctors.end());
}

void Department::addPatient(const Patient& patient) {
    if (freeplace > 0) {
        patients.push_back(patient);
        freeplace--;
    }
    else {
        std::cout << "net svobodnih mest" << std::endl;
    }
}

void Department::removePatient(const std::string& patientName) {
    if (patientName.find(' ') == std::string::npos) {
        std::cout << "Error" << std::endl;
        return;
    }

    for (auto it = patients.begin(); it != patients.end(); ++it) {
        std::string fullName = it->getname1() + " " + it->getname2();
        if (fullName == patientName) {
            patients.erase(it);
            freeplace++;
            return;
        }
    }
    std::cout << "Error" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Department& department) {
    out << department.name << "," << department.place << "," << department.freeplace;
    return out;
}

std::istream& operator>>(std::istream& in, Department& department) {
    std::getline(in, department.name, ',');
    in >> department.place;
    in.ignore(1, ',');
    in >> department.freeplace;
    in.ignore(1, '\n');
    return in;
}
