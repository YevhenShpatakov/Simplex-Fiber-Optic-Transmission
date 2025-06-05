/*
Autor: Yevhen Shpatakov
Wersja kodu: 2.3.4
Data napisania: 28.01.2025
Jezyk: Arduino (C)
System operacyjny: Windows 11
Opis: Program odbiornika, ktory odbiera dane przeslane przez nadajnik i wyswietla je na ekranie LCD.
*/
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Inicjalizacja wyswietlacza LCD (adres I2C 0x27, 16 kolumn, 2 wiersze)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definiowanie pinow RX i TX dla SoftwareSerial
SoftwareSerial mySerial(0, 1); // RX (D0), TX (D1)

void setup() {
  Serial.begin(9600);         // Inicjalizacja komunikacji przez monitor szeregowy (baud rate: 9600)
  mySerial.begin(9600);       // Inicjalizacja SoftwareSerial z tym samym baud rate (9600)
  
  lcd.init();                 // Inicjalizacja wyswietlacza LCD
  lcd.backlight();            // Wlaczenie podswietlenia wyswietlacza
  lcd.clear();                // Wyczyszczenie ekranu LCD
  lcd.setCursor(0, 0);        // Ustawienie kursora na pierwszym wierszu
  lcd.print("Waiting for msg"); // Wyswietlenie poczatkowego komunikatu na LCD
  Serial.println("Waiting for output..."); // Wyswietlenie komunikatu w monitorze szeregowym
}

void loop() {
  // Sprawdzenie, czy dane sa dostepne w monitorze szeregowym
  if (Serial.available() > 0) {
    // Odczytywanie danych z monitora szeregowego do momentu napotkania znaku nowej linii ('\n')
    String data = Serial.readStringUntil('\n');
    String message = data.substring(0, data.length() - 1); // Usuniecie ewentualnego ostatniego znaku nowej linii
    
    lcd.clear();                 // Wyczyszczenie ekranu LCD
    lcd.setCursor(0, 0);         // Ustawienie kursora na pierwszym wierszu
    lcd.print("Message:");       // Wyswietlenie statycznej etykiety na LCD
    mySerial.println(message);   // Wyslanie wiadomosci przez SoftwareSerial
    Serial.println("Message received: " + message); // Wyswietlenie odebranej wiadomosci w monitorze szeregowym

    if (message.length() <= 16) {
      // Jesli wiadomosc miesci sie w 16 znakach, wyswietl ja bez przewijania w drugim wierszu
      lcd.setCursor(0, 1);
      lcd.print(message);
    } else {
      // Jesli wiadomosc jest dluzsza niz 16 znakow, przewin ja w drugim wierszu
      String displayMessage = message + " "; // Dodanie spacji dla plynnego przewijania
      for (int i = 0; i < displayMessage.length(); i++) {
        lcd.setCursor(0, 1); // Ustawienie kursora na drugim wierszu
        lcd.print(displayMessage.substring(i, i + 16)); // Wyswietlenie okna 16 znakow
        delay(263); // Dostosowanie predkosci przewijania
      }
      lcd.setCursor(0, 1);
      lcd.print(" "); // Wyczyszczenie drugiego wiersza po przewijaniu
    }
  }
}
