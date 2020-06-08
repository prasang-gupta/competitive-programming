class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            int temp = new_val;
            while (temp % 2 == 0){
                temp /= 2;
                A::func(val);
            }

            temp = new_val;
            while (temp % 3 == 0){
                temp /= 3;
                B::func(val);
            }

            temp = new_val;
            while (temp % 5 == 0){
                temp /= 5;
                C::func(val);
            }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};
