//Algoritmo que identifica si un caracter ingresado es vocal o consonante
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <algorithm>


using namespace std;

int main() {
    char char_i;
     vector<char> consonantes = {'B', 'b', 'C', 'c', 'D', 'd', 'F', 'f', 'G', 'g', 'H', 'h', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'V', 'v', 'X', 'x', 'Y', 'y', 'Z', 'z'};
     vector<char> vocales = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
     cout <<"Ingrese un letra: ";
     cin >> char_i;
        auto it = find(consonantes.begin(), consonantes.end(), char_i);
        if (it != consonantes.end()) {
            cout << char_i << " es una consonante" << endl;
        }
        auto it2 = find(vocales.begin(), vocales.end(), char_i);
        if (it2 != vocales.end()) {
            cout << char_i << " es una vocal" << endl;
        }
        if (it==consonantes.end() &&  it2 == vocales.end()) {
            cout << char_i << " no es una letra" << endl;
        }
}

#include <iostream>
#include <iomanip> // Para std::setw y std::setfill

using namespace std;

int main() {

    int hora, duracion;
   
    // Leer los dos números enteros
    cout << "Ingrese la hora en formato HHMM (24 horas): ";
    cin >> hora;
   
    cout << "Ingrese la duración en formato HHMM: ";
    cin >> duracion;
   
    // Extraer horas y minutos del primer número
    int horaActual = hora / 100;
    int minutoActual = hora % 100;
   
    // Extraer horas y minutos del segundo número
    int horaDuracion = duracion / 100;
    int minutoDuracion = duracion % 100;
   
    // Sumar las horas y minutos
    int minutoTotal = minutoActual + minutoDuracion;
    int horaTotal = horaActual + horaDuracion;
   
    // Ajustar los minutos si son 60 o más
    if (minutoTotal >= 60) {
        minutoTotal -= 60;
        horaTotal++;
    }
}

#include <iostream>
#include <iomanip> // Para std::setw y std::setfill

using namespace std;

int main() {
    int hora, duracion;
   
    // Leer los dos números enteros
    cout << "Ingrese la hora en formato HHMM (24 horas): ";
    cin >> hora;
   
    cout << "Ingrese la duración en formato HHMM: ";
    cin >> duracion;
   
    // Extraer horas y minutos del primer número
    int horaActual = hora / 100;
    int minutoActual = hora % 100;
   
    // Extraer horas y minutos del segundo número
    int horaDuracion = duracion / 100;
    int minutoDuracion = duracion % 100;
   
    // Sumar las horas y minutos
    int minutoTotal = minutoActual + minutoDuracion;
    int horaTotal = horaActual + horaDuracion;
   
    // Ajustar los minutos si son 60 o más
    if (minutoTotal >= 60) {
        minutoTotal -= 60;
        horaTotal++;
    }
}

