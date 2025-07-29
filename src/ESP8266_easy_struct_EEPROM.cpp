#include "ESP8266_easy_struct_EEPROM.h"

EASY_EEPROM_STRUCT::EASY_EEPROM_STRUCT(size_t eepromSize)
    : _eepromSize(eepromSize) {}

void EASY_EEPROM_STRUCT::begin() {
    EEPROM.begin(_eepromSize);
}

void EASY_EEPROM_STRUCT::end() {
    EEPROM.end();
}

void EASY_EEPROM_STRUCT::clear() {
    begin();
    for (int i = 0; i < _eepromSize; i++) {
        EEPROM.write(i, 0);
    }
    EEPROM.commit();
    end();
}
