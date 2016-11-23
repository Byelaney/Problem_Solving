class Student :  public Person{
	private:
		vector<int> testScores;
	public:
  		// Write your constructor
        Student(string firstName, string lastName, int identification, vector<int> scores) :
        Person(firstName, lastName, identification), testScores(scores) { }
  		char calculate() {
            double sum = 0;
            for (int i = 0;i<testScores.size();++i) {
                sum += testScores[i];
            }
            sum /= 1.0 * (testScores.size());
            if (sum >= 90 && sum <= 100)
                return 'O';
            else if (sum >=80 && sum < 90)
                return 'E';
            else if (sum >=70 && sum < 80)
                return 'A';
            else if (sum >=55 && sum < 70)
                return 'P';
            else if (sum >= 40 && sum < 55)
                return 'D';
            else
                return 'T';
        }
};
