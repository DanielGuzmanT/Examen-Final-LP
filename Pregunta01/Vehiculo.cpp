/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: alulab14
 * 
 * Created on 11 de diciembre de 2018, 08:12 AM
 */

#include "Vehiculo.h"
#include <cstring>
#include <iostream>

Vehiculo::Vehiculo() {
    this->placa = NULL;
    this->infracciones.clear();
}

Vehiculo::~Vehiculo() {
    if(this->placa!=NULL) delete [] this->placa;
    this->infracciones.clear();
    this->placa = NULL;
}

char* Vehiculo::GetPlaca() const {
    if(this->placa==NULL) return NULL;
    char* placa = new char[strlen(this->placa)+1];
    strcpy(placa, this->placa);
    return placa;
}

void Vehiculo::SetPlaca(const char* placa) {
    if(this->placa!=NULL) delete [] this->placa;
    this->placa = new char[strlen(placa)+1];
    strcpy(this->placa, placa);
}

void Vehiculo::leer(std::ifstream& in) {
    char placa[8];
    for(int i=0; i<7; i++) placa[i] = in.get();
//    in.getline(placa,7,','); in.ignore();
    placa[7] = '\0';
    cout << placa << endl;
    this->SetPlaca(placa);
}

void Vehiculo::imprimir(std::ofstream& out) {
    out << "Vehiculo: " << this->placa << endl;
}

bool Vehiculo::operator<(const Vehiculo& vehiculo) const {
    return strcmp(this->placa, vehiculo.placa)<0;
}

void Vehiculo::operator=(const Vehiculo& vehiculo) {
    this->SetPlaca(vehiculo.placa);
}
