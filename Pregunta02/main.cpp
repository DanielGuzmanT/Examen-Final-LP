/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 09:16 AM
 */

#include <iostream>
#include <fstream>
#include "ListaConductores.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream arch1("Conductores.csv", ios::in);
    ifstream arch2("Registro_de_Faltas.csv", ios::in);
    ofstream reporte("Reporte.txt", ios::out);
    
    ListaConductores conductores;
    conductores.leerConductores(arch1);
    
//    cout << "leer infracciones" << endl;
    conductores.leerInfracciones(arch2);
    
//    cout << "imprimir conductores" << endl;
    conductores.imprimirConductores(reporte);
    
    return 0;
}

