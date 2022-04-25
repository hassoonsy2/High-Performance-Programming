# include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include <cstring>
#include<omp.h>
#include <chrono>
#include <mpi.h>

using namespace std;



int main(int argc, char** argv){

    int id = -1, numProcesses = -1, length = -1;
	char myHostName[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv);
	

    cout << "pleas input postitive integer n: ";
    int n =1e9; 
    cin >> n;

   

    bool* sieve = new bool[n +1];
    memset(sieve,0,n+1);
    vector<int> prime;
    
    sieve[0] = sieve[1] = 1;
    int n_sqrt = (int)(sqrt(n));

    MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
	MPI_Get_processor_name (myHostName, &length);

     // Start measuring time
    auto begin = std::chrono::high_resolution_clock::now();

    omp_set_num_threads(8);
    #pragma omp parallel for schedule(dynamic, 1) 
        for (int i=2; i <= n_sqrt;i++)
            {
                 
                if(!sieve[i]){
                    #pragma omp parallel for
                    for(int j = i*i; j<=n; j+= i)
                    sieve[j]= 1;
        }
        
    }
    
    for(int i =2;i <=n; i++)
        if(!sieve[i]) prime.push_back(i);

    // Stop measuring time and calculate the elapsed time
    auto end = std::chrono::high_resolution_clock::now();

 
    cout<<"Primes between 2 and "<<n<<endl;
    cout<<"\n Primes : "<< prime.size()<<"\n";
     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
     printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
     printf("MPI & OpenMP uses up to %d threads running on %d processors %d\n\n",
         omp_get_max_threads(), numProcesses);
   

    system("pause");
    MPI_Finalize();
    return 0;
    
}