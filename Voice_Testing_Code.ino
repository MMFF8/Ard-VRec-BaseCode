int Int = 11;
int S1 = 2;
int S2 = 3;
int S3 = 4;
byte com = 0;
int CG = 1;

void setup()
{
Serial.begin(9600);
pinMode(Int, OUTPUT); // lights up when command from group 1 is recognized
pinMode(S1, OUTPUT); // lights up when subgroup x command 1 is recognized
pinMode(S2, OUTPUT); // lights up when subgroup x command 2 is recognized
pinMode(S3, OUTPUT); // lights up when subgroup x command 3 is recognized

delay(2000);

Serial.write(0xAA); // wait for input
Serial.write(0x37); // enter compact mode

delay(1000);

Serial.write(0xAA); // wait for input
Serial.write(0x21); // import group 1
Serial.println();
Serial.write(0x11); // //REMOVE LATERERERERERERRERER <------------------------------
Serial.println(" = Voice 1");
Serial.write(0x12); // //REMOVE LATERERERERERERRERER <------------------------------
Serial.println(" = Voice 2");
Serial.write(0x13); // //REMOVE LATERERERERERERRERER <------------------------------
Serial.println(" = Voice 3");
}

void loop()
{
while(Serial.available())
  {
  com = Serial.read();
  switch(com)
    {
      case 0x11: // current group: command 1
        if (CG == 1) // if current group is 1 (initializer group)
          {
            digitalWrite(Int, HIGH); // turn on the Int LED
            Serial.println("Switched to SG1"); //REMOVE LATERERERERERERRERER <------------------------------
            Serial.write(0x22); // switch voice checks to group 2
            CG = 2; // switch actions to group 2 (command subgroup for initializer 1)
          }
        else
          {
          if (CG == 2) // if current group is 2 (command subgroup for initializer 1)
            {
              digitalWrite(S1, HIGH); // turn on the S1 LED
              delay(100);
              digitalWrite(Int, LOW); // turn off the Int LED
              delay(1000);
              digitalWrite(S1, LOW); // turn off the S1 LED
              Serial.println("SG1 Command 1; switched to G1"); //REMOVE LATERERERERERERRERER <------------------------------
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          if (CG == 3) // if current group is 3 (command subgroup for initializer 2)
            {
              digitalWrite(Int, LOW); // turn off the Int LED
              Serial.println("SG2 Command 1; switched to G1"); //REMOVE LATERERERERERERRERER <------------------------------
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          if (CG == 4) // if current group is 4 (command subgroup for initializer 3)
            {
              digitalWrite(Int, LOW); // turn off the Int LED
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          }
      break;
//-----------------------------------------------
      case 0x12:
        if (CG == 1) // if current group is 1 (initializer group)
          {
            digitalWrite(Int, HIGH); // turn on the Int LED
            Serial.println("Switched to SG2"); //REMOVE LATERERERERERERRERER <------------------------------
            Serial.write(0x23); // switch voice checks to group 3
            CG = 3; // switch actions to group 3 (command subgroup for initializer 2)
          }
        else
          {
          if (CG == 2) // if current group is 2 (command subgroup for initializer 1)
            {
              digitalWrite(S2, HIGH); // turn on the S2 LED
              delay(100);
              digitalWrite(Int, LOW); // turn off the Int LED
              delay(1000);
              digitalWrite(S2, LOW); // turn off the S1 LED
              Serial.println("SG1 Command 2; switched to G1"); //REMOVE LATERERERERERERRERER <------------------------------
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          if (CG == 3) // if current group is 3 (command subgroup for initializer 2)
            {
              digitalWrite(Int, LOW); // turn off the Int LED
              Serial.println("SG2 Command 2; switched to G1"); //REMOVE LATERERERERERERRERER <------------------------------
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          if (CG == 4) // if current group is 4 (command subgroup for initializer 3)
            {
              digitalWrite(Int, LOW); // turn off the Int LED
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          }
      break;
//-----------------------------------------------
      case 0x13:
        if (CG == 1) // if current group is 1 (initializer group)
          {
            digitalWrite(Int, HIGH); // turn on the Int LED
            Serial.write(0x24); // switch voice checks to group 4
            CG = 4; // switch actions to group 4 (command subgroup for initializer 4)
          }
        else
          {
          if (CG == 2) // if current group is 2 (command subgroup for initializer 1)
            {
              digitalWrite(S3, HIGH); // turn on the S3 LED
              delay(100);
              digitalWrite(Int, LOW); // turn off the Int LED
              delay(1000);
              digitalWrite(S3, LOW); // turn off the S3 LED
              Serial.println("SG1 Command 3; switched to G1"); //REMOVE LATERERERERERERRERER <------------------------------
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          if (CG == 3) // if current group is 3 (command subgroup for initializer 2)
            {
              digitalWrite(Int, LOW); // turn off the Int LED
              Serial.println("SG2 Command 3; switched to G1"); //REMOVE LATERERERERERERRERER <------------------------------
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          if (CG == 4) // if current group is 4 (command subgroup for initializer 3)
            {
              digitalWrite(Int, LOW); // turn off the Int LED
              Serial.write(0x21); // switch voice checks to group 1
              CG = 1; // switch back to initializer group
            }
          }
      break;
//-----------------------------------------------      
      case 0x14:

      break;
//-----------------------------------------------      
      case 0x15:

      break;
//-----------------------------------------------
    }
  }
}

