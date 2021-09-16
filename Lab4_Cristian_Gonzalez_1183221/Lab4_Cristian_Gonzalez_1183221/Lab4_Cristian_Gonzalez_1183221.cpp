// Lab4_Cristian_Gonzalez_1183221.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
    char camino[70];
    int probalidadt[10] = { 3,3,3,3,3,-6,-6,1,1,1 };
    int probalidadl[10] = { 0,0,9,9,-12,1,1,1,-2,-2 };
    char* tortuga = &camino[0];
    char* liebre = &camino[0];
    int opcion=1;
    int aleatoriot;
    int aleatoriol;
    for (int  i = 0; i < 70; i++)
    {
        camino[i] = 'X';
    }
    int j = 0;
    int k = 0;
    *tortuga = 'T';
    *liebre = 'L';
    cout << "LISTOS\n";
    cout << "YA\n";
    while (opcion==1)
    {
        camino[j] = 'X';
        camino[k] = 'X';
        aleatoriot = rand() % 10;
        aleatoriol = rand() % 10;
        j += probalidadt[aleatoriot];
        k += probalidadl[aleatoriol];
        if (j < 0)
        {
            tortuga = &camino[0];
            j = 0;
        }
        else if (j >=70)
        {
            tortuga = &camino[69];
            j = 69;
        }
        else
        {
            tortuga = &camino[j];
        }
        if (k < 0)
        {
            liebre = &camino[0];
            k = 0;
        }
        else if (k >= 70)
        {
            liebre = &camino[69];
            k = 69;
        }
        else
        {
            liebre = &camino[k];
        }
        *tortuga = 'T';
        *liebre = 'L';
        if (tortuga == liebre) {
            cout << "OUCH";
        }
        else
        {
            for (int i = 0; i < 70; i++)
            {
                cout << camino[i];
                cout << " ";
            }
        }
        cout << "\n";
        if (tortuga != &camino[69] && liebre != &camino[69]) 
        {
            cout << "DESEA CONTINUAR: 1.SI 2. NO";
            cin >> opcion;
        }
        else if(tortuga == &camino[69] && liebre != &camino[69])
        {
            cout << "La tortuga ha ganado. VIVA";
            opcion == 2;
        }
        else if(tortuga != &camino[69] && liebre == &camino[69])
        {
            cout << "La liebre gana. Ya ni modo";
            opcion == 2;
        }
        else if(tortuga == &camino[69] && liebre== &camino[69])
        {
            cout << "Un empate, quizas para la proxima";
            opcion == 2;
        }
        system("PAUSE");
    }
    cout << "El proceso ha terminado";
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
