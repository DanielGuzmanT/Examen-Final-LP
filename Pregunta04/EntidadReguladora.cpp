/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntidadReguladora.cpp
 * Author: Author: Jhair Guzman 20163275
 * 
 * Created on 11 de diciembre de 2018, 10:53 AM
 */

#include "EntidadReguladora.h"

EntidadReguladora::EntidadReguladora() {
}

EntidadReguladora::~EntidadReguladora() {
}

void EntidadReguladora::leerConductores(ifstream& in) {
    this->conductores.leerConductores(in);
}

void
void EntidadReguladora::leerInfracciones(ifstream& in) {
    this->infracciones.crear(in);
}

void EntidadReguladora::leerRegistroFaltas(ifstream& in) {
    
}

