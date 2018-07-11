#include <iostream>
#include <string.h>
#define maxn 5005
using namespace std;
string str1, str2;
int table[maxn][maxn];
void init(){
	cin >> str1;
	cin >> str2;
}
void create_table(){
	int l1 = str1.length();
	int l2 = str2.length();
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l1; j++){
			if(i == 0 || j == 0){
				table[i][j] = 0;
				continue;
			}
			if(str1[i - 1] == str2[j - 1]) table[i][j] = table[i - 1][j - 1] + 1;
			if(str1[i - 1] != str2[j - 1]) table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}
}
void Run(){
	init();
	create_table();
	cout << table[str1.length()][str2.length()];
}
main(){
	Run();
	return 0;
}
