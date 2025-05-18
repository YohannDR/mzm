// Copyright(c) 2016 YamaArashi
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <cstdio>
#include <cstdarg>
#include <stdexcept>
#include <unordered_map>
#include <array>
#include "preproc.h"
#include "string_parser.h"
#include "char_util.h"
#include "utf8.h"

struct ShiftJisData
{
public:
    const char* text;
    std::array<unsigned char, 2> code;

    constexpr ShiftJisData(const char* t, std::array<unsigned char, 2>&& c) : text(t), code(c) {};
};

static constexpr std::array<ShiftJisData, 86> kShiftJisMap = {
    ShiftJisData("。", { 0xA1, 0x00 }),
    ShiftJisData("「", { 0xA2, 0x00 }),
    ShiftJisData("」", { 0xA3, 0x00 }),
    ShiftJisData("、", { 0xA4, 0x00 }),
    ShiftJisData("・", { 0xA5, 0x00 }),
    ShiftJisData("ヲ", { 0xA6, 0x00 }),
    ShiftJisData("ァ", { 0xA7, 0x00 }),
    ShiftJisData("ィ", { 0xA8, 0x00 }),
    ShiftJisData("ゥ", { 0xA9, 0x00 }),
    ShiftJisData("ェ", { 0xAA, 0x00 }),
    ShiftJisData("ォ", { 0xAB, 0x00 }),
    ShiftJisData("ャ", { 0xAC, 0x00 }),
    ShiftJisData("ュ", { 0xAD, 0x00 }),
    ShiftJisData("ョ", { 0xAE, 0x00 }),
    ShiftJisData("ッ", { 0xAF, 0x00 }),
    ShiftJisData("ー", { 0xB0, 0x00 }),
    ShiftJisData("ア", { 0xB1, 0x00 }),
    ShiftJisData("イ", { 0xB2, 0x00 }),
    ShiftJisData("ウ", { 0xB3, 0x00 }),
    ShiftJisData("エ", { 0xB4, 0x00 }),
    ShiftJisData("オ", { 0xB5, 0x00 }),
    ShiftJisData("カ", { 0xB6, 0x00 }),
    ShiftJisData("キ", { 0xB7, 0x00 }),
    ShiftJisData("ク", { 0xB8, 0x00 }),
    ShiftJisData("ケ", { 0xB9, 0x00 }),
    ShiftJisData("コ", { 0xBA, 0x00 }),
    ShiftJisData("サ", { 0xBB, 0x00 }),
    ShiftJisData("シ", { 0xBC, 0x00 }),
    ShiftJisData("ス", { 0xBD, 0x00 }),
    ShiftJisData("セ", { 0xBE, 0x00 }),
    ShiftJisData("ソ", { 0xBF, 0x00 }),
    ShiftJisData("タ", { 0xC0, 0x00 }),
    ShiftJisData("チ", { 0xC1, 0x00 }),
    ShiftJisData("ツ", { 0xC2, 0x00 }),
    ShiftJisData("テ", { 0xC3, 0x00 }),
    ShiftJisData("ト", { 0xC4, 0x00 }),
    ShiftJisData("ナ", { 0xC5, 0x00 }),
    ShiftJisData("ニ", { 0xC6, 0x00 }),
    ShiftJisData("ヌ", { 0xC7, 0x00 }),
    ShiftJisData("ネ", { 0xC8, 0x00 }),
    ShiftJisData("ノ", { 0xC9, 0x00 }),
    ShiftJisData("ハ", { 0xCA, 0x00 }),
    ShiftJisData("ヒ", { 0xCB, 0x00 }),
    ShiftJisData("フ", { 0xCC, 0x00 }),
    ShiftJisData("ヘ", { 0xCD, 0x00 }),
    ShiftJisData("ホ", { 0xCE, 0x00 }),
    ShiftJisData("マ", { 0xCF, 0x00 }),
    ShiftJisData("ミ", { 0xD0, 0x00 }),
    ShiftJisData("ム", { 0xD1, 0x00 }),
    ShiftJisData("メ", { 0xD2, 0x00 }),
    ShiftJisData("モ", { 0xD3, 0x00 }),
    ShiftJisData("ヤ", { 0xD4, 0x00 }),
    ShiftJisData("ユ", { 0xD5, 0x00 }),
    ShiftJisData("ヨ", { 0xD6, 0x00 }),
    ShiftJisData("ラ", { 0xD7, 0x00 }),
    ShiftJisData("リ", { 0xD8, 0x00 }),
    ShiftJisData("ル", { 0xD9, 0x00 }),
    ShiftJisData("レ", { 0xDA, 0x00 }),
    ShiftJisData("ロ", { 0xDB, 0x00 }),
    ShiftJisData("ワ", { 0xDC, 0x00 }),
    ShiftJisData("ン", { 0xDD, 0x00 }),
    // Katakana with dakuten and handakuten
    ShiftJisData("ガ", { 0xB6, 0xDE }),
    ShiftJisData("ギ", { 0xB7, 0xDE }),
    ShiftJisData("グ", { 0xB8, 0xDE }),
    ShiftJisData("ゲ", { 0xB9, 0xDE }),
    ShiftJisData("ゴ", { 0xBA, 0xDE }),
    ShiftJisData("ザ", { 0xBB, 0xDE }),
    ShiftJisData("ジ", { 0xBC, 0xDE }),
    ShiftJisData("ズ", { 0xBD, 0xDE }),
    ShiftJisData("ゼ", { 0xBE, 0xDE }),
    ShiftJisData("ゾ", { 0xBF, 0xDE }),
    ShiftJisData("ダ", { 0xC0, 0xDE }),
    ShiftJisData("ヂ", { 0xC1, 0xDE }),
    ShiftJisData("ヅ", { 0xC2, 0xDE }),
    ShiftJisData("デ", { 0xC3, 0xDE }),
    ShiftJisData("ド", { 0xC4, 0xDE }),
    ShiftJisData("バ", { 0xCA, 0xDE }),
    ShiftJisData("ビ", { 0xCB, 0xDE }),
    ShiftJisData("ブ", { 0xCC, 0xDE }),
    ShiftJisData("ベ", { 0xCD, 0xDE }),
    ShiftJisData("ボ", { 0xCE, 0xDE }),
    ShiftJisData("パ", { 0xCA, 0xDF }),
    ShiftJisData("ピ", { 0xCB, 0xDF }),
    ShiftJisData("プ", { 0xCC, 0xDF }),
    ShiftJisData("ペ", { 0xCD, 0xDF }),
    ShiftJisData("ポ", { 0xCE, 0xDF })
};

