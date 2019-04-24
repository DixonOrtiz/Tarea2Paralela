#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

void llenarArregloRandom(vector<int> &);
void mostrarArreglo(vector<int>);
float calcularPromedio(vector<int>);
float calcularDesviacion(vector<int>);
float calcularVarianza(vector<int>);


int main(){
    vector<int> arreglo;

    llenarArregloRandom(arreglo);
    mostrarArreglo(arreglo);

    cout << "Promedio valores: " << calcularPromedio(arreglo) << endl;
    cout << "Desviación Estandar: " << fixed << setprecision(2) << calcularDesviacion(arreglo) << endl;
    cout << "Varianza: " << fixed << setprecision(2) << calcularVarianza(arreglo) << endl;
    return 0;
}

void llenarArregloRandom(vector<int> &arreglo){
    srand(time(NULL));
    int num;

    for(int i = 0; i < 100000; i++){
        num=1+rand()%(100001-1);
        arreglo.push_back(num);
    }
}

void mostrarArreglo(vector<int> arreglo){
    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << endl;
    }
    cout << "VECTOR DE 100000 VALORES RANDOM ENTRE 1 Y 100000\n" << endl;
}

float calcularPromedio(vector<int> arreglo){
    float suma = 0;
    float promedio;

    for(int i = 0; i < arreglo.size(); i++){
        suma += arreglo[i];
    }

    promedio = suma/(arreglo.size());

    return promedio;
}

float calcularDesviacion(vector<int> arreglo){
    int promedio = calcularPromedio(arreglo);
    float sumatoriaCudrados = 0;
    float sumatoriaSobreTotal;
    float desviacion;

    for(int i = 0; i < arreglo.size(); i++)
        sumatoriaCudrados += pow((arreglo[i] - promedio), 2);

    sumatoriaSobreTotal = sumatoriaCudrados/(arreglo.size());
    desviacion = sqrt(sumatoriaSobreTotal);

    return desviacion;
}

float calcularVarianza(vector<int> arreglo){
    float varianza;
    varianza = pow(calcularDesviacion(arreglo), 2);

    return varianza;

}
