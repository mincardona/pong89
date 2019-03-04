#include "game.h"

#include <graph.h>
#include <kbd.h>
#include <compat.h>

#define GBUF_WIDTH 239
#define GBUF_HEIGHT 127

void hello_world() {
    ClrScr();
    FontSetSys(F_8x10);
    DrawStr(3, 3, "Hello world!", A_NORMAL);
    ngetchx();
}

/**
 * A 2-dimensional integer vector
 */
struct vec2 {
    int x;
    int y;
}

/**
 * A player paddle
 */
struct paddle {
    struct vec2 pos;
    int thickness;
    int length;
};

#define STD_PADDLE_THICKNESS 2
#define STD_PADDLE_LENGTH 10

/**
 * A ball
 */
struct ball {
    struct vec2 pos;
    struct vec2 veloc;  // velocity
    int side;           // the length of each side of the ball
};

#define STD_BALL_SIDE 4

struct score {
    int player;
    int ai;
};

struct pong_game_state {
    struct paddle paddle_left;
    struct paddle paddle_right;
    struct ball pong_ball;
    struct score pong_score;
};

struct logical_input {
    int quit;   // boolean
    int direction;
}


/**
 * Tells whether a paddle intersects with the ball.
 * @param pad the paddle
 * @param ball the ball
 * @return true if the paddle intersects the ball; false if it does not
 */
int contact_paddle_ball(struct paddle* pad, struct ball* ball);

void render() {
    // LCD_WIDTH, LCD_HEIGHT
}

void init_game_state(struct pong_game_state* state) {
    state.paddle_left.thickness = STD_PADDLE_THICKNESS;
    state.paddle_left.length = STD_PADDLE_LENGTH;
    state.paddle_left.pos.x = 0;
    state.paddle_left.pos.y = LCD_HEIGHT / 2;

    state.paddle_right.thickness = STD_PADDLE_THICKNESS;
    state.paddle_right.length = STD_PADDLE_LENGTH;
    state.paddle_right.pos.x = LCD_WIDTH - paddle_right.thickness;
    state.paddle_right.pos.y = LCD_HEIGHT / 2;

    state.pong_ball.pos.x = LCD_WIDTH / 2;
    state.pong_ball.pos.y = LCD_HEIGHT / 2;
    state.pong_ball.veloc.x = 1;
    state.pong_ball_veloc.y = 1;
    state.pong_ball.side = STD_BALL_SIDE;

    state.pong_score.player = 0;
    state.pong_score.ai = 0;
}

void check_input(struct logical_input_t* input) {
    if (_keytest(RR_ESC)) {
        input->quit = 1;
    } else {
        input->quit = 0;
    }

    input->direction = 0;
    if (_keytest(RR_UP)) {
        input->direction--;
    }
    if (_keytest(RR_DOWN)) {
        input->direction++;
    }
}

void* render_init() {
    void* gbuf = malloc(LCD_SIZE);
    if (gbuf != NULL) {
        // redirect all graphics routines to the buffer
        PortSet(gbuf, GBUF_WIDTH - 1, GBUF_HEIGHT - 1);
    }
    return gbuf;
}

void render_close(void* gbuf) {
    // set graphics routines back to the screen and free the buffer
    PortRestore();
    free(gbuf);
}

void render(void* gbuf, struct pong_game_state* state) {
    // note that we are drawing on a buffer by this point
    ClearScr();



    // blit the stuff to the screen
    LCD_restore(gbuf);
}

void update_tick(struct pong_game_state* state, struct logical_input* input);

void game_loop() {
    pong_game_state state;
    init_game_state(&state);

    void* gbuf = render_init();
    if (gbuf == NULL) {
        return;
    }

    for(;;) {
        struct logical_input input;

        render(gbuf, &state);

        check_input(&input);
        if (input.quit) {
            break;
        }

        update_tick(&state, &input);
    }

    // we have quit
    render_close(gbuf);
}
