// Banking App with Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include "account.h" 

int menu() {
    int choice = -1;
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "Account Menu:" << std::endl;
    std::cout << "0. Quit Program" << std::endl;
    std::cout << "1. Display Account Information" << std::endl;
    std::cout << "2. Add a deposit to an account" << std::endl;
    std::cout << "3. Withdraw from an account" << std::endl;
    std::cout << "4. Add new account" << std::endl;
    std::cout << "5. Find account by ID" << std::endl;
    std::cout << "6. Remove account" << std::endl;
    std::cout << "7. Show total balance for all accounts" << std::endl;
    std::cout << "8. Add a dividend to all accounts" << std::endl;
    std::cout << "9. Add contact information to an account" << std::endl;
    std::cout << "Your Choice: ";
    std::cin >> choice, "\n";
    return choice;
}

int add_account(std::list<Account>& accounts,int id) {
    Account new_account;
    new_account.create_accout(id);
    accounts.push_back(new_account);
    return id += 1;
}

void display_all_accounts(std::list<Account> account_list) {
    // This is how you can use iterators in a loop.
    /*std::list<Account>::iterator it;
    for (it = account_list.begin(); it != account_list.end(); it++) {
        it->display_account_info();
    }*/

    // This uses the Algorithm Library, requires 2 iterators and a Lambda Function.
    for_each(account_list.begin(), account_list.end(), [](auto& account) {
        account.display_account_info();
        });
}

std::list<Account>::iterator find_account(std::list<Account>& account_list, int id) {

    std::list<Account>::iterator it;
    for (it = account_list.begin(); it != account_list.end(); it++)
    {
        if (it->get_id() == id)
        {
            return it; // Return iterator to Person matching the ID
        }
    }

    return it;
}

void remove_account(std::list<Account>& accounts, int id) {
    auto end = remove_if(accounts.begin(), accounts.end(), [id](auto& account) {
        return id == account.get_id();
        });
    accounts.erase(end, accounts.end());
}

void select_account(std::list<Account>& account_list, int nav) {
    int account_id;
    float amount = 0;
    std::cout << "Enter the ID of the account to find : ";
    std::cin >> account_id;

    std::list<Account>::iterator it = find_account(account_list, account_id);

    if (it != account_list.end()) {
        std::cout << "Found account : ";
        it->display_account_info();
        if (nav == 2) {
            std::cout << "\nEnter the amount you would like to deposit: $";
            std::cin >> amount;
            it->deposit(amount);
        }
        else if (nav == 3) {
            std::cout << "\nEnter the amount you would like to withdrawl: $";
            std::cin >> amount;
            it->withdrawl(amount);
        }
        else if (nav == 9) {
            it->add_contact_info();
        }
    }
    else {
            std::cout << "ID: " << account_id << " was not found!" << std::endl;
    }
}

void display_bank_total(std::list<Account>& accounts_list) {
    float total = accumulate(accounts_list.begin(), accounts_list.end(), 0.0,
        [](auto accumulator, auto& member) {
            return accumulator + member.get_balance();
        }
    );
    std::cout << "Total in all accounts: " << total << std::endl;
}

void add_dividend(std::list<Account>& accounts_list, float dividend) {
    float interest = dividend / 100;
    transform(accounts_list.begin(), accounts_list.end(), accounts_list.begin(),
        [interest](auto& account) {
            account.deposit(account.get_balance() * interest);
            return account;
        }
    );


}


int main()
{ 
    int id = 0;
    int nav;
    int remove_id;
    float dividend;
    std::list<Account> accounts;
    do {
        try {
            nav = menu();
            if (nav == 1) {
                display_all_accounts(accounts);
            }
            else if (nav == 2) {
                select_account(accounts, nav);
               
            }
            else if (nav == 3) {
                select_account(accounts, nav);

            }
            else if (nav == 4) {
                id = add_account(accounts, id);
            }
            else if (nav == 5) {
                select_account(accounts, nav);
            }
            else if (nav == 6) {
                std::cout << "Enter account ID to remove: ";
                std::cin >> remove_id;
                remove_account(accounts, remove_id);
            }
            else if (nav == 7) {
                display_bank_total(accounts);
            }
            else if (nav == 8) {
                std::cout << "Enter the dividend as a percentage: ";
                std::cin >> dividend;
                add_dividend(accounts, dividend);
            }
            else if (nav == 9) {
                select_account(accounts, nav);
            }
            else if (nav == 0) {
                std::cout << "\nThank you for banking with us!!!" << std::endl;
            }
        }
        catch (std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
            std::cout << "'" << nav << "'" << "is not a valid input. Please try again." << std::endl;
        }
    } 
    while (nav != 0);
}
