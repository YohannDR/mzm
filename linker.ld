MEMORY {
    ewram : ORIGIN = 0x02000000 LENGTH = 256K
    iwram : ORIGIN = 0x03000000 LENGTH = 32K
    rom : ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    ewram (NOLOAD) : ALIGN(4) {}
    iwram (NOLOAD) : ALIGN(4) {}

    rom : ALIGN(2) {
        asm/romheader.o(.text);
        asm/crt0.o(.text);
        asm/blob_0x00000104-0x00800000.o(.text);
    } >rom

    /DISCARD/ : {
        *(*);
    }
}
