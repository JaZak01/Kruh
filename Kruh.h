#ifndef KRUH_KRUH_H
#define KRUH_KRUH_H

class Kruh
{
private:
    static constexpr float PI{3.14};
    float polomer;
    char nazov;
    void random();

public:
    class noNumber
    {
    private:
        const char * msg;
    public:
        noNumber(const char * sprava):msg(sprava){};
        void getMsg() const;

    };

    class noZero
    {
    private:
        const char * msg;
    public:
        noZero(const char * sprava):msg(sprava){};
        void getMsg() const;

    };

    class noNegative
    {
    private:
        const char * msg;
    public:
        noNegative(const char * sprava):msg(sprava){};
        void getMsg() const;

    };
    static Kruh getMax(Kruh pole[],int pocet);
    static void vymenKruhy(Kruh *prvy, Kruh *druhy);
    static void vymenKruhy(Kruh &prvy, Kruh &druhy);
    static float getfloat(bool noZero= false, bool noNegative= false);
    Kruh(float mojPolomer, char mojNazov);
    Kruh ();
    explicit Kruh(float mojPolomer);
    explicit Kruh (char mojNazov);
    static void sortovanie(Kruh pole[], int pocet);



    float getPolomer() const;
    char getNazov() const;
    void setPolomer(float mojPolomer);
    void setNazov (char mojNazov);
    float getObvod() const;
    float getObsah() const;
    //void vypisKruh() const;
    //bool jeVacsi(const Kruh &otherKruh) const;
    //bool jeVacsi(const Kruh *otherKruh) const;
    bool operator>(const Kruh &inyKruh) const;
    bool operator<(const Kruh &inyKruh) const;
    //Kruh spocitaj(const Kruh &other)const;
    Kruh operator+(const Kruh & inyKruh) const;
    Kruh operator-(const Kruh & inyKruh) const;
    //Kruh spocitaj(const Kruh *otherKruh) const;
    //Kruh vydel(float cislo)const;
    Kruh operator/(float cislo) const;
    Kruh operator*(float cislo) const;
    Kruh operator+(float cislo) const;
    friend Kruh operator+(float cislo, const Kruh & other);
    friend Kruh operator*(float cislo, const Kruh & other);
    friend std::ostream & operator<<(std::ostream & os,const Kruh & other);
    friend std::istream & operator>>(std::istream & is, Kruh & other);
    const Kruh &operator++();
    Kruh operator++(int nepotrebna);
    const Kruh & operator--();
    Kruh operator--(int nepotrebny);
    const Kruh & operator+=(float cislo);
    const Kruh & operator-=(float cislo);
    const Kruh & operator*=(float cislo);
    const Kruh & operator/=(float cislo);
    //Kruh pripocitaj(float cislo) const;
    static void generujKruh(Kruh * pole, int pocet);
    static Kruh * generuj(int pocet);
    static void vypisKruhy(const Kruh * pole,int pocet);

// metoda kruh:: pricitajKruh (kruh otherkruh)  const;


};



#endif