#ifndef BITMAP_H_
#define BITMAP_H_

static const unsigned char PROGMEM navCurrentPos[] = {
        0x0c, 0x00,
        0x0c, 0x00,
        0x33, 0x00,
        0x21, 0x00,
        0xcc, 0xc0,
        0xcc, 0xc0,
        0x21, 0x00,
        0x33, 0x00,
        0x0c, 0x00,
        0x0c, 0x00
};

static const unsigned char PROGMEM navFlag[] = {
        0x3f, 0xc0,
        0x3f, 0xc0,
        0x3f, 0xc0,
        0x3f, 0xc0,
        0x3f, 0xc0,
        0x3f, 0xc0,
        0x20, 0x00,
        0x20, 0x00,
        0x20, 0x00,
        0x20, 0x00
};

static const unsigned char PROGMEM menuNavigation[] = {
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x3e,
        0x00, 0x00, 0x22,
        0x00, 0x55, 0x22,
        0x00, 0x00, 0x3e,
        0x01, 0x00, 0x20,
        0x00, 0x00, 0x20,
        0x01, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x55, 0x40,
        0x3e, 0x00, 0x00,
        0x3e, 0x00, 0x10,
        0x3e, 0x00, 0x00,
        0x3e, 0x00, 0x10,
        0x20, 0x00, 0x00,
        0x21, 0x55, 0x40,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x44, 0xe4, 0x5f,
        0x65, 0x14, 0x44,
        0x55, 0xf4, 0x44,
        0x4d, 0x12, 0x84,
        0x45, 0x11, 0x1f,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuLog[] = {
        0x00, 0x00, 0x00,
        0x0f, 0xfc, 0x00,
        0x08, 0x06, 0x00,
        0x08, 0x05, 0x00,
        0x08, 0x04, 0x80,
        0x08, 0x04, 0x40,
        0x08, 0x04, 0x20,
        0x08, 0x07, 0xf0,
        0x09, 0xf0, 0x10,
        0x09, 0x10, 0x10,
        0x09, 0x10, 0x10,
        0x09, 0xf0, 0x10,
        0x09, 0x00, 0x10,
        0x09, 0x00, 0x10,
        0x09, 0x00, 0x10,
        0x08, 0x00, 0x10,
        0x0f, 0xff, 0xf0,
        0x00, 0x00, 0x00,
        0x10, 0x38, 0xe0,
        0x10, 0x45, 0x00,
        0x10, 0x45, 0x30,
        0x10, 0x45, 0x10,
        0x1f, 0x38, 0xe0,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuHardware[] = {
        0x00, 0xaa, 0x80,
        0x00, 0xaa, 0x80,
        0x00, 0x00, 0x00,
        0x01, 0xff, 0xc0,
        0x0d, 0x00, 0x58,
        0x01, 0x40, 0x40,
        0x0d, 0x00, 0x58,
        0x01, 0x00, 0x40,
        0x0d, 0x00, 0x58,
        0x01, 0x00, 0x40,
        0x0d, 0x00, 0x58,
        0x01, 0x00, 0x40,
        0x0d, 0x00, 0x58,
        0x01, 0xff, 0xc0,
        0x00, 0x00, 0x00,
        0x00, 0xaa, 0x80,
        0x00, 0xaa, 0x80,
        0x00, 0x00, 0x00,
        0x7d, 0x17, 0xce,
        0x11, 0x94, 0x11,
        0x11, 0x57, 0x91,
        0x11, 0x34, 0x11,
        0x7d, 0x14, 0x0e,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuAltimeter[] = {
        0x00, 0x00, 0x00,
        0x00, 0x80, 0x00,
        0x01, 0xc0, 0x00,
        0x01, 0x40, 0x00,
        0x02, 0x20, 0x00,
        0x02, 0x20, 0x80,
        0x06, 0x11, 0xc0,
        0x07, 0xf1, 0x40,
        0x0f, 0xfa, 0x20,
        0x0f, 0xff, 0xe0,
        0x1f, 0xff, 0xf0,
        0x1f, 0xff, 0xf8,
        0x3f, 0xff, 0xf8,
        0x3f, 0xff, 0xfc,
        0x7f, 0xff, 0xfc,
        0x7f, 0xff, 0xfe,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x39, 0x07, 0xdf,
        0x45, 0x01, 0x04,
        0x7d, 0x01, 0x04,
        0x45, 0x01, 0x04,
        0x45, 0xf1, 0x1f,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuCompass[] = {
        0x00, 0x00, 0x00,
        0x00, 0x10, 0x00,
        0x00, 0x38, 0x00,
        0x00, 0x7c, 0x00,
        0x00, 0x7c, 0x00,
        0x00, 0xfe, 0x00,
        0x00, 0xfe, 0x00,
        0x01, 0xff, 0x00,
        0x01, 0x39, 0x00,
        0x01, 0x39, 0x00,
        0x00, 0x82, 0x00,
        0x00, 0x44, 0x00,
        0x00, 0x44, 0x00,
        0x00, 0x28, 0x00,
        0x00, 0x28, 0x00,
        0x00, 0x10, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x3c, 0xe4, 0x5e,
        0x41, 0x16, 0xd1,
        0x41, 0x15, 0x5e,
        0x41, 0x14, 0x50,
        0x3c, 0xe4, 0x50,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuRadar[] = {
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x01, 0xff, 0x80,
        0x02, 0x00, 0xc0,
        0x04, 0x7e, 0x20,
        0x04, 0x81, 0x20,
        0x05, 0x03, 0xa0,
        0x05, 0x07, 0xa0,
        0x05, 0x0f, 0xa0,
        0x05, 0x07, 0xa0,
        0x05, 0x03, 0xa0,
        0x04, 0x81, 0x20,
        0x04, 0x7e, 0x20,
        0x02, 0x00, 0xc0,
        0x01, 0xff, 0x80,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x79, 0xf4, 0x5f,
        0x25, 0x04, 0x44,
        0x25, 0xe4, 0x44,
        0x25, 0x02, 0x84,
        0x79, 0xf1, 0x1f,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuSatellite[] = {
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x18, 0x3e, 0x0c,
        0x18, 0x41, 0x0c,
        0x18, 0x80, 0x8c,
        0x18, 0x80, 0x8c,
        0x1f, 0x80, 0xfc,
        0x18, 0x80, 0x8c,
        0x18, 0x80, 0x8c,
        0x18, 0x41, 0x0c,
        0x18, 0x3e, 0x0c,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x3c, 0xe7, 0xc0,
        0x41, 0x11, 0x00,
        0x39, 0xf1, 0x00,
        0x05, 0x11, 0x0c,
        0x79, 0x11, 0x0c,
        0x00, 0x00, 0x00
};

static const unsigned char PROGMEM menuGPS[] = { // 24x24
        0x00, 0x00, 0x00,
        0x00, 0xfe, 0x00,
        0x01, 0x01, 0x00,
        0x02, 0x00, 0x80,
        0x02, 0x38, 0x80,
        0x02, 0x44, 0x80,
        0x02, 0x44, 0x80,
        0x02, 0x44, 0x80,
        0x02, 0x38, 0x80,
        0x02, 0x00, 0x80,
        0x02, 0x00, 0x80,
        0x01, 0x01, 0x00,
        0x00, 0x82, 0x00,
        0x00, 0x44, 0x00,
        0x00, 0x28, 0x00,
        0x00, 0x10, 0x00,
        0x00, 0x00, 0x00,
        0x00, 0x00, 0x00,
        0x0e, 0x78, 0xf0,
        0x10, 0x45, 0x00,
        0x13, 0x78, 0xe0,
        0x11, 0x40, 0x10,
        0x0e, 0x41, 0xe0,
        0x00, 0x00, 0x00
};

/*----------------------------------------------------------------------*/

static const unsigned char PROGMEM sunrise_sunset_icon [] = { //18x14
        0x02, 0x00, 0x40,
        0x42, 0x10, 0xe0,
        0x20, 0x21, 0x50,
        0x07, 0x00, 0x40,
        0x08, 0x80, 0x40,
        0x10, 0x40, 0x40,
        0xd0, 0x58, 0x00,
        0x10, 0x40, 0x40,
        0x08, 0x80, 0x40,
        0x07, 0x00, 0x40,
        0x20, 0x21, 0x50,
        0x42, 0x10, 0xe0,
        0x02, 0x00, 0x40
};

static const unsigned char PROGMEM satellite_tracker_icon [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x00, 0x07, 0x00, 0x00, 0x03, 0x80, 0x00,
        0x00, 0x0f, 0x80, 0x00, 0x07, 0xc0, 0x00,
        0x00, 0x19, 0x80, 0x00, 0x06, 0x60, 0x00,
        0x00, 0x3b, 0x80, 0x00, 0x07, 0x30, 0x00,
        0x00, 0x1f, 0x00, 0x00, 0x03, 0xf0, 0x00,
        0x00, 0xfe, 0x00, 0x00, 0x01, 0xfc, 0x00,
        0x01, 0xfc, 0x00, 0x00, 0x00, 0xfe, 0x00,
        0x01, 0x38, 0x00, 0x00, 0x00, 0x32, 0x00,
        0x01, 0xf0, 0x00, 0x00, 0x00, 0x3e, 0x00,
        0x0f, 0xff, 0x00, 0x00, 0x03, 0xff, 0xc0,
        0x1f, 0xde, 0x00, 0x00, 0x01, 0xef, 0xe0,
        0x33, 0x1c, 0xa0, 0x00, 0x0a, 0xe3, 0x30,
        0x77, 0x1a, 0xa0, 0x00, 0x09, 0x63, 0x90,
        0x7e, 0x11, 0x20, 0x00, 0x0a, 0x21, 0xd0,
        0x3c, 0x06, 0x41, 0xf8, 0x09, 0xc0, 0xf0,
        0x18, 0x00, 0x86, 0x06, 0x04, 0x00, 0x60,
        0x00, 0x0f, 0x08, 0x01, 0x03, 0xc0, 0x00,
        0x00, 0x00, 0x14, 0xcc, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x2f, 0xff, 0x40, 0x00, 0x00,
        0x00, 0x00, 0x5f, 0xff, 0x60, 0x00, 0x00,
        0x00, 0x00, 0x5f, 0xff, 0x60, 0x00, 0x00,
        0x00, 0x00, 0x9f, 0xfe, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x83, 0xd9, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x8f, 0xc3, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x9f, 0xe2, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x9f, 0xe7, 0x90, 0x00, 0x00,
        0x00, 0x00, 0x8f, 0xf0, 0xd0, 0x00, 0x00,
        0x00, 0x00, 0x43, 0xf0, 0x20, 0x00, 0x00,
        0x00, 0x00, 0x41, 0xe3, 0xa0, 0x00, 0x00,
        0x00, 0x00, 0x21, 0xc7, 0xc0, 0x00, 0x00,
        0x00, 0x00, 0x10, 0xc7, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x08, 0xc5, 0x3e, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x06, 0x40, 0x03, 0x00,
        0x00, 0x00, 0x01, 0xf8, 0x8c, 0x07, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x91, 0x0f, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0xab, 0x1d, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0xa7, 0x19, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x8f, 0x7f, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x90, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x3b, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM radar_icon [] = {
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3c, 0x20, 0xe0, 0x00, 0x00,
        0x00, 0x00, 0xc0, 0x20, 0x18, 0x00, 0x00,
        0x00, 0x03, 0x00, 0x20, 0x06, 0x00, 0x00,
        0x00, 0x04, 0x00, 0x20, 0x01, 0x00, 0x00,
        0x00, 0x78, 0x00, 0x20, 0x00, 0xc0, 0x00,
        0x00, 0xf8, 0x00, 0x20, 0x00, 0x20, 0x00,
        0x00, 0xf8, 0x00, 0x20, 0x00, 0x10, 0x00,
        0x00, 0xf8, 0x00, 0x20, 0x00, 0x08, 0x00,
        0x01, 0x70, 0x00, 0x20, 0x00, 0x04, 0x00,
        0x01, 0x00, 0x01, 0xfc, 0x00, 0x04, 0x00,
        0x02, 0x00, 0x0e, 0x23, 0xb8, 0x02, 0x00,
        0x04, 0x00, 0x10, 0x20, 0x7c, 0x01, 0x00,
        0x04, 0x00, 0x60, 0x20, 0x7c, 0x01, 0x00,
        0x08, 0x00, 0x80, 0x20, 0x7c, 0x00, 0x80,
        0x08, 0x01, 0x00, 0x20, 0x3c, 0x00, 0x80,
        0x10, 0x01, 0x0e, 0x20, 0x04, 0x00, 0x80,
        0x10, 0x02, 0x1f, 0x20, 0x02, 0x00, 0x40,
        0x10, 0x04, 0x1f, 0x20, 0x01, 0x00, 0x40,
        0x10, 0x04, 0x1f, 0xf8, 0x01, 0x00, 0x40,
        0x20, 0x04, 0x0f, 0x24, 0x01, 0x00, 0x20,
        0x20, 0x08, 0x02, 0x22, 0x00, 0x80, 0x20,
        0x20, 0x08, 0x04, 0x21, 0x00, 0x80, 0x20,
        0x20, 0x08, 0x04, 0x21, 0x00, 0x80, 0x20,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
        0x20, 0x08, 0x04, 0x21, 0x00, 0x80, 0x20,
        0x20, 0x08, 0x04, 0x21, 0x00, 0x80, 0x20,
        0x20, 0x08, 0x02, 0x22, 0x70, 0x80, 0x20,
        0x20, 0x04, 0x01, 0x24, 0xf9, 0x00, 0x20,
        0x20, 0x04, 0x00, 0xf8, 0xf9, 0x00, 0x40,
        0x10, 0x04, 0x00, 0x20, 0xf9, 0x00, 0x40,
        0x10, 0x02, 0x00, 0x20, 0x72, 0x00, 0x40,
        0x10, 0x02, 0x00, 0x20, 0x04, 0x00, 0x40,
        0x08, 0x01, 0x70, 0x20, 0x04, 0x00, 0x80,
        0x08, 0x00, 0xf8, 0x20, 0x08, 0x00, 0x80,
        0x04, 0x00, 0xf8, 0x20, 0x30, 0x01, 0x00,
        0x04, 0x00, 0xf8, 0x20, 0x40, 0x01, 0x00,
        0x02, 0x00, 0x7e, 0x23, 0x80, 0x02, 0x00,
        0x01, 0x00, 0x01, 0xfc, 0x00, 0x04, 0x00,
        0x01, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00,
        0x00, 0x80, 0x00, 0x20, 0x00, 0x08, 0x00,
        0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 0x00,
        0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
        0x00, 0x18, 0x00, 0x20, 0x00, 0xc0, 0x00,
        0x00, 0x04, 0x00, 0x20, 0x01, 0x00, 0x00,
        0x00, 0x03, 0x00, 0x20, 0x06, 0x00, 0x00,
        0x00, 0x00, 0xe0, 0x20, 0x18, 0x00, 0x00,
        0x00, 0x00, 0x1c, 0x21, 0xe0, 0x00, 0x00,
        0x00, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM reception_signal_icon [] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xcc, 0x00, 0x00, 0x40,
        0x00, 0x00, 0x01, 0xc6, 0x00, 0x00, 0xe0,
        0x00, 0x00, 0x03, 0xe3, 0x00, 0x0d, 0xc0,
        0x00, 0x00, 0x06, 0x37, 0x80, 0x1f, 0x80,
        0x00, 0x0f, 0x07, 0x1e, 0xc7, 0xf7, 0x00,
        0x00, 0x3f, 0x03, 0x9c, 0x6e, 0xf3, 0x80,
        0x00, 0x70, 0x01, 0xfe, 0x38, 0x31, 0x80,
        0x00, 0xe3, 0x00, 0xf3, 0x30, 0x1f, 0x00,
        0x00, 0xcf, 0x00, 0x71, 0xe1, 0x8e, 0x00,
        0x01, 0x9c, 0x00, 0x39, 0xc3, 0xc6, 0x00,
        0x01, 0x99, 0x80, 0x1d, 0x86, 0xe6, 0x00,
        0x01, 0xb3, 0xc0, 0x0f, 0x0c, 0x62, 0x00,
        0x01, 0xb6, 0x60, 0x06, 0x18, 0xc6, 0x00,
        0x00, 0x06, 0x60, 0x0c, 0x31, 0x86, 0x00,
        0x00, 0x03, 0xc0, 0x0c, 0x63, 0x0c, 0x00,
        0x00, 0x01, 0x80, 0x07, 0x76, 0x18, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x3c, 0x3c, 0x00,
        0x00, 0x00, 0x00, 0x7d, 0x98, 0x66, 0x00,
        0x00, 0x00, 0x00, 0x70, 0xc0, 0xe3, 0x00,
        0x00, 0x00, 0x00, 0x38, 0x71, 0xf1, 0x80,
        0x00, 0x00, 0x00, 0x1c, 0x33, 0x1b, 0xc0,
        0x00, 0x00, 0x00, 0x0e, 0x7f, 0x8f, 0x60,
        0x00, 0x00, 0x00, 0x07, 0x6d, 0xce, 0x30,
        0x00, 0x00, 0x00, 0x03, 0xc0, 0xff, 0x18,
        0x00, 0x00, 0xe0, 0x01, 0xc0, 0x79, 0x98,
        0x00, 0x01, 0xf0, 0x00, 0xc0, 0x38, 0xf0,
        0x01, 0xff, 0x90, 0x00, 0x00, 0x1c, 0xe0,
        0x1f, 0xff, 0xf0, 0x00, 0x00, 0x0e, 0xc0,
        0x3f, 0x71, 0xe0, 0x00, 0x00, 0x07, 0x80,
        0x37, 0x3b, 0x40, 0x00, 0x00, 0x03, 0x00,
        0x63, 0x9e, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x61, 0xce, 0xc0, 0x00, 0x00, 0x00, 0x00,
        0x60, 0xe7, 0xc0, 0x00, 0x06, 0x00, 0x00,
        0x60, 0x73, 0xc0, 0x00, 0x0f, 0x00, 0x00,
        0x60, 0x39, 0xc0, 0x00, 0x19, 0x80, 0x00,
        0x60, 0x1c, 0xe0, 0x00, 0x19, 0xb6, 0x00,
        0x60, 0x0e, 0xc0, 0x00, 0x0f, 0x36, 0x00,
        0x20, 0x07, 0x80, 0x00, 0x06, 0x66, 0x00,
        0x30, 0x03, 0x80, 0x00, 0x00, 0xe6, 0x00,
        0x18, 0x01, 0xc0, 0x00, 0x03, 0xcc, 0x00,
        0x1c, 0x01, 0xc0, 0x00, 0x03, 0x1c, 0x00,
        0x1f, 0x87, 0x00, 0x00, 0x00, 0x38, 0x00,
        0x13, 0xfe, 0x00, 0x00, 0x03, 0xf0, 0x00,
        0x10, 0x60, 0x00, 0x00, 0x03, 0xc0, 0x00,
        0x10, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x10, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM route_icon [] = {
        0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x07, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00,
        0x1f, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00,
        0x30, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
        0x30, 0x7c, 0x1c, 0x00, 0x00, 0x00, 0x00,
        0x70, 0xfe, 0x0c, 0x00, 0x00, 0x00, 0x00,
        0xe1, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00,
        0xe3, 0xc7, 0x86, 0x00, 0x00, 0x00, 0x00,
        0xe3, 0x83, 0x86, 0x00, 0x00, 0x00, 0x00,
        0xe3, 0x83, 0x86, 0x00, 0x00, 0x00, 0x00,
        0xe3, 0x83, 0x86, 0x00, 0x00, 0x00, 0x00,
        0xe3, 0xc7, 0x86, 0x00, 0x00, 0x00, 0x00,
        0x61, 0xff, 0x0e, 0x00, 0x00, 0x00, 0x00,
        0x70, 0xfe, 0x0e, 0x00, 0x00, 0x00, 0x00,
        0x70, 0x7c, 0x1c, 0x00, 0x00, 0x00, 0x00,
        0x30, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
        0x30, 0x00, 0x18, 0x00, 0x01, 0xfe, 0x00,
        0x1c, 0x00, 0x38, 0x00, 0x1f, 0xff, 0x80,
        0x1c, 0x00, 0x70, 0x00, 0x1c, 0x03, 0xe0,
        0x0e, 0x00, 0x70, 0x00, 0x38, 0x00, 0xf0,
        0x0e, 0x00, 0xe0, 0x00, 0x70, 0x00, 0x70,
        0x07, 0x00, 0xc0, 0x00, 0xf0, 0x00, 0x30,
        0x03, 0x83, 0xc0, 0x01, 0xe0, 0xf8, 0x18,
        0x01, 0x83, 0x80, 0x01, 0xc1, 0xfc, 0x18,
        0x01, 0x87, 0x00, 0x01, 0x83, 0xfe, 0x1c,
        0x00, 0xc6, 0x00, 0x01, 0x87, 0x8f, 0x1c,
        0x00, 0xee, 0x00, 0x01, 0x87, 0x07, 0x1c,
        0x00, 0xfc, 0x00, 0x01, 0x87, 0x07, 0x1c,
        0x00, 0x7c, 0x00, 0x01, 0x87, 0x07, 0x1c,
        0x00, 0x7e, 0x00, 0x01, 0x87, 0x8f, 0x1c,
        0x00, 0xff, 0x00, 0x01, 0xc3, 0xfe, 0x18,
        0x00, 0xe7, 0xff, 0x81, 0xc1, 0xfc, 0x18,
        0x00, 0xe7, 0xff, 0xc0, 0xe0, 0xf8, 0x18,
        0x00, 0xff, 0xff, 0xf0, 0xf0, 0x00, 0x70,
        0x00, 0xff, 0x00, 0x70, 0x30, 0x00, 0x70,
        0x00, 0x7e, 0x00, 0x30, 0x30, 0x00, 0xe0,
        0x00, 0x18, 0x00, 0x30, 0x18, 0x00, 0xe0,
        0x00, 0x00, 0x00, 0x30, 0x1c, 0x01, 0xc0,
        0x00, 0x00, 0x00, 0xf0, 0x1e, 0x03, 0x80,
        0x00, 0xff, 0xff, 0xf0, 0x06, 0x03, 0x00,
        0x01, 0xff, 0xff, 0xc0, 0x07, 0x06, 0x00,
        0x03, 0xff, 0xff, 0x00, 0x03, 0x86, 0x00,
        0x07, 0x80, 0x00, 0x00, 0x03, 0x8e, 0x00,
        0x07, 0x00, 0x00, 0x00, 0x01, 0xdc, 0x00,
        0x06, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00,
        0x06, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00,
        0x07, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00,
        0x03, 0x80, 0x00, 0x00, 0x03, 0x9c, 0x00,
        0x03, 0xff, 0xfc, 0xcf, 0xff, 0x9c, 0x00,
        0x00, 0xff, 0xfc, 0xcf, 0xff, 0xfc, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00
};
static const unsigned char PROGMEM borany_icon [] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe1, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0xf2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0xf2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0x92, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0x8a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe2, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe1, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x2a, 0xaa, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x2a, 0xaa, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x2a, 0xaa, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x30, 0x00, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x30, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x00, 0x00, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x00, 0x00, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x00, 0x00, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x17, 0x2e, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x35, 0x6a, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x15, 0x2a, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x15, 0x2a, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x1d, 0x17, 0x2e, 0x5c, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x2a, 0xaa, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x2a, 0xaa, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x2a, 0xaa, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe3, 0xc7, 0x3c, 0x71, 0x14, 0x5d, 0xdc, 0x47,
        0xe2, 0x28, 0xa2, 0x89, 0x94, 0x45, 0x44, 0xc7,
        0xe3, 0xc8, 0xbc, 0xf9, 0x52, 0x9d, 0x5c, 0x47,
        0xe2, 0x28, 0xa4, 0x89, 0x31, 0x11, 0x50, 0x47,
        0xe3, 0xc7, 0x22, 0x89, 0x11, 0x1d, 0xdc, 0x47,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
static const unsigned char PROGMEM gps_map_icon [] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
        0xe0, 0x00, 0x00, 0xe3, 0x80, 0x0c, 0x00,
        0xe0, 0x00, 0x00, 0x61, 0x80, 0x0c, 0x00,
        0xe0, 0x00, 0x00, 0x61, 0x80, 0x0c, 0x00,
        0xe0, 0x3f, 0x00, 0x71, 0x80, 0x0c, 0x00,
        0xe0, 0x7f, 0x80, 0x71, 0xc0, 0x0c, 0x00,
        0xe1, 0xff, 0xe0, 0x71, 0xc0, 0x0c, 0x00,
        0xe1, 0x80, 0x70, 0x30, 0xc0, 0x0c, 0x00,
        0xe3, 0x8c, 0x30, 0x38, 0xc0, 0x0c, 0x00,
        0xe7, 0x3f, 0x38, 0x38, 0xe0, 0x0c, 0x00,
        0xe7, 0x3f, 0x38, 0x38, 0xe0, 0x0c, 0x00,
        0xe6, 0x73, 0x9f, 0xf8, 0x7f, 0xfc, 0x00,
        0xe6, 0x73, 0x98, 0x00, 0x00, 0x0c, 0x00,
        0xe7, 0x7f, 0x98, 0x00, 0x00, 0x0c, 0x00,
        0xe7, 0x3f, 0x38, 0x00, 0x00, 0x0c, 0x00,
        0xe3, 0x9e, 0x30, 0x00, 0x00, 0x0c, 0x00,
        0xe3, 0x80, 0x70, 0x00, 0x00, 0x0c, 0x00,
        0xff, 0xc0, 0xff, 0x0f, 0xcc, 0xfc, 0x00,
        0xff, 0xe0, 0xff, 0x0f, 0xcc, 0xfc, 0x00,
        0xff, 0xe1, 0xff, 0x1f, 0x00, 0x7c, 0x00,
        0xe0, 0x73, 0x87, 0x18, 0x00, 0x0c, 0x00,
        0xe0, 0x3f, 0x0e, 0x38, 0x00, 0x0c, 0x00,
        0xe0, 0x1e, 0x1c, 0x70, 0x3f, 0xcc, 0x00,
        0xe0, 0x0c, 0x1c, 0xe0, 0xff, 0xfc, 0x00,
        0xe0, 0x04, 0x38, 0xe3, 0xe0, 0xfc, 0x00,
        0xe0, 0x00, 0x39, 0xc7, 0x80, 0x1e, 0x00,
        0xe0, 0x00, 0x31, 0xc7, 0x00, 0x0f, 0x00,
        0xff, 0xc4, 0x71, 0x9c, 0x00, 0x07, 0xc0,
        0xff, 0xc4, 0x63, 0x38, 0x00, 0x01, 0xc0,
        0xe0, 0x00, 0xe3, 0x38, 0x00, 0x00, 0xc0,
        0xe0, 0x00, 0xe7, 0x70, 0x00, 0x00, 0x40,
        0xe0, 0x01, 0xc7, 0x60, 0x00, 0x00, 0x60,
        0xe0, 0x03, 0xce, 0xe7, 0xcf, 0x0f, 0x60,
        0xe0, 0x03, 0x9c, 0xc7, 0xcf, 0x9f, 0x70,
        0xe0, 0x07, 0x1c, 0xcc, 0x0d, 0x98, 0x70,
        0xe0, 0x07, 0x38, 0xcc, 0x0f, 0x98, 0x70,
        0xff, 0xff, 0xff, 0xcc, 0xef, 0x9f, 0x70,
        0xff, 0xff, 0xff, 0xcf, 0xef, 0x01, 0xf0,
        0x00, 0x00, 0x00, 0xe7, 0xec, 0x1f, 0x70,
        0x00, 0x00, 0x00, 0xe7, 0x8c, 0x1e, 0x60,
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x60,
        0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x60,
        0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0xc0,
        0x00, 0x00, 0x00, 0x1c, 0x00, 0x01, 0xc0,
        0x00, 0x00, 0x00, 0x1c, 0x00, 0x03, 0x80,
        0x00, 0x00, 0x00, 0x0e, 0x00, 0x07, 0x00,
        0x00, 0x00, 0x00, 0x07, 0x00, 0x0e, 0x00,
        0x00, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00
};
static const unsigned char PROGMEM task_icon [] = {
        0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
        0xc0, 0x1a, 0x26, 0x66, 0x45, 0x80, 0x30,
        0xc0, 0x1b, 0x66, 0x66, 0x6d, 0x80, 0x30,
        0xc0, 0x1f, 0xff, 0xff, 0xff, 0x80, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
        0xf8, 0x00, 0x31, 0x08, 0xc0, 0x03, 0x00,
        0xf8, 0x00, 0x31, 0x08, 0xc0, 0x03, 0x00,
        0xc8, 0x00, 0x31, 0x08, 0xc0, 0x03, 0xf0,
        0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xd8, 0x00, 0xff, 0xfc, 0xf0, 0x00, 0x30,
        0xc8, 0x01, 0xff, 0xfc, 0x78, 0x00, 0x30,
        0xd8, 0x01, 0x80, 0x00, 0x18, 0x00, 0x30,
        0xf8, 0x1d, 0xff, 0x80, 0x19, 0x80, 0x30,
        0xc8, 0x1d, 0xff, 0xc0, 0x19, 0x80, 0x30,
        0xc8, 0x01, 0x80, 0xc0, 0x18, 0x00, 0x30,
        0xf8, 0x01, 0x80, 0xc0, 0x18, 0x00, 0x30,
        0xf8, 0x01, 0x80, 0xc0, 0x18, 0x00, 0x30,
        0xc8, 0x1d, 0x80, 0xc2, 0x1b, 0x80, 0x30,
        0xc8, 0x01, 0x80, 0xc2, 0x18, 0x00, 0x30,
        0xf8, 0x01, 0x80, 0xc2, 0x18, 0x00, 0x30,
        0xf8, 0x01, 0x80, 0x42, 0x18, 0x00, 0x30,
        0xc8, 0x01, 0x80, 0x02, 0x18, 0x00, 0x30,
        0xc8, 0x1d, 0x80, 0x02, 0x1b, 0x80, 0x30,
        0xf8, 0x01, 0x80, 0xc0, 0x18, 0x00, 0x30,
        0xf8, 0x01, 0x80, 0xc0, 0x18, 0x00, 0x30,
        0xc8, 0x01, 0x80, 0xc0, 0x18, 0x00, 0x30,
        0xc8, 0x1d, 0xff, 0xc0, 0x19, 0x80, 0x30,
        0xf8, 0x1d, 0xff, 0x80, 0x19, 0x80, 0x30,
        0xd8, 0x01, 0x80, 0x00, 0x18, 0x00, 0x30,
        0xc8, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x30,
        0xd8, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x30,
        0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xc8, 0x00, 0x01, 0x08, 0x00, 0x3f, 0x30,
        0xf8, 0x00, 0x31, 0x08, 0xc0, 0x31, 0x30,
        0xf8, 0x00, 0x31, 0x08, 0xc0, 0x21, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x21, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x21, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
        0xc0, 0x1f, 0xff, 0xff, 0xff, 0x80, 0x30,
        0xc0, 0x1b, 0x66, 0x66, 0x6d, 0x80, 0x30,
        0xc0, 0x1a, 0x26, 0x66, 0x45, 0x80, 0x30,
        0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
        0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0
};
static const unsigned char PROGMEM connecting_icon [] = { // 54x54
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0xc7, 0x1b, 0x00,
        0x00, 0x00, 0x00, 0x01, 0xc3, 0xbf, 0x80,
        0x00, 0x00, 0x00, 0x00, 0xe3, 0xff, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x77, 0xe6, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x3f, 0xc3, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x1b, 0x81, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x06, 0x03, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0c, 0x0f, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x0c, 0x1f, 0xc0,
        0x00, 0x00, 0x00, 0x00, 0x06, 0x3f, 0xe0,
        0x00, 0x00, 0x00, 0x00, 0x07, 0xf6, 0x70,
        0x00, 0x00, 0x00, 0x01, 0x79, 0xce, 0x30,
        0x00, 0x00, 0x00, 0x03, 0x78, 0x0e, 0x18,
        0x00, 0x03, 0xf8, 0x03, 0xf8, 0x07, 0x38,
        0x00, 0x1f, 0xff, 0x81, 0xd8, 0x03, 0xf0,
        0x00, 0x7f, 0x7f, 0xc0, 0xe0, 0x01, 0xe0,
        0x00, 0xf6, 0x6e, 0xe0, 0x78, 0x00, 0xc0,
        0x01, 0xc4, 0x66, 0x78, 0x10, 0x00, 0x00,
        0x07, 0x8c, 0x63, 0x1e, 0x00, 0x00, 0x00,
        0x0f, 0x98, 0x61, 0xbe, 0x00, 0x00, 0x00,
        0x0f, 0xf8, 0x61, 0xfe, 0x00, 0x00, 0x00,
        0x18, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00,
        0x18, 0x3f, 0xff, 0x83, 0x80, 0x00, 0x00,
        0x10, 0x30, 0x60, 0x81, 0x80, 0x00, 0x00,
        0x30, 0x30, 0x60, 0x81, 0xc0, 0x00, 0x00,
        0x30, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00,
        0x30, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00,
        0x60, 0x60, 0x60, 0xc0, 0x60, 0x00, 0x00,
        0x60, 0x60, 0x60, 0xc0, 0x60, 0x00, 0x00,
        0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
        0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00,
        0x60, 0x60, 0x60, 0xc0, 0x60, 0x00, 0x00,
        0x60, 0x60, 0x60, 0xc0, 0x60, 0x00, 0x00,
        0x60, 0x60, 0x60, 0xc0, 0x60, 0x00, 0x00,
        0x30, 0x60, 0x60, 0xc0, 0xc0, 0x00, 0x00,
        0x30, 0x30, 0x60, 0x80, 0xc0, 0x00, 0x00,
        0x30, 0x30, 0x60, 0x81, 0xc0, 0x00, 0x00,
        0x10, 0x30, 0x60, 0x81, 0x80, 0x00, 0x00,
        0x18, 0x3f, 0xff, 0x83, 0x80, 0x00, 0x00,
        0x18, 0xff, 0xff, 0xe3, 0x00, 0x00, 0x00,
        0x0f, 0xf8, 0x61, 0xfe, 0x00, 0x00, 0x00,
        0x07, 0x0c, 0x63, 0x0e, 0x00, 0x00, 0x00,
        0x03, 0x8c, 0x63, 0x1c, 0x00, 0x00, 0x00,
        0x01, 0xc4, 0x66, 0x78, 0x00, 0x00, 0x00,
        0x00, 0xf6, 0x6e, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00,
        0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM mini_satellite_icon [] = { // 15x7
        0x87, 0x08,
        0x8f, 0x88,
        0x9f, 0xc8,
        0xff, 0xf8,
        0x9f, 0xc8,
        0x8f, 0x88,
        0x87, 0x08
};
static const unsigned char PROGMEM rising_icon [] = { // 10x5
        0x03, 0xc0,
        0x20, 0xc0,
        0x51, 0x40,
        0x8a, 0x40,
        0x04, 0x00
};
static const unsigned char PROGMEM no_changing_icon [] = { // 10x5
        0x01, 0x00,
        0x00, 0x80,
        0xff, 0xc0,
        0x00, 0x80,
        0x01, 0x00
};
static const unsigned char PROGMEM falling_icon [] = { // 10x5
        0x04, 0x00,
        0x8a, 0x40,
        0x51, 0x40,
        0x20, 0xc0,
        0x03, 0xc0
};

static const unsigned char PROGMEM compass_logo [] = { // 33x33
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x90, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x30, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0x6f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x6f, 0xc0, 0x00, 0x00,
        0x00, 0x00, 0xf8, 0x01, 0xf0, 0x00, 0x00,
        0x00, 0x01, 0xe0, 0x00, 0x78, 0x00, 0x00,
        0x00, 0x03, 0x80, 0x00, 0x1c, 0x00, 0x00,
        0x00, 0x07, 0x03, 0xfc, 0x0e, 0x00, 0x00,
        0x00, 0x0e, 0x0f, 0xff, 0x07, 0x00, 0x00,
        0x00, 0x1c, 0x3f, 0xff, 0x83, 0x80, 0x00,
        0x00, 0x18, 0x7f, 0xff, 0xe1, 0x80, 0x00,
        0x00, 0x38, 0xff, 0xff, 0xe1, 0xc0, 0x00,
        0x00, 0x30, 0xff, 0xfe, 0xf0, 0xc0, 0x00,
        0x00, 0x71, 0xff, 0xf8, 0x78, 0xe0, 0x00,
        0x00, 0x61, 0xff, 0xe0, 0xf8, 0x60, 0x00,
        0x00, 0x63, 0xff, 0x80, 0xf8, 0x60, 0x00,
        0x88, 0x63, 0xfe, 0x01, 0xfc, 0x63, 0xe0,
        0xa8, 0x03, 0xf0, 0x01, 0xfc, 0x02, 0x00,
        0xab, 0xe3, 0xc0, 0x03, 0xfc, 0x7b, 0xc0,
        0xab, 0xe3, 0x80, 0x03, 0xfc, 0x7a, 0x00,
        0x50, 0x03, 0x80, 0x07, 0xfc, 0x03, 0xe0,
        0x00, 0x63, 0xf0, 0x07, 0xfc, 0x60, 0x00,
        0x00, 0x63, 0xfc, 0x0f, 0xf8, 0x60, 0x00,
        0x00, 0x61, 0xfe, 0x0f, 0xf8, 0x60, 0x00,
        0x00, 0x71, 0xfe, 0x1f, 0xf8, 0xe0, 0x00,
        0x00, 0x30, 0xff, 0x1f, 0xf0, 0xc0, 0x00,
        0x00, 0x38, 0x7f, 0x3f, 0xe1, 0xc0, 0x00,
        0x00, 0x18, 0x7f, 0x3f, 0xc1, 0x80, 0x00,
        0x00, 0x1c, 0x1f, 0xff, 0x83, 0x80, 0x00,
        0x00, 0x0e, 0x0f, 0xff, 0x07, 0x00, 0x00,
        0x00, 0x07, 0x01, 0xf8, 0x0e, 0x00, 0x00,
        0x00, 0x03, 0x80, 0x00, 0x1c, 0x00, 0x00,
        0x00, 0x01, 0xe0, 0x00, 0x78, 0x00, 0x00,
        0x00, 0x00, 0xf8, 0x01, 0xf0, 0x00, 0x00,
        0x00, 0x00, 0x3f, 0x6f, 0xc0, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0x6f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM altimeter_logo [] = { // 33x33
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xe0, 0x00, 0x00,
        0x0f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00,
        0x0f, 0xff, 0xf0, 0x01, 0xff, 0xff, 0x00,
        0x1c, 0xff, 0x81, 0xf8, 0x3f, 0xe7, 0x00,
        0x18, 0x7e, 0x09, 0xfa, 0x0f, 0xc3, 0x00,
        0x18, 0x7c, 0x21, 0xf8, 0x03, 0xc3, 0x00,
        0x1c, 0xf0, 0x80, 0xf0, 0x91, 0xe7, 0x00,
        0x1f, 0xe6, 0x90, 0x60, 0xa4, 0xff, 0x00,
        0x1f, 0xc2, 0x40, 0x00, 0x28, 0x7f, 0x00,
        0x1f, 0x89, 0x00, 0x00, 0x19, 0x3f, 0x00,
        0x1f, 0x05, 0x00, 0x00, 0x12, 0x5f, 0x00,
        0x1f, 0x30, 0x00, 0x00, 0x00, 0x8f, 0x00,
        0x1e, 0x88, 0x00, 0x00, 0x01, 0x07, 0x00,
        0x1c, 0x40, 0x00, 0x00, 0x01, 0x67, 0x00,
        0x1c, 0x20, 0x18, 0x00, 0x06, 0x83, 0x80,
        0x39, 0x80, 0x1c, 0x00, 0x0c, 0x33, 0x80,
        0x38, 0x40, 0x0e, 0x00, 0x38, 0x43, 0xc0,
        0x3b, 0x00, 0x06, 0x00, 0x70, 0x1d, 0xc0,
        0x78, 0xc0, 0x07, 0x00, 0xc0, 0x71, 0xc0,
        0x70, 0x00, 0x03, 0x03, 0x80, 0x01, 0xc0,
        0x73, 0x80, 0x01, 0x87, 0x00, 0x19, 0xe0,
        0x70, 0x00, 0x01, 0xcc, 0x00, 0x00, 0xe0,
        0x77, 0x80, 0x00, 0xf8, 0x00, 0x1c, 0xe0,
        0x70, 0x00, 0x00, 0xf0, 0x00, 0x00, 0xe0,
        0x70, 0x00, 0x01, 0xf0, 0x00, 0x00, 0xe0,
        0x74, 0x00, 0x07, 0xf8, 0x00, 0x04, 0xe0,
        0x70, 0x00, 0x0f, 0x3c, 0x00, 0x01, 0xe0,
        0x73, 0x80, 0x07, 0x3e, 0x00, 0x1d, 0xc0,
        0x70, 0x00, 0x00, 0x3c, 0x00, 0x01, 0xc0,
        0x79, 0xc0, 0x00, 0x38, 0x00, 0x79, 0xc0,
        0x3a, 0x00, 0x00, 0x00, 0x00, 0x09, 0xc0,
        0x38, 0x40, 0x00, 0x00, 0x00, 0x63, 0xc0,
        0x3d, 0x00, 0x00, 0x00, 0x00, 0x13, 0x80,
        0x1c, 0x20, 0x00, 0x00, 0x00, 0x87, 0x80,
        0x1e, 0xc0, 0x00, 0x00, 0x00, 0x27, 0x00,
        0x1e, 0x10, 0x00, 0x00, 0x01, 0x0f, 0x00,
        0x1f, 0x20, 0x00, 0x00, 0x04, 0x8f, 0x00,
        0x1f, 0x05, 0x00, 0x00, 0x12, 0x1f, 0x00,
        0x1f, 0x89, 0x00, 0x00, 0x09, 0x3f, 0x00,
        0x1f, 0xc2, 0x40, 0x00, 0x2c, 0x7f, 0x00,
        0x1f, 0xe4, 0x90, 0x40, 0xa4, 0xff, 0x00,
        0x1c, 0xf8, 0xa5, 0x42, 0x91, 0xe7, 0x00,
        0x18, 0x7c, 0x21, 0x42, 0x03, 0xc3, 0x00,
        0x18, 0x7f, 0x09, 0x4a, 0x0f, 0xc3, 0x00,
        0x1c, 0xff, 0xc0, 0x48, 0x3f, 0xe7, 0x00,
        0x0f, 0xff, 0xf8, 0x03, 0xff, 0xff, 0x00,
        0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00,
        0x00, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif /* End BITMAP_H_ */
