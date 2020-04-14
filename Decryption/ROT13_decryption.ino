#include <Wire.h>

char temp;
void setup() {
  Serial.begin(9600);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
  temp = Wire.read();                  // read one character from the I2C
}

void loop() {
  if (temp) {
    Serial.print(rot13(char(temp)));
  }
}

char rot13(char c)
{
  if (c >= 'a' && c <= 'm') {          // if between a and m -> data + 13 ; small letter
    return c += 13;
  } else if (c >= 'n' && c <= 'z') {   // if between n and z -> data - 13 ; small letter
    return c -= 13;
  } else if (c >= 'A' && c <= 'M') {   // if between a and m -> data + 13 ; capital letter
    return c += 13;
  } else if (c >= 'N' && c <= 'Z') {   // if between n and z -> data - 13 ; capital letter
    return c -= 13;
  }

  return c;                            // return the decrypted data
}
