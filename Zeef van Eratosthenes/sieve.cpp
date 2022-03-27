# include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include <cstring>
#include<omp.h>

using namespace std;



int main(){

    cout << "pleas input postitive integer n: ";
    int n =1e9; 
    cin >> n; 
    
    int s =clock(), e;
    bool* sieve = new bool[n +1];
    memset(sieve,0,n+1);
    vector<int> prime;
    
    sieve[0] = sieve[1] = 1;
    int n_sqrt = (int)(sqrt(n));

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
    cout<<"Primes between 2 and "<<n<<endl;
    cout<<"Elapsed time "<< (e - s)<< "musec\n";
    cout<<"\n Primes : "<< prime.size()<<"\n";
     printf("OpenMP uses up to %d threads running on %d processors\n\n",
         omp_get_max_threads(), omp_get_num_procs());

    system("pause");
    return 0;
    
}