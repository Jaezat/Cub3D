#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold RGB color values
typedef struct {
    int r, g, b;
} Color;

// Helper function to convert a Hex string to a Color structure
Color hex_to_color(const char *hex_str) {
    Color c = {0, 0, 0};
    
    // Skip the leading '#' if it exists
    if (hex_str[0] == '#') {
        hex_str++;
    }
    
    // Ensure we have a valid 6-character hex string length
    if (strlen(hex_str) >= 6) {
        unsigned int hex_val;
        sscanf(hex_str, "%06x", &hex_val);
        c.r = (hex_val >> 16) & 0xFF;
        c.g = (hex_val >> 8) & 0xFF;
        c.b = hex_val & 0xFF;
    }
    return c;
}

// Function to linearly interpolate between two colors
Color interpolate(Color c1, Color c2, float t) {
    Color result;
    result.r = (int)(c1.r + (c2.r - c1.r) * t);
    result.g = (int)(c1.g + (c2.g - c1.g) * t);
    result.b = (int)(c1.b + (c2.b - c1.b) * t);
    return result;
}

// Function to generate a dynamic horizontal gradient XPM file
void generate_gradient_xpm(const char *filename, const char *var_name, int width, int height, const char *hex_start, const char *hex_end) {
    // Parse the hex strings effortlessly
    Color start_color = hex_to_color(hex_start);
    Color end_color   = hex_to_color(hex_end);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    // In a horizontal gradient, the number of unique colors matches the width
    int num_colors = width; 
    
    // XPM format allows multiple characters per pixel if the palette is large.
    // 1 char per pixel supports up to 64 colors. 2 chars supports 4096 colors.
    int chars_per_pixel = (num_colors <= 64) ? 1 : 2;

    // Base character set for encoding colors safely in text format
    const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.+";

    // Write XPM Header
    fprintf(fp, "/* XPM */\n");
    fprintf(fp, "static char *%s[] = {\n", var_name);
    fprintf(fp, "/* columns rows colors chars-per-pixel */\n");
    fprintf(fp, "\"%d %d %d %d\",\n", width, height, num_colors, chars_per_pixel);

    // Write Color Palette Definition
    fprintf(fp, "/* colors */\n");
    Color *palette = (Color *)malloc(num_colors * sizeof(Color));
    
    for (int i = 0; i < num_colors; i++) {
        // Safe division handle for 1x1 edge cases
        float t = (width > 1) ? (float)i / (width - 1) : 0.0f;
        palette[i] = interpolate(start_color, end_color, t);

        fprintf(fp, "\"");
        if (chars_per_pixel == 1) {
            fprintf(fp, "%c", chars[i % 64]);
        } else {
            fprintf(fp, "%c%c", chars[(i / 64) % 64], chars[i % 64]);
        }
        fprintf(fp, " c #%02X%02X%02X\",\n", palette[i].r, palette[i].g, palette[i].b);
    }

    // Write Pixel Matrix
    fprintf(fp, "/* pixels */\n");
    for (int y = 0; y < height; y++) {
        fprintf(fp, "\"");
        for (int x = 0; x < width; x++) {
            if (chars_per_pixel == 1) {
                fprintf(fp, "%c", chars[x % 64]);
            } else {
                fprintf(fp, "%c%c", chars[(x / 64) % 64], chars[x % 64]);
            }
        }
        
        if (y == height - 1) {
            fprintf(fp, "\"\n");
        } else {
            fprintf(fp, "\",\n");
        }
    }

    fprintf(fp, "};\n");
    
    free(palette);
    fclose(fp);
    printf("Generated: %s (%dx%d) [%s -> %s]\n", filename, width, height, hex_start, hex_end);
}

#define W 512
#define H 512

int main() {
    // -------------------------------------------------------------
    // JUST PASTE YOUR CODES HERE AND SET YOUR OWN SIZES
    // Works with or without the '#' prefix!
    // -------------------------------------------------------------

    // 1. Cozy Autumn (32x16)
    generate_gradient_xpm("autumn.xpm", "autumn", W, H, "#00eeff", "FEFAE0");

    // 2. Soft Lavender (64x8)
    generate_gradient_xpm("lavender.xpm", "lavender", W, H, "#00ff9d", "#8000ff");

    // 3. Wide Slate (120x30) - Automatically handles large width color counts!
    generate_gradient_xpm("slate_wide.xpm", "slate_wide", W, H, "#ff5ecc", "#ffec3d");

    // 4. Tiny Square Badge (8x8)
    generate_gradient_xpm("badge.xpm", "badge", W, H, "2B2D42", "EF233C");

    return 0;
}
