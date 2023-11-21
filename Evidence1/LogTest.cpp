#include <iostream>
using namespace std;
#include "Log.h"

int main()
{
    Log log1("2022","Aug","11","13:59:18","10.200.143.174","SQL injection");
    Log log2("2023","May","04","06:58:06","10.139.153.206","Load balancing issues");
    log1.key = 20220811135918;
    log2.key = 20230504065806;
    if (log1 < log2 ){
        cout << "Log 1 es menor a log 2" << endl;
    } else {
        cout << "Log 2 es mayor o igual a log 2" << endl;
    }
    // cout << log1.year << " " << log1.time << endl;


    return 0;
}
