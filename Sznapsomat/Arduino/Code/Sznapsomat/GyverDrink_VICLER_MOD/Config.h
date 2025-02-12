//╞════════════════════════════════════════════════════════════════════════════════════╣ Ustawienia ⚒ ╠════════════════════════════════════════════════════════════════════════════════════╡

/*■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ Podstawowe ustawienia ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■*/

/*  ======================== Wybór wyświetlacza ========================
   0  → OLED 128x64 na kontrolerze SSD1306 lub SSD1309 (I2C)
   1  → OLED 128x64 na kontrolerze SH1106 (I2C)
   2  → OLED 128x64 na kontrolerze SSD1306 lub SSD1309 (SPI)
   3  → Wyświetlacz 4-cyfrowy 7-segmentowy na kontrolerze TM1637
   4  → Wskaźnik analogowy
*/
#define DISPLAY_TYPE   0

#define NUM_SHOTS      5     // liczba kieliszków (to również liczba diod LED i przycisków!)
#define SWITCH_LEVEL   0     // przyciski: 1 → wysoki sygnał przy zwarciu, 0 → niski
#define ENCODER_TYPE   1     // typ enkodera. 0 lub 1. Różnią się liczbą podziałek na obrót
#define ENCODER_DIR    1     // kierunek obrotu enkodera. 0 lub 1
//#define STATUS_LED     30    // jasność diody LED statusowej. 255 → maksimum. Odkomentować, jeśli podłączona
// #define BATTERY_PIN    A7    // + akumulatora (maks. 5V bez dzielnika). Odkomentować, jeśli podłączona
// #define CHARGER_PIN    A6    // IN+ z TP4056. Używane do wykrywania ładowania

#define MOTOR_TYPE     0     // typ napędu. Serwo - 0, Silnik krokowy - 1

// ======================== Ustawienia silnika krokowego ========================

#define STEPS_PER_REVOLUTION     180  // liczba kroków na obrót silnika
#define MICROSTEPS               1    // wartość mikro kroku ustawiona na sterowniku silnika
#define STEPPER_HOMING_SPEED     2    // prędkość obrotu silnika przy ruchu do krańcówki (jeśli jest) w obr/min
//#define SMOOTH_ALGORITHM               // jeszcze większa płynność ruchu!

// ========================= Ustawienia silnika serwo =========================

#define SERVO_MIN_US  544     // minimalna szerokość impulsu w µs
#define SERVO_MAX_US  2400    // maksymalna szerokość impulsu w µs

/*■■■■■■■■■■■■■■■■■■■■■ Parametry zmienne w trybie serwisowym ■■■■■■■■■■■■■■■■■■■■■■*/

#define TIME_50ML      5000  // czas napełniania 50 ml
#define MAX_VOLUME     51    // ograniczenie maksymalnej objętości. Maksymalna wartość 255
#define MOTOR_REVERSE  0     // odwrócenie kierunku obrotu silnika
#define PARKING_POS    0     // kąt silnika dla pozycji parkingowej
#define BATTERY_CAL    1.0   // współczynnik kalibracji napięcia akumulatora

// pozycje serwo nad kieliszkami. Od pierwszego do ostatniego
#define SHOT_POSITIONS       30, 60, 90, 120, 150, 180

/*■■■■■■■■■■■■■■■■■■■■■■■■■■ Dodatkowe ustawienia ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■*/

// Online konwerter kolorów https://bit.ly/34WSaig Używamy wartości H z HSV.

#define PREPUMP_VOLUME    0           // objętość cieczy w systemie w ml. Dodawana do objętości pierwszego kieliszka po włączeniu urządzenia, gdy system jest jeszcze pusty.
#define PAUSE_TIME        1000        // przerwa po nalaniu w ms.
#define LEDS_COLOR        270         // kolor podświetlenia diod LED od 0 do 360
#define TIMEOUT_STBY      10          // czas oczekiwania na przejście w tryb oczekiwania w sekundach. W trybie oczekiwania zapisywana jest ostatnia objętość, a jasność podświetlenia jest przyciemniona
#define TIMEOUT_OFF       5           // czas oczekiwania na przejście w tryb oszczędzania energii w minutach. W tym trybie wyłączany jest wyświetlacz i wszystkie diody LED. Jeśli 0 → tryb wyłączony
#define KEEP_POWER        0           // interwał utrzymania zasilania z powerbanku w sekundach. Po tym czasie następuje skok w poborze energii przez diody LED. 0 → funkcja wyłączona
#define MOTOR_SPEED       100         // prędkość napędu w stopniach/sek (maks. 255)
#define MOTOR_ACCEL      250      // przyspieszenie silnika w stopniach/sek^2
#define AUTO_PARKING      1           // parkowanie w trybie automatycznym: 1 → włączone, 0 → wyłączone
#define MOTOR_AUTO_POWER  1           // automatyczne wyłączanie silnika podczas postoju
#define SAVE_MODE         0           // 1 → zapis ostatniego aktywnego trybu w pamięci, 0 → brak zapisu
#define STBY_LIGHT        20          // jasność podświetlenia w trybie oczekiwania. 255 → maksimum, 0 → wyłączone
#define RAINBOW_FLOW      1           // 1 → dynamiczne podświetlenie nalanych kieliszków, 0 → statyczne
#define BATTERY_LOW       3.0         // minimalne napięcie akumulatora
#define MANUAL_MODE_STATUS_COLOR  200 // kolor diody LED statusowej w trybie ręcznym
#define AUTO_MODE_STATUS_COLOR    100 // kolor diody LED statusowej w trybie automatycznym
#define DISPLAY_SESSION_VOLUME    1   // wyświetlanie całkowitej objętości za sesję na głównej stronie. 1 → włączone, 0 → wyłączone

