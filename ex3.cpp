#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int n = 3;
const int M = 15;

struct EstadoMagico {
    vector<int> matriz;
    int pos_atual;
    vector<bool> usados;
};

bool ehValido(const vector<int>& mat) {
    for (int i = 0; i < n; ++i) {
        if (mat[i*n] + mat[i*n+1] + mat[i*n+2] != M) return false;
        if (mat[i] + mat[n+i] + mat[2*n+i] != M) return false;
    }
    if (mat[0] + mat[4] + mat[8] != M) return false;
    if (mat[2] + mat[4] + mat[6] != M) return false;
    return true;
}

void gerarQuadradoMagico() {
    queue<EstadoMagico> fila;
    
    EstadoMagico inicial;
    inicial.matriz.resize(n * n, 0);
    inicial.pos_atual = 0;
    inicial.usados.resize(n * n + 1, false);
    fila.push(inicial);

    while (!fila.empty()) {
        EstadoMagico atual = fila.front();
        fila.pop();

        if (atual.pos_atual == n * n) {
            if (ehValido(atual.matriz)) {
                cout << "Quadrado Magico Encontrado:\n";
                for (int i = 0; i < n; ++i) {
                    cout << "[" << atual.matriz[i*n] << " " 
                         << atual.matriz[i*n+1] << " " 
                         << atual.matriz[i*n+2] << "]\n";
                }
                return;
            }
            continue;
        }

        for (int num = 1; num <= n * n; ++num) {
            if (!atual.usados[num]) {
                EstadoMagico proximo = atual;
                proximo.matriz[proximo.pos_atual] = num;
                proximo.usados[num] = true;
                proximo.pos_atual++;
                fila.push(proximo); 
            }
        }
    }
}

int main() {
    cout << "--- Exercicio 3: Quadrado Magico com Fila ---\n";
    cout << "Buscando solucao para n=3...\n";
    gerarQuadradoMagico();
    return 0;
}
