#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, vector<string>> graph = {
    //Peru
    {"Piura", {"Lima"}},
    {"Chiclayo", {"Lima"}},
    {"Trujillo", {"Lima"}},
    {"Iquitos", {"Lima"}},
    {"Lima", {"Piura", "Chiclayo", "Trujillo", "Iquitos", "Cusco", "Juliaca", "Arequipa"}},
    {"Cusco", {"Lima", "PuertoMaldonado", "Arequipa"}},
    {"PuertoMaldonado", {"Cusco"}},
    {"Juliaca", {"Lima"}},
    {"Arequipa", {"Lima", "Cusco"}},
};

//Funciones para la búsqueda en anchura 
bool vueloDirecto(string origen, string destino) {
    vector<string> destinos = graph[origen];
    // Buscar si la ciudad de destino se encuentra en la lista de destinos del origen
    return find(destinos.begin(), destinos.end(), destino) != destinos.end();
}

bool unaEscala(string origen, string destino) {
    vector<string> destinos = graph[origen];
    for (string parada : destinos) {
        // Buscar si la ciudad de destino se encuentra en la lista de destinos del stopover
        if (vueloDirecto(parada, destino)) {
            return true;
        }
    }
    return false;
}

bool dosEscalas(string origen, string destino) {
    vector<string> destinos = graph[origen];
    for (string parada : destinos) {
        // Buscar si hay un stopover(parada real) que tenga una conexión con la ciudad de destino
        if (unaEscala(parada, destino)) {
            return true;
        }
    }
    return false;
}

int main() {
    string origen, destino;
    cout << "Ingrese la ciudad de origen: ";
    cin >> origen;
    cout << "Ingrese la ciudad de destino: ";
    cin >> destino;

    if (vueloDirecto(origen, destino)) {
        cout << "Hay un vuelo directo de " << origen << " a " << destino << endl;
    }
    else if (unaEscala(origen, destino)) {
        cout << "Hay una conexión con una escala entre " << origen << " y " << destino << endl;
    }
    else if (dosEscalas(origen, destino)) {
        cout << "Hay una conexión con dos escalas entre " << origen << " y " << destino << endl;
    }
    else {
        cout << "No hay conexión entre " << origen << " y " << destino << endl;
    }
    return 0;
}
