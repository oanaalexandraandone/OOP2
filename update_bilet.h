#pragma once
#define BILET_H
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

enum Status { Invalid = 0, Confirmat = 1, Neconfirmat = 2 };

class Bilet
{
private:
	static int idUnic;
	string numeClient;
	string numeFilm;
	int nrBilete = 0;
	float* pret = nullptr;
	Status status = Status::Neconfirmat;
	string sala;
	int rand;
	int loc;
	const int idCurent = 0;

public:
	Bilet() : idCurent(++idUnic)
	{
		this->numeClient = numeClient;
		this->numeFilm = numeFilm;
		this->rand = rand;
		this->loc = loc;
		nrBilete = 0;
		pret = nullptr;
		status = Status::Neconfirmat;
		this->sala = sala;
	}

	Bilet(int nrBilete, float* pret, string numeFilm, string numeClient, int rand, int loc, string sala, Status status) : idCurent(++idUnic)
	{
		this->numeClient = numeClient;
		this->numeFilm = numeFilm;
		this->rand = rand;
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
		this->sala = sala;
	}

	Bilet(string numeFilm, int rand, int loc, string sala) : idCurent(++idUnic)
	{
		this->numeFilm = numeFilm;
		this->rand = rand;
		this->loc = loc;
		this->sala = sala;
	}

	Bilet(const Bilet& b) : idCurent(++idUnic)
	{
		numeClient = b.numeClient;
		numeFilm = b.numeFilm;
		rand = b.rand;
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
		sala = b.sala;
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
		numeClient = b.numeClient;
		numeFilm = b.numeFilm;
		rand = b.rand;
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
		sala = b.sala;
		return *this;
	}

	int getId()
	{
		return this->idCurent;
	}

	string getClient()
	{
		return numeClient;
	}

	string getFilm()
	{
		return numeFilm;
	}

	void setFilm (string numeFilm)
	{
		if (numeFilm != " ")
		{
			this->numeFilm = numeFilm;
		}
		else
		{
			cout << "Film inexistent!" << endl;
		}
	}

	void setSala(string sala)
	{
		if (sala != " ")
		{
			this->sala = sala;
		}
		else
		{
			cout << "Sala inexistenta!" << endl;
		}
	}

	void setRand(int rand) {
		if (rand > 0) {
			this->rand = rand;
		}
		else {
			cout << "Rand inexistent" << endl;
		}
	}

	void setLoc(int loc) {
		if (loc > 0) {
			this->loc = loc;
		}
		else {
			cout << "Loc inexistent" << endl;
		}
	}

	Status getStatus()
	{
		return status;
	}

	int getNumar()
	{
		return nrBilete;
	}
	
	string getSala()
	{
		return sala;
	}
	
