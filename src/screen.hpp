#ifndef SPACEINVADER_SRC_SCREEN_HPP
#define SPACEINVADER_SRC_SCREEN_HPP

#include <string>
#include <time.h>
#include <vector>

#include "invader.hpp"
#include "player.hpp"
#include "player_bullet.hpp"

namespace space_invader
{
  class Screen
  {
    private:

      enum {
        BLANK_MARKER_,
        INVADER_MARKER_,
        PLAYER_MARKER_,
        INVADER_BULLET_MARKER_,
        PLAYER_BULLET_MARKER_,
        MARKER_NUMBER_
      };

      // value
      std::vector<std::vector<int> > screen_array_;

      const std::string MARKER_[MARKER_NUMBER_] = {
        "　", // BLANK_MARKER
        "＊", // INVADER_MARKER
        "＋", // PLAYER_MARKER
        "￥", // INVADER_BULLET_MARKER
        "｜"  //  PLAYER_BULLET_MARDER
      };

      // function
      void screen_to_zero ();
      void clear_console ();
      void set_invaders       (space_invader::Invader invader);
      void set_invader_bullet (space_invader::Invader invader);
      void set_player         (space_invader::Player  player);
      void set_player_bullet  (space_invader::PlayerBullet);

    public:
      // value
      const int SCREEN_HEIGHT_ = 24;
      const int SCREEN_WIDTH_  = 32;

      // function
      Screen ();
      void print_screen (
          space_invader::Invader invader,
          space_invader::Player  player);
      void set_screen   (
          space_invader::Invader invader,
          space_invader::Player  player);
  };
} // namespace space_invader

#endif
