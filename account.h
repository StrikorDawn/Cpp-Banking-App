#pragma once
#include <string>
#include <iostream>
#include "contact.h"
class Account
{
private:
	int id;
	float balance;
	std::string name;

	std::shared_ptr<Contact> contact_info;

public:
	Account();

	Account(int id, std::string name, float balance);

	void create_accout(int id);

	void display_account_info() const;

	void deposit(float amount);

	void withdrawl(float amount);

	int get_id();

	std::string get_name();

	float get_balance();

	void add_contact_info();

};

