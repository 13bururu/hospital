#include "menu.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

Menu::Menu() {
    hospital.addDepartment(Department("Терапия", 30, 30));
    hospital.addDepartment(Department("Хирургия", 20, 20));
    hospital.addDepartment(Department("Кардиология", 15, 15));
}

void Menu::run() {
    while (true) {
        cout << "\n--- Главное меню ---" << endl;
        cout << "1. Управление отделениями" << endl;
        cout << "2. Врачи" << endl;
        cout << "3. Пациенты" << endl;
        cout << "4. Пропустить дни" << endl;
        cout << "5. Сохранить данные" << endl;
        cout << "6. Загрузить данные" << endl;
        cout << "7. Выход" << endl;

        int mainChoice;
        cout << "Ваш выбор: ";
        cin >> mainChoice;

        if (cin.fail()) {
            cout << "Error" << endl;
            clearInput();
            continue;
        }
        cin.ignore();

        switch (mainChoice) {
        case 1: {
            while (true) {
                cout << "\n--- Управление отделениями ---" << endl;
                cout << "1. Добавить отделение" << endl;
                cout << "2. Удалить отделение" << endl;
                cout << "3. Посмотреть информацию об отделении" << endl;
                cout << "0. Вернуться в главное меню" << endl;

                int deptAction;
                cout << "Ваш выбор: ";
                cin >> deptAction;

                if (cin.fail()) {
                    cout << "Error" << endl;
                    clearInput();
                    continue;
                }
                cin.ignore();

                if (deptAction == 1) {
                    addDepartment();
                }
                else if (deptAction == 2) {
                    removeDepartment();
                }
                else if (deptAction == 3) {
                    displayDepartments();
                    int departmentChoice;
                    cout << "Выберите номер отделения: ";
                    cin >> departmentChoice;

                    if (cin.fail()) {
                        cout << "Error" << endl;
                        clearInput();
                        continue;
                    }
                    cin.ignore();

                    if (departmentChoice >= 1 && departmentChoice <= hospital.getDepartments().size()) {
                        Department& selectedDepartment = hospital.getDepartments()[departmentChoice - 1];
                        cout << "Отделение: " << selectedDepartment.getname() << endl;
                        cout << "Всего мест: " << selectedDepartment.getplace() << endl;
                        cout << "Свободных мест: " << selectedDepartment.getfreeplace() << endl;
                        hospital.printDepartmentDoctors(selectedDepartment.getname());
                        hospital.printDepartmentPatients(selectedDepartment.getname());
                    }
                    else if (departmentChoice == 0) {
                        continue;
                    }
                    else {
                        cout << "Error" << endl;
                    }
                }
                else if (deptAction == 0) {
                    break;
                }
                else {
                    cout << "Error" << endl;
                }
            }
            break;
        }
        case 2: {
            while (true) {
                cout << "\n--- Управление врачами ---" << endl;
                cout << "1. Добавить врача" << endl;
                cout << "2. Удалить врача" << endl;
                cout << "3. Посмотреть список врачей" << endl;
                cout << "4. Редактировать врача" << endl;
                cout << "0. Вернуться в главное меню" << endl;

                int doctorAction;
                cout << "Ваш выбор: ";
                cin >> doctorAction;

                if (cin.fail()) {
                    cout << "Error" << endl;
                    clearInput();
                    continue;
                }
                cin.ignore();

                if (doctorAction == 1) {
                    addDoctor();
                }
                else if (doctorAction == 2) {
                    removeDoctor();
                }
                else if (doctorAction == 3) {
                    viewDoctors();
                }
                else if (doctorAction == 4) {
                    editDoctor();
                }
                else if (doctorAction == 0) {
                    break;
                }
                else {
                    cout << "Error" << endl;
                }
            }
            break;
        }
        case 3: {
            while (true) {
                cout << "\n--- Управление пациентами ---" << endl;
                cout << "1. Добавить пациента" << endl;
                cout << "2. Удалить пациента" << endl;
                cout << "3. Посмотреть список пациентов" << endl;
                cout << "4. Редактировать пациента" << endl;
                cout << "0. Вернуться в главное меню" << endl;

                int patientAction;
                cout << "Ваш выбор: ";
                cin >> patientAction;

                if (cin.fail()) {
                    cout << "Error" << endl;
                    clearInput();
                    continue;
                }
                cin.ignore();

                if (patientAction == 1) {
                    addPatient();
                }
                else if (patientAction == 2) {
                    removePatient();
                }
                else if (patientAction == 3) {
                    viewPatients();
                }
                else if (patientAction == 4) {
                    editPatient();
                }
                else if (patientAction == 0) {
                    break;
                }
                else {
                    cout << "Error" << endl;
                }
            }
            break;
        }
        case 4: {
            cout << "Введите количество дней для пропуска: ";
            int days;
            cin >> days;
            if (cin.fail() || days < 0) {
                cout << "Error" << endl;
                clearInput();
                break;
            }
            cin.ignore();
            hospital.skipDays(days);
            cout << "Пропущено " << days << " дней." << endl;
            break;
        }
        case 5: saveData(); break;
        case 6: loadData(); break;
        case 7: {
            
            return;
        }
        default: {
            cout << "Error" << endl;
            break;
        }
        }
    }
}

