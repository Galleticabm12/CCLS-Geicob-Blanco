#include <iostream>
#include <vector>
#include <string>
#include <cctype> // para tolower/toupper

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
    string prioridad;
};

// Protoripos
void agregarTarea(vector<Tarea>& tareas);
void mostrarTareas(const vector<Tarea>& tareas);
void completarTarea(vector<Tarea>& tareas);

int main() {
    vector<Tarea> tareas;
    int opcion;

    while (opcion != 5) {
        cout << "\nLISTA DE TAREAS\n\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Marcar tarea como completada\n";
        cout << "4. Salir\n\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarTarea(tareas);
                break;
            case 2:
                mostrarTareas(tareas);
                break;
            case 3:
                completarTarea(tareas);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}

// Agrega una nueva tarea al vector
void agregarTarea(vector<Tarea>& tareas) {
    string descripcion, prioridad;
    cout << "\nIngrese la descripción de la tarea: ";
    getline(cin, descripcion);
    
    cout << "Ingrese la prioridad (Alto/Medio/Bajo): ";
    getline(cin, prioridad);
    
    // Normalizar texto: primera letra mayúscula, resto minúscula
    if (!prioridad.empty()) {
        prioridad[0] = toupper(prioridad[0]);
        for (size_t i = 1; i < prioridad.length(); i++) {
            prioridad[i] = tolower(prioridad[i]);
        }
    }
    
    Tarea nuevaTarea;
    nuevaTarea.descripcion = descripcion;
    nuevaTarea.completada = false;
    nuevaTarea.prioridad = prioridad;
    
    tareas.push_back(nuevaTarea);
    
    cout << "Tarea agregada exitosamente!\n";
}

void mostrarTareas(const vector<Tarea>& tareas) {
    if (tareas.empty()) {
        cout << "\nNo hay tareas en la lista.\n";
        return;
    }

    cout << "\n--- TAREAS ---\n";
    for (size_t i = 0; i < tareas.size(); i++) {
        cout << i + 1 << ". ["
             << (tareas[i].completada ? "X" : " ")
             << "] " << tareas[i].descripcion
             << " [" << tareas[i].prioridad << "]"
             << "\n";
    }
    cout << "----------------\n";
}

void completarTarea(vector<Tarea>& tareas) {
    mostrarTareas(tareas);
    
    int numeroTarea;
    cout << "\nIngrese el número de la tarea a completar: ";
    cin >> numeroTarea;
    cin.ignore();

    if (numeroTarea < 1 || numeroTarea > tareas.size()) {
        cout << "\nNúmero de tarea inválido. Inténtelo de nuevo.\n";
        return;
    }
    
    tareas[numeroTarea - 1].completada = true;
    
    cout << "\nTarea completada exitosamente!\n";
}
