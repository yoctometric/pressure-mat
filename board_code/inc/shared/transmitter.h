/*
Header file responsible for communicating via the USB 1.1 serial connection to the connected computer
*/

#ifndef TRANSMITTER_HEADER
#define TRANSMITTER_HEADER

#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"


#define START_READING_COMMAND   "start_reading"
#define GET_CAL_VALS_COMMAND    "get_cal_vals"
#define PRINT_INFO_COMMAND      "print_info"

#define START_READING_COMMAND_ID    1
#define GET_CAL_VALS_COMMAND_ID     2
#define PRINT_INFO_COMMAND_ID       3

/*
Function which takes a string that has passed over serial and decides what to do based on its content
*/
int parse_input(char *string);

/*
Function responsible for initializing the transmitter
*/
void initialize_transmitter();

/*
Function which transmits a short verification string that the GUI can use to make sure mat readings are in sync
*/
void transmit_verification();

/*
Function which transmits one row of the mat (28, 8-bit values) over serial USB to the connected computer
*/
void transmit_row(uint8_t *row);

/*
Function which transmits the full mat (1568, 8-bit values) over serial USB to the connected computer
*/
void transmit_mat(uint8_t *mat);

#endif