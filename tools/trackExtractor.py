import argparse
from enum import Enum
from io import BufferedReader
import os


INDENT = "\t"
BYTE = ".byte"
WORD = ".word"
ALIGN_2 = ".align 2"

NUM_SOUNDS = 708
SOUNDS_ADDR = {
    "us": 0x8F2C0,
    "us_beta": 0x94B50
}
TRACK_0_ADDR = {
    "us": 0x908E0,
    "us_beta": 0x96170
}

VOICE_GROUPS = {
    "us": [
        0x8CF70,
        0x8D444,
        0x8D720,
        0x8D8F4,
        0x8DBAC,
        0x8DDEC,
        0x8DF24,
        0x8DFC0,
        0x8E038,
        0x8E098,
        0x8E164,
        0x8E26C,
        0x8E320,
        0x8E3A4,
        0x8E4AC,
        0x8E59C,
        0x8E5D8,
        0x8E698,
        0x8E77C,
        0x8E920,
        0x8EAE8,
        0x8F004,
        0x8F070
    ],
    "us_beta": [
        0x92800,
        0x92CD4,
        0x92FB0,
        0x93184,
        0x9343C,
        0x9367C,
        0x937B4,
        0x93850,
        0x938C8,
        0x93928,
        0x939F4,
        0x93AFC,
        0x93BB0,
        0x93C34,
        0x93D3C,
        0x93E2C,
        0x93E68,
        0x93F28,
        0x9400C,
        0x941B0,
        0x94378,
        0x94894,
        0x94900
    ]
}

ROM_OFFSET = 0x8000000

NOTE_KEY = [
    "CnM2", # 0x00
    "CsM2", # 0x01
    "DnM2", # 0x02
    "DsM2", # 0x03
    "EnM2", # 0x04
    "FnM2", # 0x05
    "FsM2", # 0x06
    "GnM2", # 0x07
    "GsM2", # 0x08
    "AnM2", # 0x09
    "AsM2", # 0x0A
    "BnM2", # 0x0B
    "CnM1", # 0x0C
    "CsM1", # 0x0D
    "DnM1", # 0x0E
    "DsM1", # 0x0F
    "EnM1", # 0x10
    "FnM1", # 0x11
    "FsM1", # 0x12
    "GnM1", # 0x13
    "GsM1", # 0x14
    "AnM1", # 0x15
    "AsM1", # 0x16
    "BnM1", # 0x17
    "Cn0",  # 0x18
    "Cs0",  # 0x19
    "Dn0",  # 0x1A
    "Ds0",  # 0x1B
    "En0",  # 0x1C
    "Fn0",  # 0x1D
    "Fs0",  # 0x1E
    "Gn0",  # 0x1F
    "Gs0",  # 0x20
    "An0",  # 0x21
    "As0",  # 0x22
    "Bn0",  # 0x23
    "Cn1",  # 0x24
    "Cs1",  # 0x25
    "Dn1",  # 0x26
    "Ds1",  # 0x27
    "En1",  # 0x28
    "Fn1",  # 0x29
    "Fs1",  # 0x2A
    "Gn1",  # 0x2B
    "Gs1",  # 0x2C
    "An1",  # 0x2D
    "As1",  # 0x2E
    "Bn1",  # 0x2F
    "Cn2",  # 0x30
    "Cs2",  # 0x31
    "Dn2",  # 0x32
    "Ds2",  # 0x33
    "En2",  # 0x34
    "Fn2",  # 0x35
    "Fs2",  # 0x36
    "Gn2",  # 0x37
    "Gs2",  # 0x38
    "An2",  # 0x39
    "As2",  # 0x3A
    "Bn2",  # 0x3B
    "Cn3",  # 0x3C
    "Cs3",  # 0x3D
    "Dn3",  # 0x3E
    "Ds3",  # 0x3F
    "En3",  # 0x40
    "Fn3",  # 0x41
    "Fs3",  # 0x42
    "Gn3",  # 0x43
    "Gs3",  # 0x44
    "An3",  # 0x45
    "As3",  # 0x46
    "Bn3",  # 0x47
    "Cn4",  # 0x48
    "Cs4",  # 0x49
    "Dn4",  # 0x4A
    "Ds4",  # 0x4B
    "En4",  # 0x4C
    "Fn4",  # 0x4D
    "Fs4",  # 0x4E
    "Gn4",  # 0x4F
    "Gs4",  # 0x50
    "An4",  # 0x51
    "As4",  # 0x52
    "Bn4",  # 0x53
    "Cn5",  # 0x54
    "Cs5",  # 0x55
    "Dn5",  # 0x56
    "Ds5",  # 0x57
    "En5",  # 0x58
    "Fn5",  # 0x59
    "Fs5",  # 0x5A
    "Gn5",  # 0x5B
    "Gs5",  # 0x5C
    "An5",  # 0x5D
    "As5",  # 0x5E
    "Bn5",  # 0x5F
    "Cn6",  # 0x60
    "Cs6",  # 0x61
    "Dn6",  # 0x62
    "Ds6",  # 0x63
    "En6",  # 0x64
    "Fn6",  # 0x65
    "Fs6",  # 0x66
    "Gn6",  # 0x67
    "Gs6",  # 0x68
    "An6",  # 0x69
    "As6",  # 0x6A
    "Bn6",  # 0x6B
    "Cn7",  # 0x6C
    "Cs7",  # 0x6D
    "Dn7",  # 0x6E
    "Ds7",  # 0x6F
    "En7",  # 0x70
    "Fn7",  # 0x71
    "Fs7",  # 0x72
    "Gn7",  # 0x73
    "Gs7",  # 0x74
    "An7",  # 0x75
    "As7",  # 0x76
    "Bn7",  # 0x77
    "Cn8",  # 0x78
    "Cs8",  # 0x79
    "Dn8",  # 0x7A
    "Ds8",  # 0x7B
    "En8",  # 0x7C
    "Fn8",  # 0x7D
    "Fs8",  # 0x7E
    "Gn8"   # 0x7F
]

