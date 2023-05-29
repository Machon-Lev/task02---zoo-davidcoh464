#pragma once
#include <cstdlib>
#include <iostream>
#include <time.h>

#define ROWS  20
#define COLUMNS  40

using std::ostream;

struct Location
{
    int row, col;
    Location();
    Location(int _row, int _col);
    friend ostream& operator << (ostream& out, const Location& c);
    friend bool operator==(const Location& lhs, const Location& rhs) { return lhs.row == rhs.row && lhs.col == rhs.col; }
    friend bool operator!=(const Location& lhs, const Location& rhs) { return !(lhs == rhs); }
    void operator+=(const Location& other);
};