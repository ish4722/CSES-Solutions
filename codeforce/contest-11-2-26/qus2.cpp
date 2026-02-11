#include <iostream>
#include <vector>
/*good qus gpt kia hai abhi toh smjh nhi aaya tha ,logic dusara tha mera, both side se traverse krke 
 but voh sense nhi bnaya ,and ans glt aa rh tha usse
 */
using namespace std;

#define ez ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> p(n), a(n);
    vector<int> pos(n + 1); // To store where each number is in p

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i; // Value p[i] is at index i
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = true;
    for(int i = 0; i < n - 1; i++) {
        // The original position of a[i] must be <= original position of a[i+1]
        if (pos[a[i]] > pos[a[i + 1]]) {
            ok = false;
            break;
        }
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ez;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}