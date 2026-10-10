#ifndef TRADE_H
#define TRADE_H

#include <string>
struct Trade{
    std::string symbol;
    long quantity;
    double price;
    std::string side;

};

#endif