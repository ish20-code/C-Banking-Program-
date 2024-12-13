#include <iostream>
#include <string>

double afterdeposit(double startingbalance, double deposit);
double afterwithdrawal(double startingbalance, double withdraw);

int main() {
    std::string fullname;
    char symbol;
    double deposit = 0;
    double withdraw = 0;
    double startingbalance;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullname);
    std::cout << "You have entered " << fullname << "'s bank account\n";

    std::cout << "Current Balance: ";
    std::cin >> startingbalance;

    do {
        std::cout << "What transaction do you want to perform ( + is deposit, - is withdraw, X to exit): ";
        std::cin >> symbol;

        if (symbol == '+') {
            std::cout << "How much do you want to deposit: ";
            std::cin >> deposit;
            startingbalance = afterdeposit(startingbalance, deposit);
            std::cout << "This is your balance after that transaction: " << startingbalance << '\n';
        } 
        else if (symbol == '-') {
            std::cout << "How much do you want to withdraw: ";
            std::cin >> withdraw;
            startingbalance = afterwithdrawal(startingbalance, withdraw);

            if (startingbalance < 0) {
                std::cout << "Insufficient funds! Transaction canceled.\n";
                startingbalance += withdraw; // Roll back the withdrawal
            } else {
                std::cout << "This is your balance after that transaction: " << startingbalance << '\n';
            }
        } 
        else if (symbol == 'X') {
            std::cout << "Thank you for using our system!\n";
            break;
        } 
        else {
            std::cout << "Enter a valid operator\n";
        }
    } while (true);

    return 0;
}

double afterdeposit(double startingbalance, double deposit) {
    return startingbalance + deposit;
}

double afterwithdrawal(double startingbalance, double withdraw) {
    return startingbalance - withdraw;
}
