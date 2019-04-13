//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H
#include "Location.h"

namespace UTEC {

    struct Node {
        Location *data;
        Node* right;
        Node* left;
        Node(Location *n_data);
        ~Node();

    };

    class BinarySearchTree {
        Node* root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(Location* data);
        void clear(Node *name);
        bool is_empty();
        Node* get_root();
        Node* search(int position_id);
        void print(Node *name);
    };

    void load_locations(BinarySearchTree* binary_search_tree, std::string file_name);
    void print_node(Node* node);
}

#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
