
#include "Bucket_sort.h" 
#include <iostream> 
using std::cout; 
using std::cin; 
using std::endl;


 void BucketSort::internalBucketSort(int * array, int entries, int digit, int places) {
    int array_index, digit_index, bucket_index, gather_index;
    Bucket ** bucket = new Bucket *[10];
    int max_value = 0;

    // initialisatie van buckets
    for ( bucket_index = 0; bucket_index < 10; bucket_index++ ) {
	bucket[bucket_index] = new Bucket(entries);
    }

    // distributiepas
    for ( array_index = 0; array_index < entries; array_index++ ) {
	int array_value = array[array_index];
	if ( array_value > max_value ) max_value = array_value;
	for ( digit_index = 0; digit_index < digit; array_value/=10, digit_index++);
	bucket[array_value%10]->add_entry(array[array_index]);
    }

    // gathering pass
    array_index = 0;
    for ( bucket_index = 0; bucket_index < 10; bucket_index++ ) {
	int bucket_entries = bucket[bucket_index]->bucket_count();
	for ( gather_index = 0; gather_index < bucket_entries; gather_index++ ) {
	    array[array_index++] = bucket[bucket_index]->bucket_entry(gather_index);
	}
    }
    if ( max_value > places ) internalBucketSort(array, entries, digit+1, places*10);
}

void BucketSort::bucketSort(int * array, int arraySize) {
    internalBucketSort(array, arraySize, 0, 10);
}
