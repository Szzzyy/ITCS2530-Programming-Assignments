#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
//week 8
enum CardRarity {
    COMMON = 1,
    UNCOMMON,
    RARE,
};
const int maxprice = 100;
const int Max_collections = 5; 

struct CardCollection {
    std::string tcg;
    std::string favoriteCard;
    int    years = 0;
    int    totalCards = 0;
    double cardValue = 0;
    double totalValue = 0;
    int    cardsPerYear = 0;
    std::string rarity; 

};

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void displayBanner() {
    setColor(5);
    std::cout << "********************************************\n";
    std::cout << "       Trading Card Collection Tracker      \n";
    std::cout << "********************************************\n\n";
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

std::string getStringInput(std::string prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
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
class CardTracker {
private:
    CardCollection myCollections[Max_collections];
    int currentcollectioncount;
    double price[maxprice];
    int actualsize;

    void printcollectionsum(const CardCollection& collection) const{
        std::cout << "\n********************************************\n";
        std::cout << "           Your Collection Report           \n";
        std::cout << "********************************************\n";
        std::cout << std::left << std::setw(28) << "TCG:" << collection.tcg << "\n";
        std::cout << std::left << std::setw(28) << "Favorite Card:" << collection.favoriteCard << "\n";
        std::cout << std::left << std::setw(28) << "Main Rarity Tier:" << collection.rarity << "\n";
        std::cout << "--------------------------------------------\n";
        std::cout << std::left << std::setw(28) << "Years Collecting:" << collection.years << " yrs\n";
        std::cout << std::left << std::setw(28) << "Total Cards:" << collection.totalCards << " cards\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left << std::setw(28) << "Avg Card Value:" << "$" << collection.cardValue << "\n";
        std::cout << "--------------------------------------------\n";
        std::cout << std::left << std::setw(28) << "Total Value:" << "$" << collection.totalValue << "\n";
        std::cout << std::left << std::setw(28) << "Cards Per Year:" << collection.cardsPerYear << " cards/yr\n";
        std::cout << "********************************************\n";
    }

    void savecollectionsum(const CardCollection& collection) const{
        std::ofstream outFile("report.txt");
        outFile << "********************************************\n";
        outFile << "           Your Collection Report           \n";
        outFile << "********************************************\n";
        outFile << std::left << std::setw(28) << "TCG:" << collection.tcg << "\n";
        outFile << std::left << std::setw(28) << "Favorite Card:" << collection.favoriteCard << "\n";
        outFile << std::left << std::setw(28) << "Main Rarity Tier:" << collection.rarity << "\n";
        outFile << "--------------------------------------------\n";
        outFile << std::left << std::setw(28) << "Years Collecting:" << collection.years << " yrs\n";
        outFile << std::left << std::setw(28) << "Total Cards:" << collection.totalCards << " cards\n";
        outFile << std::fixed << std::setprecision(2);
        outFile << std::left << std::setw(28) << "Avg Card Value:" << "$" << collection.cardValue << "\n";
        outFile << "--------------------------------------------\n";
        outFile << std::left << std::setw(28) << "Total Value:" << "$" << collection.totalValue << "\n";
        outFile << std::left << std::setw(28) << "Cards Per Year:" << collection.cardsPerYear << " cards/yr\n";
        outFile << "********************************************\n";
        outFile.close();
    }

    double calculateAveragePrice() {
        std::cout << "how many cards are we calculating? ";
        std::cin >> actualsize;

        while (actualsize <= 0 || actualsize > maxprice) {
            std::cout << "invalid card amount. Enter 1 to " << maxprice << ": ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cin >> actualsize;
        }

        for (int i = 0; i < actualsize; i++) {
            std::cout << "Enter price for item #" << (i + 1) << " ";
            std::cin >> price[i];

            while (std::cin.fail() || price[i] < 0) {
                std::cout << "Invalid entry. Enter positive dollar amount: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin >> price[i];
            }

        }
        std::cin.ignore(1000, '\n');

        double temptotal = 0.0;
        for (int j = 0; j < actualsize; j++) {
            temptotal += price[j];
        }
        return temptotal / actualsize;
    }

public:
    CardTracker() {
        currentcollectioncount = 0;
        actualsize = 0;
        for (int i = 0; i < maxprice; i++) {
            price[i] = 0.0;
        }
    }

    void addCollection() {
        if (currentcollectioncount < Max_collections) {
            std::cout << "\n--- Logging Collection #" << (currentcollectioncount + 1) << "---\n";

            CardCollection& current = myCollections[currentcollectioncount];

            current.tcg = getStringInput("What Trading Card Game do you collect? ");
            current.favoriteCard = getStringInput("What is your favorite card? ");
            current.years = getInt("How many years have you been collecting the TCG? ");
            current.totalCards = getInt("How many cards do you own? ");
            current.cardValue = getDouble("What is the average value of your cards? ");
            current.rarity = getrarity();

            current.totalValue = current.totalCards * current.cardValue;
            if (current.years > 0) {
                current.cardsPerYear = current.totalCards / current.years;
            }
            else {
                current.cardsPerYear = current.totalCards;
            }

            if (current.totalCards >= 500 && current.totalValue >= 1000) {
                std::cout << "\nHuge collection with high value.\n";
            }
            else if (current.totalCards <= 500 && current.totalValue >= 1000) {
                std::cout << "\nQuality over quantity!\n";
            }
            else {
                std::cout << "\nWe all start somewhere.\n";
            }

            printcollectionsum(current);
            savecollectionsum(current);
            currentcollectioncount++;
        }
        else {
            std::cout << "\nError, all slots filled!\n";
        }
    }


    void displaycollection()const {
        if (currentcollectioncount == 0) {
            std::cout << "\nNo collection yet\n";
            return;
        }

        double sumvalue = 0;
        int sumcards = 0;


        std::cout << "\n********************************************\n";
        std::cout << "         Total Collection Report           \n";
        std::cout << "********************************************\n";

        for (int i = 0; i < currentcollectioncount; i++) {
            std::cout << "- " << myCollections[i].tcg << " (" << myCollections[i].totalCards << " cards valued at : $" << myCollections[i].totalValue << ")\n";
            sumvalue += myCollections[i].totalValue;
            sumcards += myCollections[i].totalCards;
        }

        std::cout << "\n********************************************\n";
        std::cout << "Grand total of Cards: " << sumcards << "\n";
        std::cout << "Grand Worth: $" << sumvalue << "\n";

        std::cout << "\n********************************************\n";
        std::cout << "         Collector Recommendation           \n";
        std::cout << "********************************************\n";

        if (sumcards >= 400) {
            std::cout << "High level collector- Start vending at card shows\n";
        }
        else if (sumcards >= 200) {
            std::cout << "Medium Level collector- Start focusing on cards you like instead of value\n";
        }
        else {
            std::cout << "Low level collector- pick out a TCG and start collecting\n";
        }
        std::cout << "********************************************\n";

    }
    void runAverageCalculator() {
        std::cout << "Card Price Average Tool\n";
        double finalavg = calculateAveragePrice();

        std::cout << "\n********************************************\n";
        std::cout << "              Calculated Results            \n";
        std::cout << "********************************************\n";
        std::cout << "Total Entries:" << actualsize << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Calculated Average: $" << finalavg << "\n";
        std::cout << "\n********************************************\n";

    }
    void showMenu() const {
        setColor(5);
        std::cout << "1. Log My Collection\n";
        std::cout << "2. View Sample Report\n";
        std::cout << "3. View Collections and Recommendations\n";
        std::cout << "4. Average Price Calculator\n";
        std::cout << "Enter choice: ";
    }
};

int main() {

    CardTracker tracker;

    int    menu = 0;
    displayBanner();

    char repeat = 'y';
    do {

        tracker.showMenu();

        std::cin >> menu;
        // while loop that keeps on going until user enters a number between 1-3
        while (menu < 1 || menu > 4) {
            std::cout << "Invalid. Enter 1, 2, 3, or 4: ";
            std::cin >> menu;
        }
        std::cin.ignore(1000, '\n');

        switch (menu) {

        case 1:
            tracker.addCollection();
            break;

        case 2:
            std::cout << "\n********************************************\n";
            std::cout << "                Sample Report                \n";
            std::cout << "********************************************\n";
            std::cout << std::left << std::setw(28) << "TCG:" << "Magic The Gathering\n";
            std::cout << std::left << std::setw(28) << "Favorite Card:" << "Akroma's Will\n";
            std::cout << "--------------------------------------------\n";
            std::cout << std::left << std::setw(28) << "Years Collecting:" << "10 yrs\n";
            std::cout << std::left << std::setw(28) << "Total Cards:" << "450 cards\n";
            std::cout << std::fixed << std::setprecision(2);
            std::cout << std::left << std::setw(28) << "Avg Card Value:" << "$" << 3.50 << "\n";
            std::cout << "--------------------------------------------\n";
            std::cout << std::left << std::setw(28) << "Total Value:" << "$" << 1575.00 << "\n";
            std::cout << std::left << std::setw(28) << "Cards Per Year:" << "64 cards/yr\n";
            std::cout << "********************************************\n";
            break;

        case 3:
            tracker.displaycollection();
            break;

        case 4:
            tracker.runAverageCalculator();
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
