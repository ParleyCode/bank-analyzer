#include <iostream>
#include <vector>
#include <algorithm>



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
void delete_transaction(std::vector<Transaction>& transactions);
void change_transaction(std::vector<Transaction>& transactions);
std::string to_upper(std::string text);




int main(){
    std::vector<Transaction> transactions;   
    show_menu(transactions);
}

//Function to load transactions from the file
void load_transactions(std::vector<Transaction>& transactions){

}

//Function to save transactions to the file
void create_transaction(std::vector<Transaction>& transactions){
    Transaction transaction;
    bool type_succes = false;
    std::string type = "";
    std::string category = "";
    double money_amount;
    std::string date = "";
    std::string description = "";

    std::cout << "Please enter date of the transaction: ";
    std::cin.clear(); std::cin.ignore(10000, '\n');
    std::getline(std::cin, date);
    do{
        std::cout << "Please enter type of the transaction(earn/spend): ";
        std::getline(std::cin, type);
        if(type != "earn" && type != "spend"){
            std::cout << "Incorrect input! \n";
        }
        else{
            type_succes = true;
        }
    }while(type_succes == false);

    std::cout << "Please enter category of your transaction: ";
    std::getline(std::cin, category);
    std::cout << "Please enter amount of money on this transaction: ";
    while(!(std::cin >> money_amount)){

    std::cin >> money_amount;
    if(!(std::cin >> money_amount)){
        std::cout << "Incorrect input!\n";
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Please enter amount of money on this transaction: ";

    }
    }
    std::cout << "Enter description to the transaction: ";
    std::cin.clear(); std::cin.ignore(10000, '\n');
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
void save_transactions(std::vector<Transaction>& transactions){

}

//Function to show the main menu of the program
void show_menu(std::vector<Transaction>& transactions){
    int choise = 0;

    while(true){
        std::cout << "\n=-_-=-_-=BANK TRANSACTION LIST=-_-=-_-=\n"<<"1. Create transaction\n"
        <<"2. Show transaction list\n"<<"3. Delete transation\n"<<"4. Change transaction\n"
        <<"5. Find transaction\n"<<"7. Show only income\n"<<"8. Show only spendings\n"
        <<"9. Save and Quit\n"<<"""=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=";
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
            delete_transaction(transactions);           
        }
        else if(choise == 4){
            change_transaction(transactions);
        }
        else if(choise == 5){

        }
        else if(choise == 6){

        }
        else if(choise == 7){
            
        }
        else if(choise == 8){

        }
        else if(choise == 9){
            save_transactions(transactions);
            exit(0);
        }
        else{
            std::cout << "\nIncorrect input\n\n";
        }
    }
}

void list_transactions(std::vector<Transaction>& transactions){
    Transaction transaction;
    int counter = 0;
    std::string spam;
    if(!(transactions.empty())){
        for(const auto& block : transactions){
            ++counter;
            if(block.type == "spend"){
            std::cout << counter << ".|\t " << block.date<< "|\t  "<< block.category
            <<"|\t  \033[31m"<<to_upper(block.type)<<"\033[0m|\t  "<< block.money_amount << "|\t  " << block.description<<"|\n"; 
        }
        else{
            std::cout << counter << ".|\t " << block.date<< "|\t  "<< block.category
            <<"|\t  \033[32m"<<to_upper(block.type)<<"\033[0m|\t  "<< block.money_amount << "|\t  " << block.description<<"|\n"; 
        }
        }
    }
    else{
        std::cout << "There is nothing to list :( \n";
    }
    std::cout << "Please press any button ENTER to continue ";
    std::cin >> spam;
}

void delete_transaction(std::vector<Transaction>& transactions){
    int choise = 0;
    bool succes = false;

    list_transactions(transactions);
    if(transactions.empty()){
        //Skip
    }

    else{
        std::cout << "Please enter which transaction you want to delete: ";

    do{
        if(!(std::cin >> choise) || choise > transactions.size() || choise <= 0){
            std::cout << "Incorrect input!";
            std::cin.clear();std::cin.ignore(10000, '\n');
            std::cout << "\nPlease enter which transaction you want to delete: ";

        }
        else{
            transactions.erase(transactions.begin(), transactions.begin() + choise);
            save_transactions(transactions);
            succes = true;
        }
    }while(succes == false);
    }
}

void change_transaction(std::vector<Transaction>& transactions){
    list_transactions(transactions);

    Transaction block;
    int choise = 0;
    bool succes = false;
    bool money_succes = false;
    bool type_succes = false;
    std::string date;
    std::string description;
    std::string type;
    std::string category;
    double money_amount = 0.0;

    if(transactions.empty()){
        //Skip
    }
    else{
    std::cout << "Please enter which transaction you want to change: ";
    do{
        std::cin >> choise;
        if(!std::cin >> choise || choise > transactions.size() || choise <= 0){
            std::cout << "Incorrect input";
            std::cin.clear();std::cin.ignore(10000, '\n');
            std::cout << "\nPlease enter which transaction you want to change: ";
        }
        else{
            std::cin.clear();std::cin.ignore(10000, '\n');
            std::cout << "Please enter new date of the transaction: ";
            std::getline(std::cin, date);
            std::cout << "Please enter new category of the transaction: ";
            std::getline(std::cin, category);
            do{
                std::cout << "Please enter new type of the transaction: ";
                std::getline(std::cin, type);
                if(type != "earn" && type != "spend"){
                    std::cout << "Incorrect input! \n";
                }
                else{
                    type_succes = true;
                }
            }while(type_succes == false);

            do{
                std::cout << "Please enter new amount of money: ";
                if(!(std::cin >> money_amount)){
                    std::cout << "Incorrect input! \n";
                    std::cin.clear(); std::cin.ignore(10000, '\n');                }
                else{
                    money_succes = true;
                }
            }while(money_succes == false);

            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::cout << "Please enter new description of the transaction: ";
            std::getline(std::cin, description);

            transactions[choise - 1].category = category;
            transactions[choise - 1].date = date;
            transactions[choise - 1].type = type;
            transactions[choise - 1].money_amount = money_amount;
            transactions[choise - 1].description = description;
            succes = true;
            save_transactions(transactions);
        }

    }while(succes == false);
}
}

std::string to_upper(std::string text){
    std::transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) {
            return std::toupper(c);
        });

    return text;
}