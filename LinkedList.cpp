//
// Created by ruben on 4/5/19.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "LinkedList.h"
#include "Location.h"

UTEC::Node_List::Node_List(Location n_data) {
    data = &n_data;
    next = nullptr;
}

UTEC::Node_List::~Node_List() {

}

UTEC::LinkedList::LinkedList() {
    head= nullptr;
    tail= nullptr;
}

UTEC::LinkedList::~LinkedList() {

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

void UTEC::LinkedList::add_head(Location& data) {
    Node_List* temp = new Node_List(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void UTEC::LinkedList::add_tail(Location& data) {
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
    while(actual != nullptr) {
        std::cout<<actual->next<<"\n";
        actual = actual->next;
    }
}
void UTEC::LinkedList::insert(int position, const Location& data){
    Node_List* temp = new Node_List(data);
    Node_List* actual = head;
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        for(int i=0; i<position-1; i++){
            actual = actual->next;
        }
        temp->next=((actual->next)->next)->next;
        actual->next=temp;
    }
}

UTEC::Node_List * UTEC::LinkedList::search(int position_id) {
    //Node_List* actual = head;
    //while(actual != nullptr) {
        /*if(position_id==actual->GetPosition()){
            return actual;
        }*/
      //  actual=actual->next;
    //}
}