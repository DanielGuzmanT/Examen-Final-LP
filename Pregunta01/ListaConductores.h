/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.h
 * Author: alulab14
 *
 * Created on 11 de diciembre de 2018, 08:13 AM
 */

#ifndef LISTACONDUCTORES_H
#define LISTACONDUCTORES_H

#include "NodoC.h"

class ListaConductores {
public:
    ListaConductores();
    virtual ~ListaConductores();
    void eliminar();
    void leerConductores(std::ifstream& in);
    void imprimirConductores(std::ofstream& out);
    
private:
    NodoC* head;
    void insertar(Conductor &conductor);
    
};

#endif /* LISTACONDUCTORES_H */

