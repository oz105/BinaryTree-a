#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stack>
#include <string>
#include <list>

namespace ariel {

    template <class T>

    class BinaryTree{
        private:
            struct Node {
                T data;
                Node *left_child = nullptr;
                Node *right_child = nullptr;
                Node* parent = nullptr; 

                Node(const T & val) : data(val){}
            };

            Node *root;

            class Iterator {
                private:
                    Node *_curr;


                public:
                    Iterator(Node *ptr = nullptr): _curr(ptr){ }
                
                    T& operator*() const{return _curr->data;}

                    T* operator->() const{return &(_curr->data);} 

                    Iterator& operator++() {
                        _curr = _curr->right_child;
                        return *this;
                    }

                    const Iterator operator++(int) {
                        Iterator tmp = *this;
                        _curr = _curr->right_child;
                        return tmp;
                    }

                    bool operator==(const Iterator &other) const {return _curr == other._curr;}


                    bool operator!=(const Iterator &other) const {return _curr != other._curr;} 

                    T* operator -> (){
                        return &_curr->data;
                    }    
            }; 

    public:

        BinaryTree<T>():root(nullptr) { }

        BinaryTree& add_root(const T &val);

        BinaryTree& add_left(const T &obj, const T &left);
    
        BinaryTree& add_right(const T &obj, const T &right);

        Iterator begin_preorder();

        Iterator end_preorder();
        
        Iterator begin_inorder();

        Iterator end_inorder();

        Iterator begin_postorder();
     
        Iterator end_postorder();
     
        Iterator begin();
   
        Iterator end();

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &bt)
        {
            return os;
        }

    };

    template <typename T>
    BinaryTree<T>&  BinaryTree<T>::add_root(const T &val){
        if(root == nullptr){
            root = new Node(val);
            return *this; 
        }
        root->data = val;
        return *this;
        
    }

    template <typename T>
    BinaryTree<T>&  BinaryTree<T>::add_left(const T &obj, const T &left){
        if(root==nullptr){
            throw std::invalid_argument("There is no root in this BinaryTree");   
        }
        return *this;
    }

    template <typename T>
    BinaryTree<T>&  BinaryTree<T>::add_right(const T &obj, const T &right){
        return *this;
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::begin(){
        return Iterator{root};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::end(){
        return Iterator{nullptr};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::begin_preorder(){
        return Iterator{root};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::end_preorder(){
        return Iterator{nullptr};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::begin_inorder(){
        return Iterator{root};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::end_inorder(){
        return Iterator{nullptr};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::begin_postorder(){
        return Iterator{root};
    }

    template <typename T>
    typename BinaryTree<T>::Iterator BinaryTree<T>::end_postorder(){
        return Iterator{nullptr};
    }

} 