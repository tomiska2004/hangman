//the find method is implemented with KMP
#include <iostream>
#include <iomanip>
#define MAX 256

class STRING
{
    char *data_;
    size_t len_;
    static const size_t npos;

public:
    STRING();
    // konstruktor
    STRING(size_t len);
    STRING(const char *s);
    // konstruktor
    STRING(const STRING &other);
    // konstruktor
    STRING(const char *s, size_t n);
    // konstruktor

    // destruktor
    ~STRING();

    // egyenlővé teszi
    STRING &operator=(const char *s);
    // egyenlővé teszi
    STRING &operator=(const STRING &other);

    // hossz
    size_t length() const;
    // hossz
    size_t size() const;
    // újraméretez
    void resize(size_t n);
    // memóriát foglal még le
    void reserve(size_t n);
    // kapacitás
    size_t capacity() const;
    // törli de nem szabadítja fel
    void clear();
    // üres-e
    bool empty() const;

    // adott adattagot ad meg a poz fgvében
    const char &operator[](size_t pos) const;
    // adott adattagot ad meg a poz fgvében
    const char &at(size_t pos) const;
    // első elem
    const char &front() const;
    // utolsó elem
    const char &back() const;

    // hozzáfűz
    STRING &operator+=(const char *s);
    // hozzáfűz
    STRING &operator+=(const STRING &other);
    // hozzáfűz
    STRING &operator+=(char c);
    // hozzáfűz a végére egy karaktert
    void push_back(char c);
    // hozzáfűz tömb
    STRING &append(const char *s);
    // hozzáfűz STRING
    STRING &append(const STRING &other);
    // hozzáfűz tömb, méret szerint
    STRING &append(const char *s, size_t n);
    // hozzáfűz STRING méret szerint
    STRING &append(const STRING &other, size_t pos, size_t n);
    // felcseréli
    void swap(STRING &other);

    // visszaadja a karakterláncot
    const char *c_str() const;
    // visszaadja a karakterláncot
    const char *data() const;
    // visszaadja a karakterláncot adott poz-tól adott poz-ig
    STRING substr(size_t pos = 0, size_t n = npos) const;

    // egyenlő-e méret és maga a tartalom
    friend bool operator==(const STRING &lhs, const STRING &rhs);
    // nem egyenlő-e méret és maga a tartalom
    friend bool operator!=(const STRING &lhs, const STRING &rhs);
    // kisebb-e  maga a tartalom
    friend bool operator<(const STRING &lhs, const STRING &rhs);
    // kisebb vagy egyenlő-e  maga a tartalom
    friend bool operator<=(const STRING &lhs, const STRING &rhs);
    // nagoybb-e  maga a tartalom
    friend bool operator>(const STRING &lhs, const STRING &rhs);
    // kíír
    friend std::ostream &operator<<(std::ostream &os, const STRING &str);
    // beolvas
    friend std::istream &operator>>(std::istream &is, STRING &str);
    friend std::istream &getline(std::istream &is, STRING &str);
    // hozzáfűz 2 STRING-et
    friend STRING operator+(const STRING &lhs, const STRING &rhs);
    // hozzáfűz 1 STRING-et 1 tömböt
    friend STRING operator+(const STRING &lhs, const char *rhs);
    // hozzáfűz 1 tömböt 1 STRING-et
    friend STRING operator+(const char *lhs, const STRING &rhs);

    // hozzáfűz elsőbe a másodikat
    void *memcpy(void *dest, const void *src, size_t n);
    // prefix tömböt hoz létre
    friend void Prefix(STRING, int *);
    // KMP kereső
    friend int find(const STRING s, const STRING minta);
    // KMP kereső
};
#include "string.cpp"