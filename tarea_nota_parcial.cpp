///El docente deberá ingresar la cantidad de alumnos que rindieron el examen.
///Luego deberá ingresar el apellido del alumno
///Luego las notas de cada uno de los 4 ejercicio.
///
///El programa deberá Sumar las 4 notas de los ejercicios. y validar si el alumno aprobó o no.
///
///El programa deberá mostrar una lista con los alumnos aprobados con su respectiva nota y una lista con todos los alumnos que rindieron con su respectiva nota.

#include <iostream>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <cstring>

using namespace std;

int main (){

struct persona
{
char apellido[15];
double notaEj1;
double notaEj2;
double notaEj3;
double notaEj4;
double notaFinal;
};

int cantidadAlumnos;
int swich = 1;
int cantidadEj = 4;

cout << "Ingrese la cantidad de alumnos para ver si aprobaron: ";
cin >> cantidadAlumnos;

persona personas[cantidadAlumnos];

cout << "RECORDAR QUE! La nota maxima es de 2.5 puntos para cada ejercicio." << endl << endl;


while (swich){

    for (int i = 0; i < cantidadAlumnos; i++){
        cout << "Ingresar el apellido del alumno " << i+1 << ": ";
        cin >> personas[i].apellido;
        cout << endl;

        double notaFinalEspecifica = 0;

    for (int j = 0; j < cantidadEj; j++){

        double nota ;

        cout << "Ingrese la nota del ejercicio " << j+1 << ": ";
        cin >> nota;

        if (nota < 0 || nota > 2.5){
            swich = 0;
        }
        if (swich == 0){
            cout << "ERROR: La nota ingresada supera los 2.5 puntos o es inferior a 0." << endl;
            return 0;
        }

        else{
        if (j==0) personas[i].notaEj1 = nota;
        else if (j==1) personas[i].notaEj2 = nota;
        else if (j==2) personas[i].notaEj3 = nota;
        else if (j==3) personas[i].notaEj4 = nota;
        }

        notaFinalEspecifica += nota;
}
        personas[i].notaFinal = notaFinalEspecifica;
        cout << endl;

    }
    swich = 0;
cout << "|LISTA DE ALUMNOS Y NOTAS|" << endl << endl;

for (int i = 0; i < cantidadAlumnos; i++){

    cout << "Alumno " << personas[i].apellido << endl
    << "Nota 1: " << personas[i].notaEj1 << endl
    << "Nota 2: " << personas[i].notaEj2 << endl
    << "Nota 3: " << personas[i].notaEj3 << endl
    << "Nota 4: " << personas[i].notaEj4 << endl
    << "Nota del parcial: " << personas[i].notaFinal << endl << endl << endl;
}

    cout << "|LISTA DE ALUMNOS APROBADOS|" << endl << endl;
    for (int i = 0; i < cantidadAlumnos; i++){
        if (personas[i].notaFinal >= 6) cout  << "[]" << personas[i].apellido << ": " << personas[i].notaFinal << endl << endl << endl;
    }

    cout << "|LISTA DE ALUMNOS DESAPROBADOS|" << endl << endl;
    for (int i = 0; i < cantidadAlumnos; i++){
        if (personas[i].notaFinal < 6) cout  << "[]" << personas[i].apellido << ": " << personas[i].notaFinal  << endl << endl;
    }
}
return 0;
}
