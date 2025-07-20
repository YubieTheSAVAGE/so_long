# so_long

A simple 2D game developed as part of the 1337/42 school curriculum. The player navigates a maze, collects all collectibles, avoids enemies, and reaches the exit. Built in C using the MiniLibX graphics library.

## Features
- Pacman-inspired gameplay: collect all items and reach the exit
- Animated player, collectibles, and enemy
- Enemy AI that chases the player
- Custom map support (`.ber` files)
- Move counter display
- Error handling for invalid maps

## Installation
1. **Clone the repository:**
   ```sh
git clone <repo-url>
cd so_long
```
2. **Install dependencies:**
   - [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
   - X11 development libraries (Linux):
     ```sh
     sudo apt-get install libx11-dev libxext-dev
     ```
3. **Build the project:**
   ```sh
make
```

## Usage
Run the game with a map file:
```sh
./so_long maps/map1.ber
```

## Controls
- `W` / Up Arrow: Move up
- `A` / Left Arrow: Move left
- `S` / Down Arrow: Move down
- `D` / Right Arrow: Move right
- `ESC`: Exit the game

## Map Format
- Maps must be rectangular and use the `.ber` extension.
- Allowed characters:
  - `1`: Wall
  - `0`: Empty space
  - `P`: Player start (exactly 1)
  - `E`: Exit (exactly 1)
  - `C`: Collectible (at least 1)
  - `X`: Enemy (0 or 1)
- The map must be surrounded by walls (`1`).
- The player must collect all `C` before reaching `E`.
- The map must be solvable (all collectibles and exit reachable).

### Example Map
```
111111
1PC0E1
100001
111111
```

## Project Structure
- `sources/` - Game source code
- `includes/` - Header files
- `assets/` - XPM images for player, enemy, collectibles, etc.
- `maps/` - Example maps
- `libft/` - Custom C library (libft, required by 1337/42)
- `get_next_line/` - Line reading utility (required by 1337/42)

## Dependencies
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- X11 (Linux)
- Custom [libft](./libft/) and [get_next_line](./get_next_line/) implementations

## Credits
- **Author:** Ayoub Boudiba (<aboudiba@student.42.fr>)
- Project for 1337/42 School

## License
This project is licensed under the MIT License. See [LICENSE](./LICENSE) for details. 