/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaVehiculos.h
 * Author: Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 08:14 AM
 */

#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H

#include <fstream>
#include "NodoV.h"

class ListaVehiculos {
public:
    ListaVehiculos();
    virtual ~ListaVehiculos();
    void leerVehiculos(std::ifstream& in);
    void imprimirVehiculos(std::ofstream& out);
    void eliminar();
    void insertarInfraccion(const char* placa, int infraccion);
private:
    void insertar(Vehiculo& vehiculo);
    NodoV* buscarNodoVehiculoPorPlaca(const char* placa);
    NodoV* head;
};

#endif /* LISTAVEHICULOS_H */

