#include<iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;



void merge(int a[], int l, int m, int r){

    int temp[m-l +1], temp2[r-m];

    for(int i=0; i<(m-l + 1); i++)
            temp[i] = a[l+i];

    for(int i=0; i<(r-m); i++)
            temp2[i] = a[m+1+i];

    int i=0;
    int j=0;
    int k=l;


    while (i<(m-l+1) && j<(r-m))
    {
        if(temp[i]<temp2[j])
            a[k++]= temp[i++];
        
        else
            a[k++]= temp2[j++];
        
    }

    while (i<(m-l+1))
    {
        a[k++]= temp[i++];
    }

    while (j<(r-m))
    {
        a[k++]=temp2[j++];
    } 
} 

void merge_sort(int a[], int l, int r){
    
    if(l< r){
        int m = (l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}


void print(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
} 

void write_csv(string filename, string colname, clock_t val1, clock_t val2)
{
    
    ofstream myFile(filename);
    
    
    myFile << colname << "\n";
    
    // Send data to the stream
     
    myFile << (val1 - val2) / (val1 - val2) << "\n";
    
     
    // Close the file
    myFile.close();
}


int main()
{
    int numToSort = 0;
    int index;
    clock_t t1, t2;
    

    int * gArray = new int[numToSort]; 

    cout << "Welkom bij het Merge Sort-programma!" << endl; 
    cout << "Voer a.u.b. in hoeveel getallen worden gesorteerd: "; 
    cin >> numToSort;
    cout << endl;
    
	 //gebruiker voert elementen van de array in
    for (index = 0; index < numToSort; index++) 
    { 

        cout << "Voer alstublieft een nummer in: "; 
	    cin >> gArray[index];
	cout << endl;
    }
    t1 = clock();
	cout<<"Unsorted array; ";
	print(gArray,numToSort);

    
    

	merge_sort(gArray,0,numToSort-1);

   
	cout<<"\nSorted array: ";

    
	print(gArray,numToSort);

    t2 = clock();




   write_csv("data.csv", "Merge sort", t2 , t1);

    

    cout << "Time taken: " << (t2 - t1) / (t2 - t1) << endl;

    
}

