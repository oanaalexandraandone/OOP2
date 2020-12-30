#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define USER_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class User
{

protected:
	char* nume = nullptr;
	enum  class Rol { client, admin };

public:

	bool deleteEntity() {
		if (this != NULL) {
			delete[] this;
		}
	}
	virtual void afiseaza() = 0;

	void setName(char* n) {
		if (n != nullptr) {
			this->nume = n;
		}
		else {
			cout << "Numele introdus este invalid" << endl;
		}
	}

	friend ostream& operator<< (ostream& os, const Rol& obj)
	{
		os << static_cast<std::underlying_type<Rol>::type>(obj);
		return os;
	}


};

class Admin : public User {
private:
	User::Rol rol;
	static int id1;
	const int currentID = 0;

public:
	Admin() : currentID(++id1) {
		rol = Rol::admin;
		nume = (char*)"Anonim";
	}

	int getId() {
		return this->currentID;
	}

	Rol getRol() {
		return this->rol;
	}

	char* getName() {
		return this->nume;
	}

	void afiseaza() override {
		cout << "ID: " << getId() << endl;
		cout << "ROL: " << getRol() << endl;
		cout << "NUME: " << getName() << endl;
	}
};

int Admin::id1 = 0;

class Client : public User {
protected:
	string nrTel;
	string email;
	double venitDisponibil;
	const int currentID;
	Rol rol;
public:
	static int id;

	Client() :currentID(id++) {
		nume = (char*)"Anonim";
		nrTel = " ";
		email = " ";
		venitDisponibil = 0;
		rol = Rol::client;
	}

	Client(char* name, string tel, string mail, double venit) :currentID(id++) {
		rol = Rol::client;
		this->nume = new char[strlen(name) + 1];
		strcpy_s(this->nume, strlen(name) + 1, name);
		this->nrTel = tel;
		this->email = mail;
		if (venit > 0) {
			this->venitDisponibil = venit;
		}
		else {
			this->venitDisponibil = 0;
		}
	}

	Client(const Client& c) :currentID(c.id) {
		this->nume = c.nume;
		this->nrTel = c.nrTel;
		this->email = c.email;
		this->venitDisponibil = c.venitDisponibil;
		this->rol = c.rol;
	}


	~Client() {
		if (nume != nullptr) {
			delete nume;
		}

	}

	Client operator=(Client c) {
		if (nume != nullptr) {
			delete nume;
		}
		nume = c.nume;
		nrTel = c.nrTel;
		email = c.email;
		venitDisponibil = c.venitDisponibil;
		rol = c.rol;
	}

	friend ifstream& operator >> (ifstream& in, Client& c) {
		char aux[50];
		cout << "Nume:" << endl;
		in >> aux;
		delete[] c.nume;
		c.nume = new char[strlen(aux) + 1];
		strcpy_s(c.nume, strlen(aux) + 1, aux);
		cout << "Numar de telefon: " << endl;
		in >> c.nrTel;
		cout << "Email: " << endl;
		in >> c.email;
		cout << "Venit disponibil: " << endl;
		in >> c.venitDisponibil;
		return in;
	}
	friend ostream& operator << (ostream& out, Client& c) {
		if (c.getId() != 0) {
			c.afiseaza();
		}
		return out;
	}

	Client operator ++() {
		venitDisponibil += 50;
		return *this;
	}

	Client operator --() {

		if (this->venitDisponibil > 10) {
			this->venitDisponibil = venitDisponibil - 10;
		}
		return *this;
	}

	Client operator+(double c) {
		Client copie = *this;
		copie.venitDisponibil = venitDisponibil + c;
		return copie;
	}

	operator double() {
		return this->venitDisponibil;
	}

	bool operator> (Client& c) {
		double venitCurrent = this->venitDisponibil;
		double venitC = c.venitDisponibil;
		return venitCurrent > venitC;
	}

	bool operator == (Client& c) {
		return (this->id == c.id);
	}


	void afiseaza() override {
		cout << "ID: " << this->currentID << endl;
		cout << "ROL: " << this->getRol() << endl;
		cout << "NUME: " << this->nume << endl;
		cout << "NUMAR DE TELEFON: " << this->nrTel << endl;
		cout << "EMAIL: " << this->email << endl;
		cout << "VENIT DISPONIBIL: " << this->venitDisponibil << endl;

	}

	void setNrTel(string tel) {
		if (tel != " ") {
			this->nrTel = tel;
		}
		else {
			cout << "Numarul de telefon este invalid" << endl;
		}
	}

	string getNrTel() {
		return this->nrTel;
	}
	void setEmail(string mail) {
		if (mail != " ") {
			this->email = mail;
		}
		else {
			cout << "Email invalid" << endl;
		}
	}

	string getEmail() {
		return this->email;
	}

	void setVenitDisponibil(double venit) {
		if (venit > 0) {
			this->venitDisponibil = venit;
		}
		else {
			cout << "Venitul nu poate fi negativ" << endl;
		}
	}

	double getVenitDisponibil() {
		return this->venitDisponibil;
	}

	int getId() {
		return this->currentID;
	}

	Rol getRol() {

		return this->rol;
	}

};

int Client::id = 0;

