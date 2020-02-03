#include "SORT.h"
#include <conio.h>
#include <time.h>
#include <fstream>
int main()
{
	
	ofstream outFile;
	outFile.open("descendingData.csv", ios::out);
	outFile << "  ,Bubble,Selection,Insertion,Heap,Quick,Merge,Radix,Flash \n";
	int size[6] = { 100, 1000, 5000, 10000, 50000, 100000 };
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		outFile << size[i] << ",";
		cout << "Size of Data: " << size[i] << endl;
		//random data
		//srand(NULL);
		int*a = new int[size[i]];
		createArr(a, size[i]);	
		//quick(a, 0, 99);
		//quickReverse(a,0,99);
		//progress on tempArr
		int*temp = new int[size[i]];
		//Bubble
		equal(a, temp, size[i]);
		clock_t start1 = clock();
		sort(temp, size[i], bubble);
		clock_t finish1 = clock();
		cout << "Time of Bubble Sort: " << (finish1 - start1) << endl;
		outFile << (finish1 - start1 )<< ",";
	
		//Selection
		equal(a, temp, size[i]);
		clock_t start2 = clock();
		sort(temp, size[i], selection);
		clock_t finish2 = clock();
		cout << "Time of Selection Sort: " << (finish2 - start2) << endl;
		outFile << (finish2 - start2) << ",";
	
		//Insertion
		equal(a, temp, size[i]);
		clock_t start3 = clock();
		sort(temp, size[i],insertion);
		clock_t finish3 = clock();
		cout << "Time of Insertion Sort: " << (finish3 - start3) << endl;
		outFile << (finish3 - start3) << ",";
		
		//Heap
		equal(a, temp, size[i]);
		clock_t start4 = clock();
		sort(temp, size[i], heapSort);
		clock_t finish4 = clock();
		cout << "Time of Heap Sort: " << (finish4- start4) << endl;
		outFile <<( finish4 - start4 )<< ",";
		
		//Quick
		equal(a, temp, size[i]);
		clock_t start5 = clock();
		sort(temp,0, size[i]-1, quick);
		clock_t finish5 = clock();
		cout << "Time of Quick Sort: " << (finish5 - start5)  << endl;
		outFile << (finish5 - start5) << ",";

		//Merge
		equal(a, temp, size[i]);
		clock_t start6 = clock();
		int*L = new int[size[i] / 2];
		int*R = new int[size[i] / 2];
		sort(temp,L,R,0, size[i]-1, mergeSort);
		delete[] R;
		delete[] L;
		clock_t finish6 = clock();
		cout << "Time of Merge Sort: " << (finish6 - start6)  << endl;
		outFile << (finish6 - start6 )<< ",";

		//Radix
		equal(a, temp, size[i]);
		clock_t start7 = clock();
		sort(temp, size[i], radix);
		clock_t finish7 = clock();
		cout << "Time of Radix Sort: " << (finish7 - start7) << endl;
		outFile << (finish7 - start7) << ",";
	

		//Flash

		equal(a, temp, size[i]);
		clock_t start8 = clock();
		sort(temp, size[i], flash);
		clock_t finish8 = clock();
		cout << "Time of Flash Sort: " << (finish8 - start8) << endl;
		outFile << (finish8 - start8) << ",";
		outFile << "\n";

		//delete arr
		delete[] a;

	}
	outFile.close();
	system("pause");
	return 0;
}