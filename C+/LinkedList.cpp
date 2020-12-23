#include "bst.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Node::Node()
{   this->info = 0;
    this->name= name;
    this->quantity = quantity;
    this->version= version;
    this->price=price;
    this->parent =0;
    this->left=0;
    this->right=0;
}
string node::get_name()
{
    return this->name;
}
void node::set_name(string name)
{this->name = name;}
string node::get_version()
{
    return this->version;
}
void node::set_version(string version)
{this->version = version;}
string node::get_quantity()
{
    return this->quantity;
}
void node::set_quantity(string quantity)
{this->quantity = quantity;}
string node::get_price()
{
    return this->price;
}
void node::set_price(string price)
{this->price = price;}
BST::BST()
{
    root= 0;
    
}
bst::~BST()
{
    this->destr_helper(this->root);
}
void bst::destr_helper(Node* node)
{
    if(node){
        this->destr_helper(node->left);
        this->destr_helper(node->right);
        delete node;}
}

bool BST::search(string info)
{
    return this->search_helper(this->root, info);
}
bool bst::search_helper(Node* node, string info)
{
    if(node==NULL)
    {
        cout<<info<<" is not in the list"<<endl;
        return false;
    }
    else if(node->get_name()==info)
    {
        cout<<info<<" is in the list"<<endl;
        return true;
    }
    else if(info < node->get_name())
    {
        return this->search_helper(node->left, info);
        
    }
    else
    {
        return this->search_helper(node->right, info);
    }
}
void bst::inorderTraversal()
{
    cout<<"Inorder Traversal"<<endl;
    this->inorder_help(this->root);
    
}
void bst::inorder_help(Node* ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    
    inorder_help(ptr->left);
    
    cout<<ptr->get_name()<<endl;
    
    inorder_help(ptr->right);
}


bool bst::remove_help(Node* info, Node* ptr)
{
    if(info==NULL)
    {
        return false;
    }
    else if(info->left ==NULL && info->right ==NULL)
    {
    if(info == root)
    {
        root=NULL;
    }
    else
    {
        if(info == ptr->left)
        {
            ptr->left=NULL;
        }
        else
        {
            ptr->right = NULL;
        }
    }   
        delete info;
    }
    else if(info->left !=NULL && info->right ==NULL)
    {
        if(info == root)
        {
            root=info->left;
        }
        else
        {
            if(info == ptr->left)
            {
                ptr->left=info->left;
            }
            else
            {
                ptr->right = info->left;
            }
        }
        delete info;
    }
    else if(info->left ==NULL && info->right !=NULL)
    {
        if(info == root)
        {
            root=info->right;
        }
        else
        {
            if(info == ptr->left)
            {
                ptr->left=info->right;
            }
            else
            {
                ptr->right = info->right;
            }
        }
        delete info;
    }
    else
    {
        Node* temp = info->right;
        Node* temp2= info;
        while(temp->left!=NULL)
        {
            temp2=temp;
            temp=temp->left;
        }
        Node temp3;
        temp3=*temp;
        remove_help(temp, temp2);
        info->set_name(temp3.get_name());
        info->set_version(temp3.get_version());
        info->set_quantity(temp3.get_quantity());
        info->set_price(temp3.get_price());
        
    }
    return true;
}
/*{
    if(root==NULL)
    {cout<<"BST is empty"<<endl;
        return root;
    }
    if(info < root->get_name())
    {
        root->left = remove_help(root->left, info);
    }
    else if(info > root->get_name())
    {
        root->right = remove_help(root->right, info);
    }
    else
    {
        
        
        if (root->left == NULL){
            node *temp = new Node();
            temp=root->right;
            while(root->right!=NULL)
             {
             root=root->right;
             }
            cout<<"H"<<endl;
             temp->set_name(root->get_name());
             temp->set_version(root->get_version());
             temp->set_price(root->get_price());
             temp->set_quantity(root->get_quantity());
            delete root;
            
            return temp;
            
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            
            return temp;
        }
        node * temp = root -> right;
        while (temp->left != NULL)
        {temp = temp->left;}
        root->info=temp->info;
        root->right = remove_help(root->right, temp->get_name());
        
        
    }
    return root;
}*/

void bst::addSoftware(int info, std::string name, std::string version, std::string quantity, std::string price)
{
    Node* ptr = new Node();
    ptr->info=info;
    ptr->set_name(name);
    ptr->set_version(version);
    ptr->set_quantity(quantity);
    ptr->set_price(price);
    ptr->left=0;
    ptr->right=0;
    
    if(root == NULL) //empty tree
        root = ptr;
    else
    {
        Node* ptr2 = root;
        while(ptr2 != NULL)
        {
            if(info < ptr2->info)
            {
                if(ptr2->left == NULL) 
                {
                    ptr2->left = ptr;
                    return;
                }
                else
                    ptr2 = ptr2->left;
            }
            else
            {
                if(ptr2->right == NULL)
                {
                    ptr2->right = ptr;
                    return;
                }
                else
                    ptr2 = ptr2->right;
            }
        }
    }
}

bool bst::removeSoftware(int info)
{
    Node* ptr= new Node();
    ptr=NULL;
    Node* ptr2= new Node();
    ptr2=NULL;
    searchNode(info, ptr,ptr2);
    if(ptr==NULL)
    {
        cout<<"Empty"<<endl;
        return false;
    }
    else
    {
        return remove_help(ptr, ptr2);
    }
}

