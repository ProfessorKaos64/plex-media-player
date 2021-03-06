//
//  DisplayManagerOSX.h
//  konvergo
//
//  Created by Lionel CHAZALLON on 28/09/2014.
//
//

#ifndef _DISPLAYMANAGEROSX_H_
#define _DISPLAYMANAGEROSX_H_

#include "ApplicationServices/ApplicationServices.h"
#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFDictionary.h>

#include "display/DisplayManager.h"

#define MAX_DISPLAYS 32

typedef std::map<int, CFArrayRef> OSXDisplayModeMap;

class DisplayManagerOSX : public DisplayManager
{
  Q_OBJECT
private:
  // OSX Display/ VideoMode handling structs
  uint32_t m_osxnumDisplays;
  CGDirectDisplayID m_osxDisplays[MAX_DISPLAYS];
  OSXDisplayModeMap m_osxDisplayModes;

public:
  DisplayManagerOSX(QObject* parent) : DisplayManager(parent) {};
  virtual ~DisplayManagerOSX();

  virtual bool initialize();
  virtual bool setDisplayMode(int display, int mode);
  virtual int getCurrentDisplayMode(int display);
  virtual int getMainDisplay();
  virtual int getDisplayFromPoint(int x, int y);
};

#endif /* _DISPLAYMANAGEROSX_H_ */
