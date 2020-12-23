//
//  Header.h
//  C+
//
//  Created by Michael Dichiara on 9/23/18.
//  Copyright © 2018 Michael Dichiara. All rights reserved.
//


#ifndef linklistupdate_hpp
#define linklistupdate_hpp
#include <string>

using namespace std;




class Node
{   string name;
    string version;
    string quantity;
    string price;
    
    
    
    
public:
    Node *left, *right, *parent;
    Node();
    string get_name();
    void set_name(string);
    string get_version();
    void set_version(string);
    string get_quantity();
    void set_quantity(string);
    string get_price();
    void set_price(string);
    int info;
    
};
typedef class Node node;

class BST
{
    Node *root;
public:
    BST();
    ~BST();
    void destr_helper(Node*);
    bool search(string);
    bool search_helper(Node*,string);
    void searchNode(int info, Node* &ptr, Node* &ptr2);
    void inorderTraversal();
    void inorder_help(Node*);
    void write();
    Node* returnNode(int,node* ptr);
    void write_help(Node* ptr);
    void readFile();
    bool remove_help(Node*, Node*);
    void addSoftware(int info,string name, string version, string quantity,string price);
    bool removeSoftware(int info);
    void updateQuantity(int);
    void switchD(node* );
    node* s_help(node*);
    
};

typedef class BST bst;
#endif /* linklistupdate_hpp */


