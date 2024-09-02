#include <iostream>
#include <limits>
#include <string>
#include <cmath> 
#include <cstdlib> // Para rand(), srand()
#include <ctime>   

using namespace std; 


void ejercicio5()
// Programa que pide dos numeros e imprime la division n1/n2 con redondeo
{
    float n1, n2;
    cout<<"ingrese el primer numero"<<endl;
    cin>>n1;
    cout<<"ingrese el segundo numero"<<endl;
    cin>>n2;
    int division = (int)n1/n2 + 0.5;
    cout <<division;
    
}

void ejercicio11()
// Programa que pide un numero e imprime su tabla de multiplicar (hasta 10xN) 
{
    int n;
    cout<<"ingrese el numero"<<endl;
    cin>>n;
    for (int i=1; i<=10; i ++){
        int tabla (i*n);
        cout<<n<<"x"<<i<<"= "<<tabla<<endl;
    }
    
}
void ejercicio12()
//Programa que pide un número N e imprime todas las potencias desde N1 hasta N5
{
    int n;
    cout<<"ingrese el numero"<<endl;
    cin>>n;
    int potencia (n);
    for (int i=1; i<=5; i++){
        cout<<n<<"^"<<i<<"="<<potencia<<endl;
        potencia *= n;
    }
}
void ejercicio13()
//Programa que pida un número N e imprima todos los divisores
{
    int n;
    cout<<"ingrese el numero"<<endl;
    cin>>n;
    cout<<"los divisores de "<<n<<" son: "<<endl;
    for (int i=1;i<=n; i++){
        if (n%i==0){
            cout<<i<<endl;
        }
    }
}
void ejercicio14()
//Programa que imprime dos columnas paralelas,números del 1 al 50 y otra con los números del 50 al 1.
{
    int valorMaximo = 50;
    for (int i=1, j =valorMaximo; i<=valorMaximo;i++,j--){
        
        cout<<i;
        
        int espacio = 4;  // Espacio fijo de 4 caracteres para separación
        int num_dig = 0;  // Contar cuántos dígitos tiene el número actual i
        int calculo = i;
        
        // Calcular la longitud del número actual en la primera columna
        while (calculo > 0) {
            calculo /= 10; //division del numero para eliminar el ultimo digito
            num_dig++;
        }
        
        // Ajustar el número de espacios según el número de dígitos
        espacio -= num_dig;
        
        // Imprimir espacios para alinear la segunda columna
        for (int aux = 0; aux < espacio; ++aux) {
            cout << ' ';
        }

        // Imprimir el número en la segunda columna (descendente)
        cout << j << '\n';
        
    }
}

void ejercicio15()
//Programa que pida constantemente números hasta que se ingrese el numero cero
//e imprima en pantalla la suma de todos los números ingresados
{
    int n, suma = 0;
    do {
        cout<<"Ingrese un numero: ";
        cin>>n;
        if (n!=0){
            suma += n;
        }
        
    }while (n!=0);
    
    cout<<"la suma de todos los numeros ingresados es: "<<suma<<endl;
    
}

void ejercicio21 ()
//Programa que pide un carácter, si es una letra la debe convertir de
//mayúscula a minúscula y viceversa e imprimirla
{
        char c;
    do {
        cout << "Ingrese un carácter: ";
        cin >> c;

        // Verificar si el carácter es una letra
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (c >= 'A' && c <= 'Z') {
                // Convertir mayúscula a minúscula
                c = c + ('a' - 'A');
                cout << "Letra convertida: " << c << endl;
            } else {
                // Convertir minúscula a mayúscula
                c = c - ('a' - 'A');
                cout << "Letra convertida: " << c << endl;
            }
        } else {
            cout << "El carácter ingresado no es una letra. Inténtelo de nuevo." << endl;
        }
    } while (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')));
}

void ejercicio22()
// Programa que pide una cantidad entera de segundos e imprime 
// en formato horas:minutos:segundos
{
    int segundosT;
    cout << "Ingrese una cantidad entera de segundos" << endl;
    cin >> segundosT;
    
    int horas = segundosT / 3600;
    int minutos = (segundosT % 3600) / 60;
    int segundos = segundosT % 60;
    
    cout << horas << ":" << minutos << ":" << segundos << endl;
}

