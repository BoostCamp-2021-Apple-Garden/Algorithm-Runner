#include <iostream>
#include <vector>
using namespace std;

vector<string> read, write;
bool shouldWait;

vector<string> split(string s) {
    vector<string> v;
    string temp = "";
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(temp);
            temp = "";
        } else {
            temp += s[i];
        }
    }
    v.push_back(temp);
    return v;
}

int main(void) {
    string str;
    while (true) {
        char s[50];
        fgets(s, sizeof(s), stdin);
        str = s;
        shouldWait = false;
        str.pop_back();
        if (str == "EXIT") {
            cout << "EXIT" << endl;
            break;
        }
        
        vector<string> v = split(str);
        string r = v[1];
        
        for (int i=0; i<write.size(); i++) {
            if (r == write[i]) {
                shouldWait = true;
                break;
            }
        }

        if (shouldWait == false && v.size() == 4) {
            string w = v[3];
            for (int i=0; i<read.size(); i++) {
                if (w==read[i]) {
                    shouldWait = true;
                    break;
                }
            }
            for (int i=0; i<write.size(); i++) {
                if (w==write[i]) {
                    shouldWait = true;
                    break;
                }
            }
        }

        if (shouldWait) {
            cout << "WAIT" << endl;
            read.clear();
            write.clear();
        }
        read.push_back(r);
        if (v.size() == 4) write.push_back(v[3]);

        cout << str << endl;
    }
    return 0;
}