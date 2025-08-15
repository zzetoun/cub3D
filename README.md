# cub3D — My First RayCaster with MiniLibX

## Overview
cub3D is a ray-casting project inspired by Wolfenstein 3D. The goal is to render a realistic 3D view of a maze from a first-person perspective using MiniLibX.

Developed as part of the 42 Abu Dhabi curriculum, this project blends low-level C programming, computer graphics, and basic game mechanics.

## Features
- First-person navigation through a 2D map rendered as 3D using ray casting.
- Smooth window handling (focus changes, minimizing, etc.).
- Directional wall textures: different textures for North, South, East, and West faces.
- Configurable floor and ceiling colors.
- Keyboard controls:
  - W / A / S / D: move forward, left, backward, right.
  - Left / Right arrows: rotate view.
  - ESC or window close button: exit cleanly.
- Configurable maps via .cub files.

## Project Structure
```
cub3D/
├── src/            # Source code
│   ├── libft/      # Custom libft library (lives inside src/)
│   ├── game/       # Game logic and ray casting
│   ├── parser/     # Map parsing and validation
│   └── render/     # Rendering functions
├── include/        # Header files
├── textures/       # Wall textures (e.g., XPM)
├── maps/           # Example .cub scene files
├── Makefile        # Build instructions (all, clean, fclean, re, bonus)
└── README.md       # Project documentation
```

## Build and Run
This project depends on MiniLibX and the math library (-lm).

Clone and build:
```
git clone https://github.com/zzetoun/cub3D.git
cd cub3D
make
```

Run with a .cub scene file:
```
./cub3D path/to/map.cub
```
Example:
```
./cub3D maps/example.cub
```

## .cub Scene File Format
A .cub file contains:
- Texture paths for all four wall directions (NO, SO, WE, EA).
- Floor (F) and ceiling (C) colors as R,G,B in [0,255].
- The map layout (1 = wall, 0 = empty space, N/S/E/W = player start + orientation).

Minimal example:
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

Rules:
- The map must be fully closed/surrounded by walls.
- Spaces are significant and part of the map; parse as-is.
- Apart from the map (which must come last), elements can appear in any order and may be separated by empty lines.
- Each element uses a strict identifier and argument order:
  - NO path_to_north_texture
  - SO path_to_south_texture
  - WE path_to_west_texture
  - EA path_to_east_texture
  - F R,G,B
  - C R,G,B

## Error Handling
On any misconfiguration (invalid identifiers, unreadable textures, invalid colors, open map, etc.), the program exits and prints:
```
Error
<your descriptive message>
```

## 42 Specifications (Summary)
- Program name: cub3D
- Turn-in files: all your files
- Makefile targets: all, clean, fclean, re, bonus
- Arguments: a single .cub map file
- Allowed external functions:
  - open, close, read, write, printf, malloc, free, perror, strerror, exit, gettimeofday
  - All functions from the math library (-lm; see: man 3 math)
  - All functions from MiniLibX
- Libft: authorized (this project places libft inside src/libft/)
- Window management must remain smooth (switching focus, minimizing, etc.).
- Use MiniLibX (system version or from sources; if from sources, apply the same rules as for libft).

## Learning Outcomes
- Implement a basic ray caster (DDA or similar) and understand projection to screen space.
- Parse and validate custom scene description files.
- Handle input events and real-time rendering with MiniLibX.
- Write robust error handling and clean resource management.

## License
This project is part of the 42 Network curriculum and is provided for educational purposes.
