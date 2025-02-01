#include "contact.h"
#include <iostream>
#include <format>
#include <string>
using namespace std;

Contact::Contact()
{
	street_address = "";
	city = "";
	state = "";
	zip_code = "";
	phone_number = "";
}

void Contact::set_street_address()
{
	cout << "Enter Address: ";
	getline(cin, street_address);
}

void Contact::set_city()
{
	cout << "Enter City: ";
	getline(cin, city);
}

void Contact::set_state()
{
	cout << "Enter State: ";
	getline(cin, state);
}

void Contact::set_zip()
{
	cout << "Enter Zip Code: ";
	getline(cin, zip_code);
}

void Contact::set_phone_number()
{
	cout << "Enter Phone Number: ";
	getline(cin, phone_number);
}


void Contact::add_contact_info()
{
	cin.ignore();
	set_street_address();
	set_city();
	set_state();
	set_zip();
	set_phone_number();
}

string Contact::get_street_address()
{
	return street_address;
}

string Contact::get_city()
{
	return city;
}

string Contact::get_state()
{
	return state;
}

string Contact::get_zip()
{
	return zip_code;
}

string Contact::get_phone_number()
{
	return phone_number;
}

void Contact::display()
{
	cout << "+ Contact Information : Address: " << street_address << " City : " << city << \
		" State: " << state << " Zip: " << zip_code << " Phone: " << phone_number << endl;
}