int main() {
    int tamaño;

    // Pedir al usuario que ingrese un número impar
    cout << "Ingrese un número entero impar para el tamaño del patrón: ";
    cin >> tamaño;

    // Verificar que el tamaño es impar
    if (tamaño % 2 == 0) {
        cout << "El número ingresado no es impar. Por favor, ingrese un número impar." << endl;
        return 1;
    }

    int mitad = tamaño / 2;

    // Imprimir la parte superior del patrón
    for (int i = 0; i <= mitad; ++i) {
        // Imprimir espacios
        for (int j = 0; j < mitad - i; ++j) {
            cout << " ";
        }
        // Imprimir asteriscos
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Imprimir la parte inferior del patrón
    for (int i = mitad - 1; i >= 0; --i) {
        // Imprimir espacios
        for (int j = 0; j < mitad - i; ++j) {
            cout << " ";
        }
        // Imprimir asteriscos
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


#include <iomanip> // Para std::setprecision

using namespace std;

// Función para calcular el factorial de un número
double factorial(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num_terms;
   
    // Leer el número de términos
    cout << "Ingrese el número de términos para la aproximación de e: ";
    cin >> num_terms;
   
    if (num_terms < 1) {
        cout << "El número de términos debe ser al menos 1." << endl;
        return 1;
    }

    // Calcular la aproximación de e
    double e_approx = 0.0;
    for (int i = 0; i < num_terms; ++i) {
        e_approx += 1.0 / factorial(i);
    }
   
    // Mostrar el resultado
    cout << fixed << setprecision(6); // Mostrar con 6 decimales
    cout << "e es aproximadamente: " << e_approx << endl;
   
    return 0;
}

int main() {
    int n;
   
    // Leer el número n
    cout << "Ingrese un número n: ";
    cin >> n;
   
    // Inicializar los primeros dos números de la serie de Fibonacci
    int a = 1, b = 1;
    int suma_pares = 0;
   
    // Generar la serie de Fibonacci y sumar los números pares menores que n
    while (b < n) {
        if (b % 2 == 0) {
            suma_pares += b;
        }
        // Generar el siguiente número en la serie de Fibonacci
        int siguiente = a + b;
        a = b;
        b = siguiente;
    }
   
    // Mostrar el resultado
    cout << "El resultado de la suma es: " << suma_pares << endl;
   
    return 0;
}


///PROBLEMA 8, POR PARTES

// Función para calcular el máximo común divisor
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Función para calcular el mínimo común múltiplo
int lcm(int x, int y) {
    return (x * y) / gcd(x, y);
}

// Función para imprimir los múltiplos y calcular la suma
void imprimirYCalcularSuma(int a, int b, int c) {
    set<int> multiples;
    int mcm = lcm(a, b);
    int suma = 0;

    // Agregar múltiplos de a
    cout << "Múltiplos de " << a << ": ";
    for (int i = a; i < c; i += a) {
        multiples.insert(i);
    }

    // Agregar múltiplos de b
    cout << "Múltiplos de " << b << ": ";
    for (int i = b; i < c; i += b) {
        multiples.insert(i);
    }

    // Mostrar los múltiplos y calcular la suma
    cout << endl << "Múltiplos: ";
    for (auto it = multiples.begin(); it != multiples.end(); ++it) {
        cout << *it;
        if (next(it) != multiples.end()) {
            cout << " + ";
        }
        suma += *it;
    }
    cout << " = " << suma << endl;
}

int main() {
    int a, b, c;

    // Solicitar al usuario los valores
    cout << "Ingrese tres números enteros (a, b, c): ";
    cin >> a >> b >> c;

    // Verificar que c sea mayor que 0
    if (c <= 0) {
        cout << "El valor de c debe ser mayor que 0." << endl;
        return 1;
    }

    imprimirYCalcularSuma(a, b, c);

    return 0;
}


int main() {
    int N;

    // Pedir al usuario que ingrese un número entero
    cout << "Ingrese un número entero: ";
    cin >> N;

    // Variable para almacenar la suma de los dígitos elevados a sí mismos
    int suma = 0;

    // Trabajar con el número absoluto para manejar números negativos
    int num = abs(N);

    // Procesar cada dígito del número
    while (num > 0) {
        int digito = num % 10;          // Obtener el último dígito
        suma += pow(digito, digito);    // Elevar el dígito a sí mismo y sumarlo
        num /= 10;                      // Eliminar el último dígito del número
    }

    // Mostrar el resultado
    cout << "El resultado de la suma es: " << suma << endl;

    return 0;
}



int main() {
    float monto;
    int residuo;
    int mil, quinientos, doscientos, cien, cincuenta;

    // Leer el monto ingresado por el usuario
    cout << "Ingrese su monto: ";
    cin >> monto;

    // Convertir monto a entero y calcular las monedas
    residuo = int(monto) % 1000;
    mil = int(monto) / 1000;
    quinientos = residuo / 500;
    residuo = residuo % 500; // El resultado es para hallar las monedas de 200
    doscientos = residuo / 200;
    residuo = residuo % 200;
    cien = residuo / 100;
    residuo = residuo % 100;
    cincuenta = residuo / 50;
    residuo = residuo % 50;

    // Mostrar el resultado
    cout << "Billetes y monedas:" << endl;
    cout << "Mil: " << mil << endl;
    cout << "Quinientos: " << quinientos << endl;
    cout << "Doscientos: " << doscientos << endl;
    cout << "Cien: " << cien << endl;
    cout << "Cincuenta: " << cincuenta << endl;
    cout << "Residuo: " << residuo << endl;
}