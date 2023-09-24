#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string bruteForce(unordered_map<string, int>& words) {
    ifstream file;
    file.open("words.txt");

    if (!file.is_open()) {
        cout << "Nepodarilo se soubor otevrit" << endl;
    }

    string mode;
    int maxFrequency = 0;
    string word;

    while (file >> word) {
        words[word]++;

        if (words[word] > maxFrequency) {
            maxFrequency = words[word];
            mode = word;
        }
    }

    file.close();
    return mode;
}

string presortMode(vector<string> &wordsPresort, int &modeFrequency) {
    ifstream file;
    file.open("words.txt");

    if (!file.is_open()) {
        cout << "Nepodarilo se soubor otevrit" << endl;
    }

    string word;

    while (file >> word) {
        wordsPresort.push_back(word);
    }

    sort(wordsPresort.begin(), wordsPresort.end());

    int i = 0;
    modeFrequency = 0;
    string modeValue;

    while (i <= wordsPresort.size() - 1) {
        int runLenght = 1;
        string runValue = wordsPresort[i];
        while (i + runLenght <= wordsPresort.size()-1 && wordsPresort[i + runLenght] == runValue) {
            runLenght += 1;
        }
        if (runLenght > modeFrequency) {
            modeFrequency = runLenght;
            modeValue = runValue;
        }
        i = i + runLenght;
    }

    return modeValue;
}

    

int main() {

    unordered_map<string, int> words;
  
    string mode = bruteForce(words);
    vector<string> wordsPresort;
    int modeFrequency;

    cout << "Brute force: " << endl << endl;
    if (!mode.empty()) {
        cout << "Modus je: " << mode << endl;
        cout << "Pocet vyskytu: " << words[mode] << endl;
        cout << "-------------------------------------------------" << endl << endl;
    }
    
    cout << "Presort mode: " << endl << endl;
    cout << "Modus je: " << presortMode(wordsPresort, modeFrequency) << endl;
    cout << "Pocet vyskytu: " << modeFrequency;

    return 0;
}
