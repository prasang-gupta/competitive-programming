#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {

    private:
    int l, b, h;
    // The class should have the following functions : 
    public:
    // Constructors: 
    // Box();
    // Box(int,int,int);
    // Box(Box);
    Box () {
        l = 0;
        b = 0;
        h = 0;
    }

    Box (int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }

    Box (const Box &a) {
        l = a.l;
        b = a.b;
        h = a.h;
    }

    // int getLength(); // Return box's length
    // int getBreadth (); // Return box's breadth
    // int getHeight ();  //Return box's height
    // long long CalculateVolume(); // Return the volume of the box
    int getLength() {
        return l;
    }

    int getBreadth() {
        return b;
    }

    int getHeight() {
        return h;
    }

    long long CalculateVolume() {
        return (long long)l*b*h;
    }

    //Overload operator < as specified
    //bool operator<(Box& b)
    bool operator<(const Box& box) {
        if (l < box.l){
            return true;
        }
        if (l == box.l && b < box.b){
            return true;
        }
        if (l == box.l && b == box.b && h < box.h){
            return true;
        }
        return false;
    }

    //Overload operator << as specified
    //ostream& operator<<(ostream& out, Box& B)
    friend ostream& operator<<(ostream& out, const Box& box) {
        out << box.l << " " << box.b << " " << box.h;
        return out;
    }
};
