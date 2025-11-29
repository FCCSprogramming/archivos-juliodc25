/*Escriba un programa en C++ cuya funcion main() tenga la forma:
int main(){
    escribirFibonacciBinaerio();
    leerFibonacciBinario();
    return 0;
}
Donde:
a)La funcion escribirFibonacciBinario() escribe en el archivo binario fibonacci.bin los 20
primeros terminos de la sucesion de Fibonacci.
b)La funcion leerFibonacciBinario() lee desde el archivo binario fibonacci.bin los terminos
guardados en el item anterior y los imprime en pantalla    
*/
#include <iostream>
#include <fstream>

using namespace std;

void escribirFibonacciBinario(){
    ofstream archivo("fibonacci.bin",ios::out | ios::binary);
    if(!archivo){
        cerr << "¡Error!" << endl;
        return;
    }
    cout<<"Funcion escribirFibonacciBinario:"<<endl;
    int fib[20];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 20; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    archivo.write(reinterpret_cast<char*>(fib), sizeof(int)*20);
    cout<<"Terminos de Fibonacci escritos en el archivo correctamente."<<endl;
    archivo.close();
}

void leerFibonacciBinario(){
    ifstream archivo("fibonacci.bin",ios::in |ios::binary);
    if(!archivo){
        cerr<<"¡Error!"<<endl;
        return;
    }
    cout<<"Funcion leerFibonacciBinario:"<<endl;
    int fib[20];
    archivo.read(reinterpret_cast<char*>(fib), sizeof(int)*20);
        for(int i = 0;i<20;i++){
            cout<<"Termino "<<i+1<<": "<<fib[i]<<endl;
        }
    archivo.close();
}

int main(){
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}