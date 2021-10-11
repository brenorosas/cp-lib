#include <bits/stdc++.h>
using namespace std;
// Representação de ponto: x, y;
#define x first
#define y second
typedef pair<int, int> point;
const int MOD = 1e9 + 7;
// Representação de linha: ax + b;
// a na forma fracionária, first.first = numerador, first.second = denominador;
// b =second;
#define a_num first.first
#define a_den first.second
#define b second
typedef pair<pair<int, int>, int> line;

// Representação de poligono
typedef vector<point> polygon;

// Somatório do quadrado de n números naturais;
// 1^2 + 2^2 + 3^2 + 4^2 +...+ n^2 = n*(n+1)*(2*n+1)/6
int sumQuadrado(int n) { return n * (n + 1) * (2 * n + 1) / 6; }

const double EPS = 0.000000001;
// if(x==0.0)
// if(abs(x)<EPS){}

// if(x==y)
// if(abs(x-y)<EPS){}

// Produto interno dos pontos a e b
int dot(point a, point b) { return a.x * b.x + a.y * b.y; }

// norma de a
int norm(point a) { return dot(a, a); }

// comprimento de a
double length(point a) { return sqrt(norm(a)); }

// Retorna o angulo entre a e b em radianos
// retoruna double pois é um angulo
double angle(point a, point b) {
  return acos(dot(a, b) / (length(a) * length(b)));
}

// angulo entre a e b em radianos, tomando    como origem
double angle_ori(point a, point b, point c) {
  a = {a.x - c.x, a.y - c.y};
  b = {b.x - c.x, b.y - c.y};
  return angle(a, b);
}

// Tomar cuidado com esse define, pois com os defines para point pode dar ruim
#define x first.first
#define y first.second
#define z second
typedef pair<pair<int, int>, int> vetor;

// Produto vetorial em 3 dimensões
vetor cross3(vetor a, vetor b) {
  return {{a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z},
          a.x * b.y - a.y * b.x};
}

// produto vetorial em 2 dimensões
int cross2(point a, point b) { return a.x * b.y - a.y * b.x; }

pair<pair<int, int>, int> line(point p, point q) {
  int a = p.y - q.y;
  int b = p.x - q.x;
  int c = p.y - (a * p.x);
  return {{a, b}, c};
}

// Encontrar ângulos internos de um triângulo;
// angulo relativo ao lado a;
double angle_a(int a, int b, int c) {
  return acos(double(a * a - b * b - c * c) / double(-2 * b * c));
}

// Distancia de ponto a reta;
// Distancia do ponto q a reta p1-p2;
double dist_pl(point p1, point p2, point q) {
  double num = abs((p2.y - p1.y) * q.x - (p2.x - p1.x) * q.y + p2.x * p1.y -
                   p2.y * p1.x);
  double den =
      sqrt((p2.y - p1.y) * (p2.y - p1.y) + (p2.x - p1.x) * (p2.x - p1.x));

  return num / den;
}

// Formula de Gauss/Laço de sapato
// Calcula a area de um polígono p
double area_polygon(polygon p) {
  int n = p.size();
  double area = 0;
  for (int i = 0; i < n; i++) {
    point p1 = p[i], p2 = p[(i + 1) % n];
    area += (p2.x + p1.x) * (p2.y - p1.y);
  }
  area /= 2.0;
  return abs(area);
}

// Teste esquerda
// Calculalos através da determinante
// Det > 0 : ponto está a esquerda;
// Det == 0 : ponto c é colinear
// det <0 : ponto c está a direita
int is_left(point a, point b, point c) {
  int det = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
  if (det > 0)
    return 1; // c está a esquerda
  if (det < 0)
    return -1; // c está a direita
  return 0;    // c é colinear
}

// checa se o ponto q esta dentro do poligono p
bool is_inside(polygon p, point q) {
  int n = p.size();
  for (int i = 0; i < n; i++) {
    if (is_left(p[i], p[(i + 1) % n], q) == -1)
      return false;
  }
  return true;
}

int exp(int a, int b) {
  int result = 1;
  while (b > 0) {
    if (b & 1)
      result = result * a % MOD;
    b >>= 1;
    a = a * a % MOD;
  }
  return result;
}

// Combinatória + fatorial
vector<int> fat(1002000);
void precalc() {
  fat[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    fat[i] = i * fat[i - 1];
    fat[i] %= MOD;
  }
}
int comb(int n, int m) {
  return fat[n] * exp(fat[n - m], MOD - 2) % MOD * exp(fat[m], MOD - 2) % MOD;
}

int Nmax = 1e7 + 20;
int prime[10000020];
void crivo() {
  for (int i = 0; i < Nmax; i++) {
    prime[i] = i;
  }
  for (int i = 2; i * i < Nmax; i++) {
    if (prime[i] == i) {
      for (int j = i; j <= Nmax; j += i) {
        prime[j] = i;
      }
    }
  }
}