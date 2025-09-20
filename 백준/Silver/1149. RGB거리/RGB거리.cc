#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> vec(N + 1, {0,0,0});
    for (int i = 0; i < N; ++i)
    {
        int R,G,B;
        std::cin >> R >> G >> B;

        int min_R = R + std::min(vec[i][1], vec[i][2]);
        int min_G = G + std::min(vec[i][0], vec[i][2]);
        int min_B = B + std::min(vec[i][0], vec[i][1]);
        vec[i + 1] = {min_R, min_G, min_B};
    }

    std::cout << *std::min_element(vec[N].begin(), vec[N].end());
}