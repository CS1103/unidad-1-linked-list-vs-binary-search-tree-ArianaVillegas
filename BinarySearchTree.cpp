//
// Created by ruben on 4/5/19.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "BinarySearchTree.h"

UTEC::Node::Node(Location *n_data) {
    data = n_data;
    right = nullptr;
    left = nullptr;
}

UTEC::Node::~Node() {
    delete data;
}

UTEC::BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

UTEC::BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

void UTEC::BinarySearchTree::insert(Location* data) {
    Node* temporal = new Node(data);
    Node* start = root;
    int id_data = data->GetpostionId();
    if(is_empty())
        root=temporal;
    else{
        while (root != nullptr) {
            if(id_data<root->data->GetpostionId()){
                if(root->left == nullptr) {
                    root->left = temporal;
                    break;
                }else{
                    root=root->left;
                }
            } else {
                if(root->right == nullptr) {
                    root->right = temporal;
                    break;
                }else
                    root=root->right;
            }
        }
        root=start;
    }
}

void UTEC::BinarySearchTree::clear(Node *actual) {
    if(actual->left!= nullptr)
        clear(actual->left);
    if(actual->right!= nullptr)
        clear(actual->right);
    delete actual;
}

bool UTEC::BinarySearchTree::is_empty() {
    if(root== nullptr)
        return true;
    else
        return false;
}

UTEC::Node* UTEC::BinarySearchTree::get_root() {
    return root;
}

UTEC::Node * UTEC::BinarySearchTree::search(int position_id) {
    Node* actual = root;
    while (actual != nullptr) {
        if(position_id!=actual->data->GetpostionId()){
            if(position_id<actual->data->GetpostionId()){
                actual=actual->left;
            } else {
                actual=actual->right;
            }
        } else {
            return actual;
        }
    }
}

void UTEC::BinarySearchTree::print(Node *name) {
    std::cout<<name->data->GetpostionId()<<'\n';
    if(name->left!= nullptr)
        print(name->left);
    if(name->right!= nullptr)
        print(name->right);
}

void UTEC::load_locations(UTEC::BinarySearchTree *binary_search_tree, std::string file_name) {
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
            binary_search_tree->insert(nodeValue);
        }
    } LFILE.close();
}

void UTEC::print_node(UTEC::Node *node) {
    std::cout << "PositionId,statecode,county,point_latitude,point_longitude,line,construction\n";
    std::cout << node->data->GetpostionId() << ',';
    std::cout << node->data->GetStateCode() << ',';
    std::cout << node->data->GetCountry() << ',';
    std::cout << node->data->GetLatitude() << ',';
    std::cout << node->data->GetLongitude() << ',';
    std::cout << node->data->GetLine() << ',';
    std::cout << node->data->GetConstruction() << '\n';
}