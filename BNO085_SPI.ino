#include <Adafruit_BNO08x.h>
#include <Adafruit_Sensor.h>
#include <SPI.h>

// SPI 핀 설정
#define CS_PIN 10
#define SCK_PIN 13
#define MOSI_PIN 11
#define MISO_PIN 12

Adafruit_BNO08x bno08x; // 객체 선언
sh2_SensorValue_t sensorValue;

void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10); // 시리얼 통신이 준비될 때까지 대기

  Serial.println("Adafruit BNO08x SPI test!");

  // SPI 설정
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);  // Chip select 초기화 (비활성화)

  // SPI로 BNO08x 초기화
  if (!bno08x.begin_SPI(CS_PIN, &SPI)) {
    Serial.println("Failed to find BNO08x chip!");
    while (1) { delay(10); }
  }
  Serial.println("BNO08x Found!");

  // 센서 정보 출력
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

// 센서 출력 설정
void setReports(void) {
  Serial.println("Setting desired reports");
  if (!bno08x.enableReport(SH2_GAME_ROTATION_VECTOR)) {
    Serial.println("Could not enable game vector");
  }
}

void loop() {
  delay(10);
  if (bno08x.wasReset()) {
    Serial.print("sensor was reset ");
    setReports();
  }

  if (!bno08x.getSensorEvent(&sensorValue)) {
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