CMD_FIRST = 0x80

WAIT_FIRST = 0x80
WAIT_LAST = 0xB0

WAIT_CMD = [
    "W00",  # 0x80
    "W01",  # 0x81
    "W02",  # 0x82
    "W03",  # 0x83
    "W04",  # 0x84
    "W05",  # 0x85
    "W06",  # 0x86
    "W07",  # 0x87
    "W08",  # 0x88
    "W09",  # 0x89
    "W10",  # 0x8A
    "W11",  # 0x8B
    "W12",  # 0x8C
    "W13",  # 0x8D
    "W14",  # 0x8E
    "W15",  # 0x8F
    "W16",  # 0x90
    "W17",  # 0x91
    "W18",  # 0x92
    "W19",  # 0x93
    "W20",  # 0x94
    "W21",  # 0x95
    "W22",  # 0x96
    "W23",  # 0x97
    "W24",  # 0x98
    "W28",  # 0x99
    "W30",  # 0x9A
    "W32",  # 0x9B
    "W36",  # 0x9C
    "W40",  # 0x9D
    "W42",  # 0x9E
    "W44",  # 0x9F
    "W48",  # 0xA0
    "W52",  # 0xA1
    "W54",  # 0xA2
    "W56",  # 0xA3
    "W60",  # 0xA4
    "W64",  # 0xA5
    "W66",  # 0xA6
    "W68",  # 0xA7
    "W72",  # 0xA8
    "W76",  # 0xA9
    "W78",  # 0xAA
    "W80",  # 0xAB
    "W84",  # 0xAC
    "W88",  # 0xAD
    "W90",  # 0xAE
    "W92",  # 0xAF
    "W96"   # 0xB0
]

NOTE_LEN_FIRST = 0xD0
NOTE_LEN_LAST = 0xFF

