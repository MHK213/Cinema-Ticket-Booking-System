#pragma once

#include <iostream>
#include <string>

using namespace std;

class clsSeat
{
private:
    int _Row;
    int _Col;
    bool _IsReserved = false;
    string _ReservedBy;

public:
    clsSeat(int Row, int Col) {
        _Row = Row;
        _Col = Col;
    }

    string GetPosition() const { return "(" + to_string(_Row) + "-" + to_string(_Col) + ")"; }
    string GetReservedBy() const { return _ReservedBy; }
    int GetRow() const { return _Row; }
    int GetCol() const { return _Col; }

    bool IsReserved() const { return _IsReserved; }

    bool Reserve(string name) {
        if (!IsReserved()) {
            _IsReserved = true;
            _ReservedBy = name;
            return true;
        }
        return false;
    }

    bool Cancel() {
        if (IsReserved()) {
            _IsReserved = false;
            _ReservedBy = "";
            return true;
        }
        return false;
    }
};