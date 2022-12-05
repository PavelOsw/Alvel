#ifndef FACTURAS_H_INCLUDED
#define FACTURAS_H_INCLUDED

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

class facturaCliente
{
    public:
    char IdCliente[10], nombreCliente[100];
    char dirCliente[100],coloniaCliente[100];
    char ciudadCliente[100],codigoPostal[100];
    float pagoAlvel;

    int menuFactura();
    void agregar();
    void imprimir();
    void buscar();
    void modificar();
    void eliminar();
    void Mostrar_Indice();
    void Orden();

}factura;

class indiceInvertido
{
    public:
    char IdCliente1[10];
    long int pos;

}indiceInvert;

void facturaCliente::imprimir()
{
    ifstream a("datos.bin");
    if(!a.good())
    cout<<"UPS! No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&factura,sizeof(factura));
            if(a.eof())
                break;
            cout<<"ID del Cliente: "<<factura.IdCliente<<endl<<"Nombre del cliente: "<<factura.nombreCliente<<endl<<"Direccion del Cliente: "<<factura.dirCliente<<endl<<"Colonia del Cliente: "<<factura.coloniaCliente<<endl<<"Ciudad: "<<factura.ciudadCliente<<endl<<"Codigo Postal: "<<codigoPostal<<endl<<"Pago: "<<pagoAlvel<<endl;
        }
    }
    a.close();
}

void facturaCliente::Mostrar_Indice()
{
  ifstream a("indice.bin");
    if(!a.good())
    cout<<"UPS! No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&indiceInvert,sizeof(indiceInvert));
            if(a.eof())
                break;
            cout<<"ID del Cliente: "<<indiceInvert.IdCliente1<<endl<<endl;
        }
    }
    a.close();
}




void facturaCliente::agregar()
{
    fflush(stdin);
    cout<<"\nID del Cliente: ";
    cin.getline(IdCliente,10);
    cout<<"\nNombre del cliente: ";
    cin.getline(nombreCliente,100);
    cout<<"\nDireccion: ";
    cin.getline(dirCliente,100);
    cout<<"\nColonia: ";
    cin.getline(coloniaCliente,100);
    cout<<"\nCiudad: ";
    cin.getline(ciudadCliente,100);
    fflush(stdin);
    cout<<"\nCodigo Postal: ";
    cin.getline(codigoPostal,100);
    cout<<"\nPago Alvel (Ingresa Cantidad en pesos $): ";
    cin>>pagoAlvel;




    ofstream a("datos.bin",ios::app);
    a.write((char*)&factura,sizeof(factura));
    indiceInvert.pos=a.tellp();
    indiceInvert.pos-=sizeof(factura);
    a.close();
    strcpy(indiceInvert.IdCliente1,IdCliente);
    ofstream b("indice.bin",ios::app);
    b.write((char*)&indiceInvert,sizeof(indiceInvert));
    b.close();
    orden++;

    cout<<"=======================================================\n";
    cout<<"SE AGREGO A LA LISTA DE REPDORUCCION CORRECTAMENTE!!\n";
    cout<<"=======================================================\n";
}

