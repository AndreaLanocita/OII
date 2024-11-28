#include <bits/stdc++.h> 

using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long int
#define omap map<int, int>
#define umap unordered_map<int, int>

string read_string_from_file(const string &file_path) {
    const ifstream input_stream(file_path, std::ios_base::binary);

    if (input_stream.fail()) {
        throw std::runtime_error("Failed to open file");
    }

    std::stringstream buffer;
    buffer << input_stream.rdbuf();

    return buffer.str();
}

bool anagramma(string s1, string s2) {
    int check[26] = {};
    if(s1.size()!=s2.size()) return 0;
    for(char a: s1) {
        check[a-97]++;
    }

    for(char a: s2) {
        check[a-97]--;
    }

    for(int i=0; i<26; i++) {
        if(check[i]!=0) return 0;
    }
    return 1;
}

int calcW(string s) {
    int w =0;
    for(int i=0; i<s.size(); i++) {
        w += s[i]-97;
    }
    return w;
}

int main() {
    freopen("D:\\olimpiadi di info\\output.txt", "w", stdout);
    freopen("D:\\olimpiadi di info\\input.txt", "r", stdin);
    int N = 10000;
    // string a = read_string_from_file("D:\\olimpiadi di info\\input.txt");
    // cout << a;

    vector<string> words;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }

    string s = "while";
    for(int i=0; i<5; i++) {
        s[i] = (s[i]-97+4)%26+97;
        cout << s[i];
    }

    cout << endl;
    int maxx=-1; string s1;
    for(int i=0; i<N; i++) {
        s1 = words[i];
        for(int k=1; k<26; k++) {
            for(int j=0; j<words[i].size(); j++) {
                s1[j] = (s1[j]-97+k)%26+97;
                for(int e=0; e<N; e++) {
                    if(anagramma(s1, words[e])) {
                        maxx = max(maxx, calcW(words[i]));
                    }
                }
            }
        }
    }

    cout << maxx;
    
    return 0;
}