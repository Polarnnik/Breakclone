//
// Created by polarnik on 16.10.2024.
//

#ifndef STATE_H
#define STATE_H

class GameState {
public:
    virtual void logic() = 0;
    virtual  void render() = 0;
    virtual void handleInput() = 0;
    virtual ~GameState() = default;
};



#endif //STATE_H
