#ifndef KRUH_KRUH_H
#define KRUH_KRUH_H

class Kruh
{
private:
    static constexpr float PI{3.14}; //PI=3,14
    float polomer;
    char nazov;
public:
// konstruktor, par pol a obsah
    static Kruh getMax(Kruh pole[], int pocet);
    static void vymenKruhy(Kruh *prvy, Kruh *druhy);
    static void vymenKruhy(Kruh &prvy, Kruh &druhy);
    Kruh(float mojPolomer, char mojNazov);
    Kruh ();
    explicit Kruh(float mojPolomer);
    explicit Kruh (char mojNazov);

    float getPolomer() const;
    char getNazov() const;
    void setPolomer(float mojPolomer);
    void setNazov (char mojNazov);
    float getObvod() const;
    float getObsah() const;
    void vypisKruh() const;
    bool jeVacsi(const Kruh &otherKruh) const;
    bool jeVacsi(const Kruh *otherKruh) const;
    bool operator>(const Kruh& inyKruh) const;
    bool operator<(const Kruh& inyKruh) const;
    Kruh spocitaj(const Kruh &other) const;
    Kruh operator+(const Kruh & inyKruh) const;
    Kruh spocitaj(const Kruh *otherKruh) const;
    Kruh operator-(const Kruh &inyKruh) const;
    Kruh vydel(float cislo) const;
    Kruh operator/(float cislo) const;
    Kruh pripocitaj(float cislo) const;
    Kruh operator*(float cislo) const;
    const Kruh &operator++();
    Kruh operator++(int nepotrebna);
    const Kruh & operator--();
    Kruh operator--(int nepotrebny);
    const Kruh & operator+=(float cislo);
    const Kruh & operator-=(float cislo);




// metoda kruh:: pricitajKruh (kruh otherkruh)  const;

};





#endif //KRUH_KRUH_H