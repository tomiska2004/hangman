//the find method is implemented with KMP
#include <iostream>
#include <cstdio>
#include <iomanip>
int pref[MAX];
using namespace std;
// konstruktor
STRING::STRING() : len_(0), data_(new char[MAX]) {} // konstruktor
// konstruktor
STRING::STRING(size_t len) : len_(len), data_(new char[MAX]) {} // konstruktor
// konstruktor
STRING::STRING(const char *s) : len_(std::strlen(s))
{ // konstruktor
    data_ = new char[len_ + 1];
    memcpy(data_, s, len_ + 1);
}
// konstruktor
STRING::STRING(const STRING &other) : len_(other.len_)
{ // konstruktor
    data_ = new char[other.len_ + 1];
    // cout<<other.len_;
    memcpy(data_, other.data_, other.len_ + 1);
}
// k
STRING::STRING(const char *s, size_t n) : len_(n), data_(new char[n + 1])
{ // konstruktor
    memcpy(data_, s, n);
    // cout<<s;
    data_[n] = '\0';
}

// destructor
STRING::~STRING()
{
    delete[] data_;
}

// egyenlővé teszi
STRING &STRING::operator=(const char *s)
{
    delete[] data_;
    len_ = std::strlen(s);
    data_ = new char[len_ + 1];
    memcpy(data_, s, len_ + 1);
    return *this;
}
// egyenlővé teszi
STRING &STRING::operator=(const STRING &other)
{
    if (this != &other)
    {
        delete[] data_;
        len_ = other.len_;
        data_ = new char[len_ + 1];
        memcpy(data_, other.data_, len_ + 1);
    }
    return *this;
}

// hossz
size_t STRING::length() const
{
    return len_;
}
// hossz
size_t STRING::size() const
{
    return len_;
}
// újraméretez
void STRING::resize(size_t n)
{
    if (n > len_)
    {
        char *new_data = new char[n + 1];
        memcpy(new_data, data_, len_ + 1);
        delete[] data_;
        data_ = new_data;
    }
    len_ = n;
}
// memóriát foglal még le
void STRING::reserve(size_t n)
{
    if (n > len_)
    {
        char *new_data = new char[n + 1];
        memcpy(new_data, data_, len_ + 1);
        delete[] data_;
        data_ = new_data;
    }
}
// kapacitás
size_t STRING::capacity() const
{
    return len_;
}
// törli de nem szabadítja fel
void STRING::clear()
{
    delete[] data_;
    len_ = 0;
    data_ = nullptr;
}
// üres-e
bool STRING::empty() const
{
    return len_ == 0;
}

// adott adattagot ad meg a poz fgvében
const char &STRING::operator[](size_t pos) const
{
    return data_[pos];
}
// adott adattagot ad meg a poz fgvében
const char &STRING::at(size_t pos) const
{
    if (pos >= len_)
    {
        throw std::out_of_range("STRING::at");
    }
    return data_[pos];
}
// első elem
const char &STRING::front() const
{
    return data_[0];
}
// utolsó elem
const char &STRING::back() const
{
    return data_[len_ - 1];
}

// hozzáfűz
STRING &STRING::operator+=(const char *s)
{
    size_t new_len = std::strlen(s);
    char *new_data = new char[len_ + new_len + 1];
    memcpy(new_data, data_, len_);
    memcpy(new_data + len_, s, new_len + 1);
    delete[] data_;
    len_ += new_len;
    data_ = new_data;
    return *this;
}
// hozzáfűz
STRING &STRING::operator+=(const STRING &other)
{
    return *this += other.data_;
}
// hozzáfűz
STRING &STRING::operator+=(char c)
{
    char temp[2] = {c, '\0'};
    return *this += temp;
}

// hozzáfűz a végére egy karaktert
void STRING::push_back(char c)
{
    *this += c;
}

