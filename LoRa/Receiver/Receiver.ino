#include <SPI.h>
#include <LoRa.h>

// 핀 설정
#define CS_PIN 10      // LoRa 모듈의 NSS 핀
#define RESET_PIN 9    // LoRa 모듈의 RESET 핀
#define DIO0_PIN 2     // LoRa 모듈의 DIO0 핀

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  while (!Serial);

  Serial.println("LoRa 수신기 초기화 시작");

  // LoRa 모듈 핀 설정
  LoRa.setPins(CS_PIN, RESET_PIN, DIO0_PIN);

  // LoRa 초기화 (920.9 MHz)
  if (!LoRa.begin(9209E5)) {
    Serial.println("LoRa 초기화 실패!");
    while (1);
  }

  Serial.println("LoRa 수신기 초기화 완료!");
}

void loop() {
  // 수신 확인
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("수신된 메시지: ");

    // 수신된 데이터 읽기
    while (LoRa.available()) {
      String received = LoRa.readString();
      Serial.print(received);
    }

    Serial.println();
  }
}
