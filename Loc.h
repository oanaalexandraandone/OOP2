#pragma once
#define LOC_H
#include <iostream>
#include <iomanip>
using namespace std;

class Loc {

private:
	int rows;
	int columns;
	const char ocupat = '1';
	const char neocupat = '0';
	char map[100][100];
	int Quit = 1;
public:

	Loc() {
		this->rows = 10;
		this->columns = 10;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				map[i][j] = neocupat;
		}
	}

	Loc(int rows, int columns) {
		this->rows = rows;
		this->columns = columns;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				map[i][j] = neocupat;
		}
	}

	

	int show_Menu();
	void show_Chart();
	void reserveSeat();


};

void Loc::reserveSeat() {
	int choice=0, i, j;
	do
	{
		choice = show_Menu();
		switch (choice)
		{
		case 1:
			show_Chart();
			do
			{
				cout << "Va rugam selectati randul: ";
				cin >> i;
				cout << "Please selectati coloana";
				cin >> j;

				if (map[i][j] == '1')
				{
					cout << "Ne pare rau locul este deja ocupat!";
					cout << endl;
				}
				else
				{
					cout << "Locul dumneavoastra a fost rezervat" << endl;
					map[i][j] = ocupat;
					show_Chart();
					cout << "Doriti sa rezervati un alt loc ? ?(1 = YES / 2 = NO)";
					cin >> Quit;
				}

			} while (Quit == 1);

			break;

		case 2:
			cout << "Verifica Locuri Cinematograf\n\n";
			show_Chart();
			break;
		default: cout << "Error input\n";
		}

	} while (choice != 3);

}




int Loc::show_Menu()
{
	int menuChoice;
	cout << endl << endl;
	cout << " 1. Rezerva Loc\n";
	cout << " 2. Verfica Loc\n";
	cout << "_______\n\n";
	cout << "Introdu : ";
	cin >> menuChoice;
	cout << endl << endl;
	return menuChoice;
}

void Loc::show_Chart()
{
	for (int i = 0; i < 9; i++)
	{
		cout << endl << "Randul  " << (i + 1);
		for (int j = 0; j < 9; j++)
		{
			cout << " " << map[i][j];
		}
	}
	cout << endl;
}
