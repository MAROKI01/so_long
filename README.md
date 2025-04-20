
# So_long 42

![App Screenshot](https://i.ibb.co/zH08d2vv/github-image.png)



[![My Skills](https://skillicons.dev/icons?i=c,git,vscode)](https://skillicons.dev)
## 

so_long is a project at 42 School that requires you to create a small 2D game using the minilibX graphical library. The goal of the game is to control a character through a map, collecting items and reaching an exit while avoiding obstacles.

## Requirements
 * A Unix-based OS (Linux/MacOS)
 * C programming language
 * minilibX
 * Make

## Setup
Clone the repository :
```
  git clone https://github.com/MAROKI01/so_long.git
  cd so_long
```

Compile the project:
```
  make
```
This will generate the so_long executable.

## Features

* Basic player movement.

* Animation.

* Enemy patrol that follow the player if it is near.

* Map validation to ensure correct formatting (Using Breath First Search algorithm).

## Usage
Running the Game

After compiling the project, you can run one of this commands game using a valid map file:
```
  ./so_long maps/map.ber
  ./so_long maps/map1.ber
  ./so_long maps/map2.ber
```
Or by usig your own map after creating it:
```
  ./so_long maps/map_name + .ber
```
## Controls

* W / Arrow Up → Move up

* A / Arrow Left → Move left

* S / Arrow Down → Move down

* D / Arrow Right → Move right

* ESC → Exit the game


## Map Format

Maps should be .ber files and must follow these rules:

* Must be rectangular.

Must contain:

* 1 for walls

* 0 for empty space

* C for collectible items

* E for the exit

* P for the player’s starting position

* Must have at least one collectible (C) and one exit (E).

Example Map (map.ber):
```
  111111
  1P0C01
  101001
  1C0E11
  111111
```
## Testing
To check if your map is valid and runs correctly, you can execute:

```
  ./so_long maps/your_map.ber
```

If the map is incorrectly formatted, the program should return an error message
