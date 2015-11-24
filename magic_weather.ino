#include <ArduinoJson.h>                 //Json Parser Library
#include <TFTv2.h>                       //Screen Library
#include <SPI.h>                        
#include <Bridge.h>
#include <Process.h>

#define LEFT2RIGHT 0                     //Screen Orientation Vars
#define DOWN2UP    1
#define RIGHT2LEFT 2
#define UP2DOWN    3

void setup() {
  
    TFT_BL_ON;                           //Turn on backlight
    Tft.TFTinit();                       //Init TFT Lib
    Tft.setDisplayDirect(UP2DOWN);       //Set Orientation
    
    StaticJsonBuffer<500> jsonBuffer;    //Buffer for json
    Process p;                           //Process for curl
    char inData[750] = {};               //array to hold curl request

    char tempDisplay[] = {'0','0','\0'}; //array for temperature
    char *tempP;                         //pointer for temperature
    char *descP;                         //pointer for weather description
    char *cityP;                         //pointer for city
    const char *keywP;                   //pointer for weather description keyword
    
    Bridge.begin();                      //Make contact with linux side
    Serial.begin(9600);                  //Begin serial transmition
    pinMode(13, OUTPUT);                 //Set pin output
    digitalWrite(13, HIGH);              //Write to pin to show bridge and serial is ready
       
    p.begin("curl");                     //begin curl            
    p.addParameter("api.openweathermap.org/data/2.5/weather?id=5780993&units=imperial&mode=json&APPID=e520bd843707ba2c49a4b0d895407f7d"); 
    p.run();                             //get json data from openweathermap.org for Salt Lake City

    short index = 0; 
    while (p.available() > 0) {          //Read each character from the curl process
      char c = p.read();                 //into the array
      inData[index] = c;
      index++;
    }
    inData[index] = '\0';   
    p.close();                           //when it is finished, close the process

    JsonObject& root = jsonBuffer.parseObject(inData);          //parse the array into json
    if (!root.success()) {                                      //if its not successful, exit the program early
      Serial.println("parseObject() failed");
      return;
    } else {                                                    //if it is successful
      const char* temp = root["main"]["temp"];                  //get the temperature
      char* tempCast = const_cast<char*>(temp);
      tempDisplay[0] = tempCast[0];
      tempDisplay[1] = tempCast[1];
      tempP = tempDisplay;

      const char* desc = root["weather"][0]["description"];     //get the description
      descP = const_cast<char*>(desc);
 
      const char* city = root["name"];                          //get the city
      cityP = const_cast<char*>(city);

      keywP = root["weather"][0]["main"];                       //get the description keyword
    
      delete temp, desc, city;                                  //free some memory
                    
      Tft.fillScreen(0, 240, 0, 320, GRAY1);                    //fill screen with gray

      if(strcmp(keywP,"Clear") == 0) {                          //if the sky is clear, display a sun
        for(int r = 0; r < 60; r = r + 2) {
          Tft.drawCircle(115, 205, r, YELLOW);       
        }
      } else if(strcmp(keywP,"Rain") == 0) {                    //if its raining, draw a raincloud
        Tft.fillCircle(140, 180, 20, BLUE); 
        Tft.fillCircle(140, 200, 20, BLUE);
        Tft.fillCircle(140, 220, 20, BLUE); 
        Tft.fillCircle(140, 240, 20, BLUE);  
        Tft.fillCircle(130, 190, 20, BLUE);  
        Tft.fillCircle(130, 210, 20, BLUE); 
        Tft.fillCircle(130, 230, 20, BLUE); 
        Tft.drawLine(100, 160, 110, 170, BLUE);
        Tft.drawLine(90, 180, 100, 190, BLUE);
        Tft.drawLine(90, 210, 100, 220, BLUE);   
      } else if(strcmp(keywP,"Clouds") == 0) {  
        for(int r = 0; r < 60; r = r + 2) {
          Tft.drawCircle(115, 205, r, YELLOW);       
        }
        Tft.fillCircle(140, 180, 20, BLUE); 
        Tft.fillCircle(140, 200, 20, BLUE);
        Tft.fillCircle(140, 220, 20, BLUE); 
        Tft.fillCircle(140, 240, 20, BLUE);  
        Tft.fillCircle(130, 190, 20, BLUE);  
        Tft.fillCircle(130, 210, 20, BLUE); 
        Tft.fillCircle(130, 230, 20, BLUE); 
      }

      Tft.drawString(cityP, 220, 20, 2, CYAN);                  //Print the City
      Tft.drawString(tempP, 130, 20, 5, WHITE);                 //Print the Temperature
      Tft.drawCircle(130, 100, 3, WHITE);                       //Degree symbol
      Tft.drawString(descP, 30, 20, 2, WHITE);                  //Print the Description
      
  }
}

void loop() {}
