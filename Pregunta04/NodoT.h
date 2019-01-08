/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoT.h
 * Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 10:05 AM
 */

#ifndef NODOT_H
#define NODOT_H

#include <fstream>

template <typename DATOT> class ListaT;

template <typename DATOT>
class NodoT {
public:
    NodoT(){sgt = ant = NULL;};
    friend class ListaT<DATOT>;
private:
    DATOT dato;
    NodoT<DATOT>* sgt;
    NodoT<DATOT>* ant;
    
};

#endif /* NODOT_H */

