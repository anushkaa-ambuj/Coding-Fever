#include <iostream>
#include <vector>
#include <algorithm>

struct Lamp {
    int a;
    int b;
};

bool compareLamps(const Lamp& lamp1, const Lamp& lamp2) {
    return lamp1.b > lamp2.b;
}

long long maximumPoints(std::vector<Lamp>& lamps) {
    std::sort(lamps.begin(), lamps.end(), compareLamps);

    long long points = 0;
    int x = 0;
    int n = lamps.size();

    for (int i = 0; i < n; i++) {
        if (lamps[i].a <= x) {
            points += static_cast<long long>(lamps[i].b);
            x++;
        }
    }

    return points;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<Lamp> lamps(n);

        for (int i = 0; i < n; i++) {
            std::cin >> lamps[i].a >> lamps[i].b;
        }

        long long result = maximumPoints(lamps);
        std::cout << result << std::endl;
    }

    return 0;
}
