#include <iostream>
#include <string>

using namespace std;

class carte {
private:
    string titlu = "Necunoscut", autor = "Necunoscut", autorDoi = "Necunoscut";
    int nrPagini = -1;
    float pret = -1.0, rating = -1.0;
public:
    //Constructori
    carte(string titlu, string autor, string autorDoi, int nrPagini, float pret, float rating) {
        this->titlu = titlu;
        this->autor = autor;
        this->autorDoi = autorDoi;
        this->nrPagini = nrPagini;
        this->pret = pret;
        this->rating = rating;
    }
    //Cazul in care nu exista un autor secundar
    carte(string titlu, string autor, int nrPagini, float pret, float rating) {
        this->titlu = titlu;
        this->autor = autor;
        this->autorDoi = "Inexistent";
        this->nrPagini = nrPagini;
        this->pret = pret;
        this->rating = rating;
    }
    carte() {
        this->titlu = "Necunoscut";
        this->autor = "Necunoscut";
        this->autorDoi = "Inexistent";
        this->nrPagini = -1;
        this->pret = -1.0;
        this->rating = -1.0;
    }
    //Constructor de copiere
    carte(carte& carte0) {
        this->titlu = carte0.titlu;
        this->autor = carte0.autor;
        this->autorDoi = carte0.autorDoi;
        this->nrPagini = carte0.nrPagini;
        this->pret = carte0.pret;
        this->rating = carte0.rating;
    }
    //Destructor
    ~carte() {
        delete &titlu;
        delete &autor;
        delete &autorDoi;
        delete &nrPagini;
        delete &pret;
        delete &rating;
    }
    //Getters
    string getTitlu() {
        return this->titlu;
    }
    string getAutor() {
        return this->autor;
    }
    string getAutorDoi() {
        return this->autorDoi;
    }
    int getNrPagini() {
        return this->nrPagini;
    }
    float getPret() {
        return this->pret;
    }
    float getRating() {
        return this->rating;
    }
    //Setters
    void setTitlu(string titlu) {
        this->titlu = titlu;
    }
    void setAutor(string autor) {
        this->autor = autor;
    }
    void setAutorDoi(string autorDoi) {
        this->autorDoi = autorDoi;
    }
    void setNrPagini(int nrPagini) {
        this->nrPagini = nrPagini;
    }
    void setPret(float pret) {
        this->pret = pret;
    }
    void setRating(float rating) {
        this->rating = rating;
    }
    //Supraincarcare operatori
    carte& operator=(carte& carte0) {
        if (this != &carte0) {
            titlu = carte0.titlu;
            autor = carte0.autor;
            autorDoi = carte0.autorDoi;
            nrPagini = carte0.nrPagini;
            pret = carte0.pret;
            rating = carte0.rating;
        }
        return *this;
    }
    bool operator<(carte& carte0) {
        if (rating < carte0.rating) {
            return true;
        } else {
            return false;
        }
    }
    bool operator==(carte& carte0) {
        if (rating == carte0.rating) {
            return true;
        } else {
            return false;
        }
    }
    bool operator>(carte& carte0) {
        if (rating > carte0.rating) {
            return true;
        } else {
            return false;
        }
    }
    bool operator<=(carte& carte0) {
        if (rating <= carte0.rating) {
            return true;
        } else {
            return false;
        }
    }
    bool operator>=(carte& carte0) {
        if (rating >= carte0.rating) {
            return true;
        } else {
            return false;
        }
    }
    friend ostream& operator<<(ostream& out, carte& carte0) {
        cout<<"Titlu: "<<carte0.titlu<<endl<<"Autor: "<<carte0.autor<<endl;
        if (carte0.autorDoi != "Inexistent") cout<<"Al doilea autor: "<<carte0.autorDoi<<endl;
        cout<<"Numar pagini: "<<carte0.nrPagini<<endl<<"Pret: "<<carte0.pret<<" lei"<<endl<<"Rating: "<<carte0.rating<<"/5"<<endl<<endl;
    }
    friend istream& operator>>(istream&, carte& carte0) {
        string titlu, autor, autorDoi;
        int nrPagini;
        float pret, rating;
        cout<<"Titlu: ";
        getline(cin, titlu);
        carte0.titlu = titlu;
        cout<<"Autor: ";
        getline(cin, autor);
        carte0.autor = autor;
        cout<<"Al doilea autor (introduceti 0 daca nu exista): ";
        getline(cin, autorDoi);
        if (autorDoi == "0") autorDoi = "Inexistent";
        else carte0.autorDoi = autorDoi;
        cout<<"Numar pagini: ";
        cin>>nrPagini;
        carte0.nrPagini = nrPagini;
        cout<<"Pret: ";
        cin>>pret;
        carte0.pret = pret;
        cout<<"Rating/5: ";
        rating = -1;
        while (rating < 0 || rating > 5) {
            cin>>rating;
            if (rating < 0 || rating > 5) cout<<"Ati introdus un rating ilegal camarazi. Ratingul trebuie sa fie o valoare intre 0 si 5: ";
        }
        carte0.rating = rating;
        cout<<endl;
    }
};