////////////////////////ejercicio23/////////////////////

int mcd(int a, int b)
// Calcula el máximo común divisor
{
    while (b != 0) 
    {
        int aux = b;
        b = (a % b);
        a = aux;
    }
    return a;
}

int cal_mcm(int a, int b) 
{
    // Calcular el MCD usando la función `mcd`
    int mcdaux = mcd(a, b);

    // volver positivo el producto de 'a' y 'b'
    int producto = a * b;
    if (producto < 0) {
        producto = -producto;
    }

    // Calcular el MCM usando el MCD
    int mcm = producto / mcdaux;

    return mcm;
}

void ejercicio23()
// Programa que pide dos números e imprime en pantalla 
// el mínimo común múltiplo entre los dos
{
    int num1, num2;
    cout << "Ingrese el primer numero: " << endl;
    cin >> num1;
    cout << "Ingrese el segundo numero: " << endl;
    cin >> num2;
    
    int mcm = cal_mcm(num1, num2);
    cout << "El minimo comun multiplo de " << num1 << " y " << num2 << " es " << mcm << endl;
}

void ejercicio24()
// Programa que pide un número entero e imprime un cuadrado de dicho tamaño,
// y el interior debe estar vacío.
{
    int n;
    cout << "Ingrese un número entero: ";
    cin >> n;

    if (n > 1) 
    {
        // Imprime la primera fila de '+' caracteres
        for (int i = 0; i < n; i++) 
        {
            cout << "+";
        }
        cout << endl;

        // Filas intermedias y espacios en el medio
        for (int i = 0; i < n - 2; i++) 
        {
            cout << "+";  // Lado izquierdo del cuadrado
            for (int j = 0; j < n - 2; j++) {
                cout << " ";  // Espacio vacío en el interior
            }
            cout << "+" << endl;  // Lado derecho del cuadrado
        }

        // Imprime la última fila de '+' caracteres
        for (int i = 0; i < n; i++) {
            cout << "+";
        }
        cout << endl;
        
    } 
    else 
        cout << "+" << endl;
    }

void ejercicio25()
// Programa que pide un número e imprime en pantalla la cantidad de dígitos que tiene
{
    int n;
    cout<<"Ingrese un numero: "<<endl;
    cin>>n;
    int contador(0), numero(n);
    if (numero == 0) 
    {
        contador = 1;
    } else {
        while (numero != 0){
            numero = numero/10;
            contador ++;
        }
    }
    cout<<"La cantidad de dijitos de "<< n << " es: "<<contador<<endl;
}

int main()
{

    // ejercicio5();
    // ejercicio11();
    // ejercicio12();
    // ejercicio13();
    // ejercicio14();
    // ejercicio15();
    // ejercicio21();
    // ejercicio22();
    // ejercicio23();
    // ejercicio24();
    // ejercicio25();
    
    return 0;
}

void ejercicio06()
{
    int A, B;
    cout << "Ingrese el valor de A: ";
    cin >> A;
    cout << "Ingrese el valor de B: ";
    cin >> B;
    int resultado = 1;
    for (int i = 0; i < B; ++i) {
        resultado *= A;
    }
    cout << A << "^" << B << " = " << resultado << endl;

    return 0;
}

voidejercicio07()
{
//Dado un numero N se imprime la suma de todos los numeros entre 0 y N
    int n, sum = 1, i = 1 ;
    do {
        cout <<"Ingrese un numero positivo" <<endl;
        cin >>n;
    } while (n<=0);
   
    for (int i=1; i<=n; i++)
    {
        sum=sum*i;
    }
   
    cout << sum;
}



voidejercicio08()
{ int N;
    cout << "Ingrese el valor de N: ";
    cin >> N;
    if (N < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
        return 1; /

    long long factorial = 1;
    for (int i = 1; i <= N; ++i) {
        factorial *= i;
    }

    cout << N << "!=" << factorial << endl;

    return 0;
}
}


