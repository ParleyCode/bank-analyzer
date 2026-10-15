#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>



/*
    Bank analyzer
    Must have type of transaction
    Amount of spend money 
    top up cash and widthdraw
    show biggest and cheapest money spend
    analyze amount of transactions
    analyze the most used type of transaction

    function analyze:
    --Analyze circulation of money(is balance in + or -)
    --Analyze how much earns, spends
    --


*/

std::chrono::year_month_day date_unparse(std::string date);

enum class Color{
    Red,
    Green,
    Yellow
};

class Transaction{

    std::string type = "";
    std::string category = "";
    double money_amount = 0;
    std::string description = "";
    std::string str_date = "";

    std::chrono::year_month_day date;

    public:

    //Setters
    void setType(std::string type_str){
        type = type_str;
    }

    void setDescription(std::string newDescription){
        description = newDescription;
    }

    void setMoneyAmount(int newMoney){
        money_amount = newMoney;
    }

    void setCategory(std::string newCategory){
        category = newCategory;
    }

    void setDate(std::string strTypeDate){
        str_date = strTypeDate;
        date = date_unparse(strTypeDate);
    }


    //Getters
    std::chrono::year_month_day getChronoDate()const{
        return date;
    }

    double getMoneyAmount()const {
        return money_amount;
    }

    std::string getCategory() const{
        return category;
    }

    std::string getDescription() const{
        return description;
    }

    std::string getType()const{
        return type;
    }

    std::string getStrDate()const{
        return str_date;
    }
};

//Function that checks is date valid or not
bool isDateValid(std::string date){
    if(date.length()== 10){

    
        std::string day_part, month_part, year_part;

        std::stringstream str(date);

        std::getline(str, year_part, '-');
        std::getline(str, month_part, '-');
        std::getline(str, day_part, '-');

        try {
        int day = std::stoi(day_part);
        int month = std::stoi(month_part);
        int year = std::stoi(year_part);
    }
    catch (const std::invalid_argument&) {
        return false;
    }
    catch (const std::out_of_range&) {
        return false;
    }
    if(date_unparse(date).ok()){
        return true;
    }
    else{
        return false;
    }
    }
    else{
        return false;
    }
}

//Function to unparse string date to chrono value date
std::chrono::year_month_day date_unparse(std::string date){
    int year, month, day;
    std::string part, part1, part2;

    std::stringstream str(date);

    std::getline(str, part, '-');
    std::getline(str, part1, '-');
    std::getline(str, part2, '-');

    year = std::stoi(part);
    month = std::stoi(part1);
    day = std::stoi(part2);

    std::chrono::year_month_day int_date{
        std::chrono::year(year),
        std::chrono::month(month),
        std::chrono::day(day)
    };
    return int_date;
}

void show_information(std::vector<Transaction>& transactions);
void create_transaction(std::vector<Transaction>& transactions);
void save_transactions(std::vector<Transaction>& transactions);
void load_transactions(std::vector<Transaction>& transactions);
void show_menu(std::vector<Transaction>& transactions);
void list_transactions(std::vector<Transaction>& transactions);
void delete_transaction(std::vector<Transaction>& transactions);
void change_transaction(std::vector<Transaction>& transactions);
std::string to_upper(std::string text);
void find_transactions(std::vector<Transaction>& transactions);
void show_earning(std::vector<Transaction>& transactions);
void show_spending(std::vector<Transaction>& transactions);
void show_diapazone(std::vector<Transaction>& transactions);
std::string color_text(std::string x, Color color);




int main(){
    std::vector<Transaction> transactions;  
    load_transactions(transactions); 
    show_menu(transactions);
}

//Function to load transactions from the file
void load_transactions(std::vector<Transaction>& transactions){
    Transaction transaction;
    std::string type = "";
    std::string category = "";
    double money_amount = 0.0;
    std::string date = "";
    std::string description = "";

    std::ifstream fin;

    fin.open("transactions.txt");
    while (std::getline(fin, type)) {
        if (type.empty()) {
            continue;
        }
        std::getline(fin, category);
        if (category.empty()){
            continue;
        }
        std::getline(fin, date);
        if (date.empty()){
            continue;
        }
        std::getline(fin, description);
        if(description.empty()){
            continue;
        }

        fin >> money_amount;
        if(money_amount == 0.0){
            continue;
        }
        transaction.setCategory(category);
        transaction.setDate(date);
        transaction.setDescription(description);
        transaction.setType(type);
        transaction.setMoneyAmount(money_amount);

        transactions.push_back(transaction);
    }
}

