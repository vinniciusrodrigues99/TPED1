#include <iostream>
using namespace std;

void print(int t, int *a) {
	cout << "----------------------" << endl;
	for(int i=0; i<t; ++i) {
		cout << "Elemento: " << i << " = " << a[i] << endl;
	}
	cout << "----------------------" << endl;
}

void bubble_sort_recursiv(int t, int *a) {
	int aux;
		for(int j=0; j<(t-1); ++j) {
			cout << "[" << j << "]: " << a[j] << 
			        ", [" << j+1 << "]:  " << a[j+1];
			if (a[j] > a[j+1]) {
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				cout << " - Trocou!!!";
			}
			cout << endl;
		}
        if (t>1) {
			bubble_sort_recursiv(t-1, a);
		}
	
}


int main(int argc, char** argv)
{
	int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
	print(8, v);
	bubble_sort_recursiv(8, v);
	print(8, v);
	return 0;
}
