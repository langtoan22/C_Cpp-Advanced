#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list <int> array;

    array.push_back(6);
    array.push_back(3);
    array.push_back(8);

    for(int x : array){
        cout << x << endl;
    }
    return 0;
}
