#ifndef NODO_H
#define NODO_H

#include "Persona.h"

class Nodo {
public:
	Persona persona;
	Nodo* next;
	Nodo* prev;

	Nodo(Persona persona) : persona(persona), next(nullptr), prev(nullptr) {}
};

#endif // NODO_H