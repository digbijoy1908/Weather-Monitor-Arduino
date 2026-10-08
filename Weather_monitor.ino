//==================================================
//  SECTION 1: LIBRARIES (helper packs)
//==================================================
#include <DHT.h>                 // for the DHT11 sensor
#include <LiquidCrystal_I2C.h>   // for the I2C LCD screen
#include <Wire.h>                // for I2C communication


//==================================================
//  SECTION 2: LCD SETUP
//==================================================
// LCD address = 0x27, 16 columns, 2 rows
// (if the screen stays blank, try 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);


//==================================================
//  SECTION 3: SENSOR SETUP
//==================================================
#define DHTPIN A3        // sensor data pin is connected to A3
#define DHTTYPE DHT11    // sensor type is DHT11
DHT dht(DHTPIN, DHTTYPE);


//==================================================
//  SECTION 4: VARIABLES
//==================================================
int h;    // stores humidity
int t;    // stores temperature


//==================================================
//  SECTION 5: DEGREE SYMBOL (custom character)
//==================================================
// 1 = dot ON, 0 = dot OFF (5x8 dots per character)
byte degree[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};


//==================================================
//  SECTION 6: SETUP (runs one time)
//==================================================
void setup() {
  Serial.begin(9600);          // start Serial Monitor
  dht.begin();                 // start the sensor
  lcd.init();                  // start the LCD
  lcd.backlight();             // turn on the screen light
  lcd.createChar(0, degree);   // save the degree symbol as number 0
}


//==================================================
//  SECTION 7: LOOP (repeats forever)
//==================================================
void loop() {

  //------------------------------------------
  // 7.1 READ THE SENSOR
  //------------------------------------------
  h = dht.readHumidity();          // get humidity
  t = dht.readTemperature();       // get temperature

  //------------------------------------------
  // 7.2 SHOW VALUES ON SERIAL MONITOR
  //------------------------------------------
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %, Temp: ");
  Serial.print(t);
  Serial.println(" C");

  //------------------------------------------
  // 7.3 LCD ROW 1: TITLE
  //------------------------------------------
  lcd.setCursor(0, 0);             // column 0, row 0 (top left)
  lcd.print("Weather Monitor ");

  //------------------------------------------
  // 7.4 LCD ROW 2: TEMPERATURE (left side)
  //------------------------------------------
  lcd.setCursor(0, 1);             // column 0, row 1 (bottom left)
  lcd.print("T:");
  lcd.print(t);                    // temperature number
  lcd.write(0);                    // degree symbol
  lcd.print("C  ");                // extra spaces erase old characters

  //------------------------------------------
  // 7.5 LCD ROW 2: HUMIDITY (right side)
  //------------------------------------------
  lcd.setCursor(9, 1);             // column 9, row 1
  lcd.print("H:");
  lcd.print(h);                    // humidity number
  lcd.print("%  ");                // extra spaces erase old characters

  //------------------------------------------
  // 7.6 WAIT
  //------------------------------------------
  delay(1000);                     // wait 1 second, then repeat
}