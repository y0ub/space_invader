#ifndef SPACE_INVADER_SRC_SPACEINVADER_HPP
#define SPACE_INVADER_SRC_SPACEINVADER_HPP

#include <cstdio>
#include <iostream>
#include <random>

#ifdef _WINDOWS
#include <conio.h>
#include <kbhit.h>
#else
#include "../util/y0_conio.h"
#include "../util/y0_kbhit.h"
#endif

#include "screen.hpp"
#include "invader.hpp"
#include "player.hpp"
#include "invader_bullet.hpp"
#include "player_bullet.hpp"

namespace space_invader
{
  class SpaceInvader
  {
    private:
      // value
      const int FPS_           = 10;
#ifdef _WINDOWS
      const int INTERVAL_      = 1'000    / FPS_;
#else
      const int INTERVAL_      = 1'000'000 / FPS_;
#endif
      space_invader::Screen  screen;
      space_invader::Invader invader;
      space_invader::Player  player;

      clock_t last_clock_;
      clock_t now_clock_;
      bool lose_flag;
      int kill_invader_count;

      // function
      void call_print_screen ();
      void action_by_input_from_keybord ();
      void kill_invader (const int bullet_x, const int bullet_y);
      void player_bullet_processing ();
      void shoot_invader_bullet ();
      void invader_bullet_processing ();
      void kill_player (const int bullet_x, const int bullet_y);
      void kill_invader_processing (const int i, const int j);
      bool is_intersect_two_points (
          const int x_1, const int y_1, const int x_2, const int y_2);
      bool is_end ();
      bool is_clear ();

    public:
      // function
      SpaceInvader ();
      void game_processing ();
  };
} // namespace space_invader

#endif
