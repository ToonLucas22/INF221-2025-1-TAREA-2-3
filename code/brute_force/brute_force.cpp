#include "algorithm/sequence_difference.cpp"
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int N[] = {10};
    int E[] = {20, 50, 80};
    int C[] = {0, 1};

    string filename;
    string pathTo = "./data/brute_force_input/";
    string pathM  = "./data/measurements/";
    string pathOut= "./data/brute_force_output/";
    double execTime;
    unsigned t0, t1;
    //int beginMem, endMem, totalMemUse;
    ofstream measure(pathM+"a.txt");

    for (int &n : N) {
        for (int &e : E) {
            for (int &c : C) {
                //Abrir el input correspondiente
                filename = to_string(n)+'_'+to_string(e)+'_'+to_string(c)+".dat";
                ifstream file(pathTo+filename);
                ofstream output(pathOut+filename.substr(0,filename.size()-4)+"_out.txt");
                if (!file) {
                    cout << "Oops! Error al abrir archivo "+filename+"\n";
                    exit(EXIT_FAILURE);
                }

                int t;
                file >> t;

                for (int i=0;i<t;i++) {
                    int n1, n2;
                    string s1, s2;
                    file >> n1 >> s1 >> n2 >> s2;

                    //cout << "llegue aqui xd\n";

                    vector<pair<string, string>> sol;
                    t0 = clock();
                    sol = diferenciasFB(s1, s2);
                    t1 = clock();
                    execTime = (double(t1-t0)/CLOCKS_PER_SEC);
                    measure << filename << " " << to_string(i) << " " << execTime << "\n";

                    cout << "Algoritmo ejecutado exitosamente para "+filename+", par de strings #"+to_string(i)+"\n";

                    output << sol.size() << "\n";
                    for (auto &diff : sol) {
                        output << diff.first << ' ' << diff.second << "\n";
                    }
                }
                file.close();
                output.close();
            }
        }
    }

    measure.close();

    return 0;
}