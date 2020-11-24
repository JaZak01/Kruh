#include <iostream> // vstupne a vystupne funkcie nieco ako stdio.h
#include "Kruh.h"

int main()
{
    //Kruh Prvy;
    Kruh kruhy [3]={{3, 'a'},{7,'b'},{12,'l'}};
    Kruh Spolu {0,'s'};

    Kruh prvyKruh(3, 'a');
    Kruh &odkazKruh = prvyKruh;

    Kruh A(3, 'a');
    Kruh B(6, 'b');
    //Kruh::vymenKruhy(&A,&B);
    //Kruh::vymenKruhy(A,B);
    Kruh C = A+B; //C=A.operator+(B);
    ++C;
    std::cout<<(A<B);
    C.vypisKruh();
    (++C).vypisKruh();
    (C++).vypisKruh();
    (--C).vypisKruh();
    (C--).vypisKruh();
    C+=2;
    C-=3;
    C*=3;
    C/=3;

    /*for (auto i:kruhy)
    {
        Spolu=Spolu.spocitaj(kruhy[i]);
    }
    Spolu.vypisKruh();
    Spolu.vydel(3).vypisKruh();*/
    Kruh spoluNew (0, 'l');
    for(auto i:kruhy)
    {
        spoluNew=spoluNew.spocitaj(&i);
    }
    spoluNew.vypisKruh();

    //Kruh *pKruh = (Kruh *)malloc(sizeof(Kruh));
    Kruh *pKruh = new Kruh(0, 'p');
    //int *pole = new int[10];
    for(auto i:kruhy)
    {
        *pKruh=pKruh->spocitaj(&i);
    }
    pKruh->vypisKruh();


    //delete []pole;
    delete pKruh;


    //Spolu.vypisKruh();
    //Spolu.vydel(3).vypisKruh();
    //Kruh::PI;
    //Spolu.pripocitaj (13).vypisKruh();

    Kruh::getMax(kruhy, 3).vypisKruh();
    return 0;
    /*Prvy.setNazov('k');
    //   Prvy.setPolomer(5);
    Prvy.vypisKruh();
    std::cout<<"Obvod kruhu je: "<<Prvy.getObvod()<<std::endl;
    std::cout<<"obsah kruhu je: "<<Prvy.get()<<std::endl; zle;;;;;;;
    Kruh Druhy (8,'m');
    Kruh Treti('h');
    Kruh Stvrty(14.0f);
    std::cout<<Prvy.jeVacsi(Druhy);
    Prvy.spocitajKruh(Druhy).vypisKruh();
    Prvy.vydel(5).vypisKruh();
    return 0;*/
}
Kruh::Kruh()
{
    std::cout<<"Zadaj polomer: ";
    std::cin>>polomer;
    std::cout<<"Zadaj mazov: ";
    std::cin>>nazov;
}

Kruh::Kruh(char mojNazov)
{
    nazov=mojNazov;
    std::cout<<"Zadaj polomer: ";
    std::cin>>polomer;
}

Kruh::Kruh(float mojPolomer)
{
    polomer=mojPolomer;
    std::cout<<"Zadaj mazov: ";
    std::cin>>nazov;

}

bool Kruh::jeVacsi(const Kruh &otherKruh) const
{
    return polomer>otherKruh.polomer;
    // return (polomer>otherKruh.polomer)?true:false;
}

Kruh Kruh::getMax(Kruh *pole, int pocet)
{
    Kruh max = pole[0];
    for(int i=0; i <pocet;++i)
    {
        if(pole[i].jeVacsi(max))
        {
            max=pole[i];
        }
    }

    return max;
    // return (polomer>otherKruh.polomer)?true:false;
}

Kruh Kruh::spocitaj(const Kruh &other) const
{
    return {polomer+other.polomer, (polomer>other.polomer)?nazov:other.nazov};
}
Kruh Kruh::pripocitaj(float cislo) const
{
    //return Kruh{polomr+cislo,nazov};
    return {polomer+cislo,nazov};
}

Kruh Kruh::vydel(float cislo) const
{
    return {polomer/cislo,nazov};
}
Kruh::Kruh(float mojPolomer, char mojNazov)
{
    polomer=mojPolomer;
    nazov=mojNazov;
}

#
char Kruh::getNazov() const
{
    return nazov;
}
void Kruh::setPolomer(float mojPolomer)
{
    //this->
    polomer=mojPolomer;
}
void Kruh::setNazov(char mojNazov)
{
    nazov=mojNazov;
}
float Kruh::getObvod() const
{
    return 2*PI*polomer;
}
float Kruh::getObsah() const
{
    return PI*polomer*polomer;
}
void Kruh::vypisKruh() const
{
    std::cout << "Kruh " <<nazov <<" ma polomer "<<polomer<<std::endl;
}

bool Kruh::jeVacsi(const Kruh *otherKruh) const
{
    return polomer>otherKruh->polomer;
}

Kruh Kruh::spocitaj(const Kruh *otherKruh)const
{
    return {polomer+otherKruh->polomer, (polomer>otherKruh->polomer)?nazov:otherKruh->nazov};
}
void Kruh::vymenKruhy(Kruh *prvy, Kruh *druhy)
{
    Kruh temp;
    temp= *prvy;
    *prvy=*druhy;
    *druhy=temp;
}

void Kruh::vymenKruhy(Kruh &prvy, Kruh &druhy)
{
    Kruh temp;
    temp=prvy;
    prvy=druhy;
    druhy=temp;
}

Kruh Kruh::operator+(const Kruh & inyKruh) const
{
    return {polomer+inyKruh.polomer, (polomer>inyKruh.polomer)?nazov:inyKruh.nazov};
}

bool Kruh::operator>(const Kruh& inyKruh) const
{
    return polomer>inyKruh.polomer;
}

bool Kruh::operator<(const Kruh& inyKruh) const
{
    return polomer<inyKruh.polomer;
}

Kruh Kruh::operator/(float cislo) const
{
    return {polomer/cislo,nazov};
}

Kruh Kruh::operator-(const Kruh &inyKruh) const
{
    return {polomer<=inyKruh.polomer?1:polomer-inyKruh.polomer, 'k'};
}

Kruh Kruh::operator*(float cislo) const
{
    return {polomer*cislo,nazov};
}

const Kruh &Kruh::operator++()
{
    ++polomer;
    return *this;
}

Kruh Kruh::operator++(int nepotrebna)
{
    Kruh Tmp = *this;
    ++polomer;
    return Tmp;
}

const Kruh &Kruh::operator--()
{
    polomer = (polomer-1<=0)?1:polomer-1;
    return *this;
}

Kruh Kruh::operator--(int nepotrebny)
{
    Kruh Tmp = *this;
    polomer = (polomer-1<=0)?1:polomer-1;
    return Tmp;
}

const Kruh &Kruh::operator+=(float cislo)
{
    polomer = (polomer-cislo<=0)?1:polomer-cislo;
    return *this;
}

