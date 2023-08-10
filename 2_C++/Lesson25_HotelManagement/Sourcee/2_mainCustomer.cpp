/*
* File: 2_mainCustomer.cpp
* Author: Lang Van Toan
* Date: 23/07/2023
* Description: This is file to manage customer
*/
#include "Customer.h"


int main(int argc, char const *argv[])
{
     Customer customer("John Smith", "1234567890", "123 Main St");

    bookHistory history1 = {
        { 26, 7, 2023 },
        { 10, 0, 0 },
        IN
    };
    customer.addBookHistory(history1);

    bookHistory history2 = {
        { 26, 7, 2023 },
        { 16, 0, 0 },
        OUT
    };
    customer.addBookHistory(history2);

    customer.displayBoolHistory();

    return 0;
}
