#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

double calculate_entropy(const string& text) {
    map<char, int> freq;
    for (size_t i = 0; i < text.length(); ++i) {
        freq[text[i]]++;
    }

    double entropy = 0.0;
    for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        double p = (double)it->second / text.size();
        entropy -= p * log2(p);
    }

    return entropy;
}

int main() {
    string input;
    cout << "Enter a string of characters: ";
    getline(cin, input);

    double H = calculate_entropy(input);
    cout << "Entropy: " << H << endl;

    const int N = 256;
    double max_entropy = log2(N);
    double R = max_entropy - H;

    cout << "Redundancy: " << R << endl;

    return 0;
}
