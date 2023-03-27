#pragma once
#include <stdint.h>
#include <vector>
#include <set>
#include<string>
#include<bitset>
#include<iostream>
#define bit64(x, n) (((x) >> (n)) & 1)
#define bitW64(x, n) (((x[(n) / 64]) >> ((n) % 64)) & 1)

#define LROT32(x, s) (((x) << (s)) | ((x) >> (32 - (s))))
#define RROT32(x, s) (((x) >> (s)) | ((x) << (32 - (s))))
#define LROT64(x, s) (((x) << (s)) | ((x) >> (64 - (s))))
#define RROT64(x, s) (((x) >> (s)) | ((x) << (64 - (s))))


#define LROTW(x, s, w) (((x) << (s)) | ((x) >> ((w) - (s))))
#define RROTW(x, s, w) (((x) >> (s)) | ((x) << ((w) - (s))))


std::vector<std::vector<int>> getAllCombinations(int totalNumber, int selectNumber);

template<typename T>
T cyclicRotateLeft(T word, unsigned n) {
    unsigned bitLen=8*sizeof(T);
    return ((word << n) | (word >> (bitLen - n)));
}

template<typename T>
T cyclicRotateRight(T word, unsigned n) {
    unsigned bitLen = 8 * sizeof(T);
    return ((word >> n) | (word << (bitLen - n)));
}

template <class T>
void rotateOnceLow2High(std::vector<T> &in)
{
    auto length = in.size();
    T tmp = in[length - 1];
    for (auto i = length - 1; i >= 1; --i)
    {
        in[i] = in[i - 1];
    }
    in[0] = tmp;
}

template <class T>
void rotateLow2High(std::vector<T> &in, const int rotNumber)
{
    for (int i = 0; i < rotNumber; ++i)
        rotateOnceLow2High(in);
}

template <class T>
void rotateOnceHigh2Low(std::vector<T> &in)
{
    T tmp = in[0];
    for (auto i = 0; i < in.size() - 1; ++i)
    {
        in[i] = in[i + 1];
    }
    in[in.size() - 1] = tmp;
}

template <class T>
void rotateHigh2Low(std::vector<T> &in, int rotNumber)
{
    for (int i = 0; i < rotNumber; ++i)
        rotateOnceHigh2Low(in);
}
template <typename T>
inline void setBitVal(T &word, const int bitNum, const int val)
{
    T mask = 1;
    mask <<= bitNum;
    if (val == 0)
    {
        mask = ~mask;
        word &= mask;
    }
    else
    {
        word |= mask;
    }
}
inline uint64_t innerProduct(const uint64_t a, const uint64_t b, const int bitNum = 64)
{
    uint64_t product = 0;
    for (int i = 0; i < bitNum; ++i)
    {
        product ^= (bit64(a, i) & bit64(b, i));
    }
    return product;
}

template<size_t BitLen>
inline uint64_t innerProduct(const std::bitset<BitLen> a, const std::bitset<BitLen> b) {
    std::bitset<BitLen> andRes = a & b;
    uint64_t res = 0;
    for (auto j = 0; j < BitLen; ++j) {
        res ^= andRes[j];
    }
    return res;
}


