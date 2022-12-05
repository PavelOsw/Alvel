#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


using namespace std;

class Peliculas
{
public:
    char codigoPelicula[200], pelicula[200], categoria[200];

    void menuPeli();
    void Agregar();
    void Imprimir();
    void Buscar();
    void Eliminar();
    void Modificar();
}p;



void Peliculas::Agregar()
{
    cout<<"\n==================================================================\n";
    cout<<"                       AGREGAR UNA PELICULA\n";
    cout<<"\nASIGNA UN CODIGO DE PELICULA: ";
    cin.getline(codigoPelicula, 200);
    cin.getline(codigoPelicula, 200);
    cout<<"NOMBRE DE LA PELICULA: ";
    cin.getline(pelicula,200);
    cout<<"ASIGNA CATEGORIA DE LA PELICULA: ";
    cin.getline(categoria,200);
    ofstream Archivo("delimitadorPelicula.txt",ios::app);
    Archivo<<codigoPelicula<<'|'<<pelicula<<'|'<<categoria<<'|';
    Archivo.close();
    cout<<"\n==================================================================\n";
}


void Peliculas::Imprimir()
{
    int i;
    ifstream Lectura("delimitadorPelicula.txt");
    if(!Lectura.good())
    {
        cout<<"No existe el archivo\n";
        system("pause");
    }
    else
    {
        while(!Lectura.eof())
        {

            i=0;
            do
            {
                Lectura.read((char *)&codigoPelicula[i],1);
                if(Lectura.eof())
                    break;
                    i++;
            }while(codigoPelicula[i-1]!='|');
            codigoPelicula[i-1]='\0';

            i=0;
            do
            {
                Lectura.read((char *)&pelicula[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(pelicula[i-1]!='|');
            pelicula[i-1]='\0';

            i=0;
            do
            {
                Lectura.read((char *)&categoria[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(categoria[i-1]!='|');
            categoria[i-1]='\0';


            if(Lectura.eof())
                break;


            cout<<"\n==================================================================\n";
            cout<<"                   PELICULA "<<pelicula<<" EN ALVO +";
            cout<<"\n==================================================================\n";
            cout<<endl<<"CODIGO: "<<codigoPelicula<<endl<<"\nPELICULA: "<<pelicula<<endl<<"\nCATEGORIA: "<<categoria<<endl<<"\n";
            if(Lectura.eof())
                break;
        }
        system("pause");
    }
    Lectura.close();
}

void Peliculas::Buscar(){
    int b;  b = 0;
    int i;
    int iguales;
    char caracter;
    char alubus[10];


    ifstream arc("delimitadorPelicula.txt");
    if(!arc.good())
    {
        cout<<"\n NO EXISTE ARCHIVO...\n";
    }

    else{
        cout<<"\n==================================================================\n";
        cout<<"                      BUSCADOR DE PELICULAS\n";
        cout<<"==================================================================\n";
        cout<<"\nESCRIBE EL CODIGO DE LA PELICULA: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);


        while(!arc.eof()){
            i = 0;
            do{
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    codigoPelicula[i] = caracter;
                    i++;
                }

            }while(caracter != '|');

            codigoPelicula[i]= '\0';

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                   pelicula[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            pelicula[i]= '\0';


            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof())
                {
                    categoria[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof());
            categoria[i]= '\0';


            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(codigoPelicula,alubus);

            if(iguales == 0){
                cout<<"\n CODIGO: "<<codigoPelicula<<"\n PELICULA: "<<pelicula<<"\n CATEGORIA: " <<categoria <<endl<<"\n";
                b = 1;
                cout<<"==================================================================\n";
                break;
            }
        }

        if( b == 0){
            cout<<"\n\n UPSS! ERROR... \n\n";
        }
        arc.close();
    }
}

void Peliculas::Eliminar(){
    int b = 0;
    int i;
    int iguales,respuesta; respuesta = 0;
    char caracter;
    char alubus[10];


    ifstream arc("delimitadorPelicula.txt");
    if(!arc.good())
    {
        cout<<"\n NO EXISTE ARCHIVO...\n";
    }
    else{
        cout<<"\n==================================================================\n";
        cout<<"                      ELIMINADOR DE PELICULAS\n";
        cout<<"\nESCRIBE EL CODIGO DE LA PELICULA: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);

        while(!arc.eof()){
            i = 0;
            do{
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    codigoPelicula[i] = caracter;
                    i++;
                }

            }while(caracter != '|');

            codigoPelicula[i]= '\0';

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    pelicula[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            pelicula[i]= '\0';

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof())
                {
                    categoria[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof());
            categoria[i]= '\0';


            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(codigoPelicula,alubus);

            if(iguales == 0){
                cout<<"\nCODIGO: " <<codigoPelicula<<"\nPELICULA: " <<pelicula <<"\nCATEGORIA: " <<categoria <<endl<<"\n";
                b = 1;
                cout<<"\n==================================================================\n";
        }


        }
        arc.close();
        }

        if(b == 0) {
            cout<<"\n\n UPSS! ERROR...\n\n";
        }
        if(b == 1){

            cout<<"\nTECLEA [1] SI DESEAS BORRAR: ";

            cin>>respuesta;

            if(respuesta == 1){
                ifstream arc ("delimitadorPelicula.txt");
                ofstream temporal ("temporalauto.txt",ios::app);

                while(!arc.eof()){
                    i = 0;
                    do{
                        arc.read((char*)&caracter,1);
                        if(caracter!='|')

                        {
                            codigoPelicula[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|');
                    codigoPelicula[i]= '\0';

                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|')
                        {

                            pelicula[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|');
                    pelicula[i]= '\0';

                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|' && !arc.eof())
                        {
                            categoria[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|' && !arc.eof());
                    categoria[i]= '\0';

                   if(arc.eof())
                    {
                        break;
                    }

                    iguales = strcmp(codigoPelicula,alubus);
                    if(iguales != 0){
                        temporal <<codigoPelicula<<"|"<<pelicula<<"|"<<categoria<<"|";

                    }
                }

                arc.close();
                temporal.close();
                remove("delimitadorPelicula.txt");
                rename("temporalauto.txt","delimitadorPelicula.txt");
                cout<<"\n\n PELICULA ELIMINADA EXITOSAMENTE \n\n";
                b = 1;
                cout<<"\n==================================================================\n";
            }

            else {
                cout<<"\nUPSS! ERROR... \n\n";
            }

        }

}

void Peliculas::Modificar()
{
    int i;
    int opcion;
    char prodMod[10];
    bool b;

    ifstream Lectura("delimitadorPelicula.txt");
    ofstream LecturaTemporal("temporalauto.txt",ios::app);

    if(!Lectura.good())
        cout<<"\nUPSS! ERROR...\n ";
    else
    {
        cout<<"\n==================================================================\n";
        cout<<"                      MODIFICADOR DE PELICULAS\n";
        cout<<"\nESCRIBE EL CODIGO DE LA PELICULA: ";
        cin.getline(prodMod,10);
        cin.getline(prodMod,10);

        b = false;

        while(!Lectura.eof()){

            i=0;
            do{
                Lectura.read((char*)&codigoPelicula[i],1);
                if(Lectura.eof()) break;
                i++;
            }while(codigoPelicula[i-1]!='|');
            codigoPelicula[i-1]='\0';
            if(Lectura.eof()) break;

            i=0;
            do{
                Lectura.read((char*)&pelicula[i],1);
                if(Lectura.eof()) break;
                i++;
            }while(pelicula[i-1]!='|' && !Lectura.eof());
            pelicula[i-1]='\0';
            if(Lectura.eof()) break;


            i=0;
            do{
                Lectura.read((char*)&categoria[i],1);
                if(Lectura.eof()) break;
                i++;
            }while(categoria[i-1]!='|');
            categoria[i-1]='\0';
            if(Lectura.eof()) break;

            if(strcmp(codigoPelicula,prodMod)==0 && !b)
            {
                cout<<endl<<"CODIGO: "<<codigoPelicula<<"\nPELICULA: "<<pelicula<<"\nCATEGORIA: "<<categoria<<endl;
                cout<<"\nQUE DESEAS MODIFICAR?\n ";
                cout<<"\n1.- CODIGO: ";
                cout<<"\n2.- PELICULA: ";
                cout<<"\n3.- CATEGORIA: ";
                cout<<"\n4.- REGRESAR";
                cout<<"\n==================================================================\n";
                cout<<"\nOPCION: ";
                cin>>opcion;


                switch(opcion)
                {
                    case 1:
                        cout<<"\nNUEVO CODIGO: ";
                        cin.getline(codigoPelicula,10);
                        cin.getline(codigoPelicula,10);
                        break;
                    case 2:
                        cout<<"\nNUEVA PELICULA: ";
                        cin.getline(pelicula,35);
                        cin.getline(pelicula,35);
                        break;
                    case 3:
                        cout<<"\nNUEVA CATEGORIA: ";
                        cin.getline(categoria,15);
                        cin.getline(categoria,15);
                        break;
                    default: cout<<"\nUPSS! ERROR...";
                }

                if(opcion!=6 && opcion>0 && opcion<7)
                    b = true;
            }
            LecturaTemporal<<codigoPelicula<<'|'<<pelicula<<'|'<<categoria<<'|';
        }
        Lectura.close();
        LecturaTemporal.close();
        if(!b)
            cout<<"\nUPSS! NO SE ENCONTRO ARCHIVO";

        remove("delimitadorPelicula.txt");
        rename("temporalauto.txt","delimitadorPelicula.txt");
    }
}


void Peliculas :: menuPeli(){
    int opc;
    do{
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"                        --- PELICULAS ---\n\n";
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
        cout<<"\nMENU PRINCIPAL: ";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"\n\n1) AGREGAR \n";
        cout<<"2) IMPRIMIR \n";
        cout<<"3) BUSCAR\n";
        cout<<"4) MODIFICAR\n";
        cout<<"5) ELIMINAR\n";
        cout<<"6) SALIR\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        cout<<"\nINGRESA LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc){
            case 1: p.Agregar();
                break;

            case 2: p.Imprimir();
                break;

            case 3: p.Buscar();
                break;

            case 4: p.Modificar();
                break;

            case 5: p.Eliminar();
                break;

            case 6:
                break;
        }

    }while(opc!=6);
}
#endif
