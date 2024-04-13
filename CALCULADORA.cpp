#include <iostream>
#include "CALCULADORA.h"

int main() {
    CALCULADORA calc;

    int a, b, modulo;
    char operador, mod_str[4], operacion;

    std::cout << "Si desea realizar (+ - *) -S- , si desea realizar (Inverso) -I- : ";
    std::cin >> operacion;
    if (operacion == 'S') {
        std::cout << "Ingrese la operacion en formato 'a op b mod m': ";
        std::cin >> a >> operador >> b >> mod_str >> modulo;

        if (mod_str[0] == 'm' && mod_str[1] == 'o' && mod_str[2] == 'd' && mod_str[3] == '\0') {
            if (operador == '+') {
                std::cout << "Resultado: " << calc.sumar_mod(a, b, modulo) << " mod " << modulo << std::endl;
            }
            else if (operador == '-') {
                std::cout << "Resultado: " << calc.restar_mod(a, b, modulo) << " mod " << modulo << std::endl;
            }
            else if (operador == '*') {
                std::cout << "Resultado: " << calc.multiplicar_mod(a, b, modulo) << std::endl;
            }
            else {
                std::cout << "Operador no valido." << std::endl;
            }
        }
        else {
            std::cout << "Formato de modulo invalido." << std::endl;
        }
    }

    if (operacion == 'I') {
        std::cout << "Ingrese el modulo del que quiere sacar su inversa: ";
        std::cin >> a >> mod_str >> modulo;
        if (mod_str[0] == 'm' && mod_str[1] == 'o' && mod_str[2] == 'd' && mod_str[3] == '\0') {
            int inverso = calc.inversoModular(a, modulo);
            if (inverso == -1) {
                std::cout << "No tiene inverso";
            }
            else {
                std::cout << "El inverso es: " << inverso << std::endl;
            }
        }
    }
    return 0;
}
