# HOSPITAL MANAGEMENT SYSTEM

## Introduction
This project would help to simplify the appointment process with doctors in the hospital, along with assistance in tracking data and transactions. The program provides user interfaces for patients, doctors and admin to book appointments and will provide diagnostics to patients, store their medical records and background history in safe locations, and generate bills and provide an account development feature.

The project consists of three key modules:
### Patient Module:
   * This module focuses on the account creation of the patient.
   * Stores the patient’s current information and also displays the patient’s background history.
   * Provides a virtual interaction with the doctor for diagnosis.
   * Provides the option to book an appointment with the doctor.
   * Allows access to medicines available at the Pharmacy.

### Doctor Module:
   * Displays the scheduled appointments for the doctor.
   * Provides a virtual interaction with the patient for diagnostic purposes.
   * Access to patient’s previous records.
  
### Admin Module:
   * Provides admin a username to access controls.
   * Allows admin to check records for both doctor and patient.
   * Allows admin to add, update or remove any doctor’s data.
   * Displays current Pharmacy Stock.
   * Allows admin to add, update or remove any medicine from the Pharmacy.
   * Allows admin to refill the entire Pharmacy Stock.
  
### Appointment Module:
   * Accessible to both patients and doctors personally.
   * Patients can check the availability of any specific doctor.
   * Patients can book appointments with the doctors of their choice.
   * Doctors can view their current schedule and are able to add, remove or update any slot.

### Medicine Module:
   * Stores data for all medicines through binary filing.
   * Displays data for all the medicines from the file.
   * Allows to search medicines in the Pharmacy.
  
### Pharmacy Module:
   * Displays a menu to:
        1. Select available medicines from the Pharmacy.
        2. Print receipt for the order placed.
        3. Replace the previous order with a new order.
   * Functions to calculate billing for the order placed.
   * Functions to print the receipt of the bill.

## Tools and Technologies used
Following are the tools used in the creation of our project:
* Language used: C++
* IDEs used: Dev C++, Visual Studio Code
*  Header files:
  - #include <iostream>
  - #include <fstream>
  - #include <cstdlib>
  - #include <time.h>
  - #include <iomanip>
  - #include <string.h>
  - #include <conio.h>
  - #include <windows.h>
  - #include <stdlib.h>
  - #include<sstream>
  - #include”Hospital.h”


## Class Diagram

![image](https://github.com/Hassanj34/Hospital-Management-System/assets/96651621/886272de-92b4-411a-9a15-662451d37109)

## Future Work
Despite the numerous amounts of bug fixes and code optimization that we did, we could’ve still improved the program further in various places. There are several other features that could’ve been implemented sue time and resource constraints it was difficult to add multiple features such as a proper machine learning system for patient diagnosis and lab reports.
