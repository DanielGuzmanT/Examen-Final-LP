/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaConductores.cpp
 * Author: alulab14
 * 
 * Created on 11 de diciembre de 2018, 08:13 AM
 */

#include "ListaConductores.h"

using namespace std;

ListaConductores::ListaConductores() {
    this->head = NULL;
}

ListaConductores::~ListaConductores() {
    this->eliminar();
}

void ListaConductores::eliminar() {
    NodoC* nodoRec = this->head;
    NodoC* nodoAnt = NULL;
    
    while(nodoRec!=NULL){
        nodoAnt = nodoRec;
        nodoRec = nodoRec->sgt;
        delete nodoAnt;
    }
}

void ListaConductores::leerConductores(ifstream& in) {
    while(!in.eof()){
        Conductor conductor;
        conductor.leer(in);
        this->insertar(conductor);
    }
}

void ListaConductores::insertar(Conductor &conductor) {
    NodoC* nodoRec = this->head;
    NodoC* nodoAnt = NULL;
    NodoC* nodoNew = new NodoC();
    nodoNew->conductor = conductor;
    
    while(nodoRec!=NULL){
        if(nodoNew->conductor < nodoRec->conductor) break;
        nodoAnt = nodoRec;
        nodoRec = nodoRec->sgt;
    }
    
    nodoNew->sgt = nodoRec;
    nodoNew->ant = nodoAnt;
    
    if(nodoRec!=NULL) nodoRec->ant = nodoNew;
    if(nodoAnt==NULL) this->head = nodoNew;
    else nodoAnt->sgt = nodoNew;
}

void ListaConductores::imprimirConductores(std::ofstream& out) {
    NodoC* nodoRec = this->head;
    
    while(nodoRec!=NULL){
        nodoRec->conductor.imprimir(out);
        nodoRec = nodoRec->sgt;
    }
}

