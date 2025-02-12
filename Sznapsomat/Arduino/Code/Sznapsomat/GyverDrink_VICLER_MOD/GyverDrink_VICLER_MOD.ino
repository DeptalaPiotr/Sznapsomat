//GyverDrink VICLER_MOD
#define VERSION 7.8
#define DISPLAY_VERSION 1
//29.11.2021
/*
==============================================================================================
Zmodyfikowana wersja oprogramowania projektu "Nalewator by AlexGyver" z rozszerzonymi funkcjami
==============================================================================================
⚠ Wszystkie ustawienia znajdują się w pliku Config.h ⚠
! Wszystkie schematy połączeń znajdują się w pliku Config.h w sekcji "Połączenia" !

⚫ Arduino Nano jako mikroprocesor sterujący (ATmega 328P).
⚫ Obsługa dwóch typów wyświetlaczy:
OLED na kontrolerze SSD1306 (0.96"), SH1106 (1.3") lub SSD1309 (2.42").

Połączenie I2C:
SCK → A5
SDA → A4
RES → RST
DC → GND
CS → GND
Połączenie SPI:
CLK → A5
SDA → A4
RES → RST
DC → 0
CS → GND
4-cyfrowy, 7-segmentowy wyświetlacz na kontrolerze TM1637.

Połączenie:
DIO → 11
CLK → 12
⚫ Silnik krokowy z driverem typu StepStick (A4899, DRV8825, LV8729, TMC2100/2208/2209) lub serwo.
⚫ Funkcja "Pompowania":
Postaw kieliszek, naciśnij i przytrzymaj przycisk enkodera.
Pompowanie dostępne jest tylko w trybie ręcznym i tylko wtedy, gdy kieliszek jest na miejscu.
Po zdjęciu kieliszka, napęd powraca do pozycji parkingowej, a licznik objętości jest resetowany.
⚫ Tryb zmienia się po przytrzymaniu głównego przycisku przez pół sekundy:
Tryb ręczny: nalewanie zaczyna się tylko po jednokrotnym naciśnięciu głównego przycisku.
Tryb automatyczny: nalewanie rozpoczyna się automatycznie natychmiast po postawieniu kieliszka.
⚫ Możliwość ustawienia objętości dla każdego kieliszka osobno:
Funkcja jest aktywna tylko wtedy, gdy liczba kieliszków > 1.
Po jednokrotnym naciśnięciu enkodera podświetlana jest pozycja kieliszka, dla którego zmienia się objętość. Wartość objętości zmienia się poprzez obrót enkodera. Po ponownym naciśnięciu podświetlana jest kolejna pozycja kieliszka.
Jeśli żaden kieliszek nie jest podświetlony, obrót enkodera zmienia objętość dla wszystkich kieliszków jednocześnie (tryb ręczny).
⚫ Nalewanie można przerwać w dowolnym momencie przez naciśnięcie głównego przycisku.
⚫ Ostatnio wybrana objętość jest zapisywana po nalaniu pierwszego kieliszka.
⚫ Dodatkowa dioda LED statusowa podłączona do ostatniego kieliszka, aktywuje się w STATUS_LED. Służy do wskazania trybów pracy.
⚫ Indykacja stanu akumulatora i monitorowanie napięcia:
Aktywowane przez odkomentowanie linii #define BATTERY_PIN ....
Jeśli napięcie jest niższe niż BATTERY_LOW (domyślnie 3.3V), urządzenie przestaje reagować na zewnętrzne sygnały, a na wyświetlaczu miga ikona baterii.
Jeśli po pierwszym uruchomieniu ikona baterii miga, ale napięcie jest w porządku (więcej niż BATTERY_LOW), przytrzymaj przycisk, aby przejść do menu kalibracji akumulatora.
Aby monitorować stan ładowania, należy podłączyć IN+ z modułu ładowania TP4056 do pinu A6. Podczas ładowania na wyświetlaczu pojawi się animacja.
⚫ Animacja startowa i dynamiczne podświetlenie kieliszków w czasie i po nalaniu.
=======================================
■■■■ Cechy wersji na wyświetlaczu TM1637 ■■■■
=======================================
Tryb serwisowy:
Wejście do trybu serwisowego następuje przez przytrzymanie głównego przycisku wybierania trybu podczas animacji startowej, aż na wyświetlaczu pojawi się napis "SerViCE". Po zwolnieniu przycisku wyświetli się numer etapu kalibracji:
-1- Kalibracja pozycji serwomechanizmu nad kieliszkami:

Usuń wszystkie kieliszki. Na wyświetlaczu pojawi się pozycja parkingowa w stopniach.
Obróć enkoder, aby zmienić pozycję parkingową.
Umieść kieliszek, a na wyświetlaczu pojawi się numer kieliszka i jego pozycja. Ustaw dokładną pozycję kieliszka.
Powtórz ten krok dla wszystkich kieliszków.
Po ustawieniu wszystkich kieliszków, naciśnij główny przycisk, aby przejść do następnego etapu kalibracji.
-2- Kalibracja czasowa dla nalania 50ml:

Umieść kieliszek w dowolnej pozycji, a kran ustawi się nad nim.
Naciśnij przycisk enkodera, aby włączyć pompę. Przytrzymaj, aż zacznie płynąć ciecz.
Zdejmij kieliszek i postaw pusty w dowolnym miejscu.
Przytrzymaj przycisk enkodera, aż napełni się dokładnie 50ml.
Zdejmij kieliszek. Naciśnij główny przycisk. Jeśli monitorowanie stanu akumulatora jest aktywne, na wyświetlaczu pojawi się kolejny numer etapu kalibracji. W przeciwnym razie kalibracja zakończona, wyświetli się domyślny objętość.
-3- Kalibracja napięcia akumulatora:

Na wyświetlaczu pojawi się napięcie akumulatora w [mV].
Obróć enkoder, aby dostosować wyświetlane napięcie do mierzonego napięcia multimetrem.
Naciśnij główny przycisk, aby zakończyć kalibrację. Na wyświetlaczu pojawi się domyślny objętość.
Dodatkowo:
Jeśli przycisk trybu serwisowego zostanie przytrzymany przez ponad 5 sekund, następuje reset ustawień z pamięci (TIME_50ML, SHOT_POSITIONS, PARKING_POS, BATTERY_CAL) do wartości domyślnych zapisanych w pliku Config.h.
=======================================
■■■■ Cechy wersji na wyświetlaczu OLED ■■■■
=======================================
Pełnoprawne menu graficzne. Wejście/Wyjście przez przytrzymanie głównego przycisku przez ponad pół sekundy. Wyjście z podmenu przez jednokrotne naciśnięcie.

Kalibracja objętości nalewania, kalibracja kątów serwomechanizmu oraz kalibracja napięcia akumulatora są dostępne w menu serwisowym. Wejście do tego menu następuje przez przytrzymanie głównego przycisku podczas animacji startowej.

Możliwość zmiany ustawień oprogramowania bezpośrednio w menu. Aby to zrobić, naciśnij przycisk enkodera na wybranym parametrze i obróć enkoder, aby zmienić wartość.

Rejestrowanie statystyk. Liczba nalanych kieliszków i całkowita objętość. Po naciśnięciu przycisku enkodera, wybrane dane są resetowane.

=====================================================================================================
₽$€ Na kawę dla autora: Link do PayPal lub viktorglekler@googlemail.com (PayPal)

★ Źródła na GitHub: Link do GitHub

★ Oryginalny projekt AlexGyver: Link do AlexGyver



   ====================================================================================================
*/

