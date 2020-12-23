#include <iostream>
#include <fstream>
#include "bst.h"
using namespace std;
int main()
{
    bst Tree;
    
    Tree.readFile();
    Tree.inorderTraversal();
    
    int y=1;
    int info=6;
    while(y==1){
        int x = 0;
        cout<<"Your options for this program are \n1.Add Software \n2.Remove Software \n3.Update Software Quantity \n4.Display Inventory"<< endl;
        cout<<"Enter desired number for program"<<endl;
        cin>>x;
        if(x==1)
        {
            
            string name;
            string version;
            string quantity;
            string price;
            cout<<"Enter name"<<endl;
            cin>>name;
            cout<<"Enter version"<<endl;
            cin>>version;
            cout<<"Enter quantity"<<endl;
            cin>>quantity;
            cout<<"Enter price"<<endl;
            cin>>price;
            
            Tree.addSoftware( info, name, version, quantity, price);
            //Write to file
            info++;
        }
        if(x==2)
        {
            int i;
            Tree.inorderTraversal();
            cout<<"Enter the line number(as its presented) you wish to remove"<<endl;
            cin>>i;
            Tree.removeSoftware(i);
        }
        if(x==3)
        {   int q;
            Tree.inorderTraversal();
            cout<<"Enter the line you wish to update"<<endl;
            cin>>q;
            Tree.updateQuantity(q);
        }
        if(x==4)
        {
            Tree.inorderTraversal();
        }
        cout<< "if you wish to continue enter one"<<endl;
        cout<<"if you wish to exit, enter any other number"<<endl;
        cin>>y;
        
    }
    int z=2;
     while(z==2){ Tree.write();
     z++;
    
    return 0;
}
}
