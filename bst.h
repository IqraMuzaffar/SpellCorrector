//
//  main.cpp
//  BST
//
//  Created by Hina Khalid  on 17/06/2020.
//  Updated on 28/03/2022
//  Copyright © 2022 Hina Khalid . All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/////////////////BST

class treeNode
{
public:
    treeNode *left;
    treeNode *right;
    string data;
    treeNode *parent;
};

class BST
{

public:
    treeNode *root;

    BST()
    {
        root = NULL;
    }

    ////////// Inorder Traversal

 void InorderTraverse(treeNode *n)
    {
        if (n != NULL)
        {
            InorderTraverse(n->left);
            cout << n->data << " ";
            InorderTraverse(n->right);
        }
    }


    ////////// Insert in Tree
   void insert(string m)
    {
        treeNode *z = new treeNode();
        z->data = m;
        z->left = NULL;
        z->right = NULL;

        treeNode *y = NULL;
        treeNode *x = root;

        while (x != NULL)
        {

            y = x;
            if (x->data.compare(z->data) > 0)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (root == NULL)
            root = z;
        else if (y->data.compare(z->data) < 0)
            y->right = z;
        else
            y->left = z;
    }
  
 

    bool search(string s)
    {
        treeNode *x = root;
        while (x != NULL)

        {
            if (x->data.compare(s) > 0)
            {
                x = x->left;
            }
            else if (x->data.compare(s) < 0)
            {
                x = x->right;
            }
            else if (x->data.compare(s) == 0)
            {
                return true;
            }
            else{
                return false;
            }
        }
      
    }
  

};

// int main()
// {
//     BST St;
//       St.insert("pat");
//         St.insert("use");
//         St.insert("zoo");
//         St.insert("try");
//         St.insert("bat");
//         St.insert("hay");
//         St.insert("key");
//         St.insert("jig");
//         St.insert("apple");
//         St.insert("swag");
//         St.insert("sack");
//         St.insert("flip");
//         St.insert("void");
//         St.insert("insert");
//         St.insert("zzz");

//     cout << endl;

//     cout<<St.search("insert");

    // cout<<St.TreeMin()<<endl;
    // cout<<St.TreeMax()<<endl;

    //    treeNode* scNode=St.Predecessor("bat");
    //    cout<<scNode->data<<endl;
    //    treeNode* scNode1=St.Successor("hay");
    //    cout<<scNode1->data<<endl;





    //    St.PreorderTraverse(St.root);
    //    cout<<endl;
    //    St.PostorderTraverse(St.root);
    //    cout<<endl;

    //    treeNode* sNode=St.search("hay");
    //    if(sNode!=NULL)
    //        cout<<sNode->data<<endl;
    //    else
    //        cout<<"Data not found"<<endl;

//        St.deleteNode("key");
//        St.InorderTraverse(St.root);
//        cout<<endl;

//        St.deleteNode("bat");
//        St.InorderTraverse(St.root);
//        cout<<endl;

//        St.deleteNode("use");
//        St.InorderTraverse(St.root);
//        cout<<endl;
    
// }
