# Cinema Hall Booking System (C++)

A console-based application built using **C++** and **Data Structures** concepts to simulate a cinema seat reservation system.

---

## Overview

This project allows users to:

* View available and reserved seats
* Reserve a seat
* Cancel a reservation
* Track bookings with timestamps
* Display all bookings

The system demonstrates the use of:

* Object-Oriented Programming (OOP)
* Data Structures (`vector`, `2D vector`)
* Encapsulation and class design
* Basic system design principles

---

## Project Structure

```
Project/
│
├── main.cpp
├── clsCinemaHall.h
├── clsSeat.h
├── clsBooking.h
├── clsDate.h
```

---

## Classes Design

###  `clsSeat`

Represents a single seat in the cinema.

**Attributes:**

* Row, Column
* IsReserved (Reservation status)
* Reserved by (client name)

**Functions:**

* `Reserve(name)`
* `Cancel()`
* `IsReserved()`
* `GetPosition()`
* `Properties()`

---

### `clsBooking`

Represents a reservation record.

**Attributes:**

* Booking ID (auto-increment)
* Client Name
* Seat Position
* Booking Time

**Functions:**

* `GetClientName()`
* `GetSeatPosition()`
* `GetBookingTime()`
* `Print()`

---

### `clsCinemaHall`

Core system managing seats and bookings.

**Attributes:**

* 2D vector of seats
* Vector of bookings
* Rows, Columns

**Functions:**

* `ShowSeats()`
* `ReserveSeat(row, col, name)`
* `CancelSeat(row, col)`
* `PrintAllBookings()`
* `GetAvailableSeats()`
* `GetReservedSeats()`

---

## Features

### Seat Visualization

```
[O] [X] [O] [O]
[X] [O] [O] [X]
```

* `[O]` → Available
* `[X]` → Reserved

---

### Reserve Seat

```cpp
hall.ReserveSeat(0, 1, "Ali");
```

---

### Cancel Reservation

```cpp
hall.CancelSeat(0, 1);
```

---

### Display Bookings

```
---Bookings---

ID            : 1
Client Name   : Ali
Seat Position : 01
Booking Time  : 2026-04-27
```

---

---

## Example Flow

```
Reserve → Create Booking → Store in Vector
Cancel  → Remove Booking → Update Seat
```

---

## Author
Madi Abdelheq

---

## Notes

This project is Developed as part of **Data Structures Level 1 Project**

---
