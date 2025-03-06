#include <iostream>
#include "Lab1.h"
using namespace std;

int main()
{
    FILE* file;

    int err = fopen_s(&file, "../../prices.txt", "rt");
    
    if (!file) {
        return 1;
    }

    char buffer[256];
    int num1, num2, num3;
    money finalPrice = { 0,0 };

    while (fgets(buffer, sizeof(buffer), file)) {
        sscanf_s(buffer, "%d %d %d", &num1, &num2, &num3);

        money currentPrice = { num1,num2 };

        countPrice(currentPrice);
        multiplyPrice(currentPrice, num3);

        finalPrice.grn += currentPrice.grn;
        finalPrice.cop += currentPrice.cop;
        printPrice(currentPrice);
    }

    roundCop(finalPrice);
    
    cout << "\nFinal price: ";
    printPrice(finalPrice);

    fclose(file);
}