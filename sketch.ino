/* -----------------------------------------------------------------------------
 * Example .ino file for arduino, compiled with CmdMessenger.h and
 * CmdMessenger.cpp in the sketch directory. 
 *----------------------------------------------------------------------------*/

#include "CmdMessenger.h"

/* Define available CmdMessenger commands */
enum {
    on,
    off,
    reply,
    error,
};

/* Initialize CmdMessenger -- this should match PyCmdMessenger instance */
const int BAUD_RATE = 9600;
CmdMessenger c = CmdMessenger(Serial,',',';','/');

/* Create callback functions to deal with incoming messages */

/* callback */
void do_on(void){
    digitalWrite(LED_BUILTIN, HIGH);
    c.sendCmd(reply,"LED ON");
}
void do_off(void){
    digitalWrite(LED_BUILTIN, LOW);
    c.sendCmd(reply,"LED OFF");
}

/* callback */
void on_unknown_command(void){
    c.sendCmd(error,"Command without callback.");
}

/* Attach callbacks for CmdMessenger commands */
void attach_callbacks(void) { 
    c.attach(on,do_on);
    c.attach(off,do_off);
    c.attach(on_unknown_command);
}

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(LED_BUILTIN, OUTPUT);
    attach_callbacks();    
}

void loop() {
    c.feedinSerialData();
}
