#pragma once

#include <iostream>
#include <vector>
#include "clsSeat.h"
#include "clsBooking.h"

using namespace std;

class clsCinemaHall
{
private:
	int _Rows;
	int _Cols;

	vector <vector <clsSeat>> _Seats;
	vector <clsBooking> _Bookings;

public:
	clsCinemaHall(int Rows, int Cols) {
		_Rows = Rows;
		_Cols = Cols;

		_Seats.resize(_Rows);

		for (int r = 0; r < _Rows; r++) {
			_Seats[r].resize(_Cols);

			for (int c = 0; c < _Cols; c++) {
				_Seats[r][c] = clsSeat(r, c);
			}
		}
	}

	void ShowSeats() {
		for (int R = 0; R < _Rows; R++) {
			for (int C = 0; C < _Cols; C++) {
				clsSeat& Seat = _Seats[R][C];

				if (Seat.IsReserved()) cout << "[X] ";
				else cout << "[O] ";
			}
			cout << endl;
		}
	}

	bool ReserveSeat(int Row, int Col, string name) {
		if (Row < 0 || Row >= _Rows || Col < 0 || Col >= _Cols) {
			cout << "\nInvalid seat position!";
			return false;
		}

		clsSeat& Seat = _Seats[Row][Col];

		if (!Seat.Reserve(name)) {
			cout << "\nSeat already reserved!";
			return false;
		}

		cout << "\nSeat reserved Successfully!";
		return true;
	}

	bool CancelSeat(int Row, int Col) {
		if (Row < 0 || Row >= _Rows || Col < 0 || Col >= _Cols) {
			cout << "\nInvalid seat position!";
			return false;
		}

		clsSeat& Seat = _Seats[Row][Col];

		if (!Seat.Cancel()) {
			cout << "\nSeat Not reserved!";
			return false;
		}

		cout << "\nSeat Cancelled Successfully!";
		return true;
	}
};