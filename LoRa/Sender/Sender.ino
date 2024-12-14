#include <SPI.h>
#include <LoRa.h>

// 핀 설정
#define CS_PIN 10      // LoRa 모듈의 NSS 핀
#define RESET_PIN 9    // LoRa 모듈의 RESET 핀
#define DIO0_PIN 2     // LoRa 모듈의 DIO0 핀

void setup() {
  Serial.begin(115200); // 시리얼 통신 초기화
  while (!Serial);

  Serial.println("LoRa 송신기 초기화 시작");

  // LoRa 모듈 핀 설정
  LoRa.setPins(CS_PIN, RESET_PIN, DIO0_PIN);

  // LoRa 초기화 (920.9 MHz)
  if (!LoRa.begin(920900000)) {
    Serial.println("LoRa 초기화 실패!");
    while (1);
  }

  Serial.println("LoRa 송신기 초기화 완료!");
}

void loop() {
  Serial.println("메시지 전송 중...");

  // 메시지 보내기
  LoRa.beginPacket();
  LoRa.print("Hello, Receiver!");
  LoRa.endPacket();

  Serial.println("메시지 전송 완료!");
  delay(2000); // 2초 대기
}
