#ifndef TRANSFER_CONSTANTS_H
#define TRANSFER_CONSTANTS_H

#define CABLE_LINK_DURING_TRANSFER_ERROR_NONE                           (0)
#define CABLE_LINK_DURING_TRANSFER_ERROR_VERIFY_TIMEOUT                 (1 << 0)
#define CABLE_LINK_DURING_TRANSFER_ERROR_UNK2                           (1 << 1)
#define CABLE_LINK_DURING_TRANSFER_ERROR_INIT_TIMEOUT                   (1 << 2)
#define CABLE_LINK_DURING_TRANSFER_ERROR_INIT_TOO_MANY_CONNECTIONS      (1 << 3)

#define TRANSFER_HANDSHAKE 0x7C40

enum CableLinkSerialTransferStage {
    CABLE_LINK_SERIAL_TRANSFER_STAGE_INIT, // Clear and setup serial transfer
    CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_CONNECTION, // Initial link to pair the GBA, try to start serial transfer
    CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_DATA, // Set serial transfer to wait and load the data and size of data
    CABLE_LINK_SERIAL_TRANSFER_STAGE_TRANSFER_DATA, // Transfer the size of data, then the data
    CABLE_LINK_SERIAL_TRANSFER_STAGE_SETUP_VERIFICATION, // Setup serial transfer
    CABLE_LINK_SERIAL_TRANSFER_STAGE_VERIFY_DATA, // Transfer the data and ensure data properly transferred
    CABLE_LINK_SERIAL_TRANSFER_STAGE_TERMINATE_CONNECTION, // Serial finished
};

enum CableLinkTransferStage {
    CABLE_LINK_TRANSFER_STAGE_NO_DATA,
    CABLE_LINK_TRANSFER_STAGE_INIT_DATA,
    CABLE_LINK_TRANSFER_STAGE_SENDING_DATA
};

#endif /* TRANSFER_CONSTANTS_H */
