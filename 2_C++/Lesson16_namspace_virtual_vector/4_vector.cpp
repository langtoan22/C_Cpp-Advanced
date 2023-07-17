#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector <int> array;
//them cac phan tu vao vector
    array.push_back(5);
    array.push_back(2);
    array.push_back(4);

//chen phan tu
    array.insert(array.begin()+2, 8);
    
//xoa phan tu cuoi cung
    array.pop_back();

//in ra cac phan tu
    for (int  i = 0; i < array.size(); i++)
    {
        printf("%d\n", array[i]);
    }

//vong for cai tien
    for(int item : array){
        printf("test: %d\n", item);
    }

    return 0;
}
