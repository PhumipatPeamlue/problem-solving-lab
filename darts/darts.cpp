#include <iostream>
using namespace std;

int cal_point(int x, int y)
{
    int r_pow_2 = x*x + y*y;

    if (r_pow_2 <= 2*2) return 5;
    else if (r_pow_2 <= 4*4) return 4;
    else if (r_pow_2 <= 6*6) return 3;
    else if (r_pow_2 <= 8*8) return 2;
    else if (r_pow_2 <= 10*10) return 1;
    else return 0;
}


int main()
{
    int N, x, y, point = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;

        point += cal_point(x, y);
    }

    cout << point << endl;

    return 0;
}