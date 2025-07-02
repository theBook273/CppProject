#include<bits/stdc++.h>

using namespace std;

unordered_map<string,int> mp = {{"Danil", 0}, {"Olya", 0}, {"Slava", 0}, {"Ann", 0}, {"Nikita", 0}};

int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'A' || s[i] == 'N' || s[i] == 'O' || s[i] == 'S' || s[i] == 'D') {
			string temp;
			for(int j = 0; j <= 6; ++j){
				temp += s[i + j];
				if(mp.count(temp)){
					mp[temp]++;
					break;
				}
			}
		}
	}
	int tong = 0;
	for(auto [i,j] : mp) {
		tong += j;
 	}
 	
 	if(tong == 1) cout << "YES";
 	else cout << "NO";
	return 0;
}
