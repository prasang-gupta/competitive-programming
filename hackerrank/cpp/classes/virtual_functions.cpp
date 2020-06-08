#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    public:
    string name;
    int age;
    virtual void getdata() {}
    virtual void putdata () {}
};

class Professor : public Person {
    public:
    int publications, cur_id;
    Professor () {
        static int prof_id = 0;
        prof_id++;
        cur_id = prof_id;
    }
    void getdata() {
        cin >> name >> age >> publications;
    }
    void putdata() {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

class Student : public Person {
    public:
    int marks[6], cur_id;
    Student () {
        static int stud_id = 0;
        stud_id++;
        cur_id = stud_id;
    }
    void getdata(){
        cin >> name >> age;
        for (int i = 0; i < 6; ++i){
            cin >> marks[i];
        }
    }
    void putdata(){
        cout << name << " " << age << " ";
        long sum = 0;
        for (int i = 0; i < 6; ++i){
            sum += marks[i];
        }
        cout << sum << " " << cur_id << endl;
    }
};
int main(){