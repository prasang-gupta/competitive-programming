void counterspell(Spell *spell) {

  /* Enter your code here */
    if (typeid(*spell) == typeid(Fireball)){
        ((Fireball*)spell)->revealFirepower();
    }
    else if (typeid(*spell) == typeid(Frostbite)){
        ((Frostbite*)spell)->revealFrostpower();
    }
    else if (typeid(*spell) == typeid(Thunderstorm)){
        ((Thunderstorm*)spell)->revealThunderpower();
    }
    else if (typeid(*spell) == typeid(Waterbolt)){
        ((Waterbolt*)spell)->revealWaterpower();
    }
    else{
        string a = spell->revealScrollName();
        string b = SpellJournal::journal;
        
        vector < vector <int>> dp(a.size() + 1, vector <int> (b.size() + 1, 0));
        for (int i = 1; i < a.size()+1; ++i){
            for (int j = 1; j < b.size()+1; ++j){
                if (a[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[a.size()][b.size()] << endl;
    }
}