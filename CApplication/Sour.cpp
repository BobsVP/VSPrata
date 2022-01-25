#include"Header.h"
#include <iostream>
#include <cstring>
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTP<Worker*> lolas(SIZE);

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':   lolas.enQueueTP(new Waiter);
            break;
        case 's':   lolas.enQueueTP(new Singer);
            break;
        case 't':   lolas.enQueueTP(new SingingWaiter);
            break;
        }
        cin.get();
        lolas.GetItem(ct)->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas.GetItem(i)->Show();
    }
    for (i = 0; i < ct; i++)
    {
        delete lolas.GetItem(i);
    }
    cout << "Bye.\n";
    return 0;
}

