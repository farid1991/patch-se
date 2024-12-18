#ifndef _COLOR_H
#define _COLOR_H

#define MAX_COLOR_VAL 255
#define COLOR_GET_R(c) (((c) & 0x000000FF) >> 0)
#define COLOR_GET_G(c) (((c) & 0x0000FF00) >> 8)
#define COLOR_GET_B(c) (((c) & 0x00FF0000) >> 16)
#define COLOR_GET_A(c) (((c) & 0xFF000000) >> 24)
#define COLOR_RGBA(r, g, b, a) ((((r) & MAX_COLOR_VAL)) | (((g) & MAX_COLOR_VAL) << 8) | (((b) & MAX_COLOR_VAL) << 16) | (((a) & MAX_COLOR_VAL) << 24))

#define clEmpty 0x00000000
#define clBlack 0xFF000000
#define clRed 0xFFFF0000
#define clGreen 0xFF00FF00
#define clBlue 0xFF0000FF
#define clBlue50 0xFF000080
#define clWhite 0xFFFFFFFF
#define clWhite2 0xF0FFFFFF
#define clYellow 0xFFFFFF00
#define clHint 0xFFFFFF80
#define clHint2 0x80FFFF80
#define clTransGray 0x773F3F3F // Transparent Dark Gray

/** Grey Colors ----------------------------------------------*/

#define clAlpha 0xFF333333
#define clBeta 0xFFffffff
#define clGamma 0xFF4d4d4d
#define clDelta 0xFF5f5f5f
#define clEpsilon 0xFF858585
#define clZeta 0xFFa6a6a6
#define clEta 0xFFc7c7c7
#define clTheta 0xFFe7e7e7
#define clIota 0xFFf4f4f4

/* Primary Colors - Best for Highlighting selected UI element */

#define clPurple 0xFF873eff
#define clPink 0xFFf6529b
#define clLime 0xFF82c51b
#define clCyan 0xFF1cc1c4
#define clBlue2 0xFF0da1e1
#define clOrange 0xFFff8329
#define clRed2 0xFFf3203d

/* Mid-dark Colors - Generally used for the press effect */

#define clPurpleMidDark 0xFF6c32cc
#define clPinkMidDark 0xFFbf2392
#define clLimeMidDark 0xFF6b9a23
#define clCyanMidDark 0xFF31979e
#define clBlueMidDark 0xFF0a80b4
#define clOrangeMidDark 0xFFcc5310
#define clRedMidDark 0xFFc21930

/* Dark Colors - Generally used for the header background */

#define clPurpleDark 0xFF320374
#define clPinkDark 0xFF49122c
#define clLimeDark 0xFF143a06
#define clCyanDark 0xFF03757c
#define clBlue2Dark 0xFF21407a
#define clOrangeDark 0xFF391e0a
#define clRed2Dark 0xFF5c0600

/** Background ---------------------------------------------------*/

#define clBackground clBeta
#define clBackgroundPlus clTheta
#define clBackgroundMinus clZeta

#endif
