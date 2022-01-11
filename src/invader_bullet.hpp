#ifndef SPACE_INVADER_SRC_INVADER_BULLET_HPP
#define SPACE_INVADER_SRC_INVADER_BULLET_HPP

#include <vector>

namespace space_invader
{
  class InvaderBullet
  {
    private:
      struct BulletStatus
      {
        int x_;
        int y_;
        bool is_shoot_;
      };

      // value
      std::vector<BulletStatus> invader_bullet_;

      // function
      void resize_invader_bullet (const int invader_column);

    public:
      // function
      InvaderBullet (){}
      InvaderBullet (const int invader_column);
      const std::vector<BulletStatus> get_invader_bullet ();
      void shoot_bullet (
          const int x, const int y, const int invader_x, const int invader_y);
      void move_bullet (const int screen_height);
  };
} // namespace space_invader

#endif
