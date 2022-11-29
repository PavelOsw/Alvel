#include <iostream>
#include <windows.h>
#include <string.h>

// Headers
#include "headers/Facturas.h";
#include "headers/ListaReproduccion.h";
#include "headers/Pagos.h";
#include "headers/Peliculas.h";
#include "headers/Series.h";
#include "headers/Usuarios.h";

using namespace std;

int main()
{
    int op;
    facturaCliente      fact;
    reproduccionList    repro;
    Promocion           promo;
    Peliculas           peli;
    Series              serie;
    Orden               user;

    do
    {
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"                 --- PELICULAS, SERIES, NOVELAS Y + ---\n\n";
        SetConsoleTextAttribute(hConsole, 12);
        cout<<"                               A";
        SetConsoleTextAttribute(hConsole, 9);
        cout<<"\n                                L";
        SetConsoleTextAttribute(hConsole, 6);
        cout<<"\n                                 V";
        SetConsoleTextAttribute(hConsole, 14);
        cout<<"\n                                  E";
        SetConsoleTextAttribute(hConsole, 10);
        cout<<"\n                                   L";
        SetConsoleTextAttribute(hConsole, 13);
        cout<<"\n                                    +";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"\n\n                 BIENVENIDO AL SERVICIO DE STREAMING!";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\n\t\t\tMENU PRINCIPAL "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 3);
/*----------------------------------------------------------------------------------------*/
        cout<<"1.-Registro de usuario" <<endl;
        cout<<"2.-Mostrar registros" <<endl;
        cout<<"3.-Modificar "<<endl;
        cout<<"4.-Eliminar" <<endl;
        cout<<"5.-Buscar "<<endl;
        cout<<"6.-Salir "<<endl;
        cout<<"Ingresa la opcion: ";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            break;
        case 4:
            system("cls");
            break;
        case 5:
            system("cls");
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
    return 0;
}