//Function to save new transaction to the list
void save_transactions(std::vector<Transaction>& transactions){
    Transaction transction;
    std::ofstream fout;

    std::string type;
    std::string date;
    std::string description;
    std::string category;
    int money_amount;

    fout.open("transactions.txt");
    for(auto& block : transactions){
        type = block.getType();
        category = block.getCategory();
        date = block.getStrDate();
        description = block.getDescription();
        money_amount = block.getMoneyAmount();

        fout << type<<"\n";
        fout << category<<"\n";
        fout << date<<"\n";
        fout << description<<"\n";
        fout << money_amount<<"\n";

    }
}


//Function to create transactions 
void create_transaction(std::vector<Transaction>& transactions){
    Transaction transaction;
    bool date_succes = false;
    bool type_succes = false;
    std::string type = "";
    std::string category = "";
    double money_amount;
    std::string date = "";
    std::string description = "";

    std::cin.clear();std::cin.ignore(10000, '\n');
    do{
        std::cout << "\nPlease enter date of the transaction (YYYY-MM-DD): ";
        std::getline(std::cin, date);
        if(isDateValid(date) == true){
            date_succes = true;
        }
        else{
            std::cout << "Date input is incorrect";
        }
    }while(date_succes == false);

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
    if(!(std::cin >> money_amount)){
        std::cout << "Incorrect input!\n";
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Please enter amount of money on this transaction: ";

    }
    }
    std::cout << "Enter description to the transaction: ";
    std::cin.clear(); std::cin.ignore(10000, '\n');
    std::getline(std::cin, description);

    transaction.setCategory(category);
    transaction.setDate(date);
    transaction.setDescription(description);
    transaction.setMoneyAmount(money_amount);
    transaction.setType(type);

    transactions.push_back(transaction);

    save_transactions(transactions);
}


//Function to show the main menu of the program
void show_menu(std::vector<Transaction>& transactions){
    int choise = 0;
    while(true){
        std::cout << "\n=-_-=-_-=BANK TRANSACTION LIST=-_-=-_-=\n"<<"1. Create transaction\n"
        <<"2. Show transaction list\n"<<"3. Delete transation\n"<<"4. Change transaction\n"
        <<"5. Find transaction\n"<<"6. Show information\n"<<"7. Show only income\n"<<"8. Show only expenses\n"
        <<"9. Show transactions in diapazone\n"<<"10. Save and Quit\n"<<"=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=";
        std::cout << "\nPlease enter what you want to do: ";

        if(!(std::cin >> choise)){
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
            find_transactions(transactions);
        }
        else if(choise == 6){
            show_information(transactions);
        }
        else if(choise == 7){
            show_earning(transactions);
        }
        else if(choise == 8){
            show_spending(transactions);
        }
        else if(choise == 9){
            show_diapazone(transactions);
        }
        else if(choise == 10){
            save_transactions(transactions);
            exit(0);
        }
        else{
            std::cout << "\nIncorrect input\n\n";
        }
    }
}
//Functions to show the list of the existing transactions
void list_transactions(std::vector<Transaction>& transactions){
    Transaction transaction;
    int counter = 0;
    std::string spam;
    if(!(transactions.empty())){
        for(auto& block : transactions){
            ++counter;
            if(block.getType() == "spend"){
            std::cout << counter << ".|\t\t" << block.getChronoDate() << "|\t\t"<< block.getCategory()
            <<"|\t\t"<<color_text(to_upper(block.getType()), Color::Red)<<"|\t\t"<< block.getMoneyAmount() << "|\t\t" << block.getDescription() <<"|\n"; 
        }
        else{
            std::cout << counter << ".|\t\t" << block.getChronoDate() << "|\t\t"<< block.getCategory()
            <<"|\t\t"<<color_text(to_upper(block.getType()), Color::Green)<<"|\t\t"<< block.getMoneyAmount() << "|\t\t" << block.getDescription() <<"|\n"; 
        }
        }
    }
    else{
        std::cout << "There is nothing to list :( \n";
    }
    std::cout << "Please press any button ENTER to continue ";
    std::cin >> spam;
}

//Function to delete transaction
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
            transactions.erase(transactions.begin() + (choise - 1));
            save_transactions(transactions);
            succes = true;
        }
    }while(succes == false);
    }
}

//Function that allows change selected transaction
void change_transaction(std::vector<Transaction>& transactions){
    list_transactions(transactions);

    Transaction block;
    int choise = 0;
    bool succes = false;
    bool money_succes = false;
    bool date_succes = false;
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
        if(!(std::cin >> choise) || choise > transactions.size() || choise <= 0){
            std::cout << "Incorrect input";
            std::cin.clear();std::cin.ignore(10000, '\n');
            std::cout << "\nPlease enter which transaction you want to change: ";
        }

        else{

            std::cin.clear();std::cin.ignore(10000, '\n');
            //Cheking is date valid
            do{
                std::cout << "\nPlease enter new date of the transaction (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                if(isDateValid(date) == true){
                    date_succes = true;
                    }
                else{
                    std::cout << "Date input is incorrect";
                }
            }while(date_succes == false);

            //Checking is type valid
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
                    std::cin.clear(); std::cin.ignore(10000, '\n');                
                }
                else{
                    money_succes = true;
                }
            }while(money_succes == false);

            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::cout << "Please enter new description of the transaction: ";
            std::getline(std::cin, description);

            transactions[choise - 1].setDate(date);
            transactions[choise - 1].setCategory(category);
            transactions[choise - 1].setType(type);
            transactions[choise - 1].setMoneyAmount(money_amount);
            transactions[choise - 1].setDescription(description);
            succes = true;
            save_transactions(transactions);
        }

    }while(succes == false);
}
}

