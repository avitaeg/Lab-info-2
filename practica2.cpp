#include <iostream>
#include <iomanip> // Para el formato de columnas
#include <vector>
using namespace std;

///////////////////////////////// Problema 1 /////////////////////////////////
bool esNumeroValido(char *entrada){
    int i = 0;
    while (entrada [i] != '\0'){
        if (entrada[i] < '0' || entrada [i] > '9'){
            return false;
        }
        i++;
    }
    return true;
}

long convertirEntero(char *entrada)
{
    long numero = 0;
    int i = 0;
    while (entrada[i] != '\0'){ //Convertir caracteres en número
        numero = numero * 10 + (entrada[i] - '0');
        i++;
    }
    return numero;
}

void problema1()
{
    int billetesDisp [] = {50000, 20000, 10000, 5000, 2000, 1000,500, 200, 100,50};
    int cantidadBill = 10;
    
    cout<<"Ingrese la cantidad de dinero: ";
    char entrada [10]; 
    cin>>entrada;//Leer la entrada del usuario como cadena de texto
    
    if (!esNumeroValido(entrada)){
        cout<<"Entrada inválida. Ingrese solo números."<<endl;
        return; //Salir de la funcion, como un break
    }
    
    long cantidad = convertirEntero(entrada);//Convertir la cadena en numero
    
    int resultado[cantidadBill] = {0}; //Almacenar cuantos billetes/monedas de cada uno se necesitan
    int cantidadAux = cantidad;
    
    for (int i = 0; i < cantidadBill; i++){
        resultado [i] = cantidadAux/billetesDisp[i];
        cantidadAux = cantidadAux % billetesDisp[i];
    }
    
    //Mostrar resultados
    for (int i = 0; i < cantidadBill; i++){
        cout<<billetesDisp[i]<<": "<<resultado[i] <<endl;
    }
}

///////////////////////////////// Problema 3 /////////////////////////////////
int longitudCadena(char cadena[])
{
    int longitud = 0;
    while (cadena [longitud] != '\0'){ //El caracter '\0' indica el final de la cadena
        longitud ++;
    }
    return longitud;
}

bool compararCadena (char cadena1[], char cadena2[])
{
    int longitud1 = longitudCadena(cadena1);
    int longitud2 = longitudCadena(cadena2);
    
    if (longitud1 != longitud2){
        return false; //Si tienen diferentes longitudes, no son iguales
    }
    
    //Comparar caracter por caracter
    for (int i = 0; i < longitud1; i++){
        if (cadena1[i] != cadena2[i]){
            return false;
        }
    }
    return true;
}

void problema3()
{
    char cadena1[100], cadena2[100];
    
    cout<<"Ingrese la primer cadena: ";
    cin>>cadena1;
    cout<<"Ingrese la segunda cadena: ";
    cin>>cadena2;
    
    if (compararCadena(cadena1, cadena2)){
        cout<<"Las cadenas son iguales"<<endl;
    } else {
        cout<<"Las cadenas son diferentes"<<endl;
    }
}

///////////////////////////////// Problema 5 /////////////////////////////////

// Función que convierte un número entero a una cadena de caracteres (usando referencia)
void enteroACadena (int numero, char *&resultado) // Utilizar un puntero por referencia
{
    int i = 0;
    bool esNegativo = false;
    
    //Caso numeros negativos
    if (numero < 0){
        esNegativo = true;
        numero = -numero; // "Valor absoluto" para poder operar
    }
    
    //Obtener el ultimo dijito del numero, sumado el valor ASCII del '0'(48) 
    do {
        resultado[i++] = (numero % 10) + '0';
        numero /= 10;
    } while (numero != 0);
    
    //Si era negativo añade al resultado su respectivo '-'
    if (esNegativo){resultado[i++] = '-';}
    
    resultado[i] = '\0'; //Terminar la cadena
    
    //Invertir 
    int inicio = 0, fin = i - 1; //"inicio" apunta al principio y "fin" al ultimo digito
    while (inicio<fin){
        char aux = resultado[inicio];
        resultado[inicio] = resultado[fin];
        resultado [fin] = aux;
        inicio ++;
        fin --;
    }
}

void problema5()
{
    int numero;
    char *cadena = new char[100]; //Arreglo dinamico
    
    cout<<"Ingresa un numero entero: ";
    cin>>numero;
    
    enteroACadena(numero, cadena);
    
    cout<<"El numero convertido a cadena es: "<<cadena<<endl;
}

///////////////////////////////// Problema 7 /////////////////////////////////

void problema7()
{
    char cadena[100]; //espacio para almacenar hasta 100 caracteres
    char resultado [100]; //Para almacenar los no repetidos
    int i = 0, j = 0, k = 0; //Contadores para recorrer las cadenas
    
    cout<<"introduce una cadena: ";
    cin>>cadena;
    
    //Recorrer cada caracter
    while (cadena[i] != '\0'){
        bool repetido = false;
        
        //Comparar el caracter actual con los que ya estén en la cadena resultado
        for (j = 0 ;j < k; j++){
            if (cadena[i] == resultado[j]){
                repetido = true;
                break;
            }
        }
        
        // si no está repetido se añade a la cadena resultado
        if (!repetido){
            resultado[k] = cadena [i];
            k++;
        }
        i++;
    }
    //Añadir caracter nulo al final mara marcar final
    resultado [k]='\0';
    
    cout<<"original: "<<cadena<<endl;
    cout<<"sin repetidos: "<<resultado<<endl;
}

