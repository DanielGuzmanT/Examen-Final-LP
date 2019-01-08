/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.h
 * Author: alulab14
 *
 * Created on 11 de diciembre de 2018, 08:12 AM
 */

#ifndef CONDUCTOR_H
#define CONDUCTOR_H
#include "ListaVehiculos.h"
#include <fstream>

class Conductor {
public:
    Conductor();
    virtual ~Conductor();
    
    int GetDni() const;
    void SetDni(int dni);
    
    char* GetNombre() const;
    void SetNombre(const char* nombre);
    
    int GetTelefono() const;
    void SetTelefono(int telefono);
    
    void leer(std::ifstream& in );
    void imprimir(std::ofstream& out);
    
    bool operator<(const Conductor& conductor) const;
    void operator=(const Conductor& conductor);
    
private:
    int dni;
    char* nombre;
    int telefono;
    ListaVehiculos vehiculos;
};

#endif /* CONDUCTOR_H */

