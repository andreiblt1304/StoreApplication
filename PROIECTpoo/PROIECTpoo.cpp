#include <iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include<map>
using namespace std;

ifstream fin;
ofstream fout;
fstream fio;



class magazin
{
protected:
    string numeProd;
    int codProd;
    float pretProd;
    int cantitate;

public:

    //constructor implicit
    magazin()
    {
        numeProd="";
        codProd = 0;
        pretProd = 0;
        cantitate=0;  //incearca  cu map
    }

    //constructor de copiere
    magazin(string inNumeProd, int inCodProd, float inPretProd, int inCantitate):numeProd(inNumeProd), codProd(inCodProd), pretProd(inCodProd), cantitate(inCantitate);


    //setteri
    void setNumeProd(string n)
    {
        numeProd = n;
    }

    void setCodProd(int c)
    {
        codProd = c;
    }

    void setPretProd(int p)
    {
        pretProd = p;
    }
    

    //getteri
    string getNumeProd()
    {
        return numeProd;
    }

    int getCodProd()
    {
        return this->codProd;
    }

    float getPretProd()
    {
        return this->pretProd;
    }

    //operator <<
    friend ostream& operator<<(ostream& out, const magazin& sursa)
    {
        out << "Numele produsului este: " << sursa.numeProd << "\n";
        out << "Pretul produsului este: " << sursa.pretProd << "\n";
        out << "Codul produsului este: " << sursa.codProd << "\n";
        return out;
    }


    //destructor
    ~magazin()
    {
        
    }




    //raportul comenzilor
    void raport()
    {

    ifstream infile("comenzi.txt");
    ofstream outfile("raportComenzi.txt");
    string continut = "";
    int i;

    for (i = 0; infile.eof() != true; i++)
        continut += infile.get();

    i--;
    continut.erase(continut.end() - 1);     

    cout << i << " characters read...\n";       //!!!!!!!!!!!!!
    infile.close();

    outfile << continut;                 
    outfile.close();

    }


    //operator =
    magazin& operator=(const magazin& s)
    {
        numeProd = s.numeProd;
        codProd = s.codProd;
        pretProd = s.pretProd;
    }


};


class angajat :protected magazin
{
    string nume;
public:

    
    //citire fisier
    friend ifstream& operator>>(ifstream& fIn, angajat& a)
    {
        fIn >> a.numeProd;
        fIn >> a.codProd;
        fIn >> a.pretProd;
    };

    template<class A, class B>
void fin SaveMap(std::map<A, B>& savethismap)
{
  ofstream tfStream("filename");
  tfStream << savethismap.size() << std::endl;
  typedef std::pair<const A, B>& pr;
  BOOST_FOREACH(pr p, savethismap)
  {
     tfStream >> p.first << std::endl << p.second << std::endl;
  }
  tfStream.close();
}



    //scriere in fisier
    friend ofstream& operator<<(ofstream& fOut, const angajat& a)
    {
        //introducem map pentru produse
        std::map< string, int, float, int> Map;
        for(auto &el1:Map)
        {
            Map["Produs"]=pretProd, 
        }

    }

    //modificare fisier
    void modifica(fstream& f)
    {

    }
};


class client:magazin
{
    string numeClient;
    int nrTel;
    string adresa;

    //constructor implicit
    client()
    {
        numeClient= "";
        int nrTel = 0;
        adresa= "";
    }

    //constructor de copiere
    client(string inNumeClient, int inNrTel, string inAdresa)
    {
        numeClient=inNumeClient;
        nrTel = inNrTel;
        adresa=inAdresa;
    }
F

    //setteri
    void setNumeClient(string n)
    {
        numeClient = n;
    }

    void setNrTel(int nr)
    {
        nrTel = nr;
    }

    void setAdresa(string a)
    {
        adresa = a;
    }


    //getteri
    string getNumeClient()
    {
        return this->numeClient;
    }

    int getNrTel()
    {
        return this->nrTel;
    }

    string getAdresa()
    {
        return this->adresa;
    }



    void cautare(fstream fin, char* nm, int n)
    {
        client c;
        fin.open("magazin.bin", ios::in | ios::binary);
        while (!fin) {
            fin.read((char*)&c, sizeof(c));
            if (c.getNumeProd() == nm) {
                cout << "Produs gasit, doriti sa il adaugati in cos?(1=da, 0=nu) ";
                cin >> n;
                if (n == 1)
                    fin >> c.cosCumparaturi;
                else break;
            }
        }
        fin.close();

};
class Discount
{

};

class Produs
{
    float pret;
    int cod;
    string nume;

public:
    Produs()
    {
        pret=0;
        cod=0;
        nume="";
    }
    
   virtual void getData();
};

class Alimente:Produs
{
    int dataExpirare;

public:
    Alimente()
    {
        dataExpirare=0;
    }

    void getData()
    {
        fstream file("produse.bin", ios::binary | ios::in | ios::out | ios::trunc);
        if (!file.is_open())
        cout << "Eroare la deschiderea fisierului";
    else
    {
        file.write((char*)&prod, sizeof(Produs));
    }
    }

};
class Electronice:Produs
{
    int garantie;

public:
    Electronice()
    {

    }
};
class Curatenie:Produs
{
    int dataExpirare;

public:

};

/*void scrieProduse(Produs& produs)
{
    fstream fisier("data.bin",ios::in|ios::out|ios::binary);
    ofstream& write(, sizeof(Produs));
}*/

int main()
{

    magazin mag;
    Produs prod;
    fstream file("produse.bin", ios::binary | ios::in | ios::out | ios::trunc);
    if (!file.is_open())
        cout << "Eroare la deschiderea fisierului";
    else
    {
        file.write((char*)&prod, sizeof(Produs));
    }



    //setam pozitia de unde sa scriem in fisier
    file.seekg(0);

    //setam unde sa fie introdusele datele
    file.read((char*)&mag, sizeof(magazin));


    //selectarea profilului
    int alegere;
    cout << "Buna ziua, ce profil doriti sa accesati?"<<endl;
    cout << "1.magazin" << endl;
    cout << "2.client" << endl;
    cin >> alegere;
    switch (alegere)
    {
    case 1:
        magazin mag;
        break;

    case 2:
        client cl;
        break;

    default:
        cout << "optiune invalida\n";
        break;
    };
    

    
   


}

