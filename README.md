# 🏓 Ping Pong Game (Local Multiplayer)

A simple 2D **local multiplayer Ping Pong game** written in **C**.  
Play head-to-head on the same keyboard — no extra installation needed.  

---

## 🎮 Features
- Local 2-player gameplay  
- Smooth ball physics and paddle collisions  
- Lightweight and self-contained executable  

---

## 🕹️ Controls

### Player 1
- **W** → Move paddle up  
- **S** → Move paddle down  

### Player 2
- **Up Arrow** → Move paddle up  
- **Down Arrow** → Move paddle down  

### General
- **Esc** → Exit game  

---

## ⚙️ Build & Run
If you want to compile from source (requires Raylib installed):

### Linux / macOS
```bash
gcc main.c -o pingpong -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
./pingpong
