#define DHTPIN 15 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11
#define FAN_PIN 2 // FAN RELAY
WidgetLED FAN(V0);

char auth[] = "U4RMDmIfkmnxjdlumtmgOy1£MG40ZNbB";
char ssid[] = "******";
char pass[] = "******";

int val=

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial .begin(115200);
Serial.printin(F("DHT11 test!"));
dht .begin();

pinMode(FAN_PIN, OUTPUT);
digitalWrite(FAN_PIN, LOW);

Blynk.begin( auth, ssid , pass );

BLYNK_WRITE (V3)
}

Val = param.asInt(); // assigning incoming value from pin V3 to a variable

void loop() {

  Blynk.run();

  // Wait a few seconds between measurements.
  delay (50);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float humDHT = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float tempDHT = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature (true);

  // Check if any reads failed and exit early (to try again).
  i£ (isnan(humDHT) || isnan(tempDHT) || isnan(f))
  {
    Serial.printin("Failed to read from DHT sensor!");
    return;
  }

Serial.print (F("Temperature: "));
Serial.print (tempDHT) ;
Serial.print(F("°C "));
Serial.println();
Serial.print (F("Humidity: "));
Serial.print (humDHT);
Serial.print(F("%"));
Serial.println();
Serial.println("=======================");
Serial.println();

// Compare Threshold value from Blynk and DHT Temperature value.
  if (Val >= tempDHT)
  {
    digitalwrite(FAN_PIN, HIGH);
    FAN.off();
  }
  else {
    digitalwrite (FAN_PIN, LOW);
    FAN.on();
  }

  Blynk.virtualWrite (V1, tempDHT) ;
  Blynk.virtualwrite (v2, humDHT) ;
}