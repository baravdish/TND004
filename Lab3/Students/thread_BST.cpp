/********************************************************
* File: threaded_BST.cpp                                *
* Author: Aida Nordman                                  *
* Course: TND004, Lab 3                                 *
* Date: VT2, 2014                                       *
* Description: class BST_threaded representing          *
*              a threaded binary search tree            *
*********************************************************/

#include "threaded_BST.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

using namespace std;


//Default Constructor: create an empty tree
//Empty tree has a dummy node as root
//The real tree is stored as left child of the dummy root
BST_threaded::BST_threaded()
 : counter(0)
{
    ELEMENT v;
    root = new Node(v, nullptr, nullptr);
}


//destructor
BST_threaded::~BST_threaded()
{
  //ADD CODE
}


//Test if the tree is empty
bool BST_threaded::empty() const
{
     if(counter == 0)
	{
		return true;
	}
    return false;
}

//Return mumber of keys (elements) stored in the tree
int BST_threaded::size() const
{
    return counter;
}


//Insert v in the tree
void BST_threaded::insert(ELEMENT v)
{
    if (empty())
    {
        //Insert first node of the BST has a left child of the BST
        root->left = new Node(v, root, root);
        root->left->l_thread = root->left->r_thread = true;
        counter = 1;
    }
    else
        counter += root->left->insert(v); //call NODE::insert
}


//Remove node with key from the tree
void BST_threaded::remove(string key)
{
   //counter -= root->left->remove eller nåt;
}



//If key matches the key of an element in the container,
//then return a reference to the ELEMENT with the key
//If key does not match the key of any element in the container,
//then behaviour is undefined
ELEMENT& BST_threaded::operator[](string key)
{
    // det krashar om man direkt returnar ett element(VARFÖR?????). Måste gå via en nod. D.v.s. return temp->value(!!!!!!!!!!)

    ELEMENT e(" ", 0);
    Node *p = new Node(e, nullptr, nullptr);
    Node *temp = root->left->find(key);

    if(temp == nullptr)
        return p->value;

    return temp->value;
}


//Find the node in the BST storing key
//Return a BiIterator referring to the node storing the key, if the key is found.
//Otherwise, return this->end().
BiIterator BST_threaded::find(string key) const
{
    Node *temp = root->left->find(key);

    if(temp != nullptr)
    {
        BiIterator it(temp);
        return it;
    }
    if(temp == nullptr)
        cout<<"20 finns ej....";

    return this->end();
}


//Return an iterator referring to the first node in the inorder traversal of the BST
BiIterator BST_threaded::begin() const
{
    Node *temp = root->left->findMin();
    BiIterator it(temp);
    return it;
}


 //Return a BiIterator referring to the past-the-end element in the BST
BiIterator BST_threaded::end() const
{
    BiIterator it(root);

    return it;
}


//Display all keys increasingly
//To be used for debugging -- ONLY
void BST_threaded::display() const
{
    if (!empty())
        root->left->display();
     else
        cout << "The container is empty!!" << endl;

}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */
