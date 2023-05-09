#include <iostream>
#include <string>
#include "Nodo.h"
#include "ListaDobleCircular.h"
#include "Persona.h"

int main() {
  ListaDobleCircular lista;

  int opcion;
  bool salir = false;

  while (!salir) {
    std::cout << "Menú:\n"
                 "1. Insertar persona\n"
                 "2. Mostrar lista\n"
                 "3. Buscar por nombre\n"
                 "4. Buscar por registro\n"
                 "5. Eliminar por registro\n"
                 "6. Modificar por registro\n"
                 "7. Contar nodos\n"
                 "8. Mostrar iterador\n"
                 "9. Mover iterador al primer elemento\n"
                 "10. Mover iterador al último elemento\n"
                 "11. Mover iterador al siguiente elemento\n"
                 "12. Mover iterador al elemento anterior\n"
                 "13. Obtener item del iterador\n"
                 "14. Salir\n"
                 "Ingrese una opción: ";
    std::cin >> opcion;

    std::string nombre, apellido;
    int edad, registro;

    switch (opcion) {
    case 1:
      std::cout << "Ingrese el nombre: ";
      std::cin >> nombre;
      std::cout << "Ingrese el apellido: ";
      std::cin >> apellido;
      std::cout << "Ingrese la edad: ";
      std::cin >> edad;
      std::cout << "Ingrese el número de registro: ";
      std::cin >> registro;
      lista.insertar(Persona(nombre, apellido, edad, registro));
      break;
    case 2:
      lista.mostrar();
      break;
    case 3:
      std::cout << "Ingrese el nombre a buscar: ";
      std::cin >> nombre;
      lista.buscar(nombre);
      break;
    case 4:
      std::cout << "Ingrese el número de registro a buscar: ";
      std::cin >> registro;
      lista.buscar(registro);
      break;
    case 5:
      std::cout << "Ingrese el número de registro a eliminar: ";
      std::cin >> registro;
      lista.eliminar_por_registro(registro);
      break;
    case 6:
      std::cout << "Ingrese el número de registro a modificar: ";
      std::cin >> registro;
      std::cout << "Ingrese el nuevo nombre: ";
      std::cin >> nombre;
      std::cout << "Ingrese el nuevo apellido: ";
      std::cin >> apellido;
      std::cout << "Ingrese la nueva edad: ";
      std::cin >> edad;
      lista.modificar_por_registro(registro, nombre, apellido, edad);
      break;
    case 7:
      std::cout << "Cantidad de nodos en la lista: " << lista.contar_nodos()
                << std::endl;
      break;
    case 8:
      lista.mostrar_iterador();
      break;
    case 9:
      lista.first();
      break;
    case 10:
      lista.last();
      break;
    case 11:
      lista.next();
      break;
    case 12:
      lista.prev();
      break;
    case 13:
      lista.get_item();
      break;
    case 14:
      // salir
      break;
    }
  }
}