voidejercicio09()
{

    const double PI = 3.1416;
    double radio;
    cout << "Ingrese el radio del círculo: ";
    cin >> radio;
    if (radio <= 0) {
        cout << "El radio debe ser un número positivo." << endl;
        return 1;
    }
    
    double perimetro = 2 * PI * radio;
    double area = PI * radio * radio;
    cout << "Perímetro: " << perimetro << endl;
    cout << "Área: " << area << endl;
    
    return 0;
}

voidejercicio10()
{
    int N;
    
    cout << "Ingrese un número: ";
    cin >> N;
    if (N <= 0) {
        cout << "El número debe ser positivo." << endl;
        return 1;
    }
    cout << "Múltiplos de " << N << " menores que 100:" << endl;
    for (int i = N; i < 100; i += N) {
        cout << i << endl;
    }

    return 0;
}

voidejercicio16()
{
        double suma = 0;
    int conteo = 0;
    int numero;
    cout << "Ingrese números (ingrese 0 para finalizar):" << endl;

    do {
        cin >> numero;
        if (numero != 0) {
            suma += numero;
            conteo++;
        }

    } while (numero != 0);

    if (conteo > 0) {
        double promedio = suma / conteo;
        cout << "El promedio es: " << promedio << endl;
    } else {
        cout << "No se ingresaron números para calcular el promedio." << endl;
    }

    return 0;
}


voidejercicio17()
{

    int numero;
    int mayor = std::numeric_limits<int>::min();

    cout << "Ingrese números (ingrese 0 para finalizar):" << endl;

    do {
        cin >> numero;
        if (numero > mayor) {
            mayor = numero;
        }

    } while (numero != 0);
    if (mayor != std::numeric_limits<int>::min()) {
        cout << "El número mayor fue: " << mayor << endl;
    } else {
        cout << "No se ingresaron números para determinar el mayor." << endl;
    }

    return 0;


}


voidejercicio18()

{

 int N;
    cout << "Ingrese un número: ";
    cin >> N;

    // Verificar si N es un número no negativo
    if (N < 0) {
        cout << "Un cuadrado perfecto no puede ser negativo." << endl;
        return 1; // Salir con un código de error
    }

    // Calcular la raíz cuadrada de N
    double raiz = sqrt(N);
    
    int raizEntera = static_cast<int>(round(raiz));
    if (raizEntera * raizEntera == N) {
        cout << N << " es un cuadrado perfecto." << endl;
    } else {
        cout << N << " NO es un cuadrado perfecto." << endl;
    }

    return 0;

}

bool esPrimo(int N) {
    if (N <= 1) return false;
    for (int i = 2; i <= sqrt(N); ++i) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

voidejercicio19()
{

int N;

    // Solicitar al usuario que ingrese un número
    cout << "Ingrese un número: ";
    cin >> N;

    // Verificar si el número es primo
    if (esPrimo(N)) {
        cout << N << " es un número primo." << endl;
    } else {
        cout << N << " NO es un número primo." << endl;
    }

    return 0;
}

//Para ejercicio 20
bool esPalindromo(int N) {
    string numeroStr = to_string(N);
    int longitud = numeroStr.length();
    for (int i = 0; i < longitud / 2; ++i) {
        if (numeroStr[i] != numeroStr[longitud - 1 - i]) {
            return false;
        }
    }
    
    return true;
}


voidejercicio20()
{
    int N;

    cout << "Ingrese un número: ";
    cin >> N;

    if (esPalindromo(N)) {
        cout << N << " es un número palíndromo." << endl;
    } else {
        cout << N << " NO es un número palíndromo." << endl;
    }

    return 0;

}

voidejecicio26()
{   // Variables para almacenar los tres lados del triángulo
    int lado1, lado2, lado3;

    // Solicitar al usuario que ingrese los tres lados
    cout << "Ingrese el primer lado: ";
    cin >> lado1;
    cout << "Ingrese el segundo lado: ";
    cin >> lado2;
    cout << "Ingrese el tercer lado: ";
    cin >> lado3;

    // Verificar si los lados forman un triángulo válido
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
        // Determinar el tipo de triángulo
        if (lado1 == lado2 && lado2 == lado3) {
            cout << "Se forma un triángulo equilátero." << endl;
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            cout << "Se forma un triángulo isósceles." << endl;
        } else {
            cout << "Se forma un triángulo escaleno." << endl;
        }
    } else {
        cout << "Las longitudes ingresadas no forman un triángulo." << endl;
    }

    return 0;

}

