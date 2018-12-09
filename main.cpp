#include <iostream>
#include <string>
#include <map>
using namespace std;
    string s;
    map <string,string[10]> IDMAP;
void dec(int j){

    string levstr[10];

    int level = 0;
    int i,maxlev,len;
    int leftp = 0;
    string typ;
    string id;

    //cin >> s;
    maxlev = 0;
    for(i=j;isalpha(s[i]);i++){
        typ += s[i];
    }
    while(s[i]!=';' && s[i]!=','){
        while(isalpha(s[i])){
           id += s[i];
           i++;
        }
        if(s[i] == '*'){
            levstr[level] += s[i];
            i++;
        }
        if(s[i] == '['){
            while(s[i] != ']'){
                levstr[level] += s[i];
                i++;
            }
            levstr[level] += s[i];
            i++;
        }
        if(s[i] == '('){
            level++;
            i++;
            maxlev++;
        }
        if(s[i] == ')'){
            level--;
            i++;
        }
        if(s[i] == ' '){
            i++;
        }
    }
    level = maxlev;
    IDMAP.insert(map<string, string[10]>::value_type (id,levstr));
//   IDMAP[id]=levstr;
    //0//for (i=0;i<10;i++)
    //    IDMAP[id][i]=levstr[i];
    if (s[i]==',')
    {
        dec(i+1);
    }
    while(level >= 0){
        len = levstr[level].length();
        i = 0;
        while(levstr[level][i] != '[' && i < len-1){
            i++;
        }
        while(levstr[level][i] == '['){
            cout << "array(";
            leftp++;
            i++;
            while(isdigit(levstr[level][i])){
               cout << levstr[level][i];
               i++;
            }
            //cout << levstr[level][i];
            cout << ',';
            i++;
            if(i == len){
                break;
            }
        }
        i = 0;
        while(levstr[level][i] == '*' && i < len){
            i++;
        }
        i--;
        while(i >= 0){
            cout << "pointer(";
            leftp++;
            i--;
        }
        if(level == 0){
            cout << typ;
            while(leftp > 0){
                cout << ')';
                leftp--;
            }
        }
        level--;
    }
    cout << endl;
}

int main()
{
    getline(cin,s);
    dec(0);
    return 0;
}