// hozzáfűz tömb
STRING &STRING::append(const char *s)
{
    return *this += s;
}
// hozzáfűz STRING
STRING &STRING::append(const STRING &other)
{
    return *this += other;
}
// hozzáfűz tömb méret szerint
STRING &STRING::append(const char *s, size_t n)
{
    char *temp = new char[n + 1];
    memcpy(temp, s, n);
    temp[n] = '\0';
    *this += temp;
    delete[] temp;
    return *this;
}
// hozzáfűz STRING méret szerint
STRING &STRING::append(const STRING &other, size_t pos, size_t n)
{
    return append(other.data_ + pos, n);
}
// felcseréli
void STRING::swap(STRING &other)
{
    
    size_t tmp = len_;
    len_ = other.len_;
    other.len_ = tmp;
    char *tmpp = new char[len_ + 1];
    tmpp = data_;
    data_ = other.data_;
    other.data_ = tmpp;
}

// visszaadja a karakterláncot
const char *STRING::c_str() const
{
    return data_;
}
// visszaadja a karakterláncot
const char *STRING::data() const
{
    return data_;
}
// visszaadja a karakterláncot adott poz-tól adott poz-ig
STRING STRING::substr(size_t pos, size_t n) const
{
    if (pos > len_)
    {
        throw std::out_of_range("STRING::substr");
    }

    return STRING(data_ + pos, std::min(n, len_ - pos));
}

// egyenlő-e méret és maga a tartalom
bool operator==(const STRING &lhs, const STRING &rhs)
{
    return lhs.len_ == rhs.len_ && std::strcmp(lhs.data_, rhs.data_) == 0;
}
// nem egyenlő-e méret és maga a tartalom
bool operator!=(const STRING &lhs, const STRING &rhs)
{
    return !(lhs == rhs);
}
// kisebb-e  maga a tartalom
bool operator<(const STRING &lhs, const STRING &rhs)
{
    return std::strcmp(lhs.data_, rhs.data_) < 0;
}
// kisebb vagy egyenlő-e  maga a tartalom
bool operator<=(const STRING &lhs, const STRING &rhs)
{
    return !(rhs < lhs);
}
// nagoybb-e  maga a tartalom
bool operator>(const STRING &lhs, const STRING &rhs)
{
    return rhs < lhs;
}
// kíír
std::ostream &operator<<(std::ostream &os, const STRING &str)
{
    return os << str.data_;
}
// beolvas
std::istream &operator>>(std::istream &is, STRING &str)
{

    

    char karakter = getchar();
    while (karakter != '\n' && karakter != '\0')
    {
        str.len_++;
        if (str.len_ > str.capacity())
        {
            str.reserve(str.len_);
        }
        str.data_[str.len_ - 1] = karakter;

        karakter = getchar();
    }
    str.data_[str.len_] = '\0';
    return is;
}
std::istream &getline(std::istream &is, STRING &str)
{
    str.clear(); // töröl
    char c;
    while (is.get(c) && c != '\n')
    {
        str.push_back(c);
    }
    return is;
}

// hozzáfűz 2 STRING-et
STRING operator+(const STRING &lhs, const STRING &rhs)
{
    STRING result = lhs;
    result += rhs;
    return result;
}
// hozzáfűz 1 STRING-et 1 tömböt
STRING operator+(const STRING &lhs, const char *rhs)
{
    STRING result = lhs;
    result += rhs;
    return result;
}
// hozzáfűz 1 tömböt 1 STRING-et
STRING operator+(const char *lhs, const STRING &rhs)
{
    STRING result(lhs);
    result += rhs;
    return result;
}

// hozzáfűz elsőbe a másodikat
void *STRING::memcpy(void *dest, const void *src, size_t n)
{
    char *d = static_cast<char *>(dest);
    const char *s = static_cast<const char *>(src);
    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }
    return dest;
}

void Prefix(STRING minta, int pref[])
{
    int k = 0;
    pref[0] = 0;
    for (int i = 1; i < minta.length(); i++)
    {
        while (k > 0 && minta.data_[k] != minta.data_[i])
            k = pref[k - 1];
        if (minta.data_[k] == minta.data_[i])
            k++;
        pref[i] = k;
    }
}

int find(const STRING s, const STRING minta)
{
    int pref[minta.length() + 1];
    int k = 0;
    Prefix(minta, pref);
    for (int i = 0; i < s.length(); i++)
    {
        while (k > 0 && minta.data_[k] != s.data_[i])
            k = pref[k - 1];
        if (minta.data_[k] == s.data_[i])
            k++;
        if (k == minta.length())
            return i - minta.length() + 1;
    }
    return -1;
}

