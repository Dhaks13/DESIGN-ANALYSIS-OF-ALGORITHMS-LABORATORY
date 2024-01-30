#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>

using namespace std;

long int count;

void swap(int A[],int i, int j)
{
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
	return;
}

int Partition(int A[], int s, int e)
{
	int key=A[e];
	int i=s-1;
	for(int j=s; j<=e; j++)
	{
		count++;
		if(A[j]<=key)
		{
			i++;
			swap(A,i,j);
		}
	}
	return i;
}

void QuickSort(int A[], int s, int e)
{
	if(s>=e)
		return;
	int m=Partition(A,s,e);
	count++;
	QuickSort(A,s,m-1);
	QuickSort(A,m+1,e);
}

//Randomized QuickSort
int RPartition(int A[], int s, int e)
{
	int k = s + (rand()%(s-e));
	swap(A,k,e);
	return Partition(A,s,e);
}

void RQS(int A[], int s, int e)
{
	if(s>=e)
		return;
	int m=RPartition(A,s,e);
	count++;
	RQS(A,s,m-1);
	RQS(A,m+1,e);
}

int main()
{
	
	int i,j,t;

	cout<<showpoint<<setprecision(12);

	ofstream outf;
	ifstream inf;

	int n;
	int *a;
	
	cout<<"\nEnter n:";
	cin>>n;
	
	a = new int [n];

	srand((long int)clock());
	//Loading numbers to input file
	outf.open("in.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<rand()%n;
	}
	outf.close();
	
	
	//Analysis of Quick Sort 
	cout<<"\n\nAnalysis of Quick Sort\n";
	cout<<setfill('-')<<setw(80)<<"-";
	//Reading input in array from input file
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	//Quick Sort - Unordered Array
	//The array contains random elements

	count=0;
	QuickSort(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("QuickOut1.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();	
	cout<<"\nQuick Sort - No. of Operations - Random Order: "<<count;

	//Quick Sort - Sorted Array (Ascending)
	//Now the array a contains numbers in ascending order
	
	count = 0;
	QuickSort(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("QuickOut2.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nQuick Sort - No. of Operations - Sorted Array (Ascending): "<<count;

	//Quick Sort - Sorted Array (Descending)

	//Reverse the content of a
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t = a[i]; 	a[i] = a[j]; 	a[j] = t;
	}
	
	//Now the array a contains numbers in descending order	
	count = 0;
	QuickSort(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("QuickOut3.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nQuick Sort - No. of Operations - Sorted Array (Descending): "<<count;
	cout<<"\n";

	
	//Analysis of Randomized Quick Sort 
	cout<<"\n\nAnalysis of Randomized Quick Sort\n";
	cout<<setfill('-')<<setw(80)<<"-";
	//Reading input in array from input file
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	//Randomized Quick Sort - Unordered Array
	//The array contains random elements

	count=0;
	RQS(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("RQSOut1.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();	
	cout<<"\nRandomized Quick Sort - No. of Operations - Random Order: "<<count;

	//Randomized Quick Sort - Sorted Array (Ascending)
	//Now the array a contains numbers in ascending order
	
	count = 0;
	RQS(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("RQSOut2.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nRandomized Quick Sort - No. of Operations - Sorted Array (Ascending): "<<count;

	//Randomized Quick Sort - Sorted Array (Descending)

	//Reverse the content of a
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t = a[i]; 	a[i] = a[j]; 	a[j] = t;
	}
	
	//Now the array a contains numbers in descending order	
	count = 0;
	RQS(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("RQSOut3.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nRandomized Quick Sort - No. of Operations - Sorted Array (Descending): "<<count;
	cout<<"\n";


	return 0;
}
