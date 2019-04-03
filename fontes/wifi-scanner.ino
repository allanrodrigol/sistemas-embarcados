#include <ESP8266WiFi.h>

#define WIFI_P_DISABLE 0
#define WIFI_P_ENABLE  1

unsigned int channel = 1;

int nothing_new = 0;

void setup() {
  Serial.begin(9600);
  
  wifi_set_opmode(STATION_MODE);           
  wifi_set_channel(channel);
  
  wifi_promiscuous_enable(WIFI_P_DISABLE);
  wifi_set_promiscuous_rx_cb(wifi_promiscuous_cb);   
  wifi_promiscuous_enable(WIFI_P_ENABLE);
}

void loop() {
  channel = 1;
  wifi_set_channel(channel);
  
  while (true) {
    channel++;
      
    if (channel == 15)
      break;             
    
    wifi_set_channel(channel);
    
    delay(1000);  
  }
}

void wifi_promiscuous_cb(uint8_t *buf, uint16_t len) {
  //Verifica tipo do pacote recebido
  if((buf[12] == 0x88) || (buf[12] == 0x40) || (buf[12] == 0x94) || (buf[12] == 0xa4) || (buf[12] == 0xb4) || (buf[12] == 0x08)) {
    Serial.printf("Channel: %i ID: %02x ",channel, buf[12]);
    
    //Exibe MAC address
    Serial.printf("MAC: ");
    
    for(int i = 0;i < 5;i++) {
      Serial.printf("%02x:", buf[22 + i]);
    }
    
    Serial.printf("%02x ", buf[22 + 5]);
    //
    
    //Força do sinal
    Serial.printf("SIGNAL: ");
    Serial.printf("%i\n", int8_t(buf[0]));
  }
}
