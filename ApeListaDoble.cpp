
#include <iostream>   // Entrada y salida
#include <string>     // Uso de string
using namespace std;

// Nodo doblemente enlazada

template <typename T>
struct NodoDoble {
    T info;                        // Guarda la canción
    NodoDoble<T>* siguiente;      // Apunta al siguiente nodo
    NodoDoble<T>* anterior;       // Apunta al nodo anterior
};

// lista doblemente enlazada

template <typename T>
class ListaDoble {

private:
    NodoDoble<T>* primero;   // Apunta al primer nodo
    NodoDoble<T>* ultimo;    // Apunta al último nodo

public:
    // inicializar lista

    void inicializar() {
        // La lista inicia vacía
        primero = nullptr;
        ultimo = nullptr;
    }

    // Agregar cancion al inicio

    void agregarInicio(T cancion) {

        // Se crea un nuevo nodo
        NodoDoble<T>* nuevo = new NodoDoble<T>();

        // Se asigna la canción
        nuevo->info = cancion;

        // Inicialmente no tiene conexiones
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;

        // Si la lista está vacía
        if (primero == nullptr) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            // El nuevo nodo apunta al antiguo primero
            nuevo->siguiente = primero;

            // El antiguo primero apunta hacia atrás al nuevo
            primero->anterior = nuevo;

            // Se actualiza el primero
            primero = nuevo;
        }

        cout << " \"" << cancion << "\" agregada al INICIO.\n";
    }
    // Agregar cancion al final

    void agregarFinal(T cancion) {

        NodoDoble<T>* nuevo = new NodoDoble<T>();

        nuevo->info = cancion;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;

        // Si la lista está vacía
        if (primero == nullptr) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            // El último nodo apunta al nuevo
            ultimo->siguiente = nuevo;

            // El nuevo apunta hacia atrás al último
            nuevo->anterior = ultimo;

            // Se actualiza el último
            ultimo = nuevo;
        }

        cout << " \"" << cancion << "\" agregada al FINAL.\n";
    }

    // Buscar canción

    void buscar(T cancion) {

        NodoDoble<T>* aux = primero; // Puntero para recorrer
        int posicion = 1;

        // Recorre toda la lista
        while (aux != nullptr) {

            // Si encuentra la canción
            if (aux->info == cancion) {
                cout << " Cancion encontrada en posicion " << posicion << ".\n";
                return;
            }

            aux = aux->siguiente; // Avanza
            posicion++;
        }

        cout << " Cancion no encontrada.\n";
    }

    // Eliminar canción

    void eliminar(T cancion) {
        // Si la lista está vacía
        if (primero == nullptr) {
            cout << " Playlist vacia.\n";
            return;
        }
        NodoDoble<T>* aux = primero;
        // Recorre la lista
        while (aux != nullptr) {

            // Si encuentra la canción
            if (aux->info == cancion) {

                // CASO 1: es el primer nodo
                if (aux == primero) {
                    primero = primero->siguiente;

                    if (primero != nullptr)
                        primero->anterior = nullptr;
                    else
                        ultimo = nullptr;
                }
                // CASO 2: es el último nodo
                else if (aux == ultimo) {
                    ultimo = ultimo->anterior;
                    ultimo->siguiente = nullptr;
                }
                // CASO 3: está en medio
                else {
                    aux->anterior->siguiente = aux->siguiente;
                    aux->siguiente->anterior = aux->anterior;
                }
                delete aux; // Libera memoria

                cout << " Cancion eliminada.\n";
                return;
            }

            aux = aux->siguiente;
        }

        cout << " Cancion no encontrada.\n";
    }

    // Mostrar de incio a fin

    void mostrarInicioFin() {

        // Verifica si está vacía
        if (primero == nullptr) {
            cout << " Playlist vacia.\n";
            return;
        }

        NodoDoble<T>* aux = primero;

        cout << "\nHEAD -> ";

        // Recorre hacia adelante
        while (aux != nullptr) {

            cout << "[" << aux->info << "]";

            // Si hay siguiente, imprime enlace doble
            if (aux->siguiente)
                cout << " <-> ";

            aux = aux->siguiente;
        }

        cout << " -> NULL\n";
    }

    // Mostrar de fin a inicio

    void mostrarFinInicio() {

        // Verifica si está vacía
        if (ultimo == nullptr) {
            cout << " Playlist vacia.\n";
            return;
        }

        NodoDoble<T>* aux = ultimo;

        cout << "\nTAIL -> ";

        // Recorre hacia atrás
        while (aux != nullptr) {

            cout << "[" << aux->info << "]";

            // Si hay anterior, imprime enlace
            if (aux->anterior)
                cout << " <-> ";

            aux = aux->anterior;
        }

        cout << " -> NULL\n";
    }


    // Mostrar primera y ultima canción

    void extremos() {

        if (primero == nullptr) {
            cout << " Playlist vacia.\n";
            return;
        }

        cout << " Primera: " << primero->info << endl;
        cout << " Ultima : " << ultimo->info << endl;
    }
};

// Función principal

int main() {

    // Se crea la playlist (tipo string)
    ListaDoble<string> playlist;

    // Se inicializa manualmente
    playlist.inicializar();

    int opcion;
    string cancion;

    // Menú repetitivo
    do {
        cout << "\n MENU PLAYLIST \n";
        cout << "1. Agregar al inicio\n";
        cout << "2. Agregar al final\n";
        cout << "3. Buscar\n";
        cout << "4. Eliminar\n";
        cout << "5. Mostrar (Inicio -Fin)\n";
        cout << "6. Mostrar (Fin -Inicio)\n";
        cout << "7. Ver extremos\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";

        cin >> opcion;
        cin.ignore(1000, '\n'); // Limpia buffer

        if (opcion < 1 || opcion > 8) {
        cout << "Opcion fuera de rango.\n";
        }

        switch (opcion) {

        case 1:
            cout << "Cancion: ";
            getline(cin, cancion);
            playlist.agregarInicio(cancion);
            break;

        case 2:
            cout << "Cancion: ";
            getline(cin, cancion);
            playlist.agregarFinal(cancion);
            break;

        case 3:
            cout << "Buscar: ";
            getline(cin, cancion);
            playlist.buscar(cancion);
            break;

        case 4:
            cout << "Eliminar: ";
            getline(cin, cancion);
            playlist.eliminar(cancion);
            break;

        case 5:
            playlist.mostrarInicioFin();
            break;

        case 6:
            playlist.mostrarFinInicio();
            break;

        case 7:
            playlist.extremos();
            break;

        case 8:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 8);

    return 0;
}
