#include <iostream>
#include <stdlib.h>
#include <time.h>  

using namespace std;

int rand7()
{
    return rand()%7 + 1;
}

int rand10()
{
    int a71, a72, a10;

    do
    {
        a71 = rand7() - 1;
        a72 = rand7() - 1;

        a10 = a71 * 7 +  a72;

    }while(a10 >= 40);

    return (a71 * 7 + a72) / 4 + 1;
}

int main()
{
    srand (time(NULL));

    cout<<rand10()<<endl;
    return 0;
}