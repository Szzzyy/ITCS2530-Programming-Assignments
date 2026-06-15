#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main() {

    // Variables
    std::string tcg;
    std::string favoriteCard;
    //Just like an earlier comment, i added 0's to all the numbered variables due to diffuculties with calculations
    int    years      = 0;
    int    totalCards = 0;
    double cardValue  = 0;
    double totalValue = 0;
    int    cardsPerYear = 0;
    int    menu = 0;

    // banner for the beginning of the code to introduce the user to
    std::cout << "********************************************\n";
    std::cout << "       Trading Card Collection Tracker      \n";
    std::cout << "********************************************\n\n";

    // do while loop that keeps on repeating the program until the user stops typing y
    char repeat = 'y';
    do {

        //Menu for the selections
        std::cout << "1. Log My Collection\n";
        std::cout << "2. View Sample Report\n";
        std::cout << "3. Get Recommendation Based On Experience\n";
        std::cout << "Enter choice: ";

        std::cin >> menu;
        // while loop that keeps on going until user enters a number between 1-3
        while (menu < 1 || menu > 3) {
            std::cout << "Invalid. Enter 1, 2, or 3: ";
            std::cin >> menu;
        }
        std::cin.ignore(1000, '\n');

        switch (menu) {

            case 1:
                std::cout << "What Trading Card Game do you collect? ";
                std::getline(std::cin, tcg);

                std::cout << "What is your favorite card? ";
                std::getline(std::cin, favoriteCard);

                std::cout << "How many years have you been collecting the TCG? ";
                std::cin >> years;
                if (std::cin.fail() || years < 0) {
                    std::cout << "Invalid input, putting 0 years as default\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    years = 0;
                }

                std::cout << "How many cards do you own? ";
                std::cin >> totalCards;
                if (std::cin.fail() || totalCards < 0) {
                    std::cout << "Invalid input, putting 0 cards as default.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    totalCards = 0;
                }

                std::cout << "What is the average value of your cards? ";
                std::cin >> cardValue;
                if (std::cin.fail() || cardValue < 0) {
                    std::cout << "Invalid input, putting average card value to 0\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    cardValue = 0;
                }

                totalValue   = totalCards * cardValue;
                cardsPerYear = (years > 0) ? totalCards / years : totalCards;

                // if/else block giving comments on the value of the user's collection
                if (totalCards >= 500 && totalValue >= 1000) {
                    std::cout << "\nHuge collection with high value.\n";
                } else if (totalCards <= 500 && totalValue >= 1000) {
                    std::cout << "\nQaulity over qauntity\n";
                } else {
                    std::cout << "\nWe all start somewhere.\n";
                }

                // if/else block giving statements regarding the collection
                if (years >= 5 && totalCards >= 300) {
                    std::cout << "Long term collector\n";
                } else if (years < 5 && totalCards >= 300) {
                    std::cout << "Fast collector\n";
                } else {
                    std::cout << "Slow but steady\n";
                }

                // for loop, adding a divider between the respones and the report
                for (int i = 0; i < 44; i++) {
                    std::cout << "=";
                }
                std::cout << "\n";

                std::cout << "\n********************************************\n";
                std::cout << "           Your Collection Report           \n";
                std::cout << "********************************************\n";
                std::cout << std::left << std::setw(28) << "TCG:"            << tcg          << "\n";
                std::cout << std::left << std::setw(28) << "Favorite Card:"  << favoriteCard << "\n";
                std::cout << "--------------------------------------------\n";
                std::cout << std::left << std::setw(28) << "Years Collecting:"   << years      << " yrs\n";
                std::cout << std::left << std::setw(28) << "Total Cards:"        << totalCards << " cards\n";
                std::cout << std::fixed << std::setprecision(2);
                std::cout << std::left << std::setw(28) << "Avg Card Value:"     << "$" << cardValue  << "\n";
                std::cout << "--------------------------------------------\n";
                std::cout << std::left << std::setw(28) << "Total Value:"        << "$" << totalValue  << "\n";
                std::cout << std::left << std::setw(28) << "Cards Per Year:"     << cardsPerYear << " cards/yr\n";
                std::cout << "********************************************\n";

                {
                    std::ofstream outFile("report.txt");
                    outFile << "********************************************\n";
                    outFile << "           Your Collection Report           \n";
                    outFile << "********************************************\n";
                    outFile << std::left << std::setw(28) << "TCG:"           << tcg          << "\n";
                    outFile << std::left << std::setw(28) << "Favorite Card:" << favoriteCard << "\n";
                    outFile << "--------------------------------------------\n";
                    outFile << std::left << std::setw(28) << "Years Collecting:"  << years      << " yrs\n";
                    outFile << std::left << std::setw(28) << "Total Cards:"       << totalCards << " cards\n";
                    outFile << std::fixed << std::setprecision(2);
                    outFile << std::left << std::setw(28) << "Avg Card Value:"    << "$" << cardValue << "\n";
                    outFile << "--------------------------------------------\n";
                    outFile << std::left << std::setw(28) << "Total Value:"       << "$" << totalValue << "\n";
                    outFile << std::left << std::setw(28) << "Cards Per Year:"    << cardsPerYear << " cards/yr\n";
                    outFile << "********************************************\n";
                    outFile.close();
                }
                std::cout << "Report saved to report.txt\n";
                break;

            case 2:
                std::cout << "\n********************************************\n";
                std::cout << "           Your Collection Report           \n";
                std::cout << "********************************************\n";
                std::cout << std::left << std::setw(28) << "TCG:"           << "Magic The Gathering\n";
                std::cout << std::left << std::setw(28) << "Favorite Card:" << "Akroma's Will\n";
                std::cout << "--------------------------------------------\n";
                std::cout << std::left << std::setw(28) << "Years Collecting:" << "10 yrs\n";
                std::cout << std::left << std::setw(28) << "Total Cards:"      << "450 cards\n";
                std::cout << std::fixed << std::setprecision(2);
                std::cout << std::left << std::setw(28) << "Avg Card Value:"   << "$" << 3.50 << "\n";
                std::cout << "--------------------------------------------\n";
                std::cout << std::left << std::setw(28) << "Total Value:"      << "$" << 1575.00 << "\n";
                std::cout << std::left << std::setw(28) << "Cards Per Year:"   << "64 cards/yr\n";
                std::cout << "********************************************\n";
                break;

            case 3:
                std::cout << "\nYears collecting? ";
                std::cin >> years;
                if (std::cin.fail() || years < 0) { years = 0; }

                std::cout << "Total cards? ";
                std::cin >> totalCards;
                if (std::cin.fail() || totalCards < 0) { totalCards = 0; }

                std::cout << "\n********************************************\n";
                std::cout << "         Collector Recommendation           \n";
                std::cout << "********************************************\n";

                if (years >= 5 && totalCards >= 300) {
                    std::cout << "High level collector- Start vending at card shows\n";
                } else if (years >= 2 && totalCards >= 50) {
                    std::cout << "Medium Level collector- Start focusing on cards you like instead of value\n";
                } else {
                    std::cout << "Low level collector- pick out a TCG and start collecting\n";
                }

                std::cout << "********************************************\n";
                break;

            default:
                std::cout << "\nRun again and enter 1 2 3\n";
                break;
        }

    
        std::cout << "\nWould you like to use the tracker again? (y/n): ";
        std::cin >> repeat;
        std::cin.ignore(1000, '\n');

    } while (repeat == 'y');

    std::cout << "\nThanks for using the Trading Card Tracker!\n";

    return 0;
}