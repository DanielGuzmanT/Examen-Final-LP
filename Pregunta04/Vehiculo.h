/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.h
 * Author: alulab14
 *
 * Created on 11 de diciembre de 2018, 08:12 AM
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <list>
#include <fstream>
using namespace std;

class Vehiculo {
public:
    Vehiculo();
    virtual ~Vehiculo();
    char* GetPlaca() const;
    void SetPlaca(const char* placa);
    
    void leer(std::ifstream& in );
    void imprimir(std::ofstream& out);
    
    bool operator<(const Vehiculo& vehiculo) const;
    void operator=(const Vehiculo& vehiculo);
    
private:
    char* placa;
    list<int> infracciones;
};

#endif /* VEHICULO_H */