int meniu() {
    cout<<"Bine ati venit la libraria Prada! Alegeti o actiune apasand pe tasta corespunzatoare:"<<endl;
    cout<<"1 - Afisati cartile din stoc."<<endl;
    cout<<"2 - Adaugati o carte in stoc."<<endl;
    cout<<"3 - Comparati doua carti."<<endl;
    cout<<"4 - Modificati informatiile unei carti."<<endl;
    cout<<"0 - Parasiti libraria."<<endl;
    char optiune;
    cin>>optiune;
    cin.get();
    return optiune;
}

int main()
{
    int numar = 0;
    char optiune;
    carte* carti;
    carti = new carte[numar];

    while (true) {
        optiune = meniu();
        if (optiune == '0') break;
        else if (optiune != '1' && optiune != '2' && optiune != '3' && optiune != '4') cout<<"Nu ati introdus o optiune valida. Incercati din nou."<<endl<<endl;
        else if (optiune == '1') {
            if (numar == 0) cout<<"Momentan nu exista nicio carte in stoc. Reveniti mai tarziu."<<endl<<endl;
            else {
                for (int i = 0; i < numar; i++) {
                    cout<<carti[i];
                }
            }
        } else if (optiune == '2') {
            numar++;
            carte* aux;
            aux = new carte[numar];
            for (int i = 0; i < numar-1; i++) {
                aux[i] = carti[i];
            }
            cin>>aux[numar-1];
            carti = new carte[numar];
            for (int i = 0; i < numar; i++) {
                carti[i] = aux[i];
            }
        } else if (optiune == '3') {
            string titlu1, titlu2;
            float rating1, rating2;
            cout<<"Titlul cartii 1: ";
            getline(cin,titlu1);
            cout<<"Titlul cartii 2: ";
            getline(cin,titlu2);
            int k = 0;
            cout<<numar;
            for (int i = 0; i < numar; i++) {
                if (carti[i].getTitlu() == titlu1) {
                    rating1 = carti[i].getRating();
                    k++;
                }
                if (carti[i].getTitlu() == titlu2) {
                    rating2 = carti[i].getRating();
                    k++;
                }
            }
            if (k != 2) cout<<"Ati introdus date gresite."<<endl<<endl;
            else {
                if (rating1 < rating2) cout<<titlu1<<" ("<<rating1<<"/5) are un rating mai mic decat "<<titlu2<<" ("<<rating2<<"/5)."<<endl<<endl;
                else if (rating1 == rating2) cout<<titlu1<<" ("<<rating1<<"/5) are acelasi rating cu "<<titlu2<<" ("<<rating2<<"/5)."<<endl<<endl;
                else if (rating1 > rating2) cout<<titlu1<<" ("<<rating1<<"/5) are un rating mai mare decat "<<titlu2<<" ("<<rating2<<"/5)."<<endl<<endl;
            }
        } else if (optiune == '4') {
            string titlu1, varianta1, nou;
            int nouInt;
            float nouFloat;
            cout<<"Titlul cartii: ";
            getline(cin,titlu1);
            int k = 0;
            for (int i = 0; i < numar; i++) {
                if (carti[i].getTitlu() == titlu1) {
                    k = 1;
                }
            }
            if (k == 0) cout<<"Ati introdus un titlu inexistent."<<endl;
            else {
                cout<<"Ce doriti sa modificati? - titlu, autor, autor2, pagini, pret, rating: ";
                getline(cin,varianta1);
                if (varianta1 != "titlu" && varianta1 != "autor" && varianta1 != "autor2" && varianta1 != "pagini" && varianta1 != "pret" && varianta1 != "rating") {
                    cout<<"Ati introdus o optiune invalida."<<endl;
                } else {
                    for (int i = 0; i < numar; i++) {
                        if (carti[i].getTitlu() == titlu1) {
                            k++;
                            if (varianta1 == "titlu") {
                                getline(cin,nou);
                                cout<<"Introduceti titlul: ";
                                carti[i].setTitlu(nou);
                            } else if (varianta1 == "autor") {
                                getline(cin,nou);
                                cout<<"Introduceti autorul: ";
                                carti[i].setAutor(nou);
                            } else if (varianta1 == "autor2") {
                                getline(cin,nou);
                                cout<<"Introduceti autorul secundar: ";
                                carti[i].setAutorDoi(nou);
                            } else if (varianta1 == "pagini") {
                                cin>>nouInt;
                                cout<<"Introduceti numarul de pagini: ";
                                carti[i].setNrPagini(nouInt);
                            } else if (varianta1 == "pret") {
                                cin>>nouFloat;
                                cout<<"Introduceti pretul: ";
                                carti[i].setPret(nouFloat);
                            }  else if (varianta1 == "rating") {
                                cout<<"Introduceti ratingul: ";
                                nouFloat = -1.0;
                                while (nouFloat < 0 || nouFloat > 5) {
                                    cin>>nouFloat;
                                    if (nouFloat < 0 || nouFloat > 5) cout<<"Ati introdus o valoare ilegala. Introduceti o valoare intre 0 si 5."<<endl;
                                }
                                carti[i].setRating(nouFloat);
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"Sanatate camarazi!";
    return 0;
}
