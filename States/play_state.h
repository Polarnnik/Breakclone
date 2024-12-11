//
// Created by polarnik on 12.11.2024.
//
#ifndef BREAKCLONE_PLAY_STATE_H
#define BREAKCLONE_PLAY_STATE_H

#include <vector>
#include "state.h"
#include "../app.h"
#include "ball.h"
#include "../constants.h"

class PlayState final : public GameState {
public:
    explicit PlayState(App* app);
    PlayState(const PlayState&) = delete;
    PlayState& operator=(const PlayState&) = delete;
    ~PlayState() override = default;

    void Render() override;
    void Logic() override;
    void HandleInput() override;
    
private:
    App* const app_;
    Rectangle paddle_;
    Ball ball_;
    std::vector<Rectangle> bricks_;

    void InitGame();
    void CheckCollisions() noexcept;
};

#endif // BREAKCLONE_PLAY_STATE_H