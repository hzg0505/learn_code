#include "tree.hpp"
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// struct node{
//     int val;
//     node* lchild;
//     node* rchild;
// };

node* newNode(int val)
{
    node* nn = new node;
    nn->val = val;
    nn->lchild = nullptr;
    nn->rchild = nullptr;
    return nn;
}

void PreOrder(node* root)
{
    if(!root)
    {
        cout << root->val <<endl;
    }else{
        return;
    }
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}

void insert(node* &root, int val)
{
    if(!root){
        root = newNode(val);
    }
    node* p = root;
    while(p)
    {
        if(val > p->val){
            if(p->rchild==nullptr)
            {
                p->rchild = newNode(val);
                break;
            }else{
                p = p->rchild;
            }
        }else{
            if(p->lchild == nullptr)
            {
                p->lchild = newNode(val);
                break;
            }else{
                p = p->lchild;
            }
        }
    }
    // node* newnode = newNode(val);
    // p = newNode;
    // p->val = val;
}


// void insert(node* & root, int val)
// {
//     if(root==nullptr){
//         root = newNode(val);
//         return;
//     }else if(root->val>val)
//     {
//         insert(root->lchild, val);
//     }else{
//         insert(root->rchild, val);
//     }
// }





// node* BinTree::newNode(int val)
// {
//     node* newnode = new node;
//     newnode->val = val;
//     newnode->lchild = NULL;
//     newnode->rchild = NULL;
//     return newnode;
// }

// void BinTree::insert(int val)
// {
//     if(!root){
//         root = newNode(val);
//     }
//     node* p = root;
//     while(p)
//     {
//         if(val > p->val){
//             if(p->rchild==nullptr)
//             {
//                 p->rchild = newNode(val);
//                 break;
//             }else{
//                 p = p->rchild;
//             }
//         }else{
//             if(p->lchild == nullptr)
//             {
//                 p->lchild = newNode(val);
//                 break;
//             }else{
//                 p = p->lchild;
//             }
//         }
//     }
//     // node* newnode = newNode(val);
//     // p = newNode;
//     // p->val = val;
// }


// void BinTree::PreOrder()
// {
//     queue q;
//     if(!root){
//         cout<< root->val << endl;
//     }
    
// }