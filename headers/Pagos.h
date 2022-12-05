#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define NUMREGISTROS 100
#define CONTENEDOR   4

class Promocion
{
    private:
        char folio[ 12 ];
        char nombre[ 35 ];
        char banco[ 35 ];
        char precio[ 10 ];

        int dispersion( const char llave[ 12 ] );
        long int buscarfolio( const string & );
    public:
        Promocion( void );
        Promocion( const Promocion & );
        void setFolio( const string & );
        void setNombre( const string & );
        void setBanco( const string & );
        void setPrecio( const string & );
        friend ostream &operator<<( ostream &, const Promocion & );

        void menuPromo( void );
        bool agregar( const Promocion & );
        void mostrar( void );
        bool buscar( const string &, Promocion & );
        bool eliminar( const string &, Promocion & );
        bool modificar( const string &, const Promocion & );
        void mostrarIndice( void );
        Promocion pedirRegistro( void );
        bool contiene( const string & );
        void genera( void );
};


// constructor
Promocion::Promocion( void )
{
    for( int i = 0; i < sizeof( folio ); folio[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( nombre ); nombre[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( banco ); banco[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( precio ); precio[ i++ ] = '\0' );
}


bool Promocion::contiene( const string &folioABuscar )
{
    if( buscarfolio( folioABuscar ) == -1 )
        return false;
    return true;
}


Promocion Promocion::pedirRegistro( void )
{
    Promocion registroARetornar;
    string cadena;

    cout << endl << "Folio: ";
    fflush( stdin );
    getline( cin, cadena );
    while( contiene( cadena ) || cadena.size() == 0 )
    {
        cout << "Ese Folio ya existe o la cadena es invalida: ";
        fflush( stdin );
        getline( cin, cadena );
    }
    registroARetornar.setFolio( cadena );

    cout << "Nombre: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setNombre( cadena );

    cout << "Banco: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setBanco( cadena );

    cout << "Precio: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setPrecio( cadena );

    return registroARetornar;
}



void Promocion::genera( void )
{
    Promocion promo;
    int contador = 0;
    ofstream archivo( "pagos.txt", ios::out );
    if( !archivo )
        cout << "No se pudo crear el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
        	// indica cuantos registros hay en el contenedor
        	archivo.write( ( char * ) &contador, sizeof( int ) );
        	for( int j = 0; j < CONTENEDOR; j++ )
            	archivo.write( ( char * ) &promo, sizeof( Promocion ) );
        }
    archivo.close();
}

int Promocion::dispersion( const char llave[ 12 ] )
{
    // llena la el sobrante de la llave con espacios
    char llaveCopia[ 12 ];
    strcpy( llaveCopia, llave );
    if( strlen( llaveCopia ) < 12 )
        for( int i = strlen( llaveCopia ); i < 12; i++ )
            llaveCopia[ i ] = ' ';
    llaveCopia[ 12 ] = '\0';

    // realiza el algoritmo
    long sum = 0;
    int j = 0;
    while( j < 12 )
    {
        sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] )  % 20000;
        j += 2;
    }
    return ( sum % 99 ); // retorna la posición donde se guardará el registros.
}

// retorna la posición donde se encontro el registro
long int Promocion::buscarfolio( const string &folioABuscar )
{
    Promocion promo;
    int contador, posIndice;
    long int posByte;

    ifstream archivo( "pagos.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return -1;
    }

    posIndice = dispersion( folioABuscar.c_str() );
    posByte = posIndice * ( ( sizeof( Promocion ) * CONTENEDOR ) + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    if( contador > 0 )
    {
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( Promocion ) );
            if( strcmp( promo.folio, folioABuscar.c_str() ) == 0 )
            {
                posByte = ( long )archivo.tellg() - sizeof( Promocion );
                archivo.close();
                return posByte;
            }
        }
    }

    archivo.close();
    return -1;
}

void Promocion::setFolio( const string &valorfolio )
{
    int longitud = valorfolio.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorfolio.copy( folio, longitud );
    folio[ longitud ] = '\0';
}

void Promocion::setNombre( const string &valorNombre )
{
    int longitud = valorNombre.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorNombre.copy( nombre, longitud );
    nombre[ longitud ] = '\0';
}

void Promocion::setBanco( const string &valorBanco )
{
    int longitud = valorBanco.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorBanco.copy( banco, longitud );
    banco[ longitud ] = '\0';
}

