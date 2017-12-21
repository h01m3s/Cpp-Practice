#include <iostream>

#define LOG(x) std::cout << x << std::endl

struct Vector2 {

    float x, y;

    Vector2(float x, float y)
        : x(x), y(y) {}

    Vector2 Add(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Multiply(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator+(const Vector2& other) const {
        return Add(other);
    }

    Vector2 operator*(const Vector2& other) const {
        return Multiply(other);
    }

    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const {
        // use either syntax
        // return !operator==(other);
        return !(*this == other);
    }

};

std::ostream& operator<<(std::ostream& stream, const Vector2& other) {
    stream << other.x << ", " << other.y;
    return stream;
}

int main(int argc, char const *argv[]) {

    Vector2 position (4.0f, 4.0f);
    Vector2 speed(0.5f, 0.5f);
    Vector2 powerup(1.1f, 1.1f);

    // Hard to read
    // Vector2 result = position.Add(speed.Multiply(powerup));

    // Using operator
    Vector2 result = position + speed * powerup;

    // std::cout << result;
    LOG(result);

    return 0;
}
