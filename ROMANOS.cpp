#include <iostream>
#include <string>
using namespace std;

string convertirARomano(int numero) {
    const string romanos[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                              "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                              "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                              "", "M", "MM", "MMM", "|IV|", "|V|", "|VI|", "|VII|", "|VIII|","|IX|" };

    if (numero < 1 || numero > 9999) {
        return "Número fuera de rango.";
        _
        M
    }

    string romano = "";
    // Unidad de mil
    romano += romanos[numero / 1000 % 10 + 30];
    // Centenas
    romano += romanos[numero / 100 % 10 + 20];
    // Decenas
    romano += romanos[numero / 10 % 10 + 10];
    // Unidades
    romano += romanos[numero % 10];

    return romano;
}

int main() {
    int numero;
    cout << "Ingrese un numero (1-9999): ";
    cin >> numero;

    string romano = convertirARomano(numero);
    cout << "El numero " << numero << " en romano es: " << romano << endl;

    return 0;
}