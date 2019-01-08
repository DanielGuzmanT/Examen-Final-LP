/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 11 de diciembre de 2018, 08:12 AM
 */

#include <iostream>
#include <fstream>
#include "ListaConductores.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream arch1("Conductores.csv", ios::in);
    ofstream reporte("Reporte.txt", ios::out);
    
    ListaConductores conductores;
    conductores.leerConductores(arch1);
    conductores.imprimirConductores(reporte);
    
    return 0;
}