#ifndef __AVR_ATmega328P__
#error "Not ATmega328P board!"
#endif

//╞══════════════════════════════════════════════════════════════════════════════╡LIBS╞══════════════════════════════════════════════════════════════════════════════╡

// #define USE_TICOSERVO   // использование библиотеки Adafruit_TiCoServo вместо стандартной Servo. При использовании серводвигатель подключать к пину 9 или 10!
#include "Config.h"
#if (DISPLAY_TYPE < 2)
#include "src/microWire/microWire.h"
#include "src/SSD1306Ascii/src/SSD1306Ascii.h"
#include "src/SSD1306Ascii/src/SSD1306AsciiWire.h"
#elif (DISPLAY_TYPE == 2)
#include <SPI.h>
#include "src/SSD1306Ascii/src/SSD1306Ascii.h"
#include "src/SSD1306Ascii/src/SSD1306AsciiSoftSpi.h"
#elif (DISPLAY_TYPE == 3)
#include "src/GyverTM1637/GyverTM1637.h"
#endif
#if (MOTOR_TYPE == 0)
#include "src/ServoSmoothMinim.h"
#elif (MOTOR_TYPE == 1)
#include "src/GyverStepper.h"
#endif
#include "src/GyverTimers/GyverTimers.h"
#include "src/microLED/microLED.h"
#include "src/encUniversalMinim.h"
#include "src/buttonMinim.h"
#include "src/timer2Minim.h"
#include <EEPROM.h>

