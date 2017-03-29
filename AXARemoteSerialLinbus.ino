/**
 * Serial commands:
 * OPEN
 * CLOSE
 * STOP
 * STATUS
 * DEVICE
 * VERSION
 * 
 * LINbus configuration:
 * 19200bps 8N2
 */

void setup() {
  // First serial port is used for control menu
  Serial.begin(9600);
  Serial.println("Window controller");
  Serial.println("1: Open");
  Serial.println("2: Close");
  Serial.println("3: Stop");
  Serial.println("4: Version");
  Serial.println("5: Status");
  Serial.println("6: Device");
  Serial.println();

  // Second serial port is used for link to motor
  Serial1.begin(19200, SERIAL_8N2);

  delay(500);                        // waits for 500mseconds
}

void loop() {

  if(Serial.available() > 0)
  {
    byte command = Serial.read();
    
    //Serial.print("I received: ");
    //Serial.println(command, DEC);
    if(command == '1')
    {
      Serial.println("Opening");
      Serial1.println("OPEN");
    }

    if(command == '2')
    {
      Serial.println("Closing");
      Serial1.println("CLOSE");
    }

    if(command == '3')
    {
      Serial.println("Stopping");
      Serial1.println("STOP");
    }
    if(command == '4')
    {
      Serial.println("Version");
      Serial1.println("VERSION");
    }
    if(command == '5')
    {
      Serial.println("Status");
      Serial1.println("STATUS");
    }
    if(command == '6')
    {
      Serial.println("Device");
      Serial1.println("DEVICE");
    }
  }

  if(Serial1.available() > 0)
  {
     Serial.write(Serial1.read());
  }

  /*
  // if closed we will open the window completely.
  if (WindowStatus == WindowStatusClosed)
  {
    OpenWindowCmd();
    do
    {
      delay(500);                      // waits for half a second
    } while (GetWindowStatusCmd() != WindowStatusOpen);
    digitalWrite(ledPin, HIGH);
    WindowStatus = WindowStatusOpen;
    delay(45000);                     // waits for 45 seconds to open completely !.
    // waiting XX seconds means you open the window partly, for example: 25 seconds is about 50% !.
    // exit if we completely opened the window.
  }
  */
  //delay(200);                        // waits for 1 second
}
