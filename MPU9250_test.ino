#include <Wire.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  mpu.beginAccel();
  mpu.beginGyro();
  mpu.beginMag();

  Serial.println("MPU9250 초기화 완료");
}

void loop() {
  mpu.accelUpdate();
  mpu.gyroUpdate();
  mpu.magUpdate();

  Serial.print("가속도 X: "); Serial.print(mpu.accelX(), 2); Serial.print(" m/s^2\t");
  Serial.print("Y: "); Serial.print(mpu.accelY(), 2); Serial.print(" m/s^2\t");
  Serial.print("Z: "); Serial.print(mpu.accelZ(), 2); Serial.println(" m/s^2");

  Serial.print("자이로 X: "); Serial.print(mpu.gyroX(), 2); Serial.print(" rad/s\t");
  Serial.print("Y: "); Serial.print(mpu.gyroY(), 2); Serial.print(" rad/s\t");
  Serial.print("Z: "); Serial.print(mpu.gyroZ(), 2); Serial.println(" rad/s");

  Serial.print("지자기 X: "); Serial.print(mpu.magX(), 2); Serial.print(" uT\t");
  Serial.print("Y: "); Serial.print(mpu.magY(), 2); Serial.print(" uT\t");
  Serial.print("Z: "); Serial.print(mpu.magZ(), 2); Serial.println(" uT");

  Serial.println();
  
  delay(1000); // 데이터 갱신 속도 조절
}
