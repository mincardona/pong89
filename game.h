#ifndef PONG_H_INCLUDED
#define PONG_H_INCLUDED

void hello_world();

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
    int width;
    int height;
};

/**
 * A ball
 */
struct ball {
    struct vec2 pos;
    struct vec2 veloc;  // velocity
    int side;           // the length of each side of the ball
}

/**
 * Tells whether a paddle intersects with the ball.
 * @param pad the paddle
 * @param ball the ball
 * @return true if the paddle intersects the ball; false if it does not
 */
int contact_paddle_ball(struct paddle* pad, struct ball* ball);

#endif