//╞══════════════════════════════════════════════════════════════════════════════╡DATA╞══════════════════════════════════════════════════════════════════════════════╡

#ifdef STATUS_LED
#define statusLed 1
#else
#define statusLed 0
#endif
LEDdata leds[NUM_SHOTS + statusLed];                  // буфер ленты типа LEDdata
microLED strip(leds, NUM_SHOTS + statusLed, LED_PIN); // объект лента
#if (MOTOR_TYPE == 0)
ServoSmoothMinim servo;
#elif (MOTOR_TYPE == 1)
GStepper<STEPPER2WIRE> stepper(STEPS_PER_REVOLUTION * MICROSTEPS, STEPPER_STEP, STEPPER_DIR, STEPPER_EN);
#endif
encMinim enc(ENC_CLK, ENC_DT, ENC_SW, ENCODER_DIR, ENCODER_TYPE); // пин clk, пин dt, пин sw, направление (0/1), тип (0/1)
buttonMinim btn(BTN_PIN);
buttonMinim encBtn(ENC_SW);

timerMinim LEDtimer(30);
timerMinim FLOWdebounce(20);
timerMinim FLOWtimer(2000);
timerMinim WAITtimer(PAUSE_TIME);
timerMinim TIMEOUTtimer(TIMEOUT_STBY * 1000L); // таймаут режима ожидания
timerMinim POWEROFFtimer(TIMEOUT_OFF * 60000L);
timerMinim KEEP_POWERtimer(KEEP_POWER * 1000L);


#define INIT_VOLUME 25
bool LEDchanged = false;
bool pumping = false;
int8_t curPumping = -1;
int8_t curSelected = -1;
int8_t selectShot = -1;
uint8_t shotCount = 0;
enum { NO_GLASS, EMPTY, IN_PROCESS, READY } shotStates[NUM_SHOTS];
enum { SEARCH, MOVING, WAIT, PUMPING } systemState;
enum serviceStates { POSITION, VOLUME, BATTERY } serviceState;
enum workModes { ManualMode, AutoMode } workMode;
uint16_t time50ml = TIME_50ML;
uint8_t thisVolume = INIT_VOLUME;
uint8_t shotVolume[NUM_SHOTS];
uint8_t initShotPos[] = {SHOT_POSITIONS};
uint8_t shotPos[] = {SHOT_POSITIONS};
const byte SW_pins[] = {SW_PINS};
float volumeTick = 20.0 * 50.0 / time50ml;  // volume in one FLOWdebounce timer tick
uint8_t actualVolume = 0;
float volumeCounter = 0;
bool systemON = false;
bool timeoutState = false;
bool parking = false;
bool LEDbreathingState = false;
bool LEDblinkState = false;
float battery_voltage = 4.2;
float battery_cal = BATTERY_CAL;
bool keepPowerState = false;
bool volumeChanged = true;
uint8_t parking_pos = PARKING_POS;
uint8_t animCount = 7;
bool showMenu = 0;
uint8_t menuItem = 1;
byte volumeColor[NUM_SHOTS];
const int ledsColor = LEDS_COLOR / 360.0 * 255;
const int manualModeStatusColor = MANUAL_MODE_STATUS_COLOR / 360.0 * 255;
const int autoModeStatusColor = AUTO_MODE_STATUS_COLOR / 360.0 * 255;
bool prepumped = false;
bool serviceBoot = false;
bool dispSTBicon = false;



