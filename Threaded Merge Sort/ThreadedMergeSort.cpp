#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <thread>
#include <fstream>


using namespace std;



 using Iterator = std::vector<int>::iterator;

 void merge_sort_generaal(Iterator begin, Iterator end) {
     if (end > begin+1) {
         auto mid = begin + ((end - begin) / 2);

         std::thread t1(merge_sort_generaal, begin, mid);
         std::thread t2(merge_sort_generaal, mid, end);

         t1.join();
         t2.join();

         std::vector<int> temp(end-begin);
         std::merge(begin, mid, mid, end, std::begin(temp));
         std::copy(std::begin(temp), std::end(temp), begin);
     }
 }

 void merge_sort(std::vector<int>& v) {
     merge_sort_generaal(std::begin(v), std::end(v));
     
 }

 void write_csv(std::string filename, std::string colname, std::clock_t val1, std::clock_t val2)
 {
    // Make a CSV file with one column of integer values
    // filename - the name of the file
    // colname - the name of the one and only column
    // vals - an integer vector of values
    
    // Create an output filestream object
    std::ofstream myFile(filename);
    
    // Send the column name to the stream
    myFile << colname << "\n";
    
    // Send data to the stream
     
    myFile << (val1 - val2) /(double)CLOCKS_PER_SEC << "\n";
    
     
    // Close the file
    myFile.close();
}

 int main()
 {
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
     clock_t t1, t2;
     t1 = clock();
     std::vector<int> v{6, 5, 3, 1, 8, 7, 2, 4};
     for (int x: v) std::cout << x << ' '; std::cout << '\n';
     std::cout << "Sorting..\n";
     
     merge_sort(v);

     for (int x: v) std::cout << x << ' '; std::cout << '\n';\
     t2 = clock();

    write_csv("Thraded_data.csv", "Merge sort", t2 , t1);

     std::cout << "Time taken: " << (t2 - t1) /
              (double)CLOCKS_PER_SEC << std::endl;
 }