void facturaCliente::buscar()
{
    char idbus[14];
    int band=0;
    //cout<<"posicion "<<y.pos;
    ifstream b("indice.bin");
    if(!b.good()){
    cout<<"UPS! No existe el archivo";}
    else{
    cout<<"Ingresa el ID del cliente para buscar los datos\n";
    cout<<"\nID Cliente: "<<endl;
    fflush(stdin);cin.getline(idbus,10);
    while(!b.eof())
    {
        b.read((char*)&indiceInvert,sizeof(indiceInvert));
        if(b.eof())
        {
            break;
        }
        if(strcmp(indiceInvert.IdCliente1,idbus)==0)
        {
            ifstream a("datos.bin");
            a.seekg(indiceInvert.pos,ios::beg);
            a.read((char*)&factura,sizeof(factura));
            cout<<"ID del Cliente: "<<factura.IdCliente<<endl<<"Nombre del cliente: "<<factura.nombreCliente<<endl<<"Direccion del Cliente: "<<factura.dirCliente<<endl<<"Colonia del Cliente: "<<factura.coloniaCliente<<endl<<"Ciudad: "<<factura.ciudadCliente<<endl<<"Codigo Postal: "<<codigoPostal<<endl<<"Pago: "<<pagoAlvel<<endl;
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

void facturaCliente::modificar()
{
     char idmod[15];
     int band=0;
     int opc;
     ifstream b("indice.bin");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"Ingresa el ID del cliente para modificar los datos\n";
    cout<<"\nID Cliente: "<<endl;
     fflush(stdin);cin.getline(idmod,10);
     while(!b.eof())
    {   opc=0;
        b.read((char*)&indiceInvert,sizeof(indiceInvert));
        if(b.eof())
        {
            break;
        }
        if(strcmp(indiceInvert.IdCliente1,idmod)==0 && band==0)
        {
            ifstream a("datos.bin");
            a.seekg(indiceInvert.pos,ios::beg);

             a.read((char*)&factura,sizeof(factura));
             if(a.eof())   break;
            cout<<"ID del Cliente: "<<factura.IdCliente<<endl<<"Nombre del cliente: "<<factura.nombreCliente<<endl<<"Direccion del Cliente: "<<factura.dirCliente<<endl<<"Colonia del Cliente: "<<factura.coloniaCliente<<endl<<"Ciudad: "<<factura.ciudadCliente<<endl<<"Codigo Postal: "<<codigoPostal<<endl<<"Pago: "<<pagoAlvel<<endl;
            cout<<"Deseas modificarlo?\n"<<"1. [Si]   2. [No]\n"; cin>>opc;
            band=1;
            a.close();
            break;
         }

         }
         b.close();
         if(opc==1)
{
    fflush(stdin);
    ifstream indice("indice.bin");
    ifstream datos("datos.bin");
          while(!indice.eof())
         {
          indice.read((char*)&indiceInvert,sizeof(indiceInvert));
          cout<<"\nID: "<<indiceInvert.IdCliente1<<"\n";
          datos.read((char*)&factura,sizeof(factura));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(indiceInvert.IdCliente1,idmod)==0)
        {

    cout<<"\nID del Cliente: ";
    cin.getline(IdCliente,10);
    cout<<"\nNombre del cliente: ";
    cin.getline(nombreCliente,100);
    cout<<"\nDireccion: ";
    cin.getline(dirCliente,100);
    cout<<"\nColonia: ";
    cin.getline(coloniaCliente,100);
    cout<<"\nCiudad: ";
    cin.getline(ciudadCliente,100);
    fflush(stdin);
    cout<<"\nCodigo Postal: ";
    cin.getline(codigoPostal,100);
    cout<<"\nPago Alvel (Ingresa Cantidad en pesos $): ";
    cin>>pagoAlvel;

     }

          ofstream c("temp.bin",ios::app);
          c.write((char*)&factura,sizeof(factura));

        strcpy(indiceInvert.IdCliente1,IdCliente);
        ofstream d("tempind.bin",ios::app);
        d.write((char*)&indiceInvert,sizeof(indiceInvert));
        d.close();
        c.close();

        }



}

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }//else


    remove("indice.bin"); rename("tempind.bin","indice.bin");
    remove("datos.bin");  rename("temp.bin","datos.bin");


}

void facturaCliente::eliminar()
{
 char rfceli[15];
     int band=0;
     int opc,cont=0,cont2=0;
     ifstream b("indice.bin");
     if(!b.good()){
     cout<<"UPS! No existe el archivo";}
     else{
     cout<<"Ingresa el ID del cliente para eliminar los datos\n";
     cout<<"\nID Cliente: "<<endl;
     fflush(stdin);cin.getline(rfceli,10);
     while(!b.eof())
    {
        b.read((char*)&indiceInvert,sizeof(indiceInvert));
        cont++;
            cout<<"contador --"<<cont;
        if(b.eof())
        {
            break;
        }
        if(strcmp(indiceInvert.IdCliente1,rfceli)==0)
        {
            ifstream a("datos.bin");
            a.seekg(indiceInvert.pos,ios::beg);
            a.read((char*)&factura,sizeof(factura));
             if(a.eof())   break;

            cout<<"ID del Cliente: "<<factura.IdCliente<<endl<<"Nombre del cliente: "<<factura.nombreCliente<<endl<<"Direccion del Cliente: "<<factura.dirCliente<<endl<<"Colonia del Cliente: "<<factura.coloniaCliente<<endl<<"Ciudad: "<<factura.ciudadCliente<<endl<<"Codigo Postal: "<<codigoPostal<<endl<<"Pago: "<<pagoAlvel<<endl;
            cout<<"Deseas modificarlo?\n"<<"1. [Si]   2. [No]\n"; cin>>opc;
            band=1;
           a.close();
             break;
         }

         }
        b.close();


         if(opc==1)
         {
          ifstream indice("indice.bin");
          ifstream datos("datos.bin");
          while(!indice.eof())
         {
          indice.read((char*)&indiceInvert,sizeof(indiceInvert));
          cout<<"\nID: "<<indiceInvert.IdCliente1<<"\n";
          datos.read((char*)&factura,sizeof(factura));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(indiceInvert.IdCliente1,rfceli))
        {cont2++;


          ofstream c("temp.bin",ios::app);
          c.write((char*)&factura,sizeof(factura));

        strcpy(indiceInvert.IdCliente1,IdCliente);
        ofstream d("tempind.bin",ios::app);
        d.write((char*)&indiceInvert,sizeof(indiceInvert));
        d.close();
        c.close();
        }

        }
       indice.close();
       datos.close();
       remove("indice.bin"); rename("tempind.bin","indice.bin");
    remove("datos.bin");  rename("temp.bin","datos.bin");
        }
        else
        {

        }

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }


}

void facturaCliente::Orden()
{int i=0;
char indice[20][14];
char aux[20];

  ifstream a("indice.bin");
    if(!a.good())
    cout<<"UPS! No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&indiceInvert,sizeof(indiceInvert));
            if(a.eof())
                break;

                char *cadena=indiceInvert.IdCliente1;
                strcpy(indice[i],cadena);

                i++;
        }
    }
    a.close();

    for(int i=0;i<orden-1;i++)