void bst::searchNode(int info, Node* &ptr, Node* &ptr2)
{
    ptr = root;
    ptr2= NULL;
    while(ptr!=NULL)
    {
        if(info==ptr->info)
        {
            break;
           
        }
        ptr2= ptr;
        if(info<ptr->info)
        {
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    if(ptr==NULL)
    {
        ptr2=NULL;
    }
}


void BST::readFile(){
    string line;
    string pie;
    ifstream myfile;
    int x=1;
    node* s1= new Node();
    node* s2= new Node();
    node* s3= new Node();
    node* s4= new Node();
    node* s5= new Node();
    myfile.open("/Users/michaeldichiara/Desktop/DSProject/Software.dat", ios::beg);
    while(getline(myfile, line))
    {   cout<<line<<endl;
        int y=1;
        stringstream ss(line);
        while(getline(ss ,pie,'\t'))
        {
            
            if(x==1){
                if(y==1){
                    cout<<pie<<endl;
                    s1->set_name(pie);
                    
                }
                if(y==2){
                    cout<<pie<<endl;
                    s1->set_version(pie);
                    
                }
                if(y==3){
                    cout<<pie<<endl;
                    s1->set_quantity(pie);
                    
                }
                if(y==4){
                    cout<<pie<<endl;
                    s1->set_price(pie);
                    s1->info=1;
                    addSoftware(s1->info, s1->get_name(), s1->get_version(), s1->get_quantity(), s1->get_price());
                }}
            
            if(x==2){
                if(y==1){
                    cout<<pie<<endl;
                    s2->set_name(pie);
                    
                }
                if(y==2){
                    cout<<pie<<endl;
                    s2->set_version(pie);
                    
                }
                if(y==3){
                    cout<<pie<<endl;
                    s2->set_quantity(pie);
                    
                }
                if(y==4){
                    cout<<pie<<endl;
                    s2->set_price(pie);
                    s2->info=2;
                    addSoftware( s2->info, s2->get_name(), s2->get_version(), s2->get_quantity(), s2->get_price());
                    
                }}
            
            if(x==3){
                if(y==1){
                    cout<<pie<<endl;
                    s3->set_name(pie);
                    
                }
                if(y==2){
                    cout<<pie<<endl;
                    s3->set_version(pie);
                    
                }
                if(y==3){
                    cout<<pie<<endl;
                    s3->set_quantity(pie);
                    
                }
                if(y==4){
                    cout<<pie<<endl;
                    s3->set_price(pie);
                    s3->info=3;
                    addSoftware( s3->info, s3->get_name(), s3->get_version(), s3->get_quantity(), s3->get_price());
                }}
            if(x==4){
                
                if(y==1){
                    cout<<pie<<endl;
                    s4->set_name(pie);
                    
                }
                if(y==2){
                    cout<<pie<<endl;
                    s4->set_version(pie);
                    
                }
                if(y==3){
                    cout<<pie<<endl;
                    s4->set_quantity(pie);
                    
                }
                if(y==4){
                    cout<<pie<<endl;
                    s4->set_price(pie);
                    
                    s4->info=4;
                    addSoftware( s4->info, s4->get_name(), s4->get_version(), s4->get_quantity(), s4->get_price());
                }
                
            }
            if(x==5){
                
                if(y==1){
                    cout<<pie<<endl;
                    s5->set_name(pie);
                    
                }
                if(y==2){
                    cout<<pie<<endl;
                    s5->set_version(pie);
                    
                }
                if(y==3){
                    cout<<pie<<endl;
                    s5->set_quantity(pie);
                    
                }
                if(y==4){
                    cout<<pie<<endl;
                    s5->set_price(pie);
                    
                    s5->info=5;
                    addSoftware( s5->info, s5->get_name(), s5->get_version(), s5->get_quantity(), s5->get_price());
                }
                
            }
            
            y++;
        }
        x++;
    }

    myfile.close();
}




void bst::updateQuantity(int info)
{
    Node* ptr= new Node();
    ptr=this->root;
    string update;
    ptr= returnNode(info, ptr);
    
    if(ptr==NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }
    else
    {
        
        if(ptr->info == info)
        {
            cout<<ptr->get_quantity()<<endl;
            cout<<"Enter new quantity"<<endl;
            cin>>update;
            ptr->set_quantity(update);
            cout<<ptr->get_quantity()<<endl;
            if(ptr->get_quantity()=="0")
            {
                
                switchD(ptr);
                
            }
            
        }
        
    }
    
    
}
Node* bst::returnNode(int info, node *ptr)
{
    if(ptr !=NULL)
    {
        if(ptr->info==info)
        {
            return ptr;
        }
        else
        {
            if(info < ptr->info)
            {
                return returnNode(info, ptr->left);
            }
            else
            {
                return returnNode(info, ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}


void bst::write()
{
    ofstream myfile("/Users/michaeldichiara/Desktop/DSProject/Software.dat", ios::ate);
    myfile.clear();
    myfile.close();
    node*ptr = this->root;
    write_help(ptr);
}

void bst:: write_help(Node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    ofstream myfile("/Users/michaeldichiara/Desktop/DSProject/Software.dat", fstream::in | fstream::out | fstream::app);
    myfile<<ptr->get_name()<<"\t"<<ptr->get_version()<<"\t"<<ptr->get_quantity()<<"\t"<< ptr->get_price()<<endl;
    write_help(ptr->left);
    write_help(ptr->right);
    myfile.close();
    
}
void bst::switchD(node* info)
{
    node* nswitch= new Node();
    nswitch=this->root;
    nswitch=s_help(nswitch);
    info->set_name(nswitch->get_name());
    info->set_version(nswitch->get_version());
    info->set_quantity(nswitch->get_quantity());
    info->set_price(nswitch->get_price());
    removeSoftware(nswitch->info);
    
}
node * bst::s_help(node * ptr)
{
    if(ptr==NULL)
    {
        cout<<"Empty"<<endl;
        return ptr;
    }
    while(ptr->right!= NULL)
    {
       ptr=ptr->right;
    }
    return ptr;
}
