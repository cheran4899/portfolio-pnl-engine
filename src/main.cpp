
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>

#include "trade.h"
#include "portfolio.h"

void print_section(const std::string& title)
{
    std::cout << "\n"
              << std::string(65, '=') << '\n'
              << title << '\n'
              << std::string(65, '=') << '\n';
}

int main()
{
    std::cout << std::fixed << std::setprecision(2);

    // 1. Initialise the portfolio
    Portfolio portfolio("Quant Portfolio");

    std::cout << "Portfolio & P&L Engine\n";
    std::cout << "C++ Portfolio Accounting Demo\n";

    // 2. Define and process trades
    print_section("1. TRADE PROCESSING");

    const std::vector<Trade> trades = {
        {"AAPL", 100, 100.00, "BUY"},
        {"AAPL", 50, 110.00, "BUY"},
        {"MSFT", 200, 50.00, "BUY"},
        {"AAPL", 80, 120.00, "SELL"},
        {"MSFT", 50, 45.00, "SELL"},
        {"MSFT", 100, 40.00, "BUY"},
        {"AAPL", 70, 90.00, "SELL"}
    };

    for (const auto& trade : trades)
    {
        const bool success = portfolio.process_trade(trade);

        std::cout << trade.side << ' '
                  << trade.quantity << ' '
                  << trade.symbol << " @ "
                  << trade.price << " : "
                  << (success ? "ACCEPTED" : "REJECTED")
                  << '\n';
    }

    // 3. Demonstrate invalid trade handling
    print_section("2. TRADE VALIDATION");

    const std::vector<Trade> invalid_trades = {
        {"MSFT", 300, 60.00, "SELL"}, // Oversell
        {"GOOGL", 10, 150.00, "SELL"}, // No existing position
        {"TSLA", 10, 200.00, "HOLD"},  // Invalid side
        {"TSLA", 0, 200.00, "BUY"},    // Invalid quantity
        {"TSLA", 10, -200.00, "BUY"}   // Invalid price
    };

    for (const auto& trade : invalid_trades)
    {
        const bool success = portfolio.process_trade(trade);

        std::cout << trade.side << ' '
                  << trade.quantity << ' '
                  << trade.symbol << " : "
                  << (success ? "ACCEPTED" : "REJECTED")
                  << '\n';
    }

    // 4. Display individual positions
    print_section("3. POSITION SUMMARY");
    portfolio.show_all_positions();

    // 5. Supply market prices
    print_section("4. MARKET VALUATION");

    const std::map<std::string, double> market_prices = {
        {"AAPL", 95.00},
        {"MSFT", 60.00}
    };

    // 6. Display consolidated report
    portfolio.show_portfolio_report(market_prices);

    // 7. Display portfolio-level metrics
    print_section("5. PORTFOLIO METRICS");

    std::cout << "Total realised P&L: "
              << portfolio.get_total_realised_pnl()
              << '\n';

    try
    {
        std::cout << "Total unrealised P&L: "
                  << portfolio.get_total_unrealised_pnl(market_prices)
                  << '\n';

        std::cout << "Total market value: "
                  << portfolio.get_total_market_value(market_prices)
                  << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Valuation error: "
                  << e.what() << '\n';
    }

    // 8. Demonstrate missing market-price handling
    print_section("6. MISSING MARKET PRICE TEST");

    const std::map<std::string, double> incomplete_prices = {
        {"AAPL", 95.00}
    };

    try
    {
        const double pnl =
            portfolio.get_total_unrealised_pnl(incomplete_prices);

        std::cout << "Unrealised P&L: " << pnl << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected validation failure: "
                  << e.what() << '\n';
    }

    // 9. Demonstrate invalid market-price handling
    print_section("7. INVALID MARKET PRICE TEST");

    const std::map<std::string, double> invalid_prices = {
        {"AAPL", 95.00},
        {"MSFT", -10.00}
    };

    try
    {
        const double market_value =
            portfolio.get_total_market_value(invalid_prices);

        std::cout << "Total market value: "
                  << market_value << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << "Expected validation failure: "
                  << e.what() << '\n';
    }

    print_section("DEMO COMPLETED");

    return 0;
}
