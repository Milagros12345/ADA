
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <ctime>
#include<utility>
#include <set>
using namespace std;
clock_t c1;
int n; vector<vector<int> > tablero;
int h[8] = { 2,1,-1,-2,-2,-1,1,2 };
int v[8] = { -1,-2,-2,-1,1,2,2,1 };

int get_degree(int x, int y) {
	int c = 0;
	for (int i = 0; i < 8; i++) {
		int a = x + h[i]; int b = y + v[i];
		if (a >= n or a < 0 or b >= n or b < 0)continue;
		if (tablero[a][b])continue;
		c++;
	}
	return c;
}
void next(int x, int y, pair<int, pair<int, int> >& c) {
	std::set<pair<int, pair<int, int>>> s;
	for (int i = 0; i < 8; i++) {
		int a = x + h[i]; int b = y + v[i];
		if (a >= n or a < 0 or b >= n or b < 0)continue;
		if (tablero[a][b])continue;
		int g = get_degree(a, b);
		pair<int, pair<int, int> >x = { g,{a,b} };
		s.insert({ g,{a,b} });
	}
	c = *s.begin();
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %2d ", tablero[i][j]);
		}
		cout << "\n";
	}
}

bool Tenta(int i, int x, int y) {
	if (i == n * n)return true;
	for (int m = 0; m < 8; m++) {
		pair<int, pair<int, int>> p;
		next(x, y, p);
		int xn = p.second.first;
		int yn = p.second.second;
		if (xn < 0 or xn >= n or yn < 0 or yn >= n)continue;
		if (tablero[xn][yn] != 0)continue;
		tablero[xn][yn] = i + 1;
		if (Tenta(i + 1, xn, yn))return true;
		tablero[xn][yn] = 0;
	}
	return false;
}

int main() {
	cin >> n;
	tablero.resize(n, vector<int>(n));
	int a, b; cin >> a >> b;
	tablero[a][b] = 1;
	c1 = clock();
	bool ok = Tenta(1, a, b);
	c1 = clock() - c1;
	if (ok)print();
	else cout << "No hay solucion!\n";
	cout << "Tiempo de ejecucion: " << c1 / (long double)CLOCKS_PER_SEC << endl;
}
