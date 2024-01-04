/*
Here is the code of the program that draws a circle that is 69.0%
ideal according to the game. It’s not a fact that this will work for
you exactly, since the result is affected by the resolution of the screen
and browser window. But if you really want to get the same result, then
you can try to select the necessary constants, which are marked in the comments below.
*/

#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>
#include <string.h>

void thSleep(long mills) {
    usleep(mills * 1000);
}

void mouseMove(double x, double y) {
    CGEventRef event = CGEventCreateMouseEvent(
            NULL, kCGEventMouseMoved,
            CGPointMake(x, y),
            kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

void mouseClickDown(double x, double y) {
    CGEventRef event = CGEventCreateMouseEvent(
            NULL, kCGEventLeftMouseDown,
            CGPointMake(x, y),
            kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

void mouseClickUp(double x, double y) {
    CGEventRef event = CGEventCreateMouseEvent(
            NULL, kCGEventLeftMouseUp,
            CGPointMake(x, y),
            kCGMouseButtonLeft
    );
    CGEventPost(kCGHIDEventTap, event);
    CFRelease(event);
}

int main(int argc, char** argv) {
    int steps = 1000;
    int sleep = 5;
    int wait = 5000;
    int r = 400;

    if (argc > 1) {
        for (int i = 1; i < argc; i += 2) {
            if (strcmp(argv[i], "-steps") == 0) {
                steps = atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "-sleep") == 0) {
                sleep = atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "-wait") == 0) {
                wait = atoi(argv[i + 1]);
            } else if (strcmp(argv[i], "-r") == 0) {
                r = atoi(argv[i + 1]);
            }
        }
    }

    thSleep(wait);
    CGEventRef event = CGEventCreate(NULL);
    CGPoint cursor = CGEventGetLocation(event);
    CFRelease(event);
    double x, y, xc = cursor.x, yc = cursor.y;
    mouseMove(xc + r, yc);
    mouseClickDown(xc + r, yc);
    // Number of waves in circle
    int waves = 12;
    // Wave amplitude in pixels
    int amplitude = 195;
    for (double angle = 0; angle < M_PI * 2; angle += (M_PI * 2) / steps) {
        x = cos(angle) * (r + sin(waves * angle) * amplitude);
        y = sin(angle) * (r + sin(waves * angle) * amplitude);
        mouseMove(xc + x, yc + y);
        thSleep(sleep);
    }
    mouseClickUp(xc + x, yc + y);
    return 0;
}
