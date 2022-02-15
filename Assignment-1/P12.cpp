//Ahmed Essam eldin Abd-elfattah Ibrahim    CS-S2   20190050

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cfloat>

using namespace std;
class Point{
public:     int x , y;
};
int compX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    if(p1->x == p2->x)
    {
        return (p1->y - p2->y);
    }
    else return  (p1->x - p2->x) ;
}

int compY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    if (p1->y == p2->y) return (p1->x - p2->x);
    else return (p1->y - p2->y);
}

double calcDist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double findMin(Point P[], int n)
{
    double min = DBL_MAX ;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (calcDist(P[i], P[j]) < min)
                min = calcDist(P[i], P[j]);
    return min;
}
double stripClosest(Point strip[], int size, double d)
{
    double min = d;
    double min2;
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j){
            min2=calcDist(strip[i],strip[j]);
            if (min2 < min)     min = min2;
        }

    return min;
}
double calcMin(Point *px, Point *py, int n)
{
    // base condition to stop the recursion.
    if (n <= 3)
        return findMin(px, n);


    int mid = n/2;
    Point midPoint = px[mid];


    Point pyLow[mid];           // store all element smaller than midpoint x co-ordinate.
    Point pyHigh[n - mid];     // store all element bigger than midpoint x co-ordinate.
    int leftIndx = 0, rightIndx = 0;
    for (int i = 0; i < n; i++)
    {
        if ((py[i].x < midPoint.x || (py[i].x == midPoint.x && py[i].y < midPoint.y)) && leftIndx < mid){
            pyLow[leftIndx] = py[i];
            leftIndx++;
        }
        else{
            pyHigh[rightIndx] = py[i];
            rightIndx++;}
    }


    double dl = calcMin(px, pyLow, mid);    // find smallest distance between points smaller than midpoint.
    double dh = calcMin(px + mid, pyHigh, n - mid);            // find smallest distance between points bigger than midpoint.

   // find minimum of the two smallest distance.
    double d = min(dl, dh);


    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(py[i].x - midPoint.x) < d)
            strip[j] = py[i], j++;


    return stripClosest(strip, j, d);
}
double minDist(Point *p, int n)
{
    Point px[n];
    Point py[n];
    for (int i = 0; i < n; i++)
    {
        px[i] = p[i];
        py[i] = p[i];
    }
    // using quick sort to sort points on plane according to x and y co-ordinate.
    qsort(px, n, sizeof(Point), compX);
    qsort(py, n, sizeof(Point), compY);

    return calcMin(px, py, n);
}
int main() {

    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << minDist(P, n);

    return 0;
}
