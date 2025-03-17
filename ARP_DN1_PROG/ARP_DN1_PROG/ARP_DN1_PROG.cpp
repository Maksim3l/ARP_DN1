﻿#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int getVecMax(vector<int>& vec);
void countingSort(vector<int>& arr);
void binaryRadixSort(vector<unsigned char>& arr);
bool Branje_Stevil(vector<unsigned char>& vec, const char s[]);
void Izpis_Stevil(unsigned char* polje, unsigned int velikost);

int main(int argc, char* argv[]) {
    //Uporaba tipa: unsigned char
    vector<unsigned char> Arr;

    // Error handling
    if (argc != 2) {
        cerr << endl << "Uporaba: " << argv[0] << endl << "- <vhodna datoteka>" << endl << endl;
        return 1;
    }

    // pridobi številke
    if (!Branje_Stevil(Arr, argv[1])) {
        cerr << "Napaka pri branju stevil iz datoteke." << endl << endl;
        return 1;
    }

    binaryRadixSort(Arr);

    // ven
    Izpis_Stevil(&Arr[0], Arr.size());
    return 0;
}

bool Branje_Stevil(vector<unsigned char>& vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (input >> st) {
        if (st >= 0 && st <= 255) {
            vec.push_back(static_cast<unsigned char>(st));
        }
        else {
            cerr << "Warning: Number " << st << " is out of range for unsigned char." << endl;
        }
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(unsigned char* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i < velikost; i++)
        output << static_cast<int>(polje[i]) << ' ';
}

int getVecMax(vector<int>& vec) {
    int maxNum = vec[0];

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > maxNum) {
            maxNum = vec[i];
        }
    }

    return maxNum;
}

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxVecNum = getVecMax(arr);
    vector<int> helperC(maxVecNum + 1, 0);
    vector<int> sortedB(arr.size(), 0);

    for (size_t i = 0; i < arr.size(); ++i) {
        helperC[arr[i]] = helperC[arr[i]] + 1;
    }

    for (size_t i = 1; i <= maxVecNum; ++i) {
        helperC[i] = helperC[i] + helperC[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        sortedB[helperC[arr[i]] - 1] = arr[i];
        helperC[arr[i]] = helperC[arr[i]] - 1;
    }

    arr = sortedB;
}

void binaryRadixSort(vector<unsigned char>& arr) {
    if (arr.empty()) return;

    // Od polja vhodnih števil A vzemite od vsakega števila k-ti bit (k je na
    // začetku 0).Tako dobite polje bitov D

    // 1. korak: za vsak A[i] velja C[(A[i] >> k) & 1]++

    // Dostop do k - tega bita števila A[i]:
    // bool bit = (A[i] >> k) & 1;

    vector<unsigned char> helperC(arr.size(), 0);

    for (int k = 0; k < 8; k++) {
        for (int i = 0; i < arr.size() - 1; i++) {
            helperC[(arr[i] >> k) & 1]++;

            cout << ((arr[i] >> k) & 1) << "\n";
        }
        cout << "______\n";
    }
       
    // Bite (polje D) sortirajte s stabilnim algoritmom za sortiranje
    // (najboljše counting sort)

    // Glede na indekse sortiranih bitov popravite vrstni red števil
    // v A(tako velja i == j, za A[i] in D[j]).

    // Indeks k inkrementirate in se vrnete na prvi korak.Postopek
    // ponovite še 7 - krat saj sortiramo 8 - bitna števila.
    // k = 1



    // 2. korak(prefix sum) : C[1] += C[0]
    // 3. korak : B[--C[(A[i] >> k) & 1]] = A[i]
    // 4. Imamo sortirano polje A po k - tem bitu v polju B.Zamenjamo
    //  kazalca od polj : std::swap(A, B)

    /*
    1. Od polja vhodnih števil A vzamite od vsakega števila k-ti bit (k je na začetku 0). Tako
        dobite polje bitov D.
    2. Bite (polje D) sortirajte s stabilnim algoritmom za sortiranje (najboljše counting
        sort).
    3. Glede na indekse sortiranih bitov popravite vrstni red števil v A (tako velja i == j,
        za A[i] in D[j]).
    4. Indeks k inkrementirate in se vrnete na prvi korak. Postopek ponovite še 7-krat saj
        sortiramo 8-bitna števila
    */

}
/*



• Izpis bitov števila A[i]:
• for(int k=0;k<8;k++)
std::cout<<( (A[i] >> k) & 1) <<"\n";
• Namig:
• V vsakem prehodu skozi korake 1-3 je možno urediti števila v polju A tudi brez uporabe
polja D, saj so vse vrednosti v polju D neposredno dostopne iz polja A

*/