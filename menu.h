#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "department.h"
#include "doctor.h"
#include "patient.h"
#include "hospital.h"

class Menu {
private:
    Hospital hospital;
    void displayDepartments() const;
    void clearInput();
    void addDoctor();
    void removeDoctor();
    void viewDoctors();
    void addPatient();
    void removePatient();
    void viewPatients();
    void saveData();
    void loadData();
    void editPatient();
    void addDepartment();
    void removeDepartment();
    void editDoctor();

public:
    Menu();
    void run();
};

#endif