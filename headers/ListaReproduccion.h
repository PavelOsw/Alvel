#ifndef LISTAREPRO_H_INCLUDED
#define LISTAREPRO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <windows.h>


using namespace std;
int orden=0;

class reproduccionList
{
    public:
    char pelicula[100], nombrePelicula[35], categoria[40],anio[20];

    void agregar();
    void imprimir();
    void buscar();
    void modificar();
    void eliminar();
    void Mostrar_Indice();
    void Orden();
}firstClass;

class Indice
{
    public:
    char peliculaIndice[100];
    long int pos;

}indizacion;

void reproduccionList::imprimir()
{
    ifstream a("datos.txt");
    if(!a.good())
    cout<<"No existe el archivo...";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&firstClass,sizeof(firstClass));
            if(a.eof())
                break;
            cout<<"\nID lista:"<<firstClass.pelicula<<endl<<"Nombre de la pelicula: "<<firstClass.nombrePelicula<<endl<<"Categoria: "<<firstClass.categoria<<endl<<"Year: "<<firstClass.anio<<endl;
        }
    }
    a.close();
}

void reproduccionList::Mostrar_Indice()
{
  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&indizacion,sizeof(indizacion));
            if(a.eof())
                break;
            cout<<"No. Lista de Reproduccion: "<<indizacion.peliculaIndice<<endl<<endl;
        }
    }
    a.close();
}




void reproduccionList::agregar()
{
    fflush(stdin);
    cout<<"Ingresa ID de LRP (Lista de reproduccion):"<<endl;
    cin.getline(pelicula,14);
    cout<<"Nombre de pelicula: "<<endl;
    cin.getline(nombrePelicula,35);
    cout<<"Categoria: "<<endl;
    cin.getline(categoria,40);
    cout<<"Year: "<<endl;
    cin.getline(anio,20);
    fflush(stdin);
    ofstream a("datos.txt",ios::app);
    a.write((char*)&firstClass,sizeof(firstClass));
    indizacion.pos=a.tellp();
    indizacion.pos-=sizeof(firstClass);
    a.close();
    strcpy(indizacion.peliculaIndice,pelicula);
    ofstream b("indice.txt",ios::app);
    b.write((char*)&indizacion,sizeof(indizacion));
    b.close();
    orden++;
    cout<<"=======================================================\n";
    cout<<"SE AGREGO A LA LISTA DE REPDORUCCION CORRECTAMENTE!!\n";
    cout<<"=======================================================\n";
}

void reproduccionList::buscar()
{
    char peliculabus[80];
    int band=0;

    ifstream b("indice.txt");
    if(!b.good()){
    cout<<"No existe el archivo";}
    else{
    cout<<"\nIngresa ID: "<<endl;
    fflush(stdin);cin.getline(peliculabus, 100);
    while(!b.eof())
    {
        b.read((char*)&indizacion,sizeof(indizacion));
        if(b.eof())
        {
            break;
        }
        if(strcmp(indizacion.peliculaIndice,peliculabus)==0)
        {
            ifstream a("datos.txt");
            a.seekg(indizacion.pos,ios::beg);
            a.read((char*)&firstClass,sizeof(firstClass));
            cout<<"No. Lista de Reproduccion: "<<firstClass.pelicula<<endl<<"Nombre de la pelicula: "<<firstClass.nombrePelicula<<endl<<"Categoria: "<<firstClass.categoria<<endl<<"Year:"<<firstClass.anio<<endl;
            a.close();
            band=1;
            break;
        }
    }
    if(band==0)
    {
     cout<<"\n NO EXISTE REGISTRO....."   ;
    }
    }
    b.close();

}

