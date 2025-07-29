#ifndef EEPROM_SAVE_H
#define EEPROM_SAVE_H

#include <Arduino.h>
#include <EEPROM.h>

class EASY_EEPROM_STRUCT {
public:
    EASY_EEPROM_STRUCT(size_t eepromSize = 512);  

    void begin();
    void end();
    void clear();

    template<typename T>
    bool saveStruct(int address, const T& data) {
        begin();
        EEPROM.put(address, data);
        bool ok = EEPROM.commit();
        end();
        return ok;
    }

    template<typename T>
    bool loadStruct(int address, T& data) {
        begin();
        EEPROM.get(address, data);
        end();
        return true;
    }

private:
    size_t _eepromSize;
};

#endif
