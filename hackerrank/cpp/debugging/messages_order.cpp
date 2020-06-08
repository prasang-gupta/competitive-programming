class Message {
private:
    string m;
    static int id;
    int current_id;
public: 
    Message() {current_id = ++id;}
    Message (string s) : m(s) {current_id = ++id;}
    const string& get_text() {
        return m;
    }
    bool operator < (const Message& a) {
        return current_id < a.current_id;
    }
};
int Message::id = 0;

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message temp(text);
        return temp;
    }
};