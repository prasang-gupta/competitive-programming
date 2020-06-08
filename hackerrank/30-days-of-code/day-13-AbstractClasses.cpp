// Write your MyBook class here

class MyBook : public Book {
public:
    int price;

    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    
    MyBook (string t, string a, int p) : Book (t, a), price(p) {}
    
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here

    virtual void display () {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: " << price << endl;
    }

// End class

};