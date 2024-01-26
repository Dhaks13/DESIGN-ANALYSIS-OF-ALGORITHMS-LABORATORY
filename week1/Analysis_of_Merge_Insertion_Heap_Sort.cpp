#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int count = 0;

//Merge sort

void Merge(int A[],int f, int m, int l)
{
	int n1=m-f+1;
	int n2=l-m;
	int L[n1], R[n2];
	int i=0,j=0;
	for (int k=f; k<=l; k++)
	{
		count++;
		if(k<=m)
		{
			L[i++]=A[k];
		}
		else
		{
			R[j++]=A[k];
		}
	}
	L[i]=R[j]=999999;
	i=j=0;
	for(int k=f;k<=l;k++)
	{
		count++;
		if (L[i]<R[j])
		{
			A[k]=L[i++];
		}
		else
		{
			A[k]=R[j++];
		}
	}
}

void MergeSort(int A[], int f, int l)
{
	count++;
	if(f>=l)
	{
		return;
	}
	else
	{
		int m = (f+l)/2;
		MergeSort(A,f,m);
		MergeSort(A,m+1,l);
		Merge(A,f,m,l);
	}
}



//Insertion Sort

void InsertionSort(int A[], int n)
{
	int key,j;
	for (int i=1; i<=n-1; i++)
	{
		count++;
		key=A[i];
		j=i-1;
		while (j>=0 && A[j]>key)
		{
			count++;
			A[j+1]=A[j--];	
		}
		A[j+1]=key;
	}
}



//Heap Sort

void MaxHeapify(int A[], int n, int i)
{
	count++;
	int l=(2*i)+1;
	int r=(2*i)+2;
	int m,temp;
	m=i;
	if(l<=n-1 && A[l]>A[m])
	{
		m=l;
	}
	if(r<=n-1 && A[r]>A[m])
	{
		m=r;
	}
	if (m!=i)
	{
		temp=A[m];
		A[m]=A[i];
		A[i]=temp;
		MaxHeapify(A,n,m);
	}
}

void buildHeap(int A[],int n)
{
	for(int i=(n-2)/2; i>=0; i--)
	{
		count++;
		MaxHeapify(A,n,i);
	}
}

void HeapSort(int A[], int n)
{
	buildHeap(A,n);
	while (n!=1)
	{
		count++;
		int temp=A[0];
		A[0]=A[n-1];
		A[--n]=temp;
		MaxHeapify(A,n,0);
	}
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
	

	
	//Analysis of Insertion Sort 
	cout<<"\n\nAnalysis of Insertion Sort\n";
	cout<<setfill('-')<<setw(80)<<"-";
	//Reading input in array from input file
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	//Insertion Sort - Unordered Array
	//The array contains random elements

	count=0;
	InsertionSort(a,n);
	//Writing sorted numbers to output file
	outf.open("InsertOut1.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();	
	cout<<"\nInsertion Sort - No. of Operations - Random Order: "<<count;

	//Insertion Sort - Sorted Array (Ascending)
	//Now the array a contains numbers in ascending order
	
	count = 0;
	InsertionSort(a,n);
	//Writing sorted numbers to output file
	outf.open("InsertOut2.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nInsertion Sort - No. of Operations - Sorted Array (Ascending): "<<count;

	//Insertion Sort - Sorted Array (Descending)

	//Reverse the content of a
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t = a[i]; 	a[i] = a[j]; 	a[j] = t;
	}
	
	//Now the array a contains numbers in descending order	
	count = 0;
	InsertionSort(a,n);
	//Writing sorted numbers to output file
	outf.open("InsertOut3.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nInsertion Sort - No. of Operations - Sorted Array (Descending): "<<count;
	cout<<"\n";



	//Analysis of Merge Sort 
	cout<<"\n\nAnalysis of Merge Sort\n";
	cout<<setfill('-')<<setw(80)<<"-";
	//Reading input in array from input file
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	//Merge Sort - Unordered Array
	//The array contains random elements

	count = 0;
	MergeSort(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("MergeOut1.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();	
	cout<<"\nMerge Sort - No. of Operations - Random Order: "<<count;

	//Merge Sort - Sorted Array (Ascending)
	//Now the array a contains numbers in ascending order
	
	count = 0;
	MergeSort(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("MergeOut2.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nMerge Sort - No. of Operations - Sorted Array (Ascending): "<<count;

	//Merge Sort - Sorted Array (Descending)

	//Reverse the content of a
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t = a[i]; 	a[i] = a[j]; 	a[j] = t;
	}
	
	//Now the array a contains numbers in descending order	
	count = 0;
	MergeSort(a,0,n-1);
	//Writing sorted numbers to output file
	outf.open("MergeOut3.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nMerge Sort - No. of Operations - Sorted Array (Descending): "<<count;
	cout<<"\n";


	//Analysis of Heap Sort 
	cout<<"\n\nAnalysis of Heap Sort\n";
	cout<<setfill('-')<<setw(80)<<"-";
	//Reading input in array from input file
	inf.open("in.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	
	//Heap Sort - Unordered Array
	//The array contains random elements

	count = 0;
	HeapSort(a,n);
	//Writing sorted numbers to output file
	outf.open("HeapOut1.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();	
	cout<<"\nHeap Sort - No. of Operations - Random Order: "<<count;

	//Heap Sort - Sorted Array (Ascending)
	//Now the array a contains numbers in ascending order
	
	count = 0;
	HeapSort(a,n);
	//Writing sorted numbers to output file
	outf.open("HeapOut2.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nHeap Sort - No. of Operations - Sorted Array (Ascending): "<<count;

	//Heap Sort - Sorted Array (Descending)

	//Reverse the content of a
	for(i=0,j=n-1;i<j;i++,j--)
	{
		t = a[i]; 	a[i] = a[j]; 	a[j] = t;
	}
	
	//Now the array a contains numbers in descending order	
	count = 0;
	HeapSort(a,n);
	//Writing sorted numbers to output file
	outf.open("HeapOut3.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	cout<<"\nHeap Sort - No. of Operations - Sorted Array (Descending): "<<count;
	cout<<"\n";

	return 0;
}