/*■■■■■■■■■■■■■■■■■■■■■■■■■■■ Ustawienia wyświetlacza OLED ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■*/

#define INVERT_DISPLAY 0     // inwersja kolorów wyświetlacza OLED
#define OLED_CONTRAST  15    // jasność wyświetlacza. Maks 255
#define MENU_SELECT    0     // 0 → wybór opcji menu za pomocą inwersji, 1 → za pomocą strzałki
#define MENU_LANG      1     // język menu. 0 → rosyjski, 1 → angielski
#define NUM_FONT       0     // wybór czcionki do wyświetlania objętości (0 lub 1)
#define WIRE_SPEED     888   // częstotliwość transmisji danych do wyświetlacza OLED w kHz (min 100, średnia 400, max 900). Zmniejsz częstotliwość, jeśli występują problemy z wyświetlaczem.
#define BOOTSCREEN     "Sznapsomat"  // tekst na wyświetlaczu OLED przy starcie urządzenia


//╞════════════════════════════════════════════════════════════════════════════════════╣ Połączenia ╠════════════════════════════════════════════════════════════════════════════════════╡

#define PUMP_POWER  3        // sygnał sterujący sterownikiem pompy (zwykle oznaczony jako IN na sterownikach silników, lub GATE/BASE, jeśli używany jest tranzystor)
#define SERVO_POWER 4        // sygnał sterujący sterownikiem zasilania silnika serwo (zwykle oznaczony jako IN na sterownikach silników, lub GATE/BASE, jeśli używany jest tranzystor)
#define SERVO_PIN   5        // sygnał z silnika serwo
#define LED_PIN     6        // sygnał DIO/DI pierwszej diody LED (WS2812b)
#define BTN_PIN     7        // sygnał z głównego przycisku do nalewania i zmiany trybów
#define ENC_SW      8        // sygnał centralnego przycisku na enkoderze do pompowania i ustawiania różnych objętości. Oznaczony jako SW lub BTN
#define ENC_DT      9        // sygnał DT lub A z enkodera
#define ENC_CLK     10       // sygnał CLK lub B z enkodera

//#define STEPPER_ENDSTOP 1    // sygnał z krańcówki dla silnika. W stanie aktywnym powinien zamykać na GND. Zakomentować, jeśli krańcówka nie jest używana
#define STEPPER_EN      2    // sygnał EN sterownika
#define STEPPER_DIR     4    // sygnał DIR sterownika
#define STEPPER_STEP    5    // sygnał STEP sterownika

/*■■■■■■■■■■■■■■■■■■■■■■■■■■■ Wersja z wyświetlaczem TM1639 ■■■■■■■■■■■■■■■■■■■■■■■■■■■*/
#if(DISPLAY_TYPE == 3)

#define DISP_DIO    11       // sygnał DIO na wyświetlaczu TM1637
#define DISP_CLK    12       // sygnał CLK na wyświetlaczu TM1637
#define SW_PINS     A0, A1, A2, A3, A4, A5    // sygnały z czujników obecności kieliszków na wersji TM1637: od pierwszego do ostatniego kieliszka

/*■■■■■■■■■■■■■■■■■■■■■■■■■■■■ Wersja z wyświetlaczem OLED ■■■■■■■■■■■■■■■■■■■■■■■■■■■■*/
#elif (DISPLAY_TYPE < 3)

#define DISP_SDA    A4       // sygnał SDA wyświetlacza OLED
#define DISP_SCK    A5       // sygnał SCK wyświetlacza OLED
// piny SPI
#define DISP_DC     0        // sygnał DC wyświetlacza OLED
#define DISP_MOSI   A4       // sygnał MOSI lub SDA wyświetlacza OLED
#define DISP_CLK    A5       // sygnał CLK lub SCL wyświetlacza OLED

#define SW_PINS     A0, A1, A2, A3, 11, 12  // sygnały z czujników obecności kieliszków na wersji OLED: od pierwszego do ostatniego kieliszka

/*■■■■■■■■■■■■■■■■■■■■■■■ Wersja z wskaźnikiem analogowym ■■■■■■■■■■■■■■■■■■■■■■■*/
#elif (DISPLAY_TYPE == 4)

#define ANALOG_METER_PIN 11  // + z wskaźnika
#define SW_PINS     A0, A1, A2, A3, A4, A5    // sygnały z czujników obecności kieliszków na wersji ANALOG_METER: od pierwszego do ostatniego kieliszka
#endif
