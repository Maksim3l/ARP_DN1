#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool Branje_Stevil(vector<int>& vec, const char s[]);
void Izpis_Stevil(int* polje, unsigned int velikost);

int main(int argc, char* argv[]) {
    vector<int> Arr;

    // pridobi številke
    if (!Branje_Stevil(Arr, argv[2])) {
        cerr << "Napaka pri branju stevil iz datoteke." << endl << endl;
        return 1;
    }

    // ven
    Izpis_Stevil(&Arr[0], Arr.size());
    return 0;
}

bool Branje_Stevil(vector<int>& vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i < velikost; i++)
        output << polje[i] << ' ';
}