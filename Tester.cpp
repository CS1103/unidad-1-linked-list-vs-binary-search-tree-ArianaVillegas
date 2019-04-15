//
// Created by ariana on 15/04/19.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.h"
#include "BinarySearchTree.h"

TEST_CASE( "LINKEDLIST") {
    UTEC::LinkedList *ll=new UTEC::LinkedList;
    SECTION("Comprobar los punteros inicializados") {
        REQUIRE(ll->get_head() == nullptr);
        REQUIRE(ll->get_tail() == nullptr);
    }
    SECTION("Comprobar que el tamaño sea cero"){
        REQUIRE(ll->is_empty() == 1);
        REQUIRE(ll->size() == 0);
    }
    Location ej1(1321,"fafas","afas",12.32,453.23,"fdsdfsa","dsfasdf");
    ll->add_head(&ej1);
    SECTION("Agregar elementos al head"){
        REQUIRE(ll->get_head()!= nullptr);
        REQUIRE(ll->get_tail()!= nullptr);
        REQUIRE(ll->get_head()->data->GetpostionId() == 1321);
        REQUIRE(ll->get_head()->data->GetStateCode() == "fafas");
        REQUIRE(ll->get_head()->data->GetCountry() == "afas");
        REQUIRE(ll->get_head()->data->GetLatitude() == 12.32);
        REQUIRE(ll->get_head()->data->GetLongitude() == 453.23);
        REQUIRE(ll->get_head()->data->GetLine() == "fdsdfsa");
        REQUIRE(ll->get_head()->data->GetConstruction() == "dsfasdf");
    }
    Location ej2(1322,"fafs","afs",14.31,432.654,"gsre","esrg");
    ll->add_tail(&ej2);
    SECTION("Agregar elementos al tail"){
        REQUIRE(ll->get_tail()->data->GetpostionId() == 1322);
        REQUIRE(ll->get_tail()->data->GetStateCode() == "fafs");
        REQUIRE(ll->get_tail()->data->GetCountry() == "afs");
        REQUIRE(ll->get_tail()->data->GetLatitude() == 14.31);
        REQUIRE(ll->get_tail()->data->GetLongitude() == 432.654);
        REQUIRE(ll->get_tail()->data->GetLine() == "gsre");
        REQUIRE(ll->get_tail()->data->GetConstruction() == "esrg");
    }
    Location ej3(1323,"faf","af",24.31,532.654,"gse","esg");
    ll->insert(0,&ej3);
    Location ej4(1324,"fafa","afa",24.31,532.654,"gsea","esga");
    ll->insert(3,&ej4);
    Location ej5(1325,"fafa","afa",24.31,532.654,"gsea","esga");
    ll->insert(1,&ej5);
    SECTION("Insertar un elemento en la posición 0 y 3"){
        //La posicion 0 es equivalente a colocarlo en la posicion del head en este caso
        REQUIRE(ll->get_head()->data->GetpostionId() == 1323);
        //La posicion 3 es equivalente a colocarlo en la posicion del tail en este caso
        REQUIRE(ll->get_tail()->data->GetpostionId() == 1324);
        //La posicion 1 es el next del head
        REQUIRE(ll->get_head()->next->data->GetpostionId() == 1325);
    }
    SECTION("Buscar por ID los elementos en la posicion 2 y 4"){
        //Posicion 2
        REQUIRE(ll->search(1325)->data->GetpostionId() == 1325);
        //Posicion 4
        REQUIRE(ll->search(1322)->data->GetpostionId() == 1322);
    }
}

TEST_CASE("Binary Search Tree"){
    UTEC::BinarySearchTree *bst=new UTEC::BinarySearchTree;
    SECTION("Comprobar los punteros inicializados") {
        REQUIRE(bst->get_root() == nullptr);
    }
    SECTION("Comprobar que el árbol esta vacío"){
        REQUIRE(bst->is_empty() == 1);
    }
    Location ej1(1322,"fafas","afas",12.32,453.23,"fdsdfsa","dsfasdf");
    bst->insert(&ej1);
    Location ej2(1321,"fafs","afs",14.31,432.654,"gsre","esrg");
    bst->insert(&ej2);
    Location ej3(1323,"faf","af",24.31,532.654,"gse","esg");
    bst->insert(&ej3);
    SECTION("Insetar elementos"){
        REQUIRE(bst->get_root()!= nullptr);
        REQUIRE(bst->get_root()->data->GetpostionId() == 1322);
        REQUIRE(bst->get_root()->left->data->GetpostionId() == 1321);
        REQUIRE(bst->get_root()->right->data->GetpostionId() == 1323);
    }
    SECTION("Buscar por ID los elementos 1321,1323"){
        //Posicion 2
        REQUIRE(bst->search(1321)->data->GetpostionId() == 1321);
        //Posicion 4
        REQUIRE(bst->search(1323)->data->GetpostionId() == 1323);
    }
    bst->clear(bst->get_root());
    SECTION("Comprobar que se ha limpiado el árbol"){
        REQUIRE(bst->get_root()== nullptr);
    }
}