NOTE_LEN = [
    "N01",  # 0xD0
    "N02",  # 0xD1
    "N03",  # 0xD2
    "N04",  # 0xD3
    "N05",  # 0xD4
    "N06",  # 0xD5
    "N07",  # 0xD6
    "N08",  # 0xD7
    "N09",  # 0xD8
    "N10",  # 0xD9
    "N11",  # 0xDA
    "N12",  # 0xDB
    "N13",  # 0xDC
    "N14",  # 0xDD
    "N15",  # 0xDE
    "N16",  # 0xDF
    "N17",  # 0xE0
    "N18",  # 0xE1
    "N19",  # 0xE2
    "N20",  # 0xE3
    "N21",  # 0xE4
    "N22",  # 0xE5
    "N23",  # 0xE6
    "N24",  # 0xE7
    "N28",  # 0xE8
    "N30",  # 0xE9
    "N32",  # 0xEA
    "N36",  # 0xEB
    "N40",  # 0xEC
    "N42",  # 0xED
    "N44",  # 0xEE
    "N48",  # 0xEF
    "N52",  # 0xF0
    "N54",  # 0xF1
    "N56",  # 0xF2
    "N60",  # 0xF3
    "N64",  # 0xF4
    "N66",  # 0xF5
    "N68",  # 0xF6
    "N72",  # 0xF7
    "N76",  # 0xF8
    "N78",  # 0xF9
    "N80",  # 0xFA
    "N84",  # 0xFB
    "N88",  # 0xFC
    "N90",  # 0xFD
    "N92",  # 0xFE
    "N96"   # 0xFF
]

class ParamType(Enum):
    NONE = 0    # None
    NOTE = 1    # Note, can take key, velocity, and extra length
    TIE = 2     # Tie, can take key and velocity
    BYTE = 3    # Unsigned (0 to 127)
    C_V = 4     # Signed with center value 0x40 (-64 to 63)
    PTR = 5     # Pointer, used for jumps
    MEM = 6     # ?
    MODT = 7    # ?
    XCMD = 8    # ?

CODE_CMD_FIRST = 0xB1
CODE_CMD_LAST = 0xCF

CODE_CMD = [
    # Name, ParamType, Repeatable
    ("FINE",   ParamType.NONE, False),  # 0xB1
    ("GOTO",   ParamType.PTR,  False),  # 0xB2
    ("PATT",   ParamType.PTR,  False),  # 0xB3
    ("PEND",   ParamType.NONE, False),  # 0xB4
    ("REPT",   ParamType.PTR,  False),  # 0xB5
    ("0xB6",   ParamType.NONE, False),  # 0xB6
    ("0xB7",   ParamType.NONE, False),  # 0xB7
    ("0xB8",   ParamType.NONE, False),  # 0xB8
    ("MEMACC", ParamType.MEM,  False),  # 0xB9
    ("PRIO",   ParamType.BYTE, False),  # 0xBA
    ("TEMPO",  ParamType.BYTE, False),  # 0xBB
    ("KEYSH",  ParamType.BYTE, False),  # 0xBC
    ("VOICE",  ParamType.BYTE, False),  # 0xBD
    ("VOL",    ParamType.BYTE, True),   # 0xBE
    ("PAN",    ParamType.C_V,  True),   # 0xBF
    ("BEND",   ParamType.C_V,  True),   # 0xC0
    ("BENDR",  ParamType.BYTE, True),   # 0xC1
    ("LFOS",   ParamType.BYTE, False),  # 0xC2
    ("LFODL",  ParamType.BYTE, False),  # 0xC3
    ("MOD",    ParamType.BYTE, True),   # 0xC4
    ("MODT",   ParamType.MODT, False),  # 0xC5
    ("0xC6",   ParamType.NONE, False),  # 0xC6
    ("0xC7",   ParamType.NONE, False),  # 0xC7
    ("TUNE",   ParamType.C_V,  False),  # 0xC8
    ("0xC9",   ParamType.NONE, False),  # 0xC9
    ("0xCA",   ParamType.NONE, False),  # 0xCA
    ("0xCB",   ParamType.NONE, False),  # 0xCB
    ("0xCC",   ParamType.NONE, False),  # 0xCC
    ("XCMD",   ParamType.XCMD, False),  # 0xCD
    ("EOT",    ParamType.TIE,  True),   # 0xCE
    ("TIE",    ParamType.TIE,  True)    # 0xCF
]

REPEATABLE = {"VOL", "PAN", "BEND"}

CENTER_VALUE = 0x40

MEM_PARAM = [
    "mem_set",
    "mem_add",
    "mem_sub",
    "mem_mem_set",
    "mem_mem_add",
    "mem_mem_sub",
    "mem_beq",
    "mem_bne",
    "mem_bhi",
    "mem_bhs",
    "mem_bls",
    "mem_blo",
    "mem_mem_beq",
    "mem_mem_bne",
    "mem_mem_bhi",
    "mem_mem_bhs",
    "mem_mem_bls",
    "mem_mem_blo"
]

MODT_PARAM = [
    "mod_vib",
    "mod_tre",
    "mod_pan"
]