void reproduccionList::modificar()
{
     char peliculamod[15];
     int band=0;
     int opc;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nIngresa ID a modificar: "<<endl;
     fflush(stdin);cin.getline(peliculamod,14);
     while(!b.eof())
    {   opc=0;
        b.read((char*)&indizacion,sizeof(indizacion));
        if(b.eof())
        {
            break;
        }
        if(strcmp(indizacion.peliculaIndice,peliculamod)==0 && band==0)
        {
            ifstream a("datos.txt");
            a.seekg(indizacion.pos,ios::beg);

             a.read((char*)&firstClass,sizeof(firstClass));
             if(a.eof())   break;
            cout<<"No. Lista de Reproduccion: "<<firstClass.pelicula<<endl<<"Nombre: "<<firstClass.nombrePelicula<<endl<<"Categoria: "<<firstClass.categoria<<endl<<"Year:"<<firstClass.anio<<endl;
            cout<<"Deseas modificarlo? "<<"1. [Si]  2.[No] \n"; cin>>opc;
            band=1;
            a.close();
            break;
         }
         }
         b.close();
         if(opc==1)
{
    fflush(stdin);
    ifstream indice("indice.txt");
    ifstream datos("datos.txt");
          while(!indice.eof())
         {
          indice.read((char*)&indizacion,sizeof(indizacion));
          cout<<"\n ID:"<<indizacion.peliculaIndice<<"\n";
          datos.read((char*)&firstClass,sizeof(firstClass));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(indizacion.peliculaIndice,peliculamod)==0)
        {
        cout<<"No. Lista de Reproduccion: "<<endl;
       cin.getline(pelicula,14);
        cout<<"Nombre de la pelicula"<<endl;
    cin.getline(nombrePelicula,35);
    cout<<"Categoria de la pelicula: "<<endl;
    cin.getline(categoria,40);
    cout<<"Anio de la pelicula: "<<endl;
    cin.getline(anio,20);
    fflush(stdin);

     }

          ofstream c("temp.txt",ios::app);
          c.write((char*)&firstClass,sizeof(firstClass));

        strcpy(indizacion.peliculaIndice,pelicula);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&indizacion,sizeof(indizacion));
        d.close();
        c.close();

        }



}

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }

    remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");


}

void reproduccionList::eliminar()
{
 char peliculaeli[15];
     int band=0;
     int opc,cont=0,cont2=0;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nIngresa ID a Eliminar: "<<endl;
     fflush(stdin);cin.getline(peliculaeli,14);
     while(!b.eof())
    {
        b.read((char*)&indizacion,sizeof(indizacion));
        cont++;
        if(b.eof())
        {
            break;
        }
        if(strcmp(indizacion.peliculaIndice,peliculaeli)==0)
        {
            ifstream a("datos.txt");
            a.seekg(indizacion.pos,ios::beg);
            a.read((char*)&firstClass,sizeof(firstClass));
             if(a.eof())   break;

            cout<<"No. Lista de Reproduccion: "<<firstClass.pelicula<<endl<<"Nombre: "<<firstClass.nombrePelicula<<endl<<"Categoria: "<<firstClass.categoria<<endl<<"Year:"<<firstClass.anio<<endl;
            cout<<"Deseas modificarlo? "<<"1. [Si]  2.[No] \n"; cin>>opc;
            band=1;
           a.close();
             break;
         }

         }
        b.close();


         if(opc==1)
         {
          ifstream indice("indice.txt");
          ifstream datos("datos.txt");
          while(!indice.eof())
         {cout<<"entro al ciclo\n";
          indice.read((char*)&indizacion,sizeof(indizacion));
          cout<<"\n ID:"<<indizacion.peliculaIndice<<"\n";
          datos.read((char*)&firstClass,sizeof(firstClass));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(indizacion.peliculaIndice,peliculaeli))
        {cont2++;


          cout<<"Nombre de pelicula a quitar de la lista: "<<firstClass.nombrePelicula;
          ofstream c("temp.txt",ios::app);
          c.write((char*)&firstClass,sizeof(firstClass));

        strcpy(indizacion.peliculaIndice,pelicula);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&indizacion,sizeof(indizacion));
        d.close();
        c.close();
        }
        }//while archivo
       indice.close();
       datos.close();
       remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");
        }//if
        else
        {

        }

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }


}

int main()
{
    int opc;
    do{
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
        cout<<"1) Agregar\n";
        cout<<"2) Imprimir\n";
        cout<<"3) Buscar\n";
        cout<<"4) Modificar\n";
        cout<<"5) Eliminar\n";
        cout<<"6) Salir\n";
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"\nOPC: ";
        cin>>opc;
        switch(opc)
    {

        case 1:
        firstClass.agregar();

        break;

        case 2:
        firstClass.imprimir();

        break;

        case 3:
        firstClass.buscar();
        break;

        case 4:
        firstClass.modificar();
        break;

        case 5:
        firstClass.eliminar();
        break;

        case 6:
        cout<<"SALIENDO..."<<endl<<endl;
        return 0;
        break;
    }
    getch();
    }while(opc!=7);
    return 0;
}
#endif