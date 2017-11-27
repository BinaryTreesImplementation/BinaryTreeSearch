#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>


using namespace std;

template <class T>
struct Node
{
	T element, count, level;
	Node<T> *left, *right, *parent;
};

template <class T>
class AAT {
private:
	Node<T>* root;
public:
	AAT();
	int countNode(Node<T>* t);
	int lookup(T &el);
	Node<T>* insert(Node<T>* t, Node<T>* x);
	void Skew(Node<T>* t);
	bool Split(Node<T>* t);
	void Rebal(Node<T>* t);
	void Print(Node<T>* t);
	Node<T>* getroot() const;



};




template <typename T> AAT<T>::AAT() {
	root = NULL;
}



template <typename T> 
int AAT<T>::lookup(T &element) {

	Node<T>* temp = new Node<T>;
	temp->element = element;
	temp->level = 1;
	temp->count = 0;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	temp = insert(root, temp);

	return temp->count;
}



template <typename T> 
void AAT<T>::Skew(Node<T>* temp) {

	Node<T> *ptr = temp->left;
	if (temp->parent->left == temp)
		temp->parent->left = ptr;
	else
		temp->parent->right = ptr;
	ptr->parent = temp->parent;
	temp->parent = ptr;
	temp->left = ptr->right;
	if (temp->left != NULL)
		temp->left->parent = temp;
	ptr->right = temp;
	temp->level = (temp->left ? temp->left->level + 1 : 1);
}



template <typename T> 
bool AAT<T>::Split(Node<T>* temp) {

	Node<T>* ptr = temp->right;
	if (ptr && ptr->right && (ptr->right->level == temp->level))
	{
		if (temp->parent->left == temp)
			temp->parent->left = ptr;
		else
			temp->parent->right = ptr;
		ptr->parent = temp->parent;
		temp->parent = ptr;
		temp->right = ptr->left;
		if (temp->right != NULL)
			temp->right->parent = temp;
		ptr->left = temp;
		ptr->level = temp->level + 1;
		return true;
	}
	return false;
}


template <typename T>
void AAT<T>::Rebal(Node<T>* temp) {

	temp->left = NULL;
    temp->right = NULL;
    temp->level = 1;
    for (temp = temp->parent; temp != root; temp = temp->parent)
    {
        if (temp->level != (temp->left ? temp->left->level + 1 : 1 ))
        {
            Skew(temp);
            if (temp->right == NULL)
                temp = temp->parent;
            else if (temp->level != temp->right->level)
                temp = temp->parent;
        }
        if (temp->parent != root)
        {
            if (Split(temp->parent) == false)
                break;
        }
    }
}




template <typename T> 
Node<T>* AAT<T>::insert(Node<T>* temp, Node<T>* x) {

	if (root == NULL)
	{
		x->count = 1;
		x->parent = NULL;
		x->left = NULL;
		x->right = NULL;
		root = x;
		return root;
	}
	if (x->element < temp->element)
	{
		if (temp->left)
			return insert(temp->left, x);
		temp->left = x;
		x->parent = temp;
		x->count = 1;
		Rebal(x);
		return x;
	}
	if (x->element > temp->element)
	{
		if (temp->right)
			return insert(temp->right, x);
		temp->right = x;
		x->parent = temp;
		x->count = 1;
		Rebal(x);
		return x;
	}
	temp->count++;
	delete x;
	return temp;
}


template <typename T> 
Node<T>* AAT<T>::getroot() const {
	return root;
}


template <typename T> 
void AAT<T>::Print(Node<T>* temp) {

	if (!temp)
		return;
	Print(temp->left);
	cout << "Value: " << temp->element << "  Count:" << temp->count;
	cout << "  Level: " << temp->level << endl;
	Print(temp->right);
}



template <typename T>
int AAT<T>::countNode(Node<T>* temp) {

	if (!temp)
		return 0;
	int count = 1;
	count = count + countNode(temp->left);
	count = count + countNode(temp->right);
	return count;
}