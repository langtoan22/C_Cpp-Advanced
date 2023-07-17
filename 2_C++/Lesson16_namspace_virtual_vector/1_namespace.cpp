#include <iostream>

namespace conOngB{
    int A = 10;
}

namespace conOngC{
    int A = 5;
}

using namespace conOngB;

int main(int argc, char const *argv[])
{
    //conOngB :: A = 20;
    printf("A: %d\n", conOngB::A);
    printf("A: %d\n", conOngC::A);

    //khi su dung using namespace conOngB
    printf("A: %d", A);

    return 0;
}