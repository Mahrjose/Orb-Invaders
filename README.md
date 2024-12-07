# Orb Invader

Orb Invader is a thrilling 2D shooter game where you defend against descending orbs using precise shooting and quick reflexes. This project is part of my class assignment for **CSE423 - Computer Graphics**.

## Gameplay Mechanics

- **Shooter Control:** Use 'a' and 'd' keys to move the shooter spaceship horizontally.
- **Firing Mechanism:** Press the spacebar to shoot projectiles upwards.
- **Falling Circles:** Circles fall vertically from the top of the screen. Randomize their horizontal positions.
- **Scoring:** Successfully hitting a falling circle increases your score by 1. Both the projectile and falling circle are removed upon hit.
- **Game Over:** The game ends if:
  - A falling circle touches the spaceship.
  - You miss three falling circles.
  - You misfire three times.

## Rules

1. **Draw Everything Using Midpoint Algorithms:** Use the midpoint line and circle drawing algorithms to render all elements on screen.
2. **Use GL_POINTS Primitive:** Only use the GL_POINTS primitive type for rendering.
3. **Control Buttons:**
   - **Left Arrow (Restart):** Restarts the game.
   - **Play/Pause Icon (Amber Colored):** Toggles between play and pause states.
   - **Cross (Red Colored):** Terminates the game.

## Getting Started

1. Clone the repository.
2. Build the project using CMake.
3. Run the executable to start the game.

## Dependencies

- OpenGL
- GLUT/GLFW
- C++

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Warning

This project is my class assignment for **CSE423 - Computer Graphics**. Also, this was the first game I made with C++ & OpenGL. Therefore, please mind any mistakes as well as anything dumb :) 
Enjoy the game and happy coding!
