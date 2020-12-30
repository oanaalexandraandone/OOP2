#pragma once
#define BILET_H
#include "User.h"
#include "Film.h"
include "Loc.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
enum Status { Invalid = 0, Confirmat = 1, Neconfirmat = 2};

class Bilet : public Film
{
private:
	static int idUnic;
	Client client;
	Film film;
	string numeFilm;
	int nrBilete = 0;
	float* pret = nullptr;
	Status status = Status::Neconfirmat;
	Loc loc{};
	const int idCurent = 0;

public:
	Bilet() : idCurent(++idUnic)
	{
		this->client = client;
		this->film = film;
		this->loc = loc;
		nrBilete = 0;
		pret = nullptr;
		status = Status::Neconfirmat;
	}
	
	Bilet(int nrBilete, float* pret, Film& film, Client& client, Loc& loc, Status status) : idCurent(++idUnic)
	{
		this->client = client;
		this->film = film;
		this->loc = loc;
		if (pret != nullptr && nrBilete > 0)
		{
			this->pret = new float[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				this->pret[i] = pret[i];
			}
			this->nrBilete = nrBilete;
		}
		else
		{
			this->pret = nullptr;
			this->nrBilete = 0;
		}
		this->status = status;
	}

	Bilet(const Bilet& b) : idCurent(++idUnic)
	{
		client = b.client;
		film = b.film;
		loc = b.loc;
		if (b.pret != nullptr && b.nrBilete > 0)
		{
			pret = new float[b.nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				pret[i] = b.pret[i];
			}
			nrBilete = b.nrBilete;
		}
		else
		{
			pret = nullptr;
			nrBilete = 0;
		}
		status = b.status;
	}

	~Bilet()
	{
		if (pret != nullptr)
		{
			delete[] pret;
		}
	}

	Bilet& operator=(const Bilet& b)
	{
		client = b.client;
		film = b.film;
		loc = b.loc;
		if (pret != nullptr)
		{
			delete[] pret;
		}
		if (b.pret != nullptr && b.nrBilete > 0)
		{
			nrBilete = b.nrBilete;
			pret = new float[nrBilete];
			for (int i = 0; i < b.nrBilete; i++)
			{
				pret[i] = b.pret[i];
			}
		}
		else
		{
			pret = nullptr;
			nrBilete = 0;
		}
		status = b.status;
		return *this;
	}

	int getId()
	{
		return this->idCurent;
	}

	Client getClient()
	{
		return client;
	}
	
	Film getFilm()
	{
		return film;
	}

	Status getStatus()
	{
		return status;
	}

	int getNumar()
	{
		return nrBilete;
	}

	float* getPret()
	{
		if (this->nrBilete != 0)
		{
			int copie_nr = this->nrBilete;
		}
		else {
			this->nrBilete;
		}

		if (pret != nullptr)
		{
			float* copie = new float[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				copie[i] = pret[i];
			}

			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	void setPret(float* pret, int nrBilete)
	{
		if (pret != nullptr && nrBilete > 0)
		{
			this->nrBilete = nrBilete;
			this->pret = new float[nrBilete];
			for (int i = 0; i < nrBilete; i++)
			{
				this->pret[i] = pret[i];
			}
		}
		else
		{
			this->pret = nullptr;
			this->nrBilete = 0;
		}
	}

	float pretTotal()
	{
		float suma = 0;
		if (nrBilete > 0 && pret != nullptr)
		{
			for (int i = 0; i < nrBilete; i++)
			{
				suma += pret[i];
			}
		}
		return suma;
	}

	Bilet operator+(int nrBilete)
	{
		if (nrBilete < 0)
		{
			throw 500;
		}
		Bilet copie = *this;
		copie.nrBilete += nrBilete;
		return copie;
	}

	float& operator[](int index) throw (exception)
	{
		if (index >= 0 && index < nrBilete && pret != nullptr)
		{
			return pret[index];
		}
		else
		{
			throw exception("index invalid!");
		}
	}

	Bilet operator++()
	{
		this->nrBilete++;
		return *this;
	}

	explicit operator Loc()
	{
		return loc;
	}

	bool operator!()
	{
		return nrBilete > 0;
	}

	bool operator == (Bilet& b) {
		return (this->idUnic == b.idUnic);
	}

	friend bool operator<(const Bilet& l, const Bilet& r)
	{
		return (l.nrBilete,  l.pret) < (r.nrBilete, r.pret);
	}

	friend ostream& operator<<(ostream&, Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	friend ofstream& operator << (ofstream&, Bilet&);
	friend ifstream& operator>>(ifstream&, Bilet&);

};

int Bilet::idUnic = 0;

ostream& operator<<(ostream& out, Bilet & b)
{
	out << "ID unic: " << b.idUnic << endl;
	out << "Client: " << b.client;
	out<< "Film: " << b.film;
	out << "Loc: " << b.loc;
	out << "Nr. bilete: " << b.nrBilete << endl;
	if (b.pret != nullptr)
	{
		cout << "Pret per bilet: ";
		for (int i = 0; i < b.nrBilete; i++)
		{
			out << b.pret[i] << " ";
		}
		out << endl;
	}
	out << "Status: " << b.status << endl;
	out << "Pret total: " << b.pretTotal();
	return out;
}

istream& operator>>(istream & in, Bilet & b)
{
	cout << "ID unic: ";
	in >> b.idUnic;
	in >> b.client;
	in >> b.film;
	in >> b.loc;
	if (b.pret != nullptr)
	{
		delete[] b.pret;
	}
	cout << "Nr. bilete: ";
	in >> b.nrBilete;
	if (b.nrBilete > 0)
	{
		b.pret = new float[b.nrBilete];
		for (int i = 0; i < b.nrBilete; i++)
		{
			cout << "Pret per bilet: ";
			in >> b.pret[i];
		}
	}
	else
	{
		b.nrBilete = 0;
		b.pret = nullptr;
	}
	cout << endl << "Status: ";
	int status;
	in >> status;
	switch (status) {
	case 0:
		b.status = Status::Invalid;
		break;
	case 1:
		b.status = Status::Confirmat;
		break;
	default:
		b.status = Status::Neconfirmat;
	}
	return in;
}

ofstream& operator << (ofstream& of, Bilet& b)
{
	if (of.is_open())
	{
		of << "ID unic: " << b.idUnic << endl;
		of << "Client: " << b.client;
		//out << "Film: " <<  b.film;
		of << "Loc: " << b.loc;
		of << "Nr. bilete: " << b.nrBilete << endl;
		if (b.pret != nullptr)
		{
			cout << "Pret per bilet: ";
			for (int i = 0; i < b.nrBilete; i++)
			{
				of << b.pret[i] << " ";
			}
			of << endl;
		}
		of << "Status: " << b.status << endl;
		of << "Pret total: " << b.pretTotal();

		return of;
	}
}

ifstream& operator>>(ifstream& is, Bilet& b)
{
	cout << "ID unic: ";
	is >> b.idUnic;
	cout << "Client: ";
	is >> b.client;
	cout << "Film: ";
	is >> b.film;
	cout << "Loc: ";
	is >> b.loc;
	if (b.pret != nullptr)
	{
		delete[] b.pret;
	}
	cout << "Nr. bilete: ";
	is >> b.nrBilete;
	if (b.nrBilete > 0)
	{
		b.pret = new float[b.nrBilete];
		for (int i = 0; i < b.nrBilete; i++)
		{
			cout << "Pret per bilet: ";
			is >> b.pret[i];
		}
	}
	else
	{
		b.nrBilete = 0;
		b.pret = nullptr;
	}
	return is;
}
