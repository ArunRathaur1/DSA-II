#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
int steadyGene(string s) {
   unordered_map<char,int>st;
   for(int i=0;i<s.length();i++){
    st[s[i]]++;
   }
   int left=0;
   int right=0;
   int idealcount=s.length()/4;
   int minlength=INT_MAX;
   if(st['A']==st['G']&&st['A']==st['C']&&st['A']==st['T'])return 0;
   while (right<s.length())
   {
     st[s[right]]--;
     right++;
     while(left<right && st['A']<=idealcount&&st['G']<=idealcount&&st['C']<=idealcount&&st['T']<=idealcount){
        minlength=min(minlength,right-left);
        st[s[left]]++;
        left++;

     }   
   }

   cout<<minlength<<endl;
   return minlength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

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
