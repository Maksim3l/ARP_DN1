﻿#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

void binaryRadixSort(vector<unsigned char>& arr);
bool Branje_Stevil(vector<unsigned char>& vec, const char s[]);
void Izpis_Stevil(unsigned char* polje, unsigned int velikost);

int main(int argc, char* argv[]) {
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

void binaryRadixSort(vector<unsigned char>& arr) {
    if (arr.empty()) return;
}
