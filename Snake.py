import tkinter
import random

ROWS = 25
COLS = 25
TILE_SIZE = 25

WINDOW_WIDTH = TILE_SIZE * COLS
WINDOW_HEIGHT = TILE_SIZE * ROWS

class Tile:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Game window
window = tkinter.Tk()
window.title("Snake")
window.resizable(False, False)

canvas = tkinter.Canvas(window, bg="black", width=WINDOW_WIDTH, height=WINDOW_HEIGHT, borderwidth=0, highlightthickness=0)
canvas.pack()
window.update()

# Center the window
window_width = window.winfo_width()
window_height = window.winfo_height()
screen_width = window.winfo_screenwidth()
screen_height = window.winfo_screenheight()

window_x = int((screen_width / 2) - (window_width / 2))
window_y = int((screen_height / 2) - (window_height / 2))
window.geometry(f"{window_width}x{window_height}+{window_x}+{window_y}")

# Game variables
snake = Tile(5 * TILE_SIZE, 5 * TILE_SIZE)
food = Tile(10 * TILE_SIZE, 10 * TILE_SIZE)
snake_body = []
velocityX = 0
velocityY = 0
game_over = False
score = 0
game_loop = None

# Function to handle direction changes
def change_direction(e): 
    global velocityX, velocityY, game_over
    if game_over:
        return

    # Use temporary variables to store the potential new direction
    new_velocityX, new_velocityY = velocityX, velocityY

    if e.keysym == "Up" and velocityY != 1:  # Up
        new_velocityX, new_velocityY = 0, -1
    elif e.keysym == "Down" and velocityY != -1:  # Down
        new_velocityX, new_velocityY = 0, 1
    elif e.keysym == "Left" and velocityX != 1:  # Left
        new_velocityX, new_velocityY = -1, 0
    elif e.keysym == "Right" and velocityX != -1:  # Right
        new_velocityX, new_velocityY = 1, 0

    # Prevent immediate reversal into itself
    if (new_velocityX, new_velocityY) != (-velocityX, -velocityY):
        velocityX, velocityY = new_velocityX, new_velocityY

# Function to move the snake
def move():
    global snake, food, snake_body, game_over, score
    if game_over:
        return

    if snake.x < 0 or snake.x >= WINDOW_WIDTH or snake.y < 0 or snake.y >= WINDOW_HEIGHT:
        game_over = True
        return

    for tile in snake_body:
        if snake.x == tile.x and snake.y == tile.y:
            game_over = True
            return

    # Collision with food
    if snake.x == food.x and snake.y == food.y:
        snake_body.append(Tile(food.x, food.y))
        while True:
            food.x = random.randint(0, COLS - 1) * TILE_SIZE
            food.y = random.randint(0, ROWS - 1) * TILE_SIZE
            if not any(tile.x == food.x and tile.y == food.y for tile in snake_body):
                break
        score += 1

    # Update snake body
    for i in range(len(snake_body) - 1, -1, -1):
        tile = snake_body[i]
        if i == 0:
            tile.x = snake.x
            tile.y = snake.y
        else:
            prev_tile = snake_body[i - 1]
            tile.x = prev_tile.x
            tile.y = prev_tile.y

    snake.x += velocityX * TILE_SIZE
    snake.y += velocityY * TILE_SIZE

# Function to restart the game when Spacebar is pressed
def restart_game(e):
    global snake, snake_body, food, velocityX, velocityY, game_over, score, game_loop
    if e.keysym == "space" and game_over:
        if game_loop is not None:
            window.after_cancel(game_loop)

        snake = Tile(5 * TILE_SIZE, 5 * TILE_SIZE)
        food = Tile(10 * TILE_SIZE, 10 * TILE_SIZE)
        snake_body = []
        velocityX = 0
        velocityY = 0
        game_over = False
        score = 0
        canvas.delete("all")
        start_game_loop()

# Function to draw the game elements
def draw():
    global snake, food, snake_body, game_over, score
    move()

    canvas.delete("all")
    
    # Draw food
    canvas.create_rectangle(food.x, food.y, food.x + TILE_SIZE, food.y + TILE_SIZE, fill="red")
    
    # Draw snake
    canvas.create_rectangle(snake.x, snake.y, snake.x + TILE_SIZE, snake.y + TILE_SIZE, fill="lime green")
    for tile in snake_body:
        canvas.create_rectangle(tile.x, tile.y, tile.x + TILE_SIZE, tile.y + TILE_SIZE, fill="lime green")

    if game_over:
        canvas.create_text(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, font="Arial 20", text=f"Game Over: {score}", fill="white")
    else:
        canvas.create_text(30, 20, font="Arial 10", text=f"Score: {score}", fill="white")
    
    global game_loop
    game_loop = window.after(100, draw)

# Function to start the game loop
def start_game_loop():
    global game_loop
    game_loop = window.after(100, draw)

# Start the game loop for the first time
start_game_loop()

# Bind the direction change function to key presses (Arrow keys)
window.bind("<KeyRelease>", change_direction)
# Bind the restart game function to the "Space" key (for restarting the game)
window.bind("<space>", restart_game)

# Start the Tkinter main loop
window.mainloop()