	float* getPret()
	{
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

	int getIdUnic()
	{
		return idUnic;
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
	explicit operator float* () const
	{
		return nullptr;
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
		return (l.nrBilete, l.pret) < (r.nrBilete, r.pret);
	}

	void serializare()
	{
		ofstream f("bilet.bin", ios::binary);
		for (int i = 0; i < nrBilete; i++)
		{
			f.write((char*)&pret[i], sizeof(pret[i]));
		}
		f.close();
	}

	void deserializare()
	{
		ifstream f("bilet.bin", ios::binary);
		f.read((char*)&nrBilete, sizeof(nrBilete));
		delete[] pret;
		pret = new float[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			f.read((char*)&pret[i], sizeof(pret[i]));
		}
		f.close();
	}

	void afisare()
	{
		cout << "ID: " << idUnic << endl;
		cout << "Film: " << numeFilm << endl;
		cout << "Rand: " << rand << endl;
		cout << "Loc: " << loc << endl;
		cout << "Sala: " << sala << endl;
	}

	Bilet updateBilet() {
		int choice = 0;
		cout << "Ce atribut doriti sa actualizati?" << endl;
		cout << "1 - film // 2- rand si loc // 3 - sala // 9 - inchide meniu" << endl;
		cout << "Optiune: " << endl;


		do {
			cin >> choice;

			switch (choice) {
			case 1: {

				string newFilm = " ";
				cout << "Introduceti noul film: " << endl;
				cin >> newFilm;
				if (newFilm != " ") {
					this->setFilm(newFilm);
				}
				this->afisare();
			}break;
			case 2: {
				int newRand = 0;
				int newLoc = 0;
				cout << "Introduceti noul rand: " << endl;
				cin >> newRand;
				cout << "Introduceti noul loc: " << endl;
				cin >> newLoc;
				this->setRand(newRand);
				this->setLoc(newLoc);
				this->afisare();
			}break;
			case 3: {
				string newSala = " ";
				cout << "Introduceti noua sala: " << endl;
				cin >> newSala;
				if (newSala != " ") {
					this->setSala(newSala);
				}
				this->afisare();
				} break;
			
			case 9:
				cout << "La revedere!" << endl;
				break;

			default:
				cout << "Optiune invalida!" << endl;
				break;
			}
		} while (choice != 9);
		return *this;
	}

	static Bilet updateBilet(int id, vector<Bilet> vector) {
		int choice = 0;
		Bilet temp;
		for (int i = 0; i < vector.size(); i++) {
			if (vector[i].getId() == id)
			{
				temp = vector[i];
				break;
			}
		}
		cout << "Ce atribut doriti sa actualizati?" << endl;
		cout << "1 - film // 2- rand si loc // 3 - sala // 9 - inchide meniu" << endl;
		do {
			cout << "Optiune: " << endl;
			cin >> choice;

			switch (choice) {
			case 1: {

				string newFilm = " ";
				cout << "Introduceti noul film: " << endl;
				cin >> newFilm;
				if (newFilm != " ") {
					temp.setFilm(newFilm);
				}
				temp.afisare();
			}break;
			case 2: {
				int newRand = 0;
				int newLoc = 0;
				cout << "Introduceti noul rand: " << endl;
				cin >> newRand;
				cout << "Introduceti noul loc: " << endl;
				cin >> newLoc;
				temp.setRand(newRand);
				temp.setLoc(newLoc);
				temp.afisare();
			}break;
			case 3: {
				string newSala = " ";
				cout << "Introduceti noua sala: " << endl;
				cin >> newSala;
				if (newSala != " ") {
					temp.setSala(newSala);
				}
				temp.afisare();
			} break;
			
			case 9:
				cout << "La revedere!" << endl;
				break;

			default:
				cout << "Optiune invalida!" << endl;
				break;
			}
		} while (choice != 9);
		return temp;
	}

	//write a single object into the binary file
	static void saveInFile(const Bilet& b, const char* fileName) {
		fstream file;
		file.open(fileName, ios::out | ios::binary);
		if (!file) {
			cout << "Eroare!" << endl;;
		}
		file.write((char*)&b, sizeof(b));
		file.close();
	}

	//write an array of objects into the binary file
	static void saveInFile(vector<Bilet>& b) {
		fstream file;
		file.open("bilete.bin", ios::out | ios::binary);
		if (!file) {
			cout << "Eroare" << endl;;
		}
		for (int i = 0; i < b.size(); i++) {
			file.write((char*)&b[i], sizeof(Bilet));
		}
		file.close();
		cout << "Date scrise cu succes!" << endl;
	}

	//read an array of objects into the binary file
	static void readFromFile() {
		Bilet temp;
		vector<Bilet> vector;
		ifstream ifs("bilete.bin", ios::binary);
		if (!ifs) {
			cout << "Eroare!" << endl;
		}
		while (ifs.read((char*)&temp, sizeof(temp))) {
			vector.push_back(Bilet(temp));
			cout << endl << endl;
			cout << "Date extrase!" << endl;
			cout << temp;
			temp.afisare();
		}
		ifs.close();
	}

	//read a single object from a binary file
	static void readFromFile(const char* fileName) {
		ifstream b;
		b.open(fileName);
		Bilet bilet;
		if (b.read((char*)&bilet, sizeof(bilet))) {
			cout << endl;
			cout << "Date extrase!" << endl;
			//print the object
			cout << bilet;
		}
		else {
			cout << "Eroare!" << endl;
		}
		b.close();
	}

	static void deleteFromFile(int idUnic) {
		cout << "START OF DELETE \n";
		Bilet biletTemp;
		vector<Bilet> vector;
		ifstream ifs("bilete.bin", ios::out | ios::binary);
		ofstream fout("temp.bin", ios::out | ios::binary);
		if (!ifs) {
			cout << "Error in opening file...\n";
		}
		while (ifs.read((char*)&biletTemp, sizeof(biletTemp))) {
			vector.push_back(Bilet(biletTemp));
			cout << endl << endl;
			for (int i = 0; i < vector.size(); i++) {
				if (vector[i].idUnic != idUnic) {
					fout.write((char*)&vector[i], sizeof(Bilet));
				}
			}

		}
		fout.close();
		ifs.close();
		remove("bilete.bin");
		rename("temp.bin", "bilete.bin");

	}

	static Bilet createBilet() {
		Bilet b;
		cout << "ID:" << endl;
		cin >> b.idUnic;
		cout << "Film: " << endl;
		cin >> b.numeFilm;
		cout << "Rand: " << endl;
		cin >> b.rand;
		cout << "Loc: " << endl;
		cin >> b.loc;
		return b;

	}

	static void CRUDMenuBilet() {
		int choice;
		vector<Bilet> vector;
		do {
			cout << "Alegeti o optiune: 1 -> Create; 2-> Read ; 3-> Update; 4-> Delete ; 9-> EXIT \n";
			cin >> choice;
			switch (choice) {
			case 1: {
				cout << "Cate bilete doriti sa creati? \n";
				int number;
				Bilet temp;

				cin >> number;
				for (int i = 0; i < number; i++) {
					cout << endl;
					temp = createBilet();
					cout << "Biletul cu numarul " << i + 1 << "a fost creat \n";
					vector.push_back(temp);
				}
				saveInFile(vector);
				break;
			}

			case 2:
				readFromFile();
				break;
			case 3: {

				cout << "Introduceti ID-ul biletului pe care doriti sa il actualizati : \n";
				int id;
				cin >> id;
				updateBilet(id, vector);
				break;
			}
			case 4:
				int id;
				cout << "Introduceti ID-ul biletului pe care doriti sa il stergeti \n";
				cin >> id;
				deleteFromFile(id);
			case 9:
				break;
			default:
				cout << "Optiune invalida!" << endl;
				break;
			}

		} while (choice != 9);

	}

	friend ostream& operator<<(ostream&, Bilet&);
	friend istream& operator>>(istream&, Bilet&);
	friend ofstream& operator << (ofstream&, Bilet&);
	friend ifstream& operator>>(ifstream&, Bilet&);

};

int Bilet::idUnic = 0;

ostream& operator<<(ostream& out, Bilet& b)
{
	out << "ID unic: " << b.idUnic << endl;
	out << "Client: " << b.numeClient << endl;
	out << "Film: " << b.numeFilm << endl;
	out << "Rand: " << b.rand << endl;
	out << "Loc: " << b.loc << endl;
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
	out << "Sala: " << b.sala << endl;
	out << "Pret total: " << b.pretTotal() << endl;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "ID unic: ";
	in >> b.idUnic;
	in >> b.numeClient;
	in >> b.numeFilm;
	cout << "Rand:" << endl;
	in >> b.rand;
	cout << "Loc:" << endl;
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
	cout << "Sala:" << endl;
	in >> b.sala;
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
		of << "Client: " << b.numeClient << endl;
		of << "Film: " << b.numeFilm << endl;
		of << "Rand: " << b.rand << endl;
		of << "Loc: " << b.loc << endl;
		of << "Nr. bilete: " << b.nrBilete << endl;
		if (b.pret != nullptr)
		{
			cout << "Pret per bilet: ";
			for (int i = 0; i < b.nrBilete; i++)
			{
				cout << "Preturi: ";
				of << b.pret[i] << " ";
			}
			of << endl;
		}
		of << "Sala: " << b.sala << endl;
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
	is >> b.numeClient;
	cout << "Film: ";
	is >> b.numeFilm;
	cout << "Loc:" << endl;
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
	cout << "Sala:" << endl;
	is >> b.sala;
	return is;
}


int main()
{

}
