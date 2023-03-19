#ifndef COLORS_H
#define COLORS_H

/* Text Colors */
#define F_T_BLK "\x1B[30m"  // Black
#define F_T_RED "\x1B[31m"  // Red
#define F_T_GRN "\x1B[32m"  // Green
#define F_T_YEL "\x1B[33m"  // Yellow
#define F_T_BLU "\x1B[34m"  // Blue
#define F_T_MAG "\x1B[35m"  // Magenta
#define F_T_CYN "\x1B[36m"  // Cyan
#define F_T_WHT "\x1B[37m"  // White
#define F_T_ORG "\x1B[38;5;202m" // Orange
#define F_T_PNK "\x1B[38;5;206m" // Pink
#define F_T_PRP "\x1B[38;5;141m" // Purple
#define F_T_SKY "\x1B[38;5;45m" // Sky blue
#define F_T_YLW "\x1B[38;5;226m" // Yellow
#define F_T_GRY "\x1B[38;5;246m" // Grey
#define F_T_BRN "\x1B[38;5;52m" // Brown
#define F_T_GRD "\x1B[38;5;28m" // Greenish
#define F_T_AQU "\x1B[38;5;14m" // Aquamarine

/* Background Colors */
#define F_B_BLK "\x1B[40m"  // Background Black
#define F_B_RED "\x1B[41m"  // Background Red
#define F_B_GRN "\x1B[42m"  // Background Green
#define F_B_YEL "\x1B[43m"  // Background Yellow
#define F_B_LUB "\x1B[44m"  // Background Blue
#define F_B_MAG "\x1B[45m"  // Background Magenta
#define F_B_CYN "\x1B[46m"  // Background Cyan
#define F_B_WHT "\x1B[47m"  // Background White

/* Text Modifiers */
#define F_RESET "\x1B[0m"  // Reset to default color
#define F_DIM "\x1B[2m"    // Dim text
#define F_BOLD "\x1B[1m"   // Bold text
#define F_UNDL "\x1B[4m"   // Underline text
#define F_BLNK "\x1B[5m"   // Blink text
#define F_RVID "\x1B[7m"   // Reverse color text
#define F_HIDN "\x1B[8m"   // Hidden text

#endif /* COLORS_H */