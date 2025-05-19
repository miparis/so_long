
# 🎮 so_long

> A simple 2D game project built with the MiniLibX graphical library. Developed as part of the 42 School curriculum.

---

## 📌 Project Overview

**so_long** is a basic top-down tile-based game. The player navigates through a map filled with walls, collectibles, and a single exit. The objective is to collect all items and reach the exit without breaking any rules defined by the map.

---

## 🛠 Features

- Map parsing and validation
- Real-time rendering with **MiniLibX**
- Keyboard controls (WASD or arrow keys)
- Player movement with collision logic
- Collectible tracking and win condition
- Error handling for invalid maps
- Game closing via ESC or window close

---

## 🚀 Getting Started

### ✅ Requirements
- **Linux**
- `gcc` compiler
- MiniLibX (included in the repository or via system libs)

### ⚙️ Compilation

```bash
make
````

### ▶️ Running the game

```bash
./so_long maps/example.ber
```

---

## 📁 Map Format

Maps are `.ber` files and must follow these rules:

* Only the characters:
  `1`: wall
  `0`: floor
  `P`: player start
  `C`: collectible
  `E`: exit
* Exactly one `P`, at least one `C` and one `E`.
* Rectangular shape (all lines same length).
* Surrounded by walls (`1`).
* All collectibles and the exit must be reachable.

### 🧪 Sample Map (maps/example.ber)

```
11111
1P0C1
10001
1E001
11111
```

---

## 🎮 Controls

| Key   | Action     |
| ----- | ---------- |
| W / ↑ | Move Up    |
| A / ← | Move Left  |
| S / ↓ | Move Down  |
| D / → | Move Right |
| ESC   | Exit Game  |


---
👨‍💻 Developed by @miparis. For a more detailed guide of the implementation go to https://miparis.gitbook.io/www.42miparis.com
