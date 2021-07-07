#include<bits/stdc++.h>
using namespace std;

string get(int k) {
  if (k < 10) return "input00" + to_string(k) + ".txt";
  else return "input0" + to_string(k) + ".txt";
}
string get2(int k) {
  if (k < 10) return "output00" + to_string(k) + ".txt";
  else return "output0" + to_string(k) + ".txt";
}
int32_t main() {
  string inn, outt;
  for (int i = 1; i <= 10; i++) {
    inn = get(i);
    outt = get2(i);
    double c = clock();
    string ww = "orig-" + outt;
    string st = "original < " + inn + " > " + ww;
    system(st.c_str());
    ifstream orig(ww, ios::in); 
    string s;
    orig >> s;
    cout << s << ' ';
    ww = "random-" + outt;
    st = "random < " + inn + " > " + ww;
    system(st.c_str());
    ifstream random(ww,ios::in);
    random >> s;
    cout << s << ' ';
    ww = "greedy-" + outt;
    st = "greedy < " + inn + " > " + ww;
    system(st.c_str());
    ifstream greedy(ww,ios::in);
    greedy >> s;
    cout << s << ' ';
    ww = "best-" + outt;
    st = "best < " + inn + " > " + ww;
    system(st.c_str());
    ifstream best(ww,ios::in);
    best >> s;
    cout << s << ' ';
    cout << '\n';
    orig.close();
    random.clear();
    greedy.close();
    best.close();
    cerr << i << " " << (clock()-c)/CLOCKS_PER_SEC << "s" << endl;
  }
  return 0;
}