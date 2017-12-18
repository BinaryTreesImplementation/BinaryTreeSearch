#include <iostream>
#include <string>
class Counter
{
protected:
	size_t& Count() { static size_t counter = 0; return counter; }
	
public:
	Counter() { ++Count(); }
	~Counter() { --Count(); }
};
template <typename T> 
class BST
{
private:
	
	struct Node: public Counter
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
		try
		{
			if (search_result(added))
				throw 5;
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
		catch (int i)
		{
			std::cout << "This number \"" << added << "\" has already added in the tree!\nError #5\n";
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

	Node* get_pointer(const T& value, Node* temp)const
	{
		if (temp == 0 || value == temp->element)
			return temp;
		if (value > temp->element)
			return get_pointer(value, temp->right);
		else return get_pointer(value, temp->left);
	}

	Node* search_result(const T& value)const
	{
		return get_pointer(value, root);
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

	void remove(const T value)
	{
		try
		{
			Node* delNode = get_pointer(value, root);
			if (!search_result(value))
				throw 6;

			if (delNode->left && delNode->right)
			{
				delNode->element = minValue(delNode->right)->element;
				delNode = minValue(delNode->right);
			}


			if (!delNode->left && !delNode->right)
			{
				if (delNode->parent == nullptr)
				{
					root = nullptr;
					delete delNode;
					--count;
					return;
				}
				if (delNode->parent->left == delNode)
				{
					delNode->parent->left = nullptr;
					delete delNode;

					return;
				}
				if (delNode->parent->right == delNode)
				{
					delNode->parent->right = nullptr;
					delete delNode;
					
					return;
				}
			}
			if (delNode->parent&&delNode->left)
			{
				delNode->parent->left = delNode->left;
				delNode->left->parent = delNode->parent;
				delete delNode;
				
				return;
			}
			if (delNode->parent&&delNode->right)
			{
				if (delNode == delNode->parent->left)
				{
					delNode->parent->left = delNode->right;
				}
				else delNode->parent->right = delNode->right;
				delNode->right->parent = delNode->parent;
				delete delNode;
				
				return;
			}
			if (delNode->left)
			{
				root = delNode->left;
				delNode->left = nullptr;
				delete delNode;
				
				return;
			}
			if (delNode->right)
			{
				root = delNode->right;
				delNode->right = nullptr;
				delete delNode;
				
				return;
			}
			if (!delNode->parent && !delNode->left && !delNode->right)
			{
				root = nullptr;
				delete delNode;
				
				return;
			}

		}

		catch (int i)
		{
			std::cout << "There isnt element \"" << value << "\" in the tree!\nError#6\n";
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
		Node *node = search_result(key);
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
		Node *node = search_result(key);
		if (node != nullptr && node->left != nullptr)
			return new T(node->left->element);
		else
			return nullptr;
	}


	T* getParentKey(const T& key)
	{
		Node *node = search_result(key);
		if (node != nullptr && node->parent != nullptr)
			return new T(node->parent->element);
		else
			return nullptr;
	}
};
