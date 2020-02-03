#include "SORT.h"
void createArr(int*&a, int n)
{
	srand(NULL);
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = rand() % RAND_MAX;
}
void copyArr(int*source, int*dest, int n)
{
	for (int i = 0; i < n; i++)
		dest[i] = source[i];
}
void equal(int* source, int* dest, int n){
	for (int i = 0; i < n; i++)
		dest[i] = source[i];
}
void sort(int*a, int n, void(*method)(int*, int))
{
	method(a,n);
}
void sort(int*a, int left,int right, void(*method)(int*,int,int))
{
	method(a,left,right);
}
void sort(int*a, int*L,int*R,int left, int right, void(*method)(int*, int*, int*,int,int))
{
	method(a,L,R,left, right);
}
void output(int*a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
}
void bubble(int*a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j]<a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void selection(int*a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i; 
		for (int j = i + 1; j < n; j++)
		{
			if (a[minIndex]>a[j])
			{
				minIndex = j;
			}
			if (minIndex != i)
			{
				int temp = a[minIndex];
				a[minIndex] = a[i];
				a[i] = temp;
			}
		}
	}
}
void insertion(int*a, int n)
{
	int key;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j]>key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}
void heapify(int*a, int n, int i)
{
	int root = i; 
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[left]>a[root])
	{
		root = left;
	}
	if (right < n&&a[right] > a[root])
	{
		root = right;
	}
	if (root != i)
	{
		int temp = a[root];
		a[root] = a[i];
		a[i] = temp;
		heapify(a, n, root);
	}
}
void heapSort(int*a, int n)
{
	for (int i = n / 2; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i,0);
	}
}
void quick(int*a, int left, int right)
{
	int mid = a[(left + right) / 2];
	int i = left;
	int j = right;
	do
	{
		while (a[i]<mid)
		{
			i++;
		}
		while (a[j]>mid)
		{
			j--;
		}
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quick(a, left, j);
	if (i < right) quick(a, i, right);
}
void merge(int*a ,int*L, int*R, int left, int right)
{
	int  mid = (left + right) / 2;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	for (int i = 0; i < n1; i++)
	{
		L[i] = a[left + i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = a[mid + 1 + j];
	}
	int i, j, k;
	i = j = 0;
	k = left;
	while (i < n1&&j < n2)
	{
		if (L[i] < R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int*a, int*L, int*R, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, L, R, left, mid);
		mergeSort(a, L, R, mid + 1, right);
		merge(a, L, R, left, right);
	}
}
void countSort(int*a, int n, int exp)
{
	int* output = (int*)malloc(n*sizeof(int));
	int count[10] = { 0 };
	for (int i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}
int getMax(int*a, int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}
void radix(int*a, int n)
{
	int max = getMax(a, n);
	for (int exp = 1; max / exp>0; exp *= 10)
	{
		countSort(a, n, exp);
	}
}
void quickReverse(int*a, int left, int right)
{
	int mid = a[(left + right) / 2];
	int i = left;
	int j = right;
	do
	{
		while (a[i] > mid)
			i++;
		while (a[j] < mid)
			j--;
		if (i <= j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)  quickReverse(a, left, j);
	if (i < right)  quickReverse(a, i, right);
}
void flash(int*a, int n)
{
	int max, min;
	max = min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int m = 0.43*n;
	int *count = new int[m + 10];
	for (int i = 0; i < m; i++)
		count[i] = 0;
	int k;
	for (int i = 0; i < n; i++)
	{
		k = ((m - 1)*(a[i] - min)) / (max - min);
		count[k]++;
	}
	for (int i = 1; i < m; i++)
		count[i] += count[i - 1];
	int i = 0;
	int x, temp;
	while (i < n)
	{
		k = (m - 1)*(a[i] - min) / (max - min);
		x = a[i];
		while (i < count[k])
		{
			temp = a[count[k] -  1];
			a[count[k] - 1] = x;
			count[k]--;
			x = temp;
			k = (m - 1)*(x - min) / (max - min);
		}
		i++;
	}
	for (int i = 0; i < m - 1; i++)
	{
		int key, k;
		for (int j = count[i]; j < count[i + 1]; j++)
		{
			key = a[j];
			k = j - 1;
			while (k >= count[i] && a[k]>key)
			{
				a[k+1] = a[k];
				k--;
			}
			a[k + 1] = key;
		}
	}
}