template <typename T>
T gcd(T m, T n)
{
    T r, t;
    if (m < n)
    {
        t = m;
        m = n;
        n = t;
    }
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

template <typename T>
T gcd(const std::vector<T> mm)
{
    if (mm.empty())
        throw "gcd: no input!\n";
    if (mm.size() == 1)
        return mm[0];
    T div = mm[0];
    for (auto i = 1; i < mm.size(); ++i)
    {
        div = gcd(div, mm[i]);
    }
    return div;
}

template <typename T>
bool isEqual(T *vec0, T *vec1, int vecLen)
{
    bool equal = true;
    for (int i = 0; i < vecLen; ++i)
    {
        if (vec0[i] != vec1[i])
        {
            equal = false;
            break;
        }
    }
    return equal;
}

template <typename T>
bool isGreaterThan(T *vec0, T *vec1, int vecLen)
{
    bool equal = isEqual(vec0, vec1, vecLen);
    if (equal)
        return false;
    bool greaterThan = true;
    ;
    for (int i = 0; i < vecLen; ++i)
    {
        if (vec0[i] > vec1[i])
        {
            return true;
        }
        else if (vec0[i] < vec1[i])
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    throw "isGreaterThan: Illegal defined!";
}

template <typename T>
bool isLessThan(T *vec0, T *vec1, int vecLen)
{
    bool equal = isEqual(vec0, vec1, vecLen);
    if (equal)
        return false;
    for (int i = 0; i < vecLen; ++i)
    {
        if (vec0[i] < vec1[i])
        {
            return true;
        }
        else if (vec0[i] > vec1[i])
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    throw "isLessThan: Illegal defined!";
}

template <class T>
std::vector<T> uniqueVec(std::vector<T> raw)
{
    std::set<T> uSet;
    std::vector<T> vec;
    for (auto i = 0; i < raw.size(); ++i)
    {
        uSet.insert(raw[i]);
    }
    for (auto ite = uSet.begin(); ite != uSet.end(); ++ite)
    {
        vec.push_back(*ite);
    }
    return vec;
}

void printNumber2Entry(const uint64_t number, const int bitLength);

//void flipBitVal(uint64_t &reg, int bitNo);
template<typename T>
void flipBitVal(T& reg, int bitNo) {
    T msk = 1;
    msk <<= bitNo;
    reg ^= msk;
}

inline uint64_t maj(const uint64_t a, const uint64_t b, const uint64_t c)
{
    return ((a & b) ^ (b & c) ^ (a & c));
}

// extend Euclidian
// d=gcd(a,b)=a*x+b*y
inline void ext_gcd(int64_t a, int64_t b, int64_t &d, int64_t &x, int64_t &y)
{
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
        return;
    }
    ext_gcd(b, a % b, d, y, x);
    y -= a / b * x;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    //itoa exists
#else

/**
 * C++ version 0.4 std::string style "itoa":
 * Contributions from Stuart Lowe, Ray-Yuan Sheu,

 * Rodrigo de Salvo Braz, Luc Gallant, John Maloney
 * and Brian Hunt
 */
std::string itoa(int value, int base);

/**
* C++ version 0.4 char* style "itoa":
* Written by Lukás Chmela
* Released under GPLv3.

*/
char* itoa(int value, char* result, int base);
#endif


template<size_t Length>
struct CompareBitset {
    bool operator()(std::bitset<Length>  a, std::bitset<Length>  b) const {
        bool result = false;
        for (auto i = Length; i > 0; --i) {
            if (a[i - 1] == b[i - 1])continue;
            else {
                result = (a[i - 1] < b[i - 1]);
                break;
            }
        }
        return result;
    }
};


template<typename T>
std::string toHexStr(T num) {
    int bitLen = sizeof(T) * 8;
    std::string hexes[16] = { "0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f" };
    std::string outStr="";
    for (auto nibble = 0; nibble < bitLen / 4; ++nibble) {
        T cur = (num >> (4 * nibble))&0xf;
        outStr = hexes[cur]+ outStr;
    }
    outStr = "0x" + outStr;
    return outStr;
}


template <typename T>
void showNumeric(T x, std::ostream & o=std::cout)
{
    int bitLen = sizeof(T) * 8;
    for (auto bt = bitLen - 1; bt >= 0; --bt)
    {
        if (bit64(x, bt) == 1)
        {
            o << std::dec << bt << ",";
        }
    }
}

template<typename T>
void showNumericState(std::vector<T> x, std::ostream& o = std::cout) {
    for (auto j = 0; j < x.size(); ++j)
    {
        if (x[j] != 0)
        {
            o << std::dec << j << ":";
            showNumeric(x[j],o);
            o << std::endl;
        }
    }
    o << std::endl;
}

template <typename T>
bool isVecZero(std::vector<T> a)
{
    bool res = true;
    for (auto i = 0; i < a.size(); ++i)
    {
        if (a[i] != 0)
        {
            res = false;
            break;
        }
    }
    return res;
}