void Menu::displayDepartments() const {
    cout << "\nДоступные отделения:" << endl;
    const auto& departments = hospital.getDepartments();
    for (size_t i = 0; i < departments.size(); ++i) {
        cout << i + 1 << ". " << departments[i].getname() << endl;
    }
    cout << "0. Вернуться в главное меню" << endl;
}

void Menu::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Menu::addDoctor() {
    string name, specialization, deptName;

    displayDepartments();
    cout << "Выберите номер отделения для врача: ";
    int deptChoice;
    cin >> deptChoice;

    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Error" << endl;
        clearInput();
        return;
    }
    cin.ignore();
    deptName = hospital.getDepartments()[deptChoice - 1].getname();

    cout << "Введите имя врача: ";
    getline(cin, name);

    cout << "Введите специализацию врача: ";
    getline(cin, specialization);

    hospital.addDoctor(deptName, Doctor(name, specialization));
    cout << "Врач \"" << name << "\" добавлен в отделение \"" << deptName << "\"." << endl;
}

void Menu::removeDoctor() {
    displayDepartments();
    cout << "Выберите номер отделения: ";
    int deptChoice;
    cin >> deptChoice;

    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Error" << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string deptName = hospital.getDepartments()[deptChoice - 1].getname();

    hospital.printDepartmentDoctors(deptName);
    cout << "Введите имя врача для удаления: ";
    string doctorName;
    getline(cin, doctorName);

    hospital.removeDoctor(deptName, doctorName);
}

void Menu::viewDoctors() {
    cout << "\nСписок врачей по отделениям:" << endl;
    const auto& departments = hospital.getDepartments();
    if (departments.empty()) {
        cout << "Нет отделений." << endl;
        return;
    }
    for (const auto& dept : departments) {
        hospital.printDepartmentDoctors(dept.getname());
    }
}