class TrackExtractor:

    def __init__(self, rom: BufferedReader):
        self.rom = rom
        self.prev_repeatable_cmd: int = None
        self.prev_key: int = None
        self.prev_vel: int = None
        self.cmd_addr: int = None
        self.jumps: set[int] = None
        self.label: str = None
        self.cmd_text: list[tuple[str, int]] = None

    def _parse_command(self, value: int, repeated: bool) -> None:
        if WAIT_FIRST <= value <= WAIT_LAST:
            # Wait command
            assert not repeated
            wait = WAIT_CMD[value - WAIT_FIRST]
            self._add_cmd_text(f"{INDENT}{BYTE} {wait}")
        elif CODE_CMD_FIRST <= value <= CODE_CMD_LAST:
            # Code command
            cmd, param_type, repeatable = CODE_CMD[value - CODE_CMD_FIRST]
            if repeatable:
                self.prev_repeatable_cmd = value
            params = self._get_command_params(param_type, cmd, repeated)
            self._add_cmd_text(f"{INDENT}{BYTE} {params}")
        elif value >= NOTE_LEN_FIRST:
            # Note command
            self.prev_repeatable_cmd = value
            note = NOTE_LEN[value - NOTE_LEN_FIRST]
            params = self._get_command_params(ParamType.NOTE, note, repeated)
            self._add_cmd_text(f"{INDENT}{BYTE} {params}")
        else:
            raise ValueError("Expected command value")

    def _get_command_params(self, type: ParamType, cmd: str, repeated: bool) -> str:
        params = []
        comment = []
        if repeated:
            comment.append(cmd)
        else:
            params.append(cmd)
        if type == ParamType.NONE:
            pass
        elif type == ParamType.NOTE or type == ParamType.TIE:
             # First param is note key
            value = read_8(self.rom)
            if value < CMD_FIRST:
                params.append(NOTE_KEY[value])
                self.prev_key = value
                # Second param is velocity
                value = read_8(self.rom)
                if value < CMD_FIRST:
                    params.append(f"v{value:03}")
                    self.prev_vel = value
                    # Third param is extra length
                    if type == ParamType.NOTE:
                        value = read_8(self.rom)
                        if value < CMD_FIRST:
                            params.append(f"{value}")
                        else:
                            self.rom.seek(self.rom.tell() - 1)
                else:
                    if self.prev_vel is None:
                        raise ValueError("No previous note velocity")
                    comment.append(f"v{self.prev_vel:03}")
                    self.rom.seek(self.rom.tell() - 1)
            else:
                if self.prev_key is None:
                    raise ValueError("No previous note key")
                if self.prev_vel is None:
                    raise ValueError("No previous note velocity")
                comment.append(NOTE_KEY[self.prev_key])
                comment.append(f"v{self.prev_vel:03}")
                self.rom.seek(self.rom.tell() - 1)
        elif type == ParamType.BYTE:
            value = read_8(self.rom)
            params.append(f"{value}")
        elif type == ParamType.C_V:
            value = read_8(self.rom)
            c_v = "c_v"
            if value > CENTER_VALUE:
                c_v += "+" + str(value - CENTER_VALUE)
            elif value < CENTER_VALUE:
                c_v += "-" + str(CENTER_VALUE - value)
            params.append(c_v)
        elif type == ParamType.PTR:
            ptr = read_ptr(self.rom)
            self.jumps.add(ptr)
            return f"{cmd}\n{INDENT*2}{WORD} {self.label}{ptr:x}"
        elif type == ParamType.MEM:
            value = read_8(self.rom)
            params.append(MEM_PARAM[value])
        elif type == ParamType.MODT:
            value = read_8(self.rom)
            params.append(MODT_PARAM[value])
        elif type == ParamType.XCMD:
            value = read_8(self.rom)
            if value == 8:
                params.append("xIECV")
            elif value == 9:
                params.append("xIECL")
        if repeated:
            assert len(params) > 0
        result = ", ".join(params)
        if comment:
            result += " @ " + ", ".join(comment)
        return result

    def _add_cmd_text(self, text: str) -> None:
        self.cmd_text.append((text, self.cmd_addr))

    def extract_track(self, addr: int, sound_id: int) -> str:
        self.prev_repeatable_cmd = None
        self.prev_key = None
        self.prev_vel = None
        self.cmd_addr = addr
        self.jumps = set()
        self.label = f"track_{sound_id}_lbl_"
        self.cmd_text = []
        self.rom.seek(addr)
        value = read_8(self.rom)

        while value != 0xB1 and value != 0xB6:
            if value >= CMD_FIRST:
                self._parse_command(value, False)
            else:
                # Repeat previous command
                if self.prev_repeatable_cmd is None:
                    raise ValueError("No previous command to repeat")
                self.rom.seek(self.rom.tell() - 1)
                self._parse_command(self.prev_repeatable_cmd, True)
            self.cmd_addr = self.rom.tell()
            value = read_8(self.rom)

        end = "FINE" if value == 0xB1 else "0xB6"
        self._add_cmd_text(f"{INDENT}{BYTE} {end}")

        # Add labels
        lines = []
        for text, cmd_addr in self.cmd_text:
            if cmd_addr in self.jumps:
                lines.append(f"{self.label}{cmd_addr:x}:")
                self.jumps.remove(cmd_addr)
            lines.append(text)
        if len(self.jumps) > 0:
            raise ValueError("Invalid jump address")

        return "\n".join(lines)


