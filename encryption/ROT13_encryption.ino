#include <Wire.h>

int temp ;
void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  if (Serial.available())              // if any data is avalible
  {
    temp = char(Serial.read());        //  read the data and store it in temp1
    Serial.print(rot13(temp));
    Wire.beginTransmission(9);
    Wire.write(temp);
    Wire.endTransmission();            // print the data
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

  return c;                            // return the encrypted data
}
