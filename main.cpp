#include <clocale>
#include "menu.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Menu menu;
    menu.run();
   
    return 0;
}
