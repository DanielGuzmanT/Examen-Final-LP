/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.cpp
 * Author: alulab14
 * 
 * Created on 11 de diciembre de 2018, 10:31 AM
 */

#include "Infraccion.h"
#include <cstring>
#include <fstream>

Infraccion::Infraccion() {
    this->descripcion = NULL;
    this->gravedad = NULL;
}

Infraccion::~Infraccion() {
    if(this->descripcion!=NULL) delete [] this->descripcion;
    if(this->gravedad!=NULL) delete [] this->gravedad;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

double Infraccion::GetMulta() const {
    return multa;
}
char* Infraccion::GetDescripcion() const {
    if(this->descripcion==NULL) return NULL;
    char* descripcion = new char[strlen(this->descripcion)+1];
    strcpy(descripcion, this->descripcion);
    return descripcion;
}
void Infraccion::SetDescripcion(const char* descripcion) {
    if(this->descripcion!=NULL) delete [] this->descripcion;
    this->descripcion = new char[strlen(descripcion)+1];
    strcpy(this->descripcion, descripcion);
}

void Infraccion::SetGravedad(const char* gravedad) {
    if(this->gravedad!=NULL) delete [] this->gravedad;
    this->gravedad = new char[strlen(gravedad)+1];
    strcpy(this->gravedad, gravedad);
}
char* Infraccion::GetGravedad() const {
    if(this->gravedad==NULL) return NULL;
    char* gravedad = new char[strlen(this->gravedad)+1];
    strcpy(gravedad, this->gravedad);
    return gravedad;
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

bool Infraccion::operator<(const Infraccion& infraccion) {
    return this->codigo < infraccion.codigo;
}

void Infraccion::operator=(const Infraccion& infraccion) {
    this->SetCodigo(infraccion.codigo);
    this->SetDescripcion(infraccion.descripcion);
    this->SetGravedad(infraccion.gravedad);
    this->SetMulta(infraccion.multa);
}

bool Infraccion::operator==(int valor) {
    return this->codigo == valor;
}

double Infraccion::retornaDouble() {
    return this->multa;
}

ifstream& operator>>(ifstream& in, Infraccion& infraccion) {
    int codigo; double multa; char descripcion[300], gravedad[50];
    
    in >> codigo; in.ignore();
    in.getline(descripcion,300,',');
    in.getline(gravedad,50,',');
    in >> multa >> ws;
    
    infraccion.SetCodigo(codigo);
    infraccion.SetDescripcion(descripcion);
    infraccion.SetGravedad(gravedad);
    infraccion.SetMulta(multa);
    
}
ofstream& operator<<(ofstream& out, const Infraccion& infraccion) {
    out << "INFRACCION : " << infraccion.codigo << endl;
    out << "DESCRIPCION: " << infraccion.descripcion << endl;
    out << "GRAVEDAD   : " << infraccion.gravedad << endl;
    out << "MULTA      : " << infraccion.multa << endl << endl;
}






