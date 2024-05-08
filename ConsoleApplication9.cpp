#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;




int main() {
	
	string s = "", t = "";

	cin >> s;
	cin >> t;
	vector<char> letrasS;
	vector<char> letrasT;
	

	for (int i = 0; i < s.length(); i++) {
		letrasS.push_back(s[i]);
	}
	for (int i = 0; i < t.length(); i++) {
		letrasT.push_back(t[i]);
	}
	int i = 0;
	while(i < letrasS.size()) {

		if (i == 0 && letrasS[i] == '#') {
			letrasS.erase(letrasS.begin() + i);
		}

		else if (i > 0 && letrasS[i] == '#') {

			letrasS.erase(letrasS.begin() + i);
			letrasS.erase(letrasS.begin() + (i - 1));
			i--;
		}
		else {
			i++;
		}
		
	}

	int it = 0;
	while (it < letrasT.size()) {

		if (it == 0 && letrasT[it] == '#') {
			letrasT.erase(letrasT.begin() + it);
		}

		else if (it > 0 && letrasT[it] == '#') {

			letrasT.erase(letrasT.begin() + it);
			letrasT.erase(letrasT.begin() + (it - 1));
			it--;
		}
		else {
			it++;
		}

	}

	string newS(letrasS.begin(), letrasS.end());
	string newT(letrasT.begin(), letrasT.end());

	if (letrasS == letrasT) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	

	

	


}