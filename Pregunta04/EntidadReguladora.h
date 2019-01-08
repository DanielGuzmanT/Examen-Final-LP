/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EntidadReguladora.h
 * Author: Author: Jhair Guzman 20163275
 *
 * Created on 11 de diciembre de 2018, 10:53 AM
 */

#ifndef ENTIDADREGULADORA_H
#define ENTIDADREGULADORA_H

#include "ListaConductores.h"
#include "ListaT.h"
#include "Infraccion.h"

class EntidadReguladora {
public:
    EntidadReguladora();
    virtual ~EntidadReguladora();
    void leerConductores(ifstream& in);
    void leerRegistroFaltas(ifstream& in);
    void leerInfracciones(ifstream& in);
    
private:
    ListaConductores conductores;
    ListaT<Infraccion> infracciones;
};

#endif /* ENTIDADREGULADORA_H */

