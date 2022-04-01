#include<iostream>
#include <stdlib.h>
#include <string.h> 
using namespace std;

const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int *codigo;
	string *nombre;
	string *apellido;
	string *direccion;
	int *telefono;
};

int main(){
int fila_estudiante=0;
FILE* archivo = fopen(nombre_archivo, "ab");
Estudiante estudiante;
cout<<"Cuantos Estudiantes Desea Ingresar: ";
cin>>fila_estudiante;
estudiante.codigo = new int[fila_estudiante];
estudiante.nombre = new string[fila_estudiante];
estudiante.apellido = new string[fila_estudiante];
estudiante.direccion = new string[fila_estudiante];
estudiante.telefono = new int[fila_estudiante];

cout<<"--------------Ingrese Datos--------------"<<endl;
string nombre;
for (int i=0;i<fila_estudiante;i++){
	cout<<"Codigo: ";
	cin>>estudiante.codigo[i];
	cin.ignore();
	cout<<"Nombre:";
	getline(cin,estudiante.nombre[i]);
	cout<<"Apellido:";
	getline(cin,estudiante.apellido[i]);
	cout<<"Direccion:";
	getline(cin,estudiante.direccion[i]);
	cout<<"Telefono:";
	cin>>estudiante.telefono[i];
	cout<<"------------------------------------"<<endl;
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	fclose(archivo);
	system("Pause");
}
	cout<<"--------------Mostrar Datos--------------"<<endl;
	for (int i=0;i<fila_estudiante;i++){
	cout<<"Codigo: "<<estudiante.codigo[i]<<" Nombre:"<<estudiante.nombre[i]<<" Apellido:"<<estudiante.apellido[i]<<" Direccion:"<<estudiante.direccion[i]<<" Telefono:"<<estudiante.telefono[i]<<"."<<endl;
	
}

delete[] estudiante.codigo;
delete[] estudiante.nombre;
delete[] estudiante.apellido;
delete[] estudiante.direccion;
delete[] estudiante.telefono;

	system("PAUSE");
	return 0;
}