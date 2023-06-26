#include "data/internal_ending_and_gallery_data.h"
#include "ending_and_gallery.h"

const CreditsFunc_T sCreditsFunctionPointers[3] = {
    [0] = CreditsDisplay,
    [1] = CreditsChozoWallMovement,
    [2] = CreditsChozoWallZoom
};

const CreditsFunc_T sEndScreenFunctionPointers[1] = {
    [0] = EndScreenSamusPosing
};

const CreditsFunc_T sEndingImageFunctionPointers[1] = {
    [0] = EndingImageDisplay
};

const CreditsFunc_T sUnlockedOptionsFunctionPointers[2] = {
    [0] = UnlockedOptionsPopUp,
    [1] = UnlockedOptionsPopUp
};

