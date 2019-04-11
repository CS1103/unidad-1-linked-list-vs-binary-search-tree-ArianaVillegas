#include <iostream>
#include <sstream>
#include <string>

#include <vector>
#include <fstream>
#include "LinkedList.h"
#include "BinarySearchTree.h"

// Nombres de archivos
const std::string LOCATION_FILE = "Locations.csv";
const std::string SEARCH_FILE = "Search.txt";

using namespace UTEC;

int main() {

    // Declarando variables
    LinkedList ll;
    std::vector<int> vsearch;
    BinarySearchTree bst;

    // Grabar Datos del archivo "Locations.csv" en ll
    load_locations(&ll,LOCATION_FILE);

    // Grabar Datos del archivo "Locations.csv" en bst
    load_locations(&bst,LOCATION_FILE);

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::ifstream SFILE(SEARCH_FILE);
    if (SFILE.is_open()) {
        std::string line;
        while (!SFILE.eof()) {
            std::getline(SFILE, line);
            vsearch.push_back(std::stoi(line));
        }
    } SFILE.close();

    double avgtime_ll = 0;
    double avgtime_bst = 0;


    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    double t0=clock();
    for (auto id: vsearch) {
        Node_List* search=ll.search(id);
    }
    double t1=clock();

    double t2=clock();
    for (auto id: vsearch) {
        Node* search=bst.search(id);
    }
    double t3=clock();


    // Calcular los tiempos promedios en cada caso
    avgtime_ll=((t1-t0)/CLOCKS_PER_SEC);
    avgtime_bst=((t3-t2)/CLOCKS_PER_SEC);

    std::cout<<avgtime_ll<<'\n'<<avgtime_bst;

    /*for (auto id: vsearch) {
        Node* search=bst.search(id);
        std::cout << search->data->GetpostionId() << ',';
        std::cout << search->data->GetStateCode() << ',';
        std::cout << search->data->GetCountry() << ',';
        std::cout << search->data->GetLatitude() << ',';
        std::cout << search->data->GetLongitude() << ',';
        std::cout << search->data->GetLine() << ',';
        std::cout << search->data->GetConstruction() << '\n';
    }*/


    return 0;
}