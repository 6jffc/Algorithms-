#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int min_rating = INT_MAX;

        // Calculate the maximum possible rating of the company
        for (int i = 0; i < n; ++i) {
            int rating1 = a[i];
            int rating2 = b[i];
            int company_rating = min(rating1, rating2);
            min_rating = min(min_rating, company_rating);
        }

        cout << min_rating << "\n";
    }

    return 0;
}

