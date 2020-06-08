class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here

        Student (string fn, string ln, int identification, vector <int> s) 
        : Person (fn, ln, identification) , testScores (s) {}

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here

        char calculate () {
            long avg = 0;
            for (int i = 0; i < testScores.size(); ++i){
                avg += testScores[i];
            }
            avg /= testScores.size();

            if (avg >= 90)
                return 'O';
            else if (avg >= 80)
                return 'E';
            else if (avg >= 70)
                return 'A';
            else if (avg >= 55)
                return 'P';
            else if (avg >= 40)
                return 'D';
            return 'T';
        }
};