#if(DISPLAY_TYPE < 3) // OLED
int16_t shots_session = 0, volume_overall = 0;
float volume_session = 0;
char bootscreen[] = {BOOTSCREEN};
#endif

// названия параметров в меню настроек OLED
enum
{
  timeout_off = 0,
  stby_time,
  stby_light,
  leds_color,
  rainbow_flow,
  invert_display,
  oled_contrast,
  max_volume,
  // доступны из сервисного меню
  motor_reverse,
  motor_speed,
  auto_parking,
  keep_power
};
// массив параметров в меню настроек OLED
uint8_t parameterList[] = {
  TIMEOUT_OFF,
  TIMEOUT_STBY,
  STBY_LIGHT,
  ledsColor,
  RAINBOW_FLOW,
  INVERT_DISPLAY,
  OLED_CONTRAST,
  MAX_VOLUME,
  // доступны из сервисного меню
  MOTOR_REVERSE,
  MOTOR_SPEED,
  AUTO_PARKING,
  KEEP_POWER
};


// расчёт адрессных ячеек для сохранения параметров
const struct EEPROMAddress
{
  const byte _thisVolume = 0;
  const byte _time50ml = _thisVolume + sizeof(thisVolume);
  const byte _shotPos = _time50ml + sizeof(time50ml);
  const byte _parking_pos = _shotPos + sizeof(byte) * NUM_SHOTS;
  const byte _workMode = _parking_pos + sizeof(parking_pos);
  const byte _battery_cal = _workMode + sizeof(byte);
  const byte _animCount = _battery_cal + sizeof(battery_cal);
#if(DISPLAY_TYPE < 3) // OLED
  const byte _timeout_off = _animCount + sizeof(animCount);
  const byte _stby_time = _timeout_off + sizeof(parameterList[timeout_off]);
  const byte _keep_power = _stby_time + sizeof(parameterList[stby_time]);
  const byte _motor_reverse = _keep_power + sizeof(parameterList[keep_power]);
  const byte _motor_speed = _motor_reverse + sizeof(parameterList[motor_reverse]);
  const byte _auto_parking = _motor_speed + sizeof(parameterList[motor_speed]);
  const byte _max_volume = _auto_parking + sizeof(parameterList[auto_parking]);
  const byte _stby_light = _max_volume + sizeof(parameterList[max_volume]);
  const byte _rainbow_flow = _stby_light + sizeof(parameterList[stby_light]);
  const byte _invert_display = _rainbow_flow + sizeof(parameterList[rainbow_flow]);
  const byte _leds_color = _invert_display + sizeof(parameterList[invert_display]);
  const byte _oled_contrast = _leds_color + sizeof(parameterList[leds_color]);
  const byte _volume_overall = _oled_contrast + sizeof(parameterList[oled_contrast]);
#endif
} eeAddress;



//╞══════════════════════════════════════════════════════════════════════════════╡MACROS╞══════════════════════════════════════════════════════════════════════════════╡

#define servoON() digitalWrite(SERVO_POWER, 1)
#define servoOFF() digitalWrite(SERVO_POWER, 0)
#define pumpON() digitalWrite(PUMP_POWER, 1)
#define pumpOFF() digitalWrite(PUMP_POWER, 0)

#ifdef STATUS_LED
#define LED leds[NUM_SHOTS]
#endif

#if (MOTOR_TYPE == 1) && defined STEPPER_ENDSTOP
#define ENDSTOP_STATUS (!digitalRead(STEPPER_ENDSTOP))
#endif