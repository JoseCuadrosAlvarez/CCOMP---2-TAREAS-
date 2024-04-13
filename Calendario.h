#pragma once
#include <iostream>
#include <string>

class Calendario {
private:
    std::string dias[7] = { "D", "L", "M", "M", "J", "V", "S" };
    int dias_meses[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
    Calendario() {}

    void imprimir_calendario(int dia, int mes, int ano) {
        int primer_dia_enero = calcular_1_enero(ano);

        // Calcular el d�a de la semana en que comienza el mes
        int dias_desde_enero = calcular_dias_desde_enero(1, mes, ano); // Calculamos los d�as desde enero 1
        int primer_dia_mes = (primer_dia_enero + dias_desde_enero) % 7;

        // Imprimir los nombres de los d�as de la semana
        for (int i = 0; i < 7; i++) {
            std::cout << dias[i] << "\t";
        }
        std::cout << std::endl;

        // Imprimir espacios hasta llegar al d�a de la semana en que comienza el mes
        for (int i = 0; i < primer_dia_mes; i++) {
            std::cout << "\t";
        }

        // Imprimir los d�as del mes
        int dias_en_mes = dias_meses[mes - 1];
        if (mes == 2 && es_bisiesto(ano)) {
            dias_en_mes = 29; // Febrero tiene 29 d�as en a�os bisiestos
        }
        int dia_actual = 1;
        for (int i = 0; i < dias_en_mes; i++) {
            std::cout << dia_actual++ << "\t";
            if ((i + primer_dia_mes + 1) % 7 == 0) {
                std::cout << std::endl;
            }
        }
    }

    int calcular_1_enero(int ano) {
        int primer_dia_1900 = 1; // Lunes
        // Calcular el desfase respecto al a�o 1900
        int desfase = ano - 1900;
        // Ajustar el primer d�a del a�o actual seg�n el desfase y el n�mero de a�os bisiestos
        int primer_dia_ano = (primer_dia_1900 + desfase) % 7;
        if (desfase > 0) { // No se aplica para 1900
            int bisiestos = contar_bisiestos_hasta(ano - 1); // Contar bisiestos hasta el a�o anterior
            primer_dia_ano += bisiestos; // Sumar el n�mero de a�os bisiestos al primer d�a del a�o actual
        }
        // Asegurarse de que el valor est� en el rango 0-6 (Lunes-Domingo)
        if (primer_dia_ano < 0) {
            primer_dia_ano += 7;
        }
        return primer_dia_ano;
    }

    int calcular_dias_desde_enero(int dia, int mes, int ano) {
        // Calcular el d�a de la semana en que comienza el a�o
        int primer_dia_enero = calcular_1_enero(ano);

        // Calcular el d�a de la semana en que comienza el mes
        int dias_desde_enero = 0;
        for (int i = 1; i < mes; i++) {
            dias_desde_enero += dias_meses[i - 1];
            if (i == 2 && es_bisiesto(ano)) {
                dias_desde_enero++;
            }
        }
        dias_desde_enero += dia - 1; // Resta 1 para calcular correctamente los d�as desde enero

        // Ajustar si excede el l�mite de 6 (Domingo)
        dias_desde_enero %= 7;

        return dias_desde_enero;
    }

    bool es_bisiesto(int ano) {
        return (ano % 4 == 0 && ano % 100 > 0) || (ano % 400 == 0);
    }

    int contar_bisiestos_hasta(int ano) {
        int contador = 0;
        for (int i = 1900; i <= ano; ++i) {
            if (es_bisiesto(i)) {
                ++contador;
            }
        }
        return contador;
    }
};

