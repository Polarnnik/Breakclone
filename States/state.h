//
// Created by polarnik on 16.10.2024.
//
#ifndef BREAKCLONE_STATE_H
#define BREAKCLONE_STATE_H

class GameState {
public:
    virtual void Logic() = 0;
    virtual void Render() = 0;
    virtual void HandleInput() = 0;
    virtual ~GameState() = default;

protected:
    GameState() = default;
    GameState(const GameState&) = default;
    GameState& operator=(const GameState&) = default;
};

#endif // BREAKCLONE_STATE_H