#include "patient.h"

Patient::Patient() : name1(""), name2(""), name3(""), gender(""),
age(0), diagnos(""), doctor(""), status(""),
gday(0), vday(0) {}

Patient::Patient(std::string name1_, std::string name2_, std::string name3_,
    std::string gender_, int age_, std::string diagnos_, std::string doctor_,
    std::string status_, int gday_, int vday_)
    : name1(name1_), name2(name2_), name3(name3_),
    gender(gender_), age(age_), diagnos(diagnos_), doctor(doctor_),
    status(status_), gday(gday_), vday(vday_) {}

std::string Patient::getname1() const { return name1; }
std::string Patient::getname2() const { return name2; }
std::string Patient::getname3() const { return name3; }
std::string Patient::getgender() const { return gender; }
int Patient::getage() const { return age; }
std::string Patient::getdiagnos() const { return diagnos; }
std::string Patient::getdoctor() const { return doctor; }
std::string Patient::getstatus() const { return status; }
int Patient::getgday() const { return gday; }
int Patient::getvday() const { return vday; }
void Patient::setname1(std::string name1_) { name1 = name1_; }
void Patient::setname2(std::string name2_) { name2 = name2_; }
void Patient::setname3(std::string name3_) { name3 = name3_; }
void Patient::setgender(std::string gender_) { gender = gender_; }
void Patient::setage(int age_) { age = age_; }
void Patient::setdiagnos(std::string diagnos_) { diagnos = diagnos_; }
void Patient::setdoctor(std::string doctor_) { doctor = doctor_; }
void Patient::setstatus(std::string status_) { status = status_; }
void Patient::setgday(int gday_) { gday = gday_; }
void Patient::setvday(int vday_) { vday = vday_; }

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    out << patient.name1 << "," << patient.name2 << "," << patient.name3 << ","
        << patient.gender << "," << patient.age << "," << patient.diagnos << ","
        << patient.doctor << "," << patient.status << "," << patient.gday << ","
        << patient.vday;
    return out;
}

std::istream& operator>>(std::istream& in, Patient& patient) {
    std::getline(in, patient.name1, ',');
    std::getline(in, patient.name2, ',');
    std::getline(in, patient.name3, ',');
    std::getline(in, patient.gender, ',');
    in >> patient.age;
    in.ignore(1, ',');
    std::getline(in, patient.diagnos, ',');
    std::getline(in, patient.doctor, ',');
    std::getline(in, patient.status, ',');
    in >> patient.gday;
    in.ignore(1, ',');
    in >> patient.vday;
    in.ignore(1, '\n');
    return in;
}