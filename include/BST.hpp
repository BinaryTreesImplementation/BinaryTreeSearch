#include <iostream>
#include <string>

template <class T> struct Node
{
	T element;
	Node* left;
	Node* right;
	Node* parent;
};

template <class T> class BST
{
private:
	Node<T>* root;
	unsigned int count;
public:

	BST()
	{
		root = nullptr;
		count = 0;
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

	void deleteNode(Node<T>* temp)
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
			Node<T>* daughter = new Node<T>;
			daughter->element = added;
			daughter->left = daughter->right = daughter->parent = nullptr;
			Node<T>* parent = root;
			Node<T>* temp = root;
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
			count++;
		}
		catch (int i)
		{
			std::cout << "This number \"" << added << "\" has already added in the tree!\nError #5\n";
		}
	}

	void display(const Node<T>* temp, unsigned int level)const
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
		return count;
	}

	Node<T>* get_pointer(const T& value, Node<T>* temp)const
	{
		if (temp == 0 || value == temp->element)
			return temp;
		if (value > temp->element)
			return get_pointer(value, temp->right);
		else return get_pointer(value, temp->left);
	}

	Node<T>* search_result(const T& value)const
	{
		return get_pointer(value, root);
	}

	Node<T>* root_()const
	{
		return root;
	}

	void reading(const std::string& filename)
	{
		try
		{
			std::ifstream fin(filename);
			if (!fin)
				throw 1;
			T temp;
			fin >> count;
			for (int i = 0; i < count; ++i)
			{
				fin >> temp;
				insert(temp);
				count--;
			}
			fin.close();
		}
		catch (int i)
		{
			std::cout << "File doesn't exist!\nError #1\n";
		}
	}
	

	Node<T>* minValue(Node<T>* cur)
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
			Node<T>* delNode = get_pointer(value, root);
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
					--count;
					return;
				}
				if (delNode->parent->right == delNode)
				{
					delNode->parent->right = nullptr;
					delete delNode;
					--count;
					return;
				}
			}
			if (delNode->parent&&delNode->left)
			{
				delNode->parent->left = delNode->left;
				delNode->left->parent = delNode->parent;
				delete delNode;
				--count;
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
				--count;
				return;
			}
			if (delNode->left)
			{
				root = delNode->left;
				delNode->left = nullptr;
				delete delNode;
				--count;
				return;
			}
			if (delNode->right)
			{
				root = delNode->right;
				delNode->right = nullptr;
				delete delNode;
				--count;
				return;
			}
			if (!delNode->parent && !delNode->left && !delNode->right)
			{
				root = nullptr;
				delete delNode;
				--count;
				return;
			}

		}

		catch (int i)
		{
			std::cout << "There isnt element \"" << value << "\" in the tree!\nError#6\n";
		}
	}

	bool compare(const Node<T>* temp1, const Node<T>* temp2)const
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
	bool operator == (const BST<T>& tree)const
	{
		return (compare(root, tree.root_()));
	}


	T* getRightKey(const T& key)
	{
		Node<T> *node = search_result(key);
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
		Node<T> *node = search_result(key);
		if (node != nullptr && node->left != nullptr)
			return new T(node->left->element);
		else
			return nullptr;
	}


	T* getParentKey(const T& key)
	{
		Node<T> *node = search_result(key);
		if (node != nullptr && node->parent != nullptr)
			return new T(node->parent->element);
		else
			return nullptr;
	}
};
	{
		if (root == bottom)
			cout << "Empty tree" << endl;
		else
			printTree(root);
	}


	void insert(const T & x)
	{
		insert(x, root);
		count++;

	}

	void remove(const T & x)
	{
		remove(x, root);
		count--;
	}



	void insert(const T & x, AANode * & t)
	{
		if (t == bottom)
			t = new AANode(x, bottom, bottom);
		else if (x < t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);
		else
			return; 

		skew(t);
		split(t);
	}

	void remove(const T & x, AANode * & t)
	{
		static AANode *lastNode, *deletedNode = bottom;

		if (t != bottom)
		{
			// Step 1: Search down the tree and set lastNode and deletedNode
			lastNode = t;
			if (x < t->element)
				remove(x, t->left);
			else
			{
				deletedNode = t;
				remove(x, t->right);
			}

			// Step 2: If at the bottom of the tree and
			//         x is present, we remove it
			if (t == lastNode)
			{
				if (deletedNode == bottom || x != deletedNode->element)
					return;   // Item not found; do nothing
				deletedNode->element = t->element;
				deletedNode = bottom;
				t = t->right;
				delete lastNode;
			}

			// Step 3: Otherwise, we are not at the bottom; rebalance
			else
				if (t->left->level < t->level - 1 ||
					t->right->level < t->level - 1)
				{
					if (t->right->level > --t->level)
						t->right->level = t->level;
					skew(t);
					skew(t->right);
					skew(t->right->right);
					split(t);
					split(t->right);
				}
		}
		
	}



	void printTree(AANode *t) const
	{
		if (t != bottom)
		{
			printTree(t->left);
			cout << t->element << endl;
			printTree(t->right);
		}
	}

	void skew(AANode * & t)
	{
		if (t->left->level == t->level)
			rotateWithLeftChild(t);
	}


	void split(AANode * & t)
	{
		if (t->right->right->level == t->level)
		{
			rotateWithRightChild(t);
			t->level++;
		}
	}

	void rotateWithLeftChild(AANode * & k2)
	{
		AANode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2 = k1;
	}

	void rotateWithRightChild(AANode * & k1)
	{
		AANode *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1 = k2;
	}

	T* getLevel(const T& key)
	{
		AANode *node = search(key);
		if (node != nullptr)
			return new T(node->level);
		else
			return nullptr;
	}

	T* getRightKey(const T& key)
	{
		AANode *node = search(key);
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
		AANode *node = search(key);
		if (node != nullptr && node->left != nullptr)
			return new T(node->left->element);
		else
			return nullptr;
	}

	int getcount() {
		return count;
	}
	
	AANode* getroot() const {
		return root;
	}
};
