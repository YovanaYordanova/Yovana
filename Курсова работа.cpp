#include <iostream>
#include <string>

using namespace std;

class YuridicheskoLice {
protected:
    string Ime;
    int GodinaNaPostupvane;

public:
    YuridicheskoLice() : Ime("Nqma ime"), GodinaNaPostupvane(2026) {}

    YuridicheskoLice(string pIme, int pGodina = 2026) : Ime(pIme), GodinaNaPostupvane(pGodina) {}

    virtual ~YuridicheskoLice() {}

    virtual void printInfo() const = 0;
    virtual void Godishnina() const = 0;

    virtual void zapochniRabota() { cout << "Rabotniqt proces za " << Ime << " zapochna.\n"; }
    virtual void proveriStatus() { cout << "Statusut na liceto e proveren.\n"; }
};

class Sudiq : public YuridicheskoLice {
protected:
    string Sud;
    int Staj;

public:
    Sudiq() : YuridicheskoLice(), Sud("Raionen"), Staj(1) {}
    Sudiq(string pIme, int pGodina, string pSud, int pStaj = 5)
        : YuridicheskoLice(pIme, pGodina), Sud(pSud), Staj(pStaj) {
    }

    void uvelichiStaj() { Staj++; }
    void smeniSud(string n) { Sud = n; }

    void Godishnina() const override { cout << Ime << " ima " << Staj << " godini staj.\n"; }
    void printInfo() const override { cout << "Sudiq: " << Ime << ", Sud: " << Sud << endl; }
};

class NakazatelenSudiq : public Sudiq {
private:
    int BroiPrisudi;
    string Kvalifikaciq;

public:
    NakazatelenSudiq() : Sudiq(), BroiPrisudi(0), Kvalifikaciq("Mladshi") {}
    NakazatelenSudiq(string pIme, int pGodina, string pSud, int pPrisudi, string pKval = "Starshi")
        : Sudiq(pIme, pGodina, pSud, 10), BroiPrisudi(pPrisudi), Kvalifikaciq(pKval) {
    }

    void daiPrisuda() { cout << "Sudiq " << Ime << " dade prisuda.\n"; }
    void korigiraiKvalifikaciq(string n) { Kvalifikaciq = n; }

    void printInfo() const override { cout << "Nakazatelen Sudiq: " << Ime << ", Kvalifikaciq: " << Kvalifikaciq << endl; }
};

class Advokat : public YuridicheskoLice {
protected:
    string Oblast;
    int Klienti;

public:
    Advokat() : YuridicheskoLice(), Oblast("Obshto"), Klienti(0) {}
    Advokat(string pIme, int pGodina, string pObl, int pKlienti = 5)
        : YuridicheskoLice(pIme, pGodina), Oblast(pObl), Klienti(pKlienti) {
    }

    void dobaviKlient() { Klienti++; }
    void smeniOblast(string n) { Oblast = n; }

    void Godishnina() const override { cout << "Advokat " << Ime << " raboti ot " << GodinaNaPostupvane << " g.\n"; }
    void printInfo() const override { cout << "Advokat: " << Ime << ", Oblast: " << Oblast << endl; }
};

class Zashtitnik : public Advokat {
protected:
    string KlientIme;
    float Reiting;

public:
    Zashtitnik() : Advokat(), KlientIme("Nqma"), Reiting(4.5) {}
    // Поправено: Предаваме параметъра pObl нагоре, а не несъществуващата променлива Oblast
    Zashtitnik(string pIme, int pGodina, string pObl, string pKl, float pReiting = 9.0)
        : Advokat(pIme, pGodina, pObl), KlientIme(pKl), Reiting(pReiting) {
    }

    void podgotviZashtita() { cout << "Podgotovka za " << KlientIme << ".\n"; }
    void obnoviReiting(float n) { Reiting = n; }

    void printInfo() const override { cout << "Zashtitnik: " << Ime << ", Klient: " << KlientIme << ", Reiting: " << Reiting << endl; }
};

class GlavenSutrudnik : public Zashtitnik {
protected:
    int Pobedi;
    string Firma;

public:
    GlavenSutrudnik() : Zashtitnik(), Pobedi(20), Firma("Law Ltd") {}
    GlavenSutrudnik(string pIme, int pGodina, string pOblast, string pKlient, string pFirma, int pPobedi = 50)
        : Zashtitnik(pIme, pGodina, pOblast, pKlient, 10.0), Pobedi(pPobedi), Firma(pFirma) {
    }

    void uvelichiPobedi() { Pobedi++; }
    void smeniFirma(string n) { Firma = n; }

    void printInfo() const override { cout << "Glaven Sutrudnik: " << Ime << ", Firma: " << Firma << ", Pobedi: " << Pobedi << endl; }
};

class Upravnik : public GlavenSutrudnik {
private:
    int Personal;
    double Budjet;

public:
    Upravnik() : GlavenSutrudnik(), Personal(5), Budjet(20000) {}
    Upravnik(string pIme, int pGodina, string pFirma, int pPers, double pBudjet = 50000.0)
        : GlavenSutrudnik(pIme, pGodina, "Upravlenie", "Firmata", pFirma), Personal(pPers), Budjet(pBudjet) {
    }

    void odobriRazhodi() { cout << "Razhodi za " << Budjet << " lv sa odobreni.\n"; }
    void naemiHora() { Personal++; }

    void printInfo() const override { cout << "Upravnik: " << Ime << ", Personal: " << Personal << ", Budjet: " << Budjet << endl; }
};

int main() {
    const int BROI = 6;
    YuridicheskoLice* spisuk[BROI];

    spisuk[0] = new Sudiq("Georgi Georgiev", 2015, "Apelativen", 12);
    spisuk[1] = new NakazatelenSudiq("Petur Petrov", 2010, "Sofiiski", 150);
    spisuk[2] = new Advokat("Maria Todorova", 2020, "Grajdansko", 25);
    spisuk[3] = new Zashtitnik("Anna Ivanova", 2018, "Semeino", "Dimitrov");
    spisuk[4] = new GlavenSutrudnik("Ivan Stoyanov", 2000, "Turgovsko", "Banka X", "Obshto pravo");
    spisuk[5] = new Upravnik("Elena Nikolova", 1995, "Justice Corp", 100);

    for (int i = 0; i < BROI; i++) {
        cout << "--- Obekt " << i + 1 << " ---\n";
        spisuk[i]->printInfo();
        spisuk[i]->Godishnina();
        spisuk[i]->zapochniRabota();
        spisuk[i]->proveriStatus();
        cout << endl;
    }

    for (int i = 0; i < BROI; i++) delete spisuk[i];

    return 0;
}