#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <stdlib.h>


using namespace std;

class Orden
{
public:
    char nombre[35],username[30],email[35],password[25],fecha_inicio[10],fecha_final[10];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} RegisUser;
void Orden::Agregar()
{
    cout<<"\n==================================================================\n";
    cout<<"\t\tRegistro de usuario"<<endl;
    cout<<"\n==================================================================\n";
    cout<<"Nombre completo: ";
    cin.getline(nombre,35);
    cin.getline(nombre,35);
    cout<<"Nombre de usuario: ";
    cin.getline(username,30);
    cout<<"Email: ";
    cin.getline(email,35);
    printf("Contrase%ca: ", 164);
    cin.getline(password,25);
    cout<<"Fecha de inicio: ";
    cin.getline(fecha_inicio,10);
    cout<<"Finalizacion: ";
    cin.getline(fecha_final,10);
    ofstream archivo("usuarios.txt",ios::app);
    archivo.write((char*)&RegisUser,sizeof(RegisUser));
    archivo.close();
}
void Orden::Mostrar()
{
    system("cls");
    cout<<"\n==================================================================\n";
    cout<<"                   ALVEL+";
    cout<<"\n==================================================================\n";    
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"Usuarios registrados"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&RegisUser,sizeof(RegisUser));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Nombre del cliente: "<<nombre<<endl;
            cout<<"Nombre de usuario: "<<username<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Fecha de inicio: "<<fecha_inicio<<endl;
            cout<<"Fecha de fin: "<<fecha_final<<endl;
            cout<<""<<endl;
            cout<<"\n==================================================================\n";
        }
        archivo.close();
    }
}
void Orden::Modificar()
{
    char user[30];
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"\n==================================================================\n";    
        cout<<"\t\tModificar datos de usuario"<<endl;
        cout<<"\n==================================================================\n"<<endl<<endl;
        cout<<"Ingrese el nombre de usuario a modificar: ";
        cin.getline(user,30);
        cin.getline(user,30);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&RegisUser,sizeof(RegisUser));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(username,user)==0)
            {
                cout<<endl<<"\t\tUSUARIO ENCONTRADO!"<<endl<<endl;
                cout<<"Nuevo nombre de cliente: ";
                cin.getline(nombre,30);
                cout<<"Nuevo Username: ";
                cin.getline(username,30);
                cout<<"Nuevo Email: ";
                cin.getline(email,35);
                cout<<"Nueva password: ";
                cin.getline(password,25);
                cout<<"Nueva fecha de inicio: ";
                cin.getline(fecha_inicio,10);
                cout<<"Nueva fecha final: ";
                cin.getline(fecha_final,10);
                ofstream archivo("usuarios.txt",ios::app);
                archivo2.write((char*)&RegisUser,sizeof(RegisUser));
            }
            else
            {
                archivo2.write((char*)&RegisUser,sizeof(RegisUser));
            }

        }
        archivo.close();
        archivo2.close();
        remove("usuarios.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="usuarios.txt";
        rename(oldname,newname);
    }
}
void Orden::Eliminar()
{
    char user[30];
    int opcion=0;
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"\n==================================================================\n";
        cout<<"Eliminar usuario"<<endl;
        cout<<"\n==================================================================\n"<<endl;
        cout<<"Ingrese el nombre de usuario a eliminar: ";
        cin.getline(user,30);
        cin.getline(user,30);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&RegisUser,sizeof(RegisUser));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(username,user)==0)
            {
                cout<<"\t\tUSUARIO ENCONTRADO!"<<endl;
                cout<<"Nombre del cliente: "<<nombre<<endl;
                cout<<"Nombre de usuario: "<<username<<endl;
                cout<<"Email: "<<email<<endl;
                cout<<"Fecha de inicio: "<<fecha_inicio<<endl;
                cout<<"Fecha final: "<<fecha_final<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&RegisUser,sizeof(RegisUser));
                }
            }
            else
            {
                archivo2.write((char*)&RegisUser,sizeof(RegisUser));
            }
        }
        archivo.close();
        archivo2.close();
        remove("usuarios.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="usuarios.txt";
        rename(oldname,newname);
    }

}
void Orden::Buscar()
{
    char user[30];
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"\n==================================================================\n";
        cout<<"\t\tBUSCAR USUARIO"<<endl;
        cout<<"\n==================================================================\n";
        cout<<"Ingrese el nombre de usuario a buscar: ";
        cin.getline(user,30);
        cin.getline(user,30);
        archivo.read((char*)&RegisUser,sizeof(RegisUser));
        if(strcmp(username,user)==0)
        {
            cout<<endl<<"\t\tUSUARIO ENCONTRADO"<<endl;
            cout<<"Nombre de cliente: "<<nombre<<endl;
            cout<<"Username: "<<username<<endl;
            cout<<"Email: "<<email<<endl;
            cout<<"Fecha de inicio: "<<fecha_inicio<<endl;
            cout<<"Fecha final: "<<fecha_final<<endl;
        }
        else
        {
            cout << "Usuario no encontrado..." << endl;
        }
    }
    archivo.close();
}
void Pausar()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    system("cls");
}
int main()
{
    int op;
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
            RegisUser.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            RegisUser.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            RegisUser.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            RegisUser.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            RegisUser.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
    return 0;
}
#endif