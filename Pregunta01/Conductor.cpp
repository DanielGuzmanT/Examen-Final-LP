/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: alulab14
 * 
 * Created on 11 de diciembre de 2018, 08:12 AM
 */

#include "Conductor.h"
#include <cstring>
#include <iomanip>

using namespace std;

Conductor::Conductor() {
    this->nombre = NULL;
}


Conductor::~Conductor() {
    if(this->nombre!=NULL) delete [] this->nombre;
}

int Conductor::GetDni() const {
    return this->dni;
}
void Conductor::SetDni(int dni) {
    this->dni = dni;
}

char* Conductor::GetNombre() const {
    if(this->nombre==NULL) return NULL;
    char* nombre = new char[strlen(this->nombre)+1];
    strcpy(nombre, this->nombre);
    return nombre;
}
void Conductor::SetNombre(const char* nombre){
    if(this->nombre!=NULL) delete [] this->nombre;
    this->nombre = new char[strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

int Conductor::GetTelefono() const {
    return this->telefono;
}
void Conductor::SetTelefono(int telefono) {
    this->telefono = telefono;
}

void Conductor::leer(ifstream& in) {
    int dni, telefono; char nombre[100];
    in >> dni; in.ignore();
    in.getline(nombre, 100, ',');
    in >> telefono; in.ignore();
    
    // prueba 1
//    in.ignore(500, '\n');
//    in >> ws;
    this->SetDni(dni);
    this->SetNombre(nombre);
    this->SetTelefono(telefono);

    this->vehiculos.leerVehiculos(in);
}

void Conductor::imprimir(ofstream& out) {
    out << left;
    out << setw(10) << this->dni << setw(50) << this->nombre;
    out << setw(15) << this->telefono << endl;
    this->vehiculos.imprimirVehiculos(out);
    out << endl;
}

bool Conductor::operator<(const Conductor& conductor) const {
    return this->dni < conductor.dni;
}

void Conductor::operator=(const Conductor& conductor) {
    this->SetDni(conductor.dni);
    this->SetNombre(conductor.nombre);
    this->SetTelefono(conductor.telefono);
    // este = se utiliza al inicio de la lectura, no es necesario copiar la lista de vehiculos
}


