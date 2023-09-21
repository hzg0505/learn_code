#ifndef TREE_H
#define TREE_H
    struct node{
        int val;
        node* lchild;
        node* rchild;
    };

    node* newNode(int val);

    void PreOrder(node* root);
    void insert(node* &root, int val);

#endif




// #ifndef TREE_H
// #define TREE_H
// #include <string>
// #include <iostream>

// struct node{
//     int val;
//     node* lchild;
//     node* rchild;
// };



// // void search(node*)

// class BinTree
// {
// private:
//     node* root;
// public:
    
//     node* newNode(int val);
//     void insert(int val);
//     // void PreOrder();
// };

// #endif
