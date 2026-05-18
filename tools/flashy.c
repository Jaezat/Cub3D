#include <stdio.h>
#include <stdlib.h>

// Structure to hold RGB color values
typedef struct {
    int r, g, b;
} Color;

// Function to linearly interpolate between two colors
// Formula: C = C1 + (C2 - C1) * (t)  where t ranges from 0 to 1
Color interpolate(Color c1, Color c2, float t) {
    Color result;
    result.r = (int)(c1.r + (c2.r - c1.r) * t);
    result.g = (int)(c1.g + (c2.g - c1.g) * t);
    result.b = (int)(c1.b + (c2.b - c1.b) * t);
    return result;
}

// Function to generate a 16x16 horizontal gradient XPM file
void generate_horizontal_gradient_xpm(const char *filename, const char *var_name, Color start_color, Color end_color) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    int width = 16;
    int height = 16;
    int num_colors = 16; // 16 columns means 16 unique colors for a perfect horizontal gradient
    int chars_per_pixel = 1;

    // Characters used to represent the 16 different colors in the XPM pixel matrix
    char color_chars[] = "abcdefghijklmnop";

    // Write XPM Header
    fprintf(fp, "/* XPM */\n");
    fprintf(fp, "static char *%s[] = {\n", var_name);
    fprintf(fp, "/* columns rows colors chars-per-pixel */\n");
    fprintf(fp, "\"%d %d %d %d\",\n", width, height, num_colors, chars_per_pixel);

    // Write Color Palette Definition
    fprintf(fp, "/* colors */\n");
    Color palette[16];
    for (int i = 0; i < 16; i++) {
        float t = (float)i / (width - 1);
        palette[i] = interpolate(start_color, end_color, t);
        fprintf(fp, "\"%c c #%02X%02X%02X\",\n", color_chars[i], palette[i].r, palette[i].g, palette[i].b);
    }

    // Write Pixel Matrix
    fprintf(fp, "/* pixels */\n");
    for (int y = 0; y < height; y++) {
        fprintf(fp, "\"");
        for (int x = 0; x < width; x++) {
            // Because it's a horizontal gradient, the character depends only on 'x'
            fprintf(fp, "%c", color_chars[x]);
        }
        // Format the trailing comma and newline correctly for C syntax inside XPM
        if (y == height - 1) {
            fprintf(fp, "\"\n");
        } else {
            fprintf(fp, "\",\n");
        }
    }

    fprintf(fp, "};\n");
    fclose(fp);
    printf("Successfully generated: %s\n", filename);
}

int main() {
    // Define 4 different color combinations (Start -> End)
    
    // 1. Sunset Fire: Red to Yellow
    Color fire_start = {255, 0, 0};
    Color fire_end   = {255, 255, 0};
    generate_horizontal_gradient_xpm("gradient_sunset.xpm", "gradient_sunset", fire_start, fire_end);

    // 2. Ocean Breeze: Deep Blue to Cyan
    Color ocean_start = {0, 0, 128};
    Color ocean_end   = {0, 255, 255};
    generate_horizontal_gradient_xpm("gradient_ocean.xpm", "gradient_ocean", ocean_start, ocean_end);

    // 3. Cyberpunk: Magenta to Teal
    Color cyber_start = {255, 0, 128};
    Color cyber_end   = {0, 255, 128};
    generate_horizontal_gradient_xpm("gradient_cyber.xpm", "gradient_cyber", cyber_start, cyber_end);

    // 4. Forest Mist: Dark Green to Light Mint
    Color forest_start = {10, 50, 10};
    Color forest_end   = {150, 230, 150};
    generate_horizontal_gradient_xpm("gradient_forest.xpm", "gradient_forest", forest_start, forest_end);

    return 0;
}
