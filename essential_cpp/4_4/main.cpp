#include<string>
#include<iostream>
#include<map>
#include<cstdlib>
#include "userprofile.h"

 using namespace std;

int main(){
   
    UserProfile anon;    // test output operation
    cout << anon;

    UserProfile anon_too; // test whether unique or not
    cout << anon_too;

    UserProfile anna("AnnaL", UserProfile::Guru);
    cout << anna;

    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();

    cout << anna;

    cin >> anon;
    cout << anon;
}
