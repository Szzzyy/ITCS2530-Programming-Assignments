#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

enum CardRarity {
    COMMON = 1,
    UNCOMMON,
    RARE,
};
const int maxprice = 100;

void displayBanner();
void setColor(int color);
void displayMenu();
std::string getStringInput(std::string prompt);
int getInt(std::string prompt);
double getDouble(std::string prompt);
double calculateTotalValue(int totalCards, double cardValue);
int calculateCardsPerYear(int totalCards, int years);
void Report(std::string tcg, std::string favoriteCard, int years, int totalCards, double cardValue, double totalValue, int cardsPerYear, std::string rarity); // adedc str rarity
std::string getrarity(); //@ added for enum
double cardavg(double price[], int& size, int maxsize);

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

    std::string rarity; //@
    double price[maxprice] = { 0.0 };
    double finalavg = 0.0;
    int actualsize = 0;

    displayBanner();

    // do while loop that keeps on repeating the program until the user stops typing y
    char repeat = 'y';
    do {

        displayMenu();

        std::cin >> menu;
        // while loop that keeps on going until user enters a number between 1-3
        while (menu < 1 || menu > 4) {
            std::cout << "Invalid. Enter 1, 2, 3, or 4: ";
            std::cin >> menu;
        }
        std::cin.ignore(1000, '\n');

        switch (menu) {

            case 1:
                tcg = getStringInput("What Trading Card Game do you collect? ");
                favoriteCard = getStringInput("What is your favorite card? ");
                years = getInt("How many years have you been collecting the TCG? ");
                totalCards = getInt("How many cards do you own? ");
                cardValue = getDouble("What is the average value of your cards? ");

                rarity = getrarity(); //@ call new rarity function

                totalValue = calculateTotalValue(totalCards, cardValue);
                cardsPerYear = calculateCardsPerYear(totalCards, years);

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
                std::cout << std::left << std::setw(28) << "Main Rarity Tier:" << rarity << "\n"; //@ added for rarity 
                std::cout << "--------------------------------------------\n";
                std::cout << std::left << std::setw(28) << "Years Collecting:"   << years      << " yrs\n";
                std::cout << std::left << std::setw(28) << "Total Cards:"        << totalCards << " cards\n";
                std::cout << std::fixed << std::setprecision(2);
                std::cout << std::left << std::setw(28) << "Avg Card Value:"     << "$" << cardValue  << "\n";
                std::cout << "--------------------------------------------\n";
                std::cout << std::left << std::setw(28) << "Total Value:"        << "$" << totalValue  << "\n";
                std::cout << std::left << std::setw(28) << "Cards Per Year:"     << cardsPerYear << " cards/yr\n";
                std::cout << "********************************************\n";

                Report(tcg, favoriteCard, years, totalCards, cardValue, totalValue, cardsPerYear, rarity);
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
                years = getInt("\nYears collecting? ");
                totalCards = getInt("Total cards? ");

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

            case 4:
                std::cout << "Card Price Average Tool\n";
                finalavg = cardavg(price, actualsize, maxprice);

                std::cout << "\n********************************************\n";
                std::cout << "              Calculated Results            \n";
                std::cout << "********************************************\n";
                std::cout << "Total Entries:" << actualsize << "\n";
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Calculated Average: $" << finalavg << "\n";
                std::cout << "\n********************************************\n";
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

void displayBanner() {
    setColor(5);
    std::cout << "********************************************\n";
    std::cout << "       Trading Card Collection Tracker      \n";
    std::cout << "********************************************\n\n";
}

// Changes the console text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void displayMenu() {
    setColor(5);
    std::cout << "1. Log My Collection\n";
    std::cout << "2. View Sample Report\n";
    std::cout << "3. Get Recommendation Based On Experience\n";
    std::cout << "4. Average Price Calculator\n";
    std::cout << "Enter choice: ";
}

std::string getStringInput(std::string prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

int getInt(std::string prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail() || value < 0) {
        std::cout << "Invalid input, using 0 as default\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        value = 0;
    }
    return value;
}

double getDouble(std::string prompt) {
    double value;
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail() || value < 0) {
        std::cout << "Invalid input, using 0 as default\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        value = 0;
    }
    return value;
}

double calculateTotalValue(int totalCards, double cardValue) {
    return totalCards * cardValue;
}

int calculateCardsPerYear(int totalCards, int years) {
    if (years > 0) {
        return totalCards / years;
    }
    return totalCards;
}

// Saves the collection report to a text file
void Report(std::string tcg, std::string favoriteCard, int years, int totalCards, double cardValue, double totalValue, int cardsPerYear, std::string rarity) {
    std::ofstream outFile("report.txt");
    outFile << "********************************************\n";
    outFile << "           Your Collection Report           \n";
    outFile << "********************************************\n";
    outFile << std::left << std::setw(28) << "TCG:"           << tcg          << "\n";
    outFile << std::left << std::setw(28) << "Favorite Card:" << favoriteCard << "\n";
    outFile << std::left << std::setw(28) << "Main Rarity Tier:" << rarity << "\n"; //@ also update this
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
std::string getrarity() {
    int rarechoice = 0;
    std::cout << "Average Rarity of colleciton: 1. Common, 2. Uncommon, 3. Rare\n";
    std::cin >> rarechoice;
    std::cin.ignore(); // Clear the newline character from the buffer

    CardRarity rarity = static_cast<CardRarity>(rarechoice);

    switch (rarity) {
        case COMMON:      return "Common";
        case UNCOMMON:    return "Uncommon";
        case RARE:        return "Rare"; 
        default:          return "unkown";
    }
}
double cardavg(double price[], int& size, int maxsize) {
   
    std::cout << "how many cards are we calculating? ";
    std::cin >> size;

    while (size <= 0 || size > maxsize) {
        std::cout << "invalid card amoun";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    for (int i = 0; i < size; i++) {
    std::cout << "Enter price for item #" << (i + 1) << " ";
    std::cin >> price[i];

    while (std::cin.fail() || price[i] < 0) {
        std::cout << "Invalid entrym enter positive dollar amount";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> price[i];
        }
    }
    std::cin.ignore(1000, '\n');

    double temptotal = 0.0;
    for (int j = 0; j < size; j++) {
        temptotal += price[j];
    }
    return temptotal / size;

}