/*Write the class AddElements here*/
template <class T>
class AddElements {
    public:
        T element;

        AddElements(T elem) : element(elem) {};
        
        T add(T elem) {
            element += elem;
            return element;
        }

        T concatenate(T elem) {
            element += elem;
            return element;
        }
};