#ifndef _COLLISION_HPP_
#define _COLLISION_HPP_

#include "led-matrix-c.h"
#include "Adafruit_PixelDust.h"
//#include "fontC.h"
//#include <cstddef>
//#include <ostream>
#include <iostream>

namespace CollisionMatrix {

class Collision{

  public:
  
  // template<int H>
  // void drawMTX(int a[][H], int L, int x, int o, int R, int G, int B);  

  void Initiate(Adafruit_PixelDust *sand, LedCanvas *canvas);
  
  template<unsigned size>  void initMTX(Adafruit_PixelDust *sand, int x[][size], int a, int o);
  
  template<unsigned size>  void printMTX(LedCanvas *canvas, int x[][size],  int a, int o, int R, int G, int B);
  
  void printtxt(std::string o, int x, int y, int R, int G, int B, int selectr, Adafruit_PixelDust *sand, LedCanvas *canvas);

  private:
  
   

}

}

#endif // _COLLISION_H_
  
