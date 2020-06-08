/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
    private:
        int age, standard;
        string first_name, last_name;
    
    public:
        void set_age(int a) {
            age = a;
        }
        void set_standard(int a) {
            standard = a;
        }
        void set_first_name(string a) {
            first_name = a;
        }
        void set_last_name(string a) {
            last_name = a;
        }

        int get_age() {
            return age;
        }
        int get_standard() {
            return standard;
        }
        string get_first_name() {
            return first_name;
        }
        string get_last_name() {
            return last_name;
        }

        string to_string() {
            stringstream ss;
            ss << age << "," << first_name << "," << last_name << "," << standard << endl;
            return ss.str();
        }
};