///////////////////////////////// Problema 9 /////////////////////////////////

void problema9()
{
    int n;
    char cadena [100];
    int suma = 0;
    int digitos = 0;
    
    cout<<"ingrese el valor de n: ";
    cin>>n;
    cout<<"ingrese la cadena de caracteres numericos: ";
    cin>>cadena;
    
    while(cadena[digitos] != '\0'){
        digitos++;
    }
    
    //Determinar si es necesario agregar ceros
    int resto = digitos % n;
    int inicio = 0;
    
    if (resto != 0) {
        inicio = n - resto; //Cuantos ceros se deben agregar al inicio
    }
    
    cout<<"Original: ";
    for (int i = 0; i < inicio; i++){
        cout<<"0";
    }
    
    cout<<cadena;
    
    //Sumar los numeros de n cifras
    int actual = 0; //Para guardar el numero temporal
    for (int i = 0; i < digitos + inicio; i++)
    {
        if (i < inicio){
            actual = actual * 10; //Agrega un ceros
        }else{ 
            actual = actual *10 + (cadena [i - inicio] - '0'); //Convertir el caracter a número
        }
    
    //Sumar
    if((i + 1) % n == 0){
        suma += actual;
        actual = 0; //Reiniciar para el siguiente grupo de n digitos
        }
    }
    cout<<'\n'<<"Suma: "<<suma<<endl;
}


///////////////////////////////PROBLEMA 11/////////////////////////////////////////////////

void problema11()
{  
    int opcion;
    int opcion_fila, opcion_columna;
    int filas = 15;  // Filas de A a O
    int columnas = 20;  // Asientos del 1 al 20
    char disp = '+';  // Asiento disponible
    char nodisp = '-';  // Asiento no disponible
    char actual = ' ';  // Estado actual del asiento
    bool reservas[15][20] = {false};  // Inicializar todas las reservas en false (no reservado)

    do {
        // Primera fila: espacio vacío y letras de la A a O
        cout << "A continuación se presentan los asientos disponibles:" << endl;
        cout << setw(5) << " ";  // Dejar un espacio vacío para la cabecera de fila
        for (char letra = 'A'; letra <= 'O'; letra++) {
            cout << setw(5) << letra;
        }
        cout << endl;

        // Imprimir los números del 1 al 15 en la primera columna y el estado de las reservas
        for (int i = 0; i < filas; i++) {
            cout << setw(5) << (char)('A' + i);  // Imprimir la letra de la fila (A-O)
            for (int j = 0; j < columnas; j++) {
                if (reservas[i][j] == false) {
                    actual = nodisp;  // Si el asiento no está reservado, mostrar "-"
                } else {
                    actual = disp;  // Si el asiento está reservado, mostrar "+"
                }
                cout << setw(5) << actual;  // Imprimir el estado del asiento
            }
            cout << endl;  // Nueva línea al final de cada fila
        }

        // Solicitar al usuario la opción de reservar o cancelar
        cout << "Los asientos marcados con '-' están disponibles, los asientos marcados con '+' están reservados." << endl;
        cout << "Marque 1 para realizar una reservación, 2 para cancelar una reservación, 0 para salir: ";
        cin >> opcion;

        if (opcion == 1) {
            // Solicitar la fila
            do {
                cout << "Indique la fila (A-O): ";
                char letra_fila;
                cin >> letra_fila;
                opcion_fila = letra_fila - 'A';  // Convertir letra a índice
            } while (opcion_fila < 0 || opcion_fila >= 15);

            // Solicitar la columna
            do {
                cout << "Indique el número de asiento (1-20): ";
                cin >> opcion_columna;
            } while (opcion_columna < 1 || opcion_columna > 20);

            // Verificar si el asiento está disponible
            if (reservas[opcion_fila][opcion_columna - 1] == false) {
                reservas[opcion_fila][opcion_columna - 1] = true;  // Reservar asiento
                cout << "Reserva realizada con éxito." << endl;
            } else {
                cout << "El asiento ya está reservado." << endl;
            }
        } 
        else if (opcion == 2) {
            // Solicitar la fila para cancelar
            do {
                cout << "Indique la fila (A-O) para cancelar la reserva: ";
                char letra_fila;
                cin >> letra_fila;
                opcion_fila = letra_fila - 'A';  // Convertir letra a índice
            } while (opcion_fila < 0 || opcion_fila >= 15);

            // Solicitar la columna para cancelar
            do {
                cout << "Indique el número de asiento (1-20): ";
                cin >> opcion_columna;
            } while (opcion_columna < 1 || opcion_columna > 20);

            // Verificar si el asiento está reservado
            if (reservas[opcion_fila][opcion_columna - 1] == true) {
                reservas[opcion_fila][opcion_columna - 1] = false;  // Cancelar reserva
                cout << "Reserva cancelada con éxito." << endl;
            } else {
                cout << "El asiento no estaba reservado." << endl;
            }
        } 
        else if (opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        } 
        else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }

    } while (opcion != 0);  // Bucle continúa hasta que el usuario elija la opción 0 (salir)
}

