#pragma once

#include <string>
#include <SDL.h>
#include <deque>

#include "Thing.h"
#include "TrailThing.h"

class PlayerThing: public Thing {
public:
  PlayerThing( std::string n, SDL_Scancode left, SDL_Scancode right );
  ~PlayerThing();

  void Input();
  void Move( float timeStep );

  void NewRoundSetup( int xmin, int xmax, int ymin, int ymax );
  void CreateTrail( std::deque <TrailThing> &trails ) const;

  SDL_Rect GetRenderRect() const;
  int GetRadius() const { return radius_; }
private:
  std::string name_;

  double direction_; //in degrees
  bool turnR_, turnL_;

  static const float TURN_DEG;
  int vel_; //pixels per seconds - depends on the size of the playfield

  int radius_; //for thickness buffs
  int score_;

  bool dead_;

  SDL_Scancode leftKey_, rightKey_;
};