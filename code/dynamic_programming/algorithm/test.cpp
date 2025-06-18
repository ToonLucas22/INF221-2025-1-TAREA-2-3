#include "sequence_difference.cpp"
using namespace std;

int main() {
    int pairs;
    cin >> pairs;
    cout << pairs << "\n";
    for (int i=0;i<pairs;i++) {
        int n1, n2;
        string s1, s2;
        cin >> n1 >> s1;
        cin >> n2 >> s2;
        vector<pair<string, string>> sol = diferenciasDP(s1, s2);
        for (int j=0;j<sol.size();j++) {
            cout << sol[j].first << ' ' << sol[j].second << "\n";
        }
    }

    return 0;
}