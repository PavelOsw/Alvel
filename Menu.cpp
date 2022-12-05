#include <iostream>
#include <windows.h>
#include <string.h>

// Headers
#include "headers/Facturas.h"
#include "headers/ListaReproduccion.h"
#include "headers/Pagos.h"
#include "headers/Peliculas.h"
#include "headers/Series.h"
#include "headers/Usuarios.h"

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
        cout<<"1) USUARIOS" <<endl;
        cout<<"2) PELICULAS" <<endl;
        cout<<"3) SERIES"<<endl;
        cout<<"4) LISTA DE REPRODUCCION" <<endl;
        cout<<"5) PAGOS"<<endl;
        cout<<"6) FACTURAS" << endl;
        cout<<"7) SALIR"<<endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        cout<<"\nINGRESA LA OPCION DESEADA: ";
        cin>>op;
        switch(op)
        {
        case 1:
            USUARIOS_H_INCLUDED;
            RegisUser.menuUser();
            system("cls");
            break;
        case 2:
            PELICULAS_H_INCLUDED;
            p.menuPeli();
            system("cls");
            break;
        case 3:
            SERIES_H_INCLUDED;
            pr.menuSerie();
            system("cls");
            break;
        case 4:
            LISTAREPRO_H_INCLUDED;
            firstClass.menuListaRepro();
            system("cls");
            break;
        case 5:
            PAGOS_H_INCLUDED;
            promo.menuPromo();
            system("cls");
            break;
        case 6:
            FACTURAS_H_INCLUDED;
            factura.menuFactura();
            system("cls");
            break;
        case 7:
            break;
        }
    }
    while(op!=7);
    return 0;
}
