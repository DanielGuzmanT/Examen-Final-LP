/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaVehiculos.cpp
 * Author: alulab14
 * 
 * Created on 11 de diciembre de 2018, 08:14 AM
 */

#include "ListaVehiculos.h"

#include <iostream>

ListaVehiculos::ListaVehiculos() {
    this->head = NULL;
}


ListaVehiculos::~ListaVehiculos() {
    this->eliminar();
}

void ListaVehiculos::eliminar() {
    NodoV* nodoRec = this->head;
    NodoV* nodoAnt = NULL;
    
    while(nodoRec!=NULL){
        nodoAnt = nodoRec;
        nodoRec = nodoRec->stg;
        delete nodoAnt;
    }
}

void ListaVehiculos::leerVehiculos(std::ifstream& in) {
    while(true){
        char placa[8];
        for(int i=0; i<7; i++) placa[i] = in.get();
        placa[7] = '\0';
        
        Vehiculo vehiculo;
        vehiculo.SetPlaca(placa);
        this->insertar(vehiculo);
        
        if(in.peek()==',') in.get();
        else if(in.peek()=='\n') break;
    }   in >> ws; // ignora salto de linea
}

void ListaVehiculos::insertar(Vehiculo& vehiculo) {
    NodoV* nodoRec = this->head;
    NodoV* nodoAnt = NULL;
    NodoV* nodoNew = new NodoV();
    nodoNew->vehiculo = vehiculo;
//    cout << "insertar " << vehiculo.GetPlaca() << endl;
    while(nodoRec!=NULL){
        if(nodoNew->vehiculo < nodoRec->vehiculo){
//            cout << "insertado" << endl;
            break;
        }
        nodoAnt = nodoRec;
        nodoRec = nodoRec->stg;
    }
    
    nodoNew->stg = nodoRec;
    nodoNew->ant = nodoAnt;
    
    if(nodoRec!=NULL) nodoRec->ant = nodoNew;
    
    if(nodoAnt==NULL) this->head = nodoNew;
    else nodoAnt->stg = nodoNew;
}



void ListaVehiculos::imprimirVehiculos(std::ofstream& out) {
    NodoV* nodoRec = this->head;
    while(nodoRec!=NULL){
        nodoRec->vehiculo.imprimir(out);
        nodoRec = nodoRec->stg;
    }
}

