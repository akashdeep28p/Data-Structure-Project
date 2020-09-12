#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
using namespace std;


class LRU{
public:
    list<string> li ;
    unordered_map<string , pair<string , list<string>::iterator>> mp;

    int capacity ;
    LRU(int capacity){
        this->capacity = capacity;
    }

    string get(string name){
        if(mp.count(name)){
            string msg = mp[name].first;
            li.erase(mp[name].second);
            li.push_front(name);
            mp[name].second = li.begin();
            return msg;

        }else{
            
            return "No message yet !\n";
        }

    }


    void newMessage(string name , string msg){

        if(mp.count(name)){
            li.erase(mp[name].second);
            li.push_front(name);
            mp.erase(name);
            mp[name] = {msg , li.begin()};
        }else{
            if(li.size()==capacity){
                li.pop_back();
                li.push_front(name);
                mp[name] = {msg , li.begin()};
            }else{
                li.push_front(name);
                mp[name]={msg , li.begin()};
            }

        }
    }

    void msgOnTop(){
        string s= *li.begin();
        cout<<s<<" -> "<<mp[s].first<<'\n';
    }

};

int32_t main(){   

fastio
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt","w", stdout);
#endif

LRU chatList(10);
chatList.newMessage("Akash" , "Hey!");
chatList.msgOnTop();

chatList.newMessage("John" , "What you doin this weekend ?");
chatList.msgOnTop();

chatList.newMessage("Tim" , "I gotta go");
chatList.msgOnTop();

cout<<chatList.get("Akash")<<'\n';
chatList.msgOnTop();

cout<<chatList.get("William")<<'\n';


return 0;
}
