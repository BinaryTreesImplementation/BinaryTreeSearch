#include "AATree.hpp"

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
		cout << "1.Insert elements from text file" << endl;
		cout << "2.Insert element from keyboard" << endl;
		cout << "3.Print Tree Data" << endl;
		cout << "4.Total Tree Nodes" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			if (fin.is_open())
			{
				while (fin >> x)
				{
					at.lookup(x);
				}
				fin.close();
			}
			break;
		case 2:
			cout << "Enter element" << endl;
			cin >> x;
			at.lookup(x);
		case 3:
			cout << "Elemets of AA Tree" << endl;
			at.Print(at.getroot());
			break;
		case 4:
			cout << "Total number of nodes" << endl;
			cout << at.countNode(at.getroot()) << endl;
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