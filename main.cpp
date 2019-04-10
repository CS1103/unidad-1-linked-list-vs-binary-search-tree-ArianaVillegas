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
    /*BinarySearchTree bst;*/

    // Grabar Datos del archivo "Locations.csv" en ll
    std::ifstream LFILE(LOCATION_FILE);
    if (LFILE.is_open()) {
        std::string vread[7];
        std::string line;
        while (!LFILE.eof()) {
            std::getline(LFILE, line);
            std::istringstream iss(line);
            unsigned int count = 0;
            while (std::getline(iss, line, ',')) {
                vread[count] = line;
                count++;
            }
            Location *nodeValue=new Location(std::stoi(vread[0]), vread[1], vread[2], std::stod(vread[3]), std::stod(vread[4]),
                    vread[5], vread[6]);
            ll.add_tail(*nodeValue);
        }
    } LFILE.close();

    std::cout<<ll.get_head()->GetPosition()<<'\n';
    // Grabar Datos del archivo "Locations.csv" en bst

    // Leer los datos del archivo "Search.txt" y grabarlos en vsearch
    std::ifstream SFILE(SEARCH_FILE);
    if (SFILE.is_open()) {
        std::string line;
        while (!SFILE.eof()) {
            std::getline(SFILE, line);
            vsearch.push_back(std::stoi(line));
        }
    } SFILE.close();

    /*double avgtime_ll = 0;
    double avgtime_bst = 0;*/

    // Utilizar cada item de vsearch para buscar los lugares en ll y bsd
    // Calcular los tiempos promedios en cada caso



    for (const auto& id: vsearch) {
        Node_List* search=ll.search(id);
        //std::cout << search->data->GetpostionId() << ',';
        /*std::cout << search->data->GetStateCode() << ',';
        std::cout << search->data->GetCountry() << ',';
        std::cout << search->data->GetLatitude() << ',';
        std::cout << search->data->GetLongitude() << ',';
        std::cout << search->data->GetLine() << ',';
        std::cout << search->data->GetConstruction() << ',' << '\n';*/
    }


    return 0;
}