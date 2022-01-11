#ifndef SPACE_INVADER_SRC_INVADER_HPP
#define SPACE_INVADER_SRC_INVADER_HPP

#include <iostream>
#include <utility>
#include <vector>

#include "invader_bullet.hpp"

namespace space_invader {
  class Invader
  {
    private:
      struct InvaderStatus
      {
        int x_;
        int y_;
        bool is_dead_;
      };

      enum {
        DIRECTION_RIGHT_,
        DIRECTION_DOWN_,
        DIRECTION_LEFT_,
        DIRECTION_MAX_
      };

      // value
      int invader_direction_;

      std::vector<std::vector<space_invader::Invader::InvaderStatus> > invader_array_;
      std::vector<std::pair<int, int> > directions_;

      // function
      int get_next_invader_direction (const int i, const int j,
          const int screen_height, const int screen_width, int next_invader_direction);
      void resize_invader_array_ ();
      void set_first_position_of_invader_array_ ();
      void prepare_directions_ ();
      void change_point_of_invader_array (const int i, const int j);

    public:
      // value
      const int INVADER_ROW_    = 5;
      const int INVADER_COLUMN_ = 11;
      InvaderBullet invader_bullet_;

      // function
      Invader ();
      const std::vector<std::vector<space_invader::Invader::InvaderStatus> > get_invader_array ();
      void move_invaders (const int screen_height, const int screen_width);
      void kill_invader (const int x, const int y);
  };
} // namespace space_invader

#endif
