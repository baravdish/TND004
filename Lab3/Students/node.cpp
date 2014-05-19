/**********************************************
* File: node.cpp                              *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2014                             *
* Description: class Node                     *
***********************************************/

#include "node.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS


Node::Node(ELEMENT v, Node *l, Node *r)
 : value(v), left(l), right(r)
{
    l_thread = r_thread = false;
}


//Destructor
//recursively deletes the nodes in the left_subtree and right-subtree
Node::~Node()
{
    //ADD CODE
}


//Insert v in the tree having as root this node (╯°□°)╯︵ ┻━┻
//Return true, if v was inserted
//Otherwise, return false -- v already exists in the tree
bool Node::insert(ELEMENT v)
{
    Node *temp = this;

    istringstream issKey(v.first);
    int val = 0;
    int intKey = 0;
    issKey>>intKey;

	while( temp != nullptr && temp->value.first != v.first)
	{
		istringstream is(temp->value.first);
		is>>val;
		if(val < intKey)
		{
			if(temp->r_thread == true)
			{
				temp->right = new Node(v, temp, temp->right);
				temp->right->l_thread = true;
				temp->right->r_thread = true;
				temp->r_thread = false;
				return true;
			}
			temp = temp->right;
		}
		else
		{
			if(temp->l_thread == true)
			{
				temp->left = new Node(v, temp->left, temp);
				temp->left->l_thread = true;
				temp->left->r_thread = true;
				temp->l_thread = false;
				return true;
			}
			temp = temp->left;
		}
	}
	temp->value.second++;
    return false;
}



//Remove the key from the tree having as root this node
//Return true, if a node storing key was found and deleted
//Otherwise, return false -- there is no node storing key
//isRight==false: this node is left child of parent
//isRight==true: this node is right child of parent
bool Node::remove(string key, Node* parent, bool isRight)
{
    //ADD CODE
    return false;
}



//Remove this node -- this node has at most one child
//isRight==false: this node is left child of parent
//isRight==true: this node is right child of parent
//Remove has 6 cases
//1a: a left child with only a right child
//1b: a left child with only a left child
//1c: a left child with no children
//2a: a right child with only a right child
//2b: a right child with only a left child
//2c: a right child with no children
void Node::removeMe(Node* parent, bool isRight)
{
   //ADD CODE
}



//Return a pointer to the Node storing key
//key is possibly stored in one of the sub-trees of this node
//If there is no node storing key then return nullptr
Node* Node::find(string key)
{
    Node *temp = this;

    istringstream issKey(key);
	int val = 0;
    int intKey = 0;
    issKey>>intKey;

	if(temp->value.first == key)
		return temp;

	while( temp != nullptr && temp->value.first != key)
	{
		istringstream is(temp->value.first);
		is>>val;
		if(val < intKey)
		{
			// cout<<val<<" < "<<intKey<<endl;
			temp = temp->right;
		}
		else
		{
			// cout<<temp->value.first<<" > "<<key<<endl;
			temp = temp->left;
		}
	}
	if(temp == nullptr)
		return nullptr;


	return temp;
}


//Return a pointer to the node storing the smalest value
//of the tree whose root is this node
Node* Node::findMin()
{
    // Går att göra recurs
	Node *temp = this;
    while(temp->l_thread == false)
    {
    	cout<<temp->value.first<<endl;
    	temp = temp->left;
    }
    return temp;
}


//Return a pointer to the node storing the largest value
//of the tree whose root is this node
Node* Node::findMax()
{
	Node *temp = this;
    while(temp->r_thread == false)
    {
    	cout<<temp->value.first<<endl;
    	temp = temp->right;
    }
    return temp;
}



//Display in inorder all keys
//stored in the tree whose root is this node
//recursive function
//Used for debugging -- ONLY
void Node::display() const
{
    if ( !l_thread ) //display left sub-tree
        left->display();

    cout << value.first << " "; //display key stored in the node

    if ( !r_thread ) //display right sub-tree
        right->display();
}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */
