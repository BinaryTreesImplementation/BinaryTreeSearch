#include "BST.hpp"

int main() {

	AAT<int> at;
	int ch;
	int x;
	ifstream fin("test.txt");
	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "\nOperations on AA Tree" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.Insert element into Tree" << endl;
		cout << "2.Print Tree" << endl;
		cout << "3.Delete element" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter element to enter" << endl;
			cin >> x;
			at.insert(x);
			break;
		case 2:
			cout << "Elemets of AA Tree" << endl;
			at.display(at.root_(),0);
			break;
		case 3:
			cout << "Enter element to delete" << endl;
			cin >> x;
			at.remove(x);
			break;
		
		case 5:
			cout << "Exiting" << endl;
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
	return 0;
}
