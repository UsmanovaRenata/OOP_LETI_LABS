#include "application.h"
#include"matrix.h"
#include"number.h"


int Application::exec()
{
	int choice;
	int size;
	Matrix m = Matrix();
	while (true) {
		choice = menu();
		switch(choice)
		{
		case 1:
		{
			cout << "\nenter size" << endl;
			cin >> size;
			m = Matrix(size);
		}
			break;
		case 2:
			cout << "\nMatrix determinant: "<< m.determinant() << endl;
			break;
		case 3:
			cout << "\n";
			m.transposition();
			m.print();
			break;
		case 4:
			m.rank();
			break;
		case 5:
			m.print();
			break;
		case 6:
			return 0;
		default:
			cout << "\nThe menu has not choice " << choice << endl;
		}
	}

	return 0;
}

int Application::menu()
{
	int choice;
	cout << "1 - initializing the matrix" << endl;
	cout << "2 - matrix determinant" << endl;
	cout << "3 - matrix transposition" << endl;
	cout << "4 - matrix rank" << endl;
	cout << "5 - print" << endl;
	cout << "6 - exit" << endl;
	cin >> choice;
	return choice;

}
