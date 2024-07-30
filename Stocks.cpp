#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Structure to represent a Stock
struct Stock {
    std::string name;
    double price;
    int quantity;
};

// Function to display the available stocks
void displayStocks(const std::vector<Stock>& stocks) {
    std::cout << std::setw(10) << "Stock" << std::setw(10) << "Price" << std::setw(10) << "Quantity" << std::endl;
    for (const auto& stock : stocks) {
        std::cout << std::setw(10) << stock.name << std::setw(10) << stock.price << std::setw(10) << stock.quantity << std::endl;
    }
}

// Function to buy stocks
void buyStock(std::vector<Stock>& stocks, const std::string& stockName, int quantity) {
    for (auto& stock : stocks) {
        if (stock.name == stockName) {
            if (stock.quantity >= quantity) {
                stock.quantity -= quantity;
                std::cout << "Bought " << quantity << " of " << stockName << std::endl;
            } else {
                std::cout << "Not enough stock available." << std::endl;
            }
            return;
        }
    }
    std::cout << "Stock not found." << std::endl;
}

// Function to sell stocks
void sellStock(std::vector<Stock>& stocks, const std::string& stockName, int quantity) {
    for (auto& stock : stocks) {
        if (stock.name == stockName) {
            stock.quantity += quantity;
            std::cout << "Sold " << quantity << " of " << stockName << std::endl;
            return;
        }
    }
    std::cout << "Stock not found." << std::endl;
}

int main() {
    std::vector<Stock> stocks = {
        {"AAPL", 150.00, 100},
        {"GOOGL", 2800.00, 50},
        {"AMZN", 3400.00, 30},
        {"MSFT", 290.00, 200}
    };
    
    int choice;
    std::string stockName;
    int quantity;

    do {
        std::cout << "1. Display Stocks\n2. Buy Stock\n3. Sell Stock\n4. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayStocks(stocks);
                break;
            case 2:
                std::cout << "Enter stock name to buy: ";
                std::cin >> stockName;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                buyStock(stocks, stockName, quantity);
                break;
            case 3:
                std::cout << "Enter stock name to sell: ";
                std::cin >> stockName;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                sellStock(stocks, stockName, quantity);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 4);

    return 0;
}
