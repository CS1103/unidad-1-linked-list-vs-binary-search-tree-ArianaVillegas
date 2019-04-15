//
// Created by ruben on 4/5/19.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "LinkedList.h"

UTEC::Node_List::Node_List(Location *n_data) {
    data = n_data;
    next = nullptr;
}

UTEC::Node_List::~Node_List() {
    delete data;
}

UTEC::LinkedList::LinkedList() {
    head= nullptr;
    tail= nullptr;
}

UTEC::LinkedList::~LinkedList() {
    while (head!= nullptr){
        delete head;
        head= nullptr;
        head=head->next;
    }
}

int UTEC::LinkedList::size() {
    int count = 0;
    Node_List* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool UTEC::LinkedList::is_empty() {
    if (head== nullptr && tail== nullptr) {
        return true;
    }else{
        return false;
    }
}

UTEC::Node_List *UTEC::LinkedList::get_head() {
    return head;
}

UTEC::Node_List *UTEC::LinkedList::get_tail() {
    return tail;
}

void UTEC::LinkedList::add_head(Location* data) {
    Node_List* temp = new Node_List(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(Location* data) {
    Node_List* temp = new Node_List(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::LinkedList::print(){
    Node_List* actual = head;
    std::cout << "PositionId,statecode,county,point_latitude,point_longitude,line,construction\n";
    while(actual != nullptr) {
        std::cout << actual << '\n';
        std::cout << actual->data->GetpostionId() << ',';
        std::cout << actual->data->GetStateCode() << ',';
        std::cout << actual->data->GetCountry() << ',';
        std::cout << actual->data->GetLatitude() << ',';
        std::cout << actual->data->GetLongitude() << ',';
        std::cout << actual->data->GetLine() << ',';
        std::cout << actual->data->GetConstruction() << '\n';
        actual = actual->next;
    }
}
void UTEC::LinkedList::insert(int position, Location* data){
    Node_List* temp = new Node_List(data);
    Node_List* actual = head;
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        if (position==0){
            add_head(data);
        } else if(position==3) {
            add_tail(data);
        }else{
            for (int i = 0; i < position-1; i++) {
                actual = actual->next;
            }
            temp->next = actual->next;
            actual->next = temp;
        }
    }
}

UTEC::Node_List * UTEC::LinkedList::search(int position_id) {
    Node_List* actual = head;
    while(actual != nullptr) {
        if(position_id==actual->data->GetpostionId()){
            return actual;
        }
        actual=actual->next;
    }
}

void UTEC::load_locations(UTEC::LinkedList *linked_list, std::string file_name) {
    std::ifstream LFILE(file_name);
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
            linked_list->add_tail(nodeValue);
        }
    } LFILE.close();
}