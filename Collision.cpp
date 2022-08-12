/*!
 * Intro:
 * Decided to make a function that draws matricies into the screen and gice them collision
 * ONLY 5x5 MATRIX TESTED SO FAR
 * Dependencies:Adafruit PixelDust library
 * Author: Michael Cragun
 * BSD license, all text here must be included in any redistribution.
 */
#include "Collision.hpp"
#include "Adafruit_PixelDust.h"
#include "led-matrix-c.h"
#include "fontC.h"
#include <signal.h>
#include <iostream>
#include <iomanip>
#include <string>

//using std::setw;
//using namespace std;
//struct LedCanvas *canvas;
//struct RGBLedMatrix *matrix;  this is a coommment
Adafruit_PixelDust *sand = NULL;

namespace CollisionMatrix{

Collision col;



void Initiate(Adafruit_PixelDust *sand, LedCanvas *canvas){
  
  col.*sand = Adafruit_PixelDust *sand;

}
 
void show_images(const fontC::image_t &image, int x, int y, Adafruit_PixelDust *sand)
{
  
  for (auto& line : image) {
       y += 1;
       int t = x;
        for (auto& element : line) {
             t += 1;
            if(element == 1){
           // led_canvas_set_pixel(canvas, x + t, y, 150, 150, 150);
            sand->setPixel(x + t, y);     
      
    }
  }
}
}

void show_imagec(const fontC::image_t &image, int x, int y, LedCanvas *canvas)
{
  
  for (auto& line : image) {
       y += 1;
       int t = x;
        for (auto& element : line) {
             t += 1;
            if(element == 1){
            led_canvas_set_pixel(canvas, x + t, y, 200, 0, 255);
         //   sand->setPixel(x + t, y);     
      
    }
  }
}
}


/*
void show_image(const fontC::image_t &image)
{
  std::cout << "{\n";
  for (auto& line : image) {
    std::cout << " {";
    for (auto& element : line) {
      std::cout << element << ", ";
    }
    std::cout << "},\n";
  }
  std::cout << "}\n";
}
*/

 template<size_t size> void initMTX(Adafruit_PixelDust *sand, int x[][size], int a, int o){
   for(int U = 0; U < 5; U++, o++){
     for(size_t i = 0; i < size; i++){
       if(x[U][i] == 1){
          //cout << x[U][i] << ", " << endl;
         sand->setPixel(a + i, o); 
       }
 }
 
   }
 
}

 template<size_t size> void printMTX(LedCanvas *canvas, int x[][size], int a, int o, int R, int G, int B){
   for(int U = 0; U < 5; U++, o++){
     for(size_t i = 0; i < size; i++){
       if(x[U][i] == 1){
  //        cout << x[U][i] << ", " << endl;
         led_canvas_set_pixel(canvas, a + i, o, R, G, B);
           // return(o);
       }
 }
 
   }
 
}

void printtxt(std::string o, int x, int y, int R, int G, int B, int selectr, Adafruit_PixelDust *sand, LedCanvas *canvas){
     
             
     fontC::setup();
                    
     char ch;
                    
     int len = o.length();
             
     for(int a = 0; a < len; a++){ 
          
     ch = o.at(a);
          
     uint8_t character_index = static_cast<uint8_t>(ch);
     
     const fontC::image_t *image1 = fontC::charImage[character_index];
     
     if(selectr == 1){
     show_images(*image1, (a * 3) + x, y, sand);
}
     else if(selectr == 2){
     show_imagec(*image1, (a * 3) + x, y, canvas);
}
     else {
          std::cout << "ERROR 159" << std::endl;
     }
            
     //const fontC::image_t &image = (fontC::image_t *image1);

          //cout << x[U][i] << ", " << endl;
         //sand->setPixel(x + i + ( 5 * a), l); 
       }
 

 
   }
     
    
    
     
         //  led_canvas_set_pixel(canvas, x+i+(a*5), y, R, G, B);
 
   

  
 
 


/*
  char character = 'A';

  // Method 1: indexing an array of images
  uint8_t character_index = static_cast<uint8_t>(character);
  const fontC::image_t *image1 = fontC::charImage[character_index];
  show_image(*image1);

*/



 
     


template void printMTX<5>(LedCanvas *canvas, int x[][5], int a, int o, int R, int G, int B);
template void initMTX<5>(Adafruit_PixelDust *sand, int x[][5], int a, int o);



}
