//good qustion of two pointers

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define int long long
#define ez ios_base::sync_with_stdio(false); cin.tie(NULL);

// Helper to "undo" or "do" a move
void update(int& cx, int& cy, char move, int delta) {
    if (move == 'U') cy += delta;
    else if (move == 'D') cy -= delta;
    else if (move == 'L') cx -= delta;
    else if (move == 'R') cx += delta;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tx, ty;
    cin >> tx >> ty;

    // Basic parity and distance check
    int total_dist = abs(tx) + abs(ty);
    if (total_dist > n || (n - total_dist) % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    // Current position if we change nothing
    int cx = 0, cy = 0;
    for (char c : s) update(cx, cy, c, 1);

    // If already at target
    if (cx == tx && cy == ty) {
        cout << 0 << endl;
        return;
    }

    int L = 0, ans = n + 1;
    for (int R = 0; R < n; R++) {
        // "Remove" the current move from the robot's path to put it in the changeable window
        update(cx, cy, s[R], -1);

        // Try to shrink the window from the left
        while (L <= R) {
            int window_size = R - L + 1;
            int needed = abs(tx - cx) + abs(ty - cy);

            if (needed <= window_size && (window_size - needed) % 2 == 0) {
                ans = min(ans, window_size);
                // To shrink, we "add back" the move at L to the fixed path
                update(cx, cy, s[L], 1);
                L++;
            } else {
                break;
            }
        }
    }

    cout << (ans > n ? -1 : ans) << endl;
}

signed main() {
    ez;
    solve();
    return 0;
}