void Promocion::setPrecio( const string &valorPrecio )
{
    int longitud = valorPrecio.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorPrecio.copy( precio, longitud );
    precio[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const Promocion &promocion )
{
    salida << "Folio:        " << promocion.folio << endl
            << "Producto:  " << promocion.nombre << endl
            << "Banco: " << promocion.banco << endl
            << "Precio:    " << promocion.precio << endl;

    return salida;
}

bool Promocion::agregar( const Promocion &nuevaPromocion )
{
    Promocion promo;
    string cadena;
    int posIndice, contador;
    long int posByte;
    string folioString = nuevaPromocion.folio;

    if( contiene( folioString ) )
        return false;

    fstream archivo( "pagos.txt", ios::in | ios::out );
    posIndice = dispersion( nuevaPromocion.folio );
    cout << "Se guardara en la posicion indice: " << posIndice << endl;
    posByte = posIndice * ( sizeof( Promocion ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) ); // lee el numero de registros en el contador
    if( contador < CONTENEDOR ) // si el contenedor no esta lleno
    {
        // aumenta el contador y lo escribe
        contador++;
        archivo.seekg( posByte, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // escribe el nuevo registro en el contenedor
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &promo, sizeof( Promocion ) );
            if( promo.folio[ 0 ] == '\0' )
            {
                archivo.seekg( ( long )archivo.tellg() - sizeof( Promocion ), ios::beg );
                archivo.write( ( char * ) &nuevaPromocion, sizeof( Promocion ) );
                archivo.close();
                return true;
            }
        }

    }
    else
        cout << endl << "No hay mas espacio para este registro" << endl;
    archivo.close();
    return false;
}

void Promocion::mostrar( void )
{
    Promocion promo;
    int contador;
    long int posByte;

    ifstream archivo( "pagos.txt", ios::in );
    if( !archivo )
        cout << "No existe el archivo" << endl;
    else
    {
        cout << endl;
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
            archivo.read( ( char * ) &contador, sizeof( int ) );
            if( contador > 0 )
            {
                for( int j = 0; j < CONTENEDOR; j++ )
                {
                    archivo.read( ( char * ) &promo, sizeof( Promocion ) );
                    if( promo.folio[ 0 ] != '\0' ){
                        cout<<"=======================================================\n";
                        cout << promo << endl;
                        cout<<"=======================================================\n";
                    }
                }
            }
            else
                archivo.seekg( sizeof( Promocion ) * CONTENEDOR, ios::cur );
        }
    }
    archivo.close();
}

bool Promocion::buscar( const string &folioABuscar, Promocion &promocionEncontrada )
{
    long int posByte;

    if( !contiene( folioABuscar ) )
        return false;

    ifstream archivo( "pagos.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return false;
    }

    posByte = buscarfolio( folioABuscar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &promocionEncontrada, sizeof( Promocion ) );
    archivo.close();
    return true;
}

bool Promocion::modificar( const string &folioAModificar, const Promocion &promocionNueva )
{
    Promocion registroLimpio, promo;
    int posIndiceAntiguo, posIndiceNuevo, contador;
    long int posByteAntiguo, posByteNuevo;

    if( !contiene( folioAModificar ) )
        return false;

    fstream archivo( "pagos.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posIndiceAntiguo = dispersion( folioAModificar.c_str() );
    posByteAntiguo = buscarfolio( folioAModificar );
    posIndiceNuevo = dispersion( promocionNueva.folio );
    posByteNuevo = posIndiceNuevo * ( sizeof( Promocion ) * CONTENEDOR + sizeof( int ) );

    if( posByteAntiguo == posByteNuevo )
    {
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &promocionNueva, sizeof(  Promocion) );
    }
    else
    {
        // quita el registro antiguo y resta uno al contador del contenedor
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &registroLimpio, sizeof( Promocion ) );
        posByteAntiguo = posIndiceAntiguo * ( sizeof( Promocion ) * CONTENEDOR + sizeof( int ) );
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        contador--;
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // intenta meter el nuevo registro en la nueva posicion
        archivo.seekg( posByteNuevo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        if( contador < CONTENEDOR )
        {
            // aumenta el contador y lo escribe
            contador++;
            archivo.seekg( posByteNuevo, ios::beg );
            archivo.write( ( char * ) &contador, sizeof( int ) );

            // escribe el nuevo registro en el contenedor
            for( int i = 0; i < CONTENEDOR; i++ )
            {
                archivo.read( ( char * ) &promo, sizeof( Promocion ) );
                if( promo.folio[ 0 ] == '\0' ) // si el lugar no esta ocupado
                {
                    archivo.seekg( ( long )archivo.tellg() - sizeof( Promocion ), ios::beg );
                    archivo.write( ( char * ) &promocionNueva, sizeof( Promocion ) );
                    archivo.close();
                    return true;
                }
            }
        }
        else // el contenedor esta lleno
            return false;
    }
} // fin funcion modificar

