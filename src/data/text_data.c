#include "data/text_data.h"

const u8 sCharacterWidths[1184] = {
    0
};

const struct Message sMessage_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = TRUE,
    .messageEnded = FALSE
};

const struct Message sMessageStoryText_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const struct Message sMessageFileScreen_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const struct Message sMessageDescription_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 2,
    .delay = 20,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};
