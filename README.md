*This project has been created as part of the 42 curriculum by leschunc and mariacos.*

# Cub3D

**A raycasting engine built from scratch in C, inspired by Wolfenstein 3D.**

## Description

cub3D is a graphics project inspired by Wolfenstein 3D, one of the earliest first-person shooters and a pioneer of the raycasting technique for simulating 3D worlds without fully rendering 3D geometry.

Written in C, this project uses the MiniLibX library to render a first-person 3D maze from a 2D map. Along the way, it required:

* Implementing the raycasting algorithm from scratch
* Pixel-level image manipulation
* Window and event management via MiniLibX
* A full map/config file parser

### 3D Perspective via Raycasting

Raycasting creates a 3D illusion from a 2D map. A ray is cast from the player's position outward until it hits a wall. The distance between the player and that wall determines how tall the wall is drawn on screen:

* Close wall: tall on screen
* Far wall: short on screen

This is repeated once per vertical screen column, across the player's field of view, to build the full 3D scene.

### DDA (Digital Differential Analysis)

To efficiently find where a ray hits a wall, we use the DDA algorithm:

1. The map is treated as a grid.
2. The ray will always cross either a vertical or horizontal grid line first.
3. We calculate the distance to the next vertical line and the next horizontal line.
4. We keep stepping to whichever is closer, grid-line by grid-line, until we land on a cell marked as a wall.

### Texture Mapping and Scaling

Once we know the distance to the wall, we determine which texture to use (`NORTH`, `SOUTH`, `EAST`, or `WEST`) based on which side of the wall the ray struck.

Since textures have a fixed size (ex: 64px tall) but on-screen wall height changes with distance, the texture must be stretched or compressed to fit the wall slice being drawn.

## Instructions

### Build and Run

```bash
make
./cub3D assets/maps/flood.cub
```

### Handy Shortcuts

| Command | What it does |
|---|---|
| `make go` | Builds the project, then immediately runs it with a preset test map. |

### Cleanup and Rebuild

| Command | What it does |
|---|---|
| `make clean` | Removes build artifacts (object files, etc.) and keeps source code and the compiled binary. |
| `make fclean` | `clean` removes the compiled binary too, back to just source code. |
| `make re` | Full clean, then rebuilds everything from scratch. |

## Resources

* [Make your own Raycaster: 3DSage](https://youtu.be/gYRrGTC7GtA?si=KOLlLrP2S78ExnCX)
* [Raycasting Fully Explained (Playlist): WeirdDevers](https://www.youtube.com/watch?v=g8p7nAbDz6Y)
* [How Ray Tracing Works: Computerphile](https://www.youtube.com/watch?v=ezXGTRSx1g8)
* [Setting up a 3D Minimap: Mina Pêcheux](https://www.youtube.com/watch?v=LXzQXoheXAA&t=434s)
* [How to Create a Minimap: Wawa Sensei](https://www.youtube.com/watch?v=d3cMODi1CtU&t=688s)
* [Raycasting Tutorial: Permadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
* [Wolfenstein 3D Raycasting in C: Tim Wheeler](https://timallanwheeler.com/blog/2023/04/01/wolfenstein-3d-raycasting-in-c/)
* [Raycasting: Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
* [Why Radians?: Ask a Mathematician](https://www.askamathematician.com/2014/10/q-why-radians/)

### Use of AI

AI tools were used to support the project in the following ways:

* Researching and understanding mathematical and technical concepts.
* Debugging assistance.