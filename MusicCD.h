#ifndef _MUSIC_CD_H_
#define _MUSIC_CD_H_

#include "Product.h"
#include <string>

class MusicCD : Product
{
  private:
    int numTracks;
    int artist;
    string* trackTitle;
    
  public:
    void printInfo();
}

#endif
