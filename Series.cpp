#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"
#include <windows.h>
#include <stdio.h>

using namespace std;


class Series
{
    public:
        char titulo[50], anio[5], pais[25];

    void Agregar();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Buscar();
	void menu();
}pr;

int dim1, dim2, dim3, opc = 0;


void Series::Agregar()
{
    cout<<"\n==================================================================\n";
    cout<<"                       AGREGAR UNA SERIE\n";
    cout<<"\nESCRIBE EL TITULO DE LA SERIE: ";
    cin.ignore();
    cin.getline(titulo, 50);
    cout<<"ESCRIBE EL ANIO: ";
    cin.getline(anio,5);
    cout<<"ESCRIBE EL PAIS DE ORIGEN: ";
    cin.getline(pais,25);
    ofstream Archivo("Series.txt",ios::app);
    dim1 = strlen(titulo);
    dim2 = strlen(anio);
    dim3 = strlen(pais);
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&titulo, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&anio, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&pais, dim3);
    Archivo.close();

}
void Series::Mostrar()
{
    int count = 0;
	system("cls");
    cout<<"\n==================================================================\n";
    cout<<"                   ALVEL+";
    cout<<"\n==================================================================\n";

    ifstream archivo("Series.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
		while(!archivo.eof()){
            count++;
			archivo.read((char*)&dim1, sizeof(int));
			archivo.read((char*)&titulo, dim1);
			titulo[dim1] = '\0'; 
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&anio, dim2);
			anio[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&pais, dim3);
			pais[dim3] = '\0';
            cout << titulo << "  " << anio << "  " << pais << endl;
            cout<<"\n==================================================================\n";
		}
	}
    archivo.close();
}


void Series::Modificar()
{
    int band = 0;
    char titulo2[50];

	ifstream archivo("Series.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
        cout<<"\n==================================================================\n";
        cout<<"                      MODIFICAR SERIE\n";
        cout<<"==================================================================\n";
	    cout << "Escribe el titulo de la serie: ";
        cin.getline(titulo2, 50);
        cin.getline(titulo2, 50);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&titulo, dim1);
            titulo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&anio, dim2);
            anio[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&pais, dim3);
            pais[dim3] = '\0';

            if(strcmp(titulo2, titulo) == 0)
            {
                cout << titulo << "  " << anio << "  " << pais << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Series.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&titulo, dim1);
            titulo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&anio, dim2);
            anio[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&pais, dim3);
            pais[dim3] = '\0';

            if(strcmp(titulo2, titulo) == 0)
            {
                cout<<"ESCRIBE EL TITULO DE LA SERIE: ";
                cin.getline(titulo, 50);
                cin.getline(titulo, 50);
                cout<<"ESCRIBE EL ANIO: ";
                cin.getline(anio,5);
                cout<<"ESCRIBE EL PAIS DE ORIGEN: ";
                cin.getline(pais,25);
                dim1 = strlen(titulo);
                dim2 = strlen(anio);
                dim3 = strlen(pais);
            }//condicion
            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&titulo, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&anio, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&pais, dim3);
        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Series.txt");
	rename("temporal.txt", "Series.txt");
	}//condicional de la opcion

    }// else

}

void Series::Eliminar()
{
int band = 0;
    char titulo2[50];

	ifstream archivo("Series.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
        cout<<"\n==================================================================\n";
        cout<<"                      ELIMINADOR DE SERIES\n";
	    cout << "TITULO QUE QUIERES ELIMINAR: ";
        cin.getline(titulo2, 50);
        cin.getline(titulo2, 50);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&titulo, dim1);
            titulo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&anio, dim2);
            anio[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&pais, dim3);
            pais[dim3] = '\0';

            if(strcmp(titulo2, titulo) == 0)
            {
                cout << titulo << "  " << anio << "  " << pais << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
                
            }//condicion
            cout<<"\n==================================================================\n";

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Series.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&titulo, dim1);
            titulo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&anio, dim2);
            anio[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&pais, dim3);
            pais[dim3] = '\0';

            if(strcmp(titulo2, titulo) != 0)
            {
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&titulo, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&anio, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&pais, dim3);
            }//condicion

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Series.txt");
	rename("temporal.txt", "Series.txt");
	}//condicional de la opcion

    }//

}

void Series::Buscar()
{
    char titulo2[50];
    int band = 0;
    system("cls");

    ifstream archivo("Series.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout<<"\n==================================================================\n";
        cout<<"                      BUSCADOR DE SERIES\n";
        cout << "Escribe el titulo de la serie que quieres buscar: ";
        cin.getline(titulo2, 50);
        cin.getline(titulo2, 50);
		while(!archivo.eof() && !band)
        {
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
			archivo.read((char*)&titulo, dim1);
			titulo[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&anio, dim2);
			anio[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&pais, dim3);
			pais[dim3] = '\0';
			if( strcmpi(titulo2, titulo) == 0)
            {
                cout << titulo << "  " << anio << "  " << pais << endl;
                band = 1;
                cout<<"\n==================================================================\n";

            }
		}
		if (!band)
            cout << "NO SE ENCUENTRA EL Serie..." << endl;
	}
    archivo.close();
}
int main()
{

	cout<<"\n\n\t\tBIENVENIDO AL MENU DE SERIES\n\n";
	do{
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
        cout<<"\nMENU PRINCIPAL: ";
        SetConsoleTextAttribute(hConsole, 3);
        cout<<"\n\n1.- AGREGAR SERIE.\n";
        cout<<"2.- IMPRIMIR DATOS DE SERIES.\n";
        cout<<"3.- BUSCAR DATOS DE SERIES.\n";
        cout<<"4.- MODIFICAR DATOS DE SERIES.\n";
        cout<<"5.- ELIMINAR DATOS DE SERIES.\n";
        cout<<"6.- SALIR.\n";
        SetConsoleTextAttribute(hConsole, 15);
        cout<<"\n==================================================================";cout<<endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout<<"OPC: ";cin>>opc;
		switch(opc) {
		  case 1:
			pr.Agregar();
			break;
		  case 2:
			pr.Mostrar();
			break;
          case 3:
			pr.Buscar();
			break;
		  case 4:
            pr.Modificar();
			//empleado.Datos();
			break;
          case 5:
			pr.Eliminar();
			break;
          default:
            cout << "OPCION INCORRECTA...."<<endl;
        }
        system("Pause");
    }while(opc != 6);
}
