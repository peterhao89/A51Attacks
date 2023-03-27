#include "Common.h"
#include <iostream>
#include <algorithm>
using namespace std;

std::vector<std::vector<int>> getAllCombinations(int totalNumber, int selectNumber)
{
    if(totalNumber<=0 || selectNumber <=0 )throw "getAllCorrelationsByHw: illegal totalNumber or selectNumber!\n";
    if (selectNumber > totalNumber)
        throw "getAllCorrelationsByHw: selectNumber > totalNumber\n";
    vector<vector<int>> hwRes;
    vector<int> actBits;
    for (auto i = 0; i < selectNumber; ++i)
        actBits.push_back(i);
    int currentAdder = selectNumber - 1;
    while (1)
    {
		currentAdder = selectNumber - 1;
        
        hwRes.push_back(actBits);
        
        while (currentAdder >= 0 && actBits[currentAdder] == totalNumber - (selectNumber - currentAdder))
        {
            --currentAdder;
        }
        if (currentAdder < 0)
            break;
        ++actBits[currentAdder];
        for (auto j = currentAdder + 1; j < actBits.size(); ++j)
        {
            actBits[j] = actBits[currentAdder] + j - currentAdder;
        }
    }
    return hwRes;
}

void printNumber2Entry(const uint64_t number, const int bitLength)
{
    cout << "(";
    for (int i = 0; i < bitLength; ++i)
    {
        cout << bit64(number, i);
        if (i != bitLength - 1)
            cout << ",";
    }
    cout << ")";
}



//void flipBitVal(uint64_t &reg, int bitNo)
//{
//    uint64_t msk = 1;
//    msk <<= bitNo;
//    reg ^= msk;
//}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
// itoa exists
#else
std::string itoa(int value, int base)
{

    std::string buf;

    // check that the base if valid
    if (base < 2 || base > 16)
        return buf;

    enum
    {
        kMaxDigits = 35
    };
    buf.reserve(kMaxDigits); // Pre-allocate enough space.

    int quotient = value;

    // Translating number to string with base:
    do
    {
        buf += "0123456789abcdef"[std::abs(quotient % base)];
        quotient /= base;
    } while (quotient);

    // Append the negative sign
    if (value < 0)
        buf += '-';

    std::reverse(buf.begin(), buf.end());
    return buf;
}

char *itoa(int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36)
    {
        *result = '\0';
        return result;
    }

    char *ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do
    {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz"[35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0)
        *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
#endif