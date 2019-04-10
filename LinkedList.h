//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"

namespace UTEC {

    struct Node_List {
        Location *data;
        Node_List *next;
        Node_List(Location n_data);
        ~Node_List();
        int GetPosition(){ return data->GetpostionId();};
    };

    class LinkedList {
        Node_List* head;
        Node_List* tail;
    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool is_empty();
        Node_List* get_head();
        Node_List* get_tail();
        void add_head(Location& data);
        void add_tail(Location& data);
        void print();
        void insert(int position, const Location& data);
        Node_List* search(int position_id);
    };
}

#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
