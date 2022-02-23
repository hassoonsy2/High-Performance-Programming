
class Bucket
{
    private:
	int	bucket_entries;
	int *	entry;
    public:
	Bucket(int entries) : bucket_entries(0) { 
	    int index;
	    entry = new int[entries]; 
	    for ( index = 0; index < entries; entry[index] = 0, index++ );
	}
	void add_entry(int entry_value) { entry[bucket_entries++] = entry_value; };
	int bucket_count() { return bucket_entries; };
	int bucket_entry(int index) { return entry[index]; };
};

class BucketSort 
{
    private:
	void internalBucketSort(int * array, int entries, int digit, int places);
    public: 
        void bucketSort(int * array, int entries); 

};