/////////////////////////Problema 13//////////////////////////////


// Función que analiza una matriz para determinar el número de estrellas
void problema13(vector<vector<int>>& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    int cuentaEstrellas = 0;

    // Iterar sobre la matriz, excluyendo la primera y última fila y columna
    for (int i = 1; i < filas - 1; i++) {
        for (int j = 1; j < columnas - 1; j++) {
            // Calcular el promedio del elemento y sus vecinos inmediatos
            float promedio = (matriz[i][j] + matriz[i][j - 1] + matriz[i][j + 1] +
                              matriz[i - 1][j] + matriz[i + 1][j]) / 5.0;
            
            // Verificar si el promedio supera el umbral
            if (promedio > 6) {
                cuentaEstrellas++;
            }
        }
    }

    cout << "Número de estrellas detectadas: " << cuentaEstrellas << endl;
}

/*
int main() {
    
    vector<vector<int>> matriz = {
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5, 0, 0, 2, 3, 7, 3, 0},
        {2, 6, 2, 7, 3, 0, 10, 0},
        {0, 0, 4, 5, 4, 1, 6, 0},
        {0, 0, 7, 2, 6, 9, 10, 4},
        {0, 5, 0, 6, 4, 8, 0, 0}
    };

    problema13(matriz);
    return 0;
}
*/


////////////////////////////////////Problema 15///////////////////////////////////

void problema15() {
    // Definir los rectángulos A y B en el formato [x, y, ancho, alto]
    int A[4], B[4];
    
    // Leer los datos del rectángulo A
    cout << "Ingrese las coordenadas x, y, ancho y alto del rectángulo A (en ese orden):" << endl;
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    
    // Leer los datos del rectángulo B
    cout << "Ingrese las coordenadas x, y, ancho y alto del rectángulo B (en ese orden):" << endl;
    cin >> B[0] >> B[1] >> B[2] >> B[3];

    // Calcular los límites de los rectángulos
    int xA[2] = {A[0], A[0] + A[2]}; // Inicio y fin en x de A
    int yA[2] = {A[1], A[1] - A[3]}; // Inicio y fin en y de A (recuerda que las coordenadas decrecen en y)
    int xB[2] = {B[0], B[0] + B[2]}; // Inicio y fin en x de B
    int yB[2] = {B[1], B[1] - B[3]}; // Inicio y fin en y de B

    // Validar si no hay intersección en el eje X
    if (xA[1] <= xB[0] || xB[1] <= xA[0]) {
        cout << "No hay intersección en el eje x." << endl;
        return;
    }

    // Validar si no hay intersección en el eje Y
    if (yA[1] >= yB[0] || yB[1] >= yA[0]) {
        cout << "No hay intersección en el eje y." << endl;
        return;
    }

    // Si hay intersección, calculamos el rectángulo de intersección
    int x_interseccion_inicio = max(xA[0], xB[0]);
    int x_interseccion_fin = min(xA[1], xB[1]);
    int y_interseccion_inicio = min(yA[0], yB[0]);
    int y_interseccion_fin = max(yA[1], yB[1]);

    // Ancho y alto del rectángulo de intersección
    int ancho_interseccion = x_interseccion_fin - x_interseccion_inicio;
    int alto_interseccion = y_interseccion_inicio - y_interseccion_fin;

    cout << "Rectángulo de intersección (x, y, ancho, alto): " << x_interseccion_inicio << ", " << y_interseccion_inicio 
         << ", " << ancho_interseccion << ", " << alto_interseccion << endl;
}


//////////////////////////////Problema 17/////////////////////////////////////////


// Función para encontrar la suma de los divisores propios de un número
int sumaDivisores(int num) {
    int suma = 0;
    for (int i = 1; i <= num / 2; i++) {  // Solo hasta num/2 para encontrar divisores propios
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma;
}

// Función que encuentra y suma todos los números amigables menores al número dado
void problema17() {
    int limite;
    cout << "Ingresa un número límite: ";
    cin >> limite;

    int sumaTotal = 0;

    // Iteramos sobre los posibles valores de a
    for (int a = 1; a < limite; a++) {
        int b = sumaDivisores(a);  // Suma de divisores de 'a'
        
        // Verificamos si b es mayor que a y si es un número amigable con a
        if (b > a && b < limite) {
            if (sumaDivisores(b) == a) {  // Verificar si b también es amigable con a
                sumaTotal += a + b;
                cout << "Pareja amigable encontrada: (" << a << ", " << b << ")" << endl;
            }
        }
    }

    cout << "El resultado de la suma es: " << sumaTotal << endl;
}





int main ()
{
    //problema1();
    //problema3();
    //problema5();
    //problema7();
    //problema9();
    
    return 0;
}