for(int j=i+1;j<orden;j++)
if(strcmp(indice[i],indice[j])>0)
{
strcpy(aux,indice[j]);
strcpy(indice[j],indice[i]);
strcpy(indice[i],aux);
system("cls");}
for(int i=0;i<orden;i++)
{

strcpy(indiceInvert.IdCliente1,indice[i]);

ofstream a("tempind.bin",ios::app);
a.write((char*)&indiceInvert,sizeof(indiceInvert));
a.close();
}

 remove("indice.bin");
 rename("tempind.bin","indice.bin");

}

int facturaCliente :: menuFactura()
{
    int opc;
    do{
        system("cls");
        HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"                          --- FACTURAS ---\n\n";
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
        cout<<"1) AGREGAR\n";
        cout<<"2) IMPRIMIR\n";
        cout<<"3) BUSCAR\n";
        cout<<"4) MODIFICAR\n";
        cout<<"5) ELIMINAR\n";
        cout<<"6) SALIR\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================\n";
        cout<<"\nINGRESA LA OPCION DESEADA: ";
        cin>>opc;
        switch(opc)
    {

        case 1:
        factura.agregar();
        break;

        case 2:
        factura.imprimir();
        break;

        case 3:
        factura.buscar();
        break;

        case 4:
        factura.modificar();
        break;

        case 5:
        factura.eliminar();
        break;

        case 6:
        break;
    }
    getch();
    }while(opc!=6);
}
#endif
