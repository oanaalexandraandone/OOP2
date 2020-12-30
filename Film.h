#pragma once
#define FILM_H
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

enum TipFilm { Full = 300, Partial = 200, Empty = 100 };
class Film {
private:
	char* nume = nullptr;
	string descriere = "";
	//ora & data
	char data[20];
	TipFilm tip = TipFilm::Empty;

public:
	

	//constructor implicit
	Film() {
		this->nume = new char[strlen("Film nedefinit") + 1];
		strcpy_s(this->nume, strlen("Film nedefinit") + 1, "Film nedefinit");
		descriere = "";
		strcpy_s(data, strlen("01/01/2021 00:00") + 1, "01 / 01 / 2021 00:00");
		tip = TipFilm::Empty;
	}
	//constructor parametrii
	Film(char* nume, string descriere, char data[17], TipFilm tip) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->descriere = descriere;
		this->tip = tip;
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	//destructor
	~Film()
	{
		if (nume != nullptr)
			delete[] nume;
	}
	//operator copiere
	Film(const Film& f)
	{
		if (f.nume != nullptr)
		{
			this->nume = new char[strlen(f.nume) + 1];
			strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		this->descriere = f.descriere;
		strcpy_s(this->data, strlen(f.data) + 1, f.data);
	}



	Film& operator=(Film f)
	{
		if (nume != nullptr)
		{
			delete[] nume;
		}
		if (f.nume != nullptr)
		{
			this->nume = new char[strlen(f.nume) + 1];
			strcpy_s(this->nume, strlen(f.nume) + 1, f.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		this->descriere = f.descriere;
		strcpy_s(this->data, strlen(f.data) + 1, f.data);

		return *this;
	}
	//getter&setter
	void setNume(char* nume) {
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	char* getNume() {
		return nume;
	}

	string getDescriere() {
		return this->descriere;
	}

	void setdata(char data_noua[17]) {
		if (strlen(data_noua) < 2)
			cout << ("Intorduceti o data valida");
		else
		{
			strcpy_s(this->data, strlen(data) + 1, data);
		}
	}
	char getdata()
	{
		return strcpy_s(data, strlen(data) + 1, data);
	}
	//operatori?
	friend ostream& operator << (ostream& out, Film f) {
		out << "Nume film: " << f.nume << endl;
		out << "Descriere film: " << f.descriere << endl;
		out << "Data: " << f.data << endl;
		out << endl << "Tip: " << f.tip;
		out << endl;

		return out;
	}

	friend ofstream& operator << (ofstream& out, Film f) {
		out << f.nume << " ";
		out << f.descriere << " ";
		out << f.data << " ";
		out << endl;

		return out;
	}

	friend istream& operator >> (istream& in, Film& f) {
		char aux[50];
		cout << "Nume film: ";
		in >> aux;
		delete[] f.nume;
		f.nume = new char[strlen(aux) + 1];
		strcpy_s(f.nume, strlen(aux) + 1, aux);
		cout << "Descriere film: ";
		in >> f.descriere;
		cout << "Data: ";
		in >> f.data;
		cout << endl << "Tip: ";
		int tip;
		in >> tip;
		switch (tip) {
		case 100:
			f.tip = TipFilm::Empty;
			break;
		case 200:
			f.tip = TipFilm::Partial;
			break;
		case 300:
			f.tip = TipFilm::Full;
			break;
		default:
			f.tip = TipFilm::Empty;
		}
		cout << endl;

		return in;
	}

	friend ifstream& operator >> (ifstream& in, Film& f) {
		char aux[50];
		in >> aux;
		delete[] f.nume;
		f.nume = new char[strlen(aux) + 1];
		strcpy_s(f.nume, strlen(aux) + 1, aux);
		in >> f.descriere;
		in >> aux;
		strcat(aux, " ");
		strcpy_s(f.data, strlen(aux) + 1, aux);
		return in;
	}

};


