#include <iostream>
#include "clsBooking.h"
#include "clsCinemaHall.h"

using namespace std;

int clsBooking::NextID = 0;

int main()
{
    clsCinemaHall hall(3, 4);

    hall.ShowSeats();

    cout << endl;

    hall.ReserveSeat(0, 1, "Ali");
    hall.ReserveSeat(1, 2, "Sara");

    hall.PrintAllBookings();

    hall.CancelSeat(0, 1);

    hall.ShowSeats();

    return 0;
}