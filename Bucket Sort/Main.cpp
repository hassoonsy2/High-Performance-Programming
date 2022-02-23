#include <iostream> 
#include "Bucket_sort.h"
#include <algorithm>
using std::cout; 
using std::cin; 
using std::endl; 
 
int main() 
{ 
    int numToSort = 0;
    int index;

    cout << "Welkom bij het Bucket Sort-programma!" << endl; 
    cout << "Voer a.u.b. in hoeveel getallen worden gesorteerd: "; 
    cin >> numToSort;
    cout << endl;

    int * oneDimensionalArray = new int[numToSort]; 

    //elementen van de array worden geïnitialiseerd op 0.
    for (index = 0; index < numToSort; index++) {
	oneDimensionalArray[index] = 0;
    }
	
    //gebruiker voert elementen van de array in
    for (index = 0; index < numToSort; index++) 
    { 
        cout << "Voer alstublieft een nummer in: "; 
	cin >> oneDimensionalArray[index];
	cout << endl;
    }

    BucketSort myBucketBook; 
    myBucketBook.bucketSort(oneDimensionalArray, numToSort) ;
    
    cout << "Gesorteerde nummers:"; 
    for (index = 0; index < numToSort; index++) 
    {
	cout << oneDimensionalArray[index] << " ";
    }
    cout << endl;
    return 0; 
}