static std::array<unsigned char, 2> FindShiftJisCharacter(const int code)
{
    for (const ShiftJisData& it : kShiftJisMap)
    {
        if (DecodeUtf8(it.text).code == code)
        {
            return it.code;
        }
    }

    printf("--- Couldn't find character %x ---", code);
    return {};
}

// Reads a charmap char or escape sequence.
std::string StringParser::ReadCharOrEscape()
{
    std::string sequence;

    bool isEscape = (m_buffer[m_pos] == '\\');

    if (isEscape)
    {
        m_pos++;

        if (m_buffer[m_pos] == '"')
        {
            sequence = g_charmap->Char('"');

            if (sequence.length() == 0)
                RaiseError("no mapping exists for double quote");

            return sequence;
        }
        else if (m_buffer[m_pos] == '\\')
        {
            sequence = g_charmap->Char('\\');

            if (sequence.length() == 0)
                RaiseError("no mapping exists for backslash");

            return sequence;
        }
    }

    unsigned char c = m_buffer[m_pos];

    if (c == 0)
    {
        if (m_pos >= m_size)
            RaiseError("unexpected EOF in UTF-8 string");
        else
            RaiseError("unexpected null character in UTF-8 string");
    }

    if (IsAscii(c) && !IsAsciiPrintable(c))
        RaiseError("unexpected character U+%X in UTF-8 string", c);

    UnicodeChar unicodeChar = DecodeUtf8(&m_buffer[m_pos]);
    m_pos += unicodeChar.encodingLength;
    std::int32_t code = unicodeChar.code;

    if (code == -1)
        RaiseError("invalid encoding in UTF-8 string");

    if (isEscape && code >= 128)
        RaiseError("escapes using non-ASCII characters are invalid");

    sequence = isEscape ? g_charmap->Escape(code) : g_charmap->Char(code);

    if (sequence.length() == 0)
    {
        if (isEscape)
            RaiseError("unknown escape '\\%c'", code);
        else
            RaiseError("unknown character U+%X", code);
    }

    return sequence;
}

