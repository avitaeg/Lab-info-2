#include <iostream>
using namespace std;

/////////////////// Problema 10 ////////////////////////////////////

bool esPrimo(int numero) 
// Verificar si se ingresa un numero primo
{
    if (numero <= 1) 
    {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) 
    {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

void problema10(){

    int n;
    cout << "Introduce un número entero: ";
    cin >> n;

    int contador = 0;
    int numeroAux = 2;
    int primo;

    while (contador < n) {
        if (esPrimo(numeroAux)) {
            contador++;  // Incrementa el contador si es primo
            primo = numeroAux;  // Almacena el enésimo primo encontrado
        }
        numeroAux++;
    }           
    cout << "El primo numero " << n << " es: " << primo << endl;
}

//////////////////////Problema 11/////////////////////////////////////

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
    // Calcular el mcm usando la función `mcd`
    int mcdaux = mcd(a, b);

    // volver positivo el producto de 'a' y 'b'
    int producto = a * b;
    if (producto < 0) {
        producto = -producto;
    }

    int mcm = producto / mcdaux;

    return mcm;
}

void problema11()
{
    int n;
    cout<<"Ingrese un numero entero: "<<endl;
    cin>>n;
    int mcm = 1;
    for (int i = 1; i<=n; i++)
    {
    mcm = cal_mcm(mcm,i);
    }
    cout<<"El minimo comun multiplo es: "<<mcm<<endl;
    
}

//////////////////////Problema 12/////////////////////////////////////
void problema12()
//Programa que calcula el máximo factor primo de un número

{
    int n;
    cout<<"Ingrese un numero entero: "<<endl;
    cin>>n;
    
    int factorPrimomax = -1;
    
    while (n%2==0){
        factorPrimomax = 2;
        n /=2;
    } 
    for (int i = 3; i*i<=n;i+=2){
        while (n %i==0){
            factorPrimomax = i;
            n/=i;
        }
    }
    if (n>2){
        factorPrimomax = n;
    }
    cout<<"el mayor factor primo es: "<<factorPrimomax<< endl;
    
}
//////////////////////Problema 13/////////////////////////////////////
void problema13(){
    int n;
    cout<<"ingresa un numero: "<<endl;
    cin>>n;
    int sumaprimos = 0;
    for (int i =2; i <n;i++){
        if (esPrimo(i)){
            sumaprimos+=i;
        }
    }
    cout <<"El resultado de la suma es: "<<sumaprimos<<endl;
    
}
//////////////////////Problema 14/////////////////////////////////////
bool esPalindromo(int n){
    int original = n, inverso = 0, digito;
    
    //invertir el numero
    
    while (n>0){
        digito = n% 10;
        inverso = inverso*10+digito;
        n /=10;
    }
    return original == inverso;
}
void problema14(){
    int maxPalindromo = 0;
    int n1 = 0, n2 = 0;
    
    //iterar sobre todos los numeros de 3 digitos
    for (int i =100;i<=999;i++){
        for (int j =i;j<=999;j++){
            int producto = i*j;
            
            if (esPalindromo(producto)&&producto>maxPalindromo){
                maxPalindromo=producto;
                n1 = i;
                n2=j;
            }
        }
    }
    cout<<"el palindromo mas grande es: "<<maxPalindromo<< endl;
    cout<<"producto de: "<<n1<<"*"<<n2<<endl;
}
int main()
{
    //problema10();
    //problema11();
    //problema12();
    //problema13();
    problema14();
    return 0;
}