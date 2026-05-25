#include <iostream>
#include <string>

int main() {

    //defining the variables to use in ending output

    std::string tcgName;
    std::string favoriteCard;
    int yearsCollecting;

    //using getline to take the string of the respone in case its longer then one word
    std::cout << "What Trading Card Game do you collect? ";
    std::getline(std::cin, tcgName);

    std::cout << "What is your favorite card from that Trading Card Game? ";
    std::getline(std::cin, favoriteCard);

    std::cout << "How many years have you been collecting this Trading Card Game? ";
    std::cin >> yearsCollecting;


    //Take all the input values to create the short paragraph

    std::cout << "\nYou have been collecting " << tcgName << " for " << yearsCollecting << " years with " << favoriteCard << " being your favorite card after all that time!";

    return 0;
}