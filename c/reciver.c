/*
Autor: Yevhen Shpatakov
Wersja kodu: 2.3.4
Data napisania: 28.01.2025
Jezyk: Arduino (C)
System operacyjny: Windows 11
Opis: Program nadajnika, ktory odbiera dane z monitora szeregowego i wysyla je przez SoftwareSerial.
*/
#include <SoftwareSerial.h>

// Definiowanie pinow RX i TX dla SoftwareSerial
SoftwareSerial mySerial(0, 1); // RX (D0), TX (D1)

void setup() {
  Serial.begin(9600); // Inicjalizacja komunikacji przez monitor szeregowy (predkosc 9600 bodow)
  mySerial.begin(9600); // Inicjalizacja SoftwareSerial z predkoscia 9600 bodow
  Serial.println("Waiting for input..."); // Wyswietlanie komunikatu w monitorze szeregowym
}

void loop() {
  // Sprawdzanie, czy dane sa dostepne w monitorze szeregowym
  if (Serial.available() > 0) {
    // Odczytanie wiadomosci z monitora szeregowego do momentu napotkania znaku nowej linii ('\n')
    String message = Serial.readStringUntil('\n');
    
    // Wyswietlenie odczytanej wiadomosci w monitorze szeregowym
    Serial.println(message);
  }
}