// Reads a charmap constant, i.e. "{FOO}".
std::string StringParser::ReadBracketedConstants()
{
    std::string totalSequence;

    m_pos++; // Assume we're on the left curly bracket.

    while (m_buffer[m_pos] != '}')
    {
        SkipWhitespace();

        if (IsIdentifierStartingChar(m_buffer[m_pos]))
        {
            long startPos = m_pos;

            m_pos++;

            while (IsIdentifierChar(m_buffer[m_pos]))
                m_pos++;

            std::string txt = std::string(&m_buffer[startPos], m_pos - startPos);
            std::string sequence = g_charmap->Constant(txt);

            if (sequence.length() == 0)
            {
                m_buffer[m_pos] = 0;
                RaiseError("unknown constant '%s'", &m_buffer[startPos]);
            }

            if (m_buffer[m_pos] == '(')
            {
                m_pos++; // (

                Integer integer = ReadInteger();

                unsigned short mask = sequence[0] << 8 | (sequence[1] & 0xFF);

                mask |= integer.value;

                sequence[0] = mask >> 8;
                sequence[1] = mask;

                m_pos++; // )
            }

            totalSequence += sequence;
        }
        else if (IsAsciiDigit(m_buffer[m_pos]))
        {
            Integer integer = ReadInteger();

            switch (integer.size)
            {
            case 1:
                totalSequence += (unsigned char)integer.value;
                break;
            case 2:
                totalSequence += (unsigned char)integer.value;
                totalSequence += (unsigned char)(integer.value >> 8);
                break;
            case 4:
                totalSequence += (unsigned char)integer.value;
                totalSequence += (unsigned char)(integer.value >> 8);
                totalSequence += (unsigned char)(integer.value >> 16);
                totalSequence += (unsigned char)(integer.value >> 24);
                break;
            }
        }
        else if (m_buffer[m_pos] == 0)
        {
            if (m_pos >= m_size)
                RaiseError("unexpected EOF after left curly bracket");
            else
                RaiseError("unexpected null character within curly brackets");
        }
        else
        {
            if (IsAsciiPrintable(m_buffer[m_pos]))
                RaiseError("unexpected character '%c' within curly brackets", m_buffer[m_pos]);
            else
                RaiseError("unexpected character '\\x%02X' within curly brackets", m_buffer[m_pos]);
        }
    }

    m_pos++; // Go past the right curly bracket.

    return totalSequence;
}

// Reads a charmap string.
int StringParser::ParseString(long srcPos, unsigned short* dest, int& destLength)
{
    m_pos = srcPos;

    if (m_buffer[m_pos] != '"')
        RaiseError("expected UTF-8 string literal");

    long start = m_pos;

    m_pos++;

    destLength = 0;

    while (m_buffer[m_pos] != '"')
    {
        std::string sequence = (m_buffer[m_pos] == '{') ? ReadBracketedConstants() : ReadCharOrEscape();

        for (size_t i = 0; i < sequence.size(); i += 2)
        {
            if (destLength == kMaxStringLength)
                RaiseError("mapped string longer than %d bytes", kMaxStringLength);

            unsigned int c;
            if (sequence[i] == 0)
                c = sequence[i + 1] & 0xFF;
            else
                c = sequence[i] << 8 | (sequence[i + 1] & 0xFF);

            dest[destLength++] = c;
        }
    }

    m_pos++; // Go past the right quote.

    return m_pos - start;
}

