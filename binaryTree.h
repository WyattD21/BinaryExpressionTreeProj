#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType>* lLink;
    nodeType<elemType>* rLink;

    nodeType() : info(elemType()), lLink(nullptr), rLink(nullptr) {} 
};

template <class elemType>
class binaryTreeType
{
protected:
    nodeType<elemType>* root;  

public:
    binaryTreeType() : root(nullptr) {}  
    virtual ~binaryTreeType() { destroyTree(); }  
    
    virtual bool search(const elemType& searchItem) const = 0;
    virtual void insert(const elemType& insertItem) = 0;
    virtual void deleteNode(const elemType& deleteItem) = 0;

    void destroyTree() { destroyTree(root); } 

protected:
    void destroyTree(nodeType<elemType>*& p) {
        if (p != nullptr) {
            destroyTree(p->lLink);
            destroyTree(p->rLink);
            delete p;
            p = nullptr;
        }
    }
};

#endif
