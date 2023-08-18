#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> array;

    array.push_back(3);
    array.push_back(7);
    array.push_back(4);

    int i = 0;

    // khi sử dụng tham chiếu(&) thì item = i 
    for(int &item : array){
        item = i;
        i++;
    }
    
    for(int item : array){
        cout << item<< endl;
    }
    return 0;
}
