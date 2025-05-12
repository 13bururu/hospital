#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <iostream>

class Patient {
private:
    std::string name1;
    std::string name2;
    std::string name3;
    std::string gender;
    int age;
    std::string diagnos;
    std::string doctor;
    std::string status;
    int gday;
    int vday;

public:
    Patient();
    Patient(std::string name1_, std::string name2_, std::string name3_,
        std::string gender_, int age_, std::string diagnos_, std::string doctor_,
        std::string status_, int gday_, int vday_);
    void setname1(std::string name1_);
    void setname2(std::string name2_);
    void setname3(std::string name3_);
    void setgender(std::string gender_);
    void setage(int age_);
    std::string getname1() const;
    std::string getname2() const;
    std::string getname3() const;
    std::string getgender() const;
    int getage() const;
    std::string getdiagnos() const;
    std::string getdoctor() const;
    std::string getstatus() const;
    int getgday() const;
    int getvday() const;
    void setdiagnos(std::string diagnos_);
    void setdoctor(std::string doctor_);
    void setstatus(std::string status_);
    void setgday(int gday_);
    void setvday(int vday_);
    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
    friend std::istream& operator>>(std::istream& in, Patient& patient);
};

#endif