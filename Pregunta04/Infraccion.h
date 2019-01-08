/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infraccion.h
 * Author: Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 10:31 AM
 */

#ifndef INFRACCION_H
#define INFRACCION_H

#include <fstream>
using namespace std;

class Infraccion {
public:
    Infraccion();
    virtual ~Infraccion();
    
    int GetCodigo() const;
    void SetCodigo(int codigo);
    
    char* GetDescripcion() const;
    void SetDescripcion(const char* descripcion);
    
    char* GetGravedad() const;
    void SetGravedad(const char* gravedad);
    
    double GetMulta() const;
    void SetMulta(double multa);
    
    bool operator <(const Infraccion& infraccion);
    bool operator==(int valor);
    void operator=(const Infraccion& infraccion);

    friend ifstream& operator>>(ifstream& in , Infraccion& infraccion);
    friend ofstream& operator<<(ofstream& out, const Infraccion& infraccion);
    
    double retornaDouble();
    
private:
    int codigo;
    char* descripcion;
    char* gravedad;
    double multa;
};

#endif /* INFRACCION_H */

