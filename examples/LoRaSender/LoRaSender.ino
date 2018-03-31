#include <SPI.h>
#include <LoRa.h>

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


int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  SPI.setMISO(RADIO_MISO_PORT);
  SPI.setMOSI(RADIO_MOSI_PORT);
  SPI.setSCLK(RADIO_SCLK_PORT);
  SPI.setSSEL(RADIO_NSS_PORT);
  LoRa.setPins(RADIO_NSS_PORT, RADIO_RESET_PORT, RADIO_DIO_0_PORT);
  

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello----------------------------------------------------------------------------------------------");
  LoRa.print("hello----------------------------------------------------------------------------------------------");
  LoRa.print("hello----------------------------------------------------------------------------------------------");
  LoRa.print("hello----------------------------------------------------------------------------------------------");
  LoRa.print("hello----------------------------------------------------------------------------------------------");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(5000);
}
