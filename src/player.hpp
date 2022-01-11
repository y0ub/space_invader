#ifndef SPACE_INVADER_PLAYER_HPP
#define SPACE_INVADER_PLAYER_HPP

#include <algorithm>

#include "player_bullet.hpp"

namespace space_invader
{
  class Player
  {
    private:
      struct Point {
        int x_;
        int y_;
      };

      Point point;

    public:
      // value
      PlayerBullet player_bullet;

      // function
      Player () {}
      Player (const int height, const int width);
      space_invader::Player::Point get_player_point ();
      void move_player (const char c, const int screen_width);
  };
} // namespace space_invader

#endif
