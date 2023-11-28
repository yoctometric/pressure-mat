/*
Header file responsible for 'communicating with the mat' i.e. controlling the shift
registers and ADC's to read the mat in partial or in full
*/

#ifndef MATTERFACE
#define MATTERAFCE

#include <stdint.h>
#include <stdlib.h>

#include "pico/stdlib.h"

#include "adc.h"


#define ROW_WIDTH       28
#define COL_HEIGHT      56
#define MAT_SIZE        1568

#define SH_CLK_PIN      19
#define SH_CLR_PIN      18
#define SH_SERIN_PIN    17
#define SH_SEROUT_PIN   16

#define SHREG_GPIO_SLEEP_US     1000    // sleep time in us between shreg gpio actions   
#define ADC_READ_SLEEP_US       1000    // sleep time in us between adc reads 

/*
Sets up the gpio pins sued for communicating with the shift registers
*/
void initialize_shreg_pins();

/*
Writes inval to the shift registers, and then clocks 
the shift registers so that they shift their values by 1
*/
void shift_shreg(int inval);

/*
Resets the shift registers so that they are all outputting 0
*/
void clear_shreg();

/*
Sets up the interrupts for EOC pins
*/
void initialize_EOC_interrupts();

/*
reads the entire mat and writes it to the char array 'mat'
'mat' should be of length MAT_SIZE
*/
void read_mat(uint8_t *mat, struct adc_inst *adc1, struct adc_inst *adc2);

/*
for debugging purposes: prints the mat in a human readable format
*/
void prettyprint_mat(uint8_t *mat);

#endif