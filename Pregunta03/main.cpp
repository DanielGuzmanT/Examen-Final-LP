/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 11 de diciembre de 2018, 10:04 AM
 */

#include <cstdlib>
#include "ListaT.h"
#include "Infraccion.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream arch("Infracciones.csv", ios::in);
    ofstream reporte1("Creciente.txt", ios::out);
    ofstream reporte2("Decreciente.txt", ios::out);
    
    
    ListaT<Infraccion> lista;
    lista.crear(arch);
    lista.imprimir(reporte1, 1);
    lista.imprimir(reporte2, 0);

    return 0;
}

