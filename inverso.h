#pragma once
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
#include <fstream>
#include <string>

class CALCULADORA {
private:
    const int modulo = 256;;

public:
    CALCULADORA(){}

    int inversoModular(int a, int modulo) {
        int U0 = 0;
        int U1 = 1;
        int Un = 0;
        int num2 = a;
        int num1 = modulo;
        int cociente_o_q = 0;
        int residuo;

        while (num1 > 1) {
            cociente_o_q = num1 / num2;
            residuo = num1 % num2;
            num1 = num2;
            num2 = residuo;

            Un = U0 - cociente_o_q * U1;
            U0 = U1;
            U1 = Un;
            
            if (num2 == 0) {
                break;
            }
        }

        if (num1 == 1) {
            if (U0 < 0) {
                U0 += modulo;
            }
            return U0;
        }
        else {
            std::cout << "No se puede calcular el inverso modular para " << a << " modulo " << modulo << std::endl;
            return -1; 
        }
    }

    void cifrarTexto(const std::string& textoOriginal, int op1) {
        std::ofstream archivoCifrado("cifrado.txt");
        for (char c : textoOriginal) {
            char nuevo_caracter = (c + op1) % 256;
            archivoCifrado << nuevo_caracter;
        }
        archivoCifrado.close();
    }

    void descifrarTexto(int op1) {
        std::ifstream archivoCifrado("cifrado.txt");
        std::ofstream archivoDescifrado("descifrado.txt");

        char caracter;
        while (archivoCifrado.get(caracter)) {
            char original_caracter = caracter - op1;
            archivoDescifrado << original_caracter;
        }

        archivoCifrado.close();
        archivoDescifrado.close();
    }
};

#endif