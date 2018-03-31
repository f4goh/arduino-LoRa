/*
  LoRa register dump

  This examples shows how to inspect and output the LoRa radio's
  registers on the Serial interface
*/


#define RADIO_RESET_PORT        PC_0
#define RADIO_MOSI_PORT         PA_7
#define RADIO_MISO_PORT         PA_6
#define RADIO_SCLK_PORT         PB_3
#define RADIO_NSS_PORT          PA_15
#define RADIO_DIO_0_PORT        PB_4
#define RADIO_DIO_1_PORT        PB_1
#define RADIO_DIO_2_PORT        PB_0
#define RADIO_DIO_3_PORT        PC_13
#define RADIO_DIO_4_PORT        PA_5
#define RADIO_DIO_5_PORT        PA_4

#include <SPI.h>              // include libraries
#include <LoRa.h>


void setup() {
  Serial.begin(9600);               // initialize serial
  while (!Serial);

  Serial.println("LoRa Dump Registers");

  // override the default CS, reset, and IRQ pins (optional)
  // LoRa.setPins(7, 6, 1); // set CS, reset, IRQ pin

  SPI.setMISO(RADIO_MISO_PORT);
  SPI.setMOSI(RADIO_MOSI_PORT);
  SPI.setSCLK(RADIO_SCLK_PORT);
  SPI.setSSEL(RADIO_NSS_PORT);
  LoRa.setPins(RADIO_NSS_PORT, RADIO_RESET_PORT, RADIO_DIO_0_PORT);


  if (!LoRa.begin(915E6)) {         // initialize ratio at 915 MHz
    Serial.println("LoRa init failed. Check your connections.");
    while (true);                   // if failed, do nothing
  }

  LoRa.dumpRegisters(Serial);
}


void loop() {
}

