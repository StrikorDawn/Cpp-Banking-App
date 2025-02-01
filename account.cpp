#include "account.h"
#include <iostream>
#include <string>

Account::Account(): id(0), balance(0), name("Test")
{

}

Account::Account(int id, std::string name, float balance): id(id), name(name), balance(balance)
{

}

void Account::create_accout(int account_id)
{
	std::string account_name;
	float starting_balance;

	std::cout << "Enter the name for the account: ";
	std::getline(std::cin >> std::ws, account_name); // Use std::getline to read the entire line
	std::cout << "Enter the starting balance for the account: $";
	std::cin >> starting_balance;

	id = account_id;
	name = account_name;
	balance = starting_balance;
}

void Account::display_account_info() const
{
	std::cout << "\nAccount ID: " << id << "\tName: " << name << "\tBalance: $" << balance << std::endl;
	if (contact_info != nullptr)
	{
		contact_info->display();
	}
}

void Account::deposit(float deposit)
{
	balance += deposit;
}

void Account::withdrawl(float withdraw)
{
	balance -= withdraw;
}

int Account::get_id()
{
	return id;
}

std::string Account::get_name()
{
	return name;
}

float Account::get_balance()
{
	return balance;
}

void Account::add_contact_info()
{
	contact_info = std::make_shared<Contact>();
	contact_info->add_contact_info();
}
