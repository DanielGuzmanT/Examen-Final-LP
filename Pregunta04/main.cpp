/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 10:52 AM
 */

#include <cstdlib>
#include "EntidadReguladora.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream arch1("Conductores.csv", ios::in);
    ifstream arch2("Registro_de_Faltas.csv", ios::in);
    ifstream arch3("Infracciones.csv", ios::in);
    
    EntidadReguladora reguladora;
    reguladora.leerConductores(arch1);
    reguladora.leerInfracciones(arch2);
    reguladora.leerRegistroFaltas(arch3);
    
    return 0;
}

