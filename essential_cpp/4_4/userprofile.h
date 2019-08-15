/*
 *
 *
 *
 *
 *
 */
#ifndef _USERPROFILE_H
#define _USERPROFILE_H

#include<iostream>
#include<string>
#include<map>

using namespace std;

class UserProfile{
	
	public:
		enum uLevel{Beginner, Intermediate, Advanced, Guru};
		
		UserProfile(string login, uLevel = Beginner);
		UserProfile();

		/*
		 * default memberwise initialization和default memberwise copy
		 * 已经足够，不必另外设计copy constructor或copy assign operator，
		 * 也不心要destructor
		 */

		bool operator==(const UserProfile&);
		bool operator!=(const UserProfile&);

		/*
		 * 以下函数用来读取数据
		 */
		string login() const {return _login;}
		string user_name() const {return _user_name;}
		int login_count() const {return _times_logged;}
		int guess_count() const {return _guesses;}
		int guess_correct() const {return _correct_guesses;}
		double guess_average() const;
		string level() const;

		/*
		 * 以下函数用来写入数据
		 */
		void reset_login(const string& val) {_login = val;}
		void user_name(const string& val) {_user_name = val;}
		
		void reset_level(const string&);
		void reset_level(uLevel newlevel) {_user_level = newlevel;}

		void reset_login_count(int val){_times_logged = val;}
		void reset_guess_count(int val){_guesses = val;}
		void reset_guess_correct(int val){_correct_guesses = val;}

		void bump_login_count(int cnt = 1){_times_logged += cnt;}
		void bump_guess_count(int cnt = 1){_guesses += cnt;}
		void bump_guess_correct(int cnt = 1){_correct_guesses += cnt;}

	private:
		string _login;
		string _user_name;
		int _times_logged;
		int _guesses;
		int _correct_guesses;
		uLevel _user_level;

		static map<string,uLevel> _level_map;
		static void init_level_map();
		static string guest_login();

};

std::istream& operator>>(std::istream& is, UserProfile& rhs);
std::ostream& operator<<(std::ostream & os, const UserProfile& rhs);


#endif