//Function to set selected text to upper register
std::string to_upper(std::string text){
    std::transform(text.begin(), text.end(), text.begin(),
        [](unsigned char c) {
            return std::toupper(c);
        });

    return text;
}

//Function that allows to find transaction by tags
void find_transactions(std::vector<Transaction>& transactions){
    std::string finding_word;
    std::string spam;

    if(transactions.empty()){
        std::cout << "There is nothing to find from :(\n";
    }
    else{
        std::cin.clear();std::cin.ignore(10000, '\n');
        std::cout << "Please enter which transactions you want to find: ";
        std::getline(std::cin, finding_word);
        finding_word = to_upper(finding_word);
        for (auto& block : transactions){
        if(to_upper(block.getDescription()).find(finding_word) != std::string::npos){
            if(block.getType() == "spend"){
                std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
                <<"|\t\t"<<color_text(to_upper(block.getType()), Color::Red)<<"|\t\t"<< block.getMoneyAmount() << "|\t\t" << block.getDescription() <<"|\n"; 
            }
            else{
                std::cout << block.getChronoDate() << "|\t"<< block.getCategory()
                <<"|\t\t"<<color_text(to_upper(block.getType()), Color::Green)<<"|\t\t"<< block.getMoneyAmount() << "|\t\t" << block.getDescription()<<"|\n"; 
            }
        }

        else if(to_upper(block.getStrDate()).find(finding_word) != std::string::npos){
            if(block.getType() == "spend"){
                std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
                <<"|\t"<<color_text(to_upper(block.getType()), Color::Red)<<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription()<<"|\n"; 
            }
            else{
                std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
                <<"|\t"<<color_text(to_upper(block.getType()), Color::Green)<<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription() <<"|\n"; 
            }
        }
        
        else if(to_upper(block.getCategory()).find(finding_word) != std::string::npos){
            if(block.getType() == "spend"){
                std::cout << block.getChronoDate() << "|\t"<< block.getCategory()
                <<"|\t"<<color_text(to_upper(block.getType()), Color::Red)<<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription() <<"|\n"; 
            }
            else{
                std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
                <<"|\t"<<color_text(to_upper(block.getType()), Color::Green)<<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription() <<"|\n"; 
            }
        }

    }
    }
    std::cout << "Press any button + ENTER to continue: ";
    std::cin >> spam;
}

//Function that shows only income transactions
void show_earning(std::vector<Transaction>& transactions){
    std::string spam;
    int counter = 0;
    if(transactions.empty()){
        std::cout << "There is no transactions to search from :(\n";
    }
    else{
    for(auto& block : transactions){
        if(block.getType() == "earn"){
            ++counter;
            std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
            <<"|\t"<<color_text(to_upper(block.getType()), Color::Green)<<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription() <<"|\n"; 
        }
    }
    if(counter == 0){
        std::cout << "There is no income transactions :(\n";
    }
    }
    std::cout << "Press any button ENTER to continue: ";
    std::cin >> spam;
    
}

//Function that show only expense transactions
void show_spending(std::vector<Transaction>& transactions){
    std::string spam;
    int counter = 0;

    if(transactions.empty()){
        std::cout << "There is no transactions to search from :(\n";
    }
    else{
    for(auto& block : transactions){
        if(block.getType() == "spend"){
            ++counter;
            std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
            <<"|\t\t"<<color_text(to_upper(block.getType()), Color::Red)<<"|\t\t"<< block.getMoneyAmount() << "|\t\t" << block.getDescription() <<"|\n"; 
        }
    }
    if(counter == 0){
        std::cout << "There is no expense transactions :(\n";
    }
    }
    std::cout << "Press any button ENTER to continue: ";
    std::cin >> spam;
}

