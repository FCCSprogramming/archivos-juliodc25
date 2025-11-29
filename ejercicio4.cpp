/*Escribe un programa que realice la multiplicacion de dos polinomios.
*/
#include <iostream>

using namespace std;

int main(){
    int grado1,grado2;
    cout<<"Grado del primer polinomio: ";
    cin>>grado1;
    cout<<"Grado del segundo polinomio: ";
    cin>>grado2;
    int coef1[grado1+1],coef2[grado2+1],resultado[grado1+grado2+1]={0};
    cout<<"Coeficientes del primer polinomio: ";
    for(int i=0;i<=grado1;i++){
        cin>>coef1[i];
    }
    cout<<"Coeficientes del segundo polinomio: ";
    for(int i=0;i<=grado2;i++){
        cin>>coef2[i];
    }
    cout<<"Primer polinomio: ";
    for(int i=0;i<=grado1;i++){
        cout<<coef1[i]<<"x^"<<i;
        if(i<grado1){ 
           cout<<" + ";
        }
    }
    cout<<endl;
    cout<<"Segundo polinomio: ";
    for(int i=0;i<=grado2;i++){
        cout<<coef2[i]<<"x^"<<i;
        if(i<grado2){
             cout<<" + ";
        }
    }
    cout<<endl;
    //Multiplicacion de polinomios
    for(int i=0;i<=grado1;i++){
        for(int j=0;j<=grado2;j++){
            resultado[i+j]+=coef1[i]*coef2[j];
        }
    }
    cout<<"Polinomio resultante: ";
    for(int i=0;i<=grado1+grado2;i++){
        cout<<resultado[i]<<"x^"<<i;
        if(i<grado1+grado2){
            cout<<" + ";
        }
    }
    return 0;
}