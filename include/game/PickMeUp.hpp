#pragma once

#include <functional>

#include <SFML/Graphics.hpp>

#include "app/Log.hpp"
#include "game/Player.hpp"

enum class PickUpType {
    Null = 0,

    SelfHaste,
    OpponentHaste,
    SelfSlow,
    OpponentSlow,

    Count
};

class PickMeUp {
public:
    using OnPickUp = std::function<void(std::string pName)>;

    PickMeUp(uint32_t xPos, uint32_t yPos, OnPickUp);

    const sf::CircleShape& getShape() const { return shape_; }

    void onPickUp(std::string pName) {
        print::info("{}: {} got something", __func__, pName);
        onPickUp_(pName);
    }

private:
    sf::CircleShape shape_;
    OnPickUp onPickUp_;
};