bool Promocion::eliminar( const string &folioAEliminar, Promocion &destinoEliminado )
{
    Promocion promo;
    int posIndice, posByte, contador;

    if( !contiene( folioAEliminar ) )
        return false;

    fstream archivo( "pagos.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posIndice = dispersion( folioAEliminar.c_str() );
    posByte = buscarfolio( folioAEliminar );

    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &destinoEliminado, sizeof(  Promocion) );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &promo, sizeof(  Promocion) );

    posByte = posIndice * ( sizeof( Promocion ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    contador--;
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &contador, sizeof( int ) );
    archivo.close();
    return true;
}


void Promocion :: menuPromo( void )
{
    Promocion promocion, promocionBuscar, promocionModificar, promocionEliminar, registroAgregar;
    string folioABuscar, folioAModificar, folioAEliminar;
    char opcion, op;

    promocion.genera();
    system( "cls" );

    do{
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"                           --- PAGOS ---\n\n";
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
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\n\t\t\tMENU PRINCIPAL "<<endl<<endl;
        SetConsoleTextAttribute(hConsole, 3);

        /*----------------------------------------------------------------------------------------*/
        cout<< endl
            << "1) AGREGAR"   << endl
            << "2) MOSTRAR"   << endl
            << "3) BUSCAR"    << endl
            << "4) MODIFICAR" << endl
            << "5) ELIMINAR"  << endl
            << "6) SALIR"     << endl
            << endl;
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        cout<<"\nINGRESA LA OPCION DESEADA: ";
        cin >> opcion;
        switch( opcion )
        {
          case '1':
            registroAgregar = promocion.pedirRegistro();
            if( promocion.agregar( registroAgregar ) ){
                cout<<"=======================================================\n";
                cout << "Cliente agregado con exito" << endl;
                cout<<"=======================================================\n";
            }else
                cout << "No se agrego la promocion" << endl;
            break;

          case '2':
            system( "cls" );
            promocion.mostrar();
            break;

          case '3':
            cout << "Ingrese el folio del pago a buscar: ";
            fflush( stdin );
            getline( cin, folioABuscar );
            if( promocion.buscar( folioABuscar, promocionBuscar ) )
                cout << endl << promocionBuscar << endl;
            else
                cout << "No existe el registro" << endl;
            break;

          case '4':
            cout << "Ingrese el folio del pago a modificar: ";
            fflush( stdin );
            getline( cin, folioAModificar );
            if( promocion.buscar( folioAModificar, promocionBuscar ) )
            {
                cout << endl << promocionBuscar << endl;
                cout << "Desea modificarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                {
                    promocionModificar = promocion.pedirRegistro();
                    if( promocion.modificar( folioAModificar, promocionModificar ) ){
                        cout<<"=======================================================\n";
                        cout << endl << "Promocion modificada con exito" << endl;
                        cout<<"=======================================================\n";
                    }else
                        cout << endl << "No se pudo modificar" << endl;
                }
            }
            else
                cout << "No existe el registro" << endl;
            break;

          case '5':
            cout << "Ingrese el folio del pago a eliminar: ";
            fflush( stdin );
            getline( cin, folioAEliminar );
            if( promocion.buscar( folioAEliminar, promocionBuscar ) )
            {
                cout << endl << promocionBuscar << endl;
                cout << "Desea eliminarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                    if( promocion.eliminar( folioAEliminar, promocionEliminar ) ){
                        cout<<"=======================================================\n";
                        cout << endl << promocionEliminar << endl << "SE ELIMINO CORRECTAMENTE" << endl;
                        cout<<"=======================================================\n";
                    }else
                        cout << "NO SE PUDO ELIMINAR" << endl;
            }
            else
                cout << "No existe el registro" << endl;
            break;
        }
        cout << endl;
        system("Pause");
        system( "cls" );
    }while(opcion != '6');
}
#endif
