/**
  Read in object from file
  Author: Zihao Pan
*/
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Body
{
private:
    string name;
    double mass;
    double radius;
    double x;
    double y;
    double z;
public:
    Body()
    {
        name = "NaN";
    }
    Body(string n, double m, double r, double d)
    {
        name = n;
        mass = m;
        radius = r;
        x = d;
        y = 0;
        z = 0;
    }
    friend ostream& operator << (ostream&,Body&);
};
ostream& operator << (ostream& out,Body& b)
{
    out << '(' << b.name << ',' << b.mass << ',' << b.radius << ',' << b.x << ',' << b.y << ',' << b.z << ')';
    return out;
}
int main()
{
    double m, Diam, Perihelion, Aphelion;
    string n,orbits,line;
    char buf[1024];
    Body a;
    ifstream f("solarsystem.dat");
    f.getline(buf, sizeof(buf));
    while (!f.eof())
    {
        f.getline(buf, sizeof(buf));
        istringstream linestr(buf);
        linestr >> n >> orbits >> m >> Diam >> Perihelion >> Aphelion;
        a = Body(n, m, Diam / 2, (Perihelion + Aphelion) / 2);
        cout << a << endl;
    }
    return 0;
}