def read_8(rom: BufferedReader) -> int:
    return rom.read(1)[0]


def read_ptr(rom: BufferedReader) -> int:
    values = rom.read(4)
    word = values[0] | (values[1] << 8) | (values[2] << 16) | (values[3] << 24)
    if word < ROM_OFFSET:
        raise ValueError(f"Invalid pointer {word:X} at {rom.tell()-4:X}")
    return word - ROM_OFFSET


def extract_sound(
    extractor: TrackExtractor,
    rom: BufferedReader,
    region: str,
    output_path: str,
    addr: int,
    sound_id: int
) -> None:
    name = f"track_{sound_id}"
    output_path = os.path.join(output_path, name + ".s")
    with open(output_path, "w") as f:
        f.write(f"{ALIGN_2}\n\n.global {name}\n\n")

        rom.seek(addr)
        num_tracks = read_8(rom)
        unk_1 = read_8(rom)
        prio = read_8(rom)
        echo = read_8(rom)
        voice = read_ptr(rom)
        for t in range(num_tracks):
            track_addr = read_ptr(rom)
            next_addr = rom.tell()
            f.write(f"{name}_{t}:\n")
            f.write(extractor.extract_track(track_addr, sound_id))
            f.write("\n\n")
            rom.seek(next_addr)
        
        f.write(f"{ALIGN_2}\n\n")
        f.write(f"{name}:\n")
        f.write(f"{INDENT}{BYTE} {num_tracks}\n")
        f.write(f"{INDENT}{BYTE} {unk_1}\n")
        f.write(f"{INDENT}{BYTE} {prio}\n")
        f.write(f"{INDENT}{BYTE} {echo}\n")

        try:
            vg = VOICE_GROUPS[region].index(voice)
        except:
            raise ValueError(f"No voice group at {voice:X} (sound {sound_id})")
        f.write(f"{INDENT}{WORD} voice_group{vg}\n")

        for t in range(num_tracks):
            f.write(f"{INDENT}{WORD} {name}_{t}\n")
        
        f.write(f"\n{ALIGN_2}\n")


def extract_all_sounds(rom: BufferedReader, region: str, output_path: str) -> None:
    if not os.path.exists(output_path):
        os.makedirs(output_path, exist_ok=True)

    rom.seek(SOUNDS_ADDR[region])
    track_0_addr = TRACK_0_ADDR[region]
    extractor = TrackExtractor(rom)
    for i in range(NUM_SOUNDS):
        addr = read_ptr(rom)
        next_addr = rom.tell() + 4
        if addr != track_0_addr:
            extract_sound(extractor, rom, region, output_path, addr, i)
        rom.seek(next_addr)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("rom_path", type=str)
    parser.add_argument("output_path", type=str)

    args = parser.parse_args()
    rom = open(args.rom_path, "rb")
    # Detect region from rom
    rom.seek(0xAC)
    code = rom.read(4).decode("ascii")
    if code == "BMXE":
        rom.seek(0x238)
        if read_8(rom) == 0x2C:
            region = "us_beta"
        else:
            region = "us"
    else:
        raise ValueError("Unsupported region")

    extract_all_sounds(rom, region, args.output_path)
