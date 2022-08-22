#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef struct binaryTree
{
    char value;
    binaryTree *leftChild;
    binaryTree *rightChild;
}*tnp;
class CTree
 {
 public:
     tnp m_rootTree;
     CTree(){}
     CTree(char *type,char *str1,char *str2);
     tnp createNodalPoint(char data);
     void connect(tnp parent,tnp leftChild,tnp rightChild);
     tnp pre_in(char *pre,char *_in,long size);
     tnp in_post(char *_in,char *_post,long size);
     void preOrder(tnp root);
     void inOrder(tnp root);
     void postOrder(tnp root);
     void levelOrder(tnp root);
     ~CTree();
 };
 
CTree::CTree(char *type,char *str1,char *str2)
{
    if (!strcmp(type, "pre_in")) {
        m_rootTree=pre_in(str1,str2,strlen(str1));
    }
    else if(!strcmp(type, "in_post")){
        m_rootTree=in_post(str1,str2,strlen(str1));
    }
}

tnp CTree::createNodalPoint(char data){
    tnp newNodalPoint=new binaryTree;
    newNodalPoint->value=data;
    newNodalPoint->leftChild=NULL;
    newNodalPoint->rightChild=NULL;
    return newNodalPoint;
}

void CTree::connect(tnp parent,tnp leftChild,tnp rightChild){
    parent->leftChild=leftChild;
    parent->rightChild=rightChild;
}

tnp CTree::pre_in(char *_pre,char *_in,long size){
    if (size<=0) {
        return NULL;
    }
    tnp newTree=createNodalPoint(*_pre);
    char *position=strchr(_in,*_pre);
    long distance=position-_pre;
    newTree->leftChild=pre_in(_pre+1,_in,distance);
    newTree->rightChild=
    pre_in(_pre+1+distance,_in+1+distance,size-1-distance);
    return newTree;
}

tnp CTree::in_post(char *_in,char *_post,long size){
    if (size<=0) {
        return NULL;
    }tnp newTree=createNodalPoint(*(_post+size-1));
    char *position=strchr(_in,*(_post+size-1));
    long distance=position-_post;
    newTree->leftChild=in_post(_in,_post,distance);
    newTree->rightChild=
    in_post(_in+1+distance,_post+distance,size-1-distance);
    return newTree;
}

void CTree::preOrder(tnp root){
    if (root)
    {
        printf("%c",root->value);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

void CTree::inOrder(tnp root){
    if (root)
    {
        inOrder(root->leftChild);
        printf("%c",root->value);
        inOrder(root->rightChild);
    }
}

void CTree::postOrder(tnp root){
    if (root)
    {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        printf("%c",root->value);
    }
}

void CTree::levelOrder(tnp root){
    if (root) {
        queue<tnp> traversal;
        tnp current;
        traversal.push(root);
        while (!traversal.empty()) {
            current=traversal.front();
            printf("%c",current->value);
            traversal.pop();
            if (current->leftChild)
            {
                traversal.push(current->leftChild);
            }
            if (current->rightChild)
            {
                traversal.push(current->rightChild);
            }
            
        }
    }
}

CTree::~CTree(){
    //delete m_rootTree;
}
