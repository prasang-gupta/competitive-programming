// Define specializations for the Traits class template here.
template <typename T> struct Traits {
    static string name(int i) {
        switch (i){
            case 0: return (typeid(T) == typeid(Color)) ? "red" : "apple";
            case 1: return (typeid(T) == typeid(Color)) ? "green" : "orange";
            case 2: return (typeid(T) == typeid(Color)) ? "orange" : "pear";
            default: return "unknown";
        }
    }
};