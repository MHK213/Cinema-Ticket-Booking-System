#pragma once

#include <iostream>
#include <vector>
#include "clsSeat.h"
#include "clsBooking.h"
#include <iomanip>

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

		cout << "\n\n\t\t\t        ---All Seats---\n\n";

		int consoleWidth = 80;
		int seatWidth = 4; 
		int lineWidth = _Cols * seatWidth;
		int padding = (consoleWidth - lineWidth) / 2;

		for (int R = 0; R < _Rows; R++) {

			cout << setw(padding) << ""; 

			for (int C = 0; C < _Cols; C++) {

				clsSeat& seat = _Seats[R][C];

				if (seat.IsReserved())
					cout << "[X] ";
				else
					cout << "[O] ";
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
			cout << "\nSeat with position [" << Row << "][" << Col << "] already reserved!";
			return false;
		}

		cout << "\nSeat with position [" << Row << "][" << Col << "] reserved Successfully!\n";

		clsBooking booking(name, Seat.GetPosition());

		_Bookings.push_back(booking);

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

		string position = Seat.GetPosition();

		for (auto it = _Bookings.begin(); it != _Bookings.end(); ++it) {
			if (it->GetSeatPosition() == position) {
				_Bookings.erase(it);
				break;
			}
		}

		return true;
	}

	int GetAvailableSeats() {

		int count = 0;

		for (int r = 0; r < _Rows; r++) {
			for (int c = 0; c < _Cols; c++) {

				if (!_Seats[r][c].IsReserved())
					count++;
			}
		}

		return count;
	}

	int GetReservedSeats() {

		int count = 0;

		for (int r = 0; r < _Rows; r++) {
			for (int c = 0; c < _Cols; c++) {

				if (_Seats[r][c].IsReserved())
					count++;
			}
		}

		return count;
	}

	void PrintAllBookings() {

		if (_Bookings.empty()) {
			cout << "\n\n\t\t\t          ---Bookings---";
			cout << "\n\t\t\tNo bookings available.\n";
			return;
		}

		cout << "\n\n\t\t\t          ---Bookings---";

		for (clsBooking& B : _Bookings) {
			B.Print();
		}
	}
};