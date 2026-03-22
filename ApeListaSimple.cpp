#include <iostream>   // Librería para entrada y salida (cout, cin)
#include <string>     // Librería para usar string
using namespace std;

template <typename T>
struct Nodo {
    T info;                 // Guarda el dato (nombre de la canción)
    Nodo<T>* siguiente;     // Apunta al siguiente nodo
};


// lista simple

template <typename T>
class ListaSimple {

private:
    Nodo<T>* primero;   // Apunta al primer nodo de la lista
    Nodo<T>* ultimo;    // Apunta al último nodo de la lista

public:


    // inicializar lista

    void inicializar() {
        // Se establece la lista como vacía
        primero = nullptr;
        ultimo  = nullptr;
    }


    // agregar canción al inicio

    void agregarInicio(T cancion) {

        // Se crea un nuevo nodo dinámicamente
        Nodo<T>* nuevo = new Nodo<T>();

        // Se asigna el valor al nodo
        nuevo->info = cancion;

        // Inicialmente no apunta a nada
        nuevo->siguiente = nullptr;

        // Si la lista está vacía
        if (primero == nullptr) {

            // El nuevo nodo será el primero y el último
            primero = nuevo;
            ultimo = nuevo;

        } else {

            // El nuevo nodo apunta al antiguo primero
            nuevo->siguiente = primero;

            // Se actualiza el primero
            primero = nuevo;
        }

        cout << " \"" << cancion << "\" agregada al INICIO de la playlist.\n";
    }


    // Agregar canción al final

    void agregarFinal(T cancion) {

        // Se crea un nuevo nodo
        Nodo<T>* nuevo = new Nodo<T>();

        nuevo->info = cancion;
        nuevo->siguiente = nullptr;

        // Si la lista está vacía
        if (primero == nullptr) {

            primero = nuevo;
            ultimo = nuevo;

        } else {

            // El último nodo actual apunta al nuevo
            ultimo->siguiente = nuevo;

            // Se actualiza el último nodo
            ultimo = nuevo;
        }

        cout << " \"" << cancion << "\" agregada al FINAL de la playlist.\n";
    }


    // Buscar canción

    void buscar(T cancion) {

        // Puntero auxiliar para recorrer la lista
        Nodo<T>* aux = primero;

        int contador = 0; // Contador de posición

        // Recorre la lista mientras no llegue a NULL
        while (aux != nullptr) {

            // Si encuentra la canción
            if (aux->info == cancion) {
                contador++;
            }

            // Avanza al siguiente nodo
            aux = aux->siguiente;
            
        }
        
        if(contador > 0){
        // Si no se encontró
         cout << "La cancion aparece " << contador << " veces.\n";
        }else{
        cout << "La cancion no existe.\n";
        }
    }

    // Eliminar canción

    void eliminar(T cancion) {

        // Si la lista está vacía
        if (primero == nullptr) {
            cout << " La playlist esta vacia.\n";
            return;
        }

        // CASO 1: eliminar el primer nodo
        if (primero->info == cancion) {

            Nodo<T>* temp = primero; // Guardamos el nodo a eliminar

            // El primero ahora será el siguiente
            primero = primero->siguiente;

            // Si la lista quedó vacía
            if (primero == nullptr)
                ultimo = nullptr;

            delete temp; // Liberamos memoria

            cout << " Cancion eliminada.\n";
            return;
        }

        // CASO 2: eliminar en medio o final
        Nodo<T>* anterior = primero;
        Nodo<T>* actual = primero->siguiente;

        while (actual != nullptr) {

            // Si encontramos la canción
            if (actual->info == cancion) {

                // Saltamos el nodo a eliminar
                anterior->siguiente = actual->siguiente;

                // Si era el último nodo
                if (actual == ultimo)
                    ultimo = anterior;

                delete actual; // Liberamos memoria

                cout << " Cancion eliminada.\n";
                return;
            }

            // Avanzamos en la lista
            anterior = actual;
            actual = actual->siguiente;
        }

        // Si no se encontró
        cout << " Cancion no encontrada.\n";
    }


    // Mostrar la playlist

    void mostrar() {

        // Si la lista está vacía
        if (primero == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }

        cout << "\nPlaylist:\nHEAD -> ";

        // Puntero auxiliar para recorrer
        Nodo<T>* aux = primero;

        // Recorre toda la lista
        while (aux != nullptr) {

            // Imprime el valor del nodo
            cout << "[" << aux->info << "]";

            // Si hay siguiente, imprime flecha
            if (aux->siguiente)
                cout << " -> ";

            // Avanza al siguiente nodo
            aux = aux->siguiente;
        }

        // Indica el final de la lista
        cout << " -> NULL\n";
    }


    // Mostrar primera y ultima canción

    void extremos() {

        // Si está vacía
        if (primero == nullptr) {
            cout << " Playlist vacia.\n";
            return;
        }

        // Muestra directamente usando los punteros
        cout << " Primera: " << primero->info << endl;
        cout << " Ultima : " << ultimo->info << endl;
    }
};


// Función principal

int main() {

    // Se crea la playlist
    ListaSimple<string> playlist;

    playlist.inicializar();

    int opcion;
    string cancion;

    do {
        
        cout << "       MENU PLAYLIST \n";
        cout << " 1) Agregar cancion al inicio\n";
        cout << " 2) Agregar cancion al final\n";
        cout << " 3) Buscar cancion\n";
        cout << " 4) Eliminar cancion\n";
        cout << " 5) Mostrar playlist\n";
        cout << " 6) Ver primera y ultima\n";
        cout << " 7) Salir\n";
        cout << "-----------------------------\n";
        cout << " Seleccione una opcion: ";

        cin >> opcion;

        // Limpia el buffer
        cin.ignore(1000, '\n');

        switch (opcion) {

        case 1:
            cout << "Nombre de la cancion: ";
            getline(cin, cancion);
            playlist.agregarInicio(cancion);
            cout << "";
            break;

        case 2:
            cout << "Nombre de la cancion: ";
            getline(cin, cancion);
            playlist.agregarFinal(cancion);
            cout << "";
            break;

        case 3:
            cout << "Buscar cancion: ";
            getline(cin, cancion);
            playlist.buscar(cancion);
            cout << "";
            break;

        case 4:
            cout << "Eliminar cancion: ";
            getline(cin, cancion);
            playlist.eliminar(cancion);
            cout << "";
            break;

        case 5:
            playlist.mostrar();
            break;

        case 6:
            playlist.extremos();
            break;

        case 7:
            cout << "\n Saliendo del sistema... hasta luego!\n";
            break;

        default:
            cout << " Opcion invalida, intenta de nuevo.\n";
        }

    } while (opcion != 7);

    return 0;
}
