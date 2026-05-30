#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'calculateWays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER wordLen
 *  2. INTEGER maxVowels
 */

int calculate_factorial(int n){
    int product = 1;
    for (int i=n; i>=1; i--){
        product *= i;
    }
    return product;
}

int calc_n_choose_k(int n, int k){
    return (calculate_factorial(n)/calculate_factorial(n-k));
}

int calculateWays(int wordLen, int maxVowels) {
    int vowels = 5; 
    int consonants = 21;
    int ways = 0;
    int vow_ways=0;
    
    
    for (int i=maxVowels; i<=0; i--){
        vow_ways = calc_n_choose_k(wordLen, i);
        cout<<"ways for vowels ="<<vow_ways<<endl;
        ways += vow_ways*((vowels^i)*(consonants^(wordLen-i)));
        cout<<"ways "<<ways<<endl;
    }
        
    
    
    
    return ways;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string wordLen_temp;
    getline(cin, wordLen_temp);

    int wordLen = stoi(ltrim(rtrim(wordLen_temp)));

    string maxVowels_temp;
    getline(cin, maxVowels_temp);

    int maxVowels = stoi(ltrim(rtrim(maxVowels_temp)));

    int result = calculateWays(wordLen, maxVowels);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
