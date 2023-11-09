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
    int steps = 200;
    int sleep = 20;
    int wait = 5000;
    int r = 250;

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
    for (double angle = 0; angle < M_PI * 2; angle += (M_PI * 2) / steps) {
        x = cos(angle) * r;
        y = sin(angle) * r;
        mouseMove(xc + x, yc + y);
        thSleep(sleep);
    }
    mouseClickUp(xc + x, yc + y);
    return 0;
}
