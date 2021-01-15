#include <iostream>
#include <ctime>
#include<time.h>
#include<algorithm>
using namespace std;
int k=44;
void insertionSort(int A[], int p, int r) {
    int i, j, key;

    for (j = p + 1; j <= r; j++) {
        key = A[j];
        i = j - 1;
        while (i >= p && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}
void Merge(int *a, int low, int high, int mid)
{   int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= high)
	{
		temp[k++] = a[j++];
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void MergeSort(int *a, int low, int high)//l y r
{
    int mid;
    if(low<high){
	   mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
    }

}
void InsertionMergeSort(int *a, int low, int high)//l y r
{
	int mid;
	if (low >high) return;

    if ((high-low)< k)//k
        insertionSort(a, low, high);
	else
	{   mid=(low+high)/2;
		InsertionMergeSort(a, low, mid);
		InsertionMergeSort(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int* rand_(int num) {
	int  mm;
	int* a = new int[num];
	for (int i = 0; i < num; i++) {
		mm = (1 + rand() % 1000);
		a[i] = mm;
	}
	return a;
}
int* copiar_(int* a, int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = a[i];
	}
	return arr;
}
int main()
{
    cout << "Hello world!" << endl;
    int i;
    cout<<"ingrese el el tamano "<<endl;
    cin>>i;
    //int ar[]={4,7,9,2,78,67,35,88,90,21,1};
    int *arr,*arr2,*arr3;
    arr=rand_(i);
    arr2=copiar_(arr,i);
    arr3=copiar_(arr,i);
    //printArray(arr, i);
    unsigned t0, t1,t2,t3,t4,t5;
    t0=clock();
    insertionSort(arr,0,i-1);
    t1 = clock();
    t2=clock();
    MergeSort(arr2,0,i-1);
    t3 = clock();
    t4=clock();
    InsertionMergeSort(arr3,0,i-1);
    t5 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    double time1 = (double(t3-t2)/CLOCKS_PER_SEC);
    double time2 = (double(t5-t4)/CLOCKS_PER_SEC);

    cout << "insertion Sort: " << time << endl;
    cout << "merge Sort: " << time1 << endl;
    cout << "insertionMergeSort: " << time2 << endl;
      printArray(arr2, i) ;
    return 0;
}
