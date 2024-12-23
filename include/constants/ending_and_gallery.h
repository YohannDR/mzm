#ifndef ENDING_AND_GALLERY_CONSTANTS_H
#define ENDING_AND_GALLERY_CONSTANTS_H

#define ENDING_FLAG_NEW_TIME_ATTACK_RECORD 0x1
#define ENDING_FLAG_UNKNOWN 0x10
#define ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR 0x20
#define ENDING_FLAG_FIRST_HARD_MODE_CLEAR 0x40
#define ENDING_FLAG_FIRST_CLEAR 0x80

#define ENDING_IMAGE_OAM_SET_CLEAR_TIME 0
#define ENDING_IMAGE_OAM_SET_YOUR_RATE 1
#define ENDING_IMAGE_OAM_SET_COLLECTING 2

enum EndingImageLine {
    ENDING_IMAGE_LINE_CLEAR_TIME,
    ENDING_IMAGE_LINE_TIMER,
    ENDING_IMAGE_LINE_YOUR_RATE,
    ENDING_IMAGE_LINE_COLLECTING,
    ENDING_IMAGE_LINE_PERCENTAGE,
    ENDING_IMAGE_LINE_NEXT_MISSION,

    ENDING_IMAGE_LINE_END
};

#define CREDIT_LINE_TYPE_BLUE 0
#define CREDIT_LINE_TYPE_RED 1
#define CREDIT_LINE_TYPE_WHITE_BIG 2
#define CREDIT_LINE_TYPE_WHITE_SMALL 3
#define CREDIT_LINE_TYPE_UNK_5 5
#define CREDIT_LINE_TYPE_END 6
#define CREDIT_LINE_TYPE_ALL_RIGHTS 10
#define CREDIT_LINE_TYPE_THE_COPYRIGHT 11
#define CREDIT_LINE_TYPE_SCENARIO 12
#define CREDIT_LINE_TYPE_RESERVED 13

enum EndingImage {
    ENDING_IMAGE_ZERO,   // Always Easy, or Normal or Hard, Any%, >= 4 hours, Samus in her Gravity Suit sitting atop a rock
    ENDING_IMAGE_ONE,    // Normal or Hard, Any%, 2 < hours <= 4, Samus in her Gravity Suit with her helmet off looking into the distance
    ENDING_IMAGE_TWO,    // Normal or Hard, Any%, < 2 hours, Samus in her Zero Suit looking behind her
    ENDING_IMAGE_THREE,  // Normal or Hard, 100%, >= 2 hours, Samus in her orange two-piece, looking to the side
    ENDING_IMAGE_FOUR,   // Normal, 100%, < 2 hours, Samus in her orange two-piece, at a bar
    ENDING_IMAGE_FIVE,   // Hard, 100%, < 2 hours, Samus in her orange two-piece, looking away from the city
    ENDING_IMAGE_SIX,    // Normal, Low%, Samus in her orange two-piece, partially sitting on a window sill
    ENDING_IMAGE_SEVEN,  // Hard, Low%, Samus in her Gravity Suit and orange two-piece, ready for battle

    ENGING_IMAGE_COUNT
};

#define ENDING_OAM_TYPE_NONE 0
#define ENDING_OAM_TYPE_CHAR 1
#define ENDING_OAM_TYPE_LINE 2

#endif
