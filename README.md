
# 🐬 so_long

> _"So long, and thanks for all the fish!"_

---

## 🇫🇷 Version Française

### 🎯 Objectif

`so_long` est un jeu 2D développé en C avec la **MiniLibX**, dans lequel le joueur collecte des objets et tente de s'échapper par une sortie. Ce projet introduit la gestion de fenêtres, les événements clavier et l'affichage d'images.

### 🧱 Fonctionnalités

- Lecture et parsing de cartes `.ber`
- Contrôle du personnage avec les touches **W, A, S, D**
- Affichage du monde en 2D avec la **MiniLibX**
- Affichage du nombre de déplacements dans le terminal
- Fermeture propre du programme via **ESC** ou la croix de la fenêtre
- Vérification des erreurs dans les cartes :
  - Carte rectangulaire
  - Bordures fermées (murs)
  - Présence obligatoire d’un point de départ, d’au moins un item, et d’une sortie
  - Chemin valide obligatoire

### 🎮 Règles du jeu

Le joueur commence à la position `P`, collecte tous les objets `C`, puis se dirige vers la sortie `E`. Les murs `1` sont infranchissables, le sol est représenté par `0`.

Exemple de carte :

```
111111
1P0C01
100001
1C0E01
111111
```

### 🛠️ Technologies

- **Langage :** C
- **Librairie :** MiniLibX
- **Norme :** Norme C 42
- **Compilation :** Makefile (`all`, `clean`, `fclean`, `re`, `bonus`)

### 🚀 Utilisation

```bash
make
./so_long maps/map1.ber
```

### ✨ Bonus (si disponibles)

- Score affiché dans la fenêtre (pas juste dans le terminal)
- Sprites animés
- Ennemis qui patrouillent
- Autres améliorations graphiques ou mécaniques

### 📁 Structure du projet

```
so_long/
├── src/                # Sources principales
├── include/            # Headers
├── maps/               # Cartes de test (.ber)
├── textures/           # Ressources graphiques
├── libft/              # Libft (si utilisée)
├── Makefile
└── README.md
```

### 🧠 Compétences développées

- Programmation bas niveau (C pur)
- Utilisation d’une bibliothèque graphique
- Parsing et validation de fichiers
- Structuration de projet et rigueur

---

## 🇬🇧 English Version

### 🎯 Objective

`so_long` is a small 2D game written in C using **MiniLibX**, where the player must collect items and escape through an exit. This project introduces basic graphics programming and event handling.

### 🧱 Features

- Parses `.ber` map files
- Controls: **W, A, S, D** to move the player
- Renders a 2D world using **MiniLibX**
- Displays movement count in the terminal
- Clean window handling (ESC or window close button exits properly)
- Validates map rules:
  - Rectangular shape
  - Surrounded by walls
  - Contains one start, at least one item and one exit
  - Ensures a valid solvable path

### 🎮 Game Rules

The player starts at `P`, collects all `C` items, and exits through `E`. Walls (`1`) are not walkable. Empty space is `0`.

Example map:

```
111111
1P0C01
100001
1C0E01
111111
```

### 🛠️ Tech Stack

- **Language:** C
- **Graphics Library:** MiniLibX
- **Coding Standard:** 42 C Norm
- **Build:** Makefile with rules (`all`, `clean`, `fclean`, `re`, `bonus`)

### 🚀 Run

```bash
make
./so_long maps/map1.ber
```

### ✨ Bonus Features (if implemented)

- Movement count shown inside the game window
- Animated sprites
- Enemies patrolling the map
- Other graphic or gameplay improvements

### 📁 Project Structure

```
so_long/
├── src/                # Source files
├── include/            # Headers
├── maps/               # Test maps (.ber)
├── textures/           # Sprites and assets
├── libft/              # Libft (if used)
├── Makefile
└── README.md
```

### 🧠 Skills Gained

- Low-level C programming
- Graphics and window handling
- File parsing and error checking
- Project organization and precision

