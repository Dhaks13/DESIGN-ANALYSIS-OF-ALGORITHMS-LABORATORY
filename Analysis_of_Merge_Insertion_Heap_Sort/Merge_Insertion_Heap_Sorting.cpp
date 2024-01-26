#include<iostream>

using namespace std;

//Merge sort

void Merge(int A[],int f, int m, int l)
{
	int n1=m-f+1;
	int n2=l-m;
	int L[n1], R[n2];
	int i=0,j=0;
	for (int k=f; k<=l; k++)
	{
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
		key=A[i];
		j=i-1;
		while (j>=0 && A[j]>key)
		{
			A[j+1]=A[j--];	
		}
		A[j+1]=key;
	}
}



//Heap Sort

void MaxHeapify(int A[], int n, int i)
{
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
		MaxHeapify(A,n,i);
	}
}

void HeapSort(int A[], int n)
{
	buildHeap(A,n);
	while (n!=1)
	{
		int temp=A[0];
		A[0]=A[n-1];
		A[--n]=temp;
		MaxHeapify(A,n,0);
	}
}


//Main fns
int main()
{
	int arr[10];
	cout<<"Enter the elements for Merge Sort:\n";
	for(int i=0; i<10; i++)
	{
		cin>>arr[i];
	}
	MergeSort(arr,0,9);
	cout<<"The elements after MergeSort:\n";
	for(int i=0; i<10; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	int arr1[10];
	cout<<"Enter the elements for InsertionSort:\n";
	for(int i=0; i<10; i++)
	{
		cin>>arr1[i];
	}
	InsertionSort(arr1,10);
	cout<<"The elements after InsertionSort:\n";
	for(int i=0; i<10; i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<"\n";
	int arr2[10];
	cout<<"Enter the elements for Heap Sort:\n";
	for(int i=0; i<10; i++)
	{
		cin>>arr2[i];
	}
	HeapSort(arr2,10);
	cout<<"The elements after Heap Sort:\n";
	for(int i=0; i<10; i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
