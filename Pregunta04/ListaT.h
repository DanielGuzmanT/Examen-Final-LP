/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaT.h
 * Author: Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 10:05 AM
 */

#ifndef LISTAT_H
#define LISTAT_H
#include "NodoT.h"

template <typename DATOT>
class ListaT {
public:
    ListaT();
    virtual ~ListaT(){this->eliminar();};
    void crear(std::ifstream& in);
    void imprimir(std::ofstream& out, int sentido);
    double buscarDouble(int valor);
private:
    void insertar(DATOT& dato);
    void eliminar();
    NodoT<DATOT>* first;
    NodoT<DATOT>* last;
    void imprimirCreciente(std::ofstream& out);
    void imprimirDecreciente(std::ofstream& out);
};

template <typename DATOT>
ListaT<DATOT>::ListaT(){
    this->first = NULL;
    this->last = NULL;
}

template <typename DATOT>
void ListaT<DATOT>::crear(std::ifstream& in){
    while(!in.eof()){
        DATOT dato;
        in >> dato;
        this->insertar(dato);
    }
}

template <typename DATOT>
void ListaT<DATOT>::insertar(DATOT& dato){
    NodoT<DATOT>* nodoRec = this->first;
    NodoT<DATOT>* nodoAnt = NULL;
    NodoT<DATOT>* nodoNew = new NodoT<DATOT>;
    nodoNew->dato = dato;
    
    while(nodoRec!=NULL){
        if(nodoNew->dato < nodoRec->dato) break;
        nodoAnt = nodoRec;
        nodoRec = nodoRec->sgt;
    }
    
    nodoNew->sgt = nodoRec;
    nodoNew->ant = nodoAnt;
    
    if(nodoRec!=NULL) nodoRec->ant = nodoNew;
    
    // llega al final de la lista, es el ultimo
    else this->last = nodoNew;
    
    // no hay nodo antes, es el primero
    if(nodoAnt==NULL) this->first = nodoNew;
    else nodoAnt->sgt = nodoNew;
}

template <typename DATOT>
void ListaT<DATOT>::eliminar(){
    NodoT<DATOT>* nodoRec = this->first;
    NodoT<DATOT>* nodoAnt = NULL;
    
    while(nodoRec!=NULL){
        nodoAnt = nodoRec;
        delete nodoAnt;
        nodoRec = nodoRec->sgt;
    }
}

template <typename DATOT>
void ListaT<DATOT>::imprimir(std::ofstream& out, int sentido){
    if(sentido==1) this->imprimirCreciente(out);
    else if(sentido==0) this->imprimirDecreciente(out);
}

template <typename DATOT>
void ListaT<DATOT>::imprimirCreciente(std::ofstream& out){
    NodoT<DATOT>* nodoRec = this->first;
    
    while(nodoRec!=NULL){
        out << nodoRec->dato;
        nodoRec = nodoRec->sgt;
    }
}


template <typename DATOT>
double ListaT<DATOT>::buscarDouble(int valor){
    NodoT<DATOT>* nodoRec = this->first;
    while(nodoRec!=NULL){
        if(nodoRec->dato == valor) return nodoRec->dato.retornaDouble();
        nodoRec = nodoRec->sgt;
    }
}

template <typename DATOT>
void ListaT<DATOT>::imprimirDecreciente(std::ofstream& out){
    NodoT<DATOT>* nodoRec = this->last;
    
    while(nodoRec!=NULL){
        out << nodoRec->dato;
        nodoRec = nodoRec->ant;
    }
}



#endif /* LISTAT_H */

