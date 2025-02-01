#pragma once
#include <string>
#include <iostream>
using namespace std;
class Contact
{
private:
	string street_address;
	string city;
	string state;
	string zip_code;
	string phone_number;

public:
	Contact();
	void set_street_address();
	void set_city();
	void set_state();
	void set_zip();
	void set_phone_number();
	void add_contact_info();
	string get_street_address();
	string get_city();
	string get_state();
	string get_zip();
	string get_phone_number();
	void display();
};

