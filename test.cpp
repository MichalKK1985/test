// Prosty przykład symulacji grawitacji na ESP32

float velocity = 0.0;  // Prędkość początkowa
float position = 0.0;  // Pozycja początkowa
float gravity = 9.8;   // Przyspieszenie ziemskie w m/s^2
float timeStep = 0.1;  // Czas kroku (symulacja co 100ms)

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Obliczanie przyspieszenia w wyniku grawitacji
  velocity += gravity * timeStep;  // Zmiana prędkości przez grawitację

  // Zmiana pozycji na podstawie prędkości
  position += velocity * timeStep; // Zmiana pozycji przez prędkość

  // Wyświetlanie wyników
  Serial.print("Pozycja: ");
  Serial.println(position);
  Serial.print("Prędkość: ");
  Serial.println(velocity);

  delay(100);  // Opóźnienie 100ms (symulacja co 100ms)
}


*************************************************
#include <RGBmatrixPanel.h>  // Biblioteka do matrycy LED

// Definicje pinów i konfiguracja matrycy
#define CLK   8
#define DATA  9
#define LAT   10
RGBmatrixPanel matrix(A, B, C, CLK, LAT, DATA);

// Parametry fizyki obiektu
float x = 32.0f;  // Pozycja x (środek matrycy)
float y = 32.0f;  // Pozycja y (środek matrycy)
float radius = 3.0f;  // Promień kulki
float velocityX = 1.5f;  // Prędkość w osi X
float velocityY = 1.0f;  // Prędkość w osi Y
float gravity = 0.1f;  // Grawitacja

void setup() {
  matrix.begin();
}

void loop() {
  // Wyczyszczenie ekranu
  matrix.fillScreen(LOW);

  // Aktualizacja pozycji kulki
  x += velocityX;
  y += velocityY;

  // Zastosowanie grawitacji (zmiana prędkości w osi Y)
  velocityY += gravity;

  // Kolizje z krawędziami ekranu
  if (x - radius < 0 || x + radius > 63) {
    velocityX = -velocityX;  // Odbicie od krawędzi w osi X
  }
  if (y - radius < 0 || y + radius > 63) {
    velocityY = -velocityY;  // Odbicie od krawędzi w osi Y
  }

  // Rysowanie kulki
  matrix.fillCircle(x, y, radius, HIGH);

  delay(20);  // Opóźnienie, aby kontrolować prędkość animacji
}

