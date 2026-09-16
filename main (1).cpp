#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa una tarea
struct Tarea {
    string descripcion;
    bool completada;
};

// Protoripos
// void agregarTarea(vector<Tarea>& tareas);
// void mostrarTareas(const vector<Tarea>& tareas);
// void completarTarea(vector<Tarea>& tareas);

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
                // agregarTarea(tareas);
                break;
            case 2:
                // mostrarTareas(tareas);
                break;
            case 3:
                // completarTarea(tareas);
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
// void agregarTarea(vector<Tarea>& tareas) {
// 
// }

// Muestra todas las tareas
// void mostrarTareas(const vector<Tarea>& tareas) {
// 
// }

// Marca una tarea como completada
// void completarTarea(vector<Tarea>& tareas) {
// 
// }