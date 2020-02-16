#pragma once

#include "Application.hpp"
#include "IGameState.hpp"
#include "game/Player.hpp"
#include "game/BorderThing.hpp"

#include <vector>
#include <deque>

enum class GameplayStatus {
    null = 0,
    roundBegin, // at the start of each round; move to RUNNING
    running, // when everybody is furiously trying to kill each other; move to PAUSE, ROUND_END or GAME_END
    pause, // when a player needs a break; move to RUNNING or quit the game in progress
    roundEnd, // when there's only one standing; move to ROUND_BEGIN
    gameEnd // when a player has reached the score goal and is declared a winner; move to another gamestate
};

class StateGame: public IGameState {
public:
    StateGame(const Application::Interface&, const std::vector<PlayerInfo>&);
    ~StateGame();

    void input(const sf::Event&) override;
    void logic() override;
    void render() override;

private:
    std::vector<PlayerThing> initializePlayers(const std::vector<PlayerInfo>&);
    void loadGui();
    void sortScoreList();

    Application::Interface app_;

    std::deque<TrailThing> trails_;

    std::vector<PlayerThing> players_;
    std::vector<PlayerThing>::iterator lastAlive_;

    BorderThing border_;

    // for calculating per-pixel movement speed and turn angles
    sf::Clock moveTimer_;

    // GameplayStatus status_ = GameplayStatus::roundBegin;
};
