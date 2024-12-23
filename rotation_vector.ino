#include <Adafruit_BNO08x.h> 
#include <Adafruit_Sensor.h> 
#include <Wire.h>

Adafruit_BNO08x bno08x; // 객체 선언
sh2_SensorValue_t sensorValue;

void setup(void) {
  Wire.setSDA(17);
  Wire.setSCL(16);
  Wire.begin();
  while (!Serial) delay(10);     

  Serial.begin(115200);
  Serial.println("Adafruit BNO08x test!");

  // Try to initialize!
  if (!bno08x.begin_I2C(BNO08x_I2CADDR_DEFAULT, &Wire)) {
    Serial.println("Failed to find BNO08x chip");
    Serial.println(bno08x.begin_I2C(BNO08x_I2CADDR_DEFAULT, &Wire)); 
    while (1) { delay(10); }
  }
  Serial.println("BNO08x Found!");

  for (int n = 0; n < bno08x.prodIds.numEntries; n++) {
    Serial.print("Part ");
    Serial.print(bno08x.prodIds.entry[n].swPartNumber);
    Serial.print(": Version :");
    Serial.print(bno08x.prodIds.entry[n].swVersionMajor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionMinor);
    Serial.print(".");
    Serial.print(bno08x.prodIds.entry[n].swVersionPatch);
    Serial.print(" Build ");
    Serial.println(bno08x.prodIds.entry[n].swBuildNumber);
  }

  setReports();

  Serial.println("Reading events");
  delay(100);
}

// Here is where you define the sensor outputs you want to receive
void setReports(void) {
  Serial.println("Setting desired reports");
  if (! bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
    Serial.println("Could not enable game vector");
  }
}

void loop() {
  delay(10);
  if (bno08x.wasReset()) {
    Serial.print("sensor was reset ");
    setReports();
  }
  
  if (! bno08x.getSensorEvent(&sensorValue)) {
    return;
  }
  
  switch (sensorValue.sensorId) {
    
    case SH2_GAME_ROTATION_VECTOR:
      Serial.print("Game Rotation Vector - r: ");
      Serial.print(sensorValue.un.gameRotationVector.real);
      Serial.print(" i: ");
      Serial.print(sensorValue.un.gameRotationVector.i);
      Serial.print(" j: ");
      Serial.print(sensorValue.un.gameRotationVector.j);
      Serial.print(" k: ");
      Serial.println(sensorValue.un.gameRotationVector.k);
      break;
  }
}