int StringParser::ParseShiftJis(long srcPos, unsigned short* dest, int& destLength)
{
    m_pos = srcPos;

    if (m_buffer[m_pos] != '"')
        RaiseError("expected UTF-8 string literal");

    long start = m_pos;

    m_pos++;

    destLength = 0;

    while (m_buffer[m_pos] != '"')
    {
        UnicodeChar unicodeChar = DecodeUtf8(&m_buffer[m_pos]);
        m_pos += unicodeChar.encodingLength;
        std::int32_t code = unicodeChar.code;

        if (IsAscii(code))
        {
            dest[destLength++] = code;
            continue;
        }

        const std::array<unsigned char, 2> encoded = FindShiftJisCharacter(code);
        for (const unsigned char c : encoded)
        {
            if (c == 0)
                break;

            dest[destLength++] = c;
        }
    }

    m_pos++; // Go past the right quote.

    return m_pos - start;
}

void StringParser::RaiseError(const char* format, ...)
{
    const int bufferSize = 1024;
    char buffer[bufferSize];

    std::va_list args;
    va_start(args, format);
    std::vsnprintf(buffer, bufferSize, format, args);
    va_end(args);

    throw std::runtime_error(buffer);
}

// Converts digit character to numerical value.
static int ConvertDigit(char c, int radix)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'F')
        digit = 10 + c - 'A';
    else if (c >= 'a' && c <= 'f')
        digit = 10 + c - 'a';
    else
        return -1;

    return (digit < radix) ? digit : -1;
}

void StringParser::SkipRestOfInteger(int radix)
{
    while (ConvertDigit(m_buffer[m_pos], radix) != -1)
        m_pos++;
}

StringParser::Integer StringParser::ReadDecimal()
{
    const int radix = 10;
    std::uint64_t n = 0;
    int digit;
    std::uint64_t max = UINT32_MAX;
    long startPos = m_pos;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;

        if (n >= max)
        {
            SkipRestOfInteger(radix);

            std::string intLiteral(m_buffer + startPos, m_pos - startPos);
            RaiseError("integer literal \"%s\" is too large", intLiteral.c_str());
        }

        m_pos++;
    }

    int size;

    if (m_buffer[m_pos] == 'H')
    {
        if (n >= 0x10000)
        {
            RaiseError("%lu is too large to be a halfword", (unsigned long)n);
        }

        size = 2;
        m_pos++;
    }
    else if (m_buffer[m_pos] == 'W')
    {
        size = 4;
        m_pos++;
    }
    else
    {
        if (n >= 0x10000)
            size = 4;
        else if (n >= 0x100)
            size = 2;
        else
            size = 1;
    }

    return{ static_cast<std::uint32_t>(n), size };
}

StringParser::Integer StringParser::ReadHex()
{
    const int radix = 16;
    std::uint64_t n = 0;
    int digit;
    std::uint64_t max = UINT32_MAX;
    long startPos = m_pos;

    while ((digit = ConvertDigit(m_buffer[m_pos], radix)) != -1)
    {
        n = n * radix + digit;

        if (n >= max)
        {
            SkipRestOfInteger(radix);

            std::string intLiteral(m_buffer + startPos, m_pos - startPos);
            RaiseError("integer literal \"%s\" is too large", intLiteral.c_str());
        }

        m_pos++;
    }

    int length = m_pos - startPos;
    int size = 0;

    switch (length)
    {
    case 2:
        size = 1;
        break;
    case 4:
        size = 2;
        break;
    case 8:
        size = 4;
        break;
    default:
    {
        std::string intLiteral(m_buffer + startPos, m_pos - startPos);
        RaiseError("hex integer literal \"0x%s\" doesn't have length of 2, 4, or 8 digits", intLiteral.c_str());
    }
    }

    return{ static_cast<std::uint32_t>(n), size };
}

StringParser::Integer StringParser::ReadInteger()
{
    if (!IsAsciiDigit(m_buffer[m_pos]))
    {
        // printf("\n\n\nXXXXXX\n%s\n\n\n", &m_buffer[m_pos]);
        RaiseError("expected integer");
    }

    if (m_buffer[m_pos] == '0' && m_buffer[m_pos + 1] == 'x')
    {
        m_pos += 2;
        return ReadHex();
    }

    return ReadDecimal();
}

// Skips tabs and spaces.
void StringParser::SkipWhitespace()
{
    while (m_buffer[m_pos] == '\t' || m_buffer[m_pos] == ' ')
        m_pos++;
}