void Menu::addPatient() {
    string name1, name2, name3, gender, diagnos, doctor;
    int age, gday, vday;

    displayDepartments();
    cout << "Выберите номер отделения для пациента: ";
    int deptChoice;
    cin >> deptChoice;

    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Error" << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string deptName = hospital.getDepartments()[deptChoice - 1].getname();

    cout << "Выберите статус пациента (1 - госпитализирован, 2 - амбулаторное лечение): ";
    int statusChoice;
    cin >> statusChoice;
    if (cin.fail() || (statusChoice != 1 && statusChoice != 2)) {
        cout << "Неверный выбор статуса." << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string status = (statusChoice == 1) ? "hospitalized" : "outpatient";
    if (statusChoice == 1 && hospital.getDepartments()[deptChoice - 1].getfreeplace() == 0) {
        cout << "Error" << endl;
        return;
    }

    cout << "Введите имя пациента: ";
    getline(cin, name1);
    cout << "Введите фамилию пациента: ";
    getline(cin, name2);
    cout << "Введите отчество пациента: ";
    getline(cin, name3);
    cout << "Введите пол пациента (male/female): ";
    getline(cin, gender);
    cout << "Введите возраст пациента: ";
    cin >> age;
    if (cin.fail() || age < 0 || age > 150) {
        cout << "Error" << endl;
        clearInput();
        return;
    }
    cin.ignore();
    cout << "Введите диагноз пациента: ";
    getline(cin, diagnos);
    cout << "Введите имя лечащего врача: ";
    getline(cin, doctor);

    bool doctorExists = false;
    for (const auto& doc : hospital.getDepartments()[deptChoice - 1].getdoctors()) {
        if (doc.getname() == doctor) {
            doctorExists = true;
            break;
        }
    }
    if (!doctorExists) {
        cout << "Указанный врач не работает в этом отделении." << endl;
        return;
    }

    if (name1.empty() || name2.empty() || diagnos.empty() || doctor.empty()) {
        cout << "Поля не могут быть пустыми." << endl;
        return;
    }
    if (diagnos.find(',') != string::npos || doctor.find(',') != string::npos) {
        cout << "Запятые в диагнозе или имени врача недопустимы." << endl;
        return;
    }

    cout << "Введите количество дней госпитализации: ";
    cin >> gday;
    if (cin.fail()) {
        cout << "Некорректный ввод дней." << endl;
        clearInput();
        return;
    }
    cout << "Введите количество дней до выписки: ";
    cin >> vday;
    if (cin.fail()) {
        cout << "Некорректный ввод дней." << endl;
        clearInput();
        return;
    }
    cin.ignore();

    Patient patient(name1, name2, name3, gender, age, diagnos, doctor, status, gday, vday);
    if (status == "hospitalized") {
        hospital.admitPatient(patient, deptName);
        cout << "Пациент \"" << name1 << " " << name2 << "\" добавлен в отделение \"" << deptName << "\"." << endl;
    }
    else {
        hospital.getPatients().push_back(patient);
        cout << "Пациент \"" << name1 << " " << name2 << "\" добавлен на амбулаторное лечение." << endl;
    }
}

void Menu::removePatient() {
    displayDepartments();
    cout << "Выберите номер отделения: ";
    int deptChoice;
    cin >> deptChoice;

    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Неверный выбор отделения." << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string deptName = hospital.getDepartments()[deptChoice - 1].getname();

    hospital.printDepartmentPatients(deptName);
    cout << "Введите полное имя пациента для удаления (Имя Фамилия): ";
    string patientName;
    getline(cin, patientName);

    hospital.dischargePatient(patientName, deptName);
}

void Menu::viewPatients() {
    cout << "\n--- Список пациентов ---" << endl;
    hospital.printAllPatients();
}

void Menu::editPatient() {
    displayDepartments();
    cout << "Выберите номер отделения: ";
    int deptChoice;
    cin >> deptChoice;
    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Неверный выбор отделения." << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string deptName = hospital.getDepartments()[deptChoice - 1].getname();
    hospital.printDepartmentPatients(deptName);
    cout << "Введите полное имя пациента (Имя Фамилия): ";
    string patientName;
    getline(cin, patientName);

    for (auto& patient : hospital.getPatients()) {
        if (patient.getname1() + " " + patient.getname2() == patientName) {
            cout << "Введите новый диагноз: ";
            string diagnos;
            getline(cin, diagnos);
            if (!diagnos.empty() && diagnos.find(',') == string::npos) {
                patient.setdiagnos(diagnos);
            }
            cout << "Введите новое имя врача: ";
            string doctor;
            getline(cin, doctor);
            bool doctorExists = false;
            for (const auto& doc : hospital.getDepartments()[deptChoice - 1].getdoctors()) {
                if (doc.getname() == doctor) {
                    doctorExists = true;
                    break;
                }
            }
            if (doctorExists && !doctor.empty() && doctor.find(',') == string::npos) {
                patient.setdoctor(doctor);
            }
            cout << "Пациент обновлён." << endl;
            return;
        }
    }
    cout << "Пациент не найден." << endl;
}

void Menu::addDepartment() {
    string name;
    int totalPlaces, freePlaces;

    cout << "Введите название отделения: ";
    getline(cin, name);
    if (name.empty()) {
        cout << "Название не может быть пустым." << endl;
        return;
    }

    cout << "Введите общее количество мест: ";
    cin >> totalPlaces;
    if (cin.fail() || totalPlaces < 0) {
        cout << "Некорректный ввод." << endl;
        clearInput();
        return;
    }

    cout << "Введите количество свободных мест: ";
    cin >> freePlaces;
    if (cin.fail() || freePlaces < 0 || freePlaces > totalPlaces) {
        cout << "Некорректный ввод. Свободных мест не может быть больше общего количества." << endl;
        clearInput();
        return;
    }
    cin.ignore();

    hospital.addDepartment(Department(name, totalPlaces, freePlaces));
    cout << "Отделение \"" << name << "\" добавлено." << endl;
}

void Menu::removeDepartment() {
    displayDepartments();
    cout << "Выберите номер отделения для удаления: ";
    int deptChoice;
    cin >> deptChoice;

    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Неверный выбор отделения." << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string deptName = hospital.getDepartments()[deptChoice - 1].getname();

    hospital.removeDepartment(deptName);
    cout << "Отделение \"" << deptName << "\" удалено." << endl;
}

void Menu::editDoctor() {
    displayDepartments();
    cout << "Выберите номер отделения: ";
    int deptChoice;
    cin >> deptChoice;

    if (cin.fail() || deptChoice < 1 || deptChoice > hospital.getDepartments().size()) {
        cout << "Неверный выбор отделения." << endl;
        clearInput();
        return;
    }
    cin.ignore();
    string deptName = hospital.getDepartments()[deptChoice - 1].getname();

    hospital.printDepartmentDoctors(deptName);
    cout << "Введите имя врача для редактирования: ";
    string doctorName;
    getline(cin, doctorName);

    for (auto& dept : hospital.getDepartments()) {
        if (dept.getname() == deptName) {
            for (auto& doctor : dept.getdoctors()) {
                if (doctor.getname() == doctorName) {
                    cout << "Введите новое имя врача: ";
                    string newName;
                    getline(cin, newName);
                    if (!newName.empty()) {
                        doctor.setname(newName);
                    }
                    cout << "Введите новую специализацию: ";
                    string newSpec;
                    getline(cin, newSpec);
                    if (!newSpec.empty()) {
                        doctor.setspec(newSpec);
                    }
                    cout << "Врач обновлён." << endl;
                    return;
                }
            }
            cout << "Врач не найден." << endl;
            return;
        }
    }
    cout << "Отделение не найдено." << endl;
}

void Menu::saveData() {
    hospital.saveToFile("departments.txt", "patients.txt");
    cout << "Данные сохранены." << endl;
}

void Menu::loadData() {
    hospital.loadFromFile("departments.txt", "patients.txt");
    cout << "Данные загружены." << endl;
}
