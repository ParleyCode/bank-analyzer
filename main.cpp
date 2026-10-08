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


void create_transaction(std::vector<Transaction>& transactions);
void save_transactions(std::vector<Transaction>& transactions);
void load_transactions(std::vector<Transaction>& transactions);
void show_menu(std::vector<Transaction>& transactions);
void list_transactions(std::vector<Transaction>& transactions);




int main(){
    std::vector<Transaction> transactions;   
    show_menu(transactions);
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
    //save_transaction
}

//Function to create new transaction to the list
void create_transaction(std::vector<Transaction>& transactions){

}

//Function to show the main menu of the program
void show_menu(std::vector<Transaction>& transactions){
    int choise = 0;

    while(true){
        std::cout << "=-_-=-_-=BANK TRANSACTION LIST=-_-=-_-=\n"<<"1. Create transaction\n"
        <<"2. Show transaction list\n"<<"3. Delete transation\n"<<"4. Change transaction\n"
        <<"5. Find transaction\n"<<"7. Show only income\n"<<"8. Show only spendings\n"
        <<"=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=";
        std::cout << "\nPlease enter what you want to do: ";
        std::cin >> choise;

        if(!std::cin >> choise){
            std::cout << "\nIncorrect input\n\n";
            std::cin.clear();std::cin.ignore(100000, '\n');
            continue;
        }

        if(choise == 1){
            create_transaction(transactions);
        }
        else if(choise == 2){
            list_transactions(transactions);
        }
        else if(choise == 3){

        }
        else if(choise == 4){

        }
        else if(choise == 5){

        }
        else if(choise == 6){

        }
        else if(choise == 7){
            
        }
        else if(choise == 8){

        }
        else{
            std::cout << "\nIncorrect input\n\n";
        }
    }
}

void list_transactions(std::vector<Transaction>& transactions){

}
