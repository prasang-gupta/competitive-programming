/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle {
    public:
    int height, width;

    void display() {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle {
    public:

    void read_input() {
        cin >> width >> height;
    }

    void display() {
        cout << width*height << endl;
    }
};