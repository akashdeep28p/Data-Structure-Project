#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
using namespace std;


int32_t main(){   

fastio
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt","w", stdout);
#endif


int transactions , friends;
cin>>transactions>>friends;

string x ,y;
int amount;

map<string , int> net;

while(transactions--){

    cin>>x>>y;
    cin>>amount;

    net[x]-=amount;
    net[y]+=amount;
}

// insert the people whose transactions needs to be settled into muliset 
multiset<pair<int ,string>> m;

for(auto i: net){
    if(i.second != 0)m.insert({i.second , i.first});
}

int cnt =0 ;

while(!m.empty()){
    auto left = m.begin();
    auto right = prev(m.end());

    // pop the two person out becuase we need to settle them
    m.erase(left);
    m.erase(right);

    int debit = left->first;
    int credit = right->first;

    int settled_amt = min(abs(debit) , credit);

    string debit_person = left->second;
    string credit_person = right->second;

    debit+=settled_amt;
    credit-=settled_amt;

    //print the transaction between poeple 

    cout<<debit_person<<" will pay "<<settled_amt<<" to "<<credit_person<<'\n';

    if(debit != 0)m.insert({debit , debit_person});

    if(credit != 0)m.insert({credit , credit_person});

    cnt++;
}

cout<<"Total Transactions : "<<cnt<<'\n';

// Sample Test
// 3 3 
// rahul ajay 100
// ajay neha 50 
// neha rahul 40

// Expected output
// rahul will pay 50 to ajay
// rahul will pay 10 to neha
// Total Transactions : 2


return 0;
}
