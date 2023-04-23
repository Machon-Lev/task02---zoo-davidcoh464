#include "Location.h"

ostream& operator << (ostream& out, const Location& loc)
{
    out << "(" << loc.row << "," << loc.col << ")";
    return out;
}

void Location::operator+=(const Location& other)
{
    if (this->row + other.row >= ROWS)
        this->row = ROWS - 1;
    else if (this->row + other.row < 0)
        this->row = 0;
    else
        this->row += other.row;

    if (this->col + other.col >= COLUMNS)
        this->col = COLUMNS - 1;
    else if (this->col + other.col < 0)
        this->col = 0;
    else
        this->col += other.col;
}
