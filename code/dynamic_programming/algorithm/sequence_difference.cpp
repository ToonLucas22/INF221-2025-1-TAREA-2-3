/*
    CÓDIGO PARCIALMENTE GENERADO POR CHATGPT, NO PUDE ENCONTRAR NINGUNA OTRA SOLUCIÓN AL PROBLEMA NI ONLINE NI POR MI CUENTA

    BIBLIOGRAFÍA:
    
    📘 Para el algoritmo de LCS (Longest Common Subsequence)

        Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.

            Capítulo 15: Dynamic Programming.

            Sección 15.4: Longest Common Subsequence Problem.

        Skiena, Steven S. (2008). The Algorithm Design Manual (2nd ed.). Springer.

            Capítulo sobre programación dinámica y alineación de secuencias.

    📘 Para diseño de algoritmos en C++

        Sedgewick, R., & Wayne, K. (2011). Algorithms (4th ed.). Addison-Wesley.

            Aunque más enfocado en Java, los conceptos son directamente aplicables a C++.

        Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.

            Para estilo, prácticas recomendadas y uso correcto de estructuras estándar (vector, string).

    ChatGPT, OpenAI (2025). Código generado por IA a solicitud personalizada del usuario.
    Basado en algoritmos clásicos de programación dinámica y recursión para detectar diferencias entre cadenas mediante LCS.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Calcula la LCS usando DP y la reconstruye
string lcsDP(const string& s, const string& t) {
    int n = s.size(), m = t.size();
    /*
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int cur = i % 2, prev = 1 - cur;
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1])
                dp[cur][j] = dp[prev][j - 1] + 1;
            else
                dp[cur][j] = max(dp[prev][j], dp[cur][j - 1]);
        }
    } //codigo comentado por mi, esto no es util para nada
    */

    // Reconstrucción de la LCS
    string lcs;
    int i = n, j = m;
    vector<vector<int>> full_dp(n + 1, vector<int>(m + 1, 0));
    // Calculamos nuevamente para reconstrucción
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i] == t[j])
                full_dp[i+1][j+1] = full_dp[i][j] + 1;
            else
                full_dp[i+1][j+1] = max(full_dp[i][j+1], full_dp[i+1][j]);

    i = n; j = m;
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            lcs = s[i-1] + lcs;
            --i; --j;
        } else if (full_dp[i-1][j] >= full_dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    return lcs;
}

vector<pair<string, string>> diferenciasDP(const string& s, const string& t) {
    string common = lcsDP(s, t);
    vector<pair<string, string>> diffs;
    int i = 0, j = 0;
    for (char c : common) {
        int start_i = i, start_j = j;
        while (i < s.size() && s[i] != c) ++i;
        while (j < t.size() && t[j] != c) ++j;
        if (start_i != i || start_j != j)
            diffs.emplace_back(s.substr(start_i, i - start_i), t.substr(start_j, j - start_j));
        ++i; ++j;
    }
    if (i < s.size() || j < t.size())
        diffs.emplace_back(s.substr(i), t.substr(j));
    return diffs;
}