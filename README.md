# Portfolio & P&L Engine

My second C++ project, built as part of my journey towards learning C++ for quantitative finance and trading systems.

The goal of this project was to understand how a portfolio manages positions, processes buy and sell trades, and calculates profit and loss.

## What I've built

- Process BUY and SELL trades.
- Manage positions for different symbols using `std::map`.
- Calculate average entry price when buying more of an existing position.
- Calculate realised P&L when selling.
- Calculate unrealised P&L using market prices.
- Calculate market value for individual positions and the overall portfolio.
- Validate trades and reject invalid transactions.
- Validate market prices before calculating portfolio metrics.
- Generate a portfolio report showing positions, market value and P&L.
- Build the project using CMake.

## Tech Stack

- C++17
- STL (`std::map`, `std::vector`, `std::string`)
- Object-oriented programming
- CMake

## Project Structure

```text
portfolio-pnl-engine/
├── CMakeLists.txt
├── include/
├── src/
├── tests/
└── README.md
```

## How to Build and Run

Make sure you have a C++ compiler and CMake installed.

```bash
cmake -S . -B build
cmake --build build
./build/portfolio_pnl_engine
```

## Example

The demo processes trades for AAPL and MSFT, including multiple buys and sells.

After processing the trades, the expected results are:

| Metric | Value |
|---|---:|
| Total realised P&L | 150.00 |
| Total unrealised P&L | 3500.00 |
| Total market value | 15000.00 |

The calculations use average-cost accounting and market prices supplied to the application. Transaction fees and slippage are not included.

## Things I learned

- Working with classes, structs and header files across multiple source files.
- Using `std::map` to manage positions by symbol.
- Updating average entry prices when processing additional buys.
- Calculating realised and unrealised P&L.
- Handling invalid trades without changing portfolio state.
- Validating market prices before calculating valuations.
- Setting up a multi-file C++ project with CMake.

---

This is a learning project, and I'll keep adding features as I progress with C++ and quantitative development.
