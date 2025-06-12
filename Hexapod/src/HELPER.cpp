#include <Arduino.h>

void PRINT_ESP_INFO() {
  Serial.println("== ESP32 Info ==");
  Serial.println();

  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());

  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());

  Serial.print("CPU Frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");

  Serial.print("Flash Chip Size: ");
  Serial.print(ESP.getFlashChipSize() / (1024 * 1024));
  Serial.println(" MB");

  Serial.print("Flash Frequency: ");
  Serial.print(ESP.getFlashChipSpeed() / 1000000);
  Serial.println(" MHz");

  Serial.print("Heap Size: ");
  Serial.println(ESP.getHeapSize());

  Serial.print("Free Heap: ");
  Serial.println(ESP.getFreeHeap());

  Serial.print("PSRAM Size: ");
  Serial.println(ESP.getPsramSize());

  Serial.print("Sketch Size: ");
  Serial.println(ESP.getSketchSize());

  Serial.print("Free Sketch Space: ");
  Serial.println(ESP.getFreeSketchSpace());

  Serial.print("Chip ID (MAC): ");
  Serial.println(ESP.getEfuseMac(), HEX);

  Serial.println();
}