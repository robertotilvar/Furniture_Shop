#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;

class iFile //clasa abstracta + metode virtuale pure
{
public:
	virtual void WriteToFile(fstream& file) = 0;
	virtual void ReadFromFile(fstream& file) = 0;
	virtual void Raport(fstream& file) = 0;
};


class Mobila:public iFile
//este vorba despre categorie mai mult gen: scaun, masa sau bucatarie/baie, inca nu m am decis
{
private:
	const int id_mobila;
	string denumire_mobila;
	static int nr_mobila;
	int nr_modele;
	string* modele;
	int* cantitate_model;
	float* pret_model;
public:
	Mobila() :
		id_mobila(nr_mobila),denumire_mobila("NA"), nr_modele(0), modele(NULL),cantitate_model(NULL),pret_model(NULL)
	{
		nr_mobila++;
	}

	Mobila(string denumire_mobila, int nr_modele, string* modele, int* cantitate_model, float* pret_model) :
		id_mobila(nr_mobila), denumire_mobila(denumire_mobila)
	{
		if (nr_modele > 0 && modele != NULL && cantitate_model != NULL && pret_model != NULL)
		{
			this->nr_modele = nr_modele;
			this->modele = new string[nr_modele];
			this->cantitate_model = new int[nr_modele];
			this->pret_model = new float[nr_modele];
			for (int i = 0;i < this->nr_modele;i++)
			{
				this->modele[i] = modele[i];
				this->cantitate_model[i] = cantitate_model[i];
				this->pret_model[i] = pret_model[i];
			}
		}
		else
		{
			if (nr_modele == 0)
			{
				this->nr_modele = 0;
				this->modele = NULL;
				this->cantitate_model = NULL;
				this->pret_model = NULL;
			}
			else
				throw exception("\nValorile introduse nu sunt bune!\n");
		}
		nr_mobila++;
	}
	Mobila(string denumire_mobila) :
		id_mobila(nr_mobila), denumire_mobila(denumire_mobila),
		nr_modele(0), modele(NULL), cantitate_model(NULL), pret_model(NULL)
	{
		nr_mobila++;
	}
	Mobila(const Mobila& m) :
		id_mobila(m.id_mobila), denumire_mobila(m.denumire_mobila),
		nr_modele(m.nr_modele), modele(m.modele),
		cantitate_model(m.cantitate_model), pret_model(m.pret_model)
	{
		if (m.nr_modele > 0 && m.modele != NULL)
		{
			this->nr_modele = m.nr_modele;
			this->modele = new string[this->nr_modele];
			for (int i = 0;i < this->nr_modele;i++)
				this->modele[i] = m.modele[i];
			if (m.cantitate_model !=NULL && m.pret_model != NULL)
			{
				this->cantitate_model = new int[this->nr_modele];
				this->pret_model = new float[this->nr_modele];
				for (int i = 0;i < this->nr_modele;i++)
				{
					this->cantitate_model[i] = m.cantitate_model[i];
					this->pret_model[i] = m.pret_model[i];
				}
			}
			else
			{
				this->cantitate_model = NULL;
				this->pret_model = NULL;
			}
		}
		else
		{
			this->nr_modele = 0;
			this->modele = NULL;
			this->cantitate_model = NULL;
			this->pret_model = NULL;
		}
	}
	~Mobila()
	{
		delete[] this->modele;
		delete[] this->cantitate_model;
		delete[] this->pret_model;
	}
	string getdenumire()
	{
		return this->denumire_mobila;
	}
	int getid()
	{
		return this->id_mobila;
	}
	int getnrmodele()
	{
		return this->nr_modele;
	}
	string getmodele(int i)
	{
		if (i >= 0 && i < this->nr_modele)
			return this->modele[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	int getcantitate(int i)
	{
		if (i >= 0 && i < this->nr_modele)
			return this->cantitate_model[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	float getpret(int i)
	{
		if (i >= 0 && i < this->nr_modele)
			return this->pret_model[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	int getnrmobila()
	{
		return this->nr_mobila;
	}

	void setdenumire(string denumire)
	{
		this->denumire_mobila = denumire;
	}
	void setnrmodele(int i)
	{
		if (i >= 0)
			this->nr_modele = i;
		else
			throw exception("Valoarea introdusa este prea mica!\n");
	}
	void setmodele(string* modele, int nr)
	{
		if (modele != NULL && nr > 0)
		{
			this->nr_modele = nr;
			delete[] this->modele;
			this->modele = new string[nr];
			for (int i = 0;i < nr;i++)
				this->modele[i] = modele[i];
		}
		else
		{
			if (nr == 0)
			{
				this->nr_modele = 0;
				this->modele = NULL;
			}
			else
				throw exception("Valorile introduse nu sunt bune!\n");
		}
	}
	void setcantitate(int* cantitate, int nr)
	{
		if (cantitate != NULL && nr > 0)
		{
			this->nr_modele = nr;
			delete[] this->cantitate_model;
			this->cantitate_model = new int[nr];
			for (int i = 0;i < nr;i++)
				this->cantitate_model[i] = cantitate[i];
		}
		else
		{
			if (nr == 0)
			{
				this->nr_modele = 0;
				this->cantitate_model = NULL;
			}
			else
				throw exception("Valorile introduse nu sunt bune!\n");
		}
	}
	void setpret(float* pret, int nr)
	{
		if (pret != NULL && nr > 0)
		{
			this->nr_modele = nr;
			delete[] this->pret_model;
			this->pret_model= new float[nr];
			for (int i = 0;i < nr;i++)
				this->pret_model[i] = pret[i];
		}
		else
		{
			if (nr == 0)
			{
				this->nr_modele = 0;
				this->pret_model = NULL;
			}
			else
				throw exception("Valorile introduse nu sunt bune!\n");
		}
	}

	Mobila& operator=(const Mobila& m)
	{
		this->denumire_mobila = m.denumire_mobila;
		this->nr_modele = m.nr_modele;
		delete[] this->cantitate_model;
		delete[] this->modele;
		delete[] this->pret_model;
		if (this->nr_modele > 0 && m.cantitate_model!=NULL&&m.modele!=NULL&&m.pret_model!=NULL)
		{
			this->modele = new string[this->nr_modele];
			this->cantitate_model = new int[this->nr_modele];
			this->pret_model = new float[this->nr_modele];
			for (int i = 0;i < this->nr_modele;i++)
			{
				this->modele[i] = m.modele[i];
				this->cantitate_model[i] = m.cantitate_model[i];
				this->pret_model[i] = m.pret_model[i];
			}
		}
		else
		{
			this->modele = NULL;
			this->cantitate_model = NULL;
			this->pret_model = NULL;
		}
		return *this;
	}

	Mobila& operator+(int x)
	{
		if (x >= 0)
		{
			cout << "\n===============================\n\nAdaugare de modele pentru:\n";
			cout << "Mobila " << this->id_mobila<<endl<<endl;
			Mobila copie = *this;
			delete[] this->modele;
			delete[] this->cantitate_model;
			delete[] this->pret_model;
			this->nr_modele = copie.nr_modele + x;
			this->modele = new string[this->nr_modele];
			this->cantitate_model = new int[this->nr_modele];
			this->pret_model = new float[this->nr_modele];
			for (int i = 0;i < copie.nr_modele;i++)
			{
				this->modele[i] = copie.modele[i];
				this->cantitate_model[i] = copie.cantitate_model[i];
				this->pret_model[i] = copie.pret_model[i];
			}
			for (int i = copie.nr_modele;i < this->nr_modele;i++)
			{
				cout << "Modelul " << i + 1 << " se numeste: ";
				getline(cin, this->modele[i], '\n');
				if (this->modele[i].empty())
					getline(cin, this->modele[i], '\n');
				cout << "\nCantitatea disponibila: ";
				cin >> this->cantitate_model[i];
				cout << "\nPretul: ";
				cin >> this->pret_model[i];
			}
			return *this;
		}
		else
			throw exception("\nValoarea introdusa este prea mica!\n");
	}
	Mobila& operator!()
	{
		cout << "\n============================== = \n\nOperator de negatie pentru: \n";
		cout << "Mobila " << this->id_mobila << endl << endl;
		delete[] this->modele;
		delete[] this->cantitate_model;
		delete[] this->pret_model;
		this->nr_modele = 0;
		this->modele = NULL;
		this->cantitate_model = NULL;
		this->pret_model = NULL;
		return *this;
	}
	int& operator[](int x)//pentru cantitate
	{
		if (x >= 0 && x < this->nr_modele)
		{
			/*cout << "\n===============================\n\nOperatorul index pentru:\n";
			cout << "Mobila " << this->id_mobila << endl << endl;*/
			return this->cantitate_model[x];
		}
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	explicit operator string()
	{
		return this->denumire_mobila;
	}
	bool operator==(const Mobila& m)
	{
		if (this->nr_modele == m.nr_modele)
			return true;
		else
			return false;
	}
	bool operator<(const Mobila& m)
	{
		if (this->nr_modele < m.nr_modele)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& out, const Mobila& m);
	friend istream& operator>>(istream& in, Mobila& m);

	void WriteToFile(fstream& file)
	{
		file.write((char*)&this->id_mobila, sizeof(int));
		int lgstring = this->denumire_mobila.length() + 1;
		file.write((char*)&lgstring, sizeof(int));
		file.write(this->denumire_mobila.data(), lgstring);
		file.write((char*)&this->nr_mobila, sizeof(int));
		file.write((char*)&this->nr_modele, sizeof(int));
		for (int i = 0;i < this->nr_modele;i++)
		{
			lgstring = this->modele[i].length() + 1;
			file.write((char*)&lgstring, sizeof(int));
			file.write(this->modele[i].data(), lgstring);
			file.write((char*)&this->cantitate_model[i], sizeof(int));
			file.write((char*)&this->pret_model[i], sizeof(float));
		}
	}
	void ReadFromFile(fstream& file)
	{
		delete[] this->modele;
		delete[] this->cantitate_model;
		delete[] this->pret_model;

		file.read((char*)&this->id_mobila, sizeof(int));
		char* buffer;
		int lgstring = 0;
		file.read((char*)&lgstring, sizeof(int));
		buffer = new char[lgstring];
		file.read(buffer, lgstring);
		this->denumire_mobila = buffer;
		file.read((char*)&this->nr_mobila, sizeof(int));
		file.read((char*)&this->nr_modele, sizeof(int));
		if (this->nr_modele > 0)
		{
			for (int i = 0;i < this->nr_modele;i++)
			{
				delete[] buffer;
				lgstring = 0;
				file.read((char*)&lgstring, sizeof(int));
				buffer = new char[lgstring];
				file.read(buffer, lgstring);
				this->modele[i] = buffer;
				file.read((char*)&this->cantitate_model[i], sizeof(int));
				file.read((char*)&this->pret_model[i], sizeof(float));
			}
		}
		else
		{
			this->nr_modele = 0;
			this->modele = NULL;
			this->cantitate_model = NULL;
			this->pret_model = NULL;
		}
	}
	void Raport(fstream& file)
	{
		float valoare_mobila = 0;
		for (int i = 0;i < this->nr_modele;i++)
			valoare_mobila += this->cantitate_model[i] * this->pret_model[i];
		cout << "Mobila cu ID = " << this->id_mobila << " are valoarea " << valoare_mobila << " lei.\n";
		file << "Mobila cu ID = "<<this->id_mobila<<" are valoarea "<<valoare_mobila<<" lei.\n";
	}

};
int Mobila::nr_mobila = 1;
ostream& operator<<(ostream& out, const Mobila& m)
{
	out << "\n====================================";
	out << endl << "\nInformatii mobila:\n\n";
	out << "ID mobila: " << m.id_mobila << endl;
	out << "Denumire mobila: " << m.denumire_mobila << endl;
	out << "Modele disponibile: " << m.nr_modele << endl<<endl;
	if (m.nr_modele > 0)
	{
		for (int i = 0;i < m.nr_modele;i++)
		{
			out << "Modelul " << i + 1 << " - " << m.modele[i] << endl;
			out << "Cantitatea disponibila este: " << m.cantitate_model[i] << endl;
			out << "Pretul pe bucata este: " << m.pret_model[i] << " lei\n" << endl;
		}
	}
	else
		cout << "Nu exista alte informatii.";
	cout << endl;
	return out;
}
istream& operator>>(istream& in, Mobila& m)
{
	cout << "\n====================================";
	cout << "\n\nInregistrare mobila:\n\n";
	cout << "Denumire mobila: ";
	//in >> m.denumire_mobila;
	getline(in, m.denumire_mobila, '\n');
	if(m.denumire_mobila=="")
		getline(in, m.denumire_mobila, '\n');
	cout << "Modele disponibile: ";
	in >> m.nr_modele;
	if (m.nr_modele > 0)
	{
		m.modele = new string[m.nr_modele];
		m.cantitate_model = new int[m.nr_modele];
		m.pret_model = new float[m.nr_modele];
		for (int i = 0;i < m.nr_modele;i++)
		{
			cout << "Model "<<i+1<<" : ";
			in >> m.modele[i];
			cout << "Cantitate disponibila: ";
			in >> m.cantitate_model[i];
			cout << "Pretul pe bucata: ";
			in >> m.pret_model[i];
		}
	}
	else
	{
		if (m.nr_modele == 0)
		{
			m.modele = NULL;
			m.cantitate_model = NULL;
			m.pret_model = NULL;
		}
		else
			throw exception("Valoarea trebuie sa fie >= 0 !");
	}
	cout << endl;
	return in;
}

class Client: public iFile
{
private:
	const int id;
	int nrcomenzi;
	float* pretcomenzi;
	static int nr;
protected:
	string numeclient;
public:
	Client() :id(nr), numeclient("NA"), nrcomenzi(0), pretcomenzi(NULL)
	{
		nr++;
	}
	Client(string nume, int nrcom, float* pret) :
		id(nr),numeclient(nume)
	{
		if (nrcom > 0 && pret != NULL)
		{
			this->nrcomenzi = nrcom;
			this->pretcomenzi = new float[this->nrcomenzi];
			for (int i = 0;i < nrcom;i++)
				this->pretcomenzi[i] = pret[i];
		}
		else
		{
			this->nrcomenzi = 0;
			this->pretcomenzi = 0;
		}
		nr++;
	}
	Client(string denumire) :id(nr), numeclient(denumire), nrcomenzi(0), pretcomenzi(NULL)
	{
		nr++;
	}
	Client(const Client& c):id(c.id),numeclient(c.numeclient)
	{
		if (c.nrcomenzi > 0 && c.pretcomenzi != NULL)
		{
			this->nrcomenzi = c.nrcomenzi;
			this->pretcomenzi = new float[c.nrcomenzi];
			for (int i = 0;i < c.nrcomenzi;i++)
				this->pretcomenzi[i] = c.pretcomenzi[i];
		}
		else
		{
			this->nrcomenzi = 0;
			this->pretcomenzi = NULL;
		}
	}
	~Client()
	{
		delete[] this->pretcomenzi;
	}

	Client& operator=(const Client& c)
	{
		this->numeclient = c.numeclient;
		this->nrcomenzi = c.nrcomenzi;
		if (this->nrcomenzi && c.pretcomenzi != NULL)
		{
			delete[] this->pretcomenzi;
			this->pretcomenzi = new float[this->nrcomenzi];
			for (int i = 0;i < this->nrcomenzi;i++)
				this->pretcomenzi[i] = c.pretcomenzi[i];
		}
		else
		{
			this->nrcomenzi = 0;
			this->pretcomenzi = NULL;
		}
		return *this;
	}
	string getnume()
	{
		return this->numeclient;
	}
	int getnrcomenzi()
	{
		return this->nrcomenzi;
	}
	float getpret(int i)
	{
		if (i>=0 && i < this->nrcomenzi)
			return this->pretcomenzi[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	void setnume(string denumire)
	{
		this->numeclient = denumire;
	}
	void setnrcomenzi(int i)
	{
		if (i >= 0)
			this->nrcomenzi = i;
		else
			throw exception("\nValoarea nu poate fi negativa!\n");
	}
	void setpret(int nr, float* pret)
	{
		if (nr >= 0 && pret != NULL)
		{
			this->nrcomenzi = nr;
			delete[] this->pretcomenzi;
			this->pretcomenzi = new float[this->nrcomenzi];
			for (int i = 0;i < nr;i++)
				this->pretcomenzi[i] = pret[i];
		}
		else
			throw exception("\nValorile introduse nu se potrives!\n");
	}
	int getnrclienti()
	{
		return this->nr;
	}
	int getidclient()
	{
		return this->id;
	}

	Client& operator+(int x)
	{
		if (x >= 0)
		{
			cout << "\n===============================\n\nAdaugare comenzi pentru:\n";
			cout << "Clientul " << this->id << endl << endl;
			Client copie = *this;
			this->nrcomenzi = copie.nrcomenzi + x;
			delete[] this->pretcomenzi;
			this->pretcomenzi = new float[this->nrcomenzi];
			for (int i = 0;i < copie.nrcomenzi;i++)
			{
				this->pretcomenzi[i] = copie.pretcomenzi[i];
			}
			for (int i = copie.nrcomenzi;i < this->nrcomenzi;i++)
			{
				cout << "Comanda " << i + 1 << " a costat: ";
				cin >> this->pretcomenzi[i];
			}
			return *this;
		}
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	Client& operator!()
	{
		cout << "\n============================== = \n\nOperator de negatie pentru: \n";
		cout << "Comenzile clientului " << this->id << endl << endl;
		delete[] this->pretcomenzi;
		this->nrcomenzi = 0;
		this->pretcomenzi = NULL;
		return *this;
	}
	float& operator[](int x)
	{
		if (x >= 0 && x < this->nrcomenzi)
			return this->pretcomenzi[x];
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	explicit operator string()
	{
		return this->numeclient;
	}
	bool operator==(const Client& c)
	{
		if (this->id == c.id)
			return true;
		else
			return false;
	}
	bool operator<(const Client& c)
	{
		if (this->nrcomenzi < c.nrcomenzi)
			return true;
		else
			return false;
	}


	friend ostream& operator<<(ostream& out, const Client& c);
	friend istream& operator>>(istream& in, Client& c);

	void WriteToFile(fstream& file)
	{
		file.write((char*)&this->id, sizeof(int));
		int lgstring = this->numeclient.length() + 1;
		file.write((char*)&lgstring, sizeof(int));
		file.write(this->numeclient.data(), lgstring);
		file.write((char*)&this->nrcomenzi, sizeof(int));
		for (int i = 0;i < this->nrcomenzi;i++)
			file.write((char*)&this->pretcomenzi[i], sizeof(float));
		file.write((char*)&this->nr, sizeof(int));
	}
	void ReadFromFile(fstream& file)
	{
		file.read((char*)&this->id, sizeof(int));
		char* buffer;
		int lgstring = 0;
		file.read((char*)&lgstring, sizeof(int));
		buffer = new char[lgstring];
		file.read(buffer, lgstring);
		this->numeclient = buffer;
		file.read((char*)&this->nrcomenzi, sizeof(int));
		if (this->nrcomenzi > 0)
			for (int i = 0;i < this->nrcomenzi;i++)
				file.read((char*)&this->pretcomenzi[i], sizeof(float));
		else
		{
			this->nrcomenzi = 0;
			this->pretcomenzi = NULL;
		}
		file.read((char*)&this->nr, sizeof(int));
	}
	void Raport(fstream& file)
	{

	}
};
int Client::nr = 1;
ostream& operator<<(ostream& out, const Client& c)
{
	out << "\n====================================\n";
	out << "\nInformatii client\n\n";
	out << "ID client: " << c.id << endl;
	out << "Nume client: " << c.numeclient << endl;
	if (c.nrcomenzi > 0)
	{
		out << "Numar de comenzi efectuate: " << c.nrcomenzi << endl;
		for (int i = 0;i < c.nrcomenzi;i++)
			out << "Comanda " << i + 1 << " a costat: " << c.pretcomenzi[i] << endl;
	}
	else
		out << "Nu exista informatii inregistrate!\n";
	return out;
}
istream& operator>>(istream& in, Client& c)
{
	cout << "\n====================================\n";
	cout << "\nInregistrare client\n\n";
	cout << "Nume client: ";
	//in >> c.numeclient;
	getline(in, c.numeclient, '\n');
	if(c.numeclient.empty())
		getline(in, c.numeclient, '\n');
	cout << "Comenzi efectuate de client: ";
	in >> c.nrcomenzi;
	if (c.nrcomenzi > 0)
	{
		c.pretcomenzi = new float[c.nrcomenzi];
		for (int i = 0;i < c.nrcomenzi;i++)
		{
			cout << "Comanda " << i + 1 << " a costat: ";
			in >> c.pretcomenzi[i];
		}
	}
	else
	{
		if (c.nrcomenzi == 0)
			c.pretcomenzi = NULL;
		else
			throw exception("Valoarea trebuie sa fie mai mica sau egala cu 0 !");
	}
	return in;
}

class Angajat:public iFile
{
private:
	int tranzactii;
	float* comision;//in lei
	static int nrangajat;
protected:
	string nume;
	int id;
	string data_ang;
public:
	Angajat() :id(0),nume("NA"),data_ang("-"),tranzactii(0),comision(NULL)
	{
		nrangajat++;
	}
	Angajat(int id, string nume, string data_ang, int ore, float* salariu) :
		id(id), nume(nume), data_ang(data_ang)
	{
		if (ore != 0 && salariu != NULL)
		{
			this->tranzactii = ore;
			this->comision = new float[ore];
			for (int i = 0;i < ore;i++)
				this->comision[i] = salariu[i];
		}
		else
		{
			this->tranzactii = 0;
			this->comision = NULL;
		}
		nrangajat++;
	}
	Angajat(int id) :id(id), nume("NA"), data_ang("-"), tranzactii(0), comision(NULL)
	{
		nrangajat++;
	}
	~Angajat()
	{
		delete[] this->comision;
	}
	Angajat(const Angajat& a):id(a.id),nume(a.nume),data_ang(data_ang)
	{
		if (a.tranzactii != 0 && a.comision != NULL)
		{
			this->tranzactii = a.tranzactii;
			this->comision = new float[a.tranzactii];
			for (int i = 0;i < a.tranzactii;i++)
				this->comision[i] = a.comision[i];
		}
		else
		{
			this->tranzactii = 0;
			this->comision = NULL;
		}
	}
	Angajat& operator=(const Angajat& a)
	{
		this->id = a.id;
		this->nume = a.nume;
		this->data_ang = a.data_ang;
		if (a.tranzactii != 0 && a.comision != NULL)
		{
			this->tranzactii = a.tranzactii;
			delete[] this->comision;
			this->comision = new float[this->tranzactii];
			for (int i = 0;i < this->tranzactii;i++)
				this->comision[i] = a.comision[i];
		}
		else
		{
			this->tranzactii = 0;
			this->comision = NULL;
		}
		return *this;
	}
	int getid()
	{
		return this->id;
	}
	string getnume()
	{
		return this->nume;
	}
	string getdata()
	{
		return this->data_ang;
	}
	int gettranzactii()
	{
		return this->tranzactii;
	}
	float getsalariu(int i)
	{
		if (i >= 0 && i < this->tranzactii)
			return this->comision[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	void setid(int i)
	{
		if (i >= 0)
			this->id = i;
		else
			throw exception("\nID-ul nu poate fi negativ!\n");
	}
	void setnume(string nume)
	{
		this->nume = nume;
	}
	void setdata(string data)
	{
		this->data_ang = data;
	}
	void settranzactii(int i)
	{
		if (i >= 0)
			this->tranzactii = i;
		else
			throw exception("\nValoarea nu poate fi negativa!\n");
	}
	void setsalariu(int ore, float* salariu)
	{
		if (ore >= 0 && salariu != NULL)
		{
			this->tranzactii = ore;
			delete[] this->comision;
			this->comision = new float[this->tranzactii];
			for (int i = 0;i < this->tranzactii;i++)
				this->comision[i] = salariu[i];
		}
		else
			throw exception("\nValorile nu sunt bune!\n");
	}
	int getnrangajati()
	{
		return this->nrangajat;
	}

	/*bool operator<(const Angajat& angajat)
	{
		if (this->id < angajat.id)
			return true;
		else
			return false;
	}*/
	Angajat& operator+(int x)
	{
		if (x >= 0)
		{
			cout << "\n===============================\n\nAdaugare tranzactii pentru:\n";
			cout << "Angajatul " << this->id << endl << endl;
			Angajat copie = *this;
			this->tranzactii = copie.tranzactii + x;
			delete[] this->comision;
			this->comision = new float[this->tranzactii];
			for (int i = 0;i < copie.tranzactii;i++)
				this->comision[i] = copie.comision[i];
			for (int i = copie.tranzactii;i < this->tranzactii;i++)
			{
				cout << "Tranzactia " << i + 1 << " a avut comisionul = ";
				cin >> this->comision[i];
			}
			return *this;
		}
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	Angajat& operator!()
	{
		cout << "\n============================== = \n\nOperator de negatie pentru: \n";
		cout << "Tranzactiile angajatului " << this->id << endl << endl;
		delete[] this->comision;
		this->tranzactii = 0;
		this->comision = NULL;
		return *this;
	}
	float& operator[](int x)
	{
		if (x >= 0 && x < this->tranzactii)
			return this->comision[x];
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	operator int()
	{
		return this->tranzactii;
	}
	bool operator==(const Angajat& a)
	{
		if (this->tranzactii == a.tranzactii)
			return true;
		else
			return false;
	}
	friend bool operator<(const Angajat& a, const Angajat& b)
	{
		if (a.tranzactii < b.tranzactii)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& out, const Angajat& a);
	friend istream& operator>>(istream& in, Angajat& a);

	void WriteToFile(fstream& file)
	{
		file.write((char*)&this->id, sizeof(int));
		int lgstring = this->nume.length() + 1;
		file.write((char*)&lgstring, sizeof(int));
		file.write(this->nume.data(), lgstring);
		lgstring = this->data_ang.length() + 1;
		file.write((char*)&lgstring, sizeof(int));
		file.write(this->data_ang.data(), lgstring);
		file.write((char*)&this->tranzactii, sizeof(int));
		for (int i = 0;i < this->tranzactii;i++)
			file.write((char*)&this->comision[i], sizeof(float));
	}
	void ReadFromFile(fstream& file)
	{
		file.read((char*)&this->id, sizeof(int));
		int lgstring = 0;
		char* buffer;
		file.read((char*)&lgstring, sizeof(int));
		buffer = new char[lgstring];
		file.read(buffer, lgstring);
		this->nume = buffer;
		file.read((char*)&lgstring, sizeof(int));
		delete[] buffer;
		buffer = new char[lgstring];
		file.read(buffer, lgstring);
		this->data_ang = buffer;
		file.read((char*)&this->tranzactii, sizeof(int));
		if (this->tranzactii > 0)
			for (int i = 0;i < this->tranzactii;i++)
				file.read((char*)&this->comision[i], sizeof(float));
		else
		{
			this->tranzactii = 0;
			this->comision = NULL;
		}
	}
	void Raport(fstream& file)
	{

	}
};
int Angajat::nrangajat = 0;
ostream& operator<<(ostream& out, const Angajat& a)
{
	out << "\n====================================";
	out << "\n\nInformatii angajat:\n\n";
	out << "ID: " << a.id<<endl;
	out << "Nume angajat: " << a.nume<<endl;
	out << "Data angajarii: " << a.data_ang << endl;
	if (a.tranzactii > 0)
	{
		out << "Tranzactii: " << a.tranzactii << endl;
		for (int i = 0;i < a.tranzactii;i++)
			out << "Comisionul pentru tranzactia " << i + 1 << " este: " << a.comision[i] << endl;
	}
	else
		out << "Nu exista alte informatii.\n";
	return out;
}
istream& operator>>(istream& in, Angajat& a)
{
	cout << "\n====================================";
	cout << "\nInregistrare angajat:\n\n";
	cout << "ID angajat: ";
	in >> a.id;
	cout << "\nNume angajat:";
	getline(in, a.nume, '\n');//aici nu merge
	if (a.nume.empty())
		getline(in, a.nume, '\n');//a mers dupa ce am pus asta
	cout << "\nData angajarii: ";
	//in >> a.data_ang;
	getline(in, a.data_ang, '\n');//nici aici
	cout<< "\nTranzactii efectuate: ";
	in >> a.tranzactii;
	if (a.tranzactii > 0)
	{
		a.comision = new float[a.tranzactii];
		for (int i = 0;i < a.tranzactii;i++)
		{
			cout << "Tranzactia " << i + 1 << " a avut comisionul: ";
			in >> a.comision[i];
		}
	}
	else
	{
		if (a.tranzactii == 0)
			a.comision = NULL;
		else
			throw exception("\nNu puteti inregistra o valoare negativa!\n");
	}
	return in;
}

class Furnizor: public iFile
{
private:
	const int id;
	string denumire;
	int nrproduse;
	int* livrari;//cate livrari au fost efectuate pt fiecare produs
	float* pret;//pret pe bucata pt fiecare produs
	static int fur;
public:
	Furnizor() :id(fur),denumire("NA"),nrproduse(0),livrari(NULL),pret(NULL)
	{
		fur++;
	}
	Furnizor(string denumire) :id(fur), denumire(denumire), nrproduse(0), livrari(NULL), pret(NULL)
	{
		fur++;
	}
	Furnizor(string denumire, int nrproduse, int* livrari, float* pret) :
		id(fur),denumire(denumire)
	{
		if (nrproduse > 0 && livrari != NULL && pret != NULL)
		{
			this->nrproduse = nrproduse;
			this->livrari = new int[nrproduse];
			this->pret = new float[nrproduse];
			for (int i = 0;i < this->nrproduse;i++)
			{
				this->livrari[i] = livrari[i];
				this->pret[i] = pret[i];
			}
		}
		else
		{
			if (nrproduse == 0)
			{
				this->pret = NULL;
				this->livrari = NULL;
			}
			else
				throw exception("\nValorile nu sunt bune!\n");
		}
	}
	Furnizor(const Furnizor& f):id(f.id),denumire(f.denumire)
	{
		if (f.nrproduse > 0 && f.livrari != NULL && f.pret != NULL)
		{
			this->nrproduse = f.nrproduse;
			this->livrari = new int[f.nrproduse];
			this->pret = new float[f.nrproduse];
			for (int i = 0;i < this->nrproduse;i++)
			{
				this->livrari[i] = f.livrari[i];
				this->pret[i] = f.pret[i];
			}
		}
		else
		{
			if (f.nrproduse == 0)
			{
				this->nrproduse = 0;
				this->pret = NULL;
				this->livrari = NULL;
			}
			else
				throw exception("\nValorile nu sunt bune!\n");
		}
	}
	Furnizor& operator=(const Furnizor f)
	{
		this->denumire = f.denumire;
		delete[] this->livrari;
		delete[] this->pret;
		if (f.nrproduse > 0 && f.livrari != NULL && f.pret != NULL)
		{
			this->nrproduse = f.nrproduse;
			this->livrari = new int[f.nrproduse];
			this->pret = new float[f.nrproduse];
			for (int i = 0;i < this->nrproduse;i++)
			{
				this->livrari[i] = f.livrari[i];
				this->pret[i] = f.pret[i];
			}
		}
		else
		{
			if (f.nrproduse == 0)
			{
				this->nrproduse = 0;
				this->pret = NULL;
				this->livrari = NULL;
			}
			else
				throw exception("\nValorile nu sunt bune!\n");
		}
		return *this;
	}

	int getid()
	{
		return this->id;
	}
	string getdenumire()
	{
		return this->denumire;
	}
	int getnrproduse()
	{
		return this->nrproduse;
	}
	int getlivrari(int i)
	{
		if (i >= 0 && i < this->nrproduse)
			return this->livrari[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	float getpret(int i)
	{
		if (i >= 0 && i < this->nrproduse)
			return this->pret[i];
		else
			throw exception("\nInregistrarea nu exista!\n");
	}
	void setdenumire(string denumire)
	{
		this->denumire = denumire;
	}
	void setnrproduse(int nrprod)
	{
		if (nrprod >= 0)
			this->nrproduse = nrprod;
		else
			throw exception("\nValoarea nu este buna!\n");
	}
	void setlivrari(int nr, int* livrari)
	{
		if (nr >= 0&&livrari!=NULL)
		{
			this->nrproduse = nr;
			delete[] this->livrari;
			this->livrari = new int[nr];
			for (int i = 0;i < nr;i++)
				this->livrari[i] = livrari[i];
		}
		else
			throw exception("\nValorile nu sunt bune!\n");
	}
	void setpret(int nr, float* pret)
	{
		if (nr >= 0 && pret != NULL)
		{
			this->nrproduse = nr;
			delete[] this->pret;
			this->pret = new float[nr];
			for (int i = 0;i < nr;i++)
				this->pret[i] = pret[i];
		}
		else
			throw exception("\nValorile nu sunt bune!\n");
	}
	int getnrfurnizori()
	{
		return this->fur;
	}

	Furnizor& operator+(int x)
	{
		if (x >= 0)
		{
			cout << "\n===============================\n\nAdaugare produse pentru:\n";
			cout << "Furnizorul " << this->id << endl << endl;
			Furnizor copie = *this;
			this->nrproduse = copie.nrproduse + x;
			delete[] this->livrari;
			delete[] this->pret;
			this->livrari = new int[this->nrproduse];
			this->pret = new float[this->nrproduse];
			for (int i = 0;i < copie.nrproduse;i++)
			{
				this->livrari[i] = copie.livrari[i];
				this->pret[i] = copie.livrari[i];
			}
			for (int i = copie.nrproduse;i < this->nrproduse;i++)
			{
				cout << "Produsul " << i + 1 << " are cantitatea = ";
				cin >> this->livrari[i];
				cout << "Pretul pe bucata a fost = ";
				cin >> this->pret[i];
			}
			return *this;
		}
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	Furnizor& operator!()
	{
		delete[] this->livrari;
		delete[] this->pret;
		this->nrproduse = 0;
		this->livrari = NULL;
		this->pret = NULL;
		return *this;
	}
	int& operator[](int x)
	{
		if (x >= 0 && x < this->nrproduse)
			return this->livrari[x];
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	operator int()
	{
		return this->nrproduse;
	}
	explicit operator string()
	{
		return this->denumire;
	}
	bool operator==(const Furnizor& f)
	{
		if (this->nrproduse == f.nrproduse)
			return true;
		else
			return false;
	}
	bool operator<(const Furnizor& f)
	{
		if (this->nrproduse < f.nrproduse)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& out, const Furnizor& f);
	friend istream& operator>>(istream& in, Furnizor& f);

	void WriteToFile(fstream& file)
	{
		file.write((char*)&this->id, sizeof(int));
		int lgstring = this->denumire.length() + 1;
		file.write((char*)&lgstring, sizeof(int));
		file.write(this->denumire.data(), lgstring);
		file.write((char*)&this->nrproduse, sizeof(int));
		for (int i = 0;i < this->nrproduse;i++)
		{
			file.write((char*)&this->livrari[i], sizeof(int));
			file.write((char*)&this->pret[i], sizeof(float));
		}
		file.write((char*)&this->fur, sizeof(int));
	}
	void ReadFromFile(fstream& file)
	{
		file.read((char*)&this->id, sizeof(int));
		int lgstring = 0;
		char* buffer;
		file.read((char*)&lgstring, sizeof(int));
		buffer = new char[lgstring];
		file.read(buffer, lgstring);
		this->denumire = buffer;
		file.read((char*)&this->nrproduse, sizeof(int));
		if (this->nrproduse > 0)
		{
			for (int i = 0;i < this->nrproduse;i++)
			{
				file.read((char*)&this->livrari[i], sizeof(int));
				file.read((char*)&this->pret[i], sizeof(int));
			}
		}
		else
		{
			this->nrproduse = 0;
			this->livrari = NULL;
			this->pret = NULL;
		}
		file.read((char*)&this->fur, sizeof(int));
	}
	void Raport(fstream& file)
	{
		float valoare_livrari = 0;
		for (int i = 0;i < this->nrproduse;i++)
			valoare_livrari += this->pret[i] * this->livrari[i];
		cout << "Furnizorul cu ID= " << this->id << " a livrat marfa in valoare totala de " << valoare_livrari << " lei.\n";
		file << "Furnizorul cu ID= " << this->id << " a livrat marfa in valoare totala de " << valoare_livrari << " lei.\n";
	}
};
int Furnizor::fur = 1001;
ostream& operator<<(ostream& out, const Furnizor& f)
{
	out << "\n====================================";
	out << "\n\nInformatii furnizor:\n\n";
	out << "ID furnizor: " << f.id<<endl;
	out << "Denumire furnizor: " << f.denumire << endl;
	if (f.nrproduse > 0)
	{
		out << "Produse: " << f.nrproduse << endl;
		for (int i = 0;i < f.nrproduse;i++)
		{
			out << "Produsul " << i + 1 << " a fost livrat in "
				<< f.livrari[i] << " bucati la pretul de " << f.pret[i] << " lei/bucata.\n";
		}
	}
	else
		out << "Nu exista alte inregistrari.\n";
	return out;
}
istream& operator>>(istream& in, Furnizor& f)
{
	cout << "\n====================================";
	cout << "\n\nInregistrare furnizor:\n\n";
	cout << "Denumire furnizor: ";
	//in >> f.denumire;
	getline(in, f.denumire, '\n');
	if (f.denumire == "")
		getline(in, f.denumire, '\n');
	cout << "Produse furnizor: ";
	in >> f.nrproduse;
	if (f.nrproduse > 0)
	{
		f.livrari = new int[f.nrproduse];
		f.pret = new float[f.nrproduse];
		for (int i = 0;i < f.nrproduse;i++)
		{
			cout << "Livrari pentru produsul " << i + 1 << " = ";
			in >> f.livrari[i];
			cout << "Pretul produsului a fost = ";
			in >> f.pret[i];
		}
	}
	else
	{
		if (f.nrproduse == 0)
		{
			f.livrari = NULL;
			f.pret = NULL;
		}
		else
			throw exception("\nValorile introduse nu sunt bune!\n");
	}
	return in;
}

class NotaDeReceptie:public iFile
{
private:
	const int nr_nota;
	static int note;
	int idangajat;
	int idfurnizor;
	string data_receptie;
	int produse_receptionate;
	float* pret_produs;
	int* cantitate_livrata;
public:
	NotaDeReceptie() :nr_nota(note), idangajat(0), idfurnizor(0), data_receptie("-"),
		produse_receptionate(0), pret_produs(NULL), cantitate_livrata(NULL)
	{
		note++;
	}
	NotaDeReceptie(int idangajat, int idfurnizor, string data_receptie,
		int produse_receptionate, float* pret_produs, int* cantitate_livrata) :
		nr_nota(note),idangajat(idangajat),idfurnizor(idfurnizor),data_receptie(data_receptie)
	{
		if (produse_receptionate != 0 && pret_produs != NULL && cantitate_livrata != NULL)
		{
			this->produse_receptionate = produse_receptionate;
			this->pret_produs = new float[this->produse_receptionate];
			this->cantitate_livrata = new int[this->produse_receptionate];
			for (int i = 0;i < this->produse_receptionate;i++)
			{
				this->pret_produs[i] = pret_produs[i];
				this->cantitate_livrata[i] = cantitate_livrata[i];
			}
		}
		else
		{
			this->produse_receptionate = 0;
			this->pret_produs = NULL;
			this->cantitate_livrata = NULL;
		}
		note++;
	}
	NotaDeReceptie(const NotaDeReceptie& n) :nr_nota(n.nr_nota)
	{
		this->idangajat = n.idangajat;
		this->idfurnizor = n.idfurnizor;
		this->data_receptie = n.data_receptie;
		if (n.produse_receptionate != 0 && n.pret_produs != NULL && n.cantitate_livrata != NULL)
		{
			this->produse_receptionate = n.produse_receptionate;
			this->pret_produs = new float[this->produse_receptionate];
			this->cantitate_livrata = new int[this->produse_receptionate];
			for (int i = 0;i < this->produse_receptionate;i++)
			{
				this->pret_produs[i] = n.pret_produs[i];
				this->cantitate_livrata[i] = n.cantitate_livrata[i];
			}
		}
		else
		{
			this->produse_receptionate = 0;
			this->pret_produs = NULL;
			this->cantitate_livrata = NULL;
		}
	}
	NotaDeReceptie& operator=(const NotaDeReceptie n)
	{
		this->idangajat = n.idangajat;
		this->idfurnizor = n.idfurnizor;
		this->data_receptie = n.data_receptie;
		delete[] this->cantitate_livrata;
		delete[] this->pret_produs;
		if (n.produse_receptionate != 0 && n.pret_produs != NULL && n.cantitate_livrata != NULL)
		{
			this->produse_receptionate = n.produse_receptionate;
			this->pret_produs = new float[this->produse_receptionate];
			this->cantitate_livrata = new int[this->produse_receptionate];
			for (int i = 0;i < this->produse_receptionate;i++)
			{
				this->pret_produs[i] = n.pret_produs[i];
				this->cantitate_livrata[i] = n.cantitate_livrata[i];
			}
		}
		else
		{
			this->produse_receptionate = 0;
			this->pret_produs = NULL;
			this->cantitate_livrata = NULL;
		}
		return *this;
	}

	int getnr_nota()
	{
		return this->nr_nota;
	}
	int getidangajat()
	{
		return this->idangajat;
	}
	int getidfurnizor()
	{
		return this->idfurnizor;
	}
	string getdata_receptie()
	{
		if (this->data_receptie != "")
			return this->data_receptie;
		else
			return "";
	}
	int getproduse_receptionate()
	{
		return this->produse_receptionate;
	}
	float getpret_produs(int i)
	{
		if (i >= 0 && i < this->produse_receptionate)
			return this->pret_produs[i];
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	int getcantitate_livrata(int i)
	{
		if (i >= 0 && i < this->produse_receptionate)
			return this->cantitate_livrata[i];
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	void setidangajat(int i)
	{
		if (i >= 0)
			this->idangajat = i;
		else
			throw exception("\nValoarea nu este buna!\n");
	}
	void setidfurnizor(int i)
	{
		if (i >= 0)
			this->idfurnizor = i;
		else
			throw exception("\nValoarea nu este buna!\n");
	}
	void setdata_receptie(string data)
	{
		this->data_receptie = data;
	}
	void setproduse_receptionate(int i)
	{
		if (i >= 0)
			this->produse_receptionate = i;
		else
			throw exception("\nValoarea nu este buna!\n");
	}
	void setpret_produs(int nr, float* pret)
	{
		if (nr >= 0 && pret != NULL)
		{
			this->produse_receptionate = nr;
			this->pret_produs = new float[this->produse_receptionate];
			for (int i = 0;i < nr;i++)
				this->pret_produs[i] = pret[i];
		}
		else
			throw exception("\nValorile introduse nu sunt bune!\n");
	}
	void setcantitate_livrata(int nr, int* q)
	{
		if (nr >= 0 && q != NULL)
		{
			this->produse_receptionate = nr;
			this->cantitate_livrata = new int[this->produse_receptionate];
			for (int i = 0;i < nr;i++)
				this->cantitate_livrata[i] = q[i];
		}
		else
			throw exception("\nValorile introduse nu sunt bune!\n");
	}
	int getnote()
	{
		return this->note;
	}

	NotaDeReceptie& operator-(int x)
	{
		if (x >= 0 && x <= this->produse_receptionate)
		{
			cout << "\n===============================\n\nLipsa produse receptionate la:\n";
			cout << "Nota de receptie " << this->nr_nota << endl << endl;
			NotaDeReceptie copie = *this;
			delete[] this->cantitate_livrata;
			delete[] this->pret_produs;
			this->produse_receptionate = copie.produse_receptionate - x;
			for (int i = 0;i < this->produse_receptionate;i++)
			{
				this->cantitate_livrata[i] = copie.cantitate_livrata[i];
				this->pret_produs[i] = copie.pret_produs[i];
			}
			return *this;
		}
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	NotaDeReceptie& operator!()
	{
		delete[] this->cantitate_livrata;
		delete[] this->pret_produs;
		this->produse_receptionate = 0;
		this->cantitate_livrata = NULL;
		this->pret_produs = NULL;
		return *this;
	}
	int& operator[](int x)
	{
		if (x >= 0 && x < this->produse_receptionate)
			return this->cantitate_livrata[x];
		else
			throw exception("\nValoarea introdusa nu este buna!\n");
	}
	explicit operator string()
	{
		return this->data_receptie;
	}
	bool operator==(const NotaDeReceptie& n)
	{
		if (this->data_receptie == n.data_receptie)
			return true;
		else
			return false;
	}
	bool operator<(const NotaDeReceptie& n)
	{
		if (this->produse_receptionate < n.produse_receptionate)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& out, const NotaDeReceptie& n);
	friend istream& operator>>(istream& in, NotaDeReceptie& n);

	void WriteToFile(fstream& file)
	{
		file.write((char*)&this->nr_nota, sizeof(int));
		file.write((char*)&this->note, sizeof(int));
		file.write((char*)&this->idangajat, sizeof(int));
		file.write((char*)&this->idfurnizor, sizeof(int));
		int lg = this->data_receptie.length() + 1;
		file.write((char*)&lg, sizeof(int));
		file.write(this->data_receptie.data(), lg);
		file.write((char*)&this->produse_receptionate, sizeof(int));
		for (int i = 0;i < this->produse_receptionate;i++)
		{
			file.write((char*)&this->pret_produs[i], sizeof(float));
			file.write((char*)&this->cantitate_livrata[i], sizeof(int));
		}
	}
	void ReadFromFile(fstream& file)
	{
		file.read((char*)&this->nr_nota, sizeof(int));
		file.read((char*)&this->note, sizeof(int));
		file.read((char*)&this->idangajat, sizeof(int));
		file.read((char*)&this->idfurnizor, sizeof(int));
		int lg = 0;
		char* buffer;
		file.read((char*)&lg, sizeof(int));
		buffer = new char[lg];
		file.read((char*)&buffer, lg);
		this->data_receptie = buffer;
		file.read((char*)&this->produse_receptionate, sizeof(int));
		if (this->produse_receptionate > 0)
		{
			for (int i = 0;i < this->produse_receptionate;i++)
			{
				file.read((char*)&this->pret_produs[i], sizeof(float));
				file.read((char*)&this->cantitate_livrata[i], sizeof(int));
			}
		}
		else
		{
			this->produse_receptionate = 0;
			this->pret_produs = NULL;
			this->cantitate_livrata = NULL;
		}
	}
	void Raport(fstream& file)
	{
		float valoare_receptie = 0;
		for (int i = 0;i < this->produse_receptionate;i++)
			valoare_receptie += this->cantitate_livrata[i] * this->pret_produs[i];
		cout << "In data de " << this->data_receptie << ", receptia " << this->nr_nota << " a avut valoarea totala de " << valoare_receptie << " lei.\n";
		file << "In data de " << this->data_receptie << ", receptia " << this->nr_nota << " a avut valoarea totala de " << valoare_receptie << " lei.\n";
	}
};
int NotaDeReceptie::note = 1;
ostream& operator<<(ostream& out, const NotaDeReceptie& n)
{
	out << "\n====================================";
	out << "\n\nInformatii nota de receptie:\n\n";
	out << "Numar nota: " << n.nr_nota<<endl;
	out << "Data: " << n.data_receptie << endl;
	out << "Intocmita de angajatul: " << n.idangajat << endl;
	out << "Produsele au fost livrate de furnizorul: " << n.idfurnizor << endl;
	if (n.produse_receptionate > 0)
	{
		out << "Au fost receptionate " << n.produse_receptionate << " produse:\n";
		for (int i = 0;i < n.produse_receptionate;i++)
		{
			out << "Au fost receptionate " << n.cantitate_livrata[i] << " bucati din produsul "
				<< i + 1 << " la pretul de " << n.pret_produs[i] << " lei/bucata.\n";
		}
	}
	else
		out << "Nu a fost receptionat niciun produs.\n";
	return out;
}
istream& operator>>(istream& in, NotaDeReceptie& n)
{
	cout << "\n====================================";
	cout << "\n\nInregistrare nota de receptie:\n\n";
	cout << "Data receptiei: ";
	getline(in, n.data_receptie, '\n');
	if(n.data_receptie=="")
		getline(in, n.data_receptie, '\n');
	cout << "Nota de receptie a fost intocmita de: ";
	in >> n.idangajat;
	cout << "Marfurile au fost livrate de:";
	in >> n.idfurnizor;
	cout << "Numar produse receptionate: ";
	in >> n.produse_receptionate;
	if (n.produse_receptionate > 0)
	{
		n.pret_produs = new float[n.produse_receptionate];
		n.cantitate_livrata = new int[n.produse_receptionate];
		for (int i = 0;i < n.produse_receptionate;i++)
		{
			cout << "Cantitatea din produsul " << i + 1 << " receptionata: ";
			in >> n.cantitate_livrata[i];
			cout << "Pretul unitar la receptie: ";
			in >> n.pret_produs[i];
		}
	}
	else
	{
		if (n.produse_receptionate == 0)
		{
			n.cantitate_livrata = NULL;
			n.pret_produs = NULL;
		}
		else
			throw exception("\nValorile introduse nu sunt corecte!\n");
	}
	return in;
}

//clasa pt faza 3
class Comanda //compunere
{
public:
	static int comenzi;
	int nrcomanda;
	Mobila* mobila = NULL; //agregare
	Client client; //compunere
	int produse_comandate=0;
	int* cantitate_comandata = NULL;

	Comanda()
	{
		this->nrcomanda=comenzi;
		comenzi++;
	}

	Comanda(Mobila* mobila, Client client, int produse_comandate, int* cantitate_comandata)
	{
		if (mobila != NULL && cantitate_comandata != NULL)
		{
			if (produse_comandate <= mobila[0].getnrmobila() && produse_comandate > 0)
			{
				this->produse_comandate = produse_comandate;
				this->mobila = new Mobila[this->produse_comandate];
				this->cantitate_comandata = new int[this->produse_comandate];
				for (int i = 0;i < this->produse_comandate;i++)
				{
					this->mobila[i] = mobila[i];
					this->cantitate_comandata[i] = cantitate_comandata[i];
				}
				this->client = client;
			}
			else
				throw exception("\nNumarul de produse comandate este incorect!\n");
		}
		else
			throw exception("\nCantitatea si/sau mobila comandata trebuie sa existe!\n");
		this->nrcomanda = comenzi;
		comenzi++;
	}
	int getnrcomenzi()
	{
		return this->comenzi;
	}

	~Comanda()
	{
		delete[] this->mobila;
		delete[] this->cantitate_comandata;
	}

	friend ostream& operator<<(ostream& out, const Comanda& comanda);
	//friend istream& operator>>(istream& in, Comanda& comanda);
};
int Comanda::comenzi = 1;
ostream& operator<<(ostream& out, const Comanda& comanda)
{
	out << "\nComanda: " << comanda.nrcomanda << endl;
	//out << "Cumparator: " << comanda.client.getnume() << endl;
	if (comanda.produse_comandate != 0)
	{
		out << "Produse comandate: " << comanda.produse_comandate << endl;
		for (int i = 0;i < comanda.produse_comandate;i++)
		{
			out << "Produsul " << i + 1 << "\nDenumire: " << comanda.mobila[i].getdenumire() <<
				"\nCantitate: " << comanda.cantitate_comandata[i] << endl;
		}
	}
	else
		out << "Nu exista alte informatii.\n";
	return out;
}

class SefDepartament :public Angajat //derivare is-a
{
public:
	static int nr_departamente;
	string denumire_departament = "N/A";
	SefDepartament()
	{
		nr_departamente++;
	}
	SefDepartament(string denumire_departament, int id, string nume, string data_ang, int ore, float* salariu) :
		Angajat(id, nume, data_ang, ore, salariu)
	{
		this->denumire_departament = denumire_departament;
		nr_departamente++;
	}
	SefDepartament(const SefDepartament& sd) :Angajat(sd)
	{
		this->denumire_departament = sd.denumire_departament;
	}
	SefDepartament& operator=(const SefDepartament& sd)
	{
		Angajat::operator = (sd);
		this->denumire_departament = sd.denumire_departament;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const SefDepartament& sd)
	{
		out << "\nDepartament: " << sd.denumire_departament;
		out << "\nSef: "<<sd.nume;
		out << "\nID: " << sd.id;
		out << "\nData angajarii: " << sd.data_ang << endl;
		return out;
	}
	int getdepartamente()
	{
		return this->nr_departamente;
	}
};
int SefDepartament::nr_departamente = 0;

int main()
{
	//faza 1
	
	cout << "Magazin de mobila\n";

	//pentru mobila
	string denumire = "Set masa+scaune";
	int nr_modele = 3;
	string modele[3] = { "Negru", "Alb", "In carouri" };
	int cantitate_model[3] = { 3,5,5 };
	float pret_model[3] = { 249.99,549.99,599.99 };
	Mobila M1;
	Mobila M2(denumire, nr_modele, modele, cantitate_model, pret_model);
	//cout << M1;
	//cout << M2;

	/*
	{//cin >> M1;
	//cout << M1;
	//M1 + 3;
	//cout << M1;
	//M1 = M2 + 1;
	//cout << M1;
	//!M2;
	//cout << M2;
	/*if (M1 == M2) cout << "M1 si M2 au acelasi numar de modele\n";
	else cout << "M1 si M2 nu au acelasi numar de modele\n";
	if (M1 < M2) cout << "M1 are mai putine modele decat M2\n";
	else cout << "M1 are mai multe modele decat M2\n";
	cout << endl;
	cout << M2[2];
	cout << endl << endl;
	cout <<"Denumirea piesei de mobilier M2 este: "<<M2.operator std::string();
	cout << endl << endl;
	}*/

	//pentru client
	string numeclient = "Ion Popescu";
	int comenziclient = 5;
	float valoarecomenziclient[5] = { 500, 600, 3000, 2500, 200 };
	Client C1;
	Client C2(numeclient, comenziclient, valoarecomenziclient);
	//cout << C2;
	//cout << C1;
	/*
	//cin >> C1;
	//cout << C1;
	//C1 = C2 + 1;
	//cout << C1;
	!C2;
	cout << C2 << endl;
	if (C1 == C2) cout << "Clientii au acelasi id.\n";
	else cout << "Clientii au id diferit.\n";
	if (C1 < C2) cout << "Clientul C1 are mai putine comenzi decat C2.\n";
	else cout << "Clientul C1 nu are mai putine comenzi decat C2.\n";
	*/

	//pentru angajat
	int idangajat = 1249;
	string numeangajat = "Plescoi Mariana";
	string data_ang = "11.02.2020";
	int tranzactii = 2;
	float comision[2] = { 120,560 };
	Angajat A1;
	Angajat A2(idangajat, numeangajat, data_ang, tranzactii, comision);
	int idangajat2 = 1250;
	string numeangajat2 = "Vasile Marian";
	string data_ang2 = "10.02.2020";
	int tranzactii2 = 2;
	float comision2[2] = { 200,400 };
	Angajat A3(idangajat2, numeangajat2, data_ang2, tranzactii2, comision2);
	//cout << A2;
	//cout << A1;
	/*
	{//cin >> A1;
	//cout << A1;
	//A2 + 1;
	//cout << A2;
	A1 = A2;
	cout << A1;
	!A2;
	cout << A2;
	}*/

	//pentru furnizor
	string denumirefurnizor = "S.C. ALFA S.R.L.";
	int nrprodusefurnizor = 3;
	int livrari[3] = { 20,25,15 };
	float pret[3] = { 2100,3400,1600 };
	Furnizor F1;
	Furnizor F2(denumirefurnizor, nrprodusefurnizor, livrari, pret);
	//cout << F2;
	//cout << F1;
	/*
	{//cin >> F1;
	//cout << F1;
	//F1 = F2 + 1;
	//cout <<F1;
	!F1;
	cout << F1;}*/

	//pentru nota de receptie
	int idfurnizor = F2.getid();
	string data_receptie = "25.10.2020";
	NotaDeReceptie N1;
	NotaDeReceptie N2(idangajat, idfurnizor, data_receptie, nrprodusefurnizor, pret, livrari);
	//cout << N2;
	//cout << N1;
	/*
	{//cin >> N1;
	//cout << N1;
	//N1 = N2 - 1;
	cout << N1;
	!N1;
	cout << N1;
	}*/

	//cout << M1;
	//cout << M2;
	
	//faza 2 - meniu
	
	fstream f_mobila_s("mobila.txt", ios::out | ios::binary | ios::app);
	fstream f_clienti_s("clienti.txt", ios::out | ios::binary | ios::app);
	fstream f_angajati_s("angajati.txt", ios::out | ios::binary | ios::app);
	fstream f_furnizori_s("furnizori.txt", ios::out | ios::binary | ios::app);
	fstream f_receptie_s("nota_receptie.txt", ios::out | ios::binary | ios::app);
	

	fstream f_mobila_c("mobila.txt", ios::in | ios::binary |ios::app);
	fstream f_clienti_c("clienti.txt", ios::in | ios::binary | ios::app);
	fstream f_angajati_c("angajati.txt", ios::in | ios::binary | ios::app);
	fstream f_furnizori_c("furnizori.txt", ios::in | ios::binary | ios::app);
	fstream f_receptie_c("nota_receptie.txt", ios::in | ios::binary | ios::app);

	fstream raport_mobila("raport_mobila.txt", ios::in | ios::app);
	fstream raport_furnizori("raport_furnizori.txt", ios::in | ios::app);
	fstream raport_receptie("raport_receptie.txt", ios::in | ios::app);

	//cout << "========================================\n";
	//cout << "========================================\n";
	//cout << "========================================\n";
	//cout << "========================================\n\n\n";

	Mobila M[] = { M1, M2 };
	Client C[] = { C1, C2 };
	Angajat A[] = { A1, A2, A3 };//A3 pus in faza 3
	//cout << "nr angajati: " << A1.getnrangajati() << endl;
	Furnizor F[] = { F1, F2 };
	NotaDeReceptie N[] = { N1, N2 };

	for (int i = 0;i < 2;i++)
	{
		
		M[i].WriteToFile(f_mobila_s);
		C[i].WriteToFile(f_clienti_s);
		A[i].WriteToFile(f_angajati_s);
		F[i].WriteToFile(f_furnizori_s);
		N[i].WriteToFile(f_receptie_s);
	}
	f_mobila_s.close();
	f_clienti_s.close();
	f_angajati_s.close();
	f_furnizori_s.close();
	f_receptie_s.close();

	//faza 3
	//compunere+agregare
	int produse_comandate_c = 2;
	int cantitate_comandata_c[] = { 2,2 };
	//derivare -> familie de clase
	SefDepartament SD1("Contabilitate", idangajat, numeangajat, data_ang, tranzactii, comision);
	SefDepartament SD2("Vanzari", idangajat2, numeangajat2, data_ang2, tranzactii2, comision2);
	//SefDepartament SD[] = { SD1,SD2 };

	Comanda Co1(M, C2, produse_comandate_c, cantitate_comandata_c);
	Comanda Co2;

	//vector<Mobila> mobila;
	//mobila.push_back(M1);
	//mobila.push_back(M2);
	vector<Client> clienti;
	clienti.push_back(C1);
	clienti.push_back(C2);
	vector<Client>::iterator it_clienti;
	vector<Angajat> angajati;
	angajati.push_back(A1);
	angajati.push_back(A2);
	vector<Furnizor> furnizori;
	furnizori.push_back(F1);
	furnizori.push_back(F2);
	vector<Furnizor>::iterator it_furnizori;
	vector<NotaDeReceptie> note;
	note.push_back(N1);
	note.push_back(N2);
	vector<NotaDeReceptie>::iterator it_note;
	//vector pt departamente
	vector<SefDepartament> sd;
	sd.push_back(SD1);
	sd.push_back(SD2);
	vector<SefDepartament>::iterator iterator_sd;

	//set care ordoneaza angajatii in functie de numarul de tranzactii
	set<Angajat> set_angajati;
	set_angajati.insert(A1);
	set_angajati.insert(A2);
	set<Angajat>::iterator iterator_set;

	//list -> lista cu obiectele de mobilier
	list<Mobila> lista_mobila;
	lista_mobila.push_back(M1);
	lista_mobila.push_back(M2);
	list<Mobila>::iterator iterator_lista;

	//map 
	map<int, NotaDeReceptie> nr;
	nr[0] = N1;
	nr[1] = N2;
	map<int, NotaDeReceptie>::iterator iterator_nr;

	//
	/*Mobila M3;
	M3.ReadFromFile(f_mobila_c);
	cout << M3;*/
	//faza 2 modificata in faza 3
	cout << "Buna ziua!\nAcest program este utilizat pentru inregistrarea si vizualizarea tranzactiilor unui magazin de mobila.\n";
	cout << "Ce doriti sa faceti? Introduceti numarul optiunii dorite.\n";
	cout << "0 -> Iesire\n";
	cout << "1 -> Inregistrare\n";
	cout << "2 -> Vizualizare\n";
	cout << "3 -> Raport\n";
	int raspuns;
	cout << "Raspuns: ";
	cin >> raspuns;
	while (raspuns != 0 /*&& raspuns != 1 && raspuns != 2 && raspuns != 3*/)
	{
		if(raspuns != 0 && raspuns != 1 && raspuns != 2 && raspuns != 3)
		cout << "\nEroare! Introduceti un raspuns dintre variantele date: ";
		if (raspuns == 1)
		{
			cout << "Ce doriti sa inregistrati? Introduceti numarul optiunii dorite.\n";
			cout << "0 -> Iesire\n";
			cout << "1 -> Mobila\n";
			cout << "2 -> Client\n";
			cout << "3 -> Angajat\n";
			cout << "4 -> Furnizor\n";
			cout << "5 -> Nota de receptie\n";
			cout << "Raspuns: ";
			int raspuns1;
			cin >> raspuns1;
			while (raspuns1 != 0 && raspuns1 != 1 && raspuns1 != 2 && raspuns1 != 3 && raspuns1 != 4 && raspuns1 != 5)
			{
				cout << "Aceasta nu este o varianta de raspuns. Introduceti din nou: ";
				cin >> raspuns1;
			}
			if (raspuns1 == 0)
				return 0;
			if (raspuns1 == 1)
			{
				cout << "Cate inregistrari efectuati?\n";
				int inr_m;
				cin >> inr_m;
				if (inr_m > 0)
				{
					Mobila* Mo = new Mobila[inr_m];
					for (int i = 0;i < inr_m;i++)
					{
						cin >> Mo[i];
						Mo[i].WriteToFile(f_mobila_s);
						lista_mobila.push_back(Mo[i]);
					}
					f_mobila_s.close();
				}
			}
			if (raspuns1 == 2)
			{
				cout << "Cate inregistrari efectuati?\n";
				int inr_c;
				cin >> inr_c;
				if (inr_c > 0)
				{
					Client* Cl = new Client[inr_c];
					for (int i = 0;i < inr_c;i++)
					{
						cin >> Cl[i];
						Cl[i].WriteToFile(f_clienti_s);
						clienti.push_back(Cl[i]);
					}
					f_clienti_s.close();
				}
			}
			if (raspuns1 == 3)
			{
				cout << "Cate inregistrari efectuati?\n";
				int inr_a;
				cin >> inr_a;
				if (inr_a > 0)
				{
					Angajat* An = new Angajat[inr_a];
					for (int i = 0;i < inr_a;i++)
					{
						cin >> An[i];
						An[i].WriteToFile(f_angajati_s);
						set_angajati.insert(An[i]);
					}
					f_angajati_s.close();
				}
			}
			if (raspuns1 == 4)
			{
				cout << "Cate inregistrari efectuati?\n";
				int inr_f;
				cin >> inr_f;
				if (inr_f > 0)
				{
					Furnizor* Fu = new Furnizor[inr_f];
					for (int i = 0;i < inr_f;i++)
					{
						cin >> Fu[i];
						Fu[i].WriteToFile(f_furnizori_s);
						furnizori.push_back(Fu[i]);
					}
					f_furnizori_s.close();
				}
			}
			if (raspuns1 == 5)
			{
				cout << "Cate inregistrari efectuati?\n";
				int inr_n;
				cin >> inr_n;
				if (inr_n > 0)
				{
					NotaDeReceptie* No = new NotaDeReceptie[inr_n];
					for (int i = 0;i < inr_n;i++)
					{
						cin >> No[i];
						No[i].WriteToFile(f_receptie_s);
						nr[i + 2] = No[i];
						note.push_back(No[i]);//la raport folosesc vector
					}
					f_receptie_s.close();
				}
			}
		}
		if (raspuns == 2)
		{
			cout << "Ce doriti sa vizualizati? Introduceti numarul optiunii dorite.\n";
			cout << "0 -> Iesire\n";
			cout << "1 -> Mobila\n";
			cout << "2 -> Client\n";
			cout << "3 -> Angajat\n";
			cout << "4 -> Furnizor\n";
			cout << "5 -> Nota de receptie\n";
			cout << "6 -> Departamente\n";
			cout << "7 -> Comenzi\n";
			cout << "Raspuns: ";
			int raspuns2;
			cin >> raspuns2;
			while (raspuns2 != 0 && raspuns2 != 1 && raspuns2 != 2
				&& raspuns2 != 3 && raspuns2 != 4 && raspuns2 != 5
				&& raspuns2 != 6 && raspuns2 != 7)
			{
				cout << "Aceasta nu este o varianta de raspuns. Introduceti din nou: ";
				cin >> raspuns2;
			}
			if (raspuns2 == 0)
				return 0;
			if (raspuns2 == 1)
			{
				/*for (int i = 0;i < M->getnrmobila()-Co1.getnrcomenzi();i++)
				{
					cout << M[i];
				}*/
				for (iterator_lista = lista_mobila.begin();iterator_lista != lista_mobila.end();iterator_lista++)
					cout << *iterator_lista << endl;
			}
			if (raspuns2 == 2)
			{
				/*for (int i = 0;i < C->getnrclienti() - Co1.getnrcomenzi();i++)
					cout << C[i];*/
				for (it_clienti = clienti.begin();it_clienti != clienti.end();it_clienti++)
					cout << *it_clienti << endl;
			}
			if (raspuns2 == 3)
			{
				/*cout << "nr angajati: " << A1.getnrangajati() << endl;
				for (int i = 0;i < A->getnrangajati()-SD1.getdepartamente();i++)
					cout << A[i];*/
				for (iterator_set = set_angajati.begin();iterator_set != set_angajati.end();iterator_set++)
					cout << *iterator_set << endl;
			}
			if (raspuns2 == 4)
			{
				/*for (int i = 0;i < F->getnrfurnizori() - 1000;i++)
					cout << F[i];*/
				for (it_furnizori = furnizori.begin();it_furnizori != furnizori.end();it_furnizori++)
					cout << *it_furnizori << endl;
			}
			if (raspuns2 == 5)
			{
				/*for (int i = 0;i < N->getnote()-1;i++)
					cout << N[i];*/
				for (iterator_nr = nr.begin();iterator_nr != nr.end();iterator_nr++)
					cout << iterator_nr->first << endl << iterator_nr->second << endl;
			}
			if (raspuns2 == 6)
			{
				for (iterator_sd = sd.begin();iterator_sd != sd.end();iterator_sd++)
					cout << *iterator_sd << endl;
			}
			if (raspuns2 == 7)
			{
				cout << Co2;
				cout << Co1;
			}
		}
		if (raspuns == 3)
		{
			cout << "Pentru ce doriti afisarea raportului?\n";
			cout << "0 -> Iesire\n";
			cout << "1 -> Mobila\n";
			cout << "2 -> Furnizor\n";
			cout << "3 -> Nota de receptie\n";
			cout << "Raspuns: ";
			int raspuns3;
			cin >> raspuns3;
			while (raspuns3 != 0 && raspuns3 != 1 && raspuns3 != 2 && raspuns3 != 3)
			{
				cout << "Aceasta nu este o varianta de raspuns. Introduceti din nou: ";
				cin >> raspuns3;
			}
			if (raspuns3 == 1)
			{
				/*for (int i = 0;i < M->getnrmobila() - 1;i++)
				{
					M[i].Raport(raport_mobila);
				}*/
				for (iterator_lista = lista_mobila.begin();iterator_lista != lista_mobila.end();iterator_lista++)
					iterator_lista->Raport(raport_mobila);
			}
			if (raspuns3 == 2)
			{
				/*for (int i = 0;i < F->getnrfurnizori() - 1000;i++)
				{
					F[i].Raport(raport_furnizori);
				}*/
				for (it_furnizori = furnizori.begin();it_furnizori != furnizori.end();it_furnizori++)
					it_furnizori->Raport(raport_furnizori);
			}
			if (raspuns3 == 3)
			{
				cout << "Pentru ce zi doriti raportul?\n";
				cout << "Raspuns: ";
				string data;
				cin >> data;
				/*for (int i = 0;i < N->getnote() - 1;i++)
				{
					if (N[i].getdata_receptie() != "")
						if (N[i].getdata_receptie() == data)
							N[i].Raport(raport_receptie);
				}*/
				for (it_note = note.begin();it_note != note.end();it_note++)
				{
					if (it_note->getdata_receptie() == data)
						it_note->Raport(raport_receptie);
				}
			}
		}
		cout << "Ce doriti sa faceti? Introduceti numarul optiunii dorite.\n";
		cout << "0 -> Iesire\n";
		cout << "1 -> Inregistrare\n";
		cout << "2 -> Vizualizare\n";
		cout << "3 -> Raport\n";
		cout << "Raspuns: ";
		cin >> raspuns;
	}
	if (raspuns == 0)
		return 0;
	
	return 0;
}