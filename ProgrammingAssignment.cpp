#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main() {

    std::string tcg;
    std::string favoriteCard;
    int years;
    int totalCards;
// added new variables for the total value of the collection and average card per year
    double cardvalue = 0; // added an = 0 to the end because i was running into trouble with the final outputs. Setting it to zero fixed problem 
    double totalvalue = totalCards * cardvalue;
    int cardsPerYear = (years > 0) ? totalCards / years : totalCards;

    // banner for the beginning of the code to introduce the user to
    std::cout << "********************************************\n";
    std::cout << "       Trading Card Collection Tracker      \n";
    std::cout << "********************************************\n\n";

    std::cout << "What Trading Card Game do you collect? ";
    std::getline(std::cin, tcg);

    std::cout << "What is your favorite card? ";
    std::getline(std::cin, favoriteCard);
//the if statement here and throughout the code allows if the user puts a number below 0 to have a default number for the variable and gives back a statement saying so
    std::cout << "How many years have you been collecting the TCG? ";
    std::cin >> years;
    if (std::cin.fail() || years < 0) {
        std::cout << "Invalid input, putting 0 years as default.\n";
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
    std::cin >> cardvalue;
    if (std::cin.fail() || cardvalue < 0) {
        std::cout << "Invalid input, putting average card value to 0.\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        cardvalue = 0;
    }
// this outputs all the information the code earlier was gathering
    std::string line   = "--------------------------------------------\n";
    std::string border = "********************************************\n";
    std::string header = "        Your Collection Report              \n";

    std::cout << "\n" << border;
    std::cout << header;
    std::cout << border;
    std::cout << std::left << std::setw(28) << "TCG:"                     << tcg              << "\n";
    std::cout << std::left << std::setw(28) << "Favorite Card:"           << favoriteCard     << "\n";
    std::cout << line;
    std::cout << std::left << std::setw(28) << "Years Collecting:"        << years  << " yrs\n";
    std::cout << std::left << std::setw(28) << "Total Cards Owned:"       << totalCards       << " cards\n";
    std::cout << std::left << std::setw(28) << "Avg Card Value:"          << "$" << cardvalue<< "\n";
    std::cout << line;
    std::cout << std::left << std::setw(28) << "Total Collection Value:"<< "$" << totalvalue << "\n";
    std::cout << std::left << std::setw(28) << "Avg Cards Per Year:"    << cardsPerYear     << " cards/yr\n";
    std::cout << border;
    std::cout << "Report saved to report.txt\n";
// this is the same as the earlier block, execept its creating a report.txt file with the information on it
    std::ofstream outFile("report.txt");
    outFile << border;
    outFile << header;
    outFile << border;
    outFile << std::left << std::setw(28) << "TCG:"                   << tcg              << "\n";
    outFile << std::left << std::setw(28) << "Favorite Card:"         << favoriteCard     << "\n";
    outFile << line;
    outFile << std::left << std::setw(28) << "Years Collecting:"      << years  << " years\n";
    outFile << std::left << std::setw(28) << "Total Cards Owned:"     << totalCards       << " cards\n";
    outFile << std::left << std::setw(28) << "Avg Card Value:"        << "$" <<cardvalue<< "\n";
    outFile << line;
    outFile << std::left << std::setw(28) << "Total Collection Value:"<< "$" << totalvalue << "\n";
    outFile << std::left << std::setw(28) << "Avg Cards Per Year:"    << cardsPerYear     << " cards/yr\n";
    outFile << border;
    outFile.close();

    return 0;
}