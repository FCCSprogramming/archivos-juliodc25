/*Un bus puede transportar diariamente entre 500 y 700 pasajeros.Considere un arreglo A
que contiene valores aleatorios del numero de pasajeros por cada dia del año,asuma que el año tiene 
12 meses de 30 dias.

escriba un programa que utilice un puntero a estructuras para crear un listado del numero de pasajeros
y fechas en la que el bus estuvo a un 95% o mas de su capacidad maxima.

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


struct TFECHA{
    int dia;
    int mes;
};
struct TCARGA{
    int numPasajeros;
    TFECHA* fecha;
};
int main(){
    const int DIAS_ANIO = 360;
    const int CAPACIDAD_MAXIMA = 700;
    TCARGA carga[DIAS_ANIO];
    TCARGA* pCarga = carga;
    int contador = 0;
    
    srand(time(0));
    for(int i=0; i<DIAS_ANIO; i++){
        pCarga->numPasajeros = rand() % 201 + 500;
        pCarga->fecha = new TFECHA;
        pCarga->fecha->dia = (i % 30) + 1;
        pCarga->fecha->mes = (i / 30) + 1;
        if(pCarga->numPasajeros >= CAPACIDAD_MAXIMA * 0.95){
            contador++;
        }
        pCarga++;
    }
    cout<<"Se encontraron "<<contador<<" dias con carga minima de 665 pasajeros"<<endl;
    for (int i = 0; i < DIAS_ANIO; i++){
        pCarga = &carga[i];
        if(pCarga->numPasajeros >= CAPACIDAD_MAXIMA * 0.95){
            cout<<right<<setw(2)<<pCarga->fecha->dia<<"/"<<right<<setw(2)<<pCarga->fecha->mes<<" :   "<<pCarga->numPasajeros<<" pasajeros"<<endl;            
        }
    }

    return 0;
}