/*

    Function that shows information about: current balance, amount of income/expense transactions
    biggest/lowest income/expense transaction

*/
void show_information(std::vector<Transaction>& transactions){
    std::string spam;

    if(transactions.empty()){
        std::cout << "Currently there is no information to report about :(\n";
    }

    else{
    double money_balance = 0;
    int earn_counter = 0;
    int spend_counter = 0;
    double biggest_amount_transaction;
    double lowest_amount_transaction;

    double biggest_income_transaction = transactions[0].getMoneyAmount();
    double lowest_income_transaction = transactions[0].getMoneyAmount();
    double currentTransaction = 0;
    int iterationCounter = 0;

    std::string balance;


    if(transactions.empty()){
        std::cout << "There is nothing to analyze from :(";
    }

    else{
    for(auto& block : transactions){
        currentTransaction = block.getMoneyAmount();

        if(block.getType() == "earn"){
            money_balance += currentTransaction;
            ++earn_counter;
            if(lowest_income_transaction >= block.getMoneyAmount()){
                lowest_income_transaction = block.getMoneyAmount();
            }
            else if(biggest_income_transaction <= block.getMoneyAmount()){
                biggest_income_transaction = block.getMoneyAmount();
            }
        }
        else{        
            currentTransaction *= -1;
            if(iterationCounter == 0){
                lowest_amount_transaction = currentTransaction;
                biggest_amount_transaction = currentTransaction;
                ++iterationCounter;
            }
            money_balance += currentTransaction;
            ++spend_counter;
            if(currentTransaction >= lowest_amount_transaction){
                lowest_amount_transaction = currentTransaction;
            }
            else if(currentTransaction < biggest_amount_transaction){
                biggest_amount_transaction = currentTransaction;
            }
        }

    }

    //Making stream output fixed to 2 digits after dot.
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2)<< money_balance;
    balance = stream.str();

    std::cout << "| Money balance of your transactions is: " << color_text(balance, Color::Yellow)<< " | amount of earns "
    << earn_counter << " | amount of expenses "<< spend_counter << "\n| biggest expense transaction is "
    << color_text(std::to_string(biggest_amount_transaction), Color::Red)<<" | lowest expense transaction is "<<color_text(std::to_string(lowest_amount_transaction), Color::Green)
    << "\n| biggest income amount is " << color_text(std::to_string(biggest_income_transaction), Color::Green)<< " | lowest income amount is " << color_text(std::to_string(lowest_income_transaction), Color::Yellow) << "\n";
}
    }
    std::cout << "\nPlease enter any button ENTER to continue: ";
    std::cin >> spam;
}

//Function that allows to show transactions in selected date diapazone
void show_diapazone(std::vector<Transaction>& transactions){
    std::string spam;
    if(transactions.empty() || transactions.size() == 1){
        std::cout << "There is not enough transactions to set any diapazone :(\n";
    }
    else{
    std::string date1;
    std::string date2;
    std::chrono::year_month_day date;
    std::chrono::year_month_day second_date;
    bool first_date_succes = false;
    bool second_date_succes = false;

    std::cin.clear();std::cin.ignore(10000, '\n');
    do{
    std::cout << "\nPlease enter from which date you want to see transactions: ";
    std::getline(std::cin, date1);
    if(isDateValid(date1)){
        date = date_unparse(date1);
        first_date_succes = true;
    }
    else{
        std::cout << "\nWrond input, input date in form YYYY-MM-DD";
    }
    }while(first_date_succes == false);

    do{
        std::cout << "\nPlease enter to which date you want to see transactions: ";
        std::getline(std::cin, date2);
        if(isDateValid(date2)){
            second_date = date_unparse(date2);
            second_date_succes = true;
        }
        else{
            std::cout << "\nWrong input, input date in form YYYY-MM-DD";
        }
    }while(second_date_succes == false);

    std::sort(transactions.begin(), transactions.end(),
    [](Transaction& a, Transaction& b) {
        return a.getStrDate() > b.getStrDate();
    }
    );

    for(auto& block : transactions){
        if(block.getChronoDate() > date && block.getChronoDate() < second_date){
            if(block.getType()== "spend"){
                std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
                <<"|\t" << color_text(to_upper(block.getType()), Color::Red) <<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription()<<"|\n\n"; 
            }
            else{
                std::cout << block.getChronoDate() << "|\t  "<< block.getCategory()
                <<"|\t"<<color_text(to_upper(block.getType()), Color::Green)<<"|\t"<< block.getMoneyAmount() << "|\t" << block.getDescription()<<"|\n\n"; 
            }
        }
    }
    }
    std::cout << "Please enter any button ENTER to continue: ";
    std::cin >> spam;
}

//Function that allows to color selected text
std::string color_text(std::string x, Color color){
    std::string text;
    if(color == Color::Red){
        text = "\033[31m"+x+"\033[0m";
        return text;
    }
    else if(color == Color::Green){
        text = "\033[32m"+x+"\033[0m";
        return text;
    }
    else if(color == Color::Yellow){
        text = "\033[33m"+x+"\033[0m";
        return text;
    }
    return text;
}
