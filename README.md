# UNO — Console Game in C

My first C project, written in **2021** as a student, **without any AI assistance**. It's a console version of UNO with a French-language interface, kept here as it was originally written.

## Features

- **Two game modes:** player vs player, or player vs machine (the machine picks cards and colors at random)
- Full 108-card deck, shuffled and dealt randomly (7 cards each)
- Special cards: **+2**, **+4**, **Skip**, **Reverse**, and **Joker** (choose a color)
- **UNO timer:** when you're down to one card, press `u` within 3 seconds or draw 2 cards
- Draw pile is rebuilt from the discard pile when it runs out
- End-of-game point count for the losing player
- Sound effects with `Beep()` and a replay option

## Card codes

| Code | Meaning |
|------|---------|
| `V`, `R`, `B`, `J` | Green (Vert), Red (Rouge), Blue (Bleu), Yellow (Jaune) |
| `R5` | Red 5 |
| `B+2` | Blue +2 |
| `V@` | Green Skip |
| `J$` | Yellow Reverse |
| `+4` | Wild Draw Four |
| `joker` | Wild (choose a color) |

## Build and run

Windows only (uses `windows.h`, `Beep()` and `getch()`).

```bash
gcc main.c -o uno.exe
uno.exe
```

Or open `main.c` in Code::Blocks and press Build & Run.

## How to play

1. Choose a mode: `1` two players, `2` vs machine, `3` quit
2. Enter player name(s)
3. On your turn, the playable cards are listed by index — type the index of the card to play
4. If you have no playable card, you draw one automatically and can choose to play it
5. When you have one card left, press `u` quickly to call UNO
6. First player to empty their hand wins

## Note

This is a beginner project: the code is one large `main()` with duplicated logic for each player. I'm keeping it unchanged as a record of where I started.
