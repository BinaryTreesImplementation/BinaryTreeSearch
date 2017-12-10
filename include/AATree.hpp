#include <iostream>     



using namespace std;

template <typename T>
class AATree {

private:


	struct AANode
	{
		T element;
		AANode    *left;
		AANode    *right;
		int        level;

		AANode() : left(NULL), right(NULL), level(1) { }
		AANode(const T & e, AANode *lt, AANode *rt, int lv = 1)
			: element(e), left(lt), right(rt), level(lv) { }
	};


	AANode *root;
	AANode *bottom;
	size_t count;

public:


	AATree()
	{
		bottom = new AANode;
		bottom->left = bottom->right = bottom;
		bottom->level = 0;
		root = bottom;
		count = 0;
	}




	AANode* search(const T & x) const
	{
		AANode *current = root;
		bottom->element = x;

		for (; ; )
		{
			if (x < current->element)
				current = current->left;
			else if (current->element < x)
				current = current->right;
			else
				return current;
		}
	}



	void printTree() const
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
		count--;
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

	size_t getcount() {
		return count;
	}
};