voidejercicio27()
{

    int a, b;
    char operacion;

    cout << "Ingrese el primer número: ";
    cin >> a;
    cout << "Ingrese el operador (+, -, *, /): ";
    cin >> operacion;
    cout << "Ingrese el segundo número: ";
    cin >> b;

    switch (operacion) {
        case '+':
            cout << a << " + " << b << " = " << (a + b) << endl;
            break;
        case '-':
            cout << a << " - " << b << " = " << (a - b) << endl;
            break;
        case '*':
            cout << a << " * " << b << " = " << (a * b) << endl;
            break;
        case '/':
            if (b != 0) {
                cout << a << " / " << b << " = " << (a / b) << endl;
            } else {
                cout << "Error: División por cero." << endl;
            }
            break;
        default:
            cout << "Operador no válido." << endl;
            break;
    }

    return 0;

}


voidejercicio28()

{

    
    int bajo = 0; // Rango inferior
    int alto = 100; // Rango superior
    int medio; // Número adivinado
    char respuesta; // Respuesta del usuario

    cout << "Piense en un número entre 0 y 100 y el programa intentará adivinarlo." << endl;

    while (bajo <= alto) {
        medio = (bajo + alto) / 2; // Adivinanza

        // Mostrar el número adivinado al usuario
        cout << "¿Es el número " << medio << "? (Ingrese '<' si es menor, '>' si es mayor, '=' si es correcto): ";
        cin >> respuesta;

        // Evaluar la respuesta del usuario
        if (respuesta == '=') {
            cout << "¡Adiviné! El número es " << medio << "." << endl;
            break; // Salir del bucle si el número es correcto
        } else if (respuesta == '<') {
            bajo = medio + 1; // Ajustar el rango inferior
        } else if (respuesta == '>') {
            alto = medio - 1; // Ajustar el rango superior
        } else {
            cout << "Respuesta no válida. Por favor, ingrese '<', '>', o '='." << endl;
        }
    }

    return 0;
}

voidejercicio29()
{
    int bajo = 0; // Rango inferior
    int alto = 100; // Rango superior
    int medio; // Número adivinado
    char respuesta; // Respuesta del usuario

    cout << "Piense en un número entre 0 y 100 y el programa intentará adivinarlo." << endl;

    while (bajo <= alto) {
        medio = (bajo + alto) / 2; // Adivinanza

        // Mostrar el número adivinado al usuario
        cout << "¿Es el número " << medio << "? (Ingrese '<' si es menor, '>' si es mayor, '=' si es correcto): ";
        cin >> respuesta;

        // Evaluar la respuesta del usuario
        if (respuesta == '=') {
            cout << "¡Adiviné! El número es " << medio << "." << endl;
            break; // Salir del bucle si el número es correcto
        } else if (respuesta == '<') {
            bajo = medio + 1; // Ajustar el rango inferior
        } else if (respuesta == '>') {
            alto = medio - 1; // Ajustar el rango superior
        } else {
            cout << "Respuesta inválida. Por favor, ingrese '<', '>', o '='." << endl;

    }

    return 0;
}
}

voidejercicio30()
{

    
    // Inicializar la semilla para el generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Generar un número aleatorio entre 0 y 100
    int numeroAleatorio = rand() % 101; // rand() % 101 genera un número entre 0 y 100
    int intento;
    int numeroIntentos = 0;

    cout << "He generado un número aleatorio entre 0 y 100. ¡Intenta adivinarlo!" << endl;

    do {
        // Leer el número ingresado por el usuario
        cout << "Ingresa tu adivinanza: ";
        cin >> intento;
        numeroIntentos++; // Incrementar el contador de intentos

        if (intento < numeroAleatorio) {
            cout << "El número es mayor que " << intento << "." << endl;
        } else if (intento > numeroAleatorio) {
            cout << "El número es menor que " << intento << "." << endl;
        } else {
            cout << "¡Felicidades! Has adivinado el número " << numeroAleatorio << " en " << numeroIntentos << " intentos." << endl;
        }
    } while (intento != numeroAleatorio);

    return 0;


}
