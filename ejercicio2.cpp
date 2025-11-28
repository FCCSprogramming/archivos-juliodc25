/*El estado peruano en su politica de combatir el cambio climatico desea monitorear la 
superficie de las principales lagunas del pais, para ello en base a imagenes satelitales ha podido
triangular la region que ocupa cada laguna. Dicha informacion se almacena en archivos de texto con el
siguiente formato:
.En la primera linea se tiene el numero de triangulos(nt)
.En la segunda linea esta el numero de vertices(nv)
.En las siguientes nv lineas estan las coordenadas de los vertices
.En las siguientes nt lineas esta la numeracion de los vertices de los triangulos

Escriba un programa en C++ que lea el archivo laguna.txt en el formato descrito, calcule el area total
de la laguna y almecene el resultado en el archivo area.txt. Recuerde que el area de un triangulo de vertices
(x1,y1), (x2,y2), (x3,y3) es:

A= abs((x1(y3-y2)+x2(y1-y3)+x3(y2-y1))/2)
*/
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int nt, nv;
    nt=5;
    nv=7;
    float vertices[nv][2]={{0.0,0.0},{0.0,1.0},{0.0,2.0},{1.0,1.0},{1.5,1.0},{2.0,1.0},{2.0,2.0}};
    int triangulos[nt][3]={{1,2,4},{2,5,4},{2,3,5},{3,6,5},{5,6,7}};
    ofstream file1;
    file1.open("laguna.txt");
    file1<<nt<<endl;
    file1<<nv<<endl;
    for(int i=0;i<nv;i++){
        file1<<vertices[i][0]<<" "<<vertices[i][1]<<endl;
    }
    for(int i=0;i<nt;i++){
        file1<<triangulos[i][0]<<" "<<triangulos[i][1]<<" "<<triangulos[i][2]<<endl;
    }
    file1.close();
    fstream file2;
    file2.open("laguna.txt",ios::in);
    file2>>nt;
    file2>>nv;
    float vert[ nv ][ 2 ];
    int tri[ nt ][ 3 ];
    for(int i=0;i<nv;i++){
        file2>>vert[i][0]>>vert[i][1];
    }
    for(int i=0;i<nt;i++){
        file2>>tri[i][0]>>tri[i][1]>>tri[i][2];
    }
    file2.close();
    float areaTotal=0.0;
    for(int i=0;i<nt;i++){
        int v1=tri[i][0]-1;
        int v2=tri[i][1]-1;
        int v3=tri[i][2]-1;
        float x1=vert[v1][0];
        float y1=vert[v1][1];
        float x2=vert[v2][0];
        float y2=vert[v2][1];
        float x3=vert[v3][0];
        float y3=vert[v3][1];
        float areaTriangulo=abs((x1*(y3-y2)+x2*(y1-y3)+x3*(y2-y1))/2.0);
        areaTotal+=areaTriangulo;
    }
    file2.open("area.txt",ios::out);
    file2<<"El area total de la laguna es: "<<areaTotal<<endl; 
    file2.close();
    return 0;
}