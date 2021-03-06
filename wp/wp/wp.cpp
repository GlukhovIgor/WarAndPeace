/*	Goes through all of War and peace books and prints 
in descending order the number of times word was found in the text
and prints it in the following way : 
number word1 word2 ... wordN
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <windows.h>

using namespace std;
void lower(string&);
void process(string, map<int, set<string>>&, map<string, int>&);
void printMap(map<int, set<string>>&);

int main()
{
	setlocale(LC_ALL, "russian");
	map<int, set<string>> NumWords;
	map<string, int> WordNum;
	process("WAP12.txt", NumWords, WordNum);
	process("WAP34.txt", NumWords, WordNum);
	printMap(NumWords);
	system("pause");
	return 0;
}
void lower(string& str) {
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] > 64 && str[i] < 91) || (str[i] >= 'А' && str[i] <= 'Я')) {
			str[i] += 32;
		}
	}
}
void process(string filename, map<int, set<string>> &NumWords, map<string, int> &WordNum) {
	string word;
	ifstream wp12(filename);

	if (!wp12.is_open()) {
		cerr << "wp12 wasnt opened " << endl;
	}
	else {
		while (wp12 >> word) {
			if (word.length() >= 4) {	//HERE YOU CAN CHANGE MINIMAL LENGTH OF WORDS WHICH WILL BE COUNTED
				if ((word[0] <= 96 || word[0] >= 123) && (word[0] <= 64 || word[0] >= 91) && (word[0] < 'а' || word[0] > 'я') && (word[0] < 'А' || word[0] > 'Я'))
					word = word.substr(1, word.length());
				if ((word[word.length() - 2] <= 96 || word[word.length() - 2] >= 123) && (word[word.length() - 2] <= 64 || word[word.length() - 2] >= 91) && (word[word.length() - 2] < 'а' || word[word.length() - 2] > 'я') && (word[word.length() - 2] < 'А' || word[word.length() - 2] > 'Я'))
					word = word.substr(0, word.length() - 2);
				if ((word[word.length() - 1] <= 96 || word[word.length() - 1] >= 123) && (word[word.length() - 1] <= 64 || word[word.length() - 1] >= 91) && (word[word.length() - 1] < 'а' || word[word.length() - 1] > 'я') && (word[word.length() - 1] < 'А' || word[word.length() - 1] > 'Я'))
					word = word.substr(0, word.length() - 1);
				lower(word);
				++WordNum[word];
			}
		}
	}
	if (filename == "WAP34.txt") {
		for (auto wc = WordNum.begin(); wc != WordNum.end(); wc++) {
			if (wc->second > 100)		//HERE YOU CAN CHANGE MINIMAL QUANTITY OF REPETITIONS WHICH WILL BE PRINTED
				NumWords[-wc->second].insert(wc->first);
		}
	}
}
void printMap(map<int, set<string>>& NumWords) {
	for (auto wc = NumWords.begin(); wc != NumWords.end(); wc++) {
		cout << -wc->first << " ";
		for (auto wc2 = wc->second.begin(); wc2 != wc->second.end(); wc2++) {
			cout << *wc2 << " ";
		}
		cout << endl;
	}
}