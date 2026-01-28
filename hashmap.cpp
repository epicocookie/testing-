#include <bits/stdc++.h>
//we be having iostream, functional, string and vector here
using namespace std;

struct user {
    string username; 
    bool empty = true;
};

//creating a func for hash
size_t hash_func (const string& s) {
    return std::hash <std::string>{} (s);
}

int main () {
    //creating the people/bucket we want to fill for example like 1k users
    vector <user> people (1000);
    user person;
    size_t index = hash_func("boblaney") % people.size();
    people[index].username = "boblaney";
    people[index].empty = false;
    
    cout << "Stored at index: " << index << endl;

    for (int i = index; i < people.size() ;i++) {
        //if found successfully 
        if (people[i].empty) {                   // Not Found
            cout << "Not found\n";
            return 0;
        }
        else if (people[i].username == "boblaney") { // Success!
            
            cout << "Success! Logged in as " << "boblaney\n";
            return 0;
        }
    
    }



    return 0;
}