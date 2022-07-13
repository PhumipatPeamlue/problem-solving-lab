#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    
    while (1)
    {
        cin >> N;
        if (N == 0) break;

        while (1)
        {
            int current_coach = 1;
            vector<int> stack;

            for (int i = 0; i < N; i++)
            {
                cin >> M;
                if (M == 0) break;

                while (current_coach <= M)
                {
                    stack.push_back(current_coach);
                    current_coach++;
                }
                
                if (stack.back() == M) stack.pop_back();
            }

            if (M == 0)
            {
                cout << endl;
                break;
            }

            if (stack.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;

        } 
    }
    return 0;
}