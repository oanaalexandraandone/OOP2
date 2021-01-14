#pragma once
#define FILM_H
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

enum TipFilm { Full = 0, Partial = 1, Empty = 2 };

class Film
{
protected:
    static int idUnicf;
    char* nume = nullptr;
    string gen = "";
    int* ore;//ore difuzare
    int nrOre;
    int anulLansarii;
    TipFilm tip = TipFilm::Empty;
    const int idCurentf = 0;
public:

    //constructor implicit
    Film() :idCurentf(++idUnicf)
    {
        this->nume = new char[strlen("Film nedefinit") + 1];
        strcpy_s(this->nume, strlen("Film nedefinit") + 1, "Film nedefinit");
        gen = "";
        anulLansarii = 0000;
        ore = nullptr;
        nrOre = 0;
        tip = TipFilm::Empty;
    }
    //constructor parametrii
    Film(char* nume, string gen, int anulLansarii, int* ore, int nrOre, TipFilm tip) :idCurentf(++idUnicf)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
        this->gen = gen;
        this->tip = tip;
        this->anulLansarii = anulLansarii;
        if (ore != nullptr && nrOre > 0)
        {
            this->ore = new int[nrOre];
            for (int i = 0; i < nrOre; i++)
            {
                this->ore[i] = ore[i];
            }
            this->nrOre = nrOre;
        }
        else
        {
            this->ore = nullptr;
            this->nrOre = 0;
        }
    }
    //destructor
    ~Film()
    {
        if (nume != nullptr)
        {
            delete[] this->nume;
        }
        if (ore != nullptr)
        {
            delete[] this->ore;
        }
    }
    //operator copiere
    Film(const Film& f) :idCurentf(++f.idUnicf)
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
        this->gen = f.gen;
        this->anulLansarii = f.anulLansarii;
        if (f.ore != nullptr && f.nrOre > 0)
        {
            nrOre = f.nrOre;
            ore = new int[f.nrOre];
            for (int i = 0; i < f.nrOre; i++)
            {
                ore[i] = f.ore[i];
            }
        }
        else
        {
            ore = nullptr;
            nrOre = 0;
        }
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
        this->gen = f.gen;
        this->anulLansarii = f.anulLansarii;
        if (f.ore != nullptr && f.nrOre > 0)
        {
            nrOre = f.nrOre;
            ore = new int[f.nrOre];
            for (int i = 0; i < f.nrOre; i++)
            {
                ore[i] = f.ore[i];
            }
        }
        else
        {
            ore = nullptr;
            nrOre = 0;
        }

        return *this;
    }
    //setter
    void setNume(char* nume)
    {
        delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);
    }

    void setanulLansarii(int noulAn)
    {
        if (noulAn < 1900)
            cout << ("Intorduceti o valoare valida");
        if (noulAn > 1900 && noulAn < 2021)
        {
            this->anulLansarii = noulAn;
        }
    }
    void setOre(int* ore, int nrOre)
    {
        if (this->ore != nullptr)
        {
            delete[] this->ore;
        }
        if (ore != nullptr && nrOre > 0)
        {
            this->nrOre = nrOre;
            this->ore = new int[nrOre];
            for (int i = 0; i < nrOre; i++)
            {
                this->ore[i] = ore[i];
            }
        }
        else
        {
            this->ore = nullptr;
            this->nrOre = 0;
        }
    }

    void setGen(string gen)
    {
        if (gen != " ")
        {
            this->gen = gen;
        }
        else
        {
            cout << "Gen film invalid" << endl;
        }
    }
    //getter
    char* getNume()
    {
        return nume;
    }
    string getGen()
    {
        return this->gen;
    }

    int getanulLansarii()
    {
        return anulLansarii;
    }

    int* getOre()
    {
        if (ore != nullptr)
        {
            int* copie = new int[nrOre];
            for (int i = 0; i < nrOre; i++)
            {
                copie[i] = ore[i];
            }
            return copie;
        }
        else
        {
            return nullptr;
        }
    }

    int getNrOre()
    {
        return nrOre;
    }
    TipFilm getTipFilm()
    {
        return tip;
    }
    int getidUnicf()
    {
        return this->idUnicf;
    }
    bool operator!()
    {
        return nrOre > 0;
    }
    Film operator++()
    {
        this->anulLansarii++;
        return *this;
    }

    Film operator++(int i)
    {
        Film copie = *this;
        this->anulLansarii++;
        return copie;
    }

    Film operator+(int nrAni)
    {
        Film copie = *this;
        copie.anulLansarii += nrAni;
        return copie;
    }

    //int& operator[](int index) throw (exception)
    //{
    //	if (index >= 0 && index < nrOre && ore != nullptr)
    //	{
    //		return ore[index];
    //	}
    //	else
    //	{
    //		throw exception("index");
    //	}
    //}

    explicit operator int()
    {
        return anulLansarii;
    }


    friend Film operator+(int, Film);
    friend ostream& operator<<(ostream&, Film);
    friend istream& operator>>(istream&, Film&);
    friend ofstream& operator << (ofstream&, Film);
    friend ifstream& operator>>(ifstream&, Film&);


    static Film createFilm()
    {
        Film f;
        cout << "Id unic Film: " << f.getidUnicf() << endl;
        cout << "Nume:" << endl;
        cin >> f.nume;
        ///cout << "Tip acoperire sala:Full = 0, Partial = 1, Empty = 2: " << endl;
        // cin >> f.tip;
        cout << "Gen film: " << endl;
        cin >> f.gen;
        cout << "Anul lansarii film: " << endl;
        cin >> f.anulLansarii;
        cout << "Numar ore difuzare: " << endl;
        cin >> f.nrOre;
        //cout << "Ore difuzare: " <<endl;
        // cin >> f.ore;
        return f;
    }
    void afiseazaFilm()
    {
        cout << "Id unic Film: " << this->getidUnicf() << endl;
        cout << "Nume film: " << this->getNume() << endl;
        cout << "Tip acoperire sala:Full = 0, Partial = 1, Empty = 2: " << this->getTipFilm() << endl;
        cout << "Gen film: " << this->getGen() << endl;
        cout << "Anul lansarii film: " << this->getanulLansarii() << endl;
        cout << "Numar ore difuzare: " << this->getNrOre() << endl;
        cout << "Ore difuzare: " << this->getOre() << endl;

    }

    Film updateFilm()
    {
        int choice = 0;
        cout << "Ce atribut doriti sa actualizati?" << endl;
        cout << "1 nume || 2 gen || 3 an lansare || 4 ore || 9 inchide meniu" << endl;
        cout << "Optiune: " << endl;

        do
        {
            cin >> choice;

            switch (choice)
            {
            case 1:
            {

                char* newName = nullptr;
                cout << "Introduceti noul nume: " << endl;
                cin >> newName;
                if (newName != nullptr)
                {
                    this->setNume(newName);
                }
                this->afiseazaFilm();
            }
            break;
            case 2:
            {
                string newGen = " ";
                cout << "Introduceti noul gen: " << endl;
                cin >> newGen;
                this->setGen(newGen);
                this->afiseazaFilm();
            }
            break;
            case 3:
            {
                int newAn = 0000;
                cout << "Introduceti noul an de lansare: " << endl;
                cin >> newAn;
                this->setanulLansarii(newAn);
                this->afiseazaFilm();
            }
            break;
            //case 4: {
            //    int* newOre = nullptr, int NewNrOre=0;
            //   cout << "Introduceti noile ore: " << endl;
            //   cin >> newOre;
            //   this->setOre(newOre,NewNrOre);
            //   this->afiseazaFilm();
            // }break;

            case 9:
                cout << "La revedere!" << endl;
                break;

            default:
                cout << "Selectie invalida" << endl;
                break;
            }
        } while (choice != 9);
        return *this;
    }


};

