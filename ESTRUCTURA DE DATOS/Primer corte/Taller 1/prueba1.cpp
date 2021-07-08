#include <iostream>
#include <string.h>

/**
 * TODO: Validar nombre.
 * TODO: Validar edad.
 * TODO: Organizar descendentemente.
 * TODO: Permitir solo caballos registrados.
 * TODO: Mostrar los caballos ganadores con su nombre del primer y segundo lugar de cada una de las carreras.
 * TODO: Mostrar el nombre del caballo que ha obtenido el mayor númerode carreras ganadas.
 * TODO: Mostrar el nombre del caballo que ha obtenido el mayor númerode carreras ganadas.
 */
using namespace std;

struct Caballo
{
    char nombre[50];
    float peso;
    int edad;
    char raza[50];
    float distancia;
    float tiempo;
    char jockey[50];
};

struct Carrera
{
    int numero;
    Caballo listaCaballos[4];
    Caballo caballoGanador;
    Caballo caballoSegundo;
    char jockeyGanador[50];
};

void preguntarDatos();
bool estaRepetido(char nombre[50]);
void preguntarCompeticion();
void ganadores(int i);
Caballo encontrarCaballo(char nombre[50]);
void mostrarGanadores();


Carrera competicion[10];
Caballo listaCaballos[4];
Caballo nuevoCaballo;

int main()
{
    system("clear"); // cls en windows
    preguntarDatos();
    return 0;
}

void preguntarDatos()
{
    bool repetido;
    for (int i = 0; i < 2; i++)
    {
        bool caballoValido;
        cout << "\nCABALLO " << i + 1 << endl;
        do
        {
            cout << "Ingrese nombre del caballo: ";
            cin >> nuevoCaballo.nombre;
            repetido = estaRepetido(nuevoCaballo.nombre);
            if (repetido == true)
            {
                cout << " ya lo registraste";
            }
        } while (repetido);
        // gotoxy(3, 4); cout << "                                  ";

        do
        {
            cout << "Ingrese la edad del caballo: ";
            cin >> nuevoCaballo.edad;
            if (nuevoCaballo.edad > 7)
            {
                cout << "Edad fuera de rango\n\n";
                caballoValido = false;
            }
            else
            {
                caballoValido = true;
            }
        } while (caballoValido == false);
        listaCaballos[i] = nuevoCaballo;
    }
    preguntarCompeticion();
}

void preguntarCompeticion()
{
    char nombreCaballo[50];
    bool registrado;
    system("clear"); // cls en windows

    for (int i = 0; i < 2; i++)
    {
        cout << "CARRERA " << i + 1 << "\n";
        for (int j = 0; j < 2; j++)
        {
            competicion[i].numero = i;
            do
            {
                cout << "\nNombre del caballo: ";
                cin >> nombreCaballo;
                registrado = estaRepetido(nombreCaballo);
                if (registrado == false)
                {
                    cout << "Caballo no registrado.\n";
                }
            } while (registrado == false);
            nuevoCaballo = encontrarCaballo(nombreCaballo);

            cout << "Nombre del jockey: ";
            cin >> nuevoCaballo.jockey;
            cout << "Distancia recorrida: ";
            cin >> nuevoCaballo.distancia;
            cout << "Tiempo transcurrido: ";
            cin >> nuevoCaballo.tiempo;
            ganadores(i);
        }
    }
    mostrarGanadores();
}

Caballo encontrarCaballo(char nombre[50])
{
    Caballo nada;
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(nombre, listaCaballos[i].nombre) == 0)
        {
            return listaCaballos[i];
        }
    }
    return nada;
}

bool estaRepetido(char nombre[50])
{
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(nombre, listaCaballos[i].nombre) == 0)
        {
            return true;
        }
    }
    return false;
}

void ganadores(int i)
{
    if (!competicion[i].listaCaballos)
    {
        competicion[i].caballoGanador = nuevoCaballo;
    }
    else
    {
        cout << competicion[i].listaCaballos[0].nombre;
        float velocidadGanador = competicion[i].caballoGanador.distancia / competicion[i].caballoGanador.tiempo;
        float velocidadActual = nuevoCaballo.distancia / nuevoCaballo.tiempo;
        if (velocidadActual > velocidadGanador)
        {
            competicion[i].caballoSegundo = competicion[i].caballoGanador;
            competicion[i].caballoGanador = nuevoCaballo;
        }
    }
}

void mostrarGanadores()
{
    // printf("\033\143");
    for (int i = 0; i < 2; i++)
    {
        cout << "\nResultado carrera " << i << "\n";
        cout << "Primer Lugar: " << competicion[i].caballoGanador.nombre << "\n";
        cout << "Segundo Lugar: " << competicion[i].caballoSegundo.nombre << "\n";
    }

}
