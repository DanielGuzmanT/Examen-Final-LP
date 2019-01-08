/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoV.h
 * Author: alulab14
 *
 * Created on 11 de diciembre de 2018, 08:56 AM
 */

#ifndef NODOV_H
#define NODOV_H
#include "Vehiculo.h"

class ListaVehiculos;

class NodoV {
public:
    NodoV();
    virtual ~NodoV();
    friend class ListaVehiculos;
private:
    Vehiculo vehiculo;
    NodoV* stg;
    NodoV* ant;
};

#endif /* NODOV_H */

