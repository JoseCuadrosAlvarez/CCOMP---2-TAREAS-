#include <iostream>
#include <fstream>
#include <string>
#include "inverso.h"

int main() {
    int opcion;
    char continuar;
    bool salir = false;

    std::cout << "Escoge una opcion\n";

    do {
        std::cout << "Seleccione una opcion:\n";
        std::cout << "1. Encriptar\n";
        std::cout << "2. Desencriptar\n";
        std::cin >> opcion;

        if (opcion == 1) {
            std::ifstream archivoEntrada("original.txt");
            if (!archivoEntrada) {
                std::cerr << "Error al abrir el archivo de entrada." << std::endl;
                return 1;
            }

            std::string textoOriginal;
            std::getline(archivoEntrada, textoOriginal);

            int modulo = 256;
            int clavePublica;
            std::cout << "Ingrese su clave publica: ";
            std::cin >> clavePublica;

            CALCULADORA calculadora;

            int inverso = calculadora.inversoModular(clavePublica, modulo);

            if (inverso == -1) {
                std::cout << "El número " << clavePublica << " no tiene inverso modular respecto a " << modulo << ". Intente con otro número." << std::endl;
            }
            else {
                std::cout << "La clave privdada es: " << inverso << std::endl;
                calculadora.cifrarTexto(textoOriginal, inverso);
                std::cout << "Texto encriptado correctamente.\n";
            }
            archivoEntrada.close();
        }

        else if (opcion == 2) {
            int clavePrivada;
            std::cout << "Ingrese la clave privada para desencriptar: ";
            std::cin >> clavePrivada;

            CALCULADORA calculadora;

            calculadora.descifrarTexto(clavePrivada);
            std::cout << "Texto desencriptado correctamente.\n";
        }

        else {
            std::cout << "Opcion no valida (1 o 2)\n";
        }

        std::cout << "Para continuar (s/n): ";
        std::cin >> continuar;

        if (continuar == 'n' || continuar == 'N') {
            salir = true;
        }

    } while (!salir);

    std::cout << "¡Gracias!\n";

    return 0;
}