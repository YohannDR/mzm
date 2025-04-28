#ifndef TRANSFER_CONSTANTS_H
#define TRANSFER_CONSTANTS_H

#define TRANSFER_ERROR_SHIFT 4
#define TRANSFER_ERROR_NONE                           (0)
#define TRANSFER_ERROR_VERIFY_TIMEOUT                 (1 << 0)
#define TRANSFER_ERROR_UNK2                           (1 << 1)
#define TRANSFER_ERROR_INIT_TIMEOUT                   (1 << 2)
#define TRANSFER_ERROR_INIT_TOO_MANY_CONNECTIONS      (1 << 3)

#define TRANSFER_VERIFY_SHIFT   2
#define TRANSFER_VERIFY_SUCCESS (1 << 0)
#define TRANSFER_VERIFY_FAILURE (1 << 1)
#define TRANSFER_VERIFY_MASK    ((TRANSFER_VERIFY_FAILURE | TRANSFER_VERIFY_SUCCESS) << TRANSFER_VERIFY_SHIFT)

#define TRANSFER_HANDSHAKE 0x7C40

#define TRANSFER_DATA_STAGE_SHIFT   0
#define TRANSFER_DATA_STAGE_NONE    (0 << 0)
#define TRANSFER_DATA_STAGE_INIT    (1 << 0)
#define TRANSFER_DATA_STAGE_SENDING (1 << 1)
#define TRANSFER_DATA_STAGE_MASK    ((TRANSFER_DATA_STAGE_SENDING | TRANSFER_DATA_STAGE_INIT) << TRANSFER_DATA_STAGE_SHIFT)

enum TransferStage {
    TRANSFER_STAGE_INIT, // Clear and setup serial transfer
    TRANSFER_STAGE_SETUP_CONNECTION, // Initial link to pair the GBA, try to start serial transfer
    TRANSFER_STAGE_SETUP_DATA, // Set serial transfer to wait and load the data and size of data
    TRANSFER_STAGE_TRANSFER_DATA, // Transfer the size of data, then the data
    TRANSFER_STAGE_SETUP_VERIFICATION, // Setup serial transfer
    TRANSFER_STAGE_VERIFY_DATA, // Transfer the data and ensure data properly transferred
    TRANSFER_STAGE_TERMINATE_CONNECTION, // Serial finished
};

#endif /* TRANSFER_CONSTANTS_H */
