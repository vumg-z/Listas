#include <iostream>
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

class Nodo {
public:
  Persona persona;
  Nodo *next;
  Nodo *prev;

  Nodo(Persona persona) : persona(persona), next(nullptr), prev(nullptr) {}
};

class ListaDobleCircular {
public:
  Nodo *head;
  Nodo *tail;
  Nodo *iterador;

  // Constructor
  ListaDobleCircular() : head(nullptr), tail(nullptr), iterador(nullptr) {}

  void insertar(Persona persona) {
    Nodo *nuevo_nodo = new Nodo(persona);

    if (head == nullptr) {
      head = tail = nuevo_nodo;
      head->next = tail;
      head->prev = tail;
    } else {
      tail->next = nuevo_nodo;
      nuevo_nodo->prev = tail;
      nuevo_nodo->next = head;
      head->prev = nuevo_nodo;
      tail = nuevo_nodo;
    }
  }

  void buscar(const std::string &nombre = "", int registro = -1) {
    Nodo *temp = head;
    bool encontrado = false;

    if (head != nullptr) {
      do {
        if ((nombre != "" && temp->persona.nombre == nombre) ||
            (registro != -1 && temp->persona.registro == registro)) {
          std::cout << "Persona encontrada: " << std::endl;
          std::cout << temp->persona.nombre << " " << temp->persona.apellido
                    << " " << temp->persona.edad << " "
                    << temp->persona.registro << std::endl;
          encontrado = true;
          break;
        }
        temp = temp->next;
      } while (temp != head);
    }

    if (!encontrado) {
      std::cout << "No se encontró la persona buscada." << std::endl;
    }
  }

  void mostrar() {
    Nodo *temp = head;

    if (head == nullptr) {
      std::cout << "La lista está vacía." << std::endl;
      return;
    }

    std::cout << "Contenido de la lista:" << std::endl;
    do {
      std::cout << "Nodo actual: " << temp
                << " | Nombre: " << temp->persona.nombre
                << " | Apellido: " << temp->persona.apellido
                << " | Edad: " << temp->persona.edad
                << " | Registro: " << temp->persona.registro
                << " | Nodo siguiente: " << temp->next << std::endl;
      temp = temp->next;
    } while (temp != head);
  }

  void eliminar_por_registro(int registro) {
    Nodo *temp = head;

    if (head == nullptr) {
      std::cout << "La lista está vacía." << std::endl;
      return;
    }

    bool encontrado = false;
    do {
      if (temp->persona.registro == registro) {
        encontrado = true;
        break;
      }
      temp = temp->next;
    } while (temp != head);

    if (encontrado) {
      if (temp->next == temp) {
        // Solo hay un nodo en la lista
        head = tail = nullptr;
      } else {
        if (temp == head) {
          head = head->next;
        }
        if (temp == tail) {
          tail = tail->prev;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
      }

      delete temp;
      std::cout << "Nodo eliminado." << std::endl;
    } else {
      std::cout << "No se encontró el nodo con el registro proporcionado."
                << std::endl;
    }
  }

  void modificar_por_registro(int registro, const std::string &nuevo_nombre,
                              const std::string &nuevo_apellido,
                              int nueva_edad) {
    Nodo *temp = head;
    bool encontrado = false;

    if (head != nullptr) {
      do {
        if (temp->persona.registro == registro) {
          temp->persona.nombre = nuevo_nombre;
          temp->persona.apellido = nuevo_apellido;
          temp->persona.edad = nueva_edad;
          encontrado = true;
          break;
        }
        temp = temp->next;
      } while (temp != head);
    }

    if (encontrado) {
      std::cout << "Nodo modificado." << std::endl;
    } else {
      std::cout << "No se encontró el nodo con el registro proporcionado."
                << std::endl;
    }
  }

  int contar_nodos() {
    Nodo *temp = head;
    int contador = 0;

    if (head != nullptr) {
      do {
        contador++;
        temp = temp->next;
      } while (temp != head);
    }

    return contador;
  }

  // iterador

  void mostrar_iterador() {
    if (iterador) {
      std::cout << "Iterador actual:"
                << " | Nombre: " << iterador->persona.nombre
                << " | Apellido: " << iterador->persona.apellido
                << " | Edad: " << iterador->persona.edad
                << " | Registro: " << iterador->persona.registro << std::endl;
    } else {
      std::cout << "El iterador es nulo." << std::endl;
    }
  }

  void first() {
    iterador = head;
    mostrar_iterador();
  }

  void last() {
    iterador = tail;
    mostrar_iterador();
  }

  void next() {
    if (iterador) {
      iterador = iterador->next;
    }
    mostrar_iterador();
  }

  void prev() {
    if (iterador) {
      iterador = iterador->prev;
    }
    mostrar_iterador();
  }

  Nodo &get_item() {
    if (iterador) {
      return *iterador;
    } else {
      throw std::runtime_error("El iterador es nulo.");
    }
  }

  ~ListaDobleCircular() {
    Nodo *temp = head;

    if (head != nullptr) {
      do {
        Nodo *nodo_a_eliminar = temp;
        temp = temp->next;
        delete nodo_a_eliminar;
      } while (temp != head);

      head = nullptr;
      tail = nullptr;
    }
  }
};

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
      // Completar aqui
      break;
    }
  }
}
