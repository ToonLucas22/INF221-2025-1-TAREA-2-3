/*
    CÓDIGO GENERADO POR CHATGPT, NO PUDE ENCONTRAR NINGUNA OTRA SOLUCIÓN AL PROBLEMA NI ONLINE NI POR MI CUENTA

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

    @misc{chatgpt2025lcs,
  author = {{ChatGPT}},
  title = {Implementación de algoritmos de detección de diferencias entre cadenas usando fuerza bruta y programación dinámica},
  year = {2025},
  note = {Código generado por modelo de lenguaje ChatGPT, OpenAI. Disponible bajo solicitud personalizada.}
}

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string lcsBrute(const string& s, const string& t) {
    if (s.empty() || t.empty()) return "";
    if (s[0] == t[0]) return s[0] + lcsBrute(s.substr(1), t.substr(1));
    string x = lcsBrute(s, t.substr(1));
    string y = lcsBrute(s.substr(1), t);
    return (x.size() > y.size()) ? x : y;
}

vector<pair<string, string>> diferenciasFB(const string& s, const string& t) {
    string common = lcsBrute(s, t);
    vector<pair<string, string>> diffs;
    int i = 0, j = 0;
    for (char &c : common) {
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
