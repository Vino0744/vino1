/*************************************************************************
	> File Name: 3.operator_overload.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 25 Apr 2024 08:06:44 PM CST
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

class Point {
public :
    Point(double x, double y) : x(x), y(y), output_width(0) {}
    
private:
    double x, y;
    int output_width;
    friend ostream & operator<<(ostream &, const Point &);
    friend double operator*(const Point &, const Point &);
    friend Point operator*(const Point &, double);
    friend Point operator+(const Point &, double);
    friend Point &operator-(Point &, int);
    friend Point &operator-(Point &, Point &);
    friend class OutputAxis;
};

ostream & operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}


double operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

Point operator*(const Point &a, double v) {
    return Point(a.x * v, a.y * v);
}

Point operator*(double v, const Point &a) {
    return a * v;
}

Point operator+(const Point &a, double offset) {
    return Point(a.x + offset, a.y + offset);
}

Point &operator-(Point &a, int x) {
    a.output_width = x;
    return a;
}

Point &operator-(Point &a, Point &b) {
    char str[100] = {0};
    snprintf(str, 99, "(%%%dg, %%%dg)", a.output_width, a.output_width);
    printf("str = %s\n", str);
    printf(str, b.x, b.y);
    return a;
}

Point &operator-(Point &a, const char *s) {
    printf("%s", s);
    return a;
}

class OutputAxis {
public :
    OutputAxis() : per_x(5), per_y(2) {};
    void add(Point &a) const { points.push_back(a); }
    void output() const;
    void draw_x_axis(char **g, int y0, int max_len, int x) const {
        for (int i = 0; i < max_len; i++) {
            if ((i - 2) % per_x == 0) {
                g[y0][i] = '|';
                int ret = snprintf(g[y0 + 1] + i + 1, max_len, "%d", x);
                g[y0 + 1][i + 1 + ret] = ' ';
                x += 1;
            } else {
                g[y0][i] = '-';
            }
        }
        return ;
    }
    void draw_y_axis(char **g, int x0, int max_len, int y) const {
        for (int i = 0; i < max_len; i++) {
            if (i >= 2 && (i - 2) % per_y == 0) {
                if (y == 0) {
                    g[i][x0] = '+';
                    y -= 1;
                    continue;
                }
                g[i][x0] = '-';
                int ret = snprintf(g[i] + x0 + 2, max_len, "%d", y);
                g[i][x0 + 2 + ret] = ' ';
                y -= 1;
            } else {
                g[i][x0] = '|';
            }
        }
        return ;
    }
    void output_axis(char **g, int max_x, int max_y) const {
        for (int i = 0; i < max_y; i++) {
            for (int j = 0; j < max_x; j++) {
                printf("%c", g[i][j]);
            }
            printf("\n");
        }
        return ;
    }
    void draw_point(char **g, int x0, int y0, Point &p) const {
        int x = x0 + p.x * per_x;
        int y = y0 - p.y * per_y;
        g[y][x] = '*';
        return ;
    }

private:
    mutable vector<Point> points;
    int per_x, per_y;
};

OutputAxis operator^(Point &a, Point &b) {
    OutputAxis oa;
    oa.add(a);
    oa.add(b);
    return oa;
}

OutputAxis operator^(const OutputAxis &oa, Point &b) {
    oa.add(b);
    return oa;
}

OutputAxis operator^(const OutputAxis &oa, int x) {
    oa.output();
    return oa;
}

void OutputAxis::output() const {
    double x_min = INT32_MAX, x_max = INT32_MIN;
    double y_min = INT32_MAX, y_max = INT32_MIN;
    for (auto p : points) { 
        x_min = min(x_min, p.x);
        x_max = max(x_max, p.x);
        y_min = min(y_min, p.y);
        y_max = max(y_max, p.y);
    }
    x_min = min(0.0, floor(x_min)) - 2;
    y_min = min(0.0, floor(y_min)) - 2;
    x_max = ceil(x_max) + 2;
    y_max = ceil(y_max) + 2;
    int max_x = max(x_max - x_min, y_max - y_min) * per_x + 5;
    int max_y = max(x_max - x_min, y_max - y_min) * per_y + 5;
    char **g = (char **)malloc(sizeof(char *) * max_y);
    for (int i = 0; i < max_y; i++) {
        g[i] = (char *)malloc(sizeof(char) * max_x);
        for (int j = 0; j < max_x; j++) g[i][j] = ' ';
    }
    int x0 = 2 + per_x * (int)fabs(x_min - 0);
    int y0 = 2 + per_y * (int)fabs(y_max - 0);
    draw_x_axis(g, y0, max_x, x_min);
    draw_y_axis(g, x0, max_y, y_max);
    for (auto p : points) draw_point(g, x0, y0, p);
    output_axis(g, max_x, max_y);
    return ;
}

int main() {
    Point p1(5, 6), p2(3, 6), p3(6, 9), p4(10, 12);
    cout << p1 << " " << p2 << endl;
    cout << p1 * p2 << endl;
    cout << p1 * 2.3 << endl;
    cout << 2.3 * p1 << endl;
    cout << p1 + 5 << endl;
    p1 - 6 - p2 - "\n";
    p1^p2^p3^p4^1;
    return 0;
}
