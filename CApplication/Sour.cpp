#include<iostream>
#include"Header.h"
#include <string>
const int DMAC = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    AbstractDMA* p_DMA[DMAC];
    char temp[40];
    int tempnum;
    char kind;

    for (int i = 0; i < DMAC; i++)
    {
        cout << "Enter labels's name: ";
        cin >> temp;
        cout << "Enter rating: ";
        cin >> tempnum;
        cout << "Enter 1 for BaseDMA or "
            << "2 for lacksDMA or 3 for hasDMA: ";
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
            cout << "Enter either 1 or 2 or 3: ";
        if (kind == '1')
            p_DMA[i] = new baseDMA(temp, tempnum);
        else if (kind == '2')
        {
            char blank[40];
            cout << "Enter the color: ";
            cin >> blank;
            p_DMA[i] = new lacksDMA(blank, temp, tempnum);
        }
        else if (kind == '3')
        {
            char style[40];
            cout << "Enter the style: ";
            cin >> style;
            p_DMA[i] = new hasDMA(style, temp, tempnum);
        }
        while (cin.get() != '\n')
            continue;
    }
    cout << endl;
    for (int i = 0; i < DMAC; i++)
    {
        p_DMA[i]->View();
        cout << endl;
    }

    for (int i = 0; i < DMAC; i++)
    {
        delete p_DMA[i];  
    }
    cout << "Done.\n";
    return 0;
}