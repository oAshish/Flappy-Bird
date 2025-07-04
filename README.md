# Flappy Bird in C++

Welcome! This is a C++ remake of the classic Flappy Bird game. If you’ve ever wanted to flap through pipes and beat your high score right from your desktop, you’re in the right place. This project is a fun way to practice C++ and game development basics—plus, who doesn’t love a good challenge?

---

##  What is This?

A simple, faithful clone of the original Flappy Bird, built using C++ and [SFML](https://www.sfml-dev.org/). The graphics are intentionally simple. The goal is the same: keep your bird in the air and avoid the pipes. Try to beat your best score, and don’t be afraid to fail a few (hundred) times!

---

##  Getting Started

### Prerequisites

- A C++ compiler (C++11 or higher recommended)
- [SFML library](https://www.sfml-dev.org/) installed

### Installation

1. **Clone this repository**
    ```bash
    git clone https://github.com/oAshish/Flappy-Bird.git
    cd Flappy-Bird
    ```

2. **Install SFML**

   - Download SFML for your platform from [here](https://www.sfml-dev.org/download.php).
   - Follow the official install guide for your OS.

3. **Build the game**

    If there’s a Makefile or CMakeLists.txt:
    ```bash
    make
    ```
    Or manually:
    ```bash
    g++ -std=c++11 main.cpp -o flappybird -lsfml-graphics -lsfml-window -lsfml-system
    ```

4. **Run it!**
    ```bash
    ./flappybird
    ```

---

##  How to Play

- **Press SPACE** to make the bird flap upwards.
- **Let go** to let gravity pull the bird down.
- Avoid the pipes. If you touch one or hit the ground, it’s game over.
- Your score goes up by one every time you pass a set of pipes.
- That’s it—simple, but not so easy!

---

## 📁 Project Structure

```
Flappy-Bird/
├── src/          # All the game code
├── assets/       # Images, sounds, etc.
├── docs/images/  # Screenshots, GIFs
├── main.cpp
├── README.md
└── LICENSE
```





##  Contributing

Want to help out, add a feature, or fix a bug? Awesome! Please fork this repo and open a pull request with your changes.

1. Fork the project
2. Create a new branch (`git checkout -b cool-feature`)
3. Commit your changes (`git commit -m 'Add cool feature'`)
4. Push your branch (`git push origin cool-feature`)
5. Open a Pull Request

---


##  Thanks

- [SFML](https://www.sfml-dev.org/) for making graphics easy.
- Dong Nguyen for the original Flappy Bird.
- Everyone who tries, plays, and improves this little project.

---

Enjoy flapping! If you have ideas, feedback, or just want to share your high score, open an issue or make a pull request. Happy coding!
