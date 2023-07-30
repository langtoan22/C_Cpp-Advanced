//structure     [captures](parameters)->return type {statements}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    
    vector <int> li = {1, 2, 3, 6, 7, 5, 1};

    sort(li.begin(), li.end(), [](int a, int b){
        return a < b;
        });

    for(vector<int>::iterator it = li.begin(); it != li.end(); ++it) 
    {
        cout<<*it<<endl;
    }
}