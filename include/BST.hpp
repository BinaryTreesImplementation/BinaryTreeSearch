#include <iostream>
#include <string>
#ifndef Counter
class Counter
{
protected:
	size_t& Count() { static size_t counter = 0; return counter; }

public:
	Counter() { ++Count(); }
	~Counter() { --Count(); }
};
#endif
template <typename T>
class BST
{
private:

	struct Node : public Counter
	{
		T element;
		Node* left;
		Node* right;
		Node* parent;
		size_t getCounter()
		{
			return Count();
		}
	} *root;
public:

	BST()
	{
		root = nullptr;
	}

	BST(std::initializer_list<T> elements) : BST()
	{

		for (int i = 0; i < elements.size(); i++)
		{
			insert(*(elements.begin() + i));
		}
	}

	~BST()
	{
		deleteNode(root);
	}

	void deleteNode(Node* temp)
	{
		if (!temp)
			return;
		if (temp->left)
		{
			deleteNode(temp->left);
			temp->left = nullptr;
		}

		if (temp->right)
		{
			deleteNode(temp->right);
			temp->right = nullptr;
		}
		delete temp;
	}


	void insert(const T& added)
	{

		Node* daughter = new Node;
		daughter->element = added;
		daughter->left = daughter->right = daughter->parent = nullptr;
		Node* parent = root;
		Node* temp = root;
		while (temp)
		{
			parent = temp;
			if (added < temp->element)
				temp = temp->left;
			else
				temp = temp->right;
		}
		if (!parent)
			root = daughter;
		else
		{
			if (added < parent->element)
			{
				parent->left = daughter;

			}
			else
			{
				parent->right = daughter;

			}
			daughter->parent = parent;
		}
	}



	void display(const Node* temp, unsigned int level)const
	{
		try
		{
			if (!root)
			{
				throw 2;
			}
			if (temp)
			{
				display(temp->left, level + 1);
				for (int i = 0; i < level; i++)
					std::cout << "__";
				std::cout << temp->element << "\n";
				display(temp->right, level + 1);
			}
		}
		catch (int i)
		{
			std::cout << "There is nothing to print\nError #2\n";
		}
	}

	int get_count()const
	{
		return root->getCounter();
	}

	Node *Search(const T& value)const
	{
		Node *searchedElement = root;

		while (searchedElement != nullptr)
		{
			if (searchedElement->element < value)
				searchedElement = searchedElement->right;
			else if (value < searchedElement->element)
				searchedElement = searchedElement->left;
			else if (searchedElement->element == value)
			{
				return searchedElement;
			}
		}

		return nullptr;
	}
	

	Node* root_()const
	{
		return root;
	}


	Node* minValue(Node* cur)
	{
		if (cur->left == nullptr)
			return cur;
		else
			return minValue(cur->left);
	}

	void remove(const T& key)
	{
		Node *removing = Search(key);
		if (removing)
		{
			Node* parent = removing->parent;
			if (!removing->left && !removing->right)
			{
				if (removing != root)
				{
					if (removing->parent->left == removing)
					{
						removing->parent->left = nullptr;
					}
					else
					{
						removing->parent->right = nullptr;
					}
				}
				else
				{
					root = nullptr;
				}
				delete removing;
				return;
			}
			else if (removing->left && !removing->right)
			{
				if (removing->parent->left == removing)
				{
					removing->parent->left = removing->left;
					removing->left->parent = parent;
				}
				else
				{
					removing->parent->right = removing->left;
					removing->left->parent = removing->parent;
				}

				delete removing;
				return;
			}
			else if (removing->right)
			{
				Node* min = minValue(removing->right);
				T minKey = min->element;
				remove(min->element);
				removing->element = minKey;

			}
		}
	}
	bool compare(const Node* temp1, const Node* temp2)const
	{
		bool x = true;
		x = temp1->element == temp2->element;
		if (x)
		{

			if (temp1->left&&temp2->left)
				return compare(temp1->left, temp2->left);
			if (!temp1->left&&temp2->left)
				return false;
			if (temp1->left && !temp2->left)
				return false;
			if (temp1->right&&temp2->right)
				return compare(temp1->right, temp2->right);
			if (!temp1->right&&temp2->right)
				return false;
			if (temp1->right && !temp2->right)
				return false;
			return true;
		}
		else return false;
	}
	bool operator == (const BST& tree)const
	{
		return (compare(root, tree.root_()));
	}


	T* getRightKey(const T& key)
	{
		Node *node = Search(key);
		if (node != nullptr && node->right != nullptr)
			return new T(node->right->element);
		else
			return nullptr;
	}

	T* getKeyRoot()
	{
		if (root)
			return new T(root->element);
		else
			return nullptr;
	}
	T* getLeftKey(const T& key)
	{
		Node *node = Search(key);
		if (node != nullptr && node->left != nullptr)
			return new T(node->left->element);
		else
			return nullptr;
	}


	T* getParentKey(const T& key)
	{
		Node *node = Search(key);
		if (node != nullptr && node->parent != nullptr)
			return new T(node->parent->element);
		else
			return nullptr;
	}
};
