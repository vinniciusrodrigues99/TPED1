#include <iostream>
//Vinnicius Oliveira Rodrigues
using namespace std;

void print(int t, int *a) {
	cout << "----------------------" << endl;
	for(int i=0; i<t; ++i) {
		cout << "Elemento: " << i << " = " << a[i] << endl;
	}
	cout << "----------------------" << endl;
}

void bubble_sort(int t, int *a) {
	int aux;
	for(int i=t-1; i>0; --i) {
		for(int j=0; j<i; ++j) {
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
	}
}

void insertion_sort(int t, int *a) {
	int aux, i, j;
	for(i=1; i<t; i++){
		aux = a[i];
		j=i-1;
		
		while(j>=0 && a[j] > aux) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=aux;
	}
}

int partition(int *a, int start, int end) {
	int index=0, pivot=a[end], i, pivotIndex;
	int* temp = new int[end-start+1];
	for(i=start; i<=end; i++) {
		if(a[i] < pivot) {
			temp[index] = a[i];
			index++;
		}
	}
	temp[index] = pivot;
	index++;
	for(i=start; i<end; i++) {
		if(a[i] > pivot) {
			temp[index] = a[i];
			index++;
		}
	}
	
	index=0;
	for(i=start; i<=end; i++) {
		if(a[i] == pivot) {
			pivotIndex = i;
		}
		a[i] = temp[index];
		index++;
	}
	return pivotIndex;
}

void quick_sort(int *a, int start, int end) {
	if(start<end) {
		int partId = partition(a, start, end);
		quick_sort(a, start, partId-1);
		quick_sort(a, partId+1, end);
	}
}

void selection_sort(int *a, int t) {
	int i, j, minId;
	
	for(i=0; i<t-1; i++) {
		minId = i;
		for(j=i+1; j<t; j++) {
			if (a[j] < a[minId]){
				minId = j;
			}
		}
		
		if(minId != i) {
			swap(a[minId],a[i]);
		}
	}
}

void merge(int *a, int const left, int const mid, int const right) {
	int const subArrayOne = mid-left+1;
	int const subArrayTwo = right-mid;
	
	int *leftArray = new int[subArrayOne];
	int *rightArray = new int[subArrayTwo];
	
	for(int i=0; i<subArrayOne; i++) {
		leftArray[i] = a[left+i];
	}
	for(int j=0; j<subArrayTwo; j++) {
		rightArray[j] = a[mid+1+j];
	}
	
	int idSubArrayOne = 0, idSubArrayTwo = 0;
	int idMergedArray = left;
	
	while(idSubArrayOne < subArrayOne && idSubArrayTwo < subArrayTwo) {
		if(leftArray[idSubArrayOne] <= rightArray[idSubArrayTwo]) {
			a[idMergedArray] = leftArray[idSubArrayOne];
			idSubArrayOne++;
		} else {
			a[idMergedArray] = rightArray[idSubArrayTwo];
			idSubArrayTwo++;
		}
		idMergedArray++;
	}
	
	while (idSubArrayOne < subArrayOne) {
		a[idMergedArray] = leftArray[idSubArrayOne];
		idSubArrayOne++;
		idMergedArray++;
	}
	
	while (idSubArrayTwo < subArrayTwo) {
		a[idMergedArray] = rightArray[idSubArrayTwo];
		idSubArrayTwo++;
		idMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void merge_sort(int *a, int const begin, int const end) {
	if(begin >= end) {
		return;
	}
	int mid = begin + (end-begin)/2;
	merge_sort(a,begin,mid);
	merge_sort(a,mid+1,end);
	merge(a, begin, mid, end);
}

void shell_sort(int *a, int t) {
	for(int gap=t/2; gap>0; gap/=2) {
		for(int i=gap; i<t; i++) {
			int temp = a[i];
			int j;
			
			for(j=i; j>= gap && a[j-gap] > temp; j -= gap) {
				a[j] = a[j-gap];
			}
			a[j] = temp;
		}
	}
}

int main(int argc, char** argv)
{
	int opcao = -1;
	int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
	print(8, v);
	do{
		cout << "0 - Bubble sort" << endl;
		cout << "1 - Insertion sort" << endl;
		cout << "2 - Quick sort" << endl;
		cout << "3 - Selection sort" << endl;
		cout << "4 - Merge sort" << endl;
		cout << "5 - Shell sort" << endl;
		cin >> opcao;
	} while(opcao<0 || opcao>5);
	
	switch(opcao){
		case 0:
			bubble_sort(8, v);
			break;
		case 1:
			insertion_sort(8, v);
			break;
		case 2:
			quick_sort(v,0,8);
			break;
		case 3:
			selection_sort(v, 8);
			break;
		case 4:
			merge_sort(v, 0, 7);
			break;
		case 5:
			shell_sort(v, 8);
			break;
	}
	
	print(8, v);
	return 0;
}
