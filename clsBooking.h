#pragma once

#include <iostream>
#include <string>
#include "clsSeat.h"

using namespace std;

class clsBooking
{
private:
    int _ID;
    string _ClientName;
    string _SeatPosition;
    string _BookingTime;

public:
    static int NextID;

    clsBooking(string ClientName, string SeatPosition, string BookingTime) {
        _ID = ++NextID;
        _ClientName = ClientName;
        _SeatPosition = SeatPosition;
        _BookingTime = BookingTime;
    }

    string GetClientName() const { return _ClientName; }
    string GetSeatPosition() const { return _SeatPosition; }
    string GetBookingTime() const { return _BookingTime; }

    void Print() {
        cout << "\n\t\t\t ________________________________\n";
        cout << "\n\t\t\t\tBooking Info";
        cout << "\n\t\t\t ________________________________\n";
        cout << "\n\t\t\t   ID            : " << _ID;
        cout << "\n\t\t\t   Client Name   : " << _ClientName;
        cout << "\n\t\t\t   Seat Position : " << _SeatPosition;
        cout << "\n\t\t\t   Booking Time  : " << _BookingTime;
        cout << "\n\t\t\t ________________________________\n\n";
    }
};