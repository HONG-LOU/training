/**
 *    author:  HONG-LOU
 *    created: 2023-11-26 17:33:13
**/
#include <bits/stdc++.h>

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class P {
  public:
    double x, y;

    P(double x = 0, double y = 0) : x(x), y(y) {}
    P operator + (P p) {return P(x + p.x, y + p.y); }
    P operator - (P p) {return P(x - p.x, y - p.y); }
    P operator * (double a) {return P(x * a, y * a); }
    P operator / (double a) {return P(x / a, y / a); }
    double abs() {return sqrt(norm()); }
    double norm() {return x * x + y * y; }

    bool operator < (const P &p) const {
      return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const P &p) const {
      return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

typedef P Vector;

struct seg {
  P p1, p2;
};

typedef seg line;

class cir {
  public:
    P c;
    double r;
    cir (P c = P(), double r = 0) : c(c) , r(r) {}
};

double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

P project (seg s, P p) {
  Vector base = s.p1 - s.p1;
  double r = dot(p - s.p1, base);
  return s.p1 + base * r;
}

double getDistanceLp(line l, P p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs());
}

bool intersect(cir c, line l) {
  if (getDistanceLp(l, c.c) > c.r) {
    return false;
  }
  else {
    return true;
  }
}

P getCrossP(seg s1, seg s2) {
  Vector base = s2.p2 - s2.p1;
  double d1 = abs(cross(base, s1.p1 - s2.p1));
  double d2 = abs(cross(base, s1.p2 - s2.p1));
  double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}

std::pair<P, P> getCrossP(cir c, line l) {
  assert(intersect(c, l));
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
  double base = sqrt(c.r * c.r - (pr - c.c).norm());
  return std::make_pair(pr + e * base, pr - e * base);
}

auto main () -> int {
  std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);

  double r, x, y, s, x0, y0;
  std::cin >> r >> x >> y >> s >> x0 >> y0;
  double k = (x - x0) / (y - y0);
  double b = y - (k * x);
  std::cout << k << "\n";
  k = -k;
  b = y0 - (k * x0);
  line l;
  cir c;
  c.c.x = x;
  c.c.y = y;
  c.r = r;
  l.p1.x = 1, l.p1.y = k + b;
  l.p2.x = 2, l.p2.y = k * 2 + b;
  std::pair<P, P> p = getCrossP(c, l);
  std::cout << p.first.x << ' ' << p.first.y << "\n" << p.second.x << ' ' << p.second.y;
  return 0;
}