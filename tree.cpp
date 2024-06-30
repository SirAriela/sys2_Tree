#include "tree.hpp"


template<typename T,int k>
Tree<T,k>::Tree():root(nullptr) {}

template<typename T,int k>
Tree<T,k>::~Tree(){
    delete_sub(root);
}

template<typename T,int k>
void Tree<T,k>::add_root(Node<T>& node){
    this->root = node;
}

template<typename T, int k>
void Tree<T,k>::add_sub_node(Node<T>& parent, Node<T>& child){
    if(parent.children.size() < k){
    parent->children->push_back(&child);
    }
    else {
        throw std::out_of_range("cant add more childrens");
    }
}

