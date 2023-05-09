#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
public:
    std::string nombre;
    std::string apellido;
    int edad;
    int registro;

    Persona(std::string nombre, std::string apellido, int edad, int registro)
        : nombre(nombre), apellido(apellido), edad(edad), registro(registro) {}
};

#endif // PERSONA_H