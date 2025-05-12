#include "doctor.h"

Doctor::Doctor(std::string name_, std::string spec_)
    : name(name_), spec(spec_) {}

std::string Doctor::getname() const { return name; }
std::string Doctor::getspec() const { return spec; }

void Doctor::setname(std::string name_) { name = name_; }
void Doctor::setspec(std::string spec_) { spec = spec_; }

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
    out << doctor.name << "," << doctor.spec;
    return out;
}

std::istream& operator>>(std::istream& in, Doctor& doctor) {
    std::getline(in, doctor.name, ',');
    std::getline(in, doctor.spec);
    return in;
}