#include <iostream>
#include <vector>



/*
    Bank analyzer
    Must have type of transaction
    Amount of spend money 
    top up cash and widthdraw
    show biggest and cheapest money spend
    analyze amount of transactions
    analyze the most used type of transaction


*/

class Transaction{
    public:
    std::string type = "";
    std::string category = "";
    double money_amount = 0;
    std::string date = "";
    std::string description = "";
};



int main(){
    std::vector<Transaction> transactions;   
}

//Function to load transactions from the file
void load_transactions(std::vector<Transaction>& transactions){

}

//Function to save transactions to the file
void save_transactions(std::vector<Transaction>& transactions){
    Transaction transaction;

    std::string type = "";
    std::string category = "";
    double money_amount = 0;
    std::string date = "";
    std::string description = "";

    std::cout << "Please enter date of the transaction: ";
    std::cin.clear(); std::cin.ignore(10000);
    std::getline(std::cin, date);
    std::cout << "Please input type of your transaction(spend/earn): ";
    std::cin >> type;
    std::cout << "Please enter category of your transaction: ";
    std::cin.clear(); std::cin.ignore(10000);
    std::getline(std::cin, category);
    std::cout << "Please enter amount of money on this transaction: ";
    std::cin >> money_amount;
    std::cout << "Enter description to the transaction: ";
    std::cin.clear(); std::cin.ignore(10000);
    std::getline(std::cin, description);

    transaction.category = category;
    transaction.date = date;
    transaction.description = description;
    transaction.money_amount = money_amount;
    transaction.type = type;

    transactions.push_back(transaction);
    //save_transaction(transactions)
}

//Function to create new transaction to the list
void create_transaction(std::vector<Transaction>& transactions){

}

//Function to show the main menu of the program
void show_menu(std::vector<Transaction>& transactions){

}