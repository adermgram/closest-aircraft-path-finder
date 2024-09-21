#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cfloat>

using namespace std;

struct Aircraft {
    float x, y;
    string name;
};

bool compareX(const Aircraft& a1, const Aircraft& a2) {
    return a1.x < a2.x;
}

float distance(const Aircraft& a1, const Aircraft& a2) {
    return sqrt((a1.x - a2.x) * (a1.x - a2.x) + (a1.y - a2.y) * (a1.y - a2.y));
}

float bruteForce(const vector<Aircraft>& aircrafts, int left, int right, Aircraft& closestAircraft1, Aircraft& closestAircraft2) {
    float minDist = FLT_MAX;
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            float dist = distance(aircrafts[i], aircrafts[j]);
            if (dist < minDist) {
                minDist = dist;
                closestAircraft1 = aircrafts[i];
                closestAircraft2 = aircrafts[j];
            }
        }
    }
    return minDist;
}

float stripClosest(const vector<Aircraft>& strip, float d, Aircraft& closestAircraft1, Aircraft& closestAircraft2) {
    float minDist = d;
    int n = strip.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minDist; ++j) {
            float dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
                closestAircraft1 = strip[i];
                closestAircraft2 = strip[j];
            }
        }
    }
    return minDist;
}

float closestUtil(vector<Aircraft>& aircrafts, int left, int right, Aircraft& closestAircraft1, Aircraft& closestAircraft2) {
    if (right - left <= 3) {
        return bruteForce(aircrafts, left, right, closestAircraft1, closestAircraft2);
    }

    int mid = (left + right) / 2;
    Aircraft midAircraft = aircrafts[mid];

    float leftDist = closestUtil(aircrafts, left, mid, closestAircraft1, closestAircraft2);
    float rightDist = closestUtil(aircrafts, mid + 1, right, closestAircraft1, closestAircraft2);
    float minDist = min(leftDist, rightDist);

    vector<Aircraft> strip;
    for (int i = left; i <= right; ++i) {
        if (abs(aircrafts[i].x - midAircraft.x) < minDist) {
            strip.push_back(aircrafts[i]);
        }
    }
    
    return min(minDist, stripClosest(strip, minDist, closestAircraft1, closestAircraft2));
}

float closestPair(vector<Aircraft>& aircrafts, Aircraft& closestAircraft1, Aircraft& closestAircraft2) {
    sort(aircrafts.begin(), aircrafts.end(), compareX);
    return closestUtil(aircrafts, 0, aircrafts.size() - 1, closestAircraft1, closestAircraft2);
}

int main() {
    int n;
    vector<Aircraft> aircrafts;
    Aircraft a;

    cout << "Enter the number of aircrafts: ";
    cin >> n;
    cout << "Enter the x and y coordinates along with names of the aircrafts:" << endl;

    for (int i = 0; i < n; i++) {
        string name;
        cout << "Enter name for aircraft " << i + 1 << ": ";
        cin >> name;
        cout << "Enter x and y for aircraft " << i + 1 << ": ";
        cin >> a.x >> a.y;
        a.name = name;
        aircrafts.push_back(a);
    }

    Aircraft closestAircraft1, closestAircraft2;
    float closestDistance = closestPair(aircrafts, closestAircraft1, closestAircraft2);

    cout << "The closest pair distance is " << closestDistance << endl;
    cout << "The closest aircrafts are (" << closestAircraft1.x << ", " << closestAircraft1.y << ") named " << closestAircraft1.name
         << " and (" << closestAircraft2.x << ", " << closestAircraft2.y << ") named " << closestAircraft2.name << endl;

    return 0;
}