Film operator+(int nrAni, Film f)
{
    f.anulLansarii += nrAni;
    return f;
}

ostream& operator<<(ostream& out, Film f)
{
    if (f.getidUnicf() != 0)
    {
        out << "Id unic film: " << f.idUnicf << endl;
        out << "Nume film: " << f.nume << endl;
        out << "Gen film: " << f.gen << endl;
        out << "Anul Lansarii: " << f.anulLansarii << endl;
        out << "Tip acoperire sala:Full = 0, Partial = 1, Empty = 2: " << f.tip;
        out << "Numar ore difuzare: " << f.nrOre << endl;
        out << "Ore difuzare: ";
        if (f.ore != nullptr)
        {
            for (int i = 0; i < f.nrOre; i++)
            {
                out << f.ore[i] << " ";
            }
        }
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, Film& f)
{
    cout << "Nume film: ";
    delete[] f.nume;
    char buffer[100];
    in.getline(buffer, 99);
    f.nume = new char[strlen(buffer) + 1];
    strcpy_s(f.nume, strlen(buffer) + 1, buffer);
    cout << "Gen film: ";
    in >> f.gen;
    cout << "Anul lansarii: ";
    in >> f.anulLansarii;
    if (f.ore != nullptr)
    {
        delete[] f.ore;
    }
    cout << "Numar ore difuzare: ";
    cin >> f.nrOre;
    if (f.nrOre > 0)
    {
        f.ore = new int[f.nrOre];
        for (int i = 0; i < f.nrOre; i++)
        {
            cout << "ora[" << i << "] = ";
            in >> f.ore[i];
        }
    }
    else
    {
        f.nrOre = 0;
        f.ore = nullptr;
    }
    cout << "Tip acoperire sala:Full = 0, Partial = 1, Empty = 2: ";
    int tip;
    in >> tip;
    switch (tip)
    {
    case 0:
        f.tip = TipFilm::Empty;
        break;
    case 1:
        f.tip = TipFilm::Partial;
        break;
    case 2:
        f.tip = TipFilm::Full;
        break;
    default:
        f.tip = TipFilm::Empty;
    }
    cout << endl;
    return in;
}

ofstream& operator<<(ofstream& out, Film f)
{
    if (out.is_open())
    {
        out << f.nume << endl;
        out << f.gen << endl;
        out << f.anulLansarii << endl;
        out << f.tip;
        out << f.nrOre << endl;
        if (f.ore != nullptr)
        {
            for (int i = 0; i < f.nrOre; i++)
            {
                out << f.ore[i] << " ";
            }
        }
    }

    return out;
}

ifstream& operator>>(ifstream& in, Film& f)
{
    cout << "Nume film: ";
    delete[] f.nume;
    char buffer[100];
    in.getline(buffer, 99);
    f.nume = new char[strlen(buffer) + 1];
    in >> f.anulLansarii;
    cout << "Gen film: ";
    in >> f.gen;
    cout << "Anul lansarii: ";
    in >> f.anulLansarii;
    cout << endl << "Tip acoperire sala:Full = 0, Partial = 1, Empty = 2: ";
    int tip;
    in >> tip;
    switch (tip)
    {
    case 0:
        f.tip = TipFilm::Empty;
        break;
    case 1:
        f.tip = TipFilm::Partial;
        break;
    case 2:
        f.tip = TipFilm::Full;
        break;
    default:
        f.tip = TipFilm::Empty;
    }
    cout << endl;

    return in;
}
int Film::idUnicf = 0;


// CREATE scriere 1 obiect din fisier odiect
static void scriereFilmFisier(const Film& f, const char* fisierFilme)
{
    fstream file;
    file.open(fisierFilme, ios::out | ios::binary);
    if (!file)
    {
        cout << "Eroare la creare fisier.\n";
    }
    file.write((char*)&f, sizeof(f));
    file.close();
}

//creare vector obiecte fisier binar
static void scriereFilmFisier(vector<Film>& f)
{
    fstream file;
    file.open("filme.dat", ios::out | ios::binary);
    if (!file)
    {
        cout << "Eroare la creare fisier.\n";
    }
    for (size_t i = 0, ilen = f.size(); i < ilen; ++i)
    {
        file.write((char*)&f[i], sizeof(Film));
    }
    file.close();
    cout << "Datele au fost scrise in fisier.\n";
}

//READ citire 1 obiect din fisier binar
static void citireFilmFisier(const char* fisierFilme)
{
    ifstream file;
    file.open(fisierFilme);
    Film film;
    if (file.read((char*)&film, sizeof(film)))
    {
        cout << endl << endl;
        cout << "Datele au fost citite din fisier.\n";
        //print the object
        cout << film;
    }
    else
    {
        cout << "Eroare la citirea datelor din fisier.\n";
    }
    file.close();
}
//citire vector obiecte fisier binar
static void citireFilmFisier()
{
    Film temp;
    vector<Film> vector;
    ifstream ifs("filme.dat", ios::binary);
    if (!ifs)
    {
        cout << "Eroare la creare fisier.\n";
    }
    while (ifs.read((char*)&temp, sizeof(temp)))
    {
        vector.push_back(Film(temp));
        cout << endl << endl;
        cout << "Datele au fost extrase. \n";
        cout << temp;
        temp.afiseazaFilm();
    }
    ifs.close();
}
//UPDATE

//DELETE stergere 1 obiect din fisier binar
static void stergereFilmFisier(int id)
{
    cout << "Se incepe stergerea \n";
    Film filmTemp;
    vector<Film> vector;
    ifstream f1("filme.dat", ios::out | ios::binary);
    ofstream f2("temp.dat", ios::out | ios::binary);
    if (!f1)
    {
        cout << "Eroare la deschidere fisier\n";
    }
    while (f1.read((char*)&filmTemp, sizeof(filmTemp)))
    {
        vector.push_back(Film(filmTemp));
        cout << endl << endl;
        for (size_t i = 0, ilen = vector.size(); i < ilen; ++i)
        {
            if (vector[i].getidUnicf() != id)
            {
                f2.write((char*)&vector[i], sizeof(Film));
            }
        }

    }
    f2.close();
    f1.close();
    remove("filme.dat");
    rename("temp.dat", "filme.dat");

}

static void updateFilm(int id, vector<Film> vector)
{
    int choice = 0;
    Film temp;
    for (size_t i = 0, ilen = vector.size(); i < ilen; ++i)
    {
        if (vector[i].getidUnicf() == id)
        {
            temp = vector[i];
            break;
        }
    }
    cout << "Ce atribut doriti sa actualizati?" << endl;
    cout << "1 nume || 2 gen || 3 an lansare || 4 ore || 9 inchide meniu" << endl;

    do
    {
        cout << "Optiune: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            char* newName = nullptr;
            cout << "Introduceti noul nume: " << endl;
            cin >> newName;
            if (newName != nullptr)
            {
                temp.setNume(newName);
            }
            temp.afiseazaFilm();
        }
        break;
        case 2:
        {
            string newGen = " ";
            cout << "Introduceti noul gen: " << endl;
            cin >> newGen;
            temp.setGen(newGen);
            temp.afiseazaFilm();
        }
        break;
        case 3:
        {
            int newAn = 0000;
            cout << "Introduceti noul an de lansare: " << endl;
            cin >> newAn;
            temp.setanulLansarii(newAn);
            temp.afiseazaFilm();
        }
        break;
        case 4:
        {
            //    int* newOre = nullptr, int NewNrOre=0;
            //   cout << "Introduceti noile ore: " << endl;
            //   cin >> newOre;
            //   this->setOre(newOre,NewNrOre);
            //   this->afiseazaFilm();
            // }break;
        } break;

        case 9:
            cout << "La revedere!" << endl;
            break;

        default:
            cout << "Selectie invalida" << endl;
            break;
        }
    } while (choice != 9);
    //return temp;
}

static void CRUDMenuFilm()
{
    int choice;
    vector<Film> vector;
    do
    {
        cout << "Alegeti o optiune: 1 -> Create; 2-> Read ; 3-> Update; 4-> Delete ; 9-> EXIT \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Cate filme doriti sa creati? \n";
            int number;
            Film temp;

            cin >> number;
            for (int i = 0; i < number; i++)
            {
                cout << endl;
                temp = Film::createFilm();
                cout << "Filmul cu numarul " << i + 1 << " a fost creat \n";
                vector.push_back(temp);
            }
            scriereFilmFisier(vector);
            break;
        }

        case 2:
            citireFilmFisier();
            break;
        case 3:
        {

            cout << "Introduceti ID-ul filmului pe care doriti sa il actualizati : \n";
            int id;
            cin >> id;
            updateFilm(id, vector);
            break;
        }
        case 4:
            int id;
            cout << "Introduceti ID-ul filmului pe care doriti sa il stergeti \n";
            cin >> id;
            stergereFilmFisier(id);
        case 9:
            break;
        default:
            cout << "Optiune invalida, ati inchis meniul \n";
            break;
        }

    } while (choice != 9);

}

int main()
{

    CRUDMenuFilm();

}
