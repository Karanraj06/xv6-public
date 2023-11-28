#include "types.h"

#define INPUT_BUF 128
#define MAX_HISTORY 16
#define UP_ARROW 226
#define DOWN_ARROW 227

int history(char *buffer, int historyId);

// Empty the input buffer
void empty_input_buf();

// Show the given buffer on the console
void show_buf_on_console(char * given_buf, uint length);

// Saves the current command to history
void save_to_history();

// Clear the console i.e., remove the last command from it
void clear_console(void);

// Saves the given buffer to input buffer
void save_buf_to_input_buf(char * given_buf, uint length);