#pragma once
#ifndef CALCULADORA_H
#define CALCULADORA_H
class CALCULADORA {
public:
    CALCULADORA() {}

    int sumar_mod(int a, int b, int modulo) {
        if (a + b == modulo) {
            int c = a + b;
            return c;
        }
        else {
            return (a + b) % modulo;
        }
    }

    int restar_mod(int a, int b, int modulo) {
        return ((a - b) % modulo + modulo) % modulo;
    }

    int multiplicar_mod(int a, int b, int modulo) {
        int resultado = 0;
        resultado = (a * b) % modulo;
        return resultado;
    }

    int inversoModular(int a, int modulo) {
        int num2 = a;
        int num1 = modulo;
        int U0 = 0;
        int U1 = 1;
        int Un = 0;
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
            std::cout << "La expresion " << a << " modulo " << modulo << " no tiene inversa" << std::endl;
            return -1;
        }
    }
};
#endif