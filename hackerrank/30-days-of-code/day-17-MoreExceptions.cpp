//Write your code here

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "n and p should be non-negative";
  }
} myex;

class Calculator {
    public:
        int power (int n, int p) {
            if (n < 0 || p < 0){
                throw myex;
            }
            return pow(n, p);
        }
};