
cmake_minimum_required(VERSION 3.16)

project(PortfolioPnLEngine
    VERSION 1.0
    DESCRIPTION "C++ Portfolio Management and P&L Engine"
    LANGUAGES CXX
)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build the application
add_executable(portfolio_pnl_engine
    src/main.cpp
    src/position.cpp
    src/portfolio.cpp
)

# Find project header files
target_include_directories(portfolio_pnl_engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Enable useful compiler warnings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(portfolio_pnl_engine
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()
